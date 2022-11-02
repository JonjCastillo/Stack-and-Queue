#ifndef QUEUE_HPP
#define QUEUE_HPP
/**
 * @brief the queue class is also another child of the DoubleType class
 * this class will once agian use templates and is compried of the following methods:
 * isEmpty() determine if the queue is empty
 * size() returns the size of the queue
 * front() return a reference of the first element in the queue
 * back() return the last element of the queue
 * push(x) adds item x into the end of the queue
 * pop() delete the first element of the queue
 * 
 */

#include "DoubleType.hpp"
template<class T>
class Queue
{
private:
   /* data */
public:
   Queue();
   bool isEmpty() const;
   int size();
   T* front();
   T* back();
   void push(T* item);
   void pop();
};

template <class T>
Queue<T>::Queue(/* args */) : DoubleType<T> () {
}

template <class T>
bool Queue<T>::isEmpty() const {
      return DoubleType<T>::isEmpty();
}

template <class T>
int Queue<T>::size() {
   return DoubleType<T>::GetLength();
}

template <class T>
T* Queue<T>::front() {
   return DoubleType<T>::getHead();
}

template <class T>
T* Queue<T>::back() {
   return DoubleType<T>::getTail();
}

template <class T>
void Queue<T>::push(T* item) {
   DoubleType<T>::PutItemBottom(item);
}

template <class T>
void Queue<T>::pop() {
   DoubleType<T>::DeleteItemTop();
}

#endif