//
// Created by cydonia on 9.11.2019.
//

#ifndef INC_2D_BIN_PACKING_BBOX_H
#define INC_2D_BIN_PACKING_BBOX_H

#include <vector>
#include <utility>
#include <algorithm>
#include "rectangle.hpp"

using namespace std;

class BoundingBox {
public:
    BoundingBox() {};
    BoundingBox(vector<Rectangle>, unsigned int);
    unsigned int getTargetArea() const;
    unsigned int getCurrentArea() const;
    unsigned int getFitness() const;
    Rectangle& getGene(unsigned int);
<<<<<<< Updated upstream
=======
<<<<<<< HEAD
=======
>>>>>>> Stashed changes
    void calculateDimensions();
>>>>>>> 8c5f838d1588112f04d135c76176c87e3fb7527d
    void calculateFitness(unsigned int);
private:
    vector<Rectangle> rectangles;
    unsigned int targetArea;
    unsigned int width;
    unsigned int height;
    unsigned int fitness;
    unsigned int overlap(const Rectangle&, const Rectangle&);
    void calculateDimensions();
};


#endif //INC_2D_BIN_PACKING_BBOX_H
