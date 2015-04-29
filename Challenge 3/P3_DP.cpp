#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "ttmath/ttmath.h"
using namespace std;

typedef ttmath::Int<100> SuperInt; 

static const int arr[] = {2,3,5,7,11,13,17,19,23,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
vector<int> prime (arr, arr + sizeof(arr) / sizeof(arr[0]));

void solution(vector<SuperInt> &n, vector<vector<int> > &repeticiones, int ini, int fi) {
  vector <int> repeticionesPeriodo (prime.size(), 0);
  for (int k = ini; k < fi; ++k){
    if (repeticiones[k][0] == -1){
      for (int i = 0; i < prime.size(); ++i){
	repeticiones[k][i] = 0;
      }
      SuperInt m = n[k];
      int i = 0;
      while (i < prime.size()){
	while (m%prime[i] == 0){
	  m /= prime[i];
	  ++repeticiones[k][i];
	  ++repeticionesPeriodo[i];
	}
	++i;
      }
    } else{
      for (int i = 0; i < prime.size(); ++i){
	repeticionesPeriodo[i] += repeticiones[k][i];
      }
    }
  }
  
  int max_rep = 0;
  for (int i = 0; i < repeticionesPeriodo.size(); ++i) {
    if (repeticionesPeriodo[i] > max_rep){
      max_rep = repeticionesPeriodo[i];
    }
  }
  
  cout << max_rep;
  for (int i = 0; i < repeticionesPeriodo.size(); ++i) {
    if (repeticionesPeriodo[i] == max_rep){
      cout << " " << prime[i];
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
  
  int n, i, j;
  cin >> n;

  vector<vector<int> > r (cont, vector<int> (prime.size(), -1));
  while (n > 0)
  {
    cin >> i >> j;
    solution(a, r, i, j);
    n--;
  }
}