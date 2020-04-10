/*
Palindromic Substrings

Given a string S, count and return the number of substrings of S that are palindrome.
Single length substrings are also palindromes. You just need to calculate the count, not the substrings.

Input Format :
String S

Output Format :
count of palindrome substrings

Constraints :
1 <= Length of S <= 1000

Sample Input :
aba
Sample Output :
4
**Note : Here 4 corresponds to ("a","b","a","aba").
*/
//code snippet

int countPalindromeSubstrings(char s[]) {
	// complexity is O(n*n)
    int i,c=0;;
    int n=0;
    while(s[n]!='\0')
        n++;
    
    int l,r;
    
    for(i=0;i<n;i++){
        
        // odd string
        l=r=i;
        while(l>=0 && r<n && s[l]==s[r]){
            c++;
            l--;
            r++;
        }
        //even string
        l=i;r=i+1;
        while(l>=0 && r<n && s[l]==s[r]){
            c++;
            l--;
            r++;
        }   
    }
    return c;	
}
