#include<stdio.h>
long long c[11];
int main()
{
    long long  i=0;
    int a;
    scanf("%d",&a);
    long long b;
    if(a==1) b=1;
    else if(a==2) b=22;
    else if(a==3) b=400;
    else if(a==4) b=5000;
    else if(a==5) b=60000;
    else if(a=6) b=700000;
    else if(a=7) b=8000000;
    else if(a=8) b=900000000;
    else if(a=9) b=1000000000;
    else  b=100000000000;

    long long sum=0;
    for(i=1; i<=a; i++) sum+=i;
    long long  j=0;
    long long f=0;
    long long k=0;
    long long flag=0;
    if(a<=9)
    {
        for(i=1; i<=b ;i++)
        {
            c[1]=i%10;
            c[2]=(i%100)/10;
            c[3]=(i%1000)/100;
            c[4]=(i%10000)/1000;
            c[5]=(i%100000)/10000;
            c[6]=(i%1000000)/100000;
            c[7]=(i%10000000)/1000000;
            c[8]=(i%100000000)/10000000;
            c[9]=(i%1000000000)/100000000;
            for(j=1; j<=a; j++)
            {
                if(c[j]<=a&&c[j]>0) f=f+c[j];
                else f=-100;
            }
            for(j=1; j<=a-1; j++)
            {
                for(k=j+1; k<=a; k++)
                    if(c[j]==c[k])
                        flag++;

            }

            if(flag==0&&sum==f)
            {
                for(k=a; k>=1; k--) printf("%d ",c[k]);
                printf("\n");
            }
            flag=0;
            f=0;
        }


    }
    return 0;
}

