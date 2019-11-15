//
// Created by cydonia on 14.11.2019.
//

#ifndef INC_2D_BIN_PACKING_POPULATION_H
#define INC_2D_BIN_PACKING_POPULATION_H

#include "bbox.hpp"

using namespace std;

enum Mode {
    STATIC,
    DYNAMIC,
    ADAPTIVE
};

class Population {
public:
    Population(double, double, unsigned int, Mode);
    unsigned int getPopulationCount() const;
    void setGenePool(const vector<Rectangle>&);
    unsigned int getPenalty() const;
    double getAverageFitness() const;
    unsigned int getCurrentGeneration() const;
    vector<BoundingBox> getCurrentPopulation() const;
    void setCurrentPopulation(vector<BoundingBox>);
    void setPenalty(unsigned int);
    void calculateAverageFitness();
    void incrementGeneration();
    void setDimensionHeuristic();
    void initializePopulation();
    void shufflePopulation();
    vector<BoundingBox> crossover();
    void mutate();
private:
    vector<BoundingBox> individuals;
    vector<Rectangle> gene_pool;
    Mode mode;
    unsigned int population_count;
    unsigned int gene_count;
    double mutation_rate;
    double crossover_rate;
    double penalty;
    unsigned int area;
    double avg_fitness;
    unsigned int generation;
    default_random_engine generator;
    uniform_real_distribution<double> prob_generator = uniform_real_distribution<double>(0.0,1.0);
    uniform_int_distribution<unsigned int> dist;
    vector<Rectangle>& initializeGenes();
};


#endif //INC_2D_BIN_PACKING_POPULATION_H
