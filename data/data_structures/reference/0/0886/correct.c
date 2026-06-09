//
//  main.c
//  expand
//
//  Created by  on 2022/3/3.
//

#include <stdio.h>
#include <string.h>
int main() {
    char s[2001], a[5001];
    int i, j=0, k, cn, len;
    gets(s);
    len = strlen(s);
    for(i=0;i<len-1;i++){
        if(s[i]!='-')
            a[j++]=s[i];
        else if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9'&&s[i+1]>s[i-1]){
                for(k=1;k<s[i+1]-s[i-1];k++)
                    a[j++]=s[i-1]+k;
            }
        else if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z'&&s[i+1]>s[i-1]){
                for(k=1;k<s[i+1]-s[i-1];k++)
                    a[j++]=s[i-1]+k;
            }
        else if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z'&&s[i+1]>s[i-1]){
                for(k=1;k<s[i+1]-s[i-1];k++)
                    a[j++]=s[i-1]+k;
            }
        else
                a[j++]=s[i];
    }
    a[j]=s[len-1];
    for(cn=0;cn<=j;cn++)
        printf("%c", a[cn]);
    printf("\n");
    return 0;
}

