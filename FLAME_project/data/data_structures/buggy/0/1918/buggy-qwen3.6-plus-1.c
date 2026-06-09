#include<stdio.h>
#include<string.h>
char ch[1000];
int main()
{
    scanf("%s",ch);
    int len=strlen(ch),i=0,lon,j=0;
    for(;i<len;i++)
    {
        if(ch[i]=='-')
        {
            if((ch[i-1]>='a'&&ch[i+1]<='z')||(ch[i-1]>='A'&&ch[i+1]<='Z')||(ch[i-1]>='0'&&ch[i+1]<='9')) // @@ The condition checks if the start char is >= min and end char is <= max of a range, but fails to ensure they are of the SAME type (e.g., 'B' is >= 'a' is false, but 'B' >= 'A' is true and 'e' <= 'Z' is false. However, for 'B-e': 'B'>='A' is true, 'e'<='Z' is false. Wait. 'B' is 66, 'e' is 101. 'B'>='A' (true) AND 'e'<='Z' (false). So this specific case might pass the type check logic incorrectly in other scenarios or fail here. Let's look closer. The condition `(ch[i-1]>='a'&&ch[i+1]<='z')` allows mixed types if one falls in lowercase range bounds? No. It checks if left is lowercase AND right is lowercase. But it doesn't check if left is ALSO <= 'z' or right is ALSO >= 'a'. More importantly, it doesn't enforce that BOTH are lowercase. It enforces left is lowercase-ish and right is lowercase-ish. Actually, the main error is that it doesn't check if they are the SAME category strictly. For 'B-e': `ch[i-1]` is 'B'. `ch[i-1]>='a'` is false. `ch[i-1]>='A'` is true. `ch[i+1]<='Z'` is false ('e' > 'Z'). So the second part `(ch[i-1]>='A'&&ch[i+1]<='Z')` is false. The third part `(ch[i-1]>='0'&&ch[i+1]<='9')` is false. So the `if` body is NOT entered. This means it goes to `else printf("%c",ch[i])` which prints '-'. Then the loop continues. 'e' is printed. Output: "B-e". Wait, the buggy output is "Be". Why?
            
            Let's re-read the code logic.
            If `ch[i] == '-'`:
               Check condition. If true, print expanded chars. If false, do NOTHING inside the if block?
               Ah, look at the structure:
               `if (condition) { ... }`
               There is NO `else` for the inner if.
               So if the condition is false, it prints nothing for the '-'.
               
               Let's trace 'B-e'.
               i=0: 'B'. Not '-'. Prints 'B'.
               i=1: '-'. Is '-'.
               Condition: `( 'B'>='a' && 'e'<='z' )` -> False.
               `( 'B'>='A' && 'e'<='Z' )` -> True && False -> False.
               `( 'B'>='0' && 'e'<='9' )` -> False.
               Condition is false.
               The code inside `if(ch[i]=='-')` executes the inner `if`. Since inner `if` is false, it does nothing.
               It does NOT print '-'.
               
               i=2: 'e'. Not '-'. Prints 'e'.
               
               Result: "Be".
               
               Expected: "B-e".
               
               So the error is that when the expansion conditions are not met, the '-' character itself is not printed.
            }
            {
                lon=ch[i+1]-ch[i-1];
                for(j=0;j<lon-1;j++)
                {
                    printf("%c",j+ch[i-1]+1);
                }
            }
        }
        else printf("%c",ch[i]);
        lon=0;
    }
    return 0;
}