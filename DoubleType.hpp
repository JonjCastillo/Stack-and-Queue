#ifndef DOUBLETYPE_HPP
#define DOUBLETYPE_HPP


#include <iostream>
using namespace std;
template<class T>
// struct NodeType;

struct NodeType {
    NodeType<T>* previous;
    T* info;
    NodeType<T>* next;
};

template<class T>
class DoubleType {
  public:
    DoubleType();     // Class constructor
    ~DoubleType();    // Class destructor

    bool IsFull() const;
    bool isEmpty() const;
    int  GetLength() const;
    void MakeEmpty();
    T* GetItem(T* item);
    void PutItemTop(T* item);
    void PutItemBottom(T* item);
    void DeleteItem(T* item);
    void DeleteItemTop();
    void DeleteItemBottom();
    void ResetList();
    // void UpdateItem(T* item);
    T* GetNextItem();
    void sortList();
    NodeType<T>* getHead();
    NodeType<T>* getTail();

  private:
    NodeType<T>* listData; //head
    int length;
    NodeType<T>* listTail; //tail of the list
    NodeType<T>* currentPos;
};

template<class T>
DoubleType<T>::DoubleType() {  // Class constructor
  length = 0;
  listData = NULL;
}

//checks to see if there is enough memory to add another 
//node to the list.
template<class T>
bool DoubleType<T>::IsFull() const {
   NodeType<T>* location;
   try {
      location = new NodeType<T>;
      delete location;
      return false;
   }
   catch (bad_alloc exception) {
      return true;
   }
}

template<class T>
bool DoubleType<T>::isEmpty() const {
  return listData == NULL;
}
//return the length of the list
template<class T>
int DoubleType<T>::GetLength() const {
   return length;
}

//method empties out the list
template<class T>
void DoubleType<T>::MakeEmpty() {
  NodeType<T>* tempPtr;

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
 * @return T* the account that correlated to the ID
 */
template<class T>
T* DoubleType<T>::GetItem(T* item) {
  bool moreToSearch;
  NodeType<T>* location;
  NodeType<T>* tempLocation;
  T* foundItem;

  location = listData;
  moreToSearch = (location != NULL);
  if ( item == location->info ) {
    foundItem = location->info;
    return foundItem;
  }
  else {
    while (item != location->next->info) {
      location = location->next;
      foundItem = NULL;
    }

    foundItem = location->next->info;
  }

  return foundItem;
}


/**
 * @brief this method adds an item to the list by placing it at the head of the list 
 * and then making the node the new head of the list
 * 
 * @param item the account that is being added.
 */
template<class T>
void DoubleType<T>::PutItemTop(T* item)
{
  NodeType<T>* newNode;  // pointer to node being inserted
  NodeType<T>* predLoc;  // trailing pointer
  NodeType<T>* location; // traveling pointer
  // bool moreToSearch;

  location = listData;
  predLoc = NULL;
  // moreToSearch = (location != NULL);

  // Prepare node for insertion.
  newNode = new NodeType<T>;
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
template<class T>
void DoubleType<T>::PutItemBottom(T* item) {
  NodeType<T>* newNode;  // pointer to node being inserted  // trailing pointer
  NodeType<T>* location; // traveling pointer
  // bool moreToSearch;

  location = listData;
  // moreToSearch = (location != NULL);
  newNode = new NodeType<T>;
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

template<class T>
void DoubleType<T>::sortList() {
  NodeType<T>* tempNode;
  NodeType<T>* indexNode;
  T* temp;

  if (listData == NULL) {
    return;
  } else {
    for (tempNode = listData; tempNode->next != NULL; tempNode = tempNode->next) {
      for (indexNode = tempNode->next; indexNode != NULL; indexNode = indexNode->next) {
        if (tempNode->info > indexNode->info ) {
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
template<class T>
void DoubleType<T>::DeleteItem(T* item)
{
  NodeType<T>* location = listData;
  NodeType<T>* tempLocation;

  // Locate node to be deleted.
  if ( item == listData->info ) {
    tempLocation = location;
    listData = listData->next;    // Delete first node.
  }
  else {
    while (item != location->next->info) {
      location = location->next;
    }

    // Delete node at location->next
    tempLocation = location->next;
    location->next = (location->next)->next;
  }
  delete tempLocation;
  length--;
}
template<class T>
void DoubleType<T>::DeleteItemTop() {
  NodeType<T>* tempNode;
  tempNode = listData;
  listData = listData->next;
  delete tempNode;
}

template<class T>
void DoubleType<T>::DeleteItemBottom() {
  NodeType<T>* tempNode;
  tempNode = listTail;
  listTail = listTail->previous;
  delete tempNode;
}

template<class T>
void DoubleType<T>::ResetList()
{
  currentPos = NULL;
}

/**
 * @brief returns the next item in the list
 * 
 * @return T* the client that followed in the list
 */
template<class T>
T* DoubleType<T>::GetNextItem()
{
  T* item;
  if (currentPos == NULL) {
    currentPos = listData;
  }
  item = currentPos->info;
  currentPos = currentPos->next;
  return item;
}

template<class T>
DoubleType<T>::~DoubleType()
{
  NodeType<T>* tempPtr;

  while (listData != NULL)
  {
    tempPtr = listData;
    listData = listData->next;
    delete tempPtr;
  }
}

// /**
//  * @brief this method will search similar to GetItem() and then update the found
//  * node with the given parameters
//  * 
//  * @param key the account ID for the node
//  * @param balance the updated balance for the account
//  * @param name the updated name for the account
//  */
// template<class T>
// void DoubleType<T>::UpdateItem(T* item) {
//   bool moreToSearch;
//   NodeType<T>* location;
//   NodeType<T>* tempLocation;

//   location = listData;
//   moreToSearch = (location->next != NULL);

//   if ( item == location->info) {
//     location->info = item;
//   }
//   else {
//     while (item != location->next->info) {
//       location = location->next;
//     }

//     location->next->info = item;
//   }
  
// }

// returns the head of the list
template<class T>
NodeType<T>* DoubleType<T>::getHead() {
  return listData;
}

template<class T>
NodeType<T>* DoubleType<T>::getTail() {
  return listTail;
}




#endif