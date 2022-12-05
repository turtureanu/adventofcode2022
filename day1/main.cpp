#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

  vector<int> caloriesPerElf;

  int mostCalories = 0;
  int sum = 0;
  ifstream inputFile("input.txt");
  string fileOutput;
  while (getline(inputFile, fileOutput)) {
    if (fileOutput.length() == 0) {
      sum = 0;
    } else {
      sum += stoi(fileOutput);
    }
    caloriesPerElf.push_back(sum);
  }

  sort(caloriesPerElf.begin(), caloriesPerElf.end(), greater<int>());

  cout << "\nPart 1: " << caloriesPerElf[0];
  cout << "\n\nPart 2: ";
  sum = 0;
  for (int i = 0; i < 3; i++) {
    sum += caloriesPerElf[i];
  }

  cout << sum << "\n\n";
  return 0;
}
