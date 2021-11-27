#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> split(string inp) {
  vector<int> s;
  int a = inp.find(", ");
  while (a != -1) {
    s.push_back(stoi(inp.substr(0, a)));
    inp = inp.substr(a + 2, inp.size());
    a = inp.find(", ");
  }
  s.push_back(stoi(inp));
  return s;
}

void print(int par, int score) {
  string s;
  if (score == par) cout << "par\n";
  else if (score < par) cout << par - score << " under par\n";
  else cout << score - par << " over par\n";
}

int main() {
  vector<int> cumulative(2);
  vector<int> wins(2);
  int par = 0, max_score = -1;
  for (int i = 0; i < 9; i++) {
    string input;
    getline(cin, input);
    vector<int> inp = split(input);
    
    par = par + inp[0];
    
    cumulative[0] += inp[1];
    cumulative[1] += inp[2];
    
    if (inp[1] < inp[2]) wins[0]++;
    if (inp[2] < inp[1]) wins[1]++;
    
    if (max_score == -1) max_score = inp[1] + inp[2];
    else max_score = max(inp[1] + inp[2], max_score);
  }
  
  bool winner, loser;
  if (cumulative[0] < cumulative[1]) winner = false;
  else winner = true;
  loser = !winner;

  cout << cumulative[winner] << ", " << cumulative[loser] << "\n";
  print(par, cumulative[winner]);
  print(par, cumulative[loser]);
  cout << wins[winner] << "\n";
  cout << max_score << "\n";
  return 0;
}