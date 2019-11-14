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