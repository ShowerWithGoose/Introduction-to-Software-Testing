#include<stdio.h>
#include<string.h>
#include <ctype.h>
void Squeez(char s[],char c)
{
    int i,j;
    for(i=j=0;i<strlen(s);i++)
        if(s[i]!=c)
            s[j++]=s[i];
    s[j]='\0';
}
int main() {
    char s[100] = {};
    gets(s);
    Squeez(s, ' ');
    int len = strlen(s);
    int i = 0;
    int j = 0;
    int k = 0;

    int digit[100] = {};
    char operator[100] = {};
    i = 0;
    while (s[i] != '=') {
        int res = 0;
        if (!isdigit(s[i])) {
            operator[k] = s[i];
            k++;
            i++;
        } else {
            while (isdigit(s[i])) {
                res = res * 10;
                res += s[i] - '0';
                i++;
            }
            digit[j] = res;
            j++;
        }
    }
    while (k>0)
    {

            while(strstr(operator, "*") != NULL||strstr(operator, "/") != NULL)
            {
                if((strstr(operator, "*")<strstr(operator, "/")&&strstr(operator, "*") != NULL)||(strstr(operator, "*") != NULL&&strstr(operator, "/") == NULL))
                {
                    i= strstr(operator,"*") - operator;
                    digit[i]=digit[i]*digit[i+1];
                    for(int j=i;j<k;j++)
                    {
                        operator[j]=operator[j+1];
                    }
                    for(int k=i+1;k<j;k++)
                    {
                        digit[k]=digit[k+1];
                    }
                    k--;
                    j--;
                }
                else
                {
                    i= strstr(operator, "/") - operator;
                    digit[i]=digit[i]/digit[i+1];
                    for(int j=i;j<k;j++)
                    {
                        operator[j]=operator[j+1];
                    }
                    for(int k=i+1;k<j;k++)
                    {
                        digit[k]=digit[k+1];
                    }
                    k--;
                    j--;
                }
            }

            while(strstr(operator, "+") != NULL||strstr(operator, "-") != NULL)
            {
                if((strstr(operator, "+")<strstr(operator, "-")&&strstr(operator, "+") != NULL)||(strstr(operator, "+") != NULL&&strstr(operator, "-") == NULL))
                {
                    i= strstr(operator, "+") - operator;
                    digit[i]=digit[i]+digit[i+1];
                    for(int j=i;j<k;j++)
                    {
                        operator[j]=operator[j+1];
                    }
                    for(int k=i+1;k<j;k++)
                    {
                        digit[k]=digit[k+1];
                    }
                    k--;
                    j--;
                }
                else
                {
                    i= strstr(operator, "-") - operator;
                    digit[i]=digit[i]-digit[i+1];
                    for(int j=i;j<k;j++)
                    {
                        operator[j]=operator[j+1];
                    }
                    for(int k=i+1;k<j;k++)
                    {
                        digit[k]=digit[k+1];
                    }
                    k--;
                    j--;
                }
            }
        }

    printf("%d",digit[0]);
    return  0;
}

