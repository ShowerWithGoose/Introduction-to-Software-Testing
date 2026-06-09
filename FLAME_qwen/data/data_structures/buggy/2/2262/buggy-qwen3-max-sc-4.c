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
    int t=0,l=strlen(a); // @@ [strlen is used without including <string.h>, causing compilation error]
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
        sscanf(s,"%d",&num[i-1]); // @@ [sscanf is used without including <stdio.h> properly (though <stdio.h> is included, some compilers may require explicit declaration; however, the real issue is missing <string.h> for strlen)]
    }

    for(int i=0; i<k-1; i++) {
        if(b[c[i]]=='*') {
            num[i]=num[i]*num[i-1]; // @@ [Incorrect indexing: should use num[i-1] and num[i], but logic is flawed as it overwrites operands in wrong order]
        }
    }
    for(int i=0; i<k-1; i++) {
        if(b[c[i]]=='/') {
            num[i]=num[i-1]/num[i]; // @@ [Incorrect indexing and order: division should be num[i-1] / num[i], but stored into wrong location; also modifies array while relying on original values later]
        }
    }
    for(int i=0; i<k1-1; i++) {
        if(b[c[op[i]]]=='-')
            num[op[i+1]-1]=num[op[i]-1]-num[op[i+1]-1]; // @@ [Indexing logic is incorrect; op array stores indices related to c, but usage leads to out-of-bound or wrong operand access]
        else
            num[op[i+1]-1]=num[op[i]-1]+num[op[i+1]-1]; // @@ [Same indexing issue as above]
    }
    printf("%d",num[k-2]);
    return 0;
}