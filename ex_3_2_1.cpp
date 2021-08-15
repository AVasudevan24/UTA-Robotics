#include <iostream>
using namespace std;

int main () {
    float number1, number2, sum;
    cout <<"Enter your first number: ";
    cin >> number1;
    cout <<"Your first number was " <<number1<< ".  What would you like to add to it?:";
    cin >> number2;
    sum = number1+number2;
    cout <<number1<< " added to " <<number2<< " is " <<sum<< " :D "<< endl;
    return 0;
}