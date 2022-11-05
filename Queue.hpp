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
class Queue : public DoubleType<T>
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
Queue<T>::Queue() : DoubleType<T> () {
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
   return DoubleType<T>::front();
}

template <class T>
T* Queue<T>::back() {
   return DoubleType<T>::back();
}

template <class T>
void Queue<T>::push(T* item) {
   DoubleType<T>::PutItemBottom(item);
   // NodeType<T>* newNode;  // pointer to node being inserted  // trailing pointer
   // NodeType<T>* location; // traveling pointer
   // // bool moreToSearch;

   // location = listData;
   // // moreToSearch = (location != NULL);
   // newNode = new NodeType<T>;
   // newNode->info = item;

   // if (listData == NULL)         // Insert as first.
   // {
   //    newNode->next = NULL;
   //    newNode->previous = NULL;
   //    listData = newNode;
   //    listTail = newNode;
   // } else {
   //    newNode->previous = listTail;
   //    newNode->next = NULL;
   //    listTail = newNode;
      
   // }
   // length++;
}

template <class T>
void Queue<T>::pop() {
   DoubleType<T>::DeleteItemTop();
}

#endif