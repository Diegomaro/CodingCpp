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
        bool insertNodeRec(int data);
        bool deleteNode();
        int* searchNode();
        int getHeight(int data);
        bool isEmpty();
        bool printAll();
        bool clear();
    private:
        Node* root;
        int depth;
        void printAllExecution(Node* node, int curDepth);
};