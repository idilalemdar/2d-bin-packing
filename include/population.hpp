//
// Created by cydonia on 14.11.2019.
//

#ifndef INC_2D_BIN_PACKING_POPULATION_H
#define INC_2D_BIN_PACKING_POPULATION_H

#include "bbox.hpp"

using namespace std;

class Population {
public:
    static Population* getInstance();
    unsigned int getPopulationCount() const;
    void setGenePool(const vector<Rectangle>&);
    unsigned int getPenalty() const;
    void setPenalty(unsigned int);
    void initializePopulation();
private:
    static Population* instance;
    Population();
    vector<BoundingBox> individuals;
    vector<Rectangle> gene_pool;
    unsigned const int population_count = 50;
    unsigned int penalty;
};


#endif //INC_2D_BIN_PACKING_POPULATION_H
