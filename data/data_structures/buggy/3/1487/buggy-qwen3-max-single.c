#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>


int main()
{
    char a[500];
    int i=0, j=0, len;
    
    gets(a); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings depending on compiler settings. Additionally, it can lead to buffer overflow vulnerabilities.]
    len = strlen(a);
    
    if(a[i] == '0')//零点几 
    {
        i=2; // @@ [This assumes the input always starts with "0." but does not validate that a[1] is '.'; if the input is just "0" or malformed like "00.123", this will access invalid indices or skip non-zero digits incorrectly.]
        
        while(a[i] == '0')
        {
            i++;
        }
        j=i-2; // @@ [If all digits after "0." are zero (which shouldn't happen per problem statement), this could result in printing no significant digit before decimal, violating scientific notation rules. Also, j calculation assumes fixed offset which may not hold for all valid inputs.]
        
        printf("%c.", a[i]); // @@ [If the input ends right after leading zeros (e.g., "0.0"), then a[i] would be '\0', leading to undefined behavior or printing garbage. Problem states there are significant digits, but code doesn't ensure i < len before accessing a[i].]
        
        i++;
        
        while(i<len)
        {
            printf("%c", a[i]);    
            i++;
        }
        
        printf("e-%d", j+1);
    }
    else if(a[i] != '0')//几点几 
    {
        printf("%c.", a[i]);
        i=1;
         
        while(a[i] != '.') // @@ [If the input has no decimal point (e.g., "123"), this loop runs past the string end, causing undefined behavior. The problem says input has digits before and after decimal point, but code doesn't validate presence of '.']
        {
            printf("%c", a[i]);
            i++;
        }
        j=i-1;
        
        i++;
        
        while(i<len)
        {
            printf("%c", a[i]);    
            i++;
        }
        printf("e%d", j);
    }
    return 0;
}