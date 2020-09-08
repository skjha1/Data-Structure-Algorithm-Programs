#include<stdio.h>
#include<stdlib.h>
#include<math.h>
// representation of polynomial 
struct Node {
	int coeff; // coefficient of poly
	int exp; // exponential of poly 
	struct Node* next; // pointer to next node 
}*poly=NULL;  

void Create ()
{
	struct Node* t, * last = NULL;  // temp node to new node ; and ptr to last nnode 
	int num, i;
	printf("Enter number of terms ");
	scanf_s("%d", &num);
	printf("Enter each terms with there coeff and exp\n");
	for (i = 0; i < num; i++) 
	{
		t = (struct Node*)malloc(sizeof(struct Node)); // for each term we need to create node 
		scanf_s("%d %d", &t->coeff, &t->exp); // eading two value 
		t->next = NULL;  // last node will be null
		if (poly == NULL) // if it is 1st node 
		{
			poly = last = t; // all sud point on 1st
		}
		else {
			last->next = t; // moving upto last and inserion 
			last = t;
		}
	}
	

}
void Display(struct Node* p)
{
	while (p)
	{
		printf("%dx%d +", p->coeff, p->exp);
		p = p->next;
	}
	printf("\n");
}

long eval(struct Node *p, int x)
{
	double sum = 0;
	while (p)
	{
		sum += p->coeff * pow(x, p->exp);
		p = p->next;
	}
	return sum;
	
}






int main()
{
	Create();
	Display(poly);
	printf("%ld\n", eval(poly, 2));
	return 0;
}
