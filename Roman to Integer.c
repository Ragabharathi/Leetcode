int romanToInt(char * s){
    int sum=0;
    int i=0;
    for(i=0;i<strlen(s);)
    {
        if(s[i]=='I' && s[i+1]=='V')
        {
            sum=sum+4;
            i+=2;
        }
        else if(s[i]=='I' && s[i+1]=='X')
        {
            sum=sum+9;
            i+=2;
        }    
        else if(s[i]=='X' && s[i+1]=='L')
        {
            sum=sum+40;
            i+=2;
        }    
        else if(s[i]=='X' && s[i+1]=='C')
        {
            sum=sum+90;
            i+=2;
        }    
        else if(s[i]=='C' && s[i+1]=='D')
        {
            sum=sum+400;
            i+=2;
        }    
        else if(s[i]=='C' && s[i+1]=='M')
        {
            sum=sum+900;
            i+=2;
        }  
        else if(s[i]=='I')
        {
            sum=sum+1;
            i++;
        }
         else if(s[i]=='V')
        {
            sum=sum+5;
            i++;
        } else if(s[i]=='X')
        {
            sum=sum+10;
            i++;
        } else if(s[i]=='L')
        {
            sum=sum+50;
            i++;
        } else if(s[i]=='C')
        {
            sum=sum+100;
            i++;
        } else if(s[i]=='D')
        {
            sum=sum+500;
            i++;
        } else if(s[i]=='M')
        {
            sum=sum+1000;
            i++;
        }
                

     }
    return sum;

}
