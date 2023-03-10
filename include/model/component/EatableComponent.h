#ifndef DOT_H
#define DOT_H

class EatableComponent : public GameComponent {

protected:
    bool isEaten;

public:
    EatableComponent();

    void getEaten(const EatableComponent &dot, int score);

    void setIndex(short indexToSet);

    short getIndex() const;

    bool hasBeenEaten() const;

private:
    short index;
};

#endif