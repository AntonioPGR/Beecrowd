#include <iostream>
#include <vector>

using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){

    int n;
    cin >> n;

    int count_1 = 0, count_0 = 0, last_digit = -1, temp;
    bool is_lying = false;

    for(int i = 0; i < n; i++){
      cin >> temp;
      if(last_digit == 0 && temp == 0){
        is_lying = true;
      }
      if(temp) count_1++;
      if(!temp) count_0++;
      last_digit = temp;
    }

    if(count_1 > (n-1)) is_lying = true;

    if(is_lying) cout << "YES" << endl;
    else cout << "NO" << endl;

  }

  return 0;
}