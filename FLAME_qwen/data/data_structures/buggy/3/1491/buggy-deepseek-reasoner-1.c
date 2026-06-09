#include<stdio.h>
#include<string.h>
char a[100005],b[100005];
int main()
{
    gets(a);
    int i=0,j=0,k=0;
    int p;
    for(i=0;i<strlen(a);i++)
    {
        if(a[i]=='.')
        {
            p=i;
            break;
        }
    }
    if(p==1)
    {
        if(a[0]!='0')
        {
            for(i=0;i<strlen(a);i++)
            {
                printf("%c",a[i]);
            }
                printf("e0");
        }
        else
        {
            for(i=2;i<strlen(a);i++)
            {
                if(a[i]!='0')
                {
                    k=i;
                    break;
                }
            }
            for(i=k;i<strlen(a);i++)
            {
                b[j]=a[i];
                j++;
            }
            if(k!=strlen(a)-1)
            {
                printf("."); @@ This prints a dot before all digits copied to b, but the dot should appear after the first digit (b[0]). Correct placement would be: print b[0], then a dot, then the remaining digits.
            }
            for(i=0;i<strlen(b);i++) @@ Using strlen(b) here is incorrect because b has not been null-terminated after the copy loop. This leads to undefined behavior (reading past the assigned characters). A null terminator should be added before using strlen.
            {
                printf("%c",b[i]);
            }
            printf("e");
            printf("%d",-(k-1));
        }
    
    }
    else
    {
        for(i=0;i<strlen(a);i++)
        {
            if(a[i]!='.')
            {
                b[j]=a[i];
                j++;
            }
            
        }
        printf("%c",b[0]);
        printf(".");
        for(i=1;i<strlen(b);i++) @@ Using strlen(b) here is incorrect because b has not been null-terminated after the copy loop. This leads to undefined behavior. A null terminator should be added before using strlen.
        {
            printf("%c",b[i]);
        }
        printf("e");
        printf("%d",p-1);
    }
    return 0;
    
}