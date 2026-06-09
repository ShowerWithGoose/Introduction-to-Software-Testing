#include<stdio.h>
#include<string.h>
char s[100000];
double n[100000]; // @@ [Using double instead of integer type violates the requirement of integer division; e.g., 5/3 must be 1, but double would store 1.666... and later cast may not truncate correctly in all contexts]
char oper[100000];
int a[128]; // @@ [Original code used a[100], which is too small since char values like '*' (ASCII 42) are fine, but safer to use at least 128; however, more critically, uninitialized entries for non-operator chars cause undefined behavior when accessed as a[oper[p2-1]] when p2==0 or oper contains unassigned values]
double count(double a,double b,char c){
    if(c=='+')
    return a+b;
    if(c=='-')
    return a-b;
    if(c=='*')
    return a*b;
    return a/b; // @@ [Performs floating-point division, not integer division as required; e.g., 5/3 returns ~1.666 instead of 1]
}
int main(){    
    gets(s); // @@ [gets() is unsafe and deprecated; may cause buffer overflow, but more importantly, in many modern environments (like the test system), it may not be available, leading to compilation error: "gcc: not found" could be misleading, but actual issue is linking or function availability; however, primary logic errors dominate]
    int l=strlen(s);    
    a['*']=2,a['/']=2,a['+']=1,a['-']=1; // @@ [Array 'a' was declared as a[100], but char values like '+' (43), '-' (45), etc., are within 0–127, so a[100] is insufficient (e.g., '/' is 47, still ok, but if any char >99 appears, out-of-bound write); however, bigger issue: when p2==0, oper[p2-1] = oper[-1] is accessed in next loop, causing undefined behavior]
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
            if(a[s[i]]>a[oper[p2-1]]||p2==0) // @@ [When p2==0, oper[p2-1] is oper[-1], which is out-of-bounds access → undefined behavior; this can crash or produce wrong precedence comparison]
            oper[p2++]=s[i];
            else{
                n[p1-2]=count(n[p1-2],n[p1-1],oper[p2-1]);
                n[--p1]=0; // @@ [Setting n[--p1]=0 is unnecessary and incorrect; after computing result into n[p1-2], we should just decrement p1, not zero out the new top; also, using double with truncation later causes precision issues]
                oper[p2-1]=s[i]; // @@ [Should push current operator after popping and computing, but logic here replaces top operator without proper stack handling for multiple lower-precedence ops]
            }
        }
    }
    int res=n[0]; // @@ [Casting double n[0] to int truncates, but due to earlier floating-point operations, results may be inaccurate (e.g., 1.999999 becomes 1 instead of 2)]
    for(i=0;i<p2-1;i++) // @@ [Loop runs p2-1 times, but there are p2 operators and p1 numbers; after processing, should apply remaining operators from left to right, but this loop uses wrong indices: uses oper[i] with n[i+1], assuming flat evaluation, which fails for cases like 10 - 2 - 3 (should be 5, but computed as 10 - (2 - 3) = 11 if not left-associative)]
    res=(int)count(res,n[i+1],oper[i]);    
    printf("%d",res); // @@ [Final output uses %d for int, but if intermediate double inaccuracies occurred, result may be wrong; also, overall algorithm does not correctly handle operator precedence and associativity for all cases]
}