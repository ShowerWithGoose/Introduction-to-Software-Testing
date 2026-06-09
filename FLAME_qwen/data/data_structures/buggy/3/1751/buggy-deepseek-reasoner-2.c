#include<stdio.h>
#include<string.h>
int main()
{
    char num[105];
    char num1[105],num2[105];
    gets(num);
    int i=0,j=0;
    for(i=0,j=0;num[i]!='\0';i++)
    {
        if(num[i]!='.')
        {
            num1[j++]=num[i];
        }
        else
        {
            break;
        }
    }
    // num1 is not null-terminated after the loop (unless the loop exits due to string end or break)
    // The next line uses strlen on num1, which will read past the written characters until a null byte is found.
    // This is undefined behavior and can cause incorrect length or crash.
    int a=(int)strlen(num1); // @@ Missing null terminator in num1; strlen may read garbage.
    for(i+=1,j=0;num[i]!='\0';i++)
    {
        num2[j++]=num[i];
    }
    // num2 is also not null-terminated.
    if(a==1)
    {
        if(num1[0]!='0')
        {
            for(i=0;num[i]!='\0';i++)
            {
                printf("%c",num[i]);
            }
            printf("e0");
        }
        else if(num1[0]=='0')
        {
            // This loop relies on num2 being null-terminated, but it is not.
            for(i=0;num2[i]!='\0';i++) // @@ num2 is not null-terminated; loop may overrun.
            {
                if(num2[i]!='0')
                {
                    break;
                }
            }
            int k=i;
            printf("%c",num2[k]);
            if(num2[k+1]!='\0')
            {
                printf(".");
            }
            // This loop also relies on num2 null terminator.
            for(i+=1;num2[i]!='\0';i++) // @@ num2 not null-terminated; loop may overrun.
            {
                printf("%c",num2[i]);
            }
            printf("e-%d",k+1);
        }
    }
    else
    {
        printf("%c.",num1[0]);
        // This loop relies on num1 being null-terminated, but it is not.
        for(i=1;num1[i]!='\0';i++) // @@ num1 not null-terminated; loop may overrun.
        {
            printf("%c",num1[i]);
        }
        // This loop relies on num2 being null-terminated.
        for(i=0;num2[i]!='\0';i++) // @@ num2 not null-terminated; loop may overrun.
        {
            printf("%c",num2[i]);
        }
        printf("e%d",a-1);
    }
    return 0;
}