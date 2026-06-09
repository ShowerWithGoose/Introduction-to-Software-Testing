#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
char s[99999999];int a[99999],n[99999];char b[99999],m[99999];
int main()
{int i,j,t,l,sum=0,temp,f=0;

gets(s);
for(i=0,j=0;s[i]!='\0';i++) 
if(s[i]!=' ')s[j++]=s[i];
s[j]='\0';//去空格 

/*for(i=0;i<=j;i++)
{printf("%c",s[i]);
}*/

j=0;
for(i=0;i<=strlen(s)-1;i++)
{if(s[i]<'0'||s[i]>'9') 
{b[j++]=s[i];}
else 
{while(s[i]>='0'&&s[i]<='9')
{a[j]=a[j]*10+s[i]-'0';i++;}
i--;
}
}l=j-1;

/*for(i=0;i<=l;i++)
printf("%d%c",a[i],b[i]);
printf("\n");//提数字与字符 */

j=0;t=0;
for(i=0;i<=l;i++)
{if (b[i]=='*'||b[i]=='/') 
   {n[j]=a[i];
      while(b[i]=='*'||b[i]=='/') 
     {if(b[i]=='*') n[j]=n[j]*a[i+1];
      else  n[j]=n[j]/a[i+1];
      i++;
     }
            i--;j++;
    }
    else  {m[t++]=b[i];n[j++]=a[i];} // @@ The logic for handling '+' and '-' is flawed. When encountering a '+' or '-', it stores the operator in `m` and the current number in `n`. However, if the previous operation was a multiplication or division, the index `j` was incremented there. Here, `j` is incremented again. This leads to misalignment between operators in `m` and operands in `n` during the final summation loop. Specifically, `n` accumulates results of mul/div in slots, but additive terms are also added to `n`. The final loop `sum=n[0]; for(i=0;i<t-1;i++) sum+=n[i+1]` assumes `n` contains the terms separated by operators in `m`. But `n` is filled sequentially. If we have `A + B * C`, `B*C` is calculated and stored in `n[0]` (if it's the first term) or similar. Let's trace `10 + 20 * 30 - 40 / 5`.
    // 1. Parse: a=[10, 20, 30, 40, 5], b=['+', '*', '-', '/', '='] (approx, depends on parsing loop boundary).
    // Parsing loop: i goes through s.
    // s = "10+20*30-40/5="
    // i=0: '1' digit -> a[0]=10. j=0.
    // i=2: '+' op -> b[0]='+'. j=1.
    // i=3: '2' digit -> a[1]=20. j=1.
    // i=5: '*' op -> b[1]='*'. j=2.
    // i=6: '3' digit -> a[2]=30. j=2.
    // i=8: '-' op -> b[2]='-'. j=3.
    // i=9: '4' digit -> a[3]=40. j=3.
    // i=11: '/' op -> b[3]='/'. j=4.
    // i=12: '5' digit -> a[4]=5. j=4.
    // i=13: '=' op -> b[4]='='. j=5.
    // Loop ends. l = j-1 = 4.
    // So a=[10,20,30,40,5], b=['+','*','-','/','=']. l=4.
    
    // Processing loop: i from 0 to 4.
    // i=0: b[0]='+'. Else branch. m[0]='+', n[0]=a[0]=10. t=1, j=1.
    // i=1: b[1]='*'. If branch. n[1]=a[1]=20. Inner while: b[1]=='*'. n[1]=20*a[2]=600. i becomes 2. Check b[2]=='-' (false). Exit while. i-- -> i=1. j++ -> j=2.
    // i=2: b[2]='-'. Else branch. m[1]='-', n[2]=a[2]=30. t=2, j=3.  <-- ERROR HERE. a[2] was already used in the multiplication. We should use the result of the multiplication (which is in n[1]) or skip this operand. The logic mixes indices. The result of 20*30 is in n[1]. The next term should be associated with the next operator. But here, it picks up a[2] again as a new term.
    // i=3: b[3]='/'. If branch. n[3]=a[3]=40. Inner while: b[3]=='/'. n[3]=40/a[4]=8. i becomes 4. Check b[4]=='=' (false). Exit while. i-- -> i=3. j++ -> j=4.
    // i=4: b[4]='='. Else branch. m[2]='=', n[4]=a[4]=5. t=3, j=5.
    
    // Final state:
    // m = ['+', '-', '=']
    // n = [10, 600, 30, 8, 5]
    // t = 3
    
    // Summation loop:
    // sum = n[0] = 10.
    // i=0: m[0]=='+'. sum += n[1] -> 10 + 600 = 610.
    // i=1: m[1]=='-'. sum -= n[2] -> 610 - 30 = 580.
    // Loop ends (i < t-1 => i < 2).
    // Output 580.
    
    // Expected: 10 + 600 - 8 = 602.
    // The error is that the operands for additive operators are not correctly aligned. When a mul/div sequence is processed, it consumes multiple `a` entries but produces one result in `n`. The subsequent additive operator handling should pick up the next unused `a` entry, but the index `i` in the outer loop continues sequentially, and `a[i]` is accessed directly. In the step i=2, `a[2]` (30) was already consumed by the multiplication at i=1. It should have been skipped. The code fails to advance the operand index correctly after a mul/div block consumes operands.
}


/*for(i=0;i<=t-1;i++)
{printf("%d%c",n[i],m[i]);
 }printf("\n"); //进行乘除*/

sum=n[0];
for(i=0;i<t-1;i++)
{
if(m[i]=='+') sum=sum+n[i+1];
else sum=sum-n[i+1];
 } 
 printf("%d",sum);//计算和
  
return 0;
}