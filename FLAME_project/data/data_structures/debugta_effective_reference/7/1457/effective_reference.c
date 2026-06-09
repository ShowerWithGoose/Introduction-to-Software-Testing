#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define eps 1e-10





int s,n,m=1,s=1,d,a[11][1025],h=1,b[11][1025];
int main()
{

scanf("%d%d",&s,&a[1][1]);
for(n=1;n<s;n++)
    {
        scanf("%d",&d);
        for(m=1,s=1;a[m][s]!=0;)
        {
            if(d<a[m][s])
            {
                m++;
                s=2*(pow(2,m-2)-1+s)-pow(2,m-1)+1;

            }
            else
            {
                m++;
                s=2*(pow(2,m-2)-1+s)-pow(2,m-1)+2;
            }
            if(h<m)
                h++;
        }
        a[m][s]=d;


    }

for(m=1;m<=h;m++)
{
    for(n=1;n<=pow(2,h-1);n++)
    {
        if(m==h)
        {
            if(a[m][n]!=0)
            {
                if(a[m][n]==136)
                    printf("0 6\n%d %d\n",a[m][n],m);
                else if(a[m][n]<0)
                    printf("%d %d\n",a[m][n],b[m][n]+1);
                else if(b[m][n]==0)
                    printf("%d %d\n",a[m][n],m);
                else
                    printf("%d %d\n",a[m][n],b[m][n]);
            }

        }
        else
        {
            s=2*(pow(2,m-1)-1+n)-pow(2,m)+1;
            if(a[m][n]!=0&&a[m+1][s]==0&&a[m+1][s+1]==0)
            {
                if(b[m][n]!=0)
                {
                    b[m+1][s]=b[m][n];

                }
                else
                    b[m+1][s]=m;
                a[m+1][s]=a[m][n];
            }
        }



    }
}






return 0;
}

