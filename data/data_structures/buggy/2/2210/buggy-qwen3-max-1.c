#include<stdio.h>
#include<string.h>
char s[100000];
double n[100000]; // @@ [Using double instead of integer type violates the requirement of integer division; also leads to precision and casting issues]
char oper[100000];
int a[100]; // @@ [Array 'a' is indexed by char values like '*', but size 100 may be too small for ASCII values up to 127; however, main issue is logic below]
double count(double a,double b,char c){ // @@ [Function uses double, but problem requires integer arithmetic and integer division]
    if(c=='+')
    return a+b;
    if(c=='-')
    return a-b;
    if(c=='*')
    return a*b;
    return a/b; // @@ [This performs floating-point division, not integer division as required (e.g., 5/3 must be 1, not 1.666...)]
}
int main(){    
    gets(s); // @@ [Use of gets() is unsafe and deprecated; may cause buffer overflow, but more critically, some compilers reject it leading to compilation error]
    int l=strlen(s);    
    a['*']=2,a['/']=2,a['+']=1,a['-']=1; // @@ [Relies on correct precedence, but array 'a' was not initialized; other char indices (like '\0') may contain garbage]
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
            if(a[s[i]]>a[oper[p2-1]]||p2==0) // @@ [When p2==0, oper[p2-1] accesses oper[-1], which is out-of-bounds undefined behavior]
            oper[p2++]=s[i];
            else{
                n[p1-2]=count(n[p1-2],n[p1-1],oper[p2-1]);
                n[--p1]=0; // @@ [Incorrect stack management: sets n[p1] to 0 after decrement, but should just decrement p1]
                oper[p2-1]=s[i]; // @@ [Does not increment p2; overwrites last operator without pushing new one properly]
            }
        }
    }
    int res=n[0]; // @@ [Casts double to int prematurely; also assumes at least one number exists]
    for(i=0;i<p2-1;i++) // @@ [Loop runs p2-1 times, but there are p2 operators; misses last operation]
    res=(int)count(res,n[i+1],oper[i]);    
    printf("%d",res);
}