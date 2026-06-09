#include<stdio.h>
#include<string.h>
#include<ctype.h>
char in[10000];
int num[10000];
int op[10000],post[1000];
void delete(int a[],int *n,int i) //传的是第几个 不是下标 
{
    for(int j=i;j<*n;j++) a[j-1]=a[j];
    (*n)--;
}
int calc(int a,int op,int b)  //-1= +  -2= -  -3= *  -4= /
{
    if(op==-1)return a+b;
    if(op==-2)return a-b;
    if(op==-3)return a*b;
    if(op==-4)return a/b;
}
int main()
{
    int i=0,j=0;    
    gets(in);
    for(int i=0;i<strlen(in);i++) //去空格 
    {
        if(in[i]!=' ')
        {
            in[j++]=in[i];    
        }
    }
    if(in[j-1]!='=')in[j++]='=';
    in[j]='\0';

    i=0,j=0; 
    int cnt=0;
    int cnum=0,pt=0;
    for(;in[pt]!='\0';pt++)  //数字和运算符分别存到num op 
    {
        if(isdigit(in[pt]))
        {
            cnum=10*cnum+in[pt]-'0';
        }
        else
        {
            num[i++]=cnum;
            cnum=0;
            cnt++;
            if(in[pt]=='+') op[j++]=-1;
            if(in[pt]=='-') op[j++]=-2;
            if(in[pt]=='*') op[j++]=-3;
            if(in[pt]=='/') op[j++]=-4;
        }
    }
    int opcnt=cnt-1;
    for(i=0;i<opcnt;)
    {
        if(op[i]==-4)
        {
            num[i]=calc(num[i],-4,num[i+1]);
            delete(num,&cnt,i+2); // @@ The index passed to delete is incorrect. It should be i+1 (1-based index of the second operand) to remove num[i+1], but passing i+2 removes the wrong element or causes out-of-bounds access depending on implementation logic. More critically, the delete function shifts elements left starting from index i-1 (because it uses j-1). To remove the element at 1-based index K, we pass K. The element to remove from num is at 1-based index i+2 (since num[i] is 1-based i+1, num[i+1] is 1-based i+2). However, the standard way to handle this in such arrays is usually simpler. Let's look closer. delete(a, n, i) removes the element at 1-based index i. So to remove num[i+1] (which is at 1-based index i+2), we call delete(num, &cnt, i+2). This part seems logically consistent with the comment "传的是第几个". BUT, the loop condition and index update are flawed. After deletion, the current operator at op[i] is removed, and the next operator shifts to op[i]. The code does NOT decrement i, so it re-checks the new op[i]. This is correct for consecutive operators. HOWEVER, there is a major logic error in how `cnt` and `opcnt` are managed versus the indices `i`. The `delete` function modifies the array size. The critical error is that the code processes division and multiplication in separate passes, but fails to reset the index `i` or handle the shifting correctly relative to the loop bound `opcnt` which is updated. Actually, the biggest issue is likely in the `delete` function usage or the initial parsing. Let's re-read the specific failure. Input: `24 / 4 / 3 / 2 ...`. 
            // The real error is often simpler. Look at the parsing loop. `cnt` counts operators? No, `cnt` is incremented for every non-digit char. So `cnt` is number of operators. `i` counts numbers. `j` counts operators stored in `op`.
            // `opcnt = cnt - 1`. If expression is `A+B`, cnt=1, opcnt=0. Loop `i<0` doesn't run. Correct.
            // If `A/B/C`, cnt=2, opcnt=1.
            // Pass 1 (Div): i=0. op[0] is /. num[0] = 24/4=6. delete num at 1-based idx 2 (num[1]=4). delete op at 1-based idx 1 (op[0]=/).
            // Now num has [6, 3, 2...], op has [-4, ...]. cnt becomes cnt-1. opcnt becomes opcnt-1.
            // The loop continues with i=0. op[0] is now the NEXT division.
            // This logic seems okay for left-associativity.
            
            // Let's look at the `delete` function again.
            // `for(int j=i;j<*n;j++) a[j-1]=a[j];`
            // If we want to remove element at 1-based index `i`, its 0-based index is `i-1`.
            // We shift `a[i]` to `a[i-1]`, `a[i+1]` to `a[i]`, etc.
            // This effectively removes `a[i-1]`.
            
            // In the call `delete(num,&cnt,i+2)`:
            // We want to remove `num[i+1]`. The 0-based index is `i+1`. The 1-based index is `i+2`.
            // So passing `i+2` tells delete to remove the element at 1-based `i+2`, which is 0-based `i+1`. This is correct.
            
            // In the call `delete(op,&opcnt,i+1)`:
            // We want to remove `op[i]`. The 0-based index is `i`. The 1-based index is `i+1`.
            // So passing `i+1` tells delete to remove the element at 1-based `i+1`, which is 0-based `i`. This is correct.
            
            // So where is the bug?
            // Check the parsing.
            // `if(in[pt]=='+') op[j++]=-1;` ...
            // `cnt++` happens for EVERY operator including `=`.
            // The loop stops when `in[pt]=='\0'`.
            // The last character processed is `=`.
            // When `in[pt]` is `=`, it is not a digit.
            // `num[i++] = cnum`. Stores the last number.
            // `cnt++`. Increments count for `=`.
            // `if (in[pt]=='=')` is NOT handled in the if/else chain for op codes. So `op` does NOT store an entry for `=`.
            // But `cnt` includes `=`.
            // So `cnt` = number of actual operators (+,-,*,/) + 1 (for =).
            // `opcnt = cnt - 1`. This equals the number of actual operators.
            // `j` (number of items in `op`) equals the number of actual operators.
            // This seems consistent.
            
            // Let's look at the test case: `24 / 4 / 3 / 2 + 100 - 50 - 40 + 10*20*30*40 / 40 / 30 =`
            // Expected: 211. Got: 11.
            
            // Is it possible `gets` is deprecated/unsafe? No, that's not a logic error for WA.
            
            // Let's look at `delete` again.
            // `void delete(int a[],int *n,int i)`
            // `for(int j=i;j<*n;j++) a[j-1]=a[j];`
            // If `i` is 1 (1-based first element), `j` starts at 1. `a[0]=a[1]`. Correct.
            
            // Wait, look at the multiplication/division loops.
            // They only process `-4` (/) then `-3` (*).
            // The problem requires standard precedence. * and / have same precedence and are left-associative.
            // Processing all `/` first, then all `*` is INCORRECT if they are mixed.
            // Example: `10 * 2 / 5`.
            // Correct: `(10 * 2) / 5 = 20 / 5 = 4`.
            // Code's Div pass: skips `*`.
            // Code's Mul pass: processes `*`. `10 * 2 = 20`. Array becomes `20 / 5`.
            // Then no more mul.
            // Result 20 / 5 is never calculated because div pass already finished!
            
            // YES. The code separates division and multiplication into two separate sequential passes.
            // Pass 1 handles only `/`. Pass 2 handles only `*`.
            // If you have `A * B / C`, Pass 1 sees `*` (skips). Pass 2 sees `*`, calculates `A*B`. Result `Res / C`.
            // But `Res / C` is a division. Pass 1 is already done. It will not be calculated.
            // Similarly, `A / B * C`. Pass 1 calculates `A/B`. Result `Res * C`. Pass 2 calculates `Res * C`. This works.
            // But `A * B / C` fails.
            
            // To fix this, * and / must be handled in the same pass, or repeatedly until none remain.
            
            delete(op,&opcnt,i+1);
        }
        else i++;
    }

    for(i=0;i<opcnt;)
    {
        if(op[i]==-3)
        {
            num[i]=calc(num[i],-3,num[i+1]);
            delete(num,&cnt,i+2);
            delete(op,&opcnt,i+1);
        }
        else i++;
    }

    for(i=0;i<opcnt;)
    {
        if(op[i]==-2)
        {
            num[i]=calc(num[i],-2,num[i+1]);
            delete(num,&cnt,i+2);
            delete(op,&opcnt,i+1);
        }
        else i++;
    }
    for(i=0;i<opcnt;)
    {
        if(op[i]==-1)
        {
            num[i]=calc(num[i],-1,num[i+1]);
            delete(num,&cnt,i+2);
            delete(op,&opcnt,i+1);
        }
        else i++;
    }
    printf("%d\n",num[0]);
        
    return 0;
}