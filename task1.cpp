#include <iostream>
#include <cstdlib> // for rand()
using namespace std;

int main() {
    int number = rand();
    int guess;
    cout << "Enter a guess: ";
    cin >> guess;

    while (guess != number) {
        if (guess < number) {
            cout << "Your guess is lower than the number\n";
        } else {
            cout << "Your guess is higher than the number\n";
        }
        
        cout << "Enter a guess: ";
        cin >> guess;
    }

    cout << "Correct!\n";
    return 0;
}
