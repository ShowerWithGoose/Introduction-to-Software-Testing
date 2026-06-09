#include <stdio.h>
char str[10000];
int main()
{
    gets(str); // @@ [Using 'gets' is unsafe and has been removed from modern C standards; may cause compilation error if compiler enforces secure functions]
    int i=1,j;
    if(str[0]=='0')
    {
        for(i=2;str[i]=='0';i++); // @@ [Incorrect starting index: should start from i=1 or i=2 depending on whether '.' is at index 1; also fails to handle the decimal point correctly when counting leading zeros]
        if(str[i+1]=='\0') // @@ [Potential out-of-bounds access if 'i' reaches end of string; also logic flawed because it assumes a digit exists at 'i']
        {
            printf("%c",str[i]);
        }
        else
        {
            printf("%c.",str[i]);
            for(j=i+1;str[j]!='\0';j++)
            {
                printf("%c",str[j]);
            }    
            printf("e");
            printf("%d",i-1); // @@ [Exponent calculation is incorrect; does not account for position of decimal point and leading zeros properly]
        }
    }
    else if(str[1]=='.') // @@ [This condition assumes that if the second character is '.', then exponent is 0, but fails for numbers like "5.0" which should become "5e0", yet input guarantees no trailing zeros, so maybe acceptable—but logic doesn't cover all cases like single-digit integer without decimal]
    {
        for(i=0;str[i]!='\0';i++)
        {
            printf("%c",str[i]);
        }
        printf("e0");
    }
    else
    {
        for(i=0;str[i]!='.';i++); // @@ [Loop finds decimal point, but 'i' ends up being the index of '.', which is correct, but initial value of 'i' was set to 1 earlier—though reinitialized here, it's confusing]
        printf("%c.",str[0]);
        for(j=1;j<i;j++) // @@ [This prints digits between first digit and decimal point, but if there are none (e.g., "5.123"), this loop won't run—correct in that case—but overall structure may miscount exponent]
        {
            printf("%c",str[j]);
        }
        for(j=i+1;str[j]!='\0';j++)
        {
            printf("%c",str[j]);
        }
        printf("e");
        printf("%d",i-1); // @@ [Exponent should be (number of digits before decimal - 1), which is (i - 1) since 'i' is index of '.', so this might be correct—but only if input has more than one digit before decimal. However, problem states: "If there’s only one digit before the decimal point, it can be 0; otherwise, the first digit... cannot be 0." So this branch handles non-zero first digit with multiple digits before decimal. But what about "123"? No decimal point—this code would crash because loop 'for(i=0;str[i]!='.';i++)' runs past end of string]
    }
    return 0;
}