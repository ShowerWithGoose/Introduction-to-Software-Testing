#include<stdio.h>
#include<string.h>
int main(void)
{
    
    char s[110];
    while(gets(s)!=NULL)
    {
        int num=0,isok=0;
        int a=0,b=0;
        for(int i=0;i<strlen(s);i++)
        {
            if(s[i]=='.')
            {
            isok=1;
            }
        }
        if(isok)
        {
            for(int i=0;i<strlen(s)&&s[i]!='.';i++,num++);
        
            b=num;
            if(s[num-1]=='0') @@ // This condition checks if the last digit before '.' is '0', but it should check if the *first* digit (s[0]) is '0' to determine if the number is less than 1 (e.g., "0.9"). For input "0.9", s[0]=='0', but s[num-1] is also '0' (since num=1), so this branch is taken incorrectly.
            {
                for(int i=num+1;(i<strlen(s))&&(s[i]=='0');i++)
                {
                    a++;
                }
            
            printf("%c",s[a+2]); @@ // For "0.9", num=1, a=0, so s[a+2] = s[2] = '9' — correct digit, but logic is fragile and based on wrong assumption.
                if(a+2!=strlen(s))
                {
                    printf(".");
                for(int i=a+3;i<strlen(s);i++)
                {
                    printf("%c",s[i]);
                }
                }
            printf("e-%d",a+1); @@ // For "0.9", prints "9.e-1" because the '.' is printed when a+2 != strlen(s). But since there are no digits after '9', it should not print '.' at all. The condition a+2 != strlen(s) is true (2 != 3? Actually, "0.9" has length 3: '0','.','9','\0' → strlen=3, a+2=2, so 2 != 3 → true → prints '.', leading to "9." instead of "9".
            }
            else
            {
                printf("%c.",s[0]);
                for(int i=1;i<strlen(s);i++)
                {
                    if(s[i]!='.')
                    printf("%c",s[i]);
                }
                printf("e%d",b-1);

            }
        }
        else 
        {
            printf("%c.",s[0]);
                for(int i=1;i<strlen(s);i++)
                {
                    printf("%c",s[i]);
                }
                printf("e%d",strlen(s)-1);
        }
    }
    return 0;
}