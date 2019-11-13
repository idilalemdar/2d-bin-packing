//
// Created by cydonia on 9.11.2019.
//

#include "bbox.hpp"

BoundingBox::BoundingBox(vector<Rectangle> recs) {
    this->penalty = 5;
    this->rectangles = recs;
    unsigned int area_sum = 0;
    for (auto const &r: recs){
        area_sum += r.getArea();
    }
    this->target_area = area_sum;
}

unsigned int BoundingBox::getPenalty() const {
    return this->penalty;
}

unsigned int BoundingBox::getTargetArea() const {
    return this->target_area;
}

unsigned int BoundingBox::getCurrentArea() const {
    return this->width * this->height;
}

unsigned int BoundingBox::getFitness() const {
    return this->fitness;
}

void BoundingBox::setPenalty(unsigned int p) {
    this->penalty = p;
}

void BoundingBox::calculateDimensions() {
    unsigned int maxX = 0;
    unsigned int maxY = 0;
    unsigned int currX, currY;
    for (auto const &r: this->rectangles) {
        currX = r.getOffsetX() + r.getWidth();
        currY = r.getOffsetY() + r.getHeight();
        if (currX > maxX) {
            maxX = currX;
        }
        if (currY > maxY) {
            maxY = currY;
        }
    }
    this->width = maxX;
    this->height = maxY;
}

unsigned int BoundingBox::overlap(const Rectangle& r1, const Rectangle& r2) {
    // TODO: Implement
    return 0;
}

void BoundingBox::calculateFitness() {
    unsigned int currentArea = this->getCurrentArea();
    unsigned int totalOverlappingArea = 0;
    int size = this->rectangles.size();
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            totalOverlappingArea += this->overlap(this->rectangles[i], this->rectangles[j]);
        }
    }
    this->fitness = currentArea + this->penalty * totalOverlappingArea;
}