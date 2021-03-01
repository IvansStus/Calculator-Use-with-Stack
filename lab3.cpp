// Ivan Stus cssc1719
// CS320Lab3 - lab3.cpp (Driver) 

#include "point.cpp"

int main() {
    Point obj1(5.0f, 10.0f);    //Point class initializations
    Point obj2(7.0f, 12.0f);
    cout << "True = 1, False = 0" << endl;  //Compile Info
    cout << "obj1: " << obj1 << endl;       
    cout << "obj2: " << obj2 << endl;    
    cout << "obj1 < obj2 = " << (obj1 < obj2) << endl;  //Operators being tested
    cout << "obj1 > obj2 = " << (obj1 > obj2) << endl;
    cout << "obj1 <= obj2 = " << (obj1 <= obj2) << endl;
    cout << "obj1 >= obj2 = " << (obj1 >= obj2) << endl;
    cout << "obj1 == obj2 = " << (obj1 == obj2) << endl;
    cout << "obj1 != obj2 = " << (obj1 != obj2) << endl;
}