//
// Created by cydonia on 14.11.2019.
//

#ifndef INC_2D_BIN_PACKING_POPULATION_H
#define INC_2D_BIN_PACKING_POPULATION_H
#define MAX_UNSIGNED 4294967295

#include "bbox.hpp"
#include <map>
#include <utility>

using namespace std;

enum XOVER_MODE {UNIFORM, SINGLE_POINT, K_POINT};

class Population {
public:
    Population(double, double, unsigned int);
    Population() {};
    unsigned int getPopulationCount() const;
    void setGenePool(const vector<Rectangle>&);
    unsigned int getPenalty() const;
    unsigned int getTargetArea() const;
    unsigned int getTotalFitness() const;
    unsigned int getGeneCount() const;
    BoundingBox& getBestIndividual();
    void calculateFitness();
    vector<BoundingBox>& getCurrentPopulation();
    void setCurrentPopulation(vector<BoundingBox>);
    vector<BoundingBox>& getMatingPool();
    void setMatingPool(vector<BoundingBox>);
    void setOffspring(vector<BoundingBox>);
    vector<BoundingBox>& getOffspring();
    void shufflePopulation();
    void setDimensionHeuristic();
    void initializePopulation();
    vector<BoundingBox> crossover(XOVER_MODE);
    void mutate();
private:
    vector<BoundingBox> individuals;
    vector<BoundingBox> mating_pool;
    vector<BoundingBox> offsprings;
    vector<Rectangle> gene_pool;
    unsigned int population_count;
    unsigned int gene_count;
    unsigned int k = 3;
    double mutation_rate;
    double crossover_rate;
    double penalty = 5;
    unsigned int area = 0;
    unsigned int total_fitness = 0;
    BoundingBox best_individual;
    default_random_engine generator;
    uniform_real_distribution<double> prob_generator = uniform_real_distribution<double>(0.0,1.0);
    unsigned int upper_bound;
    vector<Rectangle>& initializeGenes();
    vector<BoundingBox> uniform_crossover();
    vector<BoundingBox> single_point_crossover();
    vector<BoundingBox> k_point_crossover();
    vector<unsigned int> generateRandomPoints();

};


#endif //INC_2D_BIN_PACKING_POPULATION_H
