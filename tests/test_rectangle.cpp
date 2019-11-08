//
// Created by cydonia on 8.11.2019.
//

#include "rectangle.hpp"
#include <gtest/gtest.h>

TEST(RectangleTest, Constructor) {
    Rectangle r1(3,4);
    EXPECT_EQ(r1.getWidth(), 3);
    EXPECT_EQ(r1.getHeight(), 4);
}