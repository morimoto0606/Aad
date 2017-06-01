//
// Created by morimoto on 17/06/02.
//

#ifndef SETTINGUPGOOGLETEST_TREE_H
#define SETTINGUPGOOGLETEST_TREE_H


#include <vector>
#include "Node.h"
#include <algorithm>

using node_ptr = std::shared_ptr<Node>;
class Tree {
public:
    static Tree& createInstance() {
        static Tree instance;
        return instance;
    }
    void pushBack(const node_ptr& node) {
        _nodes.push_back(node);}

    double getDerivative(
            const node_ptr& from
            , const node_ptr& to)
    {
        auto fromItr = std::find(_nodes.begin(),
        _nodes.end(), from);
        auto toItr = std::find(_nodes.begin(),
        _nodes.end(), to);

        (*toItr)->updateDTopByOwn(1.0);
        return backward(fromItr, toItr);
    }


private:
    double backward(std::vector<node_ptr>::iterator fromItr,
                    std::vector<node_ptr>::iterator toItr)
    {
        if (fromItr == toItr) {
            return (*fromItr)->getDTopByOwn();
        }
        for (auto edge : (*toItr)->getEdges()) {
            edge.first->updateDTopByOwn(
                    (*toItr)->getDTopByOwn() * edge.second);
            toItr = std::find(_nodes.begin(), _nodes.end(), edge.first);
            backward(fromItr, toItr);
        }
    }

    Tree() = default;
    ~Tree() = default;
private:
    std::vector<node_ptr> _nodes;

};


#endif //SETTINGUPGOOGLETEST_TREE_H
