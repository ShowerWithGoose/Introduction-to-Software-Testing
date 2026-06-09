#include<stdio.h>
#include<string.h>
#include<iostream> // @@ This is a C++ header and will cause a compilation error in a standard C compiler; it should be removed.
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
    while(~fscanf(in, "%s", str)) // @@ Using bitwise NOT on fscanf's return value is non-standard and unsafe; should check for EOF or successful read count.
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
            if(state > 0) // @@ Missing null-terminator assignment (data[i][j] = '\0';) before incrementing i, causing undefined behavior in strcmp and printf.
            {
                i++;
            }
        }    
    }
    fclose(in);
    qsort(id, i, sizeof(id[0]), cmp);
    printf("%s ", data[id[0]]); // @@ Incorrect output format; does not match "word count\n" requirement and will crash if file is empty (i==0).
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
            printf("%d\n%s ", s, data[id[k]]); // @@ Incorrect output format and order; prints count before word and misses required newline at the end of each line.
            s = 1;
        }
    }
    if(site == 0)
    {
        printf("1"); // @@ Missing newline character at the end of output, violating the output format specification.
    }
    else
    {
        printf("%d", s); // @@ Missing newline character at the end of output, violating the output format specification.
    }
    return 0 ;
}