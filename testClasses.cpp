#include <iostream>
#include "DoubleType.hpp"
#include "ClientType.hpp"
#include "Queue.hpp"
#include "Stack.hpp"

using namespace std;



int main(int argc, char const *argv[])
{
   // DoubleType<ClientType> doubleList;
   Stack<ClientType> myStack;
   Queue<ClientType> myQueue;
   Stack<ClientType> tempStack;
   Queue<ClientType> tempQueue;

   // ClientType* tempClient;
   bool exit = false;

   do {   

         int option;
         cout << "To access the application using a stack enter 1: " << endl;
         cout << "To access the application using a queue enter 2: " << endl;
         cout << "To exit the application enter 3: " << endl;

         if (cin >> option) {
            switch (option)
            {
            case 1:
               /* code */
               //menu for stack
               break;
            
            case 2:
               //menu for queue
               break;

            case 3:
            default:
               cout << "End of Program" << endl;
               exit = true;
               break;
            }
         }



      //   topLevelMenu();

      //   if (cin >> option) {
      //       switch (option) {
      //          case 1:
      //             populate(List);
      //             break;
      //          case 2:
      //             view(List);
      //             break;

      //          case 3:
      //             updateAccount(List);
      //             break;//update
      //          case 4:
      //             deleteItem(List);
      //             break;

      //          case 5: //exit
      //          default:
      //             cout << "Goodbye!\n";
      //             exit = true;
      //             break;

      //       }
      //   } else {
      //       invalidInput();
      //   }
      } while (!exit);


   return 0;
}

// void topLevelMenu() {
//     cout << "----Main Menu----\n"
//     << "1.\tAdd Accounts\n"
//     << "2.\tView Accounts\n"
//     << "3.\tUpdate Accounts\n"
//     << "4.\tRemove Accounts\n"
//     << "5.\tExit\n";
// }