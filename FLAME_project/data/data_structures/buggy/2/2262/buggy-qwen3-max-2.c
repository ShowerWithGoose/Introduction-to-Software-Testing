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

    for(int i=0; i<k-1; i++) {
        if(b[c[i]]=='*') {
            num[i]=num[i]*num[i-1]; // @@ [Incorrect operand order and indexing: should use num[i-1] * num[i], but also modifies num[i] which affects later operations]
        }
    }
    for(int i=0; i<k-1; i++) {
        if(b[c[i]]=='/') {
            num[i]=num[i-1]/num[i]; // @@ [Incorrect operand order: division is left-associative, so it should be num[i-1] / num[i], but storing result in num[i] breaks subsequent references]
        }
    }
    for(int i=0; i<k1-1; i++) {
        if(b[c[op[i]]]=='-')
            num[op[i+1]-1]=num[op[i]-1]-num[op[i+1]-1]; // @@ [Indexing logic is flawed; the way op[] stores indices leads to incorrect operand selection and overwrites values needed later]
        else
            num[op[i+1]-1]=num[op[i]-1]+num[op[i+1]-1]; // @@ [Same indexing issue as above; operands are not correctly tracked after multiplication/division passes]
    }
    printf("%d",num[k-2]); // @@ [Final result index is incorrect due to flawed storage and update strategy during evaluation]
    return 0;
}