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
                s[j]=s[j-1]; @@ [When j is 0, s[j-1] accesses s[-1], which is invalid and causes undefined behavior. Also, overwriting operator with previous operator breaks expression structure.]
            }
            if(s[j]=='/'){
                a[j+1]=a[j]/a[j+1];
                a[j]=0;
                s[j]=s[j-1]; @@ [Same issue as above: accessing s[j-1] when j=0 is invalid, and replacing operator corrupts parsing logic.]
            }
        }
    }
    result=a[0];
    for(j=0;j<i;j++){
        if(s[j]=='+') result+=a[j+1];
        else result-=a[j+1]; @@ [This treats every non-'+' operator as '-', including '*' and '/', which were supposed to be already processed. However, due to incorrect handling in prior loop (setting a[j]=0 and corrupting s[]), subtraction is applied incorrectly leading to wrong sign.]
    }
    printf("%d",result);
    return 0;
}