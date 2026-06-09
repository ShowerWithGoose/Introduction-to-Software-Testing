#include<stdio.h>
char a[1000000];
char b[1000000];
int num[1000000];
int c[1000000]= {-1},k=1;
int k1,k2; // @@ [k1 is uninitialized, leading to undefined behavior when used later]
int op[100000],op2[100000];
int main()
{
    fgets(a,1000000,stdin);
    int t=0,l=strlen(a);
    for(int i=0; i<l; i++)
        if(a[i]!=' ')
            b[t++]=a[i]; // @@ [newline character from fgets is not filtered out, causing extra characters in b]
    for(int i=0; i<t; i++) {
        if(b[i]=='-'||b[i]=='+'||b[i]=='=') {
            c[k++]=i;
            op[k1++]=k-1; // @@ [k1 is uninitialized, array index out of bounds]

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

    for(int i=0; i<k-1; i++) { // @@ [loop starts at i=0 causing b[c[0]] = b[-1] which is out-of-bounds]
        if(b[c[i]]=='*') { // @@ [when i=0, c[i]=-1, invalid access]
            num[i]=num[i]*num[i-1];
        }
    }
    for(int i=0; i<k-1; i++) { // @@ [same issue: loop starts at i=0]
        if(b[c[i]]=='/') { // @@ [invalid access for i=0]
            num[i]=num[i-1]/num[i];
        }
    }
    for(int i=0; i<k1-1; i++) { // @@ [k1 is uninitialized, loop behavior undefined]
        if(b[c[op[i]]]=='-')
            num[op[i+1]-1]=num[op[i]-1]-num[op[i+1]-1];
        else
            num[op[i+1]-1]=num[op[i]-1]+num[op[i+1]-1];
    }
    printf("%d",num[k-2]);
    return 0;
}