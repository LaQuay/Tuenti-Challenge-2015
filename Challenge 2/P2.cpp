#include <iostream>
#include <cmath>
using namespace std;

bool almost_prime(int n) {
    int cont = 0;
    for (int i = 2; i <= sqrt(n) && cont < 2; ++i) {
      while (n%i == 0){
	++cont;
	n /= i;
      }
    }
    return (cont == 2 && n == 1) || (cont == 1 && n != 1);
}

int solution(int ini, int fi) {
  int cont = 0;
  
  for (int i = ini; i <= fi; ++i){
    if (almost_prime(i)) ++cont;
  }
  
  return cont;
}

int main(){
  int n, i, j;
  cin >> n;
  
  while (n > 0)
  {
    cin >> i >> j;
    cout << solution(i, j) << endl;
    n--;
  }
}