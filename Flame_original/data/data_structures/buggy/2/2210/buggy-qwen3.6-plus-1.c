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
    gets(s); // @@ [gets is deprecated and removed in C11 standard, causing compilation error in modern environments; use fgets(s, sizeof(s), stdin)]
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
            int num=0,k; // @@ [int may overflow for large numeric inputs, should be long long to safely store parsed values]
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
                oper[p2-1]=s[i];
            }
        }
    }
    int res=n[0]; // @@ [accumulated result may exceed int range, should be long long]
    for(i=0;i<p2-1;i++) // @@ [loop condition i<p2-1 incorrectly skips the final operator and operand; should be i<p2]
    res=(int)count(res,n[i+1],oper[i]);    
    printf("%d",res); // @@ [format specifier %d does not match long long type; should be %lld]
}