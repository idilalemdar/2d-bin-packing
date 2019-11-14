//
// Created by cydonia on 9.11.2019.
//

#include "bbox.hpp"
#include "rectangle.hpp"
#include <gtest/gtest.h>

TEST(BBoxTest, Constructor) {
    vector<Rectangle> r1;
    r1.push_back(Rectangle(3,4));
    BoundingBox b1(r1, 12);
    EXPECT_EQ(b1.getTargetArea(), 12);
}

TEST(BBoxTest, ConstructorMultipleRectangles) {
    vector<Rectangle> r1;
    r1.push_back(Rectangle(2,8));
    r1.push_back(Rectangle(8,2));
    r1.push_back(Rectangle(4,4));
    r1.push_back(Rectangle(2,4));
    r1.push_back(Rectangle(6,4));
    r1.push_back(Rectangle(2,2));
    r1.push_back(Rectangle(4,3));
    r1.push_back(Rectangle(4,1));
    BoundingBox b1(r1, 100);
    EXPECT_EQ(b1.getTargetArea(), 100);
}

TEST(BBoxTest, calculateDimensionsSubOptimal) {
    vector<Rectangle> r;
    Rectangle r1 = Rectangle(2,8);
    Rectangle r2 = Rectangle(8,2);
    Rectangle r3 = Rectangle(4,4);
    Rectangle r4 = Rectangle(2,4);
    Rectangle r5 = Rectangle(6,4);
    Rectangle r6 = Rectangle(2,2);
    Rectangle r7 = Rectangle(4,3);
    Rectangle r8 = Rectangle(4,1);

    r2.rotate();
    r2.setOffsetX(2);
    r2.setOffsetY(4);

    r3.setOffsetX(8);
    r3.setOffsetY(7);

    r4.setOffsetX(6);
    r4.setOffsetY(2);

    r5.rotate();
    r5.setOffsetX(8);

    r6.setOffsetX(8);
    r6.setOffsetY(6);

    r7.setOffsetX(4);

    r8.rotate();
    r8.setOffsetX(6);
    r8.setOffsetY(6);

    r.push_back(r1);
    r.push_back(r2);
    r.push_back(r3);
    r.push_back(r4);
    r.push_back(r5);
    r.push_back(r6);
    r.push_back(r7);
    r.push_back(r8);

    unsigned int area = 0;
        for(auto const &ele: r) {
        area += ele.getArea();
    }

    BoundingBox b1(r, area);
    b1.calculateDimensions();
    b1.calculateFitness(5);
    EXPECT_EQ(b1.getCurrentArea(), 144);
    EXPECT_EQ(b1.getFitness(), 164);
}

TEST(BBoxTest, calculateDimensionsOptimal) {
    vector<Rectangle> r;
    Rectangle r1 = Rectangle(2,8);
    Rectangle r2 = Rectangle(8,2);
    Rectangle r3 = Rectangle(4,4);
    Rectangle r4 = Rectangle(2,4);
    Rectangle r5 = Rectangle(6,4);
    Rectangle r6 = Rectangle(2,2);
    Rectangle r7 = Rectangle(4,3);
    Rectangle r8 = Rectangle(4,1);

    r2.setOffsetY(8);

    r3.setOffsetX(2);

    r4.setOffsetX(2);
    r4.setOffsetY(4);

    r5.setOffsetX(4);
    r5.setOffsetY(4);

    r6.setOffsetX(8);
    r6.setOffsetY(8);

    r7.setOffsetX(6);

    r8.setOffsetX(6);
    r8.setOffsetY(3);

    r.push_back(r1);
    r.push_back(r2);
    r.push_back(r3);
    r.push_back(r4);
    r.push_back(r5);
    r.push_back(r6);
    r.push_back(r7);
    r.push_back(r8);

    unsigned int area = 0;
    for(auto const &ele: r) {
        area += ele.getArea();
    }

    BoundingBox b1(r, area);
    b1.calculateDimensions();
    b1.calculateFitness(5);
    EXPECT_EQ(b1.getTargetArea(), 100);
    EXPECT_EQ(b1.getFitness(), b1.getTargetArea());
    EXPECT_EQ(b1.getCurrentArea(), b1.getTargetArea());

}

TEST(BBoxTest, calculateDimensionsOptimalShifted) {
    vector<Rectangle> r;
    Rectangle r1 = Rectangle(2,8);
    Rectangle r2 = Rectangle(8,2);
    Rectangle r3 = Rectangle(4,4);
    Rectangle r4 = Rectangle(2,4);
    Rectangle r5 = Rectangle(6,4);
    Rectangle r6 = Rectangle(2,2);
    Rectangle r7 = Rectangle(4,3);
    Rectangle r8 = Rectangle(4,1);

    r2.setOffsetY(8);

    r3.setOffsetX(2);

    r4.setOffsetX(2);
    r4.setOffsetY(4);

    r5.setOffsetX(4);
    r5.setOffsetY(4);

    r6.setOffsetX(8);
    r6.setOffsetY(8);

    r7.setOffsetX(6);

    r8.setOffsetX(6);
    r8.setOffsetY(3);

    r.push_back(r1);
    r.push_back(r2);
    r.push_back(r3);
    r.push_back(r4);
    r.push_back(r5);
    r.push_back(r6);
    r.push_back(r7);
    r.push_back(r8);

    unsigned int area = 0;
    for(auto &ele: r) {
        area += ele.getArea();
        ele.setOffsetX(ele.getOffsetX() + 2);
        ele.setOffsetY(ele.getOffsetY() + 4);
    }

    BoundingBox b1(r, area);
    b1.calculateDimensions();
    b1.calculateFitness(5);
    EXPECT_EQ(b1.getTargetArea(), 100);
    EXPECT_EQ(b1.getFitness(), b1.getTargetArea());
    EXPECT_EQ(b1.getCurrentArea(), b1.getTargetArea());
}