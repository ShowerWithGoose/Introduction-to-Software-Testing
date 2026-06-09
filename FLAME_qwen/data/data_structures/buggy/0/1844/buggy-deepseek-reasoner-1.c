#include<stdio.h>
int main()
{
    char s,a[100];
    int i,j,k,delta;
    for(i=0;scanf("%c",&s)!=EOF;i++){ // @@ [Input reading method is problematic: reads until EOF, may hang on keyboard input; should use gets() or fgets().]
        a[i]=s;
    }
    for(j=0;j<=i;j++){ // @@ [Loop condition should be j<i, since a[i] is out of bounds; i is the number of characters read (indices 0 to i-1).]
        if(a[j]!='-'){
            printf("%c",a[j]);
        }
        else if(a[j]=='-'){ // @@ [Missing else clause: when the inner expansion condition fails, the '-' should be printed; currently it is not printed.]
            if((a[j-1]>='0'&&a[j+1]<='9'&&a[j-1]<a[j+1])||(a[j-1]>='a'&&a[j+1]<='z'&&a[j-1]<a[j+1])||(a[j-1]>='A'&&a[j+1]<='Z'&&a[j-1]<a[j+1])){ // @@ [Potential out-of-bounds access: need to ensure j>0 and j < i-1 (i.e., a[j+1] exists) before accessing a[j-1] and a[j+1].]
                delta=a[j+1]-a[j-1];
                for(k=1;k<=delta-1;k++){
                printf("%c",a[j-1]+k);
                }
                
                
            }
        }
    }
    return 0;
}