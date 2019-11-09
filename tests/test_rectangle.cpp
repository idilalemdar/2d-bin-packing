//
// Created by cydonia on 8.11.2019.
//

#include "rectangle.hpp"
#include <gtest/gtest.h>

TEST(RectangleTest, Constructor) {
    Rectangle r1(3,4);
    EXPECT_EQ(r1.getWidth(), 3);
    EXPECT_EQ(r1.getHeight(), 4);
    EXPECT_EQ(r1.getArea(), 12);
    EXPECT_EQ(r1.getOffsetX(), 0);
    EXPECT_EQ(r1.getOffsetY(), 0);
    EXPECT_EQ(r1.isRotated(), false);
}

TEST(RectangleTest, Rotate) {
    Rectangle r1(3,4);
    r1.rotate();
    EXPECT_EQ(r1.getWidth(), 4);
    EXPECT_EQ(r1.getHeight(), 3);
    EXPECT_EQ(r1.getArea(), 12);
    EXPECT_EQ(r1.isRotated(), true);
}

TEST(RectangleTest, RotateTwice) {
    Rectangle r1(3,4);
    r1.rotate();
    r1.rotate();
    EXPECT_EQ(r1.getWidth(), 3);
    EXPECT_EQ(r1.getHeight(), 4);
    EXPECT_EQ(r1.getArea(), 12);
    EXPECT_EQ(r1.isRotated(), false);
}

TEST(RectangleTest, SetOffsets) {
    Rectangle r1(3,4);
    r1.setOffsetX(5);
    r1.setOffsetY(7);
    EXPECT_EQ(r1.getOffsetX(), 5);
    EXPECT_EQ(r1.getOffsetY(), 7);
}