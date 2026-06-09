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
            num[i]=num[i]*num[i-1]; // @@ Error: Incorrect index usage. When processing multiplication, the result should be stored in num[i-1] (the left operand) and subsequent operations should use this updated value, but the loop does not handle consecutive multiplications/divisions correctly. Also, the index i-1 may be out of bounds when i=0.
        }
    }
    for(int i=0; i<k-1; i++) {
        if(b[c[i]]=='/') {
            num[i]=num[i-1]/num[i]; // @@ Error: Same index issue as multiplication. For division, the result should be stored in num[i-1] (the left operand), and the loop does not correctly handle consecutive divisions like 24/4/3/2.
        }
    }
    for(int i=0; i<k1-1; i++) {
        if(b[c[op[i]]]=='-')
            num[op[i+1]-1]=num[op[i]-1]-num[op[i+1]-1]; // @@ Error: Incorrect index calculation. The indices op[i]-1 and op[i+1]-1 may not correctly reference the operands after multiplication/division processing, leading to wrong results.
        else
            num[op[i+1]-1]=num[op[i]-1]+num[op[i+1]-1]; // @@ Error: Same index issue as above for addition.
    }
    printf("%d",num[k-2]); // @@ Error: The final result index k-2 may not point to the correct result after all operations, especially when multiplication/division changes the number of valid entries.
    return 0;
}