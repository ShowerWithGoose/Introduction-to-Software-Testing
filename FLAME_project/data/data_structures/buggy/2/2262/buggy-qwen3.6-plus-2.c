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
            num[i]=num[i]*num[i-1]; // @@ The multiplication logic is incorrect. It updates num[i] but leaves num[i-1] unchanged, and subsequent operations or the final result selection may use stale or incorrect values. Specifically, for chained multiplications/divisions, the result should accumulate into one operand, and the other should be marked as used/invalid to avoid double counting or incorrect indexing in later steps. Here, num[i] becomes the product, but num[i-1] remains the original left operand.
        }
    }
    for(int i=0; i<k-1; i++) {
        if(b[c[i]]=='/') {
            num[i]=num[i-1]/num[i]; // @@ The division logic is incorrect for similar reasons as multiplication. It calculates num[i-1]/num[i] and stores it in num[i]. However, if a previous multiplication modified num[i] or num[i-1], the operands might be wrong. More critically, the accumulation strategy is flawed. For example, in A / B / C, first A/B is computed. If stored in num[index_of_B], then next step uses num[index_of_B] (which is A/B) and num[index_of_C]. But the index mapping and overwriting make it hard to track. The main issue is that the final answer extraction `num[k-2]` assumes a specific structure that is broken by these in-place updates without clearing/adjusting adjacent elements properly.
        }
    }
    for(int i=0; i<k1-1; i++) {
        if(b[c[op[i]]]=='-')
            num[op[i+1]-1]=num[op[i]-1]-num[op[i+1]-1];
        else
            num[op[i+1]-1]=num[op[i]-1]+num[op[i+1]-1];
    }
    printf("%d",num[k-2]); // @@ The final result index is likely incorrect due to the flawed accumulation logic in the previous steps. The array `num` does not correctly hold the intermediate results in a way that `num[k-2]` represents the final answer. For the input "24 / 4 / 3 / 2 * 2 * 3 * 4 =", the expected output is 24, but the buggy output is 48, indicating a calculation error stemming from how * and / are processed and combined.
    return 0;
}