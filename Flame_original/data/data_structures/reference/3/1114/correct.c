#include<stdio.h>
#include<string.h>
int main(){
    char s[110];
    int len,i=0,j=-1,k=0;
    gets(s);
    len=strlen(s);
    while(!(j+1)||!k){
        if(!(j+1)&&s[i]<='9'&&s[i]>='1')j=i;
        if(s[i]=='.'||i==len)k=i;
        i++;
    }
    putchar(s[j]);
    i=j;
    if(j<len-1){
        putchar('.');
        while((++j)<len)
            if(s[j]!='.')putchar(s[j]);
    }
    putchar('e');
    k-=i;if(k>0)k--;
    printf("%d",k);
    return 0;
}


