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
                s[j]=s[j-1]; // @@ This line incorrectly sets the operator to the previous operator, which can break the order of operations when multiple operators are processed sequentially. It should set s[j] to a neutral value like '+' to avoid affecting later addition/subtraction, or better, restructure the logic to handle operator precedence correctly.
            }
            if(s[j]=='/'){
                a[j+1]=a[j]/a[j+1];
                a[j]=0;
                s[j]=s[j-1]; // @@ Same issue as above: setting s[j] to s[j-1] corrupts the operator sequence. For example, in "24 / 4 / 3", after processing the first '/', s[0] becomes undefined (s[-1]) or a previous operator, causing incorrect subsequent operations.
            }
        }
    }
    result=a[0];
    for(j=0;j<i;j++){
        if(s[j]=='+') result+=a[j+1];
        else result-=a[j+1]; // @@ This assumes all remaining operators are either '+' or '-', but due to the previous bug, s[j] may contain incorrect values (like '/' or '*' or garbage), leading to wrong results. Additionally, the logic does not handle the case where s[j] is '=' or other characters.
    }
    printf("%d",result);
    return 0;
}