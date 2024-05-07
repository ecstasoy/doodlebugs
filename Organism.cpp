//
// Created by Kunhua Huang on 5/7/24.
//

#include "organism.h"

std::vector<int> Organism::antEatenCount(1000, 0);
std::vector<int> Organism::antBreedCount(1000, 0);
std::vector<int> Organism::doodlebugBreedCount(1000, 0);
std::vector<int> Organism::doodlebugStarveCount(1000, 0);
int Organism::timeStep = 0;

void Organism::resizeCounters() {
    if (timeStep >= antBreedCount.size()) {
        antBreedCount.resize(antBreedCount.size() * 2, 0);
        antEatenCount.resize(antEatenCount.size() * 2, 0);
        doodlebugBreedCount.resize(doodlebugBreedCount.size() * 2, 0);
        doodlebugStarveCount.resize(doodlebugStarveCount.size() * 2, 0);
    }
}

bool Organism::canMove(int x, int y, std::vector<std::vector<Organism*> >& grid) {
    return x >=0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE && grid[x][y] == nullptr;
}

//Randomize a vector representing four directions
std::vector<int> randDir() {
    std::vector<int> directions = {0, 1, 2, 3};
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(directions.begin(), directions.end(), g);

    return directions;
}

void Ant::move(std::vector<std::vector<Organism*> >& grid) {
    int tempX = getX(), tempY = getY();
    switch (rand() % 4)
    {
        case 0: ++tempX; break;
        case 1: --tempX; break;
        case 2: ++tempY; break;
        case 3: --tempY; break;
    }
    if(canMove(tempX, tempY, grid)) {

        //If the randomized spot is empty, then the critter moves by swap
        std::swap(grid[getX()][getY()], grid[tempX][tempY]);
        setX(tempX);
        setY(tempY);
        isMoved = true;
    }
    if(getStepsSurvived() >= 3) breedFlag = true;
    addStepsSurvived();
    addStepsSinceLastBreed();
}

void Ant::breed(std::vector<std::vector<Organism*> >& grid) {
    if(getStepsSinceLastBreed() >= 3 && breedFlag) {
        std::vector<int> directions = randDir();
        for(int num : directions) {
            int tempX = getX(), tempY = getY();
            switch (num)
            {
                case 0: ++tempX; break;
                case 1: --tempX; break;
                case 2: ++tempY; break;
                case 3: --tempY; break;
            }
            if(canMove(tempX, tempY, grid)) {
                grid[tempX][tempY] = new Ant(tempX, tempY);
                breedFlag = false;
                setStepsSinceLastBreed(0);
                antBreedCount[timeStep]++;
                return;
            }
        }
    }
}

void Doodlebug::move(std::vector<std::vector<Organism*> >& grid) {
    std::vector<int> directions = randDir();
    for(int num : directions)  {
        int tempX = getX(), tempY = getY();
        switch (num)
        {
            case 0: ++tempX; break;
            case 1: --tempX; break;
            case 2: ++tempY; break;
            case 3: --tempY; break;
        }
        if(tempX >= 0 && tempX < GRID_SIZE && tempY >= 0 && tempY < GRID_SIZE && grid[tempX][tempY]
           && grid[tempX][tempY]->getType() == ANT) {

            //Set the pointer of the ant to be eaten to nullptr
            grid[tempX][tempY] = nullptr;
            antEatenCount[timeStep]++;
            std::swap(grid[getX()][getY()], grid[tempX][tempY]);
            setX(tempX);
            setY(tempY);
            stepsSinceLastEat = 0;
            isMoved = true;
            addStepsSurvived();

            //If the critter breeds it no longer moves in the step, so return to main
            return;
        }
    }

    int tempX = getX(), tempY = getY();
    switch (rand() % 4)
    {
        case 0: ++tempX; break;
        case 1: --tempX; break;
        case 2: ++tempY; break;
        case 3: --tempY; break;
    }
    if(canMove(tempX, tempY, grid)) {
        std::swap(grid[getX()][getY()], grid[tempX][tempY]);
        setX(tempX);
        setY(tempY);
        isMoved = true;
    }
    addStepsSurvived();
    ++stepsSinceLastEat;
}

void Doodlebug::breed(std::vector<std::vector<Organism*> >& grid) {
    if(getStepsSurvived() >= 8 && getStepsSurvived() % 8 ==0) {
        std::vector<int> directions = randDir();
        for(int num : directions) {
            int tempX = getX(), tempY = getY();
            switch (num)
            {
                case 0: ++tempX; break;
                case 1: --tempX; break;
                case 2: ++tempY; break;
                case 3: --tempY; break;
            }
            if(canMove(tempX, tempY, grid)) {
                grid[tempX][tempY] = new Doodlebug(tempX, tempY);
                doodlebugBreedCount[timeStep]++;
                return;
            }
        }
    }
}

void Doodlebug::isStarved(std::vector<std::vector<Organism*> >& grid) {
    if(stepsSinceLastEat >= 3) {

        //Set the pointer to nullptr if it dies
        grid[getX()][getY()] = nullptr;
        doodlebugStarveCount[timeStep]++;
    }
}