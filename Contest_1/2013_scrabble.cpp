#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<vi, vi> pvi;

#define FOR(i, a, b) for(int i = a; i < b; i++)
#define MP make_pair

map<char, int> points = {
  {'A', 1},
  {'E', 1},
  {'D', 2},
  {'R', 2},
  {'B', 3},
  {'M', 3},
  {'V', 4},
  {'Y', 4},
  {'J', 8},
  {'X', 8}
};

vi generate_board() {
  vi board(40, 1);
  FOR(i, 1, 41) {
    if (i % 3 == 0 && i % 6 != 0) board[i - 1] = 2;
    else if (i % 5 == 0) board[i - 1] = 3;
    else if (i % 7 == 0) board[i - 1] = 4;
    else if (i % 8 == 0) board[i - 1] = 5;
  }
  return board;
}

vector<string> split(string inp) {
  vector<string> s;
  string str = "";
  int is = inp.size();
  for(int i = 0; i < is; i++) {
    if ((48 <= inp[i] && inp[i] <= 57) || points.count(inp[i]) || inp[i] == 'H') str += inp[i];
    else if (str.compare("") != 0) {
      s.push_back(str);
      str = "";
    }
  }
  if (str.compare("") != 0) s.push_back(str);
  return s;
}

int solve(int start, char which, vector<string> words) {
  int z;
  if (which == 'H') z = 1;
  else z = 10;

  vi board = generate_board();
  int letters = 0; int word = 1;
  for(int i = start; i < 40 && i < start + 4 * z; i += z) {
    int p = points[words[(i - start)/z][0]];
    if (board[i] > 3) {
      word *= board[i] - 2;
      letters += p;
    } else {
      letters += p * board[i];
    }
  }
  return letters * word;
}

int main() {
  string input;
  getline(cin, input);
  vector<string> inp = split(input);
  vi board = generate_board();
  
  FOR(i, 0, 5) {
    getline(cin, input);
    vector<string> z = split(input);
    cout << solve(stoi(z[0]) - 1, z[1][0], inp) << "\n";
  }
  return 0;
}