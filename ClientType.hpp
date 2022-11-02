#ifndef CLIENTTYPE_HPP
#define CLIENTTYPE_HPP


#include <string>
#include <sstream>
using namespace std;


class ClientType {
   private:
      
      int id;
      string name;
      double balance;
      
   public:
      //overloading comparison operators
      inline bool operator<  (const ClientType& rhs) {return this->getID() < rhs.getID();};
      inline bool operator>  (const ClientType& rhs) {return rhs.getID() < this->getID();}; 
      inline bool operator<= (const ClientType& rhs) {return !(this->getID() > rhs.getID());};
      inline bool operator>= (const ClientType& rhs) {return !(this->getID() < rhs.getID());};
      inline bool operator== (const ClientType& rhs);
      inline bool operator!= (const ClientType& rhs);
      
      ClientType();
      ClientType(int id, string name, double balance);

      //accessors
      int getID() const;
      double getBalance() const;
      string getName() const;

      //mutators
      void setName(string name);
      void setBalance(double balance);
      void setID(int id);
      
      string toString() const;



};

inline bool ClientType::operator== (const ClientType& rhs) {
   return this->id == rhs.getID();
}

inline bool ClientType::operator!=(const ClientType& rhs) {
   return !(this->id == rhs.getID());
}

ClientType::ClientType(int id, string name, double balance) {
   this->id = id;
   this->name = name;
   this->balance = balance;
}

ClientType::ClientType() {
   this->id = 0;
   this->name = "";
   this->balance = 0.0;
}

int ClientType::getID() const{
   return id;
}

string ClientType::getName() const{
   return name;
}

double ClientType::getBalance() const{
   return balance;
}

void ClientType::setName(string newName) {
   this->name = newName;
}

void ClientType::setBalance(double balance) {
   this->balance = balance;
}

void ClientType::setID(int id) {
   this->id = id;
}

string ClientType::toString() const {
   ostringstream buffer;

   buffer << "Name: " << this->name << "\n"
          << "ID: " << this->id << "\n"
          << "Balance: " << this->balance << "\n";
   return buffer.str();

}


#endif

