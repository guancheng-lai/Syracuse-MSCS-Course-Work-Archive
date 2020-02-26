//
// Created by Guancheng Lai on 1/25/20.
//

#include "gtest/gtest.h"
#include "../main.cpp"
#include <vector>
#include <algorithm>
using std::vector;

class MergeTest : public ::testing::Test {
public:
    node * n1;

    void foo() {
        n1 = new node(10);
    }
};
TEST_F(MergeTest, example) {
    EXPECT_EQ(n1->value, 10);
}
