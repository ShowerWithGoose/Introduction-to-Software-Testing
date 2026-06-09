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

    for(int i=0; i<k-1; i++) { // @@ Loop starts from i=0, causing out-of-bounds access to c[0] (which is -1) and also processes operators in wrong order (all * before /); should evaluate * and / in original left-to-right order.
        if(b[c[i]]=='*') { // @@ Accessing b[c[i]] when i=0 leads to undefined behavior (index -1); also the algorithm incorrectly separates * and / into two passes.
            num[i]=num[i]*num[i-1]; // @@ For the given test case, this modifies num[i] based on previous multiplication, but later division loop uses already changed values, violating operator precedence.
        }
    }
    for(int i=0; i<k-1; i++) { // @@ Same indexing issue and logical error: division should be interleaved with multiplication, not executed after all multiplications.
        if(b[c[i]]=='/') { // @@ Out-of-bounds when i=0.
            num[i]=num[i-1]/num[i]; // @@ Uses num[i-1] after it may have been altered by multiplication loop, leading to wrong results.
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