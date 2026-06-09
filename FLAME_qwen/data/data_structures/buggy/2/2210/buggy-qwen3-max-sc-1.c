#include<stdio.h>
#include<string.h>
char s[100000];
double n[100000]; // @@ [Using double instead of integer type violates the requirement for integer division; also leads to precision and casting issues]
char oper[100000];
int a[128]; // @@ [Array size too small; original code used a['*']=... which requires at least 128 (ASCII range), but declared as a[100] causing out-of-bounds access]
double count(double a,double b,char c){
    if(c=='+')
    return a+b;
    if(c=='-')
    return a-b;
    if(c=='*')
    return a*b;
    return a/b; // @@ [Performs floating-point division, but problem requires integer division (e.g., 5/3 = 1)]
}
int main(){    
    gets(s); // @@ [gets() is unsafe and deprecated; may cause buffer overflow, though not directly causing compilation error here]
    int l=strlen(s);    
    a['*']=2,a['/']=2,a['+']=1,a['-']=1; // @@ [Writing to a[100] array with indices like '*' (ASCII 42), '+' (43), etc., is safe only if array size >= 128; original a[100] is too small]
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
            if(a[s[i]]>a[oper[p2-1]]||p2==0) // @@ [When p2==0, oper[p2-1] accesses oper[-1], which is undefined behavior]
            oper[p2++]=s[i];
            else{
                n[p1-2]=count(n[p1-2],n[p1-1],oper[p2-1]);
                n[--p1]=0; // @@ [Incorrectly sets n[p1] to 0 after decrement; should just decrement p1 without zeroing]
                oper[p2-1]=s[i];
            }
        }
    }
    int res=n[0]; // @@ [Casting double to int truncates, but due to earlier floating-point operations, result may be incorrect even before cast]
    for(i=0;i<p2-1;i++) // @@ [Loop runs p2-1 times, but there are p2 operators; should run while p2 > 0 or similar]
    res=(int)count(res,n[i+1],oper[i]);    
    printf("%d",res);
}