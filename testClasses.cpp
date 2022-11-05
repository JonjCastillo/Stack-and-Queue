#include <iostream>
#include "DoubleType.hpp"
#include "ClientType.hpp"
#include "Queue.hpp"
#include "Stack.hpp"

using namespace std;

void topLevelMenu() {
   cout << "1.\tadd a record: \n";
   cout << "2.\tedit record: \n";
   cout << "3.\tfind record: \n";
   cout << "4.\tview the records: \n";
   cout << "5.\tremove a record \n";
   cout << "6.\treturn to main menu \n";
}

void stackMenu(Stack<ClientType> stack) {
	int input;
	bool exit = false;
   bool found = false;
   int choice = 1;
   ClientType* tempClient;
   Stack<ClientType> tempStack;
   string name;
   int id;
   float balance;
   string consume;
   char isCorrect;

   do {
         cout << "---------Stack Menu--------" << endl;
         topLevelMenu();
			cin  >> input;

			switch (input)
			{
				case 1: // add to front
               // populateStack(stack);

               while (choice == 1) {
                  cin.ignore(255, '\n');
                  cin.clear();
                  cout << "Enter the name for the Account: " << endl;
                  getline(cin, name);
                  cout << "Enter ID for "<< name <<": " << endl;
                  cin  >> id;

                  cout << "Enter the current balance for " << name << ": " << endl;
                  cin  >> balance;
                  stack.push(new ClientType(id, name, balance));

                  cout << "Enter 1 to add another record: ";
                  cin  >> choice; 
               }
					break;

				case 2: // edit a record
               // updateAccountStack(stack);
               cout << "--------Update Records-----------" << endl;
               choice = 0;
               found = false;

               do {
                  cout << "Enter Account ID to Update: " << endl;
                  cin >> id;
                  // tempClient->setID(id);
                  while (!stack.isEmpty()) {
                     if (stack.top()->getID() == id) {
                        found = true;
                        break;
                     } else {
                        tempStack.push(stack.top());
                        stack.pop();
                     }
                  
                  }
                  if (!found) {
                     cout << "Account with Matching ID not found" << endl;
                  } else {
                     cin.ignore(256, '\n');
                     cout << "---Current Information---" << endl;
                     cout << stack.top()->toString() << endl;
                  
                     cout << "Enter the updated name for the Account: " << endl;
                     getline(cin, name);
                     
                     cout << "Enter the updated balance for " << name << ": " << endl;
                     cin  >> balance;

                     cout << "---Current Information---" << endl;
                     cout << stack.top()->toString() << endl;

                     cout << "---Updated Information---" << endl;
                     cout << "Name: "  << name << "\n"
                        << "ID: " << id << "\n"
                        << "Balance: " << balance << endl;
                     cout << "Is this information correct? (y/n): " << endl;
                     if (cin >> isCorrect) {
                        if (isCorrect == 'y' || isCorrect == 'Y') {
                           
                           stack.top()->setName(name);
                           stack.top()->setBalance(balance);
                           cout << "Record Updated." << endl;

                           while (!tempStack.isEmpty())
                           {
                              stack.push(tempStack.top());
                              tempStack.pop();
                           }

                           cout << "Enter 1 to update another record: ";
                           cin  >> choice; 
                           cin.ignore(255, '\n');
                        }
                     } 

                  }

               } while (choice == 1);
					break;

				case 3: // view (find specific)
               // viewAccountStack(stack);
               choice = 0;
               found = false;
               cout << "Enter Account ID: " << endl;
               cin >> id;
               // cout << "Setting temp" << endl;
               // tempClient->setID(id);
               while (!stack.isEmpty()) {
                  // cout << "Entering Loop" << endl;
                  if (stack.top()->getID() == id) {
                     // cout << "Item found" << endl;
                     found = true;
                     break;
                  } else {
                     // cout << "pushing to temp stack" << endl;
                     tempStack.push(stack.top());
                     stack.pop();
                  }
               }
               
               if (!found) {
                  cout << "Item not found" << endl;
               } else {
                  cout << stack.top()->toString() << endl;
               }

               while (!tempStack.isEmpty())
               {
                  stack.push(tempStack.top());
                  tempStack.pop();
               }  
					break;

				case 4: // print (trigger sub-menu)
               // printStack(stack);
               cout <<"Data in the stack\n";

               while (!stack.isEmpty()) {
                  cout << stack.top()->toString() <<endl;
                  tempStack.push(stack.top());
                  stack.pop();
                  
               }
               while (!tempStack.isEmpty())
               {
                  stack.push(tempStack.top());
                  tempStack.pop();
               }
					break;
					
				case 5: // delete
               // deleteStack(stack);
               cout << "Enter the id for the account you want to remove: \n";
               cin >> id;
               // tempClient->setID(id);
               while (!stack.isEmpty()) {
                  if (stack.top()->getID() == id) {
                     stack.pop();
                     found = true;
                     break;
                  } else {
                     tempStack.push(stack.top());
                     stack.pop();
                     // cout << "Item removed" << endl;
                  }
                  
               }
               if (!found) {
                  cout << "Item not found" << endl;
               } else {
                  cout << "Item removed" << endl;
               }
               while (!tempStack.isEmpty())
               {
                  stack.push(tempStack.top());
                  tempStack.pop();
               }
               found = false;
					break;

				case 6: //exit
				default:
					exit = true;
					break;
			}
	} while (!exit);
}

