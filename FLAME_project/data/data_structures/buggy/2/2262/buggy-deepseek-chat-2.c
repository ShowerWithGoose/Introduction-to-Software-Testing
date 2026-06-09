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
            num[i]=num[i]*num[i-1]; // @@ Error: Incorrect index usage. When i=0, num[i-1] accesses num[-1] which is out of bounds. Also, the logic does not correctly handle consecutive multiplications; it should update num[i] using the previous result stored in num[i-1] but the loop overwrites values incorrectly.
        }
    }
    for(int i=0; i<k-1; i++) {
        if(b[c[i]]=='/') {
            num[i]=num[i-1]/num[i]; // @@ Error: Similar index issue. For i=0, num[i-1] is out of bounds. Also, the division logic does not correctly handle consecutive divisions; it should use the accumulated result from previous operations.
        }
    }
    for(int i=0; i<k1-1; i++) {
        if(b[c[op[i]]]=='-')
            num[op[i+1]-1]=num[op[i]-1]-num[op[i+1]-1]; // @@ Error: The index calculations are incorrect. op[i] stores indices into c, but subtracting 1 from c[op[i]] does not correctly map to the num array. This leads to wrong operands being used for subtraction and addition.
        else
            num[op[i+1]-1]=num[op[i]-1]+num[op[i+1]-1]; // @@ Error: Same index issue as above. The addition/subtraction operations are applied to wrong elements of num, causing incorrect results.
    }
    printf("%d",num[k-2]);
    return 0;
}