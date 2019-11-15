//
// Created by cydonia on 14.11.2019.
//

#include "population.hpp"
#include "bbox.hpp"

Population::Population(double mr, double cr, unsigned int pop, Mode m) {
    this->penalty = 5;
    this->area = 0;
    this->mutation_rate = mr;
    this->crossover_rate = cr;
    this->mode = m;
    this->avg_fitness = 0;
    this->generation = 0;
    this->population_count = pop;
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

unsigned int Population::getCurrentGeneration() const {
    return this->generation;
}

void Population::incrementGeneration() {
    this->generation++;
}

double Population::getAverageFitness() const {
    return this->avg_fitness;
}

void Population::shufflePopulation(){
    shuffle(this->individuals.begin(), this->individuals.end(), this->generator);
}

vector<BoundingBox> Population::crossover() {
    vector<BoundingBox> next_generation;
    unsigned int temp_offset_x, temp_offset_y;
    for (unsigned int i = 0; i < this->population_count; i += 2) {
        BoundingBox b1(this->individuals[i]);
        BoundingBox b2(this->individuals[i+1]);
        double p_crossover = this->prob_generator(this->generator);
        if (p_crossover <= this->crossover_rate) {
            for (unsigned int j = 0; j < this->gene_count; ++j) {
                Rectangle &g_i1 = b1.getGene(j);
                Rectangle &g_i2 = b2.getGene(j);
                double flip_coin = this->prob_generator(this->generator);
                if (flip_coin >= 0.5){ //swap genes
                    temp_offset_x = g_i2.getOffsetX();
                    temp_offset_y = g_i2.getOffsetY();

                    g_i2.setOffsetX(g_i1.getOffsetX());
                    g_i2.setOffsetY(g_i1.getOffsetY());

                    g_i1.setOffsetX(temp_offset_x);
                    g_i1.setOffsetY(temp_offset_y);
                } // else keep your own genes
            }
        }
        next_generation.push_back(b1);
        next_generation.push_back(b2);
    }
    return next_generation;
}

void Population::setGenePool(const vector<Rectangle>& recs) {
    this->gene_pool = recs;
    for (auto const &ele: recs) {
        this->area += ele.getArea();
    }
    this->gene_count = recs.size();
}

vector<BoundingBox> Population::getCurrentPopulation() const {
    return this->individuals;
}

void Population::setCurrentPopulation(vector<BoundingBox> new_gen) {
    this->individuals = new_gen;
}

void Population::setDimensionHeuristic() {
    double root = sqrt(static_cast<double>(this->area));
    unsigned int dim = static_cast<unsigned int>(ceil(root));
    uniform_int_distribution<unsigned int> d(0, dim);
    this->dist = d;
}

void Population::initializePopulation() {
    for (unsigned int i = 0; i < this->population_count; ++i) {
        BoundingBox bb(this->initializeGenes(), this->area);
        bb.calculateFitness(this->penalty);
        this->avg_fitness += bb.getFitness();
        this->individuals.push_back(bb);
    }
    this->avg_fitness /= this->population_count;
}

vector<Rectangle>& Population::initializeGenes() {
    vector<Rectangle> &copy_gene_pool(this->gene_pool);
    for (auto &ele: copy_gene_pool) {
        ele.mutate(this->dist);
    }
    return copy_gene_pool;
}

void Population::mutate() {

}