void queueMenu(Queue<ClientType> queue) {
   int input;
	bool exit = false;
   bool found = false;
   int choice = 1;
   ClientType* tempClient;
   Queue<ClientType> tempQueue;
   string name;
   int id;
   float balance;
   string consume;
   char isCorrect;

   do {
         cout << "---------Queue Menu--------" << endl;
         topLevelMenu();
			cin  >> input;

			switch (input)
			{
				case 1: // add to front
               // populateStack(stack);

               while (choice == 1) {
                  cin.ignore(255, '\n');
                  cin.clear();
                  cout << "Enter the name for the Account: " << endl;
                  getline(cin, name);
                  cout << "Enter ID for "<< name <<": " << endl;
                  cin  >> id;

                  cout << "Enter the current balance for " << name << ": " << endl;
                  cin  >> balance;
                  queue.push(new ClientType(id, name, balance));

                  cout << "Enter 1 to add another record: ";
                  cin  >> choice; 
               }
					break;

				case 2: // edit a record
               // updateAccountqueue(queue);
               cout << "--------Update Records-----------" << endl;
               choice = 0;
               found = false;

               do {
                  cout << "Enter Account ID to Update: " << endl;
                  cin >> id;
                  // tempClient->setID(id);
                  while (!queue.isEmpty()) {
                     if (queue.front()->getID() == id) {
                        found = true;
                        break;
                     } else {
                        tempQueue.push(queue.front());
                        queue.pop();
                     }
                  
                  }
                  if (!found) {
                     cout << "Account with Matching ID not found" << endl;
                  } else {
                     cin.ignore(256, '\n');
                     cout << "---Current Information---" << endl;
                     cout << queue.front()->toString() << endl;
                  
                     cout << "Enter the updated name for the Account: " << endl;
                     getline(cin, name);
                     
                     cout << "Enter the updated balance for " << name << ": " << endl;
                     cin  >> balance;

                     cout << "---Current Information---" << endl;
                     cout << queue.front()->toString() << endl;

                     cout << "---Updated Information---" << endl;
                     cout << "Name: "  << name << "\n"
                        << "ID: " << id << "\n"
                        << "Balance: " << balance << endl;
                     cout << "Is this information correct? (y/n): " << endl;
                     if (cin >> isCorrect) {
                        if (isCorrect == 'y' || isCorrect == 'Y') {
                           
                           queue.front()->setName(name);
                           queue.front()->setBalance(balance);
                           cout << "Record Updated." << endl;

                           while (!tempQueue.isEmpty())
                           {
                              queue.push(tempQueue.front());
                              tempQueue.pop();
                           }

                           cout << "Enter 1 to update another record: ";
                           cin  >> choice; 
                           cin.ignore(255, '\n');
                        }
                     } 

                  }

               } while (choice == 1);
					break;

				case 3: // view (find specific)
               // viewAccountqueue(queue);
               choice = 0;
               found = false;
               cout << "Enter Account ID: " << endl;
               cin >> id;
               // cout << "Setting temp" << endl;
               // tempClient->setID(id);
               while (!queue.isEmpty()) {
                  // cout << "Entering Loop" << endl;
                  if (queue.front()->getID() == id) {
                     // cout << "Item found" << endl;
                     found = true;
                     break;
                  } else {
                     // cout << "pushing to temp queue" << endl;
                     tempQueue.push(queue.front());
                     queue.pop();
                  }
               }
               
               if (!found) {
                  cout << "Item not found" << endl;
               } else {
                  cout << queue.front()->toString() << endl;
               }

               while (!tempQueue.isEmpty())
               {
                  queue.push(tempQueue.front());
                  tempQueue.pop();
               }  
					break;

				case 4: // print (trigger sub-menu)
               // printqueue(queue);
               cout <<"Data in the queue\n";

               while (!queue.isEmpty()) {
                  cout << queue.front()->toString() <<endl;
                  tempQueue.push(queue.front());
                  queue.pop();
                  
               }
               while (!tempQueue.isEmpty())
               {
                  queue.push(tempQueue.front());
                  tempQueue.pop();
               }
					break;
					
				case 5: // delete
               // deletequeue(queue);
               cout << "Enter the id for the account you want to remove: \n";
               cin >> id;
               // tempClient->setID(id);
               while (!queue.isEmpty()) {
                  if (queue.front()->getID() == id) {
                     queue.pop();
                     found = true;
                     break;
                  } else {
                     tempQueue.push(queue.front());
                     queue.pop();
                     // cout << "Item removed" << endl;
                  }
                  
               }
               if (!found) {
                  cout << "Item not found" << endl;
               } else {
                  cout << "Item removed" << endl;
               }
               while (!tempQueue.isEmpty())
               {
                  queue.push(tempQueue.front());
                  tempQueue.pop();
               }
               found = false;
					break;

				case 6: //exit
				default:
					exit = true;
					break;
			}
	} while (!exit);
}

int main(int argc, char const *argv[])
{
   // DoubleType<ClientType> doubleList;
   Stack<ClientType> myStack;
   Queue<ClientType> myQueue;

   // ClientType* tempClient;
   bool exit = false;

   do {   

         int option;
         cout << "=================Main Menu======================" << endl;
         cout << "To access the application using a stack enter 1: " << endl;
         cout << "To access the application using a queue enter 2: " << endl;
         cout << "To exit the application enter 3: " << endl;

         if (cin >> option) {
            switch (option)
            {
            case 1:
               stackMenu(myStack);
               break;
            
            case 2:
               //menu for queue
               queueMenu(myQueue);
               break;

            case 3:
            default:
               cout << "End of Program" << endl;
               exit = true;
               break;
            }
         }

      } while (!exit);


   return 0;
}