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
            if(a[s[i]]>a[oper[p2-1]]||p2==0) // @@ This condition only pushes when precedence is strictly higher; should pop and evaluate all operators with higher or equal precedence before pushing.
            oper[p2++]=s[i];
            else{
                n[p1-2]=count(n[p1-2],n[p1-1],oper[p2-1]); // @@ This evaluates only one operator; should be inside a while loop to evaluate all higher or equal precedence operators.
                n[--p1]=0; // @@ Decrementing p1 and setting to 0 is unnecessary and may cause issues; correct approach is to just decrement p1 after storing result.
                oper[p2-1]=s[i]; // @@ Replaces the top operator without removing it; should pop the operator after evaluation and then push new operator outside the loop.
            }
        }
    }
    int res=n[0];
    for(i=0;i<p2-1;i++) // @@ Loop condition misses the last operator; should be i<p2 to process all operators.
    res=(int)count(res,n[i+1],oper[i]); // @@ This evaluates left-to-right without precedence; should pop operators from stack and evaluate with numbers correctly.
    printf("%d",res);
}