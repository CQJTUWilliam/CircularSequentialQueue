//
// Created by william on 20-1-15.
//

#ifndef CIRCULARSEQUENTIALQUEUE_CIRCULARSEQUENTIALQUEUE_H
#define CIRCULARSEQUENTIALQUEUE_CIRCULARSEQUENTIALQUEUE_H

#include <cstddef>
#include <cstring>
#include <iostream>
using std::cout;
using std::endl;

/*
 * 非动态扩容的循环顺序队列
 */
template <class T>
class CircularSequentialQueue {
private:
    size_t head;
    size_t tail;

    T* data;//使用指针以为实现动态扩容提供数据结构

    size_t capacity;
    size_t  size;
public:
    T* dequeue();
    bool enqueue(T value);

public:
    explicit CircularSequentialQueue(size_t capacity = 10);

public:
    void outputAllData();

    void swap(int *a,int *b){
        *a = *a + *b;
        *b = *a - *b;
        *a = *a - *b;
    }
};

template<class T>
T* CircularSequentialQueue<T>::dequeue() {
    if(size == 0){//数组为空. used to be 'size == 0 && head == tail'
        return nullptr;
    }

    T* temp = new T;
    *temp = data[head];
    head = (head+1)%capacity;
    size--;
    return temp;
}

template<class T>
bool CircularSequentialQueue<T>::enqueue(T value) {
//   if(head == tail && size == 0){//数组为空
//       data[tail] = value;
//       tail = (tail+1)%capacity;
//       return true;
//   }
//数组为满
   if(size == capacity-1 && ((tail+1)%capacity == head)){
       return false;
   }

    //一般情况(数组为空与正常情况)
    data[tail] = value;
    tail = (tail+1)%capacity;
    size++;
    return true;



}


template<class T>
CircularSequentialQueue<T>::CircularSequentialQueue(size_t capacity) {
    data = new T[capacity];
    head = tail = 0;
    //used to be 'head = nullptr'. the old one may more semantic, but the new one('head=data') is more easy to programme(oh god, now the new one is also gone.)
    size = 0;
    this->capacity = capacity;
}



#endif //CIRCULARSEQUENTIALQUEUE_CIRCULARSEQUENTIALQUEUE_H
