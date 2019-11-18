#include <string>
#include <fstream>
#include "rectangle.hpp"
#include "bbox.hpp"
#include "population.hpp"
#include "algorithm.hpp"
using namespace std;

int main(int argc, char** argv){
    string input_file_name = argv[1];
    ifstream infile(input_file_name);
    unsigned int w, h, i;
    i = 0;
    vector<Rectangle> genes;
    while (infile >> w >> h) {
        Rectangle r(w, h, i++);
        genes.push_back(r);
    }
    Population population(0.2, 0.7, 1000);
    population.setGenePool(genes);
    population.setDimensionHeuristic();
    for (unsigned int j = 0; j < 5; ++j) {
        Algorithm algo(population, K_POINT, 250);
        algo.evolution(j);
    }
    for (unsigned int j = 0; j < 5; ++j) {
        Algorithm algo(population, UNIFORM, 250);
        algo.evolution(j);
    }
    for (unsigned int j = 0; j < 5; ++j) {
        Algorithm algo(population, SINGLE_POINT, 250);
        algo.evolution(j);
    }
    return 0;
}