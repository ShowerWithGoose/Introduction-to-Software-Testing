#include<stdio.h>

void expand(char p,char q)
{
    int i = 0;
    int k=p;
    for (i = 0; i <=(q - p); i++)
    {
        printf("%c", k);
        k++;
    }
}

int toexpand(char p, char q)
{
    if ((p >= 'a' && q <= 'z') || (p >= 'A' && q <= 'Z') || (p >= '0' && q <= '9')) // @@ [The condition is incorrect: it checks if p is in a range and q is in the same range but does not ensure both are of the same type or that p < q. Also, it allows mixed cases like p='a' and q='Z', which should not be expanded.]
        return 1;
    else
        return 0;
}
 
int main(void)
{
    char A[50] ;
    gets(A); // @@ [Use of unsafe function 'gets' which may cause buffer overflow; also, the logic for detecting '-' is flawed—it checks if the next character is '-', meaning it treats "a-b" as having '-' at index 1, but then uses A[i] and A[i+2], so it should check if A[i] == '-', not A[i+1]. This causes misalignment in processing.]
    int i = 0;
    int k = 0;
    while (A[i] != '\0')
    {
        if (A[i+1] == '-') // @@ [Incorrect condition: should check if current character A[i] is '-', not the next one. This leads to wrong expansion triggers and skipping characters.]
        {
            k = toexpand(A[i], A[i + 2]); // @@ [Because of the wrong condition above, A[i] is not the character before '-', but two positions before. This results in passing wrong characters to toexpand.]
            if (k == 1)
            {
                expand(A[i], A[i + 2]); // @@ [Same issue: expands from A[i] to A[i+2], but due to incorrect detection of '-', these are not the actual surrounding characters of '-'. Also, expand() prints the full range including endpoints, but the problem expects only the intermediate characters (e.g., a-d → abcd, but reference program prints only b,c). However, based on problem description, full expansion including endpoints is expected, so this might be acceptable—but combined with wrong indices, it's erroneous.]
                i = i + 2; // @@ [Skipping only 2 characters after processing a '-' pattern starting at i, but because the '-' was detected at i+1, this leads to incorrect pointer advancement and possible reprocessing or skipping of characters.]
            }
            if(k==0)
                printf("%c",A[i]); // @@ [If expansion is invalid, it prints only A[i], but doesn't print the '-' or A[i+2], leading to missing characters in output.]
        }
        else
            printf("%c", A[i]);
        i++;
    }
    return 0;
}