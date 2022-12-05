#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  ifstream inputFile("input.txt");
  string fileOutput;

  int score = 0;  // used for part one
  int points = 0; // used for part two

  while (getline(inputFile, fileOutput)) {
    char them = fileOutput[0];
    char you = fileOutput[2];

    if (you == 'X') {
      score += 1;
    }
    if (you == 'Y') {
      score += 2;
    }
    if (you == 'Z') {
      score += 3;
    }

    // draw scenarios
    if ((them == 'A' && you == 'X') || (them == 'B' && you == 'Y') ||
        (them == 'C' && you == 'Z')) {
      score += 3;
    }

    // win scenarios
    if ((them == 'A' && you == 'Y') || (them == 'B' && you == 'Z') ||
        (them == 'C' && you == 'X')) {
      score += 6;
    }

    char end = you;

    // X == defeat
    // Y == draw
    // Z == victory

    // win outcome
    if (end == 'Z') {
      if (them == 'A') {
        points += 8;
      } else if (them == 'B') {
        points += 9;
      } else if (them == 'C') {
        points += 7;
      }
    }

    // draw outcome
    if (end == 'Y') {
      if (them == 'A') {
        points += 4;
      } else if (them == 'B') {
        points += 5;
      } else if (them == 'C') {
        points += 6;
      }
    }

    // defeat outcome
    if (end == 'X') {
      if (them == 'A') {
        points += 3;
      } else if (them == 'B') {
        points += 1;
      } else if (them == 'C') {
        points += 2;
      }
    }
  }

  cout << "\nPart 1: " << score;
  cout << "\n\nPart 2: " << points << "\n\n";
  return 0;
}
