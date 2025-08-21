#include <iostream>
#include <vector>

using namespace std;

int main(){

  int t;
  cin >> t;

  while(t--){
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    int  count_rounds = 0;
    
    while(n > 1 || m > 1){
      count_rounds++;
      
      if(m != 1){
        if((m/2) <= b) m = b;
        else {
          m = b - (m - b);
          b = 1;
        }
      } else {
        if((n/2) <= a) n = a;
        else {
          n = a - (n - a);
          a = 1;
        }
      }

      if(n == 1 && m == 1) break;
      else if(n > 1 && m > 1){
        a = n - 1;
        b = m - 1;
      } else if(n == 1){
        a = 1;
        b = m - 1;
      } else if(m == 1){
        a = n - 1;
        b = 1;
      }
    }

    cout << count_rounds << endl;

  }
}