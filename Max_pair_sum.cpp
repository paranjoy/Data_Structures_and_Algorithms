/*
You are given a sequence A[1], A[2], ..., A[N], ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). 
There are two types of operations and they are defined as follows:

Update:
This will be indicated in the input by a 'U' followed by space and then two integers i and x.
U i x, 1 ≤ i ≤ N, and x, 0 ≤ x ≤ 10^8.
This operation sets the value of A[i] to x.

Query:
This will be indicated in the input by a 'Q' followed by a single space and then two integers i and j.
Q x y, 1 ≤ x < y ≤ N.
You must find i and j such that x ≤ i, j ≤ y and i != j, such that the sum A[i]+A[j] is maximized. Print the sum A[i]+A[j].

Input
The first line of input consists of an integer N representing the length of the sequence. 
Next line consists of N space separated integers A[i]. Next line contains an integer Q, Q ≤ 10^5,
representing the number of operations. Next Q lines contain the operations.

Output
 Output the maximum sum mentioned above, in a separate line, for each Query.

Input:
5
1 2 3 4 5
6
Q 2 4
Q 2 5
U 1 6
Q 1 5
U 1 7
Q 1 5
Output:
7
9
11
12
*/

#include<bits/stdc++.h>
using namespace std;
pair<int,int> query(vector<pair<int,int>>&t, int start, int end, int i, int l, int r){
    
    if(l <= start && r >= end){
        return t[i];
    }
    if(l > end || r < start)
        return pair<int,int>(INT_MIN,INT_MIN);
    
    int mid = (start+end)/2;
    
    pair<int,int> p1 = query(t,start,mid,2*i,l,r);
    pair<int,int> p2 = query(t,mid+1,end,2*i+1,l,r);
	int l1 = max(p1.first,p2.first);
    int l2 = min(max(p1.first,p2.second), max(p2.first,p1.second));
    return pair<int,int>(l1, l2);
}
void update(vector<pair<int,int>>&t, int start, int end, int i, int idx, int val){
    
    if(start == end){
        t[i] = pair<int,int>(val, INT_MIN);
        return;
    }
    int mid = (start + end)/2;
    
    if(idx > mid){
        update(t,mid+1,end,2*i+1,idx,val);
    }
    else{
        update(t,start,mid,2*i,idx,val);
    }
    int a = t[2*i].first;
    int b = t[2*i].second;
    int c = t[2*i+1].first;
    int d = t[2*i + 1].second;
    int l1 = max(a,c);
    int l2 = min(max(a,d), max(c,b));
    t[i] = pair<int,int>(l1, l2);
}
void build(vector<int>&v, vector<pair<int,int>>& t, int start, int end, int i){
    
    if(start == end){
        t[i] = pair<int,int>(v[start], INT_MIN);
    	return;
    }
    
    int mid = (start + end)/2;
    build(v,t,start,mid,2*i);
    build(v,t,mid+1,end,2*i+1);
    
    int a = t[2*i].first;
    int b = t[2*i].second;
    int c = t[2*i+1].first;
    int d = t[2*i + 1].second;
    int l1 = max(a,c);
    int l2 = min(max(a,d), max(c,b));
    t[i] = pair<int,int>(l1, l2);
}

int main() {

    int n;
    cin>>n;
    vector<int>v(n,0);
    
    for(int  i = 0; i < n; i++)
        cin>>v[i];
    
    vector<pair<int,int>> t (4*n, pair<int,int>(INT_MIN,INT_MIN));
    
    build(v,t,0,n-1,1);
    int q;
    cin>>q;
    while(q--){
        char ch;
        int a, b;
        cin>>ch>>a>>b;
        if(ch =='Q'){
            pair<int,int> p = query(t,0,n-1,1,a-1,b-1);
            
            cout<<(p.first+p.second)<<endl;   
        }
        else
            update(t,0,n-1,1,a-1,b);
    }
    return 0;
}
