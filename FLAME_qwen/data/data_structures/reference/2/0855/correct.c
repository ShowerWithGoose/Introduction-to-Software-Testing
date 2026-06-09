#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char s[100];
int num[100];
void delete (char *str);
int JudgeNumber(char *str, int *num);
int Calculate(char *str, int num[]);
int main()
{
    gets(s);
    delete (s);
    JudgeNumber(s, num);
    int result = Calculate(s, num);
    printf("%d", result);
    return 0;
}
void delete (char *str)
{
    int i, j = 0;
    for (i = 0; str[i] != '\0'; j++)
    {
        str[i] = str[j];
        if (str[i] != ' ')
        {
            i++;
        }
    }
}
int JudgeNumber(char *str, int *num)
{
    int len = strlen(str);
    int i, j = 0, last = -1, digit = 0;
    for (i = 0; i < len; i++)
    {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '=')
        {
            digit = i - last-1;
            char linshi[100];
            int l = 0;
            for (l = 0; l < digit; l++)
            {
                linshi[l] = str[last + l+1];
            }
            linshi[digit] = '\0';
            num[j] = atoi(linshi);
            j++;
            last = i;
        }
    }
}
int Calculate(char *str, int num[])
{
    int cal ;
    int FirstCal = 0;
    char operator[100];
    char FirstOperator = '+';
    char MidOperator;
    int i, j = 0;
    int len = strlen(str);
    for (i = 0; i < len; i++)
    {
        if (str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-' || str[i] == '=')
        {
            operator[j] = str[i];
            j++;
        }
    }
    for (i = 0; FirstOperator != '=';i++)
    {
        cal = num[i];
        MidOperator = operator[i];
        while (MidOperator == '*' || MidOperator == '/')
        {
            if (MidOperator == '*')
            {
                cal *= num[i+1];
            }
            else if (MidOperator == '/')
            {
                cal /= num[i+1];
            }
            MidOperator = operator[i+1];
            i++;
        }
        if (FirstOperator == '+')
        {
            FirstCal += cal;
        }
        else if (FirstOperator == '-')
        {
            FirstCal -= cal;
        }
        FirstOperator = MidOperator;
    }
    return FirstCal;
}
