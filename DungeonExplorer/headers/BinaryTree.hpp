/*class BinaryTree{
public:
    class Node{
        public:
            Monster _data;
            Node *_left;
            Node* _right;
            Node();
            Node(Monster monster);
        private:
    };
    BinaryTree();
    ~BinaryTree();
public:
    bool insertNode(Monster monster);
    bool insertNodeRecursively(Monster monster);
    bool deleteNode(Monster monster);
    bool searchNode(Monster monster);
    bool isEmpty();
    bool printAll();
    bool clear();
private:
    Node* root;
    bool searchNodeExecution(Node* curNode, int data);
    void printAllExecution(Node* node, int curDepth);
    bool insertNodeRecExecution(Node *&curNode, Node *newNode);
    void clearExecute(Node *&node);
    bool findNodeToDelete(Node *&node, int data);
    void deleteNodeExecute(Node *&node);
    Node*& findMinNode(Node *&node);
};*/