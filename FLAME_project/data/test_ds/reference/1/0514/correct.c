#include <stdio.h>
#include <string.h>
int judge(char a, char b)
{
    if ((a>='a')&&(a<='z'))
    {
        if ((b>='a')&&(b<='z')&&(b>a))
        {
            return 1;
        }
    }
     if ((a>='A')&&(a<='Z'))
    {
        if ((b>='A')&&(b<='Z')&&(b>a))
        {
            return 1;
        }
    }
     if ((a>='0')&&(a<='9'))
    {
        if ((b>='0')&&(b<='9')&&(b>a))
        {
            return 1;
        }
    }
}

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
    char a[1000000], b[26];
    int len, j;
    /*gets(a);gets函数最好不要用*/
    scanf("%s", &a);
    for (int i=1; i<strlen(a)-1; i++)
    {
        if(a[i]=='-')
        {
            j = judge(a[i-1], a[i+1]);
            if (j==1)
            {
                len = a[i+1]-a[i-1]-1;/*求出插入数列b[]*/
                b[0]=a[i-1]+1;
                for (int k=1; k<len; k++)
                {
                    b[k] = b[k-1]+1;
                }

                strdel(a+i, strlen(a)-i-1);
                /*printf("%s\n", a);*/
                for (int k=strlen(a)+len; k>=i+len; k--)
                {
                    a[k]=a[k-len];
                }

                strncpy(a+i, b, len);


            }
        }
    }
    printf("%s\n", a);
    /*printf("%s\n", b);*/
    return 0;
}

