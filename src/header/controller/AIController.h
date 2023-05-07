#ifndef AICONTROLLER_H_
#define AICONTROLLER_H_

#include <list>
#include <algorithm>
#include <iostream>
#include <SDL.h>
#include "header/model/Map.h"

class Point {
public:
    Point( int a = 0, int b = 0 ) { x = a; y = b; }
    bool operator ==( const Point& o ) { return o.x == x && o.y == y; }
    Point operator +( const Point& o ) { return Point( o.x + x, o.y + y ); }
    int x, y;
};

class Node {
public:
    bool operator == (const Node& o ) { return pos == o.pos; }
    bool operator == (const Point& o ) { return pos == o; }
    bool operator < (const Node& o ) { return dist + cost < o.dist + o.cost; }
    Point pos, parent;
    int dist, cost;
};

class AIController {
public:
    AIController(vector<vector<MTYPE>> &map);

    int calcDist( Point& p );

    bool isValid( Point& p );

    bool existPoint( Point& p, int cost );

    bool fillOpen( Node& n );

    bool search( Point& s, Point& e );

    int path(std::list<Point>& path);

    SDL_Rect getNextStep( Point& s, Point& e);

    bool canPassThrough(Point& p);

    vector<vector<MTYPE>> m; 
    Point end, start;
    Point neighbours[4];
    std::list<Node> open;
    std::list<Node> closed;
};

/*int main( int argc, char* argv[] ) {
    map m;
    point s, e( 7, 7 );
    aStar as;

    if( as.search( s, e, m ) ) {
        std::list<point> path;
        int c = as.path( path );
        for( int y = -1; y < 9; y++ ) {
            for( int x = -1; x < 9; x++ ) {
                if( x < 0 || y < 0 || x > 7 || y > 7 || m( x, y ) == 1 )
                    std::cout << char(0xdb);
                else {
                    if( std::find( path.begin(), path.end(), point( x, y ) )!= path.end() )
                        std::cout << "x";
                    else std::cout << ".";
                }
            }
            std::cout << "\n";
        }

        std::cout << "\nPath cost " << c << ": ";
        for( std::list<point>::iterator i = path.begin(); i != path.end(); i++ ) {
            std::cout<< "(" << ( *i ).x << ", " << ( *i ).y << ") ";
        }
    }
    std::cout << "\n\n";
    return 0;
}*/

#endif // AICONTROLLER_H_