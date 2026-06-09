#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    char num[105];
    scanf("%s",&num); // @@ [Using &num is incorrect; should be just num since it's an array (decays to pointer). This may cause undefined behavior, though not necessarily a compilation error. However, the reported error is "gcc: not found", which is environment-related, but assuming the intent is to find logical/semantic bugs causing wrong output, this line has a subtle issue.]
    int i,k,suma=0,sumb=0;
    if(num[0]=='0')
    {
        sumb=1;
    }
    for(i=1;i<strlen(num);i++)
    {
        if(num[0]=='0')
        {
            if(num[i]=='0' && sumb==i-1)
            {
                sumb++;
                
            }
        }
        else
        {
            if(num[i]=='.')
            {
                break;
            }
            else
            {
                suma++;
                
            }
        }
    }
    //printf("%d\n%d\n",sumb,strlen(num));
    if(sumb!=0)
    {
        printf("%c",num[sumb+1]); // @@ [If the input is like "0.00123", sumb becomes 2 (index of first non-zero after decimal), so sumb+1 = 3, which is correct. But if input is "0.1", sumb=1, then sumb+1=2, which is beyond string length if num is "0.1" (len=3, indices 0,1,2 -> '.' at 1, '1' at 2). So this might access valid data. However, logic fails when there's only one significant digit after zeros, e.g., "0.005" -> prints '5' then checks if sumb+2 == strlen(num): sumb=2, sumb+2=4, strlen=4 ("0.005" -> len=5? Wait: "0.005" is 5 chars: ['0','.','0','0','5'] -> strlen=5. sumb: starts at 1, i=1: '.' -> skip? Actually, loop starts at i=1, and num[0]=='0', so enters first branch. At i=1: num[1]=='.' -> not '0', so sumb remains 1. Then i=2: num[2]=='0' and sumb(1)==i-1(1) → sumb=2. i=3: num[3]=='0' and sumb(2)==2 → sumb=3. i=4: num[4]=='5' → condition fails. So sumb=3. Then prints num[4] → '5'. Then sumb+2 = 5, strlen=5 → so prints "5e-3". Correct. But what about "0.10"? Problem states: "no trailing zeros after decimal", so this case won't occur. However, another bug: in the else branch (non-zero start), it counts digits before '.', but doesn't handle cases like "123.45" correctly? Let's see: num[0]!='0', so else branch in loop: counts non-dot chars until dot. For "123.45", i=1: '2' → suma=1; i=2: '3' → suma=2; i=3: '.' → break. So suma=2. Then prints "1." then "2345" → "1.2345e2" → correct. But what about "1.0"? Not allowed per problem (no trailing zeros). So maybe okay. However, major bug: in the sumb!=0 block, when printing fractional part, loop runs k from sumb+2 to <=strlen(num). But strlen(num) is length, and valid indices are 0 to strlen-1. So k<=strlen(num) accesses num[strlen(num)] which is '\0', and possibly beyond. This causes printing extra garbage or null char. For example, "0.0012" (len=6: '0','.','0','0','1','2'), sumb=3 (after processing), so sumb+1=4 → prints '1'. Then sumb+2=5, loop k=5 to 6 (inclusive). k=5: num[5]='2'; k=6: num[6]='\0' → prints null character (invisible but wrong). Should be k < strlen(num). Also, if only one digit after, e.g., "0.005", sumb=3, sumb+2=5, strlen=5 → loop runs k=5 to 5: prints num[5] which is out of bounds (valid indices 0-4). So this is a critical off-by-one error.]
        if((sumb+2)==strlen(num))
        {
            printf("e-%d",sumb);
        }
        else
        {
            printf(".");
            for(k=sumb+2;k<=strlen(num);k++) // @@ [Loop condition should be k < strlen(num), not k <= strlen(num). Accessing num[strlen(num)] is reading past the end of the string (null terminator), which is invalid and leads to incorrect output.]
            {
                printf("%c",num[k]);
            }
            printf("e-%d",sumb);    
        }
    }
    else
    {
        printf("%c.",num[0]);
        for(k=1;k<strlen(num);k++)
        {
            if(num[k]!='.')
            {
                printf("%c",num[k]);
            }
        }
        printf("e%d",suma);
    }
    
}