//
// Created by cydonia on 14.11.2019.
//

#include <gtest/gtest.h>
#include "population.hpp"

TEST(RectangleTest, Construct) {
    vector<Rectangle> r1;
    r1.push_back(Rectangle(2,8));
    r1.push_back(Rectangle(8,2));
    r1.push_back(Rectangle(4,4));
    r1.push_back(Rectangle(2,4));
    r1.push_back(Rectangle(6,4));
    r1.push_back(Rectangle(2,2));
    r1.push_back(Rectangle(4,3));
    r1.push_back(Rectangle(4,1));

    Population p(0.7, 0.1, 50, STATIC);
    EXPECT_EQ(p.getAverageFitness(), 0);
    EXPECT_EQ(p.getPopulationCount(), 50);
    EXPECT_EQ(p.getCurrentGeneration(), 0);
    EXPECT_EQ(p.getPenalty(), 5);
}
