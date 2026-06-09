#include<stdio.h>
int main()
{
    char s,a[100];
    int i,j,k,delta;
    for(i=0;scanf("%c",&s)!=EOF;i++){
        a[i]=s;
    }
    for(j=0;j<=i;j++){ @@ // Error: should be j < i to avoid accessing uninitialized a[i]
        if(a[j]!='-'){
            printf("%c",a[j]);
        }
        else if(a[j]=='-'){
            if((a[j-1]>='0'&&a[j+1]<='9'&&a[j-1]<a[j+1])||(a[j-1]>='a'&&a[j+1]<='z'&&a[j-1]<a[j+1])||(a[j-1]>='A'&&a[j+1]<='Z'&&a[j-1]<a[j+1])){ @@ // Error: need to check both characters are in same range (e.g., a[j-1]>='0' && a[j-1]<='9' && a[j+1]>='0' && a[j+1]<='9'); also missing else to print '-' when condition fails
                delta=a[j+1]-a[j-1];
                for(k=1;k<=delta-1;k++){
                printf("%c",a[j-1]+k);
                }
                
                
            } @@ // Error: missing else clause to print the '-' when expansion condition is not satisfied
        }
    }
    return 0;
}