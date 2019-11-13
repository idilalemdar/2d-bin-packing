//
// Created by cydonia on 9.11.2019.
//

#ifndef INC_2D_BIN_PACKING_BBOX_H
#define INC_2D_BIN_PACKING_BBOX_H

#include <vector>
#include <utility>
#include "rectangle.hpp"

using namespace std;

class BoundingBox {
public:
    BoundingBox(vector<Rectangle>);
    unsigned int getPenalty() const;
    unsigned int getTargetArea() const;
    unsigned int getCurrentArea() const;
    unsigned int getFitness() const;
    void setPenalty(unsigned int);
    void calculateDimensions();
    void calculateFitness();
private:
    vector<Rectangle> rectangles;
    unsigned int target_area;
    unsigned int penalty;
    unsigned int width;
    unsigned int height;
    unsigned int fitness;
    unsigned int overlap(const Rectangle&, const Rectangle&);
};


#endif //INC_2D_BIN_PACKING_BBOX_H
