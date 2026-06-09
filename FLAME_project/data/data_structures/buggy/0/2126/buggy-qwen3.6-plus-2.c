#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int  main()
{   
    char ch[1000],a,b,n;
    gets(ch);
    int i;
    for(i=0;i!=strlen(ch);i++)
    {
        if(ch[i]=='-')
        {
        a=ch[i-1],b=ch[i+1];
        if(((a>='a'&&a<='z')&&(b>='a'&&b<='z'))||((a>='A'&&a<='Z')&&(b>='A'&&b<='Z'))||((a>='0'&&a<='9')&&(b>='0'&&b<='9'))) // @@ [Error: The condition (a>=0&&a<=9) checks if the ASCII value of character 'a' is between 0 and 9, which is incorrect for digit characters. It should check if the character is between '0' and '9'.]
        {
            if(a<b)
            for(n=a+1;n>a&&n<b;n++){ // @@ [Error: The loop condition n<a is false immediately if n starts at a+1, but the logic n>b is also problematic. More importantly, the loop prints characters from a+1 up to b-1. It misses printing 'b' itself if the requirement is inclusive, or it might be correct depending on interpretation. However, the main issue in the previous line is the digit check. Let's look closer. The problem says expand a-d to abcd. So it includes start and end. The code prints ch[i-1] before hitting '-', then inside the if, it prints a+1 to b-1. Then it will print b in the next iteration of the outer loop when i advances. Wait, if i is at '-', next iteration i++ moves to b. So b is printed later. This seems logically okay for inclusion IF the digit check was correct. But wait, if the digit check fails, it prints "-". If it passes, it doesn't print "-", but relies on subsequent iterations. This structure is fragile but might work if the digit check is fixed. However, there is another subtle bug: if a >= b, it does nothing inside, and then the '-' is not printed? No, if a>=b, the inner if(a<b) fails, so nothing is printed for the '-' case here. The '-' itself is skipped. This is wrong. If no expansion happens (e.g. a>=b or different types), the '-' should be printed. The else branch prints "-" only if the type check fails. If type check passes but a>=b, nothing is printed for the '-'. This is a logical error.]
            printf("%c",n);
            }
        }    
        else printf("-");    
        }
        else{
              n=ch[i];
              printf("%c",n);
        }
    }
    return 0;
}