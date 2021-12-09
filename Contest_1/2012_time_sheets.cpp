#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int c(string s) {
  if (s.length() > 1) return stoi(s);
  char ch = s[0];
  if (65 <= ch && ch <= 72) return ch - 55;
  else return ch - 48;
}

vector<int> split(string inp) {
  vector<int> s;
  string str = "";
  int is = inp.size();
  for(int i = 0; i < is; i++) {
    if ((48 <= inp[i] && inp[i] <= 57) || (65 <= inp[i] && inp[i] <= 72)) str += inp[i];
    else if (str.compare("") != 0) {
      s.push_back(c(str));
      str = "";
    }
  }
  if (str.compare("") != 0) s.push_back(c(str));
  return s;
}

double money(int loc, double hrs, int day) {
  double pay = 0, nextpay = 0, hours = 0;
  switch (loc / 100) {
    case 1: 
      pay = 10.;
      nextpay = 15.;
      hours = 5.;
      break;
    case 2:
      pay = 7.5;
      nextpay = 15.;
      hours = 6.;
      break;
    case 3:
      pay = 9.25;
      nextpay = 10.5;
      hours = 4.;
      break;
    case 4:
      if (day == 1 || day == 7) nextpay = 13.5;
      else nextpay = 6.75;
      pay = 0.;
      hours = 0.;
      break;
    case 5:
      pay = 8.;
      nextpay = 12.;
      hours = 6.;
      break;  
  }
  return pay * min(hrs, hours) + nextpay * max(0., hrs - hours);
}

int main() {
  for (int i = 0; i < 5; i++) {
    string input;
    getline(cin, input);
    vector<int> inp = split(input);
    
    double pay = 0;
    for (int j = 0; j < 5; j += 4) {
      pay += money(inp[j], (inp[j + 3] - inp[j + 2]) / 2., inp[j + 1]);
    }
    cout << "$" << setprecision(2) << fixed << round(pay * 100) / 100. << "\n";
  }
  return 0;
}