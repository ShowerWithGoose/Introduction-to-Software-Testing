#include<stdio.h>
#include<string.h>
#include<iostream> // @@ Compilation Error: The header <iostream> is a C++ header and is not valid in standard C. It causes the "No such file or directory" error or compilation failure when using a C compiler. It should be removed or replaced with appropriate C headers if needed (though none are needed here as stdio.h and string.h are already included).
#include<stdlib.h>//先q 后判重归类
char str[105], data[105][20];
int id[105];
int cmp(const void*p, const void*q)
{
    int a = *(int*)p;
    int b = *(int*)q;
    return strcmp(data[a], data[b]);
}
int main()
{
    FILE*in;
    in = fopen("article.txt", "r");
    int n, j = 0, i = 0, state, len, s = 1, site = 0, k;
    while(~fscanf(in, "%s", str))
    {
        len = strlen(str);
        for(n = 0; n < len; n++)
        {
            j = 0;
            state = 0;
            while(isalpha(str[n]))
            {
                state = 1;
                data[i][j] = tolower(str[n]);
                n++;
                id[i] = i;
                j++;
            }
            if(state > 0)
            {
                i++;
            }
        }    
    }
    fclose(in);
    qsort(id, i, sizeof(id[0]), cmp);
    printf("%s ", data[id[0]]);
    for(k = 1; k < i; k++)
    {
        if(strcmp(data[id[k]], data[id[k-1]]) == 0)
        {
            site = 1;
            s++;
        }
        else
        {
            site = 0;
            printf("%d\n%s ", s, data[id[k]]);
            s = 1;
        }
    }
    if(site == 0)
    {
        printf("1");
    }
    else
    {
        printf("%d", s);
    }
    return 0 ;
}