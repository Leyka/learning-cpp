#include <iostream>

using namespace std;

void changeAge(int* pAge) {
    cout << "changeAge, pointer value of age: " << pAge << endl; // => &age : 000000B83AFCFB40
    *pAge = 30;
}

void changeAge2(int age) {
    int* pAge = &age;
    cout << "changeAge2, pointer value of age: " << pAge << endl; // => &age : 000000B83AFCFB20 so it created a copy of age
    *pAge = 40;
}

void changeAge3(int& age) {
    int* pAge = &age;
    cout << "changeAge3, age " << age << " pointer value of age: " << pAge << endl;
    *pAge = 50;
    cout << "changeAge3,  " << age << " pointer value of age: " << pAge << endl;
}

int main() {
    int age = 25;
    cout << "age = " << age << endl;

    // Create a pointer of 'age' variable
    int* pAge = &age;
    cout << "pAge = &age = " << pAge << endl; // => &age : 000000B83AFCFB40
    cout << "*pAge = " << *pAge << endl;

    changeAge(pAge);
    cout << "Age is now... " << *pAge << endl; // Age is now 30

    changeAge2(age);
    cout << "Age (2) would still be the same " << *pAge << endl; // Age is still 30, not 40. Not the same pointer reference.

    changeAge3(age);
    cout << "Age (3) is now... " << *pAge << endl;

    // Trying something for fun
    int** mindBlown = &pAge;
    cout << "------------" << endl;
    cout << "Reference of reference of Age: " << mindBlown << endl;
    
    return 0;
}
