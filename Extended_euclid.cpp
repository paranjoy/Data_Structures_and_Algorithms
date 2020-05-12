
#include<bits/stdc++.h>
using namespace std;

class Triplet{
  public:
         int gcd;
         int x;
         int y;
};

Triplet extended_euclid(int a, int b){
  Triplet ans;
  
  if( b == 0){
    ans.gcd = a;
    ans.x = 1;
    ans.y = 0;
    
    return ans;
  }
  
  Triplet smallAns = extended_euclid(b, a%b);
  
  ans.gcd = smallAns.gcd;
  ans.x = smallAns.y;
  ans.y = smallAns.x - (a/b)* smallAns.y;
  
  return ans;
}

int main(){


  int a, b;
  cin >> a >> b;
  
  // linear diophantine equation
  // ax + by = c
  // x and y will have integer sol. only if gcd(a,b) divides c
  
  Triplet ans = extended_euclid(a, b);
  int gcd = ans.gcd;
  int x = ans.x;
  int y = ans.y;
  
  cout << gcd <<" " << x <<" " << y << endl;
  return 0;
  
 }
