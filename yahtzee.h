/*
Your header here.
*/

#ifndef YAHTZEE_H
#define YAHTZEE_H

#include <vector>
#include <iostream>

void printRoll(std::vector<int> roll);
std::vector<int> inputRoll();
std::vector<int> generateRoll();
void scoreRoll(std::vector<int> roll);
int scoreDiceValue(std::vector<int> roll, int val);
int scoreXofAKind(std::vector<int> roll, int num);
int score3ofAKind(std::vector<int> roll);
int score4ofAKind(std::vector<int> roll);
int scoreYahtzee(std::vector<int> roll);
int scoreFullHouse(std::vector<int> roll);
int scoreSmallStraight(std::vector<int> roll);
int scoreLargeStraight(std::vector<int> roll);
int maxStreak(std::vector<int> roll);
int scoreChance(std::vector<int> roll);

#endif 
