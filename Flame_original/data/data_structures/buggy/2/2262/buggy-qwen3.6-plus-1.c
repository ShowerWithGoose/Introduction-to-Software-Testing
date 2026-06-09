#include<stdio.h>
char a[1000000];
char b[1000000];
int num[1000000];
int c[1000000]= {-1},k=1;
int k1,k2;
int op[100000],op2[100000];
int main()
{
    fgets(a,1000000,stdin);
    int t=0,l=strlen(a);
    for(int i=0; i<l; i++)
        if(a[i]!=' ')
            b[t++]=a[i];
    for(int i=0; i<t; i++) {
        if(b[i]=='-'||b[i]=='+'||b[i]=='=') {
            c[k++]=i;
            op[k1++]=k-1;

        } else if(b[i]=='*'||b[i]=='/')
            c[k++]=i;

    }
    for(int i=1; i<k; i++) {
        char s[10]= {};
        int sn=0;
        for(int j=c[i-1]+1; j<c[i]; j++)
            s[sn++]=b[j];
        s[sn]='\0';
        sscanf(s,"%d",&num[i-1]);
    }

    for(int i=0; i<k-1; i++) { // @@ Loop starts at 0, causing b[c[0]] to access b[-1] (since c[0]=-1) and num[i-1] to access num[-1], leading to out-of-bounds memory access.
        if(b[c[i]]=='*') {
            num[i]=num[i]*num[i-1]; // @@ Accesses num[-1] when i=0. Additionally, processing * and / in separate passes violates left-to-right associativity for operators of the same precedence.
        }
    }
    for(int i=0; i<k-1; i++) { // @@ Same out-of-bounds access issue as the multiplication loop.
        if(b[c[i]]=='/') {
            num[i]=num[i-1]/num[i]; // @@ Accesses num[-1] when i=0.
        }
    }
    for(int i=0; i<k1-1; i++) {
        if(b[c[op[i]]]=='-')
            num[op[i+1]-1]=num[op[i]-1]-num[op[i+1]-1];
        else
            num[op[i+1]-1]=num[op[i]-1]+num[op[i+1]-1];
    }
    printf("%d",num[k-2]);
    return 0;
}