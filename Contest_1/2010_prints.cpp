#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int hi[] = {16, 16, 8, 8, 4, 4, 2, 2, 1, 1};
int ai[] = {16, 8, 4, 2, 1, 16, 8, 4, 2, 1};

bool hb[] = {true, false, true, false, true, false, true, false, true, false};
bool ab[] = {false, false, false, false, false, true, true, true, true, true};

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

pair<int, int> find(vector<int> fingers, char type) {
  int top = 1, bottom = 1;
  for (int finger : fingers) {
    finger--;
    bool which;
    int num;
    if (type == 'H') {
      which = hb[finger];
      num = hi[finger];
    } else {
      which = ab[finger];
      num = ai[finger];
    }
    if (which) bottom += num;
    else top += num;
  }
  return make_pair(top, bottom);
}


int main() {
  for (int i = 0; i < 5; i++) {
    string input;
    getline(cin, input);
    vector<string> inp = split(input);
    
    char type = inp[0][0];
    vector<int> fingers;
    
    int j = 1;
    while (stoi(inp[j]) != 0) fingers.push_back(stoi(inp[j++]));

    pair<int, int> ans = find(fingers, type);
    cout << ans.first << " / " << ans.second << "\n";
  }
  return 0;
}