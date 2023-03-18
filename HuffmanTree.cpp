
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
}

void HuffmanTree::buildCodeTable() {
    std::stack<std::pair<Node *, int>> stack;
    codeTable.fill(0);
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
            stack.push({node->getRight(), (code << 1) + 1});

    }
}


std::array<char16_t, 256> HuffmanTree::originalCodes() {
    return this->codeTable;
}

std::array<char16_t, 256> HuffmanTree::canonicalCodes() {
    std::array<char16_t, 256> canonicalCodes;
    canonicalCodes.fill(0);
    // Sort the symbols based on their code lengths
    std::vector<std::pair<unsigned char, int>> symbols;
    for (int symbol = 0; symbol < 256; ++symbol) {
        if (frequencyTable.getFrequency(symbol)) {
            int codeLen = Utils::bitLength(codeTable[symbol]);
            symbols.push_back({(unsigned char) symbol, codeLen});
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


HuffmanTree::HuffmanTree(const FrequencyTable &table) : frequencyTable(table) {
    buildTree(frequencyTable);
    buildCodeTable();
}



