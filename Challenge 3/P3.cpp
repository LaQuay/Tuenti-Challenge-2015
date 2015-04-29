#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "ttmath/ttmath.h"
using namespace std;

typedef ttmath::Int<100> SuperInt; 

static const int arr[] = {2,3,5,7,11,13,17,19,23,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
vector<int> prime (arr, arr + sizeof(arr) / sizeof(arr[0]));

//a[X][Y]
//En Y = 0 el factor
//En Y = 1 el contador
void solution(vector<SuperInt> n, int ini, int fi) {
  vector<int> repeticiones (prime.size(), 0);
  
  for (int k = ini; k < fi; ++k){
    SuperInt m = n[k];
    int i = 0;
    while (i < prime.size()){
      while (m%prime[i] == 0){
	m /= prime[i];
	++repeticiones[i];
      }
      ++i;
    }
  }
  
  int max_rep = -1;
  for (int j = 0; j < repeticiones.size(); ++j){
    if (repeticiones[j] > max_rep){
      max_rep = repeticiones[j];
    }
  }
  
  cout << max_rep << " ";
  for (int j = 0; j < repeticiones.size(); ++j){
    if (repeticiones[j] == max_rep){
      cout << prime[j] << " ";
    }
  }
  cout << endl;
}

int main(){
  vector<SuperInt> a(300000);
  string sLine = "";
  ifstream infile;
  infile.open("numbers.txt");
  int cont = 0;
  while (!infile.eof())
  {
    getline(infile, sLine);
    a[cont] = sLine;
    ++cont;
  }
  infile.close();
  cout << "Read file completed!" << endl;
  
  int n, i, j;
  cin >> n;
  while (n > 0)
  {
    cin >> i >> j;
    solution(a, i, j);
    n--;
  }
}