#include<iostream>

using namespace std;

// stack by linked list
struct Node
{
	int data;
	Node* next;
	Node() {}
	Node(int x)
	{
		data=x;
		next=NULL;
	}
};


Node* head=NULL;
void push(int x)
{
	Node* temp=new Node(x);
	temp->next=head;
	head=temp;
}


int pop()
{
	if(head==NULL) return -1;
	int res=head->data;
	Node* temp=new Node();
	head=head->next;
	delete(temp);
	return(res);
}


int main()
{
	int ele;
	push(67);
	push(3670);
	push(2240);
	display();
	ele=pop();
	display();
}