#include <stdio.h>
#include <stdlib.h>
int main()
{
    char num11[10000],num22[10000];
    int num1[100],num2[100],flag[100];
    long long done1[10000],done2[10000];
    long long i,j,k=0,big1,big2,a=0,b,c=0;
    gets(num11);
    gets(num22);
    int num1_index = 0;
    for (i = 0; num11[i] != '\0'; i++) {
        if (num11[i] >= '0' && num11[i] <= '9') {
            num1[num1_index] = num1[num1_index]*10 + num11[i] - '0';
        } else {
            num1_index++;
        }
    }
    num1_index++;
    a = num1_index;
    int num2_index = 0;
    for (i = 0; num22[i] != '\0'; i++) {
        if (num22[i] >= '0' && num22[i] <= '9') {
            num2[num2_index] = num2[num2_index]*10 + num22[i] - '0';
        } else {
            num2_index++;
        }
    }
    num2_index++;
    c = num2_index;
    for(i=0;i<a;i++)
    {
            for(j=0;j<c;j++)
            {
                if(j%2==0&&i%2==0)
                {
                    done1[k]=num1[i]*num2[j];
                    done2[k]=num1[i+1]+num2[j+1];
                    k++;
                }
                else continue;
            }
    }

    for(i=0;i<k;i++)
    {
        for(j=i+1;j<k;j++)
        {
            if(done2[i]<done2[j])
            {
                big2=done2[j];
                done2[j]=done2[i];
                done2[i]=big2;
                big1=done1[j];
                done1[j]=done1[i];
                done1[i]=big1;
            }
        }
    }
    for(i=0;i<k;i++)
    {
        for(j=i+1;j<k;j++)
        {
                if(done2[i]==done2[j])
                {
                    done1[i]=done1[i]+done1[j];
                    flag[j]=1;
                }
        }
    }

    for(i=0;i<k;i++)
    {
        if(done1[i]==0||flag[i]==1)
        {
            continue;
        }
        else
        {
            printf("%lld %lld ",done1[i],done2[i]);
        }
    }
    return 0;
}



