/******************************************************************************

Yahtzee program.  CSS 132 Functions assignment.

*******************************************************************************/
#include <iostream>
#include <vector>
#include "yahtzee.h"
#include "tests.h"
using namespace std;


int main()
{
    // randomize seed
    srand(time(0));
    
    // user choice menu
    cout << "Welcome to the Yahtzee scoring program" << endl;
    cout << "Do you want to " << endl;
    cout << "A) Score an inputted roll?" << endl;
    cout << "B) Score a random roll?" << endl;
    cout << "C) Run test suite?" << endl;
    
    char userChoice;
    cin >> userChoice;
    
    vector<int> roll;
    
    switch(userChoice){
        case 'A':
        case 'a':
            roll = inputRoll();
            printRoll(roll);
            scoreRoll(roll);
            break;
        case 'B':
        case 'b':
            roll = generateRoll();
            printRoll(roll);
            scoreRoll(roll);
            break;
        case 'C':
        case 'c':
            runTestSuite();
            break;
        default:
            cout << "Invalid choice.  Choose A, B, or C.";
    }

    return 0;
}
