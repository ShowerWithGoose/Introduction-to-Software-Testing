#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int i,j,n;
    char a[666]; 
    gets(a); // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error if compiler enforces secure functions. Also, 'gets' was removed in C11 standard.]
    n=strlen(a);
    for(i=1;i<=n;i++) // @@ [Loop starts at i=1 but accesses a[i] which may go out of bounds when i == n (since valid indices are 0 to n-1). This leads to undefined behavior and potential runtime/logic errors.]
    {
        int flag=0; // @@ [flag is reset to 0 on every iteration, so it cannot accumulate count of leading zeros as intended.]
        
        if(a[0]=='0')
        {
            if(a[i]=='0'||a[i]=='.') // @@ [Accessing a[i] when i may be equal to n (due to loop condition i<=n) causes out-of-bounds read. Also, '.' should not increment flag, but logic treats it same as '0'.]
            flag++; // @@ [This only increments once per iteration and is immediately overwritten next loop; doesn't count total leading zeros.]
            else if(a[i]>='1'&&a[i]<='9')
            {
                if(flag==n-1) // @@ [flag is always 0 or 1 here due to being reset each loop, so this condition will never be true as intended.]
                printf("%c",a[i]);
                else
                printf("%c.",a[i]);
                for(j=i+1;j<n;j++)
                {
                printf("%c",a[j]);
                
                }
                printf("e-%d",flag-1); // @@ [flag is not the correct count of leading zeros before the first non-zero digit; exponent will be wrong.]
                break;
            }
        }
        else
        {
            if(a[i]=='.') // @@ [Again, a[i] may be out-of-bounds when i == n. Also, loop starts at i=1, so if input has no decimal point, loop runs to i=n and accesses invalid memory.]
            {
                printf("%c.",a[0]);
                for(j=1;j<i;j++)
                {
                    printf("%c",a[j]);
                    
                } 
                for(j=i+1;j<n;j++)
                {
                    printf("%c",a[j]);
                    
                }
                printf("e%d",i-1);
                break;
                
            }
        }
    }
    return 0;        
}