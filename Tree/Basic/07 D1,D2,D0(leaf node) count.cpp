#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Node {
public:
    Node* lchild;
    int data;
    Node* rchild;
    Node() {};
    Node(int data);
};

Node::Node(int data) {
    lchild = nullptr;
    this->data = data;
    rchild = nullptr;
}

class Tree {
private:
    Node* root;
public:
    Tree();
    ~Tree();
    void CreateTree();
    void Preorder(Node* p);
    void Preorder() { Preorder(root); }  // Passing Private Parameter in Constructor
    void Inorder(Node* p);
    void Inorder() { Inorder(root); }
    void Postorder(Node* p);
    void Postorder() { Postorder(root); }
    void Levelorder(Node* p);
    void Levelorder() { Levelorder(root); }
    void iterativePreorder(Node* p);
    void iterativePreorder() { iterativePreorder(root); }
    void iterativeInorder(Node* p);
    void iterativeInorder() { iterativeInorder(root); }
    void iterativePostorder(Node* p);
    void iterativePostorder() { iterativePostorder(root); }
    Node* generateFromTraversal(int inorder[], int preorder[], int inStart, int inEnd);
    int Height(Node* p);
    int Height() { return Height(root); }
    int Count(Node* p);
    int Count() { Count(root); }
    int Sum(Node* p);
    int Sum() { Sum(root); }
    int deg2NodeCount(Node* p);
    int deg2NodeCount() { deg2NodeCount(root); }
    int leafNodeCount(Node* p);
    int deg1ordeg2NodeCount(Node* p);
    int deg1NodeCount(Node* p);
    void DestroyTree(Node* p);
};

Tree::Tree() {
    root = nullptr;
}

Tree::~Tree() {
    DestroyTree(root);
}

void Tree::CreateTree() {
    Node* p;
    Node* t;
    int x;
    queue<Node*> q;

    root = new Node;
    cout << "Enter root data: " << flush;
    cin >> x;
    root->data = x;
    root->lchild = nullptr;
    root->rchild = nullptr;
    q.emplace(root);

    while (!q.empty()) {
        p = q.front();
        q.pop();

        cout << "Enter left child data of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1) {
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->lchild = t;
            q.emplace(t);
        }

        cout << "Enter right child data of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1) {
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->rchild = t;
            q.emplace(t);
        }
    }
}

