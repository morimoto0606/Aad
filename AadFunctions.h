//
// Created by morimoto on 17/06/02.
//

#ifndef SETTINGUPGOOGLETEST_AADFUNCTIONS_H
#define SETTINGUPGOOGLETEST_AADFUNCTIONS_H

#include "AdjointDual.h"
using node_ptr = std::shared_ptr<Node>;
inline AdjointDual operator +(const AdjointDual& x, const AdjointDual& y)
{
    double value = x.value() + y.value();
    std::map<node_ptr, double> edges;
    edges.emplace(x.node(), 1.0);
    edges.emplace(y.node(), 1.0);
    node_ptr node = std::make_shared<Node>(edges);

    return AdjointDual(value, node);
}

inline AdjointDual operator -(const AdjointDual& x, const AdjointDual& y)
{
    double value = x.value() - y.value();
    std::map<node_ptr, double> edges;
    edges.emplace(x.node(), 1.0);
    edges.emplace(y.node(), -1.0);
    node_ptr node = std::make_shared<Node>(edges);

    return AdjointDual(value, node);
}

inline AdjointDual operator *(const AdjointDual& x, const AdjointDual& y)
{
    double value = x.value() * y.value();
    std::map<node_ptr, double> edges;
    edges.emplace(x.node(), y.value());
    edges.emplace(y.node(), x.value());
    node_ptr node = std::make_shared<Node>(edges);

    return AdjointDual(value, node);
}

#endif //SETTINGUPGOOGLETEST_AADFUNCTIONS_H
