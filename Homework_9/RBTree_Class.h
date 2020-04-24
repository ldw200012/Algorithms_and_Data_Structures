
enum Color { RED, BLACK };
struct Node {
    Node(Color colo) : color(colo) {}
    int data;
    Color color;
    Node* left, * right, * parent;
};

class RedBlackTree {
private:
    Node* root;
    Node* nil = new Node(BLACK);
protected:
    void rotateLeft(Node* z);
    void rotateRight(Node* z);
public:
    RedBlackTree();
    void insertNode(int data);
    void deleteNode(Node* tobeDeleted);
    Node* predecessor(const Node* z);
    Node* successor(const Node* z);
    Node* getMinimum();
    Node* getMaximum();
    Node* search(int data);

    void RB_Insert_FixUp(Node *z);
    void Transplant(Node* z, Node* x);
    void RB_Delete_FixUp(Node* x);
};

