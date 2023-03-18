

#include <algorithm>
#include "Node.h"

Node::Node(char symbol, int frequency) : resp(symbol), freq(frequency), left(nullptr), right(nullptr) {}

Node *Node::getLeft() {
    return left;
}

Node *Node::getRight() {
    return right;
}

char Node::getResp() {
    return resp;
}

// Overload + operator
Node *Node::merge(Node *l, Node *r) {
    // Add frequencies of the nodes and create a new node
    if (!nodePtrComparator(l, r)) {
        std::swap(l, r);
    }

    int newFreq = l->freq + r->freq;
    Node *newNode = new Node(l->resp, newFreq);

    // Set left and right pointers of the new node
    newNode->setLeft(l);
    newNode->setRight(r);

    return newNode;
}

// Set left child
void Node::setLeft(Node *left) {
    this->left = left;
}

// Set right child
void Node::setRight(Node *right) {
    this->right = right;
}

// Overload < operator
bool Node::nodePtrComparator(const Node *lhs, const Node *rhs) {
    if (lhs->freq == rhs->freq) {
        return lhs->resp < rhs->resp;
    }
    return lhs->freq < rhs->freq;
}
