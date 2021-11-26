#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<string> split(string inp) {
  vector<string> s;
  int a = inp.find(", ");
  while (a != -1) {
    s.push_back(inp.substr(0, a));
    inp = inp.substr(a + 2, inp.size());
    a = inp.find(", ");
  }
  s.push_back(inp);
  return s;
}

int mappoints(char suit) {
  if (suit == 'H' || suit == 'S' || suit == 'T') return 30;
  else if (suit == 'C' || suit == 'D') return 20;
  else if (suit == 'V') return 100;
  else return 50;
}

pair<int, int> solve(int bid, int tricks, char suit, char vul) {
  int num_over = tricks - 6 - bid, under = 0, over = 0;
  if (num_over < 0) over = mappoints(vul) * num_over * -1;
  else {
    under = mappoints(suit) * bid;
    over = mappoints(suit) * num_over;
    if (suit == 'T') under += 10; 
  }
  return make_pair(under, over);
}


int main() {
  for (int i = 0; i < 5; i++) {
    string input;
    getline(cin, input);
    vector<string> inp = split(input);
    
    int bid = stoi(inp[0]), tricks = stoi(inp[1]);
    char suit = inp[2][0], vul = inp[3][0];

    pair<int, int> ans = solve(bid, tricks, suit, vul);
    cout << ans.first << ", " << ans.second << "\n";
  }
  return 0;
}