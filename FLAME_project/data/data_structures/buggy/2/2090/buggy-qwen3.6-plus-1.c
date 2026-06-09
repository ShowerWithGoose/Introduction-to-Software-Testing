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
                s[j]=s[j-1]; // @@ [Logical Error: When handling consecutive * or / operators, replacing the current operator with the previous one (s[j-1]) is incorrect. If the previous operator was + or -, this incorrectly preserves it in the position of the processed * or /, leading to incorrect subsequent evaluations. The operator should effectively be "consumed" or marked as handled, not replaced by its left neighbor.]
            }
            if(s[j]=='/'){
                a[j+1]=a[j]/a[j+1];
                a[j]=0;
                s[j]=s[j-1]; // @@ [Logical Error: Same as above. Replacing '/' with the previous operator causes logical errors in the evaluation order and operator tracking for subsequent steps.]
            }
        }
    }
    result=a[0];
    for(j=0;j<i;j++){
        if(s[j]=='+') result+=a[j+1];
        else result-=a[j+1]; // @@ [Logical Error: This 'else' clause catches all non-'+' operators, including '-', but also potentially '*' or '/' if they weren't properly handled/neutralized in the previous loop, or '='. More critically, if the previous loop failed to correctly neutralize * and / operators (which it does due to the s[j]=s[j-1] bug), this line might attempt to subtract values associated with multiplication/division terms that have already been collapsed into a[j+1], or it treats unprocessed operators as subtraction. However, the primary issue leading to the wrong answer here is likely that the previous loop's logic is flawed, leaving some operators in a state where they fall into this else block incorrectly, or the accumulation logic assumes all remaining operators are additive/subtractive. Given the input `24 / 4 / 3 / 2 * 2 * 3 * 4 =`, the division chain results in 1. Then `1 * 2 * 3 * 4` should be 24. The buggy code likely mishandles the transition or the final summation. Specifically, if `s[j]` is not '+', it subtracts. If `s[j]` was originally '*' or '/' and got changed to something else or remained, it might subtract instead of ignore or add. But the most direct error in this specific line relative to standard precedence parsing is that it assumes any non-plus operator is minus, which is unsafe if * and / are not fully resolved/removed from consideration.]
    }
    printf("%d",result);
    return 0;
}