//
// Created by morimoto on 17/06/02.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../AadFunctions.h"
using ::testing::AtLeast;
using ::testing::Eq;

class  AadFunctionTest : public ::testing::Test {
    virtual void SetUp() {
    }

public:
};

TEST_F(AadFunctionTest, addTest) {
    AdjointDual x(1.3);
    AdjointDual y(49.56);
    AdjointDual z = x + y;
    EXPECT_DOUBLE_EQ(z.deriv(x), 1.0);
}

TEST_F(AadFunctionTest, multi) {
    AdjointDual x(1.3);
    AdjointDual y(49.56);
    AdjointDual z = x * y;
    EXPECT_DOUBLE_EQ(z.deriv(x), y.value());
}

TEST_F(AadFunctionTest, minus) {
    AdjointDual x(1.3);
    AdjointDual y(49.56);
    AdjointDual z = x - y;
    EXPECT_DOUBLE_EQ(z.deriv(y), -1);
}