

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

Node *Node::merge(Node *l, Node *r) {
    //To make the tree unique, the havier node is on the right.
    if (largerComparator(l, r)) {
        std::swap(l, r);
    }

    int newFreq = l->freq + r->freq;
    Node *newNode = new Node(l->resp, newFreq);

    newNode->setLeft(l);
    newNode->setRight(r);

    return newNode;
}

void Node::setLeft(Node *left) {
    this->left = left;
}

void Node::setRight(Node *right) {
    this->right = right;
}

int Node::getFrequency() {
    return freq;
}

bool Node::largerComparator(const Node *lhs, const Node *rhs) {
    if (lhs->freq == rhs->freq) {
        return lhs->resp > rhs->resp;
    }
    return lhs->freq > rhs->freq;
}
