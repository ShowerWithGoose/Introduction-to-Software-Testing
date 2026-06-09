#include<stdio.h>
#include<string.h>
int main()
{
    char c[101],a;
    int i,n,e=0,m;
    gets(c);
    for(i=0;i<strlen(c);i++)
    {
        if(c[i]=='.')
        n=i;
         
    }
    if(strlen(c)==1)
    {
        printf("%ce0",c[0]);
    }
    else if(strlen(c)==3&&c[0]=='0')
    {
        printf("%ce-1",c[2]); @@ [This handles only the specific case "0.x" with one digit after decimal, but fails for longer inputs like "0.000...x"]
    }
    else
    {
        if(c[0]!='0')
        {
            e=n-1;
            for(i=n;i>1;i--)
            {
                c[i]=c[i-1];
            
            }
        
            c[1]='.';
            for(i=0;i<strlen(c);i++)
            {
                printf("%c",c[i]);
                
            }
            printf("e%d",e);
        }
        else
        {
            for(i=n+1;i<strlen(c);i++)
            {
                if(c[i]!='0')
                {
                    m=i;
                    e=m-n;
                    break;
                }
        
            }
            i=n+1;
            if(c[i++]=='0') @@ [This condition is flawed: it checks only the first digit after decimal again and assumes it's zero, but 'i' was already incremented in the loop above; also logic doesn't handle cases where all digits after decimal are zero (though problem states there are no trailing zeros, so at least one non-zero exists)]
            {
                printf("%ce0",c[n]); @@ [This prints '.' as base if input is like "0.0...", which is invalid scientific notation]
            }
            else
            {
                printf("%c.",c[m]);
        
                for(i=m+1;i<strlen(c);i++)
                {
                    printf("%c.",c[i]); @@ [Incorrectly prints a '.' after every digit instead of just once after the first significant digit]
                
                }
                printf("e-%d",e); @@ [Exponent should be negative of (m - n), but here 'e = m - n' is positive, so should be 'e = -(m - n)' or print 'e-%d' with correct magnitude; however, note that in this branch e = m - n, and since m > n, exponent is positive, but it should be negative because we're moving left from decimal point. So actual exponent is -(m - n) + 1? Let's see: for "0.0009", first non-zero at index 4 (0-based: '0','.','0','0','0','9'), n=1, m=5, so digits moved: from position 5 to position 0 => exponent = -4. But m - n = 4, so exponent = -(m - n) + 1? No: number of places to move = (m - n - 1). Actually, correct exponent = -(m - n - 1 + 1) = -(m - n). Wait: 0.0009 = 9e-4. Here, n=1 (index of '.'), m=5 (index of '9'), so m - n = 4, and exponent is -4. So printing "e-%d" with e = m - n is correct. BUT the issue is that in the code, after finding m, e = m - n, and then it prints "e-%d", so that part is okay. However, the main errors are in printing extra dots and handling the base incorrectly.]
                
            }
        
        }
    }
    return 0;
}