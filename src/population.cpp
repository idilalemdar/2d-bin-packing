//
// Created by cydonia on 14.11.2019.
//

#include "population.hpp"

Population::Population() {
    this->penalty = 5;
}

Population* Population::instance = nullptr;

Population* Population::getInstance() {
    if (instance == nullptr){
        instance = new Population();
    }
    return instance;
}

unsigned int Population::getPenalty() const {
    return this->penalty;
}

void Population::setPenalty(unsigned int p) {
    this->penalty = p;
}

unsigned int Population::getPopulationCount() const {
    return this->population_count;
}

void Population::setGenePool(const vector<Rectangle>& recs) {
    this->gene_pool = recs;
}

void Population::initializePopulation() {
    // for i in range # of population count do:
    // get some initial configuration of genes
    // construct new BBox with this, push it to this->individuals
}

vector<Rectangle> Population::initializeGenes() {
    vector<Rectangles> copy_gene_pool(this->gene_pool);

    return copy_gene_pool;
}