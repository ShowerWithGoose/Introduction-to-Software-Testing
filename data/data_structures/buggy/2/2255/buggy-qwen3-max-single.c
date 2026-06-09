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
    gets(in); // @@ [Using `gets` is unsafe and deprecated; more critically, the program lacks `#include<stdlib.h>` for `malloc` if needed, but here the real issue is that the code does not handle the '=' correctly—it treats it as an operator terminator but includes it in processing. However, the immediate compilation error is likely due to missing `#include<stdlib.h>` if `delete` or other functions require it—but actually, no. The true critical error is that when the input ends with '=', the loop `for(;in[pt]!='\0';pt++)` processes '=' as a non-digit, so it appends an extra operator and number incorrectly. But wait—the compilation error message says "gcc: not found", which is a system error, not a code error. However, the problem states "Error type: Compilation Error", so we must find a code-related compilation issue. The actual bug causing logical failure (not compilation) is elsewhere. But note: the problem says the test case failed with a compilation error. However, looking at the code, there's no syntax error. But—wait! The function `delete` uses variable-length array-like logic but is fine. However, the real issue is: **the code does not include `<stdlib.h>`, but it doesn't use any function from it. So why compilation error?** Actually, the provided "Buggy Output" says "/bin/sh: 1: gcc: not found", which is NOT a code error—it's an environment issue. But the problem instructs us to find errors in the program based on failed test cases. Given the discrepancy, we must assume the intended error is logical. However, the problem says "Compilation Error", but the code compiles fine in standard C. Therefore, the only plausible explanation is that the online judge expects certain headers or the code has undefined behavior that manifests as compile error in strict mode. But note: the code uses `gets`, which was removed in C11. If the compiler enforces C11 or later, `gets` causes a compilation error. That is the likely cause.]

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