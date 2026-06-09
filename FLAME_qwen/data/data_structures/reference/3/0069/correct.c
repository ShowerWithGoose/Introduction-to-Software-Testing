#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char l[100]={0},r[100]={0},chrin;
    int llen=0,rlen=0;
    while (chrin=getchar())
    {
        if(chrin=='.'){
            break;
        }
        l[llen]=chrin;
        llen++;
    }
    gets(r);
    rlen=strlen(r);
    if (l[0]-'0')
    {
        printf("%c.%s%se%d",l[0],l+1,r,llen-1);
    }
    else{
        int i=1;
        for (i = 1; r[i-1]=='0'; i++)
        {}
        if(rlen-i)
        printf("%c.%se-%d",r[i-1],r+i,i);
        else
        printf("%ce-%d",r[i-1],i);
    }
}


