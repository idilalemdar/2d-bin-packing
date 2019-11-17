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
    Population population(0.3, 0.7, 1000);
    population.setGenePool(genes);
    population.setDimensionHeuristic();
    Algorithm algo(population, K_POINT, 1000);
    algo.evolution();
    return 0;
}