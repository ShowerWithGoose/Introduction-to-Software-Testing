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
                s[j]=s[j-1]; // @@ The logic for handling operator precedence and associativity is flawed. When processing left-to-right for * and /, modifying s[j] to s[j-1] (the previous operator) incorrectly propagates the previous operator's type or creates invalid state for subsequent checks. More critically, this approach fails to correctly chain divisions and multiplications because it doesn't properly update the "current" value holder or skip processed operators in a way that respects left-associativity for mixed * and / sequences. Specifically, setting s[j] = s[j-1] overwrites the current operator with the previous one, which disrupts the logic for the next iteration if the previous operator was also * or /. For example, in A / B / C, after processing A/B, s[0] becomes the operator before A (undefined or garbage if j=0, or previous op). This leads to incorrect evaluation order or operator usage.
            }
            if(s[j]=='/'){
                a[j+1]=a[j]/a[j+1];
                a[j]=0;
                s[j]=s[j-1]; // @@ Same error as above. Overwriting the current operator with the previous one breaks the sequential processing logic for left-associative operators.
            }
        }
    }
    result=a[0];
    for(j=0;j<i;j++){
        if(s[j]=='+') result+=a[j+1];
        else result-=a[j+1]; // @@ This line incorrectly subtracts a[j+1] for any operator that is not '+'. This includes '-', which is correct, but it also includes '*' and '/' if they were not properly handled/neutralized in the previous loop. Even if * and / are handled, the logic assumes that any non-'+' operator in the final pass is a subtraction. However, the previous loop attempts to neutralize * and / by setting a[j]=0 and changing s[j]. If s[j] is changed to s[j-1], and s[j-1] was '-', this might work by accident for some cases, but if s[j-1] was '+' or another '*', it fails. More importantly, if the previous loop didn't correctly mark the operator as "processed" or convert it to a neutral state that is skipped or treated correctly, this line will execute subtraction for operators that should have been ignored or handled differently. The fundamental issue is that the first loop's modification of s[j] does not reliably ensure that only '+' and '-' remain as active operators for the second loop, or that the indices align correctly.
    }
    printf("%d",result);
    return 0;
}