#include "tests.h"
#include "yahtzee.h"
using namespace std;

/* 
Vector containing all unit tests that will be run in the test suite. 
ADD NEW TEST CASES HERE!
*/
const vector<TestCase> TEST_CASES = {
    TestCase{VALUE_1, {1, 2, 1, 6, 3}, 2 },
    TestCase{YAHTZEE, {1, 2, 1, 6, 3}, 2 },
    TestCase{LARGE_STR, {1, 2, 1, 6, 3}, 2 },
    TestCase{CHANCE, {1, 2, 1, 6, 3}, 2 },
};

void runTestSuite(){
    int fail = 0, pass = 0;
    cout << endl << "TESTING..." << endl << endl;
    for (TestCase tc : TEST_CASES){
        bool result = runTestCase(tc);
        result ? pass++ : fail++;
        cout << endl;
    }
    int total = pass + fail;
    printf("\n%d tests run, %d passed (%d%%)\n", total, pass, 100*pass / total);
}

bool runTestCase(TestCase tc){
    int score = -1;
    
    switch(tc.type){
        case VALUE_1:
            cout << "Test dice value 1 ";
            score = scoreDiceValue(tc.roll, 1);
            break;
        case VALUE_2:
            cout << "Test dice value 2 ";
            score = scoreDiceValue(tc.roll, 2);
            break;
        case VALUE_3:
            cout << "Test dice value 3 ";
            score = scoreDiceValue(tc.roll, 3);
            break;
        case VALUE_4:
            cout << "Test dice value 4 ";
            score = scoreDiceValue(tc.roll, 4);
            break;
        case VALUE_5:
            cout << "Test dice value 5 ";
            score = scoreDiceValue(tc.roll, 5);
            break;
        case VALUE_6:
            cout << "Test dice value 6 ";
            score = scoreDiceValue(tc.roll, 6);
            break;
        case SMALL_STR:
            cout << "Test small straight ";
            score = scoreSmallStraight(tc.roll);
            break;
        case LARGE_STR:
            cout << "Test large straight ";
            score = scoreLargeStraight(tc.roll);
            break;
        default:
            cout << "Undefined test type: " << tc.type << endl;
    }
    
    cout << "with roll ";
    printRoll(tc.roll);
    
    bool result = tc.expectedScore == score;
    printf("(%s) ", result ? "PASS" : "FAIL");
    printf("got: %d, expected %d\n", score, tc.expectedScore);

    return result;
}




