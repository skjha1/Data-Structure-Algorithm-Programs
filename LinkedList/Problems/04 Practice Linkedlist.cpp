#include<iostream>
using namespace std;
struct Node {
	int data;
	struct Node* next;
}*frist=NULL;

void Create(int A[], int n) {
	int i;
	struct Node* t, * last;
	frist = new Node;
	frist->data = A[0];
	frist->next = NULL;
	last = frist;

	for (i = 1; i < n; i++) {
		t = new Node;
		t->data = A[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
}

void Display(struct Node* p) {
	while (p) {
		cout << p->data << "->";
		p = p->next;
	}
}

void RDisplay(struct Node* p) {
	if (p)
	{
		cout << p->data << "->";
		RDisplay(p->next);
	}
}

int Count(struct Node* p)
{
	int count = 0;
	while (p) {
		count += 1;
		p = p->next;
	}
	return count;
}

int RCount(struct Node* p) {
	if (p == NULL)
		return 0;
	else
		return RCount(p->next) + 1;
}

int Max(struct Node* p) {
	int max = INT_MIN;
	while (p) {
		if (p->data > max)
			max = p->data;
		p = p->next;
	}
	return max;
}

int RMax(struct Node* p) {
	int x = 0;
	if (p == 0)
		return INT_MIN;
	x = RMax(p->next);
	if (x > p->data)
		return x;
	else
		return p->data;
}

int Min(struct Node* p)
{
	int min = INT_MAX;
	while (p) {
		if (p->data < min)
			min = p->data;
		p = p->next;
	}
	return min;
}
int RMin(struct Node* p) {
	int x = 0;
	if (p == 0)
		return INT_MAX;
	x = RMin(p->next);
	if (x < p->data)
		return x;
	else
		return p->data;
}

int Sum(struct Node* p) {
	int sum = 0;
	while (p)
	{
		sum += p->data;
		p = p->next;
	}
	return sum;
}

int RSum(struct Node* p)
{
	if (p == 0)
		return 0;
	else
		return Sum(p->next) + p->data;
}

float Avg(struct Node* p)
{
	return Sum(frist) / Count(frist);
}

// binary search is not applicable in linkedlist 
// only linear search is applicable in the linkedlist

struct Node* Search(struct Node* p, int key) {
	while (p)
	{
		if (key == p->data)
			return (p);
		p = p->next;
	}
	return NULL;
}

// move to head 
struct Node* Improved_Search(struct Node *p, int key) {
	Node* q = NULL; // take a extra pointer 
	while (p) {
		if (key == p->data) {
			q->next = p->next; // q is present one before the key element so make q->next to the next of key element so that there will be a breakage of link 
			p->next = frist; // then point key's element next to 1st so that  it will become the 1st element of the linkedlist 
			frist = p; // now move frist on p;
			return p;
		}
		q = p;
		p = p->next;
	}
	return NULL;
}

int main() {
	int A[] = { 545445,500,4,5,8,1 };
	int n = sizeof(A) / sizeof(int);
	Create(A, n);
	//Display(frist);
	//RDisplay(frist);
	//cout << "The length of the linkedlist is ! = " << Count(frist);
	//cout << "The length of the linkedlist is ! = " << RCount(frist);
	//cout << "The maximum element in the linkedlist is ! = " << Max(frist);
	//cout << "The maximum element in the linkedlist is ! = " << RMax(frist);
	//cout<< "The minimum element in the linkedlist is ! = " << Min(frist);
	//cout<< "The minimum element in the linkedlist is ! = " << RMin(frist);
	//cout<< "The sum of the  element in the linkedlist is ! = " << Sum(frist);
	//cout<< "The sum of the  element in the linkedlist is ! = " << RSum(frist);
	//cout<< "The Average of the elements in the linkedlist is ! = " << Avg(frist);


	/*struct Node* temp = Search(frist, 5);
	if (temp)
		cout << temp->data << " is present in the list ";
	else
		cout << "key is not found ";*/
	
	struct Node* temp = Improved_Search(frist,1);
	if (temp)
		cout << temp->data << " Is present in the list ";
	else
		cout << "Element not found";

	return 0;
}