void Tree::Preorder(Node* p) {
    if (p) {
        cout << p->data << ", " << flush;
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::Inorder(Node* p) {
    if (p) {
        Inorder(p->lchild);
        cout << p->data << ", " << flush;
        Inorder(p->rchild);
    }
}

void Tree::Postorder(Node* p) {
    if (p) {
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << ", " << flush;
    }
}

void Tree::Levelorder(Node* p) {
    queue<Node*> q;
    cout << p->data << ", " << flush;
    q.emplace(p);

    while (!q.empty()) {
        p = q.front();
        q.pop();

        if (p->lchild) {
            cout << p->lchild->data << ", " << flush;
            q.emplace(p->lchild);
        }

        if (p->rchild) {
            cout << p->rchild->data << ", " << flush;
            q.emplace(p->rchild);
        }
    }
}

void Tree::iterativePreorder(Node* p) {
    stack<Node*> stk;
    while (p != nullptr || !stk.empty()) {
        if (p != nullptr) {
            cout << p->data << ", " << flush;
            stk.emplace(p);
            p = p->lchild;
        }
        else {
            p = stk.top();
            stk.pop();
            p = p->rchild;
        }
    }
    cout << endl;
}

void Tree::iterativeInorder(Node* p) {
    stack<Node*> stk;
    while (p != nullptr || !stk.empty()) {
        if (p != nullptr) {
            stk.emplace(p);
            p = p->lchild;
        }
        else {
            p = stk.top();
            stk.pop();
            cout << p->data << ", " << flush;
            p = p->rchild;
        }
    }
    cout << endl;
}

void Tree::iterativePostorder(Node* p) {
    stack<long int> stk;
    long int temp;
    while (p != nullptr || !stk.empty()) {
        if (p != nullptr) {
            stk.emplace((long int)p);
            p = p->lchild;
        }
        else {
            temp = stk.top();
            stk.pop();
            if (temp > 0) {
                stk.emplace(-temp);
                p = ((Node*)temp)->rchild;
            }
            else {
                cout << ((Node*)(-1 * temp))->data << ", " << flush;
                p = nullptr;
            }
        }
    }
    cout << endl;
}

int searchInorder(int inArray[], int inStart, int inEnd, int data) {
    for (int i = inStart; i <= inEnd; i++) {
        if (inArray[i] == data) {
            return i;
        }
    }
    return -1;
}

Node* Tree::generateFromTraversal(int* inorder, int* preorder, int inStart, int inEnd) {
    static int preIndex = 0;

    if (inStart > inEnd) {
        return nullptr;
    }

    Node* node = new Node(preorder[preIndex++]);

    if (inStart == inEnd) {
        return node;
    }

    int splitIndex = searchInorder(inorder, inStart, inEnd, node->data);
    node->lchild = generateFromTraversal(inorder, preorder, inStart, splitIndex - 1);
    node->rchild = generateFromTraversal(inorder, preorder, splitIndex + 1, inEnd);

    return node;
}

int Tree::Height(Node* p) {
    int l = 0;
    int r = 0;

    if (p != nullptr) {
        l = Height(p->lchild);
        r = Height(p->rchild);
        if (l > r) {
            return l + 1;
        }
        else {
            return r + 1;
        }
    }
    return 0;
}

int Tree::Count(Node* p) {
    int x;
    int y;
    if (p != nullptr) {
        x = Count(p->lchild);
        y = Count(p->rchild);
        return x + y + 1;
    }
    return 0;
}

int Tree::Sum(Node* p) {
    int x;
    int y;
    if (p != nullptr) {
        x = Sum(p->lchild);
        y = Sum(p->rchild);
        return x + y + p->data;
    }
    return 0;
}

int Tree::deg2NodeCount(Node* p) {
    int x;
    int y;
    if (p != nullptr) {
        x = deg2NodeCount(p->lchild);
        y = deg2NodeCount(p->rchild);
        if (p->lchild && p->rchild) {
            return x + y + 1;
        }
        else {
            return x + y;
        }
    }
    return 0;
}

int Tree::leafNodeCount(Node* p) {
    int x;
    int y;
    if (p != nullptr) {
        x = leafNodeCount(p->lchild);
        y = leafNodeCount(p->rchild);
        if (p->lchild == nullptr && p->rchild == nullptr) {
            return x + y + 1;
        }
        else {
            return x + y;
        }
    }
    return 0;
}

int Tree::deg1ordeg2NodeCount(Node* p) {
    int x;
    int y;
    if (p != nullptr) {
        x = deg1ordeg2NodeCount(p->lchild);
        y = deg1ordeg2NodeCount(p->rchild);
        if (p->lchild != nullptr || p->rchild != nullptr) {
            return x + y + 1;
        }
        else {
            return x + y;
        }
    }
    return 0;
}

int Tree::deg1NodeCount(Node* p) {
    int x;
    int y;
    if (p != nullptr) {
        x = deg1NodeCount(p->lchild);
        y = deg1NodeCount(p->rchild);
        if (p->lchild != nullptr ^ p->rchild != nullptr) {
            return x + y + 1;
        }
        else {
            return x + y;
        }
    }
    return 0;
}

void Tree::DestroyTree(Node* p) {
    if (p != nullptr) {
        DestroyTree(p->lchild);
        DestroyTree(p->rchild);
        delete p;
    }
}


int main() {

    Tree bt;

    int preorder[] = { 8, 3, 12, 4, 9, 7, 5, 10, 6, 2 };
    int inorder[] = { 12, 9, 4, 7, 3, 8, 10, 5, 2, 6 };

    int size = sizeof(inorder) / sizeof(inorder[0]);

    Node* T = bt.generateFromTraversal(inorder, preorder, 0, size - 1);

    cout << "Preorder: " << flush;
    bt.Preorder(T);
    cout << endl;

    cout << "Inorder: " << flush;
    bt.Inorder(T);
    cout << endl;

    cout << "Height: " << bt.Height(T) << endl;
    cout << "Count: " << bt.Count(T) << endl;
    cout << "Sum: " << bt.Sum(T) << endl;
    cout << "# of degree 2 nodes: " << bt.deg2NodeCount(T) << endl;
    cout << "# of leaf nodes: " << bt.leafNodeCount(T) << endl;
    cout << "# of degree 1 or degree 2 nodes: " << bt.deg1ordeg2NodeCount(T) << endl;
    cout << "# of degree 1 nodes: " << bt.deg1NodeCount(T) << endl;

    bt.DestroyTree(T);

    return 0;
}
