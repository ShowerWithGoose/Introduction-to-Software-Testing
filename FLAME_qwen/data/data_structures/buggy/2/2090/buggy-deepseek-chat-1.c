#include<stdio.h>
int main(){
    int a[100];
    char s[100];
    int i=0,j,result;
    scanf("%d %c",&a[i],&s[i]);
    while(s[i]!='='){
        i++; 
        scanf("%d %c",&a[i],&s[i]);
    }
    for(j=0;j<i;j++){
        if(s[j]=='*'||s[j]=='/'){
            if(s[j]=='*'){
                a[j+1]=a[j]*a[j+1];
                a[j]=0;
                s[j]=s[j-1]; // @@ Error: When j is 0, s[j-1] accesses s[-1], which is out of bounds. Also, this logic incorrectly overwrites the operator, breaking the later addition/subtraction loop.
            }
            if(s[j]=='/'){
                a[j+1]=a[j]/a[j+1];
                a[j]=0;
                s[j]=s[j-1]; // @@ Error: Same out-of-bounds issue when j is 0. The logic for handling multiplication and division is fundamentally flawed; it does not correctly process the expression with multiple operators of the same precedence.
            }
        }
    }
    result=a[0];
    for(j=0;j<i;j++){
        if(s[j]=='+') result+=a[j+1];
        else result-=a[j+1]; // @@ Error: This assumes all remaining operators are '+' or '-', but the previous loop may have corrupted s[j] values, leading to incorrect results.
    }
    printf("%d",result);
    return 0;
}