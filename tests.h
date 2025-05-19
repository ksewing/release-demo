/*
A unit testing framework for the scoring components of the Yahtzee 
program.  

Each unit tests can be created by forming a TestCase object with all relevant
information for the unit test.

Ex:
TestCase{ SMALL_STR, {6, 5, 3, 1, 4}, 30}

Indicates that the test will run against the small straight scoring function.
The dice roll is 6, 5, 3, 1, 4
The score should be 30 because it does contain a small straight (3, 4, 5, 6)

Author: Katie Ewing, 2024
*/

#ifndef TESTS_H
#define TESTS_H
#include <iostream>
#include <vector>

/* Enumerates the various types of scoring functions that can be run and tested.

VALUE_1 - VALUE_6:  Validates the score for dice with face value 1 - 6.
THREE_OF_KIND:  Validates the score for rolls with 3 of the same dice.
FOUR_OF_KIND: Validates the score for rolls with 4 of the same dice.
YAHTZEE: Validates the score for rolls with all 5 dice with the same value.
FULL_HOUSE: Validates the score for rolls with 3 of one value and 2 of another.
SMALL_STR, LARGE_STR: Validates the score for rolls with 4 or 5 dice in a row.
CHANCE: Validates the score by summing the face values of the dice.
*/
enum TestType { VALUE_1, VALUE_2, VALUE_3, VALUE_4, VALUE_5, VALUE_6,
                THREE_OF_KIND, FOUR_OF_KIND, YAHTZEE, FULL_HOUSE,
                SMALL_STR, LARGE_STR, CHANCE };

/*
Unit test struct containing the needed information to run a test in this 
framework.

TestType: Specify the scoring function you want to validate, using the enum 
value.

roll: Specify a vector of dice values that you want to be evaluating by the 
specified scoring function.

expectedScore: Specify the score you expect to receive if you run the given 
roll with the given scoring function.

*/
struct TestCase {
    TestType type;
    std::vector<int> roll;
    int expectedScore;
};

/* 
Runs all specified unit tests for the Yahtzee scoring functions.
*/
void runTestSuite();

/* Runs a single unit test for the Yahtzee scoring functions.

Displays unit test information including the test type, the roll tested,
the expected score and the obtained score.

Ex:
Test dice value 1 with roll [ 1 2 1 6 3 ]
(PASS) got: 2, expected 2

Returns true if the test passed, false otherwise.
*/
bool runTestCase(TestCase tc);

#endif
