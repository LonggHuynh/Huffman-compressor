class Node {
private:
    char resp;
    int freq;
    Node* left, * right;
public:
    Node(char symbol, int frequency);

    Node *getLeft();

    Node *getRight();

    // Overload + operator
    Node* operator+(const Node &other) const;



    // Set left child
    void setLeft(Node* left);

    // Set right child
    void setRight(Node* right);

    char getResp();

    static bool nodePtrComparator(const Node *lhs, const Node *rhs);

};
