#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>
#include <algorithm>

const int GRID_SIZE = 20;
const int ANT = 1;
const int DOODLEBUG = 2;
const int ANT_NUMBER = 100;
const int DOODLEBUG_NUMBER = 5;

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
        void setStepsSurvived(int step) {stepsSurvived = step;};
        void addStepsSinceLastBreed() {stepsSinceLastBreed += 1;};
        void addStepsSurvived() {stepsSurvived += 1;};
        
        int getX() {return x;};
        int getY() {return y;};
        int getType() {return type;};
        int getStepsSinceLastBreed() {return stepsSinceLastBreed;};
        int getStepsSurvived() {return stepsSurvived;};

        //Check empty spot around the critter
        bool canMove(int x, int y, std::vector<std::vector<Organism*> >& grid);

        //Flag the critter if it has moved in the current step
        bool isMoved = false;
};

std::vector<int> Organism::antBreedCount(1000, 0);
std::vector<int> Organism::antEatenCount(1000, 0);
std::vector<int> Organism::doodlebugBreedCount(1000, 0);
std::vector<int> Organism::doodlebugStarveCount(1000, 0);
int Organism::timeStep = 0;

void Organism::resizeCounters() {
    if (Organism::timeStep >= Organism::antBreedCount.size()) {
        Organism::antBreedCount.resize(Organism::antBreedCount.size() * 2, 0);
        Organism::antEatenCount.resize(Organism::antEatenCount.size() * 2, 0);
        Organism::doodlebugBreedCount.resize(Organism::doodlebugBreedCount.size() * 2, 0);
        Organism::doodlebugStarveCount.resize(Organism::doodlebugStarveCount.size() * 2, 0);
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

class Ant : public Organism {

        //Set to true when the ant is able to breed
        bool breedFlag;
    public:
        Ant(int x, int y) : Organism(x, y, ANT), breedFlag(true) {};

        virtual void move(std::vector<std::vector<Organism*> >& grid) override;
        virtual void breed(std::vector<std::vector<Organism*> >& grid) override;
};

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
                Organism::antBreedCount[Organism::timeStep]++;
                return;
            }
        }
    }
}

class Doodlebug : public Organism {
        int stepsSinceLastEat;
    public:
        Doodlebug(int x, int y) : Organism(x, y, DOODLEBUG), stepsSinceLastEat(0) {};

        virtual void move(std::vector<std::vector<Organism*> >& grid) override;
        virtual void breed(std::vector<std::vector<Organism*> >& grid) override;
        virtual void isStarved(std::vector<std::vector<Organism*> >& grid) override;

        int getStepsSinceLastEat() {return stepsSinceLastEat;};
};

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
            Organism::antEatenCount[Organism::timeStep]++;
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
                Organism::doodlebugBreedCount[Organism::timeStep]++;
                return;
            }
        }
    }
}

void Doodlebug::isStarved(std::vector<std::vector<Organism*> >& grid) {
    if(stepsSinceLastEat >= 3) {

        //Set the pointer to nullptr if it dies
        grid[getX()][getY()] = nullptr;
        Organism::doodlebugStarveCount[Organism::timeStep]++;
    }
}

std::vector<std::vector<Organism*> > generateGrid() {
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

void printGrid(std::vector<std::vector<Organism*> >& grid) {
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

void performActions(std::vector<std::vector<Organism*> >& grid, bool& doodlebugExtinct, bool& antExtinct) {
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
                    if(org) {
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

void printStatistics(std::vector<std::vector<Organism*> >& grid) {
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

void printSummarize() {
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

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    bool doodlebugExtinct = true, antExtinct = true;

    std::vector<std::vector<Organism*> > grid = generateGrid();

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

    return 0;
}