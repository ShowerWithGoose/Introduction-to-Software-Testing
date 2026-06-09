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
                s[j]=s[j-1]; // @@ This line incorrectly sets the operator to the previous operator, which can cause incorrect operator precedence handling and disrupt subsequent operations.
            }
            if(s[j]=='/'){
                a[j+1]=a[j]/a[j+1];
                a[j]=0;
                s[j]=s[j-1]; // @@ Same issue as above; setting s[j] to s[j-1] corrupts the operator sequence and leads to wrong results.
            }
        }
    }
    result=a[0];
    for(j=0;j<i;j++){
        if(s[j]=='+') result+=a[j+1];
        else result-=a[j+1]; // @@ This assumes all remaining operators are either '+' or '-', but due to the previous corruption of s[j], some operators may have been incorrectly changed, causing wrong addition/subtraction.
    }
    printf("%d",result);
    return 0;
}