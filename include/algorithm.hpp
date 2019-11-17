//
// Created by cydonia on 15.11.2019.
//

#ifndef INC_2D_BIN_PACKING_ALGORITHM_H
#define INC_2D_BIN_PACKING_ALGORITHM_H

#include "population.hpp"
#include <fstream>
#include <iostream>

class Algorithm {
public:
    Algorithm(Population&, XOVER_MODE, unsigned int);
    void evolution();
private:
    Population p;
    XOVER_MODE xover_mode;
    unsigned int max_generation;
    unsigned int generation = 0;
    default_random_engine generator;
    uniform_real_distribution<double> prob_generator = uniform_real_distribution<double>(0.0,1.0);
    vector<BoundingBox> roulette_wheel(vector<BoundingBox>&, double);
    vector<BoundingBox> survivors(vector<BoundingBox>&, vector<BoundingBox>&);
    void incrementGeneration();
    void report();
    void final_report();
    static bool sortFitnesses(BoundingBox&, BoundingBox&);
};


#endif //INC_2D_BIN_PACKING_ALGORITHM_H
