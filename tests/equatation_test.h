#ifndef EQUATATION_TEST_H
#define EQUATATION_TEST_H

#include <gtest/gtest.h>

extern "C" {
#include "equatation.h"
}

TEST(equatationTest, num0) {
    ASSERT_EQ(equatation(1, 4, 4).flag, 2);
    ASSERT_NEAR(equatation(1, 4, 4).x1, -2.00, 0.001);
    ASSERT_NEAR(equatation(1, 4, 4).x2, -2.00, 0.001);
}

TEST(equatationTest, num1) {
    ASSERT_EQ(equatation(1, 1, 4).flag, 0);
}

TEST(equatationTest, num2) {
    ASSERT_EQ(equatation(0, 0, 2).flag, 0);
}

TEST(equatationTest, num3) {
    ASSERT_EQ(equatation(0, 2, 2).flag, 1);
    ASSERT_NEAR(equatation(0, 2, 2).x1, -1.00, 0.001);
}

TEST(equatationTest, num4) {
    ASSERT_EQ(equatation(0, 0, 1).flag, 0);
}

#endif // EQUATATION_TEST_H
