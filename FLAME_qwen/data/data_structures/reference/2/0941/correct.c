#include <stdio.h>
#include <string.h>
#include<stdlib.h>
int main()
{
    int i,j,op=0;
    char str[100];
    gets(str);
    int len = strlen(str);
    for(i=0,j=0;i<len;i++){
        if((str[i]<='9'&&str[i]>='0')||str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='='){
            str[j] = str[i];
            j++;
        }
    }//delete the \0
    len = strlen(str);
    int num[50];//stack_num
    char cal[50];//stack_char
    for(i = 0,j = 0;i < len;i++){
        if(str[i] >= '0' && str[i] <= '9'){
            num[j] = str[i] - '0';
            int k = 1;
            while(str[i+k] >= '0' && str[i+k] <= '9'){
                num[j] *= 10;
                num[j] += str[i+k] - '0';
                k++;
            }
            i += k;
            j++;
        }
            cal[op] = str[i];
            op++;
    }
    op--;
    int k;
    for(i = 0;op != 0;){
        if(cal[i] == '=') break;
        switch (cal[i])
        {
        case '*':
            num[i] = num[i] * num[i+1];
            for(k = i+1;k < j-1;k++){
                num[k] = num[k+1];
                cal[k-1] = cal[k];
            }
            op--;
            j--;
            break;
        case '/':
            num[i] = num[i] / num[i+1];
            for(k = i+1;k < j-1;k++){
                num[k] = num[k+1];
                cal[k-1] = cal[k];
            }
            op--;
            j--;
            break;
        default:
            i++;
            break;
        }
    }
    for(i = 0;op != 0;){
        if(cal[i] == '=') break;
        switch (cal[i])
        {
        case '+':
            num[i] = num[i] + num[i+1];
            for(k = i+1;k < j-1;k++){
                num[k] = num[k+1];
                cal[k-1] = cal[k];
            }
            op--;
            j--;
            break;
        case '-':
            num[i] = num[i] - num[i+1];
            for(k = i+1;k < j-1;k++){
                num[k] = num[k+1];
                cal[k-1] = cal[k];
            }
            op--;
            j--;
            break;
        default:
            i++;
            break;
        }
    }
    printf("%d",num[0]);
    system("pause");
    return 0;
}
