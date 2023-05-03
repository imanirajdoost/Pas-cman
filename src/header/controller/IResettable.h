
#ifndef PAS_CMAN_IRESETTABLE_H
#define PAS_CMAN_IRESETTABLE_H

/**
 * @brief The IResettable interface, which is implemented by classes that need to be reset when the game is reset.
 */
class IResettable {
public:
    /**
     * @brief Method that is called when the game is reset.
     */
    virtual void reset_state() = 0;
};


#endif //PAS_CMAN_IRESETTABLE_H
