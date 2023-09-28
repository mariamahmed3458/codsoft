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
// Task 1 : Number guessing game 
//First in this code i included cstdlib library to use rand function .
//In main function, first i declared two integer variables , one for rand and  i have put 
//limit to rand function to prevent any error could happen (like randomly choose very large number) 
//and the other for the guess by the user and then the game asks the user to enter their guess and 
//the game provides a feedback on whether the guess is higher or lower than the number and it keeps looping until the user guess it correctly. 

// In this task , I have developed my skills in learning new libraries and functions .
