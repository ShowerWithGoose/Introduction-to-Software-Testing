#include<stdio.h>
#include<string.h>
int main()
{
    char c[100];
    gets(c);
    int num=0,flag=0,i=0,judge=0;
    if(strlen(c)==1)
    {
        printf("%c",c[0]);
        printf("e0");
    }
    else
    {
        if(c[0]=='0')
        {
            for(num=1,i=2;c[i]=='0';i++) // @@ The loop starts from i=2, but for numbers like "0.1", the first non-zero digit is at index 2, which is correct. However, the loop condition c[i]=='0' will skip all zeros, but the exponent calculation is wrong because it doesn't account for the decimal point position correctly. Also, the loop should start from i=1 to find the first non-zero digit after the decimal point.
                num++;
            while(c[i]!='\0')
            {
                if(judge==1)
                    printf(".");
                judge++;
                printf("%c",c[i]);    
                i++;
            }
            printf("e-%d",num); // @@ The exponent should be -(number of zeros after decimal point before first non-zero digit), but the calculation of num is incorrect. For input "0.001", num should be 3, but the loop starts at i=2 and counts zeros, missing the initial zero count.
        }
        else
        {
            while(c[i]!='.'&&c[i]!='\0')
            {
                if(judge==1)
                    printf(".");
                judge++;
                printf("%c",c[i]);
                i++;
            }
            if(c[i]=='\0')
            {
                printf("e%d",judge-1); // @@ For integer inputs like "123", this prints "123e2" but should print "1.23e2". The code does not handle the decimal point insertion correctly for integers.
            }
            else
            {
                printf("."); 
                for(i++;c[i]!='\0';i++)
                {
                    printf("%c",c[i]);
                }
                printf("e%d",judge-1); // @@ For inputs like "12.34", this prints "12.34e1" but should print "1.234e1". The code does not correctly place the decimal point after the first digit.
            }
        }
    }
        

    return 0;
}