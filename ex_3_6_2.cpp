#include <iostream>
using namespace std;

main() {
    for (int num1=1; num1<10; num1+=2){  // num1 for-loop
   for (int num2=2; num2<11; num2+=2){  //num2 for-loop
      cout << num1 << " x " << num2 << " = " << num1*num2 << endl;  //prints out num1+num2
   }
}
}