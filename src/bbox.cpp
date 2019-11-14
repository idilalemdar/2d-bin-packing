//
// Created by cydonia on 9.11.2019.
//

#include "bbox.hpp"

BoundingBox::BoundingBox(vector<Rectangle> recs, unsigned int totalArea) {
    this->rectangles = recs;
    this->targetArea = totalArea;
}

unsigned int BoundingBox::getTargetArea() const {
    return this->targetArea;
}

unsigned int BoundingBox::getCurrentArea() const {
    return this->width * this->height;
}

unsigned int BoundingBox::getFitness() const {
    return this->fitness;
}

void BoundingBox::calculateDimensions() {
    unsigned int maxDistanceX = 0;
    unsigned int maxDistanceY = 0;
    unsigned int minOffsetX = 2049;
    unsigned int minOffsetY = 2049;
    unsigned int currMaxX, currMaxY, currMinX, currMinY;
    for (auto const &r: this->rectangles) {
        currMinX = r.getOffsetX();
        currMinY = r.getOffsetY();
        currMaxX = currMinX + r.getWidth();
        currMaxY = currMinY + r.getHeight();
        if (currMaxX > maxDistanceX) {
            maxDistanceX = currMaxX;
        }
        if (currMaxY > maxDistanceY) {
            maxDistanceY = currMaxY;
        }
        if (currMinX < minOffsetX) {
            minOffsetX = currMinX;
        }
        if (currMinY < minOffsetY) {
            minOffsetY = currMinY;
        }
    }
    this->width = maxDistanceX - minOffsetX;
    this->height = maxDistanceY - minOffsetY;
}

unsigned int BoundingBox::overlap(const Rectangle& r1, const Rectangle& r2) {
    unsigned int r1_x = r1.getOffsetX();
    unsigned int r1_y = r1.getOffsetY();
    unsigned int r2_x = r2.getOffsetX();
    unsigned int r2_y = r2.getOffsetY();

    unsigned int r1_w = r1.getWidth();
    unsigned int r1_h = r1.getHeight();
    unsigned int r2_w = r2.getWidth();
    unsigned int r2_h = r2.getHeight();

    int r1beyondr2 = static_cast<int>(r1_x) - static_cast<int>(r2_w + r2_x);
    int r2beyondr1 = static_cast<int>(r2_x) - static_cast<int>(r1_w + r1_x);
    int r1above2 = static_cast<int>(r1_y) - static_cast<int>(r2_h + r2_y);
    int r2abover1 = static_cast<int>(r2_y) - static_cast<int>(r1_h + r1_y);

    if (r1beyondr2 >= 0 || r2beyondr1 >= 0 || r1above2 >= 0 || r2abover1 >= 0) {
        return 0;
    }
    else {
        return static_cast<unsigned int> (max(r1beyondr2, r2beyondr1) * max(r1above2, r2abover1));
    }
}

void BoundingBox::calculateFitness(unsigned int penalty) {
    unsigned int currentArea = this->getCurrentArea();
    unsigned int totalOverlappingArea = 0;
    int size = this->rectangles.size();
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            totalOverlappingArea += this->overlap(this->rectangles[i], this->rectangles[j]);
        }
    }
    this->fitness = currentArea + penalty * totalOverlappingArea;
}