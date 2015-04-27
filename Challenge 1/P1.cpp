#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double solution(double n) {
  return floor(n/2 + (fmod(n,2) == 1)); 
}

int main(){
  
  int n;
  double i;
  cin >> n;
  
  while (n > 0)
  {
    cin >> i;
    cout<< std::setprecision(0) << fixed << solution(i) << endl;
    n--;
  }
}