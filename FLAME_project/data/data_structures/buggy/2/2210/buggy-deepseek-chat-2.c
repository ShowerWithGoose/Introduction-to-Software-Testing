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
            if(a[s[i]]>a[oper[p2-1]]||p2==0)
            oper[p2++]=s[i];
            else{
                n[p1-2]=count(n[p1-2],n[p1-1],oper[p2-1]);
                n[--p1]=0;
                oper[p2-1]=s[i]; // @@ [Error: When encountering an operator with lower or equal precedence, the code only processes one operator from the stack but does not handle multiple operators of equal or higher precedence that may be on the stack. For example, in "10+20*30-40/5", after processing "*", when encountering "-", the stack has "+" and "*", but only "*" is processed, leaving "+" unprocessed, leading to incorrect evaluation order. The correct approach is to pop and evaluate all operators with precedence >= current operator.]
            }
        }
    }
    int res=n[0];
    for(i=0;i<p2-1;i++)
    res=(int)count(res,n[i+1],oper[i]); // @@ [Error: This loop incorrectly assumes the remaining operators are in the order they were pushed, but due to the flawed precedence handling, the stack may not contain the correct sequence. Additionally, the loop starts from oper[0] but the stack may have been partially processed, leading to wrong results. The correct method is to evaluate all remaining operators in the stack in reverse order (LIFO).]
    printf("%d",res);
}