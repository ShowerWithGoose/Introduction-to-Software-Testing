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
                s[j]=s[j-1]; // @@ [When j is 0, s[j-1] accesses s[-1], which is invalid and leads to undefined behavior. Also, overwriting operator with previous operator breaks expression structure.]
            }
            if(s[j]=='/'){
                a[j+1]=a[j]/a[j+1];
                a[j]=0;
                s[j]=s[j-1]; // @@ [Same issue: accessing s[j-1] when j=0 is invalid; also, this approach incorrectly modifies operator sequence, disrupting later addition/subtraction logic.]
            }
        }
    }
    result=a[0];
    for(j=0;j<i;j++){
        if(s[j]=='+') result+=a[j+1];
        else result-=a[j+1]; // @@ [This assumes every non-'+' operator is '-', but after processing '*' and '/', some operators may have been overwritten incorrectly (e.g., to garbage or previous operators), leading to wrong sign interpretation. Also, the initial value a[0] might have been zeroed during multiplication/division pass, causing incorrect accumulation.]
    }
    printf("%d",result);
    return 0;
}