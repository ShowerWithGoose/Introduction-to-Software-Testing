#include<stdio.h>
int main()
{
    char s,a[100];
    int i,j,k,delta;
    for(i=0;scanf("%c",&s)!=EOF;i++){
        a[i]=s;
    } // @@ [The loop reads until EOF but does not null-terminate the array, and includes the newline or EOF character in the array, causing an extra character (like null or garbage) to be processed later. Also, 'i' ends up being one more than the last valid index.]
    for(j=0;j<=i;j++){ // @@ [Loop condition should be j < i, not j <= i, because 'i' is the count of characters read (including possibly a newline or EOF-induced extra), and accessing a[i] may go out of intended bounds or process an uninitialized/extra character.]
        if(a[j]!='-'){
            printf("%c",a[j]);
        }
        else if(a[j]=='-'){
            if((a[j-1]>='0'&&a[j+1]<='9'&&a[j-1]<a[j+1])||(a[j-1]>='a'&&a[j+1]<='z'&&a[j-1]<a[j+1])||(a[j-1]>='A'&&a[j+1]<='Z'&&a[j-1]<a[j+1])){ // @@ [The condition checks only upper bound of the second character and lower bound of the first, but doesn't ensure both characters are of the same category. For example, 'a' (97) and '9' (57): a[j-1] >= '0' is true, a[j+1] <= '9' is true, but they are not both digits. This leads to incorrect expansion in mixed-type cases. Correct logic requires both characters to be in the same group: e.g., (a[j-1] >= '0' && a[j-1] <= '9' && a[j+1] >= '0' && a[j+1] <= '9') etc.]
                delta=a[j+1]-a[j-1];
                for(k=1;k<=delta-1;k++){
                printf("%c",a[j-1]+k);
                }
                
                
            }
        }
    }
    return 0;
}