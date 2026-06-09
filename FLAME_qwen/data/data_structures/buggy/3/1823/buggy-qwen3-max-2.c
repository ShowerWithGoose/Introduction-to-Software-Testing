#include<stdio.h>
#include<string.h>
int main()
{
    char s[105]={'\0'};
    gets(s); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings with modern compilers.]
    int n=strlen(s);
    if(s[0]=='0')
    {
        int x=0,y=2;
        while(s[y]=='0')
        {
            x++;
            y++;
        }
        char *p=s+y+1; // @@ [If the input is like "0.001", then y becomes 3 (index of '1'), and p points to s[4], which is beyond the last digit, resulting in printing garbage or empty string. Also, if the number ends right after the first non-zero digit (e.g., "0.001"), p points to '\0', so ".%s" prints nothing, violating the requirement of having one digit after decimal when base is decimal.]
        printf("%c.%se-%d",s[y],p,x+1);
    }
    else if(s[0]!='0')
    {
        printf("%c.",s[0]);
        int x=0,y=1;
        while(s[y]!='.')
        {
            printf("%c",s[y]);
            x++;
            y++;
        }
        printf("%se%d",s+y+1,x); // @@ [This prints all digits after the decimal point directly without checking for trailing zeros, but problem states there are no trailing zeros, so this may be acceptable. However, if there are no digits after the decimal point (though problem says there are), this would print garbage. More critically, if the number has only one digit before the decimal (like "5.67"), it should output "5.67e0", but this outputs "5.67e0" correctly. However, the bigger issue is that the program assumes there is always a decimal point, which is guaranteed by the problem, so this line may not be erroneous per se. But combined with logic above, the main error is in handling the '0.xxx' case.]
    }
    return 0;
}