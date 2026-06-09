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
                s[j]=s[j-1]; @@ [Same issue: when j is 0, s[j-1] is invalid. Also, overwriting s[j] with a previous operator breaks the sequence needed for correct left-to-right evaluation of + and - in the final pass.]
            }
        }
    }
    result=a[0];
    for(j=0;j<i;j++){
        if(s[j]=='+') result+=a[j+1];
        else result-=a[j+1]; @@ [This assumes every operator that isn't '+' is '-', but after the multiplication/division pass, s[j] may have been overwritten with an invalid or incorrect operator (e.g., from s[j-1]), leading to wrong sign application. Also, if original expression starts with subtraction, initial setup doesn't handle unary minus, though problem states expression is valid and likely starts with number. Main issue is corrupted s[] array from earlier.]
    }
    printf("%d",result);
    return 0;
}