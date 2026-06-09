#include<stdio.h>
#include<string.h>
char s[100000];
double n[100000];
char oper[100000];
int a[100];
double count(double a,double b,char c){
    if(c=='+')
    return a+b;
    if(c=='-')
    return a-b;
    if(c=='*')
    return a*b;
    return a/b;
}
int main(){    
    gets(s);
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
            if(a[s[i]]>a[oper[p2-1]]||p2==0) // @@ [Error: When p2==0, oper[p2-1] accesses oper[-1], which is out of bounds. The condition should check p2==0 first before accessing oper[p2-1].]
            oper[p2++]=s[i];
            else{
                n[p1-2]=count(n[p1-2],n[p1-1],oper[p2-1]);
                n[--p1]=0;
                oper[p2-1]=s[i]; // @@ [Error: This line overwrites the last operator instead of replacing it with the new one. It should be oper[p2-1]=s[i] without decrementing p2, but the logic is flawed; the correct approach is to decrement p2 after using the operator, then assign the new operator.]
            }
        }
    }
    int res=n[0];
    for(i=0;i<p2-1;i++) // @@ [Error: The loop condition should be i<p2, not i<p2-1, because there are p2 operators to process. This misses the last operator.]
    res=(int)count(res,n[i+1],oper[i]);    
    printf("%d",res);
}