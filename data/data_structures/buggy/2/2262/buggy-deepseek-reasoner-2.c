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
            op[k1++]=k-1; // @@ The '=' symbol is included as an operator in op array, but it should not be processed in the addition/subtraction loop later.
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

    for(int i=0; i<k-1; i++) { // @@ Loop should start from i=1, because c[0] is -1 (sentinel) and accessing b[c[0]] is invalid.
        if(b[c[i]]=='*') { // @@ For i=0, c[0] = -1, leads to out-of-bounds array access.
            num[i]=num[i]*num[i-1]; // @@ For i=0, num[i-1] is num[-1], out-of-bounds.
        }
    }
    for(int i=0; i<k-1; i++) { // @@ Same issue: loop should start from i=1.
        if(b[c[i]]=='/') { // @@ Out-of-bounds for i=0.
            num[i]=num[i-1]/num[i]; // @@ Out-of-bounds for i=0.
        }
    }
    for(int i=0; i<k1-1; i++) { // @@ k1 includes '=', so this loop tries to process '=' as an operator, causing incorrect arithmetic.
        if(b[c[op[i]]]=='-')
            num[op[i+1]-1]=num[op[i]-1]-num[op[i+1]-1]; // @@ Indexing into num may be incorrect; also not handling left-to-right evaluation properly.
        else
            num[op[i+1]-1]=num[op[i]-1]+num[op[i+1]-1]; // @@ Same issue.
    }
    printf("%d",num[k-2]);
    return 0;
}