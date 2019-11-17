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

<<<<<<< Updated upstream
=======
<<<<<<< HEAD
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
=======
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
=======
>>>>>>> 8c5f838d1588112f04d135c76176c87e3fb7527d
>>>>>>> Stashed changes
    void mutate();
private:
    vector<BoundingBox> individuals;
    vector<BoundingBox> mating_pool;
    vector<BoundingBox> offsprings;
    vector<Rectangle> gene_pool;
<<<<<<< Updated upstream
=======
<<<<<<< HEAD
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
=======
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
=======
>>>>>>> 8c5f838d1588112f04d135c76176c87e3fb7527d
>>>>>>> Stashed changes
};


#endif //INC_2D_BIN_PACKING_POPULATION_H
