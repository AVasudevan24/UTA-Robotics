#include <iostream>
using namespace std;

void printGreeting(string name){
   cout << "Hello " <<name<< endl;
}

int main(){
   string userName;
   cout <<"Whats your name?: ";
   cin >> userName;

   printGreeting(userName);
   printGreeting(userName);
   return 0;
}