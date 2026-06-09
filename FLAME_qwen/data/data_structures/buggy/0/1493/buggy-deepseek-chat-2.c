#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
int main()
{
    int i;
    char a[1006], j;

    gets(a);
    
    printf("%c", a[0]); // @@ [Error: This line assumes the string is non-empty, but if the input is empty, it will cause undefined behavior. Also, the reference program does not pre-print the first character; it prints all characters in the loop. This changes the logic: if the first character is part of an expansion (e.g., "a-d"), it will be printed twice (once here and once in the loop), leading to incorrect output.]
    for(i=1;a[i]!='\0';i++)
    {
        if(a[i]=='-'&&a[i-1]<a[i+1]) // @@ [Error: The condition a[i-1] < a[i+1] is insufficient. It does not check that both characters are of the same type (e.g., both lowercase, both uppercase, or both digits). For example, "a-9" would incorrectly attempt expansion because 'a' < '9' is true, but they are different types. The reference program checks both type and range properly.]
        {
            if(a[i-1]>='a'&&a[i+1]<='z') // @@ [Error: This condition only checks that the start is >= 'a' and the end is <= 'z', but it does not ensure both are lowercase letters. For example, "a-Z" would pass because 'a' >= 'a' and 'Z' <= 'z' is false, but "a-z" works. However, it misses the case where the start is lowercase and the end is also lowercase but the start is greater than the end (e.g., "z-a"), which should not expand. The reference program checks a[i+1] > a[i-1] separately.]
        {
            for(j=a[i-1]+1;j<a[i+1];j++)
            {
                printf("%c", j);
            }
        }
        else if(a[i-1]>='A'&&a[i+1]<='Z') // @@ [Error: Similar issue as above; does not ensure both are uppercase letters. For example, "A-z" would incorrectly pass because 'A' >= 'A' and 'z' <= 'Z' is false, but "A-Z" works. Also missing the start > end check.]
        {
            for(j=a[i-1]+1;j<a[i+1];j++)
            {
                printf("%c", j);
            }
        }
        else if(a[i-1]>='0'&&a[i+1]<='9') // @@ [Error: Similar issue; does not ensure both are digits. For example, "0-9" works, but "0-a" would fail because 'a' <= '9' is false. However, it misses cases like "9-0" which should not expand.]
        {
            for(j=a[i-1]+1;j<a[i+1];j++)
            {
                printf("%c", j);
            }
        }
        }
        
        else
        {
            printf("%c", a[i]);
        }
        
    }
    
    
    return 0;
}