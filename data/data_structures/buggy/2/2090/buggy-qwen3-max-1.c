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
                s[j]=s[j-1]; @@ [Accessing s[j-1] when j=0 leads to undefined behavior (out-of-bounds array access). Also, overwriting operator with previous one breaks expression structure.]
            }
            if(s[j]=='/'){
                a[j+1]=a[j]/a[j+1];
                a[j]=0;
                s[j]=s[j-1]; @@ [Same issue: accessing s[-1] when j=0 is invalid. Additionally, this approach fails to correctly handle operator precedence across the entire expression.]
            }
        }
    }
    result=a[0];
    for(j=0;j<i;j++){
        if(s[j]=='+') result+=a[j+1];
        else result-=a[j+1]; @@ [This assumes all non-'+' operators are '-', but after processing '*' and '/', s[j] might still be '=' or other values; also, it doesn't account for modified operators from earlier flawed logic.]
    }
    printf("%d",result);
    return 0;
}