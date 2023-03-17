
#include "HuffmanTree.h"
#include <queue>
#include <functional>
#include <stack>


void HuffmanTree::buildTree(FrequencyTable &table) {
    std::priority_queue<Node *, std::vector<Node *>, decltype(&Node::nodePtrComparator)> pq(Node::nodePtrComparator);

    for (int i = 0; i < 256; ++i) {
        if (table.getFrequency(i) > 0) {
            pq.push(new Node((char) i, table.getFrequency(i)));
        }
    }

    while (pq.size() > 1) {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();

        Node *combined = *left + *right; // Use + operator overloading


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
            codeTable[(unsigned char) (node->getResp())] = code;
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
