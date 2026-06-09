#include<stdio.h>
#include<string.h>
char s[100000];
double n[100000]; // @@ [Using double instead of integer type violates the requirement of integer division; also causes precision and casting issues]
char oper[100000];
int a[100]; // @@ [Array 'a' is indexed by char values like '*', but its size (100) may be too small for ASCII values (e.g., '*' is 42, '/' is 47, '+' is 43, '-' is 45 — which fits, but it's fragile and unclear)]
double count(double a,double b,char c){ // @@ [Function uses double arithmetic, but problem requires integer operations, especially integer division (e.g., 5/3=1, not 1.666...)]
    if(c=='+')
    return a+b;
    if(c=='-')
    return a-b;
    if(c=='*')
    return a*b;
    return a/b; // @@ [This performs floating-point division, not integer division as required]
}
int main(){    
    gets(s); // @@ [Use of gets() is unsafe and deprecated; may cause buffer overflow, though not directly causing logic error here]
    int l=strlen(s);    
    a['*']=2,a['/']=2,a['+']=1,a['-']=1; // @@ [Relies on correct precedence, but array 'a' was not initialized for other characters; however, only these are used so may work, but risky]
    int i,j,p1=0,p2=0;
    for(i=0,j=0;i<l;i++){
        if(s[i]!=' '&&s[i]!='=')
        s[j++]=s[i];
    }
    l=j,i=0,j=0;
    for(i=0;i<l;i++){
        if(s[i]>='0'&&s[i]<='9'){
            int num=0,k;
            for(k=i;s[k]>='0'&&s[k]<='9';k++)
            num=num*10+s[k]-'0';
            i=k-1;
            n[p1++]=num;
        }
        else{
            if(a[s[i]]>a[oper[p2-1]]||p2==0) // @@ [When p2==0, oper[p2-1] accesses oper[-1], which is undefined behavior — this is a critical out-of-bounds read]
            oper[p2++]=s[i];
            else{
                n[p1-2]=count(n[p1-2],n[p1-1],oper[p2-1]);
                n[--p1]=0; // @@ [Setting n[--p1]=0 is unnecessary and may interfere with later calculations; also, the stack management is flawed]
                oper[p2-1]=s[i]; // @@ [Incorrectly replaces operator instead of pushing new one after reducing; breaks operator stack logic]
            }
        }
    }
    int res=n[0]; // @@ [Casts double to int prematurely; also, final evaluation loop is incorrect — it assumes left-to-right evaluation ignoring remaining operator precedence]
    for(i=0;i<p2-1;i++) // @@ [Loop runs p2-1 times, but should reduce all operators; also processes operators in wrong order (left-to-right) without considering that stack may have higher precedence ops]
    res=(int)count(res,n[i+1],oper[i]);    
    printf("%d",res); // @@ [Due to all above errors, result is incorrect for expressions like "5 - 1 * 2 * 3 + 12 / 2 / 2 =", which should be 5 - 6 + 3 = 2, but program likely gives wrong answer]
}