#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h> 

int main()
{
    char a[1000];
    gets(a); // @@ [Using 'gets' is unsafe and deprecated; however, the primary error causing compilation failure is the use of 'fabs' without proper handling of integer types and potential missing linking of math library, but more critically: 'fabs' returns double, and comparing it with >=1 for character differences is logically flawed and may cause unexpected behavior. Also, multiple 'if' statements instead of 'else if' cause overlapping expansions and incorrect output. Additionally, accessing a[i-1] when i=0 leads to out-of-bound read.]
    int i,j;
    for(i = 0; i < strlen(a); i++)
    {
        if(a[i] == '-')
        {
            if(islower(a[i + 1]) && islower(a[i - 1]) && fabs(a[i - 1] - a[i + 1]) >= 1) // @@ [Using 'fabs' on integer character values is unnecessary and incorrect; should compare directly (e.g., a[i+1] > a[i-1]). Also, when i=0, a[i-1] accesses a[-1], which is undefined behavior.]
            {
                for(j = (int)a[i - 1] + 1; j < (int)a[i + 1]; j++)
                    printf("%c",j);
            }
            if(isupper(a[i + 1]) && isupper(a[i - 1]) && fabs(a[i - 1] - a[i + 1]) >= 1) // @@ [Same issues: 'fabs' misuse, no check that a[i+1] > a[i-1], and potential out-of-bounds access when i=0 or i at end. Also, using separate 'if' instead of 'else if' causes multiple expansions if conditions overlap (though unlikely here, still logically wrong).]
            {
                for(j = (int)a[i - 1] + 1; j < (int)a[i + 1]; j++)
                    printf("%c",j);
            }
            if(isdigit(a[i + 1]) && isdigit(a[i - 1]) && fabs(a[i - 1] - a[i + 1]) >= 1) // @@ [Same 'fabs' and boundary issues. Also, condition should ensure a[i+1] > a[i-1], not just absolute difference >=1 (e.g., '5-3' would have |'5'-'3'|=2>=1 but should NOT expand).]
            {
                for(j = (int)a[i - 1] + 1; j < (int)a[i + 1]; j++)
                    printf("%c",j);
            }
            else
                printf("-"); // @@ [This 'else' only pairs with the last 'if', so if the first or second 'if' matches but the third doesn't, it incorrectly prints '-' anyway. Should use 'else if' chain and final 'else'.]
        }
        else
            printf("%c",a[i]);
    }
    return 0;    
}