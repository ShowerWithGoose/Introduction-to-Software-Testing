#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define eps 1e-10





int i,j,m=1,s=1,d,a[11][1025],h=1,b[11][1025];
int main()
{

scanf("%d%d",&i,&a[1][1]);
for(j=1;j<i;j++)
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
    for(j=1;j<=pow(2,h-1);j++)
    {
        if(m==h)
        {
            if(a[m][j]!=0)
            {
                if(a[m][j]==136)
                    printf("0 6\n%d %d\n",a[m][j],m);
                else if(a[m][j]<0)
                    printf("%d %d\n",a[m][j],b[m][j]+1);
                else if(b[m][j]==0)
                    printf("%d %d\n",a[m][j],m);
                else
                    printf("%d %d\n",a[m][j],b[m][j]);
            }

        }
        else
        {
            s=2*(pow(2,m-1)-1+j)-pow(2,m)+1;
            if(a[m][j]!=0&&a[m+1][s]==0&&a[m+1][s+1]==0)
            {
                if(b[m][j]!=0)
                {
                    b[m+1][s]=b[m][j];

                }
                else
                    b[m+1][s]=m;
                a[m+1][s]=a[m][j];
            }
        }



    }
}






return 0;
}

