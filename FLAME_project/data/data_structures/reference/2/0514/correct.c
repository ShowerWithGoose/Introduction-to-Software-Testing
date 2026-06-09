#include <stdio.h>
#include <stdlib.h>
void strdel(char a[], int lena)
{
    for (int i=0; i<lena; i++)
    {
        a[i] = a[i+1];

    }
    a[lena] = NULL;
}



int main()
{
    char a[1000000];
    static int num[1000000];
    char c[1000000];
    int tim=0, div=0, plu=0, sub=0;

    gets(a);


    a[strlen(a)-1]=NULL;//删除=号


    for (int m=0; m<strlen(a); m++)
    {
        if (a[m]==' ')
        {
            strdel(a+m, strlen(a)-m-1);

            if (a[m]==' ')
            {
                m--;
            }
        }
    }//删除空格

    //printf("%s\n", a);

    int i=0, k=0, r=0;
    for (;i<strlen(a); i++)
    {
        if ((a[i]>='0')&&(a[i]<='9'))
        {
            num[k]=(a[i]-'0');

            for (int x=i+1; ; x++)
            {
                if((a[x]>='0')&&(a[x]<='9'))
                {
                    num[k] = num[k]*10 + (a[x]-'0');
                    r++;
                }
                else
                    break;
            }
            i = i+r;
            r=0;
        }

        else
        {
        if (a[i]=='*')
        {
            c[k]='*';
        }
        if (a[i]=='/')
        {
            c[k]='/';
        }
        if (a[i]=='+')
        {
            c[k]='+';
        }
        if (a[i]=='-')
        {
            c[k]='-';
        }
        k++;
        }
    }//读入数据,共k个运算符,k+1个数字

    /*for (int p=0; p<k; p++)
    {
        printf("%c\n", c[p]);
    }
    for (int p=0; p<k+1; p++)
    {
        printf("%d\n", num[p]);
    }//检验读入的数据*/

    for(int j=0; j<k; j++)
    {
        if((c[j]=='*')||(c[j]=='/'))
        {
            if(c[j]=='*')
                num[j]=num[j]*num[j+1];
            else
                num[j]=num[j]/num[j+1];

            for (int n=j+1; n<k; n++)
            {
                num[n]=num[n+1];
            }
            num[k]=0;

            for (int n=j; n<k-1; n++)
            {
                c[n]=c[n+1];
            }
            c[k-1]=NULL;
            k--;
            //for (int n=0; n<k+1; n++)
            //{
            //    printf("%d\n", num[n]);
            //}
            j--;
        }
    }
    /*for(int j=0; j<k; j++)
    {
        if(c[j]=='2')
        {
            num[j]=num[j]/num[j+1];

            for (int n=j+1; n<k; n++)
            {
                num[n]=num[n+1];
            }
            num[k]=0;
            for (int n=j+1; n<k-1; n++)
            {
                c[n]=c[n+1];
            }
            c[k-1]=NULL;
            k--;
            j--;
        }
    }*/
    /*for(int j=0; j<k; j++)
    {
        printf("%d", num[j]);
        printf("%c", c[j]);

    }
    printf("%d\n", num[k]);*/


    for(int j=0; j<k; j++)
    {
            if(c[j]=='-')
            {
                //printf("yes");
                num[j]=num[j]-num[j+1];
                //printf("%d\n", num[j]);
            //else
                //num[j]=num[j]+num[j+1];

            for (int n=j+1; n<k; n++)
            {
                num[n]=num[n+1];
            }
            num[k]=0;

            for (int n=j; n<k-1; n++)
            {
                c[n]=c[n+1];
            }
            c[k-1]=NULL;
            k--;
            j--;
            }
            //printf("%c\n", c[0]);
    }
    //for(int j=0; j<k; j++)
        //printf("%c", c[j]);

    /*for(int j=0; j<k; j++)
    {
        printf("%d", num[j]);
        printf("%c", c[j]);

    }
    printf("%d\n", num[k]);*/



    for(int j=0; j<k; j++)
    {
        if(c[j]=='+')
        {
            //printf("yes");
            num[j]=num[j]+num[j+1];

            for (int n=j+1; n<k; n++)
            {
                num[n]=num[n+1];
            }
            num[k]=0;

            for (int n=j; n<k-1; n++)
            {
                c[n]=c[n+1];
            }
            c[k-1]=NULL;
            k--;
            j--;
        }
    }

    printf("%d", num[0]);

    return 0;
}



