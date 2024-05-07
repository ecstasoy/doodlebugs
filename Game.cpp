//
// Created by Kunhua Huang on 5/7/24.
//

#include "game.h"
#include "organism.h"

void Game::run() {
    srand(static_cast<unsigned int>(time(nullptr)));
    bool doodlebugExtinct = true, antExtinct = true;

    char autoRun;
    int stepsToRun = 1;
    std::cout << "Do you want to run the simulation automatically to a certain step? (y/n): ";
    std::cin >> autoRun;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    if(autoRun == 'y' || autoRun == 'Y') {
        std::cout << "Enter the number of steps to run: ";
        std::cin >> stepsToRun;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }

    while(true) {

        std::cout << "\nWorld at time " << Organism::timeStep + 1 << ": \n" << std::endl;
        printGrid(grid);

        performActions(grid, doodlebugExtinct, antExtinct);
        if(doodlebugExtinct) {
            std::cout << "\nDoodlebugs are extinct\n";
            printSummarize();
            std::cout << "\nPress ENTER to quit\n";
            std::cin.get();
            break;
        }
        if(antExtinct) {
            std::cout << "\nAnts are extinct\n";
            printSummarize();
            std::cout << "\nPress ENTER to quit\n";
            std::cin.get();
            break;
        }
        doodlebugExtinct = true;
        antExtinct = true;

        Organism::resizeCounters();

        printStatistics(grid);
        Organism::timeStep++;

        // If the user chose to run automatically and we've reached the specified number of steps, switch to manual mode
        if(autoRun == 'y' || autoRun == 'Y') {
            if(Organism::timeStep > stepsToRun - 1) {
                autoRun = 'n';
            }
        }

        // If we're in manual mode, pause for user input
        if(autoRun == 'n' || autoRun == 'N') {
            std::cout << "\nPress ENTER to continue\n";
            std::cout << "Enter 's' to see the summary up to this step\n";
            std::cout << "Enter 'q' to quit\n";
            char c = std::cin.get();
            if (c == '\n') {
                continue;
            } else if (c == 's') {
                printSummarize();
                std::cout << "\nPress ENTER to continue\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cin.get();
            } else if (c == 'q') {
                break;
            }

            continue;
        }

    }
}

std::vector<std::vector<Organism*> > Game::generateGrid() {
    std::vector<std::vector<Organism*> > grid(GRID_SIZE, std::vector<Organism*>(GRID_SIZE, nullptr));

    int countAnts = 0, countDoodlebugs = 0;

    while(countAnts < ANT_NUMBER) {
        int x = rand() % GRID_SIZE, y = rand() % GRID_SIZE;
        if(!grid[x][y]) {
            grid[x][y] = new Ant(x, y);
            countAnts++;
        }
    }

    while(countDoodlebugs < DOODLEBUG_NUMBER) {
        int x = rand() % GRID_SIZE, y = rand() % GRID_SIZE;
        if(!grid[x][y]) {
            grid[x][y] = new Doodlebug(x, y);
            countDoodlebugs++;
        }
    }

    return grid;
}

void Game::printGrid(std::vector<std::vector<Organism*> >& grid) {
    for(int i = 0; i < GRID_SIZE; ++i) {
        for(int j = 0; j < GRID_SIZE; ++j) {
            if(grid[i][j] == nullptr) {
                std::cout << "- ";
            } else if (grid[i][j]->getType() == ANT) {
                std::cout << "o ";
            } else if (grid[i][j]->getType() == DOODLEBUG) {
                std::cout << "X ";
            } else {
                std::cout << "-";
            }
        }
        std::cout << "\n";
    }
}

void Game::performActions(std::vector<std::vector<Organism*> >& grid, bool& doodlebugExtinct, bool& antExtinct) {
    for(auto& row : grid) {
        std::for_each(row.begin(), row.end(), [&](Organism* org) {
            if(org && org->getType() == DOODLEBUG && !org->isMoved) {
                org->move(grid);
                doodlebugExtinct = false;
            }
        });
    }

    for(auto& row : grid) {
        std::for_each(row.begin(), row.end(), [&](Organism* org) {
            if(org && org->getType() == ANT && !org->isMoved) {
                org->move(grid);
                antExtinct = false;
            }
        });
    }

    for(auto& row : grid) {
        std::for_each(row.begin(), row.end(), [&](Organism* org) {
            if(org) {
                if(org->getType() == DOODLEBUG) {
                    org->isStarved(grid);
                    if (org) {
                        org->breed(grid);
                        org->isMoved = false;
                        doodlebugExtinct = false;
                    }
                } else if(org->getType() == ANT) {
                    org->breed(grid);
                    org->isMoved = false;
                    antExtinct = false;
                }
            }
        });
    }
}

void Game::printStatistics(std::vector<std::vector<Organism*> >& grid) {
    int antCount = 0, doodlebugCount = 0;
    for(auto& row : grid) {
        std::for_each(row.begin(), row.end(), [&](Organism* org) {
            if(org && org->getType() == ANT) antCount++;
            if(org && org->getType() == DOODLEBUG) doodlebugCount++;
        });
    }

    std::cout << "\nAnts: " << antCount << "\nDoodlebugs: " << doodlebugCount << std::endl;
    std::cout << "Ants Eaten: " << Organism::antEatenCount[Organism::timeStep] << std::endl;
    std::cout << "Ants Bred: " << Organism::antBreedCount[Organism::timeStep] << std::endl;
    std::cout << "Doodlebugs Bred: " << Organism::doodlebugBreedCount[Organism::timeStep] << std::endl;
    std::cout << "Doodlebugs Starved: " << Organism::doodlebugStarveCount[Organism::timeStep] << std::endl;
}

void Game::printSummarize() {
    int totalEaten = 0, totalStarved = 0, totalBredAnts = 0, totalBredDoodlebugs = 0;

    for(auto& eaten : Organism::antEatenCount) {
        totalEaten += eaten;
    }
    for(auto& starved : Organism::doodlebugStarveCount) {
        totalStarved += starved;
    }
    for(auto& bred : Organism::antBreedCount) {
        totalBredAnts += bred;
    }
    for(auto& bred : Organism::doodlebugBreedCount) {
        totalBredDoodlebugs += bred;
    }

    std::cout << "\nIn this world of " << Organism::timeStep << " steps: \n";
    std::cout << "Total ants eaten: " << totalEaten << "\n";
    std::cout << "Total doodlebugs starved: " << totalStarved << "\n";
    std::cout << "Total ants bred: " << totalBredAnts << "\n";
    std::cout << "Total doodlebugs bred: " << totalBredDoodlebugs << "\n";
}