#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[100];
    int i,j;

    gets(str);
    for(i = 0;str[i] != '\0';i++){
        if(str[i] == '-'){
            if(str[i-1] <= 'Z' && str[i-1] >= 'A'&& str[i+1] <= 'Z' && str[i+1] >= 'A' && str[i-1] < str[i+1]){
                for(j = str[i-1] +1;j <= str[i+1];j++)
                    printf("%c",j);
            }
            else if(str[i-1] <= 'z' && str[i-1] >= 'a'&& str[i+1] <= 'z' && str[i+1] >= 'a' && str[i-1] < str[i+1])
                for(j = str[i-1] +1;j <= str[i+1];j++)
                    printf("%c",j);
            else if(str[i-1] <= '9' && str[i-1] >= '0'&& str[i+1] <= '9' && str[i+1] >= '0' && str[i-1] < str[i+1])
                for(j = str[i-1] +1;j <= str[i+1];j++)
                    printf("%c",j);
            else
                printf("-%c",str[i+1]);
            i++;
        }
        else
            printf("%c",str[i]);
    }

    return 0;
}

