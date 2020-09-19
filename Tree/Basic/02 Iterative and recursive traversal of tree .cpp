#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Node {
public:
    Node* lchild;
    int data;
    Node* rchild;
};

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
    int Height(Node* p);
    int Height() { return Height(root); }
    void iterativePreorder(Node* p);
    void iterativePreorder() { iterativePreorder(root); }
    void iterativeInorder(Node* p);
    void iterativeInorder() { iterativeInorder(root); }
    void iterativePostorder(Node* p);
    void iterativePostorder() { iterativePostorder(root); }
};

Tree::Tree() {
    root = nullptr;
}

Tree::~Tree() {
    // TODO
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
    cout << root->data << ", " << flush;
    q.emplace(root);

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

int Tree::Height(Node* p) {
    int l = 0;
    int r = 0;
    if (p == nullptr) {
        return 0;
    }

    l = Height(p->lchild);
    r = Height(p->rchild);

    if (l > r) {
        return l + 1;
    }
    else {
        return r + 1;
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


int main() {

    Tree bt;

    bt.CreateTree();
    cout << endl;

    cout << "Preorder: " << flush;
    bt.Preorder();
    cout << endl;

    cout << "Inorder: " << flush;
    bt.Inorder();
    cout << endl;

    cout << "Postorder: " << flush;
    bt.Postorder();
    cout << endl;

    cout << "Levelorder: " << flush;
    bt.Levelorder();
    cout << endl;

    cout << "Height: " << bt.Height() << endl;

    cout << "Iterative Preorder: " << flush;
    bt.iterativePreorder();

    cout << "Iterative Inorder: " << flush;
    bt.iterativeInorder();

    cout << "Iterative Postorder: " << flush;
    bt.iterativePostorder();

    return 0;
}