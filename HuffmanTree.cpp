
#include "HuffmanTree.h"
#include "Utils.h"
#include <queue>
#include <functional>
#include <stack>


void HuffmanTree::buildTree(FrequencyTable &table) {
    std::priority_queue<Node *, std::vector<Node *>, decltype(&Node::largerComparator)> pq(Node::largerComparator);

    for (int symbol = 0; symbol < 256; ++symbol) {
        if (table.getFrequency(symbol) > 0) {
            pq.push(new Node((char) symbol, table.getFrequency(symbol)));
        }
    }

    while (pq.size() > 1) {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();

        Node *combined = Node::merge(left, right);
        pq.push(combined);
    }

    root = pq.top();

    //Special case, only one character, which causes the empty code when encoded. This is handled by creating make it a child of a fake node.
    if (!root->getLeft()) {
        Node *newNode = new Node(root->getResp(), root->getFrequency());
        newNode->setLeft(root);
        root = newNode;
    }
}


void HuffmanTree::buildCodeTable() {
    std::stack<std::pair<Node *, int>> stack;
    codeLengthTable.fill(0);
    stack.push({root, 0});

    while (!stack.empty()) {
        auto current = stack.top();
        stack.pop();

        Node *node = current.first;
        int currentLen = current.second;

        if (!node->getLeft() && !node->getRight()) {
            codeLengthTable[(unsigned char) (node->getResp())] = currentLen;
        }
        if (node->getLeft())
            stack.push({node->getLeft(), currentLen + 1});
        if (node->getRight())
            stack.push({node->getRight(), currentLen + 1});
    }

}


std::array<int, 256> HuffmanTree::getCodeLengthTable() {
    return codeLengthTable;
}


HuffmanTree::HuffmanTree(const FrequencyTable &table) : frequencyTable(table) {
    buildTree(frequencyTable);
    buildCodeTable();
}








