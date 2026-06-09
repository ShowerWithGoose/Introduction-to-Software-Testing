#include<stdio.h>
int main()
{
    char s,a[100];
    int i,j,k,delta;
    for(i=0;scanf("%c",&s)!=EOF;i++){ // @@ [Error: Reads until EOF instead of a single line; also includes newline and does not null-terminate. Should use gets() or fgets().]
        a[i]=s;
    }
    for(j=0;j<=i;j++){ // @@ [Error: Loop condition should be j < i to avoid accessing uninitialized a[i] and possible out-of-bounds.]
        if(a[j]!='-'){
            printf("%c",a[j]);
        }
        else if(a[j]=='-'){ // @@ [Error: Missing else clause to print the hyphen when expansion condition fails; hyphen is silently dropped.]
            if((a[j-1]>='0'&&a[j+1]<='9'&&a[j-1]<a[j+1])||(a[j-1]>='a'&&a[j+1]<='z'&&a[j-1]<a[j+1])||(a[j-1]>='A'&&a[j+1]<='Z'&&a[j-1]<a[j+1])){ // @@ [Error: Range checks are incomplete (only one bound per type), allowing invalid combinations like 'a' to 'B'. Also no bounds checking for j-1/j+1, causing out-of-bounds at start/end of string.]
                delta=a[j+1]-a[j-1];
                for(k=1;k<=delta-1;k++){
                printf("%c",a[j-1]+k);
                }
                
                
            }
        }
    }
    return 0;
}