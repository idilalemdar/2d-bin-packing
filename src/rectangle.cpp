//
// Created by cydonia on 8.11.2019.
//

#include "rectangle.hpp"

Rectangle::Rectangle(unsigned int w, unsigned int h, unsigned int i) {
    this->width = w;
    this->height = h;
    this->area = w * h;
    this->offset_x = 0;
    this->offset_y = 0;
    this->rotated = false;
    this->id = i;

}

unsigned int Rectangle::getArea() const {
    return this->area;
}

unsigned int Rectangle::getWidth() const {
    return this->width;
}

unsigned int Rectangle::getHeight() const {
    return this->height;
}

unsigned int Rectangle::getOffsetX() const {
    return this->offset_x;
}

unsigned int Rectangle::getOffsetY() const {
    return this->offset_y;
}

unsigned int Rectangle::getID() const {
    return this->id;
}

bool Rectangle::isRotated() const {
    return this->rotated;
}

void Rectangle::rotate() {
    if(this->width != this->height) {  // Operation is not valid for squares
        this->rotated = !this->rotated;
        this->width = this->width ^ this->height;
        this->height = this->width ^ this->height;
        this->width = this->width ^ this->height;
    }
}

void Rectangle::mutate(unsigned int upper_bound) {
    uniform_int_distribution<unsigned int> dist(0, upper_bound);
    unsigned int offset_x = dist(this->generator);
    unsigned int offset_y = dist(this->generator);
    this->setOffsetX(offset_x);
    this->setOffsetY(offset_y);
    this->rotate();
}

void Rectangle::setOffsetX(unsigned int ox) {
    this->offset_x = ox;
}

void Rectangle::setOffsetY(unsigned int oy) {
    this->offset_y = oy;
}