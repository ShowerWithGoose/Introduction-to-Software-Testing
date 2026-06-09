#include <stdio.h>
#include <string.h>
#include <ctype.h>
int check(char s[],int i);
int main(){
    char s1[255]="",s2[255]="";
    int i,j;
    i=j=0;
    gets(s1);
    for (;s1[i]!='\0'; i++)
    {
        if (s1[i]!='-')
        {
            s2[j++]=s1[i];
        }else if(check(s1,i)){
            int num=s1[i+1]-s1[i-1];
            for ( int q = 1; q < num; q++)
            {
                s2[j++]=s1[i-1]+q;
            }
        }else{
            s2[j++]=s1[i];
        }
    }
    puts(s2);
    return 0;
}
int check(char s[],int i){
    if ((isdigit(s[i-1])&&isdigit(s[i+1]))||(islower(s[i-1])&&islower(s[i+1]))||(isupper(s[i-1])&&isupper(s[i+1])))
    {
        return 1;
    }else{
        return 0;
    }
    
}


