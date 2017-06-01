//
// Created by morimoto on 17/06/02.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>
#include "../Node.h"
#include <map>
#include <memory>

using ::testing::AtLeast;
using ::testing::Eq;
using testing::AtMost;

class NodeTest : public ::testing::Test {

public:
    virtual void SetUp() {
        Node n1;
        Node n2;
        std::map<std::shared_ptr<Node>, double> edge;
        edge.emplace(std::make_shared<Node>(n1), 2.0);
        edge.emplace(std::make_shared<Node>(n2), 3.4);
        Node n3(edge);
        _node = std::make_shared<Node>(n3);
    }
    std::shared_ptr<Node> _node;
};

TEST_F(NodeTest, construct) {
    EXPECT_DOUBLE_EQ(_node->getDTopByOwn(), 0.0);
}