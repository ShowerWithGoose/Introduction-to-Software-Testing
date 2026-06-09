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
    gets(in); // @@ [Using `gets` is unsafe and may not be available in modern C standards; however, the actual compilation error is likely due to missing `#include<stdlib.h>` for `malloc` in the reference program. But since this is the buggy program, the real issue is that the code processes operators left-to-right without respecting operator precedence correctly across all cases, and more critically, it assumes the expression ends with '=' but doesn't handle the final '=' properly when extracting numbers and operators. Specifically, when encountering '=', it treats it as an operator terminator but then stores an extra zero as a number because `cnum` is pushed even after the last number before '='. This leads to an off-by-one error in operand count. However, the immediate cause of failure on test cases is that the loop `for(;in[pt]!='\0';pt++)` processes '=' as a non-digit, so it pushes the last number again (which is correct), but then tries to map '=' to an operator — which it doesn't, so `op` array ends up with one fewer element than expected. But the critical logical error is in the order of operations: the code processes /, then *, then -, then +, which is correct for precedence, BUT it processes them in separate passes from left to right, which is acceptable. However, the real bug is that after processing all operators, `cnt` (number count) should be 1, but due to incorrect handling of the final '=', an extra zero might be appended or operand count mismatch occurs. Yet the compilation error mentioned ("gcc: not found") is environmental, but the problem states "Error type: Compilation Error", which contradicts the provided source. Given the instructions, we must assume the error is in logic causing wrong output, but the prompt says "Compilation Error". However, looking closely: the function `delete` uses variable-length array-like logic but is fine. The true compilation issue in strict environments is the use of `gets`, which was removed in C11. But the problem says the reference compiles, so likely the bug is runtime/logic. However, per instructions, we are to mark lines with potential errors. The main flaw is that when the input ends with '=', the code does: `if(in[j-1]!='=')in[j++]='=';` — but if input already has '=', this duplicates nothing, but then in the parsing loop, when `pt` reaches '=', it triggers the `else` clause, pushing `cnum` (which is 0, because after last digit, cnum was reset), so an extra 0 is added to `num`. For example, "5=" becomes num=[5,0], op=[], then cnt=2, opcnt=-1 → undefined behavior. So the error is in pushing `cnum` when encountering '='.]
    for(int i=0;i<strlen(in);i++) //去空格 
    {
        if(in[i]!=' ')
        {
            in[j++]=in[i];    
        }
    }
    if(in[j-1]!='=')in[j++]='='; // @@ [This line ensures '=' is present, but if the input already ends with '=', it's redundant. However, the real issue is in the next parsing loop: when '=' is encountered, it triggers the else branch and pushes cnum (which is 0) as a number, leading to an extra operand.]
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
            num[i++]=cnum; // @@ [When `in[pt]` is '=', this pushes the current `cnum` (which should be 0, because after the last number there are no digits), resulting in an extra zero at the end of `num`. This causes `cnt` to be one more than the actual number of operands, leading to incorrect calculations or array overruns.]
            cnum=0;
            cnt++;
            if(in[pt]=='+') op[j++]=-1;
            if(in[pt]=='-') op[j++]=-2;
            if(in[pt]=='*') op[j++]=-3;
            if(in[pt]=='/') op[j++]=-4;
            // Note: '=' is not handled here, so no operator is added for '=', but a number (0) is pushed.
        }
    }
    int opcnt=cnt-1; // @@ [Because an extra number (0) was pushed for '=', `cnt` is one too large, so `opcnt = cnt - 1` becomes equal to the actual number of operators, but now there's an extra operand. For a valid expression like "5=", we get num=[5,0], cnt=2, opcnt=1, but there are 0 operators. This leads to processing loops running with incorrect opcnt.]
    for(i=0;i<opcnt;)
    {
        if(op[i]==-4)
        {
            num[i]=calc(num[i],-4,num[i+1]);
            delete(num,&cnt,i+2);
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