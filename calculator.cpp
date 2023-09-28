#include <iostream>
using namespace std;
int main()
{
    int x, y,z;
    char o;
    operation:
    cout << "Enter the first number: ";
    cin >> x;

    cout << "Enter the second number: ";
    cin >> y;

    cout << "Which operation do you want (+, -, *, /): ";
    cin >> o;

    if (o == '+') {
        cout << "Result: " << (x + y) << endl;
    } else if (o == '-') {
        cout << "Result: " << (x - y) << endl;
    } else if (o == '*') {
        cout << "Result: " << (x * y) << endl;
    } else if (o == '/') {
        if (y != 0) {
            cout << "Result: " << (x / y) << endl;
        } else {
            cout << "Error: Division by zero is not allowed." << endl;
        }
    } else {
        cout << "Error: Invalid operation." << endl;
    }
    cout<<"do you want another operation"<<endl;
    cout<<"if yes press 1 if no press 0"<<endl;
    cin>>z;
    if (z == 1)
    {
        goto operation;
    }
    return 0;
}
//Task 2:Simple Calculator 
//In the main function, The code starts by declaring //3 integers variable ( two for the input from the
 //user and the third  is for whether the user wants
 //another operation or not ) and one character which is responsible for the required operation.
//The program asks the user to enter two number and to choose whish operation he wants to be done 
//on them and after the operation is done ,the program asks the user if he wants to do another 
//operation and for this I use goto statement .

//In this task , I got used to use goto Statement and know more about its syntax. 
