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
    char str[100] = {};
    gets(str);
    Squeez(str, ' ');
    int len = strlen(str);
    int i = 0;
    int cntdigit = 0;
    int cntoperator = 0;

    int digit[100] = {};
    char operator[100] = {};
    i = 0;
    while (str[i] != '=') {
        int temp = 0;
        if (!isdigit(str[i])) {
            operator[cntoperator] = str[i];
            cntoperator++;
            i++;
        } else {
            while (isdigit(str[i])) {
                temp = temp * 10;
                temp += str[i] - '0';
                i++;
            }
            digit[cntdigit] = temp;
            cntdigit++;
        }
    }
    while (cntoperator>0)
    {

            while(strstr(operator, "*") != NULL||strstr(operator, "/") != NULL)
            {
                if((strstr(operator, "*")<strstr(operator, "/")&&strstr(operator, "*") != NULL)||(strstr(operator, "*") != NULL&&strstr(operator, "/") == NULL))
                {
                    i= strstr(operator,"*") - operator;
                    digit[i]=digit[i]*digit[i+1];
                    for(int j=i;j<cntoperator;j++)
                    {
                        operator[j]=operator[j+1];
                    }
                    for(int k=i+1;k<cntdigit;k++)
                    {
                        digit[k]=digit[k+1];
                    }
                    cntoperator--;
                    cntdigit--;
                }
                else
                {
                    i= strstr(operator, "/") - operator;
                    digit[i]=digit[i]/digit[i+1];
                    for(int j=i;j<cntoperator;j++)
                    {
                        operator[j]=operator[j+1];
                    }
                    for(int k=i+1;k<cntdigit;k++)
                    {
                        digit[k]=digit[k+1];
                    }
                    cntoperator--;
                    cntdigit--;
                }
            }

            while(strstr(operator, "+") != NULL||strstr(operator, "-") != NULL)
            {
                if((strstr(operator, "+")<strstr(operator, "-")&&strstr(operator, "+") != NULL)||(strstr(operator, "+") != NULL&&strstr(operator, "-") == NULL))
                {
                    i= strstr(operator, "+") - operator;
                    digit[i]=digit[i]+digit[i+1];
                    for(int j=i;j<cntoperator;j++)
                    {
                        operator[j]=operator[j+1];
                    }
                    for(int k=i+1;k<cntdigit;k++)
                    {
                        digit[k]=digit[k+1];
                    }
                    cntoperator--;
                    cntdigit--;
                }
                else
                {
                    i= strstr(operator, "-") - operator;
                    digit[i]=digit[i]-digit[i+1];
                    for(int j=i;j<cntoperator;j++)
                    {
                        operator[j]=operator[j+1];
                    }
                    for(int k=i+1;k<cntdigit;k++)
                    {
                        digit[k]=digit[k+1];
                    }
                    cntoperator--;
                    cntdigit--;
                }
            }
        }

    printf("%d",digit[0]);
    return  0;
}

