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
    ASSERT_FALSE(r1.isRotated());
}

TEST(RectangleTest, Rotate) {
    Rectangle r1(3,4);
    r1.rotate();
    EXPECT_EQ(r1.getWidth(), 4);
    EXPECT_EQ(r1.getHeight(), 3);
    EXPECT_EQ(r1.getArea(), 12);
    ASSERT_TRUE(r1.isRotated());
}

TEST(RectangleTest, RotateTwice) {
    Rectangle r1(3,4);
    r1.rotate();
    r1.rotate();
    EXPECT_EQ(r1.getWidth(), 3);
    EXPECT_EQ(r1.getHeight(), 4);
    EXPECT_EQ(r1.getArea(), 12);
    ASSERT_FALSE(r1.isRotated());
}

TEST(RectangleTest, SetOffsets) {
    Rectangle r1(3,4);
    r1.setOffsetX(5);
    r1.setOffsetY(7);
    EXPECT_EQ(r1.getOffsetX(), 5);
    EXPECT_EQ(r1.getOffsetY(), 7);
}

TEST(RectangleTest, RotateSquare) {
    Rectangle r(4,4);
    r.rotate();
    ASSERT_FALSE(r.isRotated());
}

TEST(RectangleTest, Commutativity) {
    Rectangle r1(8,2);
    r1.rotate();
    r1.setOffsetX(2);
    r1.setOffsetY(4);

    Rectangle r2(8,2);
    r2.setOffsetX(2);
    r2.setOffsetY(4);
    r2.rotate();

    EXPECT_EQ(r1.getWidth(), r2.getWidth());
    EXPECT_EQ(r1.getHeight(), r2.getHeight());
}