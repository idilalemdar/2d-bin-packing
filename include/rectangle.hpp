//
// Created by cydonia on 8.11.2019.
//

#ifndef INC_2D_BIN_PACKING_RECTANGLE_H
#define INC_2D_BIN_PACKING_RECTANGLE_H

#include <random>
#include <algorithm>
#include <cmath>
<<<<<<< Updated upstream
=======
<<<<<<< HEAD
#include <iostream>
=======
>>>>>>> 8c5f838d1588112f04d135c76176c87e3fb7527d
>>>>>>> Stashed changes

using namespace std;

class Rectangle {
private:
    default_random_engine generator;
    unsigned int width;
    unsigned int height;
    unsigned int area;
    unsigned int offset_x;
    unsigned int offset_y;
    bool rotated;
    unsigned int id;
public:
    Rectangle(unsigned int, unsigned int, unsigned int);
    unsigned int getWidth() const;
    unsigned int getHeight() const;
    unsigned int getOffsetX() const;
    unsigned int getOffsetY() const;
    unsigned int getArea() const;
    unsigned int getID() const;
    void rotate();
    void setOffsetX(unsigned int);
    void setOffsetY(unsigned int);
    bool isRotated() const;
<<<<<<< Updated upstream
    void mutate(uniform_int_distribution<unsigned int>&);
=======
<<<<<<< HEAD
    void mutate(unsigned int);
=======
    void mutate(uniform_int_distribution<unsigned int>&);
>>>>>>> 8c5f838d1588112f04d135c76176c87e3fb7527d
>>>>>>> Stashed changes
};

#endif //INC_2D_BIN_PACKING_RECTANGLE_H
