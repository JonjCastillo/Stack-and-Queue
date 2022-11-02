#include <iostream>
#include "DoubleType.hpp"
#include "ClientType.hpp"
#include "Queue.hpp"
#include "Stack.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
   DoubleType<ClientType> doubleList;
   Stack<ClientType> testStack;
   Queue<ClientType> testQueue;

   ClientType* tempClient;
   // ClientType* tempClient = new ClientType(3, "joe", 230.32);

   cout << doubleList.isEmpty() << endl;
   cout << testStack.isEmpty() << endl;
   cout << testQueue.isEmpty() << endl;

   // tempClient->setBalance(213.23);
   // tempClient->setID(3);
   // tempClient->setName("Joe");

   cout << "Item insertion" << endl;
   doubleList.PutItemTop(tempClient);
   testQueue.push(tempClient);
   testStack.push(tempClient);

   cout << doubleList.isEmpty() << endl;
   cout << testStack.isEmpty() << endl;
   cout << testQueue.isEmpty() << endl;

   return 0;
}
