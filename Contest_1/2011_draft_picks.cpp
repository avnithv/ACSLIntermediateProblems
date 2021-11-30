#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<double> split(string inp) {
  vector<double> s;
  string str = "";
  int is = inp.size();
  for(int i = 0; i < is; i++) {
    if ((48 <= inp[i] && inp[i] <= 57) || inp[i] == 46) str += inp[i];
    else if (str.compare("") != 0) {
      s.push_back(stod(str));
      str = "";
    }
  }
  if (str.compare("") != 0) s.push_back(stod(str));
  return s;
}

vector<double> find_annual(vector<double> input) {
  vector<double> v;
  for (int i = 0; i < 10; i++) {
    v.push_back((input[2*i+1] * 1000000) / input[2 * i]);
  }
  return v;
}

int average(vector<double> input) {
  double sum = 0;
  for (double val : input) {
    sum += val;
  }
  return (int)round(sum/input.size());
}

int game_average(vector<double> games16, vector<double> games18) {
  double sum = 0;
  int s = games16.size();
  for (int i = 0; i < s; i++) {
    sum += games16[i] - games18[i];
  }
  return (int)round(sum/games16.size());
}

int highest(vector<double> input) {
  int index = 0, is = input.size();
  for (int i = 1; i < is; i++) {
    if (input[i] > input[index]) index = i;
  }
  return index;
}

int lowest(vector<double> input) {
  int index = 0, is = input.size();
  for (int i = 1; i < is; i++) {
    if (input[i] < input[index]) index = i;
  }
  return index;
}

vector<double> pergame(vector<double> input, int games) {
  int is = input.size();
  for (int i = 0; i < is; i++) {
    input[i] /= games;
  }
  return input;
}

void solve(vector<double> input) {
  vector<double> annual = find_annual(input);
  cout << average(annual) << "\n";
  int hindex = highest(annual), lindex = lowest(annual);
  cout << (int)round(annual[hindex]) << " by #" << hindex + 1 << "\n";
  vector<double> games16 = pergame(annual, 16);
  vector<double> games18 = pergame(annual, 18);
  cout << (int)round(games16[hindex] - games16[lindex]) << "\n";
  cout << (int)round((games18[hindex] + games18[lindex]) / 2.) << "\n";
  cout << game_average(games16, games18) << "\n";
}


void print(vector<double> x) {
  for (double val : x) {
    cout << val << " ";
  }
  cout << "\n";
}

int main() {
  string input;
  getline(cin, input);
  vector<double> inp = split(input);
  int s = inp.size();
  while (s < 20) {
    getline(cin, input);
    vector<double> newinp = split(input);
    s += newinp.size();
    inp.insert(inp.end(), newinp.begin(), newinp.end());
  }

  solve(inp);
  return 0;
}