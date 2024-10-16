//
// Created by Kunhua Huang on 5/7/24.
//

#ifndef DOODLEBUGS_ORGANISM_H
#define DOODLEBUGS_ORGANISM_H
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>
#include <algorithm>
#include "constant.h"
#include "game.h"


class Organism {
    int x, y;
    int stepsSinceLastBreed;
    int stepsSurvived;
    int type;
public:
    static std::vector<int> antEatenCount;
    static std::vector<int> antBreedCount;
    static std::vector<int> doodlebugBreedCount;
    static std::vector<int> doodlebugStarveCount;
    static int timeStep;
    static void resizeCounters();

    Organism(int x, int y, int type) : x(x), y(y), type(type), stepsSinceLastBreed(0), stepsSurvived(0) {};

    virtual void move(std::vector<std::vector<Organism*> >& grid) = 0;
    virtual void breed(std::vector<std::vector<Organism*> >& grid) = 0;
    virtual void isStarved(std::vector<std::vector<Organism*> >& grid) {};

    void setX(int newX) {x = newX;};
    void setY(int newY) {y = newY;};
    void setStepsSinceLastBreed(int step) {stepsSinceLastBreed = step;};
    void addStepsSinceLastBreed() {stepsSinceLastBreed += 1;};
    void addStepsSurvived() {stepsSurvived += 1;};

    int getX() const {return x;};
    int getY() const {return y;};
    int getType() const {return type;};
    int getStepsSinceLastBreed() const {return stepsSinceLastBreed;};
    int getStepsSurvived() const {return stepsSurvived;};

    //Check empty spot around the critter
    static bool canMove(int x, int y, std::vector<std::vector<Organism*> >& grid);

    //Flag the critter if it has moved in the current step
    bool isMoved = false;
};

class Ant : public Organism {

    //Set to true when the ant is able to breed
    bool breedFlag;
public:
    Ant(int x, int y) : Organism(x, y, ANT), breedFlag(true) {};

    void move(std::vector<std::vector<Organism*> >& grid) override;
    void breed(std::vector<std::vector<Organism*> >& grid) override;
};

class Doodlebug : public Organism {
    int stepsSinceLastEat;
public:
    Doodlebug(int x, int y) : Organism(x, y, DOODLEBUG), stepsSinceLastEat(0) {};

    void move(std::vector<std::vector<Organism*> >& grid) override;
    void breed(std::vector<std::vector<Organism*> >& grid) override;
    void isStarved(std::vector<std::vector<Organism*> >& grid) override;
};

#endif //DOODLEBUGS_ORGANISM_H
