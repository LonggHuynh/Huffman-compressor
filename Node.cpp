

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
Node* Node::operator+(const Node &other) const {
    // Add frequencies of the nodes and create a new node
    int newFreq = this->freq + other.freq;
    Node* newNode = new Node('\0', newFreq);

    // Set left and right pointers of the new node
    if (*this < other) {
        newNode->setLeft(const_cast<Node *>(this));
        newNode->setRight(const_cast<Node *>(&other));
    } else {
        newNode->setLeft(const_cast<Node *>(&other));
        newNode->setRight(const_cast<Node *>(this));
    }

    newNode->resp = newNode->getLeft()->resp;

    return newNode;
}
// Set left child
void Node::setLeft(Node* left) {
    this->left = left;
}

// Set right child
void Node::setRight(Node* right) {
    this->right = right;
}
// Overload < operator
bool Node::nodePtrComparator(const Node *lhs, const Node *rhs) {
    if (lhs->freq == rhs->freq) {
        return lhs->resp < rhs->resp;
    }
    return lhs->freq < rhs->freq;
}
