#include<stdio.h>
int main()
{
    char s,a[100];
    int i,j,k,delta;
    for(i=0;scanf("%c",&s)!=EOF;i++){
        a[i]=s;
    }@@ // The loop reads until EOF but does not null-terminate the array, and includes the newline or EOF character in the array, causing an extra character (like null or garbage) to be processed later.
    for(j=0;j<=i;j++){@@ // Loop condition should be j < i, not j <= i, because valid indices are 0 to i-1; accessing a[i] reads uninitialized/garbage memory (e.g., the EOF-triggering character or beyond).
        if(a[j]!='-'){
            printf("%c",a[j]);
        }
        else if(a[j]=='-'){
            if((a[j-1]>='0'&&a[j+1]<='9'&&a[j-1]<a[j+1])||(a[j-1]>='a'&&a[j+1]<='z'&&a[j-1]<a[j+1])||(a[j-1]>='A'&&a[j+1]<='Z'&&a[j-1]<a[j+1])){@@ // Condition checks only upper bounds for the second char and lower bounds for the first, but doesn't ensure both chars are of the same category (e.g., 'a' and '9' could pass parts of the condition incorrectly). Also, it doesn't verify that both characters belong to the same group (digit/digit, lower/lower, upper/upper).
                delta=a[j+1]-a[j-1];
                for(k=1;k<=delta-1;k++){
                printf("%c",a[j-1]+k);
                }
                
                
            }
        }
    }
    return 0;
}