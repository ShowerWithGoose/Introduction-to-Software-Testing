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
                s[j]=s[j-1]; @@ [When j is 0, s[j-1] accesses s[-1], which is out-of-bounds and undefined behavior. This corrupts the operator array and leads to incorrect evaluation of addition/subtraction later.]
            }
            if(s[j]=='/'){
                a[j+1]=a[j]/a[j+1];
                a[j]=0;
                s[j]=s[j-1]; @@ [Same issue: when j is 0, s[j-1] is invalid. Also, overwriting s[j] with a previous operator breaks the sequential logic needed for correct left-to-right evaluation.]
            }
        }
    }
    result=a[0];
    for(j=0;j<i;j++){
        if(s[j]=='+') result+=a[j+1];
        else result-=a[j+1]; @@ [This assumes every operator that isn't '+' is '-', but after the earlier loop, s[j] may have been overwritten with an invalid or wrong operator (e.g., from s[j-1]), leading to incorrect subtraction instead of handling original '+' or '-'. Also, it doesn't account for the fact that some terms were zeroed out but their operators were altered.]
    }
    printf("%d",result);
    return 0;
}