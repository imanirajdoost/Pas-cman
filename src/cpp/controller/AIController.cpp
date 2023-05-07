#include "header/controller/AIController.h"
#include "header/model/Map.h"

AIController::AIController(vector<vector<MTYPE>> &map) {
    neighbours[0] = Point(  0, -1 ); neighbours[1] = Point( -1,  0 );
    neighbours[2] = Point(  0,  1 ); neighbours[3] = Point(  1,  0 );

    m = map;
}

int AIController::calcDist( Point& p ) {
        // need a better heuristic
    int x = end.x - p.x, y = end.y - p.y;
    return( x * x + y * y );
}

bool AIController::isValid( Point& p ) {
    return ( p.x >-1 && p.y > -1 && p.x < m[0].size() && p.y < m.size() );
}

bool AIController::canPassThrough(Point& p) {
    int x = p.x;
    int y = p.y;
    return (m[y][x] == MTYPE::EMPTY || m[y][x] == MTYPE::ITEM);
}

bool AIController::existPoint( Point& p, int cost ) {
    
    std::list<Node>::iterator i;
    i = std::find(closed.begin(), closed.end(), p);


    if(i != closed.end()) {
        if( ( *i ).cost + ( *i ).dist < cost ) {
            return true;
        } else { 
            closed.erase( i ); return false; 
        }
    }

    i = std::find(open.begin(), open.end(), p);

    if(i != open.end()) {
        if( ( *i ).cost + ( *i ).dist < cost ){
            return true;
        } else { 
            open.erase( i ); 
            return false; 
        }
    }
    return false;
}

bool AIController::fillOpen(Node& n) {
    int stepCost, nc, dist;
    Point neighbour;

    for( int x = 0; x < 4; x++ ) {
        // one can make diagonals have different cost
        stepCost = 1;
        neighbour = n.pos + neighbours[x];
        
        if( neighbour == end ) 
            return true;

        if(isValid(neighbour) && canPassThrough(neighbour)) {
            nc = stepCost + n.cost;
            dist = calcDist(neighbour);
            if(!existPoint(neighbour, nc + dist)) {
                Node m;
                m.cost = nc; m.dist = dist;
                m.pos = neighbour;
                m.parent = n.pos;
                open.push_back(m);
            }
        }
    }
    return false;
}

bool AIController::search(Point& s, Point& e) {
    Node n; end = e; start = s;
    n.cost = 0; n.pos = s; n.parent = 0; n.dist = calcDist(s);
    open.push_back(n);
    
    while(!open.empty()) {
        Node n = open.front();
        open.pop_front();
        closed.push_back( n );
        if(fillOpen(n)) { 
            return true;
        }
    }
    return false;
}

int AIController::path( std::list<Point>& path ) {
    
    path.push_front( end );
    int cost = 1 + closed.back().cost;
    path.push_front( closed.back().pos );
    Point parent = closed.back().parent;

    for( std::list<Node>::reverse_iterator i = closed.rbegin(); i != closed.rend(); i++ ) {
        if( ( *i ).pos == parent && !( ( *i ).pos == start ) ) {
            path.push_front( ( *i ).pos );
            parent = ( *i ).parent;
        }
    }
    path.push_front( start );
    return cost;
}

SDL_Rect AIController::getNextStep(Point& s, Point& e) {
    
    open.clear();
    closed.clear();

    if(search(s, e)) {
        std::list<Point> _path;
        int c = path(_path);

        std::vector<Point> result(_path.size());
        std::copy(_path.begin(), _path.end(), result.begin());

        auto nextStep = _path.size() <= 1 ? _path.front() : result[1];

        SDL_Rect nextStepRect;
        nextStepRect.x = nextStep.x;
        nextStepRect.y = nextStep.y;

        // for( int y = 0; y < m.size(); y++ ) {
        //     for( int x = 0; x < m[0].size(); x++ ) {
        //         Point p(x, y);
        //         if( x < 0 || y < 0 || x > m[0].size() || y > m.size() || !canPassThrough(p) )
        //             std::cout << char(0xdb);
        //         else {
        //             if( std::find( _path.begin(), _path.end(), Point( x, y ) )!= _path.end() )
        //                 std::cout << "x";
        //             else std::cout << ".";
        //         }
        //     }
        //     std::cout << "\n";
        // }

        return nextStepRect;
    } else {
        SDL_Rect ghostHome;
        ghostHome.x = 11; ghostHome.y = 14;
        return ghostHome;
    }
}