#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = (int)1e9 + 7;

template<typename T>

class Queue{
    T *arr;
    int firstIndex;
    int lastIndex;
    int capacity;

    // int size = 0; ye bana sakte hai 
    // lastIndex = (lastIndex + 1) % capacity; isse update kr skte hai
    // iss tareeke se jagah bachegi

    public:
    Queue(){
        firstIndex = 0;
        lastIndex = 0;
        arr = new T[5];
        capacity = 5;
    }

    void enqueue(T data){
        if(lastIndex == capacity){
            capacity*=2;
            T *newArr = new T[capacity];
            for(int i=0; i<lastIndex ;i++){
                newArr[i] = arr[i];
            }
            delete [] arr;
            arr = newArr;
        }
        arr[lastIndex] = data;
        lastIndex++;
    }

    T dequeue(){
        if(firstIndex == lastIndex){
            cout<<"Empty Queue\n";
            return 0;
        }
        T data = arr[firstIndex];
        firstIndex++;
        return data;
    }

    T front(){
        if(firstIndex == lastIndex){
            cout<<"Empty Queue\n";
            return 0;
        }
        return arr[firstIndex];
    }

    int size(){
        return lastIndex-firstIndex;
    }

    bool isEmpty(){
        return ( firstIndex == lastIndex ) ;
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

    cout<<q1.size()<<endl;
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

    cout<<q2.size()<<endl;
    cout<<q2.isEmpty()<<endl;

    
    return 0;
}
