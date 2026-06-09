#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char a[128];
int i, k;
int flag;
char b[128], c[128];
int num, d;
int main()
{
    scanf("%s", a);
    if(a[0]=='0')
        flag = 0;//num<1
    else
        flag = 1;//num>=1
    
    switch(flag)
    {
        case 0:
            num = 1;
            i = 2;
            k = 2;
            while(a[i]=='0')
            {
                i++;
                num++;
            }
            if(a[i+1]=='\0')
            {
                b[0] = a[i];
            }
            else
            {
                b[0] = a[i];
                i += 1;
                b[1] = '.';
                while(a[i]!='\0')
                {
                    b[k] = a[i];
                    k++;
                    i++;
                }
            }
            printf("%se-%d", b, num);
            break;
        
        case 1:
            if(a[1]=='.')
            {
                strcpy(c, a);
                d = 0;
            }
            else
            {
                i = 1;
                d = 0;
                k = 2;
                while(a[i]!='.')
                {
                    d++;
                    i++;
                }
                c[0] = a[0];
                c[1] = '.';
                i = 1;
                while(a[i]!='\0')
                {
                    if(a[i]=='.')
                    {
                        i++;
                    }
                    else
                    {
                        c[k] = a[i];
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


