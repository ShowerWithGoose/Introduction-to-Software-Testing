#include<stdio.h>
#include<string.h>
int main()
{
    char fm[100];


    scanf("%s",&fm); // @@ [Error: Should be 'scanf("%s", fm);' because fm is an array; &fm is of wrong type and may cause undefined behavior.]
    int i,j;
    for(i=0;i<strlen(fm);i++) // @@ [Error: Missing bounds check for fm[i-1] and fm[i+1]; when i==0 or i==strlen(fm)-1, out-of-bounds access occurs.]
    {

        if(fm[i]=='-'&&fm[i-1]<fm[i+1]) // @@ [Error: No check that i-1>=0 and i+1<strlen(fm); this can lead to accessing invalid memory.]
        {
            if(('a'<=fm[i-1]&&fm[i-1]<='z'&&'a'<=fm[i+1]&&fm[i+1]<='z')||('A'<=fm[i-1]&&fm[i-1]<='Z'&&'A'<=fm[i+1]&&fm[i+1]<='Z')||('0'<=fm[i-1]&&fm[i-1]<='9'&&'0'<=fm[i+1]&&fm[i+1]<='9'))
            {
                for(j=1;j<=fm[i+1]-fm[i-1];j++)
                {
                    printf("%c",'fm[i-1]'+j); // @@ [Error: 'fm[i-1]' is a multi-character literal; should be fm[i-1] + j.]
                }
                continue; // @@ [Error: Logical error - after printing the expansion (inclusive of the end character), the next iteration will print the end character again, causing duplication. Should also skip the end character by e.g., incrementing i after continue or not printing it in the expansion.]
            }
            else
            {

            }
        }
        printf("%c",fm[i]); // @@ [Error: When expansion occurred (via continue), this line prints the end character of the range again, causing duplicate output.]
    }
    return 0;
}