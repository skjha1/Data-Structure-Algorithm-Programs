#include<iostream>
#include<cmath>
#include<stack>
using namespace std;

class Node{
public:
    int data;
    Node *next;
};
Node *head=new Node;
void create(int A[], int n){
    Node *temp;
    Node *tail;
    head->data=A[0];
    head->next=nullptr;
    tail=head;

    for(int i=0;i<n;i++){
        temp=new Node;
        temp->data=A[i];
        temp->next=nullptr;
        tail->next=temp;
        tail=temp;
    }
}
void middleNode1(Node *p){      //length/2==mid method
    int length=0;
    while(p){
        length++;
        p=p->next;
    }
    int index=(int) ceil(length/2.0);
    Node *q=head;
    for(int i=0;i<index-1;i++){
        q=q->next;
    }
    cout<<"Middle Element (Method-I): "<<q->data<<endl;
}
void middleNode2(Node *p){          //two pointer method
    Node *q=p;
    while(q){
        q=q->next;
        if(q){
            q=q->next;
        }
        if(q){
            p=p->next;
        }
    }
    cout<<"Middle Element(Method-II): "<<p->data<<endl;
}
void middleNode3(Node* p){           //stack Method
    stack<Node*> s;
    while (p){
        s.push(p);
        p = p->next;
    }
    int length = s.size();
    int popLength = (int)(floor(length/2.0));
    while (popLength){
        s.pop();
        popLength--;
    }
    cout << "Middle Element (Method-III): " << s.top()->data << endl;
}
int main() {
    int A[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};
    create(A, sizeof(A)/sizeof(A[0]));
    cout << endl;
    middleNode1(head);
    middleNode2(head);
    middleNode3(head);
    return 0;
}
