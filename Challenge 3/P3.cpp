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
//En X el factor
//En Y el contador
void solution(vector<SuperInt> n, int ini, int fi) {
  vector<vector<int> > a;
  
  for (int k = ini; k < fi; ++k){
    int i = 0;
    while (i < prime.size()){
      while (n[k]%prime[i] == 0){
	cout << "Number: " << prime[i] << endl;
	cout << "Before N: " << n[k] << endl;
	n[k] /= prime[i];
	cout << "After N: " << n[k] << endl;
	
	bool found = false;
	int j = 0;
	for (j = 0; j < a.size(); ++j){
	  cout << "Buscandolo... " << j << endl;
	  if (a[j][0] == prime[i]) {
	    cout << "Encontrado...!" << endl;
	    a[j][1] = a[j][1] + 1;
	    found = true;
	  }
	}
	if (!found) {
	cout << "NOT FOUND" << endl;
	  vector<int> row;
	  row.push_back(prime[i]);
	  row.push_back(1);
	  a.push_back(row);
	}
      }
      ++i;
    }
  }
  cout << "Solucion" << endl;
  for (int j = 0; j < a.size(); ++j){
    for (int k = 0; k < a[j].size(); ++k){
      cout << a[j][k] << " ";
    }
    cout << endl;
  }
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