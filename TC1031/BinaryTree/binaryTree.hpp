class BinaryTree {
    public:
        class Node{
            public:
                int _data;
                Node *_left;
                Node* _right;
                Node();
                Node(int data);
            private:
        };
        BinaryTree();
        ~BinaryTree();
        bool insertNode(int data);
        bool insertNodeRecursively(int data);
        bool deleteNode();
        int* searchNode(int data);
        int* searchNodeExecution(Node* curNode, int data);

        int getHeight(int data);
        bool isEmpty();
        bool printAll();
        bool clear();
    private:
        Node* root;
        void printAllExecution(Node* node, int curDepth);
        bool insertNodeRecExecution(Node *&curNode, Node *newNode);
        void clearExecute(Node *&node);
};