#include<stdio.h>
#include<string.h>
char s[100000];
double n[100000]; // @@ [Using double instead of integer type violates the requirement of integer division and may cause precision issues; should use long long or int]
char oper[100000];
int a[100];
double count(double a,double b,char c){ // @@ [Function returns double but problem requires integer arithmetic; should return integer type]
    if(c=='+')
    return a+b;
    if(c=='-')
    return a-b;
    if(c=='*')
    return a*b;
    return a/b; // @@ [Performs floating-point division instead of integer division as required]
}
int main(){    
    gets(s); // @@ [gets() is unsafe and deprecated; may cause buffer overflow, though not directly causing wrong output here]
    int l=strlen(s);    
    a['*']=2,a['/']=2,a['+']=1,a['-']=1;
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
            if(a[s[i]]>a[oper[p2-1]]||p2==0) // @@ [When p2==0, oper[p2-1] accesses oper[-1], which is out-of-bounds and undefined behavior]
            oper[p2++]=s[i];
            else{
                n[p1-2]=count(n[p1-2],n[p1-1],oper[p2-1]);
                n[--p1]=0; // @@ [Setting n[--p1]=0 is unnecessary and may interfere with correct stack behavior]
                oper[p2-1]=s[i];
            }
        }
    }
    int res=n[0]; // @@ [Truncating double to int here loses precision and may give incorrect result due to prior floating-point operations]
    for(i=0;i<p2-1;i++) // @@ [Loop condition should be i < p2, not p2-1, because there are p2 operators and p2+1 operands initially, but after reductions it should process all remaining operators]
    res=(int)count(res,n[i+1],oper[i]); // @@ [Incorrect left-to-right evaluation ignores operator precedence that was partially handled earlier; also uses floating-point then casts to int]
    printf("%d",res);
}