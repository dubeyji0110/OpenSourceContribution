#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = (int)1e9 + 7;

template<typename T>

class Node{
    public:

    T data;
    Node<T> *next;
    Node(T data){
        this->data = data;
        next = NULL;
    }
};

template<typename T>

class Queue{

    Node<T> *head, *tail;
    int size;
    public:

    Queue(){
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void enqueue(T data){
        Node<T> *newNode = new Node<T>(data);
        if(head == NULL && tail == NULL){
            head = newNode;
            tail = newNode;
            size++;
            return;
        }
        tail->next = newNode;
        tail = tail -> next;
        size++;
    }

    T dequeue(){
        if(size == 0){
            cout<<"Empty queue\n";
            return 0;
        }
        T data = head->data;
        Node<T> * temp = head;
        head = head->next;
        delete temp;
        size--;
        return data;
    }

    T front(){
        if(size == 0){
            cout<<"Empty queue\n";
            return 0;
        }
        return head->data;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size == 0;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    Queue<int> q1;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);

    cout<<q1.front()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;

    cout<<q1.front()<<endl;

    cout<<q1.getSize()<<endl;
    cout<<q1.isEmpty()<<endl;

    Queue<char> q2;
    q2.enqueue('a');
    q2.enqueue('b');
    q2.enqueue('c');
    q2.enqueue('d');
    q2.enqueue('e');

    cout<<q2.front()<<endl;
    cout<<q2.dequeue()<<endl;
    cout<<q2.dequeue()<<endl;
    cout<<q2.dequeue()<<endl;

    cout<<q2.front()<<endl;

    cout<<q2.getSize()<<endl;
    cout<<q2.isEmpty()<<endl;
    return 0;
}
