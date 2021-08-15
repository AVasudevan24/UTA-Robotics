#include <iostream>
using namespace std;

int main(){
   //declare the array and the other variables
   float gradeArray[10];
   float gradeSum, gradeAverage;
   int i;

   //put some grades into the array
   for (i=0; i<10;) {
       gradeArray[i] = 0;
       cout << "Enter number " << i << endl;
       cin >>gradeArray[i];
       i++;
   }
   

   //initialize the gradeSum variable to be 0
   gradeSum = 0;

   //loop through each location in gradeArray (there are 5)
   for(i=0; i<10; i++){
      //add the value of the thing stored at location
      //i in gradeArray to gradeSum
      gradeSum += gradeArray[i];
   }

   //to finish the average, divide gradeSum by 5
   gradeAverage = gradeSum/5;

   //print out the average
   cout << "Your average is " << gradeAverage << ".\n";
   return 0;
}