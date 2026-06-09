#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int i,j,n;
    char a[666]; 
    gets(a); // @@ [Use of unsafe function 'gets' which is deprecated and may cause buffer overflow; also, in some environments, this leads to compilation error if compiler enforces secure functions]
    n=strlen(a);
    for(i=1;i<=n;i++) // @@ [Loop starts at i=1 but accesses a[i] which may go out of bounds when i == n (since valid indices are 0 to n-1)]
    {
        int flag=0;
        
        if(a[0]=='0')
        {
            if(a[i]=='0'||a[i]=='.') // @@ [When i == n, a[i] is '\0', leading to undefined behavior; also, flag logic is flawed as it's reset every loop iteration]
            flag++;
            else if(a[i]>='1'&&a[i]<='9')
            {
                if(flag==n-1) // @@ [flag is always 0 or 1 due to being reset each iteration, so this condition will never be true as intended]
                printf("%c",a[i]);
                else
                printf("%c.",a[i]);
                for(j=i+1;j<n;j++)
                {
                printf("%c",a[j]);
                
                }
                printf("e-%d",flag-1); // @@ [flag is not counting leading zeros correctly; it should count positions before the first non-zero digit]
                break;
            }
        }
        else
        {
            if(a[i]=='.') // @@ [Again, a[i] may be out of bounds when i == n]
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