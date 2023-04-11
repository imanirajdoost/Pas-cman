#ifndef MAP_H
#define MAP_H

#include <vector>
#include <tuple>

using namespace std;

/**
 * @brief An enum representing the possible types of map items that can be found on a tile.
 */
enum class MTYPE {
    PACMAN, /**< A tile with Pac-Man. */
    GHOST, /**< A tile with Ghost. */
    EMPTY, /**< An empty tile that is safe to move onto. */
    WALL, /**< A tile that is blocked and cannot be moved onto. */
    DOOR, /**< A tile that acts as a door and can be moved through in one direction. */
    ITEM, /**< A tile that contains an item that can be collected. */
    TP, /**< A tile that acts as a teleporter and moves the player to a different location on the map. */
};

/**
 * @brief A class representing the map of the game and what item is on each tile.
 */
class Map {
public:

    /**
     * @brief A vector of vectors representing the map of the game, where each tile contains a map item.
     *
     * The original char_map size is [27][21].
     */
    static vector<vector<MTYPE>> map;

    /**
     * @brief A vector of tuples representing the intersections on the map, where Pac-Man can make a decision on where to move.
     */
    static vector<tuple<int, int>> intersections;

    /**
     * @brief A template function that takes a game object as a parameter and returns the type of item that is on the tile that the object is currently on.
     *
     * @tparam T The type of the game object. Must have `getTilePosition()` method.
     * @param gameObject The game object that is currently on a tile.
     * @return The type of item that is on the tile that the object is currently on.
     */
    template <typename T>
    MTYPE getCurrentTileType(const T& gameObject) const;
};

#endif
