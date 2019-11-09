//
// Created by cydonia on 8.11.2019.
//

#ifndef INC_2D_BIN_PACKING_RECTANGLE_H
#define INC_2D_BIN_PACKING_RECTANGLE_H

class Rectangle {
private:
    unsigned int width;
    unsigned int height;
    unsigned int area;
    unsigned int offset_x;
    unsigned int offset_y;
    bool rotated;
public:
    Rectangle(unsigned int, unsigned int);
    unsigned int getWidth() const;
    unsigned int getHeight() const;
    unsigned int getOffsetX() const;
    unsigned int getOffsetY() const;
    unsigned int getArea() const;
    void rotate();
    void setOffsetX(unsigned int);
    void setOffsetY(unsigned int);
    bool isRotated() const;
};

#endif //INC_2D_BIN_PACKING_RECTANGLE_H
