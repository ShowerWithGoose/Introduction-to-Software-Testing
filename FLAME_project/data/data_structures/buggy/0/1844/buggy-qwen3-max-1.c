#include<stdio.h>
int main()
{
    char s,a[100];
    int i,j,k,delta;
    for(i=0;scanf("%c",&s)!=EOF;i++){
        a[i]=s;
    } // @@ [The loop reads until EOF but does not null-terminate the array, and includes the newline or EOF character in the array, causing out-of-bound access later. Also, 'i' ends up being one past the last valid character index.]
    for(j=0;j<=i;j++){ // @@ [Loop condition should be j < i, not j <= i, because valid indices are 0 to i-1. Accessing a[i] reads uninitialized/garbage data (like the EOF-triggering character or beyond), leading to extra output like the null byte at the end.]
        if(a[j]!='-'){
            printf("%c",a[j]);
        }
        else if(a[j]=='-'){
            if((a[j-1]>='0'&&a[j+1]<='9'&&a[j-1]<a[j+1])||(a[j-1]>='a'&&a[j+1]<='z'&&a[j-1]<a[j+1])||(a[j-1]>='A'&&a[j+1]<='Z'&&a[j-1]<a[j+1])){ // @@ [Condition checks only upper bound of second char and lower bound of first char per type, but doesn't ensure both chars are of the same category. For example, 'a' (lowercase) and 'F' (uppercase) could pass if mistakenly compared, but more critically, it allows mixed-type cases like '9' and 'a' to partially satisfy conditions. However, the main issue here is that it doesn't verify that BOTH characters belong to the same group (e.g., both digits, both lowercase, etc.). Correct check should be: (a[j-1]>='0' && a[j-1]<='9' && a[j+1]>='0' && a[j+1]<='9' && ...) similarly for letters.]
                delta=a[j+1]-a[j-1];
                for(k=1;k<=delta-1;k++){
                printf("%c",a[j-1]+k);
                }
                
                
            }
        }
    }
    return 0;
}