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
    
    printf("%c", a[0]); // @@ [Error: This line prints the first character unconditionally, but if the input string is empty or the first character is part of a valid expansion (e.g., "a-c"), it will be printed twice because the loop also prints it. Additionally, if the first character is '-' (e.g., "-a"), it will be printed incorrectly. The reference program handles this by checking each character in the loop without pre-printing.]
    for(i=1;a[i]!='\0';i++)
    {
        if(a[i]=='-'&&a[i-1]<a[i+1]) // @@ [Error: The condition `a[i-1]<a[i+1]` is insufficient; it does not check that both characters are of the same type (e.g., lowercase, uppercase, or digit). For example, "a-9" would incorrectly attempt expansion because 'a' < '9' is true, but they are different types. The reference program checks type ranges explicitly.]
        {
            if(a[i-1]>='a'&&a[i+1]<='z') // @@ [Error: This condition only checks that the start is >= 'a' and end is <= 'z', but does not ensure both are lowercase letters. For example, "a-Z" would pass because 'a' >= 'a' and 'Z' <= 'z' is false, but "a-z" works. However, it misses cases like "a-9" where a[i-1] is lowercase and a[i+1] is a digit, which should not expand. The reference program uses `a[i-1]>='a' && a[i-1]<='z' && a[i+1]>='a' && a[i+1]<='z'` to ensure both are lowercase.]
        {
            for(j=a[i-1]+1;j<a[i+1];j++)
            {
                printf("%c", j);
            }
        }
        else if(a[i-1]>='A'&&a[i+1]<='Z') // @@ [Error: Similar issue; this only checks start >= 'A' and end <= 'Z', but does not ensure both are uppercase. For example, "A-z" would incorrectly pass because 'A' >= 'A' and 'z' <= 'Z' is false, but "A-Z" works. It should check both are uppercase letters.]
        {
            for(j=a[i-1]+1;j<a[i+1];j++)
            {
                printf("%c", j);
            }
        }
        else if(a[i-1]>='0'&&a[i+1]<='9') // @@ [Error: Similar issue; this only checks start >= '0' and end <= '9', but does not ensure both are digits. For example, "0-9" works, but "0-a" would incorrectly pass because '0' >= '0' and 'a' <= '9' is false. It should check both are digits.]
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