/**
 * @file Node.h
 * @brief This file provides the Node class for representing nodes in a binary tree.
 */

#ifndef NODE_H
#define NODE_H

/**
 * @class Node
 * @brief The Node class represents a node in a binary tree with frequency and character data.
 *
 * This class is used for building binary trees, such as Huffman trees, for compression and
 * decompression algorithms. Each node stores a character, its frequency, and pointers to its
 * left and right children.
 */
class Node {
private:
    char resp;
    int freq;
    Node *left, *right;

public:
    /**
     * @brief Constructs a new Node object with the given character and frequency.
     *
     * @param symbol The character to be stored in the node.
     * @param frequency The frequency of the character.
     */
    Node(char symbol, int frequency);

    /**
     * @brief Returns a pointer to the left child of the node.
     *
     * @return A pointer to the left child of the node.
     */
    Node *getLeft();

    /**
     * @brief Returns a pointer to the right child of the node.
     *
     * @return A pointer to the right child of the node.
     */
    Node *getRight();

    /**
     * @brief Returns the frequency of the character stored in the node.
     *
     * @return The frequency of the character.
     */
    int getFrequency();



    /**
     * @brief Merges two nodes into a new parent node with the combined frequency.
     *
     * @param l Pointer to the left child node.
     * @param r Pointer to the right child node.
     * @return A pointer to the new parent node with the combined frequency.
     */
    static Node *merge(Node *l, Node *r);

    /**
     * @brief Comparator function for comparing two nodes based on their frequencies (in descending order).
     *
     * @param l Pointer to the first Node object.
     * @param r Pointer to the second Node object.
     * @return true if the frequency of the first node is larger than the frequency of the second node,
     *         false otherwise.
     */
    static bool largerComparator(const Node *l, const Node *r);

    /**
     * @brief Sets the left child of the node.
     *
     * @param left Pointer to the new left child node.
     */
    void setLeft(Node *left);

    /**
     * @brief Sets the right child of the node.
     *
     * @param right Pointer to the new right child node.
     */
    void setRight(Node *right);

    /**
     * @brief Returns the character stored in the node.
     *
     * @return The character stored in the node.
     */
    char getResp();
};

#endif // NODE_H
