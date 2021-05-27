#include<bits/stdc++.h>
using namespace std;

class StackUsingArray{
    int* data;
    int nextIndex;
    int capacity;
    public:
    StackUsingArray(int totalSize){
        data = new int[totalSize];
        nextIndex=0;
        capacity=totalSize;
    }

    int size(){
        return nextIndex;   
    }

    bool isEmpty(){
        return nextIndex==0;
    }

    void push(int element){
        if(nextIndex==capacity){
            cout<<"Stack is full"<<endl;
            return;
        }
        data[nextIndex]=element;
        nextIndex++;
    }

    int pop(){
        if(isEmpty){
            cout<<"Stack is empty"<<endl;
            return INT_MIN;
        }
        nextIndex--;
        return nextIndex;
    }

    int top(){
        return data[nextIndex -1];  
    }

};