class Node {
private:
    char resp;
    int freq;
    Node *left, *right;
public:
    Node(char symbol, int frequency);

    Node *getLeft();

    Node *getRight();


    int getFrequency();


    bool operator>(const Node &other) const;


    static Node *merge(Node *l, Node *r);

    static bool largerComparator(const Node *l, const Node *r);


    void setLeft(Node *left);

    void setRight(Node *right);

    char getResp();


};
