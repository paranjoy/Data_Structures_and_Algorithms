/*
String Search

Given two strings S and T, write a function to find if T is present as a substring inside S or not. 
If yes, return the starting index otherwise return -1.

Input format :
Line 1 : String S
Line 2 : String T

Sample Input 1:
WelcomeBack
come 
Sample Output 1:
3

Sample Input 2:
WelcomeBack
code
Sample Output 2:
-1
*/
//code snippet

// S and T - input strings
// You need to check if string T is present in S or not
int getsize(char *s){
    int c=0;
    while(s[c]!='\0'){
        c++;
    }
    return c;
}

int *getlps(char *S){
    int l = getsize(S);
    int *lps = new int[l];
    lps[0] = 0;
    int j =0;
    int i = 1;
    while(i<l){
        if(S[i]==S[j]){
            lps[i]= j+1;
            i++;j++;
        }
        else{
            if(j!=0)
                j=lps[j-1];
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;  
}

int findString(char S[], char T[]) {
    // Write your code here
    
    int m = getsize(S);
    int n = getsize(T);
    int *lps = getlps(S);
    int i=0,j=0;
    while(i<m){
        if(S[i]==T[j]){
            i++;
            j++;
        }
        else if(j==n){
            return (i-j);
        }
        else if(i<m && S[i]!=T[j]){
            
            if(j!=0){
                j=lps[j-1];
            }
            else
                i++;
        }
    }
    return -1;
}
