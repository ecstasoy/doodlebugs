//
// Created by Kunhua Huang on 5/7/24.
//

#ifndef DOODLEBUGS_GAME_H
#define DOODLEBUGS_GAME_H
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>
#include <algorithm>
#include "constant.h"
#include "organism.h"

class Organism;
class Game {
    std::vector<std::vector<Organism*>> grid;

public:
    Game() : grid(generateGrid()) {};

    void run();
    static std::vector<std::vector<Organism*> > generateGrid();
    static void printGrid(std::vector<std::vector<Organism*> >& grid);
    void performActions(std::vector<std::vector<Organism*> >& grid, bool& doodlebugExtinct, bool& antExtinct);
    void printStatistics(std::vector<std::vector<Organism*> >& grid);
    void printSummarize();
};

#endif //DOODLEBUGS_GAME_H
