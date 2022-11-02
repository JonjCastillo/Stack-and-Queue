#ifndef STACK_HPP
#define STACK_HPP
/**
 * @brief This header file is to create the Stack object
 * using templates and the DoubleType as the parent class 
 * a stack can only add and remove items from the top of the 
 * the methods required are as follows
 * empty() boolean method that determines if the list is empty
 * top() returns a read/write instance of the top item in the list
 * push(x) adds item x into the stack
 * pop() remove the item from the top
 * size() method that checks the size of the list
 * 
 */
#include "DoubleType.hpp"
template<class T>
class Stack: public DoubleType {
private:
   /* data */
public:
   Stack();
   bool isEmpty() const;
   T* top();
   void push(T* item);
   void pop();
   int size();

};

template <class T>
Stack<T>::Stack() : DoubleType<T>() {

}

template <class T>
bool Stack<T>::isEmpty() const {
   return DoubleType<T>::isEmpty();
}

template <class T>
T* Stack<T>::top() {
   return DoubleType<T>::getHead();
}

template <class T>
void Stack<T>::push(T* item) {
   DoubleType<T>::PutItemTop(item);
}

template <class T>
void Stack<T>::pop() {
   DoubleType<T>::DeleteItemTop();
}

template <class T>
int Stack<T>::size() {
   return DoubleType<T>::GetLength();
}

#endif