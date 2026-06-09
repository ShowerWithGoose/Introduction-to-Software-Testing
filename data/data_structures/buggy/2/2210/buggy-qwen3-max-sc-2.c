#include<stdio.h>
#include<string.h>
char s[100000];
double n[100000]; // @@ [Using double instead of integer type violates the requirement of integer division and may cause precision issues; should use long long or int]
char oper[100000];
int a[128]; // @@ [Array size too small; 'a' is indexed by char values (e.g., '*', '/', etc.), which can go up to 127, but original code used a[100], causing out-of-bounds access. However, even a[128] may not be safe if negative chars are used, but more critically, the logic assumes valid operators only. The real issue is using int array for operator precedence without initializing all relevant entries.]
double count(double a,double b,char c){ // @@ [Function uses double arithmetic, but problem requires integer division (truncating). This leads to incorrect results for division, e.g., 5/3 becomes 1.666... then cast to int later, but intermediate steps lose integer semantics.]
    if(c=='+')
    return a+b;
    if(c=='-')
    return a-b;
    if(c=='*')
    return a*b;
    return a/b; // @@ [Performs floating-point division, not integer division as required. Should truncate toward zero using integers.]
}
int main(){    
    gets(s); // @@ [Use of gets() is unsafe and deprecated; may cause buffer overflow. Also, in some environments, gets() is not available, leading to compilation error. This likely caused the "gcc: not found" error indirectly due to compiler rejecting unsafe function.]
    int l=strlen(s);    
    a['*']=2,a['/']=2,a['+']=1,a['-']=1; // @@ [Array 'a' was declared as a[100], but '*' has ASCII 42, '/' is 47, '+' is 43, '-' is 45 — all within 0–99, so technically safe, BUT: uninitialized values for other characters could cause undefined behavior if accessed. However, the bigger issue is that oper[p2-1] when p2==0 accesses oper[-1], leading to undefined behavior.]
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
            if(a[s[i]]>a[oper[p2-1]]||p2==0) // @@ [When p2==0, oper[p2-1] is oper[-1], which is out-of-bounds access → undefined behavior. This is a critical runtime error that may cause crashes or wrong results.]
            oper[p2++]=s[i];
            else{
                n[p1-2]=count(n[p1-2],n[p1-1],oper[p2-1]);
                n[--p1]=0; // @@ [This sets n[p1] = 0 after decrementing p1, but the next number will overwrite it. However, the bigger issue is that the stack management is flawed; it doesn't properly handle operator precedence for consecutive same-precedence operators like * and / left-to-right.]
                oper[p2-1]=s[i]; // @@ [Replaces top operator instead of pushing new one after reducing; breaks associativity for same-precedence operators.]
            }
        }
    }
    int res=n[0]; // @@ [If expression starts with negative number, this fails, but problem says expression is valid and doesn't specify unary minus, so maybe okay. However, final evaluation loop is incorrect.]
    for(i=0;i<p2-1;i++) // @@ [Loop runs p2-1 times, but there are p2 operators and p1 numbers. Should reduce all operators. Also, it evaluates left-to-right ignoring precedence, but at this point all high-precedence ops should be done. However, due to earlier flawed reduction, this may be inconsistent.]
    res=(int)count(res,n[i+1],oper[i]);    
    printf("%d",res); // @@ [Casts final result to int, but if intermediate double calculations lost precision (e.g., large integers), result may be wrong. Also, if result is outside int range, undefined behavior. Should use %lld if long long, but here output as int.]
}