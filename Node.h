//
// Created by morimoto on 17/06/02.
//

#ifndef SETTINGUPGOOGLETEST_NODE_H
#define SETTINGUPGOOGLETEST_NODE_H


#include <map>
#include <memory>

class Node {
public:
    Node(): _dTopByOwn(0.0),
            _edges(std::map<std::shared_ptr<Node>, double>()) {}
    Node(const std::map<std::shared_ptr<Node>, double>& edges)
            : _dTopByOwn(0.0), _edges(edges) {}

    void updateDTopByOwn(const double d) {
        _dTopByOwn += d;
    }
    double getDTopByOwn() const
    {
        return _dTopByOwn;
    };
    std::map<std::shared_ptr<Node>, double> getEdges() const {
        return _edges;
    };

private:
    double _dTopByOwn;
    std::map<std::shared_ptr<Node>, double> _edges;

};


#endif //SETTINGUPGOOGLETEST_NODE_H
