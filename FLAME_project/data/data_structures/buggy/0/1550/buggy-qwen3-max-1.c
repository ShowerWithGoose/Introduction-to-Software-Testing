#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h> 

int main()
{
    char a[1000];
    gets(a); // @@ [Using gets() is unsafe and may cause buffer overflow; also, the reference uses scanf which stops at whitespace, while gets reads entire line—this may affect behavior but not the core logic error here. However, the main logical errors are below.]
    int i,j;
    for(i = 0; i < strlen(a); i++)
    {
        if(a[i] == '-')
        {
            if(islower(a[i + 1]) && islower(a[i - 1]) && fabs(a[i - 1] - a[i + 1]) >= 1) // @@ [Condition uses fabs(...) >= 1 which allows expansion even when a[i+1] < a[i-1], violating requirement that expansion only occurs when the character after '-' is greater than the one before. Also, accessing a[i-1] when i=0 leads to undefined behavior (out-of-bounds read).]
            {
                for(j = (int)a[i - 1] + 1; j < (int)a[i + 1]; j++)
                    printf("%c",j);
            }
            if(isupper(a[i + 1]) && isupper(a[i - 1]) && fabs(a[i - 1] - a[i + 1]) >= 1) // @@ [Same issue: fabs allows reverse ranges, and no check that a[i+1] > a[i-1]. Also, missing else-if chain causes multiple expansions or incorrect output when more than one condition could match (though unlikely due to type separation, still logically flawed).]
            {
                for(j = (int)a[i - 1] + 1; j < (int)a[i + 1]; j++)
                    printf("%c",j);
            }
            if(isdigit(a[i + 1]) && isdigit(a[i - 1]) && fabs(a[i - 1] - a[i + 1]) >= 1) // @@ [Same problem: should require a[i+1] > a[i-1], not just absolute difference >=1. Also, out-of-bounds access when i=0 or i at end.]
            {
                for(j = (int)a[i - 1] + 1; j < (int)a[i + 1]; j++)
                    printf("%c",j);
            }
            else
                printf("-"); // @@ [This else only pairs with the last 'if', not the whole group. So if first or second condition fails but third passes, it won't print '-', but if all fail, it prints '-'. However, if any of the first two conditions pass, and the third fails, it still prints the expansion AND then skips the else—but actually, because they are separate ifs, if none of the three ifs execute their body, then else runs. But the bigger issue is that the conditions are wrong (using fabs), so sometimes expansion happens when it shouldn't, and sometimes it doesn't print '-' when it should. Also, when expansion is valid, the '-' itself should not be printed, which is correct here—but when invalid, '-' is printed. However, due to using separate ifs instead of else-ifs, if one condition matches and expands, and another doesn't, it doesn't break control flow correctly. But in practice, a character can't be both digit and letter, so maybe not an issue. The real bug is fabs and boundary checks.]
        }
        else
            printf("%c",a[i]);
    }
    return 0;    
}