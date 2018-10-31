#include<iostream>
using namespace std;
int main(){
 
 cout << "==primitive types ==" << endl;
 typedef signed short age;
 age years;
 cout << "How old are you?" << endl;
 //years<< ;
 //cout << ("You are: " + years + " years old") << endl

 enum rooms {tween, single=101, lage} r1, r3;
 r1 = tween;
 r3 = lage;
 cout << r1 << endl;
 cout << r3 << endl;
 cout << sizeof(r1) << endl;
 return 0;
}