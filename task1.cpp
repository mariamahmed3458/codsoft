#include <iostream>
#include <cstdlib> // for rand()
using namespace std;

int main() {
    int number = rand() %2000;  //%2000 makes rand choose number from 1 to 1999 and also to prevent very large numbers.
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
