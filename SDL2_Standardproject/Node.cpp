//
// Created by clement on 01/06/17.
//

#include "Node.h"

Node::Node() : Node{-1, -1} {}

Node::Node(int _grid_x, int _grid_y, NodeType _type) : grid_x{_grid_x}, grid_y{_grid_y}, type{_type} {}

Node::Node(const Node &node) : grid_x{node.grid_x}, grid_y{node.grid_y}, type{node.type} {}

Node::Node(Node &&node) : grid_x{node.grid_x}, grid_y{node.grid_y}, type{node.type} {
    node.grid_x = 0;
    node.grid_y = 0;
}

Node &Node::operator=(const Node &node) {
    grid_x = node.grid_x;
    grid_y = node.grid_y;
    type = node.type;
    return *this;
}

Node &Node::operator=(Node &&node) {
    grid_x = node.grid_x;
    grid_y = node.grid_y;
    type = node.type;
    return *this;
}

bool operator==(Node lhs, Node rhs) {
    return lhs.is(rhs.type) &&
           lhs.grid_x == rhs.grid_x &&
           lhs.grid_y == rhs.grid_y;
}

bool operator!=(Node lhs, Node rhs) {
    return !lhs.is(rhs.type) ||
           lhs.grid_x != rhs.grid_x ||
           lhs.grid_y != rhs.grid_y;
}

bool Node::is(NodeType &_type) const {
    return type == _type;
}

Node::~Node() {

}

