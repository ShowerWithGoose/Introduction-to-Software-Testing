#include<stdio.h>
#include<string.h>
char s[100000];
double n[100000]; // @@ [Using double instead of integer type leads to incorrect integer division and final casting issues; problem requires integer arithmetic]
char oper[100000];
int a[100]; // @@ [Array 'a' is indexed by char values like '*', but size 100 may be too small for ASCII values (e.g., '*' is 42, but safe); however, uninitialized entries for other characters could cause undefined behavior if accessed]
double count(double a,double b,char c){ // @@ [Function uses double arithmetic, but problem requires integer operations, especially truncating integer division]
    if(c=='+')
    return a+b;
    if(c=='-')
    return a-b;
    if(c=='*')
    return a*b;
    return a/b; // @@ [This performs floating-point division, not integer division as required (e.g., 5/3 should be 1, but 5.0/3.0 ≈ 1.666...)]
}
int main(){    
    gets(s); // @@ [Use of unsafe 'gets' function which is deprecated and removed in modern C standards; may cause buffer overflow, though not directly causing logic error here]
    int l=strlen(s);    
    a['*']=2,a['/']=2,a['+']=1,a['-']=1; // @@ [Array 'a' is of size 100, but indexing with char values is okay since operators are within 0–127; however, 'oper' stack may access a[oper[p2-1]] when p2==0, leading to a[-1] or a[uninitialized]]
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
            if(a[s[i]]>a[oper[p2-1]]||p2==0) // @@ [When p2==0, oper[p2-1] is oper[-1], which is out-of-bounds access → undefined behavior]
            oper[p2++]=s[i];
            else{
                n[p1-2]=count(n[p1-2],n[p1-1],oper[p2-1]);
                n[--p1]=0; // @@ [Setting n[--p1]=0 is unnecessary and may corrupt data; also, p1 is decremented but array element is zeroed incorrectly]
                oper[p2-1]=s[i]; // @@ [Should push new operator after popping, but this overwrites without incrementing p2 properly]
            }
        }
    }
    int res=n[0]; // @@ [Casting double to int truncates, but due to earlier floating-point inaccuracies, result may be wrong]
    for(i=0;i<p2-1;i++) // @@ [Loop runs p2-1 times, but there are p2 operators; should run while p2 > 0 or for all operators]
    res=(int)count(res,n[i+1],oper[i]); // @@ [Evaluates left-to-right ignoring operator precedence now, but stack wasn't fully reduced; also uses floating-point count]
    printf("%d",res);
}