
#include "HuffmanTree.h"
#include "HuffmanTree.h"
#include <queue>
#include <functional>
#include <stack>

// Comparator for priority queue of Nodes
struct NodeComparator {
    bool operator()(const Node *lhs, const Node *rhs) const {
        return *lhs < *rhs;
    }
};

void HuffmanTree::buildTree(FrequencyTable &table) {
    std::priority_queue<Node *, std::vector<Node *>, NodeComparator> pq;

    for (int i = 0; i < 256; ++i) {
        if (table.getFrequency(i) > 0) {
            pq.push(new Node(static_cast<char>(i), table.getFrequency(i)));
        }
    }

    while (pq.size() > 1) {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();

        Node* combined = *left + *right; // Use + operator overloading


        pq.push(combined);
    }

    root = pq.top();
}

void HuffmanTree::buildCodeTable() {
    std::stack<std::pair<Node *, int>> stack;
    stack.push({root, 0});

    while (!stack.empty()) {
        auto current = stack.top();
        stack.pop();

        Node *node = current.first;
        int code = current.second;

        if (!node->getLeft() && !node->getRight()) {
            codeTable[static_cast<unsigned char>(node->getResp())] = code;
        }
        if (node->getLeft())
            stack.push({node->getLeft(), code << 1});
        if (node->getRight())
            stack.push({node->getRight(), code << 1 + 1});

    }
}

HuffmanTree::HuffmanTree(FrequencyTable &table) {
    buildTree(table);
    buildCodeTable();
}
