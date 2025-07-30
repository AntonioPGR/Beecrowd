#include <iostream>

using namespace std;

int main(){

  int n;
  cin >> n;
  while(n--){

    int l;
    cin >> l;
    cin.clear();
    cin.ignore();

    int hash = 0;
    for(int i = 0; i < l; i++){
      string line;
      getline(cin, line);

      for(int j = 0; j < line.size(); j++){
        int cur = line[j] - 'A';
        hash += i + j + cur;
      }
    }
    cout << hash << endl;
  }

  return 0;
}