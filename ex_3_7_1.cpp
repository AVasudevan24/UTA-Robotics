#include <iostream>
using namespace std;

int main () {
    float gradeArray[7];
    float gradeSum, GradeAverage;
    int i;

    gradeArray[0]=92.8;
    gradeArray[1]=76.9;
    gradeArray[2]=65.9;
    gradeArray[3]=90.8;
    gradeArray[4]=100;
    gradeArray[5]=80.9;
    gradeArray[6]=19.8;

    gradeSum=0;

    for(i=0; i<7; i++){
        gradeSum += gradeArray[i];
    }
    GradeAverage=gradeSum/7;
    cout <<"Average is: "<< GradeAverage<< endl;
}