#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char num[128];
int i, k;
int flag;
char a[128], c[128];
int b, d;
int main()
{
    scanf("%s", num);
    if(num[0]=='0')
        flag = 0;//num<1
    else
        flag = 1;//num>=1
    
    switch(flag)
    {
        case 0:
            b = 1;
            i = 2;
            k = 2;
            while(num[i]=='0')
            {
                i++;
                b++;
            }
            if(num[i+1]=='\0')
            {
                a[0] = num[i];
            }
            else
            {
                a[0] = num[i];
                i += 1;
                a[1] = '.';
                while(num[i]!='\0')
                {
                    a[k] = num[i];
                    k++;
                    i++;
                }
            }
            printf("%se-%d", a, b);
            break;
        
        case 1:
            if(num[1]=='.')
            {
                strcpy(c, num);
                d = 0;
            }
            else
            {
                i = 1;
                d = 0;
                k = 2;
                while(num[i]!='.')
                {
                    d++;
                    i++;
                }
                c[0] = num[0];
                c[1] = '.';
                i = 1;
                while(num[i]!='\0')
                {
                    if(num[i]=='.')
                    {
                        i++;
                    }
                    else
                    {
                        c[k] = num[i];
                        k++;
                        i++;
                    }
                }
            }
            printf("%se%d", c, d);
            break;
    }

    system("pause");
    return 0;
}


