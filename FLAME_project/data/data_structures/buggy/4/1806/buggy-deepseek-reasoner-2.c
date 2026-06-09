#include<stdio.h>
#include<string.h>
#include<iostream> // @@ Error: iostream is a C++ header, not available in C. Should be removed or replaced with standard C headers.
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
    while(~fscanf(in, "%s", str)) // @@ Error: Using bitwise NOT on fscanf return is non-standard; use while(fscanf(...) == 1) for portability.
    {
        len = strlen(str);
        for(n = 0; n < len; n++)
        {
            j = 0;
            state = 0;
            while(isalpha(str[n])) // @@ Error: isalpha and tolower require <ctype.h> which is not included. Add #include<ctype.h>.
            {
                state = 1;
                data[i][j] = tolower(str[n]); // tolower also needs <ctype.h>
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
    printf("%s ", data[id[0]]); // @@ Error: Output format incorrect. Should print count after word, not just a trailing space.
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
            printf("%d\n%s ", s, data[id[k]]); // @@ Error: This printf produces an extra newline before the count and may cause formatting issues.
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