#include <iostream>
using namespace std;
main() {
    int userInput,attempts;
    attempts=1;

   //get input from user
   cout << "Enter a number between 1 and 10: ";
   cin >> userInput;

   //as long as userInput is less than 1 or greater than 10
   while((userInput < 1) || (userInput > 10)){
      cout << "Read directions!  Enter a number between 1 and 10: ";
      attempts=attempts+1;
      cin >> userInput;  //get new input from the user
   }
   //when we reach this line, we know the user entered a number between 1 and 10,
   //or else we would still be stuck in the while loop.
   cout << "You entered " << userInput << "." << endl;
   if (attempts<2 && attempts>0) { //if the number is 1, it displays "try" instead of "tries" 
       cout << "It took you " <<attempts<< " try!" <<endl;
   }
   else {cout<< "It took you "<< attempts << " tries!" << endl;} //if the number isn't 1, it displats "tries"
   return 0;
}
