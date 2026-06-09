#include <stdio.h>
#include <string.h>

int reve(char *p,int beg,int end)
{
    int i,ans = 0;

    for(i = beg;i <= end;i++){
        ans = ans* 10 + p[i] - '0';
    }

    return ans;
}

int main()
{
    char str[200];
    int i,j,flag = 0,n = 0;
    int a[100] = {0};

    gets(str);
    for(i = 0,j = 0;str[i] != '\0';i++){
        if(str[i] != ' ')
            str[j++] = str[i];
    }
    str[j] = '\0';

    for(i = 0,j = 0;str[i] != '\0';i++){
        if(str[i] == '+' || str[i] == '-' || str[i] == '=' || str[i] == '*' || str[i] == '/'){
            a[j++] = reve(str,flag,i-1);
            flag = i+1;
        }
    }
    for(i = 0;str[i] != '\0';i++){
        if(str[i] == '*'){
            a[n+1] = a[n] * a[n+1];
            a[n] = 0;
            n++;
        }
        else if(str[i] == '/'){
            a[n +1] = a[n] / a[n+1];
            a[n] = 0;
            n++;
        }
        else if(str[i] == '+' || str[i] == '-')
            n++;
    }
    for(i = 0,n=0;str[i] != '=';i++){
        if(str[i] == '+'){
            j = n+1;
            while(a[j] == 0){
                j++;
            }
            a[j] = a[n] + a[j];
            a[n] = 0;
            n++;
        }
        else if(str[i] == '-'){
            j = n+1;
            while(a[j] == 0){
                j++;
            }
            a[j] = a[n] - a[j];
            a[n] = 0;
            n++;
        }
        else if(str[i] == '*' || str[i] == '/')
            n++;
    }

    printf("%d",a[n]);
    return 0;
}



