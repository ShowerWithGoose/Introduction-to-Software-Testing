#include<stdio.h>
#include<string.h>
char s[100000];
double n[100000]; // @@ [Using double instead of integer type violates the requirement of integer division; also causes precision and casting issues]
char oper[100000];
int a[100]; // @@ [Array 'a' is indexed by char values like '*', but size 100 may be too small for ASCII values (e.g., '*' is 42, but safe); however, uninitialized entries for other chars can cause undefined behavior]
double count(double a,double b,char c){ // @@ [Function uses double arithmetic, but problem requires integer operations including truncating division]
    if(c=='+')
    return a+b;
    if(c=='-')
    return a-b;
    if(c=='*')
    return a*b;
    return a/b; // @@ [This performs floating-point division, not integer division as required (e.g., 5/3 should be 1, but 5.0/3.0 ≈ 1.666... then cast later)]
}
int main(){    
    gets(s); // @@ [Use of unsafe gets() function which is deprecated and may cause buffer overflow; though not a compilation error in older standards, it often causes compilation failure in modern compilers]
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
                n[--p1]=0; // @@ [Setting n[--p1]=0 is unnecessary and may interfere with correct stack management]
                oper[p2-1]=s[i];
            }
        }
    }
    int res=n[0]; // @@ [Casting double to int here truncates, but prior floating-point inaccuracies may have already corrupted the value]
    for(i=0;i<p2-1;i++) // @@ [Loop runs p2-1 times, but there are p2 operators; this misses the last operation]
    res=(int)count(res,n[i+1],oper[i]);    
    printf("%d",res);
}