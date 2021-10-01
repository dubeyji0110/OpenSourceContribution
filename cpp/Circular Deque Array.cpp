#include<iostream>
using namespace std;

struct deque
{
	int *a;
	int cap,front,back,size;
	deque(int cap)
	{
		a=new int[cap];
		this->cap=cap;
		size=0;
		front=0;
		//rear=0; rear=front+size-1
	}
	
	int getRear()
	{
		if(isEmpty()) return -1;
		return(a[(front+size-1)%cap]);
	}
	
	int getFront()
	{
		if(isEmpty()) return -1;
		return(a[front]);		
	}
	
	bool insertFront(int x)
	{
		if(isFull()) return 0;
		if(front==0) //if front is on 0 then insertFront will get in the last index
		{
			front=cap-1;
			a[front]=x;
		}
		else
		{
			a[--front]=x;
		}
		++size;
		return 1;
	}
	
	bool insertLast(int x)
	{
		if(isFull()) return 0;
		a[(front+size)%cap]=x;
		++size;
		return 1;
	}
	
	bool deleteFront()
	{
		if(isEmpty()) return 0;
		front=(front+1)%cap;
		--size;
		return 1;
	}
	
	bool deleteLast()
	{
		if(isEmpty()) return 0;
		--size;
		return 1;
	}
	
	bool isEmpty()
	{
		return(!size);
	}
	
	bool isFull()
	{
		return(size==cap);
	}
	
	void display()
	{
		cout<<"\nPrinting Deque\n";
		for(int i=0;i<size;++i)
		cout<<a[(front+i)%cap]<<" ";
		cout<<"\n";
	}
	
};

int main()
{
	deque d(5);
	d.insertFront(10);
	d.insertFront(5);
	d.insertLast(15);
	d.insertFront(1);
	d.deleteLast();
	d.display();
}