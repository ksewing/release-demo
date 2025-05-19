#include "yahtzee.h"
#include <algorithm>
using namespace std;

const int DICE_PER_ROLL = 5;
const int MIN_DICE_VAL = 1;
const int MAX_DICE_VAL = 6;

void printRoll(vector<int> roll){
    cout << "[ ";
    for (int d : roll){
        cout << d << " ";
    }
    cout << "]" << endl;
}


vector<int> inputRoll(){
    printf("Input %d dice: ", DICE_PER_ROLL);
    vector<int> dice(DICE_PER_ROLL);
    for (int i = 0; i < DICE_PER_ROLL; i++){
        cin >> dice.at(i);
    }
    return dice;
}

vector<int> generateRoll(){
    vector<int> dice(DICE_PER_ROLL);
    for (int& d : dice){
        d = rand() % MAX_DICE_VAL + MIN_DICE_VAL;
    }
    return dice;
}

void scoreRoll(vector<int> roll){
    for (int i = MIN_DICE_VAL; i <= MAX_DICE_VAL; i++){
        printf("Dice value %d score: %d \n", i, scoreDiceValue(roll, i));
    }
    printf("3 of a kind score: %d \n", score3ofAKind(roll));
    printf("4 of a kind score: %d \n", score4ofAKind(roll));
    printf("Yahtzee score: %d \n", scoreYahtzee(roll));
    printf("Full house score: %d \n", scoreFullHouse(roll));
    printf("Small straight score: %d \n", scoreSmallStraight(roll));
    printf("Large straight score: %d \n", scoreLargeStraight(roll));
    printf("Chance score: %d \n", scoreChance(roll));
}

int scoreChance(vector<int> roll){
    int score = 0;
    for (int d : roll){
        score += d;
    }
    return score;
}

int scoreDiceValue(vector<int> roll, int val){
    int score = 0;
    for (int d : roll){
        if (d == val){
            score += d;
        }
    }
    return score;
}

int scoreXofAKind(vector<int> roll, int num){
    vector<int> freq(MAX_DICE_VAL + 1, 0);
    for (int d : roll){
        freq.at(d)++;
    }
    for (int i = MIN_DICE_VAL; i <= MAX_DICE_VAL; i++ ){
        if (freq.at(i) >= num){
            return freq.at(i) * i;
        }
    }
    return 0;
}


int score3ofAKind(vector<int> roll){
    return scoreXofAKind(roll, 3);
}

int score4ofAKind(vector<int> roll){
    return scoreXofAKind(roll, 4);
}
int scoreYahtzee(vector<int> roll){
    return scoreXofAKind(roll, 5) > 0 ? 100 : 0;
}

int scoreFullHouse(std::vector<int> roll){
    bool set3 = false, set2 = false;
    vector<int> freq(MAX_DICE_VAL + 1, 0);
    for (int d : roll){
        freq.at(d)++;
    }
    for (int f : freq){
        set2 = (f == 2) ? true : set2;
        set3 = (f == 3) ? true : set3;
    }
    return (set2 && set3) ? 25 : 0;
}

int scoreSmallStraight(std::vector<int> roll){
    return maxStreak(roll) >= 4 ? 30 : 0;
}

int scoreLargeStraight(std::vector<int> roll){
    return maxStreak(roll) >= 5 ? 40 : 0;
}

int maxStreak(std::vector<int> roll){
    sort(roll.begin(), roll.end());
    
    int currStreak = 1;
    for (int i = 1; i < roll.size(); i++){
        if (roll.at(i) == roll.at(i-1) + 1){
            currStreak++;
        } else {
            currStreak = 1;
        }
    }
    return currStreak;
}




