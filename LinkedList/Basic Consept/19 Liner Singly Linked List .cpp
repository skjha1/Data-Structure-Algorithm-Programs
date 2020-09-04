/* Code written 
	@author Shivendra k jha  
	some singly linkedlist code like create , display , max , sum , count, searching, insertion   using normal method and using recursion 

*/
#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node* next;
}*first=NULL,*second=NULL,*third=NULL;
void Create(int A[], int n)
{
	int i;
	struct Node* last, * t;
	first = (struct Node*)malloc(sizeof(struct Node));
	first->data = A[0];
	first->next = NULL;
	last = first;

	for (i = 1; i < n; i++)
	{
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = A[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
}
void Create2(int A[], int n)
{
	int i;
	struct Node* last, * t;
	second = (struct Node*)malloc(sizeof(struct Node));
	second->data = A[0];
	second->next = NULL;
	last = second;

	for (i = 1; i < n; i++)
	{
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = A[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
}
void Display(struct Node* p)
{
	while (p != NULL)
	{
		printf("->%d", p->data);
		p = p->next;
	}
}
void RDisplay(struct Node* p)
{
	if (p!=NULL)
	{
		printf("->%d", p->data);
		RDisplay(p->next);
	}
}

int count(struct Node* p)
{
	int c = 0;
	while (p != NULL)
	{
		c++;
		p = p->next;
	}
	return c;
}
int Rcount(struct Node* p)
{
		if (p == 0) return 0;
		else
			return Rcount(p->next) + 1;
	
}
int sum(struct Node* p)
{
	int sum = 0;
	while (p != NULL)
	{
		sum += p->data;
		p = p->next;
	}
	return sum;
}
int Rsum(struct Node* p)
{
	if (p == 0)
		return 0;
	else
		return Rsum(p->next) + p->data;
}

int max(struct Node* p)
{
	int m = -3276;
	while (p != NULL)
	{
		if (m < p->data)
			m = p->data;
		p = p->next;
	}
	return m;
}
int max1(struct Node* p)
{
	int x = 0;
	if (p == 0)
		return INT_MIN;
	else {
		x = max1(p->next);

		if (x > p->data)
			return x;
		else return p->data;
			
	}
}
int Rmax(struct Node* p)
{
	int x = 0;
	if (p == 0)
	{
		return INT_MIN;
	}
	else
		x=Rmax(p->next);
	return x > p->data ? x : p->data; // using ternary operator
}

// Binary search is not possible in linkedlist // Binery search is only for sorted array 

struct Node* LSearch(struct Node* p, int key)
{
	struct Node* q=NULL;

	while (p != NULL)
	{
		if (key == p->data)
		{
			return p;
			p = p->next;
		}
		
		p = p->next;
	}
	return NULL;

}

struct Node* RSearch(struct Node* p, int key) // using recursion searching the  elements in linkes list 
{
	if (p == NULL)
		return NULL;
	if (key == p->data)
		return p;
	return RSearch(p->next, key);

}

//move to top approch 
struct Node* Movetotop(struct Node* p, int key)
{
	// for sending key element to top we need one extrea pointer i.e q
	struct Node* q=NULL;

	while (p != NULL)
	{
		if (p->data == key)
		{
			q->next = p->next;
			p->next = first;
			first = p;
			return p;
		}
		q = p;
		p = p->next;

	}
	return NULL;
}

// Inserting in linkedlist // in array we start index from 0 ll is independent of that 
// we can insert by two pos 
// Insert before first & insert after given position 

void Insert(int pos, int x) // position at which element will be inserted and data (x) to be inserted
{
	struct Node* t, * p; // creating node 
	if (pos == 0) // before 1st node 
	{
		t = (struct Node*)malloc(sizeof(struct Node)); // creating node memory in heap 
		t->data = x;   // data insertion on newly created node 
		t->next = first; // newly created first next (pointer) points to the old first (for linking purpose)
		first = t;   // Bring 1st on new node 
	}
	else if (pos > 0)
	{
		p = first;
		for (int i = 0; i < pos - 1 && p; i++)
			p = p->next;
		if (p)
		{
			t = (struct Node*)malloc(sizeof(struct Node));
			t->data = x;
			t->next = p->next;
			p->next = t;
		}
	}
}

// Insert at last 
void Insertlast(int y)
{
	struct Node* tt;
	struct Node* last;
	tt = (struct Node* )malloc (sizeof(struct Node));
	last= (struct Node*)malloc(sizeof(struct Node));
	tt->data = y; // assigning data to node  
	tt->next = NULL; // assigning node next with NUll 
	if (first == NULL)  // if the ll is alredy empty 
	{
		first = last = tt;
	}
	else
	{
		last->next = tt;
		last = tt;
	}


}

void Sortedinsert(struct Node* p, int x)
{
	struct Node* t, * q = NULL;
	t = (struct Node*)malloc(sizeof(struct Node));
	t->data = x;/* first node is ready*/
	t->next = NULL; 
	if (first == NULL)
	{
		first = t;
	}
	else
	{
		while (p && p->data < x)
		{
			q = p;
			p = p->next;
		}
		if (p == first)
		{
			t->next = first;
			first = t;
		}
		else {
			t->next = q->next;
			q->next = t;
		}
	}
}

int Delete(struct Node* p, int index) // it should take pointer to 1st node & index from which element to be deleted 
{
	struct Node* q=NULL; // tail pointer 
	int x = -1, i;

	if (index < 1 || index > count(p)) // weather index is valid or not , index is from 1 to length 
		return -1;
	if (index == 1) // special cse if index is on 1st node 
	{
		q = first; // make q points on 1st node 
		x = first->data; // take the data from 1st node 
		first = first->next; // move 1st pointer to next node 
		free(q); // del the previous 1st node 
		return x;
	}
	else // if it is not 1st index || any other index  
	{
		for (i = 0; i < index - 1; i++) // using for loop we will move p and q
		{
			q = p; // everytime q will moved upon p and p will move upon next node 
			p = p->next;
		} 
		// p will be pointing on node which we want to delete 
		q->next = p->next; // p will be logically removed from ll 
		x = p->data; // strote data to be del in x from p-data 
		free(p); // 
		return x; // deleted valte 

	}


}

// Remove duplicate from ll ; if nodes data are same del that ; from sorted linkedlist 
void Removeduplicate(struct Node* p) // taking pointer to 1st node 
{
	// inside fxn we want  one more pointer 
	struct Node* q = p->next; // which will before p  // q is ahead and p is following 
	while (q != NULL)
	{
		if (p->data != q->data) // if data is not matching  // means no duplicate 
		{
			p = q; // move ahead 
			q = q->next;
		}
		else // if there is duplicate value 
		{
			p->next = q->next;  // p next points on  q next //q will be logically remove from ll 
			free(q); // delete q 
			q = p->next; // and move q to next  
		}
	}
}
// reversing ll using array 
void Reverse1(struct Node* p) // pointer to 1st node 
{
	int* A,i=0; // for storing reversed linkedlist we need an array & and its size is not known so we will find the length of ll // for that we created an array dynamically 
	struct Node* q=p; // for traversing we will take one more pointer that will help in traversing 
	A = (int*)malloc(sizeof(int) * count(p)); // create an array size is length of ll // size of int type // mul by length of ll // array is created 
	while (q != NULL) 
	{
		A[i] = q->data; // everytime copy data from q to array 
		q= q->next; // and move q to next 
		i++; // increment i

	}
	// once it reach end of linkedlist all element copied in array 
	q = p;// q sud again strat from 1st pointer  i.e p
	i--; // i shoud go back
	while (q != NULL)
	{
		q->data = A[i]; // we will copy in reverse manner 
		q = q->next; // move q to next 
		i--;

	}

}
// using sliding pointer 
void Reverse2(struct Node* p) // 1st node pointer
{
	struct Node* q = NULL, *r = NULL; // we requre three pointer p,q,r
	p = first; 
	while (p != NULL)
	{/*
	 sliding pointer */
		r = q; // r  sud come upon q
		q = p;// q sud come upon p
		p = p->next;// p sud move to next node 
		q->next = r;// q next sud points on 
	}
	first = q; // once we came out of while loop // 1st ointer sud point on q 

}
//reversing using Recursion 
void Rreverse(struct Node* q, struct Node* p) // taking two pointer p and q ; p will always ahead and q will follow that;
{
	if (p != NULL)
	{
		Rreverse(p, p->next); //  passing two pointer
		p->next = q;// while recturnig  it will make p next as q 
	}
	else
		first = q; // while p i null make first as q ;
}

// Concatenating two linkedlist 
void concat(struct Node* p, struct Node* q) // we will take two pointer p will scan through 1st linkedlist reach to end and then  q will start from 2nd after concatenating 
{
	third = p; // make poinetr third on the 1st 
	while (p->next != NULL) // scan through 1st linkedlist and stop at last node it will stop upon last node 
		p = p->next;
		p->next = q; // contaneted 
}


void Merge(struct Node* p, struct Node* q)
{
	struct Node* last;
	if (p->data < q->data)
	{
		third = last = p; // move third , last on first 
		p = p->next; // move 1st to the 1st next node 
		third->next = NULL; // make last next to null
	}
	else
	{ 
		// repaet same for 2nd linked list to be merged 
		third = last = q; 
		q = q->next;
		third->next = NULL;
	}
	while (p && q) // repeating process  
	{
		if (p->data < q->data)  // everytime check if p data is smaller then q data if so then 
		{
			last->next = p; // last next sud point on  1st 
			last = p; // last sud be same as first 
			p = p->next; // move 1st to the next node 
			last->next = NULL; // make last next as null

		}
		else // otherwise do same thing for this also 
		{
			// repete same for next ll 
			last->next = q;
			last = q;
			q = q->next;
			last->next = NULL;

		}
	}
	//this while loop keep on copying elements whichever is smaller and end of while loop remaning will be linked 
	if (p)last->next = p;// if p is not null last next sud point on p 
	if (q)last->next = q;// if q is not null last next sud point on q 

}
int main()
{

	int A[] = { 10,20,40,50,60 };
	int B[] = { 5,15,18,25,30,55 };
	Create(A, sizeof(A)/sizeof(int));
	Create2(B, sizeof(B)/sizeof(int));


	Merge(first, second);	
	printf("Merged elements \n "); 
	Display(third);

	return 0;
}