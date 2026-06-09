#include<stdio.h>
#include<string.h> // @@ Missing include for strlen
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

    for(int i=0; i<k-1; i++) {
        if(b[c[i]]=='*') {
            num[i]=num[i]*num[i-1]; // @@ Logic error: should use num[i-1] and num[i] correctly, but index i-1 may be out of bounds when i=0
        }
    }
    for(int i=0; i<k-1; i++) {
        if(b[c[i]]=='/') {
            num[i]=num[i-1]/num[i]; // @@ Logic error: similar index issue and division order may be wrong
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