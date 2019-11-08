//
// Created by cydonia on 8.11.2019.
//

#include "rectangle.hpp"

Rectangle::Rectangle(unsigned int w, unsigned int h) {
    this->width = w;
    this->height = h;
    this->area = w * h;
    this->offset_x = 0;
    this->offset_y = 0;
    this->original = true;
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

void Rectangle::rotate() {
    this->original = !this->original;
    this->width = this->width ^ this->height;
    this->height = this->width ^ this->height;
    this->width = this->width ^ this->height;
}

bool Rectangle::isRotated() const {
    return this->original;
}