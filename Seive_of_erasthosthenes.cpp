/*
Given a number N, find number of primes in the range [1,N].

Input:
The only line of input consists of a number N
Output:
Print the number of primes in the range [1,N].`

Constraints:
1≤N≤1000000

Sample Input :
3 
Sample Output -
2
*/

//code

#include<bits/stdc++.h>
using namespace std;

void update(int  i, vector<bool>& prime){
    
    for(int  j = i*i; j <= prime.size(); j += i)
        prime[j] = false;
}

int main(){
    
    int n; 
    cin >> n;
    
    if(n == 2)
        cout<< "1";
    else if(n == 1)
        cout << "0";
    
    else{
        int count = 0;
        vector<bool> prime(n, true);
        prime[0] = false;
        prime[1] = false;
        for(int i = 2; i*i <= n; i++)
            if(prime[i])
                update(i, prime);
        for(int  i = 2; i <= n; i++)
            if(prime[i])
                count++;
        
        cout<<count;
    }
    
	return 0;
}
