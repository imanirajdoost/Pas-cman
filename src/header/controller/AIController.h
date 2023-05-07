#ifndef AICONTROLLER_H_
#define AICONTROLLER_H_

#include <list>
#include <algorithm>
#include <iostream>

#include "header/model/Map.h"

class point {
public:
    point( int a = 0, int b = 0 ) { x = a; y = b; }
    bool operator ==( const point& o ) { return o.x == x && o.y == y; }
    point operator +( const point& o ) { return point( o.x + x, o.y + y ); }
    int x, y;
};

class node {
public:
    bool operator == (const node& o ) { return pos == o.pos; }
    bool operator == (const point& o ) { return pos == o; }
    bool operator < (const node& o ) { return dist + cost < o.dist + o.cost; }
    point pos, parent;
    int dist, cost;
};

class aStar {
public:
    aStar();

    int calcDist( point& p );

    bool isValid( point& p );

    bool existPoint( point& p, int cost );

    bool fillOpen( node& n );

    bool search( point& s, point& e, vector<vector<MTYPE>> mp );

    int path(std::list<point>& path);

    int find_path( point& s, point& e);

    vector<vector<MTYPE>> m; 
    point end, start;
    point neighbours[8];
    std::list<node> open;
    std::list<node> closed;
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