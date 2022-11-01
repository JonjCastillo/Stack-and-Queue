#ifndef DOUBLETYPE_HPP
#define DOUBLETYPE_HPP


template <class T>
#include "ClientType.hpp"
#include <iostream>
using namespace std;
struct NodeType;

struct NodeType {
    NodeType* previous;
    ClientType* info;
    NodeType* next;
};

class DoubleType {

public:
  DoubleType();     // Class constructor
  ~DoubleType();    // Class destructor

  bool IsFull() const;
  int  GetLength() const;
  void MakeEmpty();
  ClientType* GetItem(int key);
  void PutItemTop(ClientType* item);
  void PutItemBottom(ClientType* item);
  void DeleteItem(int key);
  void DeleteItemTop();
  void DeleteItemBottom();
  void ResetList();
  void UpdateItem(int key, double balance, string name);
  ClientType* GetNextItem();
  void sortList();
  NodeType* getHead();
  NodeType* getTail();

private:
   NodeType* listData; //head
   int length;
   NodeType* listTail; //tail of the list
   NodeType* currentPos;



};


DoubleType::DoubleType() {  // Class constructor
  length = 0;
  listData = NULL;
}

//checks to see if there is enough memory to add another 
//node to the list.
bool DoubleType::IsFull() const {
   NodeType* location;
   try {
      location = new NodeType;
      delete location;
      return false;
   }
   catch (bad_alloc exception) {
      return true;
   }
}

//return the length of the list
int DoubleType::GetLength() const {
   return length;
}

//method empties out the list
void DoubleType::MakeEmpty() {
  NodeType* tempPtr;

  while (listData != NULL) {
    tempPtr = listData;

    listData = listData->next;
    delete tempPtr;
  }
  length = 0;
}


/**
 * @brief this method returns the account found by its ID
 * it searches through the list until it finds the node.
 * 
 * @param key the id of the list
 * @return ClientType* the account that correlated to the ID
 */
ClientType* DoubleType::GetItem(int key) {
  bool moreToSearch;
  NodeType* location;
  NodeType* tempLocation;
  ClientType* item;

  location = listData;
  moreToSearch = (location != NULL);
  if ( key == location->info->getID() ) {
    item = location->info;
    return item;
  }
  else {
    while (key != location->next->info->getID()) {
      location = location->next;
      item = NULL;
    }

    item = location->next->info;
  }

  return item;
}


/**
 * @brief this method adds an item to the list by placing it at the head of the list 
 * and then making the node the new head of the list
 * 
 * @param item the account that is being added.
 */
void DoubleType::PutItemTop(ClientType* item)
{
  NodeType* newNode;  // pointer to node being inserted
  NodeType* predLoc;  // trailing pointer
  NodeType* location; // traveling pointer
  // bool moreToSearch;

  location = listData;
  predLoc = NULL;
  // moreToSearch = (location != NULL);

  // Prepare node for insertion.
  newNode = new NodeType;
  newNode->info = item;

  // Insert node into list.
  if (listData == NULL)         // Insert as first.
  {
    newNode->next = NULL;
    newNode->previous = NULL;
    listData = newNode;
    listTail = newNode;
  }
  else
  {
    newNode->next = listData;
    newNode->previous = NULL;
    listData = newNode;

  }
  length++;
}

/**
 * @brief this method inserts into the list by traveling through the list and then 
 * appending the node to the tail of the list 
 * 
 * @param item the object being entered into the list
 */
void DoubleType::PutItemBottom(ClientType* item) {
  NodeType* newNode;  // pointer to node being inserted  // trailing pointer
  NodeType* location; // traveling pointer
  // bool moreToSearch;

  location = listData;
  // moreToSearch = (location != NULL);
  newNode = new NodeType;
  newNode->info = item;

  if (listData == NULL)         // Insert as first.
  {
    newNode->next = NULL;
    newNode->previous = NULL;
    listData = newNode;
    listTail = newNode;
  } else {
    newNode->previous = listTail;
    newNode->next = NULL;
    listTail = newNode;
    
  }
  length++;
}

void DoubleType::sortList() {
  NodeType* tempNode;
  NodeType* indexNode;
  ClientType* temp;

  if (listData == NULL) {
    return;
  } else {
    for (tempNode = listData; tempNode->next != NULL; tempNode = tempNode->next) {
      for (indexNode = tempNode->next; indexNode != NULL; indexNode = indexNode->next) {
        if (tempNode->info->getBalance() > indexNode->info->getBalance() ) {
          temp = tempNode->info;
          tempNode->info = indexNode->info;
          indexNode->info = temp;
        }
      }
    }

  }
}



/**
 * @brief this method finds the specified account by its ID
 * and then deletes it by removing the node and setting the pointer of the previous node 
 * to the following node of the list.
 * 
 * @param key this is the ID of the account
 */
void DoubleType::DeleteItem(int key)
{
  NodeType* location = listData;
  NodeType* tempLocation;

  // Locate node to be deleted.
  if ( key == listData->info->getID() ) {
    tempLocation = location;
    listData = listData->next;    // Delete first node.
  }
  else {
    while (key != location->next->info->getID()) {
      location = location->next;
    }

    // Delete node at location->next
    tempLocation = location->next;
    location->next = (location->next)->next;
  }
  delete tempLocation;
  length--;
}

void DoubleType::DeleteItemTop() {
  NodeType* tempNode;
  tempNode = listData;
  listData = listData->next;
  delete tempNode;
}

void DoubleType::DeleteItemBottom() {
  NodeType* tempNode;
  tempNode = listTail;
  listTail = listTail->previous;
  delete tempNode;
}

void DoubleType::ResetList()
{
  currentPos = NULL;
}

/**
 * @brief returns the next item in the list
 * 
 * @return ClientType* the client that followed in the list
 */
ClientType* DoubleType::GetNextItem()
{
  ClientType* item;
  if (currentPos == NULL) {
    currentPos = listData;
  }
  item = currentPos->info;
  currentPos = currentPos->next;
  return item;
}

DoubleType::~DoubleType()
{
  NodeType* tempPtr;

  while (listData != NULL)
  {
    tempPtr = listData;
    listData = listData->next;
    delete tempPtr;
  }
}

/**
 * @brief this method will search similar to GetItem() and then update the found
 * node with the given parameters
 * 
 * @param key the account ID for the node
 * @param balance the updated balance for the account
 * @param name the updated name for the account
 */
void DoubleType::UpdateItem(int key, double balance, string name) {
  bool moreToSearch;
  NodeType* location;
  NodeType* tempLocation;

  location = listData;
  moreToSearch = (location->next != NULL);

  if ( key == location->info->getID() ) {
    location->info->setBalance(balance);
    location->info->setName(name); 
  }
  else {
    while (key != location->next->info->getID()) {
      location = location->next;
    }

    location->next->info->setBalance(balance);
    location->next->info->setName(name);
  }
  
}

// returns the head of the list
NodeType* DoubleType::getHead() {
  return listData;
}

NodeType* DoubleType::getTail() {
  return listTail;
}




#endif