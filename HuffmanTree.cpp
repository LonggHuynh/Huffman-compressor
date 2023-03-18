
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

        Node *combined = Node::merge(left, right);


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


std::array<char16_t, 256> HuffmanTree::originalCode() {
    return this->codeTable;
}

std::array<char16_t, 256> HuffmanTree::canonicalCode() {
    std::array<char16_t, 256> canonicalCodes;

    // Sort the symbols based on their code lengths
    std::vector<std::pair<unsigned char, int>> symbols;
    for (int i = 0; i < 256; ++i) {
        int codeLen = std::to_string(codeTable[i]).length();
        if (codeLen > 0) {
            symbols.push_back({(unsigned char) i, codeLen});
        }
    }
    std::sort(symbols.begin(), symbols.end(),
              [](const std::pair<unsigned char, int> &a, const std::pair<unsigned char, int> &b) {
                  return a.second < b.second || (a.second == b.second && a.first < b.first);
              });

    // Generate canonical codes
    int currentCode = 0;
    int prevLen = symbols[0].second;
    for (const auto &symbol: symbols) {
        while (prevLen < symbol.second) {
            currentCode <<= 1;
            ++prevLen;
        }
        canonicalCodes[symbol.first] = currentCode;
        ++currentCode;
    }

    return canonicalCodes;
}


HuffmanTree::HuffmanTree(FrequencyTable &table) {
    buildTree(table);
    buildCodeTable();
}



