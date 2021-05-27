#include<bits/stdc++.h>
using namespace std;

class StackUsingArray{
    int* data;
    int nextIndex;
    int capacity;
    public:
    StackUsingArray(int totalSize){
        data = new int[4];
        nextIndex=0;
        capacity=4;
    }

    int size(){
        return nextIndex;   
    }

    bool isEmpty(){
        return nextIndex==0;
    }

    void push(int element){
        if(nextIndex==capacity){
            int* newData = new int[2*capacity];
            for(int i=0; i<capacity; i++){
                newData[i]=data[i];
            }

            capacity=capacity*2;
            delete [] data;
            data = newData;
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