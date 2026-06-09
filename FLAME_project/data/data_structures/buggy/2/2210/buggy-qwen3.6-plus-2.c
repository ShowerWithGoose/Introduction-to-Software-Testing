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
            if(a[s[i]]>a[oper[p2-1]]||p2==0) // @@ The array 'oper' is not initialized, so oper[p2-1] accesses uninitialized memory when p2==0 is false but p2>0. More critically, when p2==0, the condition short-circuits correctly, but if p2 > 0, oper[p2-1] might contain garbage if not properly managed. However, the main logic error is in the 'else' block handling operator precedence and stack reduction.
            oper[p2++]=s[i];
            else{
                n[p1-2]=count(n[p1-2],n[p1-1],oper[p2-1]);
                n[--p1]=0;
                oper[p2-1]=s[i]; // @@ This logic incorrectly replaces the top operator instead of pushing the new one after reducing. It fails to handle cases where multiple reductions are needed or correctly maintaining the operator stack. Specifically, it reduces only once and then overwrites the operator, which breaks the precedence chain for subsequent operators.
            }
        }
    }
    int res=n[0];
    for(i=0;i<p2-1;i++) // @@ This loop assumes that all remaining operations can be performed sequentially from left to right on the reduced stack. However, due to the flawed reduction logic above, the state of 'n' and 'oper' is incorrect. Also, 'res' is cast to int early, losing precision for intermediate double results if division was involved, though the problem asks for integer division. The primary issue is the incorrect evaluation order resulting from the previous logic errors.
    res=(int)count(res,n[i+1],oper[i]);    
    printf("%d",res);
}