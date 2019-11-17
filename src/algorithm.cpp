//
// Created by cydonia on 15.11.2019.
//

#include "algorithm.hpp"

Algorithm::Algorithm(Population& pop, XOVER_MODE mode, unsigned int max_gen) {
    this->p = pop;
    this->xover_mode = mode;
    this->max_generation = max_gen;
}

void Algorithm::incrementGeneration() {
    this->generation++;
}

void Algorithm::evolution() {
    this->p.initializePopulation(); // set gene pool and determine heuristic beforehand
    this->p.calculateFitness();
    vector<BoundingBox> &parents = this->p.getCurrentPopulation();
    while (this->generation <= this->max_generation) {
        this->report();
        this->p.setMatingPool(this->roulette_wheel(parents, this->p.getTotalFitness()));
        this->p.shufflePopulation();
        this->p.setOffspring(this->p.crossover(this->xover_mode));
        this->p.mutate();
        this->p.setCurrentPopulation(this->survivors(this->p.getMatingPool(), this->p.getOffspring()));
        this->p.calculateFitness();
        this->incrementGeneration();

        if (this->p.getBestIndividual().getFitness() == this->p.getTargetArea()) break;
    }
    this->final_report();
}

vector<BoundingBox> Algorithm::survivors(vector<BoundingBox>& maters, vector<BoundingBox>& offsprings) {
    unsigned int pen = this->p.getPenalty();
    for (auto &ele: maters) ele.calculateFitness(pen);
    for (auto &ele: offsprings) ele.calculateFitness(pen);
    vector<BoundingBox> join(maters);
    join.insert(join.end(), offsprings.begin(), offsprings.end());
    sort(join.begin(), join.end(), this->sortFitnesses);
    vector<BoundingBox> result;
    result.insert(result.begin(), join.begin(), join.begin() + this->p.getPopulationCount());
    return result;
}

vector<BoundingBox> Algorithm::roulette_wheel(vector<BoundingBox>& pop, double total_fitness) {
    vector<BoundingBox> selections;
    vector<double> shares;
    double prob;
    double inverse_denominator = 0;
    vector<unsigned int> fitnesses;
    unsigned int fitness;
    for (auto const &individual: pop) {
        fitness = individual.getFitness();
        inverse_denominator += total_fitness / fitness;
        fitnesses.push_back(fitness);
    }
    for (unsigned int k = 0; k < pop.size(); ++k) {
        shares.push_back((total_fitness / fitnesses[k]) / inverse_denominator);
    }
    for (unsigned int i = 0; i < pop.size(); ++i) {
        prob = this->prob_generator(this->generator);
        int j = 0;
        while (prob > shares[j]) {
            prob -= shares[j];
            j++;
        }
        selections.push_back(pop[j]);
    }
    return selections;
}

void Algorithm::report() {
    ofstream ofs;
    ofs.open("report.txt", ofstream::app);

    ofs << "Generation:" << this->generation << " Average fitness:"
        << static_cast<double>(this->p.getTotalFitness()) / this->p.getPopulationCount()
        << " Best Fitness:" << this->p.getBestIndividual().getFitness() << endl;

    ofs.close();
}

void Algorithm::final_report() {
    ofstream ofs;
    ofs.open("report.txt", ofstream::app);
    BoundingBox &bb = this->p.getBestIndividual();
    for (unsigned int i = 0; i < this->p.getGeneCount(); ++i) {
        Rectangle &gene = bb.getGene(i);
        ofs << gene.getID() << ": <" << gene.getOffsetX() << ", "
            << gene.getOffsetY() << ", " << gene.isRotated() << ">" << endl;
    }
    ofs.close();
}

bool Algorithm::sortFitnesses(BoundingBox &b1, BoundingBox &b2) {
    return b1.getFitness() < b2.getFitness();
}