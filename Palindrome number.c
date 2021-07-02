bool isPalindrome(int x){
    long y=0;
    int t=x;
    if(t<0)
        return false;
    while(x!=0)
    {
        y=y*10+(x%10);
        x/=10;
    }
    if (t==y)
        return true;
    else
        return false;
}
