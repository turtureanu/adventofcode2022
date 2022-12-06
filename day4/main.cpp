#include <algorithm>
#include <bits/stdc++.h>
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <regex>
#include <vector>

using namespace std;

// Function copied from Geeks for geeks
bool isSubArray(vector<int> A, vector<int> B, int n, int m) {
  int i = 0, j = 0;

  while (i < n && j < m) {
    if (A[i] == B[j]) {
      i++;
      j++;

      if (j == m)
        return true;
    }

    else {
      i = i - j + 1;
      j = 0;
    }
  }

  return false;
}

int main() {
  ifstream inputFile("input.txt");
  string fileOutput;
  int overlaps = 0;
  int allOverlaps = 0;
  int lol = 0;
  while (getline(inputFile, fileOutput)) {
    smatch matchType;
    regex elfRegexStart1("^[0-9]+"), elfRegexEnd1("(?![0-9]+-)([0-9]+)(?=.*,)"),
        elfRegexStart2("(?!.*,)[0-9]+(?=-)"),
        elfRegexEnd2("(?!.*,)[0-9]+(?!.*-)");
    regex_search(fileOutput, matchType, elfRegexStart1);

    int elfStart1;
    for (auto x : matchType) {
      elfStart1 = stoi(x);
    }

    regex_search(fileOutput, matchType, elfRegexEnd1);
    int elfEnd1;
    for (auto x : matchType) {
      elfEnd1 = stoi(x);
    }

    regex_search(fileOutput, matchType, elfRegexStart2);

    int elfStart2;
    for (auto x : matchType) {
      elfStart2 = stoi(x);
    }

    regex_search(fileOutput, matchType, elfRegexEnd2);

    int elfEnd2;
    for (auto x : matchType) {
      elfEnd2 = stoi(x);
    }

    vector<int> elfRange1;
    vector<int> elfRange2;

    for (int i = elfStart1; i < (elfEnd1 + 1); i++) {
      elfRange1.push_back(i);
    }

    for (int i = elfStart2; i < (elfEnd2 + 1); i++) {
      elfRange2.push_back(i);
    }

    if (elfRange1 == elfRange2) {
      overlaps++;
    } else {
      if (isSubArray(elfRange1, elfRange2, elfRange1.size(),
                     elfRange2.size())) {
        overlaps++;
      }

      if (isSubArray(elfRange2, elfRange1, elfRange2.size(),
                     elfRange1.size())) {
        overlaps++;
      }
    }

    int i, j; // for some reason

    vector<int> common;

    for (i = 0; i < elfRange1.size(); i++) {

      for (j = 0; j < elfRange2.size(); j++) {

        if (elfRange1[i] == elfRange2[j]) {
          common.push_back(i);
        }
      }
    }

    if (common.size()) {
      allOverlaps++;
    }
  }

  cout << "\nPart 1: " << overlaps;
  cout << "\n\nPart 2: " << allOverlaps << "\n\n";
}
