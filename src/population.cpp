//
// Created by cydonia on 14.11.2019.
//

#include "population.hpp"
#include "bbox.hpp"


Population::Population(double mr, double cr, unsigned int pop) {
    this->penalty = 5;
    this->area = 0;
    this->mutation_rate = mr;
    this->crossover_rate = cr;
    this->total_fitness = 0;
    this->population_count = pop;
}

unsigned int Population::getPopulationCount() const {
    return this->population_count;
}

void Population::setGenePool(const vector<Rectangle>& recs) {
    this->gene_pool = recs;
    for (auto const &ele: recs) {
        this->area += ele.getArea();
    }
    this->gene_count = recs.size();
}

unsigned int Population::getPenalty() const {
    return this->penalty;
}

unsigned int Population::getTargetArea() const {
    return this->area;
}

unsigned int Population::getTotalFitness() const {
    return this->total_fitness;
}

unsigned int Population::getGeneCount() const {
    return this->gene_count;
}

BoundingBox& Population::getBestIndividual() {
    return this->best_individual;
}

void Population::calculateFitness() {
    unsigned int best_fitness = MAX_UNSIGNED;
    unsigned int fitness;
    this->total_fitness = 0;
    for (auto &ele: this->individuals) {
        ele.calculateFitness(this->penalty);
        fitness = ele.getFitness();
        this->total_fitness += fitness;
        if (fitness < best_fitness) {
            best_fitness = fitness;
            this->best_individual = ele;
        }
    }
}

vector<BoundingBox>& Population::getCurrentPopulation() {
    return this->individuals;
}

void Population::setCurrentPopulation(vector<BoundingBox> new_gen) {
    this->individuals = new_gen;
}

vector<BoundingBox>& Population::getMatingPool() {
    return this->mating_pool;
}

void Population::setMatingPool(vector<BoundingBox> mates) {
    this->mating_pool = mates;
}

vector<BoundingBox>& Population::getOffspring() {
    return this->offsprings;
}

void Population::setOffspring(vector<BoundingBox> offs) {
    this->offsprings = offs;
}

void Population::shufflePopulation(){
    shuffle(this->mating_pool.begin(), this->mating_pool.end(), this->generator);
}

void Population::setDimensionHeuristic() {
    double root = sqrt(static_cast<double>(this->area));
    unsigned int dim = static_cast<unsigned int>(ceil(root));
    this->upper_bound = dim;
}

void Population::initializePopulation() {
    for (unsigned int i = 0; i < this->population_count; ++i) {
        BoundingBox bb(this->initializeGenes(), this->area);
        this->individuals.push_back(bb);
    }
}

vector<BoundingBox> Population::crossover(XOVER_MODE mode) {
    vector<BoundingBox> result;
    switch (mode) {
        case UNIFORM:
            result = uniform_crossover();
            break;
        case SINGLE_POINT:
            result = single_point_crossover();
            break;
        case K_POINT:
            result = k_point_crossover();
            break;
    }
    return result;
}

void Population::mutate() {
    for (unsigned int i = 0; i < this->population_count; ++i) {
        for (unsigned int j = 0; j < this->gene_count; ++j) {
            double prob = this->prob_generator(this->generator);
            if (prob <= this->mutation_rate) {
                Rectangle &gene = this->offsprings[i].getGene(j);
                gene.mutate(this->upper_bound);
            }
        }
    }
}

vector<BoundingBox> Population::k_point_crossover() {
    vector<BoundingBox> next_generation;
    unsigned int temp_offset_x, temp_offset_y;
    bool swap = false;
    vector<unsigned int> points = this->generateRandomPoints();
    for (unsigned int i = 0; i < this->population_count; i += 2) {
        BoundingBox b1(this->mating_pool[i]);
        BoundingBox b2(this->mating_pool[i+1]);
        double p_crossover = this->prob_generator(this->generator);
        if (p_crossover <= this->crossover_rate) {
            for (unsigned int j = 0; j < this->gene_count; ++j) {
                if (swap) {
                    Rectangle &g_i1 = b1.getGene(j);
                    Rectangle &g_i2 = b2.getGene(j);

                    temp_offset_x = g_i2.getOffsetX();
                    temp_offset_y = g_i2.getOffsetY();

                    g_i2.setOffsetX(g_i1.getOffsetX());
                    g_i2.setOffsetY(g_i1.getOffsetY());

                    g_i1.setOffsetX(temp_offset_x);
                    g_i1.setOffsetY(temp_offset_y);
                }
                if (find(points.begin(), points.end(), j) != points.end()) {
                    swap = !swap;
                }
            }
        }
        next_generation.push_back(b1);
        next_generation.push_back(b2);
    }
    return next_generation;
}

vector<BoundingBox> Population::single_point_crossover() {
    vector<BoundingBox> next_generation;
    unsigned int temp_offset_x, temp_offset_y;
    unsigned int start = this->gene_count / 2;
    for (unsigned int i = 0; i < this->population_count; i += 2) {
        BoundingBox b1(this->mating_pool[i]);
        BoundingBox b2(this->mating_pool[i+1]);
        double p_crossover = this->prob_generator(this->generator);
        if (p_crossover <= this->crossover_rate) {
            for (unsigned int j = start; j < this->gene_count; ++j) {
                Rectangle &g_i1 = b1.getGene(j);
                Rectangle &g_i2 = b2.getGene(j);

                temp_offset_x = g_i2.getOffsetX();
                temp_offset_y = g_i2.getOffsetY();

                g_i2.setOffsetX(g_i1.getOffsetX());
                g_i2.setOffsetY(g_i1.getOffsetY());

                g_i1.setOffsetX(temp_offset_x);
                g_i1.setOffsetY(temp_offset_y);
            }
        }
        next_generation.push_back(b1);
        next_generation.push_back(b2);
    }
    return next_generation;
}

vector<BoundingBox> Population::uniform_crossover() {
    vector <BoundingBox> next_generation;
    unsigned int temp_offset_x, temp_offset_y;
    for (unsigned int i = 0; i < this->population_count; i += 2) {
        BoundingBox b1(this->mating_pool[i]);
        BoundingBox b2(this->mating_pool[i + 1]);
        double p_crossover = this->prob_generator(this->generator);
        if (p_crossover <= this->crossover_rate) {
            for (unsigned int j = 0; j < this->gene_count; ++j) {
                Rectangle &g_i1 = b1.getGene(j);
                Rectangle &g_i2 = b2.getGene(j);
                double flip_coin = this->prob_generator(this->generator);
                if (flip_coin >= 0.5) { //swap genes
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

vector<Rectangle>& Population::initializeGenes() {
    vector<Rectangle> &copy_gene_pool(this->gene_pool);
    for (auto &ele: copy_gene_pool) {
        ele.mutate(this->upper_bound);
    }
    return copy_gene_pool;
}

vector<unsigned int> Population::generateRandomPoints() {
    unsigned int pt;
    unsigned int i = 0;
    vector<unsigned int> pts;
    uniform_int_distribution<unsigned int> points_dist(0, this->gene_count - 1);
    while (i < this->k) {
        pt = points_dist(this->generator);
        if (find(pts.begin(), pts.end(), pt) == pts.end()) {
            pts.push_back(pt);
            i++;
        }
    }
    sort(pts.begin(), pts.end());
    return pts;
}