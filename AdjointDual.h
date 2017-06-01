//
// Created by morimoto on 17/06/02.
//

#ifndef SETTINGUPGOOGLETEST_ADJOINTDUAL_H
#define SETTINGUPGOOGLETEST_ADJOINTDUAL_H

#include "Tree.h"
#include "Node.h"

using node_ptr = std::shared_ptr<Node>;
class AdjointDual {
public:
    AdjointDual(const double value,
    const node_ptr& node) : _value(value), _node(node){
        Tree& instance = Tree::createInstance();
        instance.pushBack(_node);
    }

    AdjointDual(const double value) :
            _value(value), _node(std::make_shared<Node>()){
        Tree& instance = Tree::createInstance();
        instance.pushBack(_node);
    }

    double deriv(const AdjointDual& from) {
        Tree& instance = Tree::createInstance();
        return instance.getDerivative(from._node, _node);
    }
    double value() const { return _value;}
    node_ptr node() const { return _node;}

private:
    double _value;
    node_ptr _node;


 };


#endif //SETTINGUPGOOGLETEST_ADJOINTDUAL_H
