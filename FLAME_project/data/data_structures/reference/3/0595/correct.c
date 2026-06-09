#include <stdio.h>
#include <string.h>

int main()
{
    char str[200] = {0};
    int i,k,beg,end;

    gets(str);

    for(i = 0;str[i] != '\0';i++){
        if(str[i] == '.')
            k = i;
        if(str[i] <= '9' && str[i] > '0')
            end = i;
    }
    i = 0;
    while(str[i] > '9' || str[i] <= '0'){
        i++;
    }
    beg = i;

    if(beg == end)
        printf("%ce",str[beg]);
    else{
        printf("%c.",str[beg]);
        for(i = beg +1;i <= end;i++){
            if(str[i] != '.')
                printf("%c",str[i]);
        }
        printf("e");
    }
    if(k > beg)
        printf("%d",k - beg -1);
    else
        printf("%d",k - beg);

    return 0;
}

