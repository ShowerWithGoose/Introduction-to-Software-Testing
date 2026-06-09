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
                s[j]=s[j-1]; @@ [When j is 0, s[j-1] accesses s[-1], which is out-of-bounds and undefined behavior. This corrupts the operator array and breaks precedence handling.]
            }
            if(s[j]=='/'){
                a[j+1]=a[j]/a[j+1];
                a[j]=0;
                s[j]=s[j-1]; @@ [Same issue: when j is 0, s[j-1] is invalid. Also, using two separate 'if' statements instead of 'else if' causes both blocks to potentially execute if s[j] changes, but more critically, the logic fails to correctly propagate operators after collapsing terms.]
            }
        }
    }
    result=a[0];
    for(j=0;j<i;j++){
        if(s[j]=='+') result+=a[j+1];
        else result-=a[j+1]; @@ [This assumes every operator that isn't '+' is '-', but after the previous loop, s[j] may contain '=' or corrupted values (e.g., from s[-1]), leading to incorrect subtraction or undefined behavior. Also, the final operator before '=' is stored in s[i-1], but the loop runs up to j < i, which includes processing the '=' as an operator if not handled properly.]
    }
    printf("%d",result);
    return 0;
}