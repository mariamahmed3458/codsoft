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
