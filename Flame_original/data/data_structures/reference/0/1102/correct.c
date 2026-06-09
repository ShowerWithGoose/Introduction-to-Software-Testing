#include<stdio.h>

int main(){
    int i,j,k;
    char s[1001],t[1001];
    gets(s);

    for(i=j=0;s[i]!='\0';i++){
        if((s[i]=='-')){
            if((s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z')||(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z')||(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9')){
                for(k=s[i-1]+1;k<s[i+1];k++)t[j++]=k;
                continue;
            }
        }
        t[j++]=s[i];
    }
 puts(t);
}



