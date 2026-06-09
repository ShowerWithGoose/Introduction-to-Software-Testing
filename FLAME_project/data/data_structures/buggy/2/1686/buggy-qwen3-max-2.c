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
    else  {m[t++]=b[i];n[j++]=a[i];}

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
 printf("%d",sum);//计算和 @@ [The loop condition `i < t-1` stops one step too early. It should be `i < t` because `m[t-1]` is the '=' or last operator, and we need to process all operators up to that point. However, more critically, the logic for handling operator precedence and grouping is flawed: when processing multiplication/division, the code consumes extra tokens but doesn't correctly align the remaining numbers and operators for the final addition/subtraction pass. Specifically, after collapsing a sequence like `20 * 30`, it stores the result in `n[j]` and increments `j`, but then also appends `a[i]` (which may be stale) in the `else` branch. Also, the final loop assumes `n` and `m` are aligned such that `n[i+1]` corresponds to the operand after operator `m[i]`, but due to incorrect indexing during multiplication/division handling, this alignment is broken. For input "10 + 20 * 30 - 40 / 5 =", the multiplication 20*30=600 and division 40/5=8 are computed, but the resulting `n` array becomes [10, 600, 8] and `m` becomes ['+', '-', '='], yet the final loop only runs for `i=0` to `i<t-1` (i.e., i=0,1 if t=3), but uses `n[i+1]` which for i=1 accesses n[2]=8, so computes 10 + 600 - 8 = 602 — which actually matches expected output. However, the observed buggy output is 580, suggesting the actual stored values are different. The real issue is in the multiplication/division loop: after computing `n[j] = a[i] op a[i+1] op ...`, the index `i` is advanced past all involved operands, but the next number (`a[i]` after the loop) is not skipped properly. In particular, when the inner `while` loop ends, `i` points to the last operator processed (e.g., after '*', i points to position of '*'), then `i++` in while makes it point to next operator or '=', then `i--` after the while brings it back. But the outer for-loop will then do `i++`, so it skips the next number. However, the bigger flaw is that the `else` branch runs for every non-* / operator, including '=', and pushes `a[i]` into `n`. But when a multiplication/division block ends, the next token is an operator like '+' or '-', and the corresponding number was already consumed in the multiplication block. Yet, in the next iteration, `i` is at the '+' position, so the `else` branch runs and pushes `a[i]` — but `a[i]` at that index is not the correct number because the numbers were extracted in lockstep with operators earlier. The initial parsing assumes that numbers and operators alternate starting with a number, so there are `l+1` numbers and `l+1` operators (including '='). But during multiplication handling, multiple numbers are consumed, yet the indexing into `a` assumes each operator corresponds to one number. This leads to using wrong values from `a`. For example, in "10+20*30-40/5=", after removing spaces, we have tokens: a[0]=10, b[0]='+'; a[1]=20, b[1]='*'; a[2]=30, b[2]='-'; a[3]=40, b[3]='/'; a[4]=5, b[4]='='. Then in the multiplication/division pass: i=0: b[0]='+' → else: m[0]='+', n[0]=a[0]=10, j=1, t=1. i=1: b[1]='*' → enter if: n[1]=a[1]=20; while: b[1]='*' → n[1]=20*a[2]=600; i becomes 2; check b[2]='-' → break while; then i-- → i=1; j=2. Then i increments to 2 in for-loop. i=2: b[2]='-' → else: m[1]='-', n[2]=a[2]=30 → here's the error! a[2] is 30, but it was already used in multiplication. It should not be added again. Similarly, i=3: b[3]='/' → n[2]=a[3]=40; while: b[3]='/' → n[2]=40/a[4]=8; i=4; b[4]='=' → break; i-- → i=3; j=3. Then i=4: b[4]='=' → else: m[2]='=', n[3]=a[4]=5. So n = [10,600,30,8,5]? Actually, j and t tracking is messy. The core error is that in the `else` branch, it always does `n[j++]=a[i]`, but when `i` corresponds to an operator that follows a multiplication/division block, `a[i]` is an operand that was already consumed. Thus, stale or duplicate numbers are inserted. This causes the final sum to be incorrect. The correct approach is to not push `a[i]` in the `else` when `i` is part of a multiplication/division sequence. The reference program handles this by having two passes: first extract all numbers and operators, then collapse * and / by updating the number array in place and adjusting indices. This program fails to maintain correct correspondence between numbers and operators after collapsing * and /.]
  
return 0;
}