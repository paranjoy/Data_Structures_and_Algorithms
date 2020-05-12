

int gcd(int a,int b)
{
    int x = min(a,b);
    int y = max(a,b);
    
    if(y % x == 0)
        return x;
    else
        return gcd(x, y%x);
}

