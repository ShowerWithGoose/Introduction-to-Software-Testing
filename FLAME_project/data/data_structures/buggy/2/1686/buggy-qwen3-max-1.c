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
 printf("%d",sum);//计算和 @@ [The loop condition `i < t-1` is incorrect. It should be `i < t` because `m` has `t` operators including the final '='. However, more critically, the algorithm fails to correctly handle operator precedence and grouping: when processing multiplication/division, it consumes extra tokens but doesn't properly align the remaining addition/subtraction sequence. Specifically, after handling a * or / chain, the next number is skipped in the addition/subtraction phase because `n` and `m` arrays are not correctly synchronized with the original token positions. In the test case "10 + 20 * 30 - 40 / 5 =", the multiplication 20*30=600 and division 40/5=8 are computed, but the resulting terms [10, 600, 8] are stored in `n`, and operators ['+', '-', '='] in `m`. However, the final summation loop runs only for `i < t-1` (i.e., i=0 to i=1 when t=3), so it does 10 + 600 = 610, then 610 - 8 = 602 — which actually matches expected output. But wait: the buggy output was 580, meaning something else is wrong. The real issue is in the multiplication/division loop: when it processes `20 * 30`, it sets `n[j]=20`, then multiplies by `a[i+1]=30`, then increments `i` to point past `30`. But then `i--` brings it back to the position of `30`'s operator. However, the next iteration of the outer loop starts at that operator, which is now '-' — correct. BUT: the value `a[i]` for the next term (40) is never loaded into `n` during the else clause because after processing the * chain, the outer loop index `i` is at the '-' operator, and then the else branch runs for '-', storing `a[i]` — but `a[i]` at that point is the number corresponding to the '-' operator's left operand, which is already consumed. Actually, the core flaw is that the array `a` stores numbers aligned with operators in `b`, such that `a[0]` is first number, `b[0]` is first operator, etc., and `a[l]` is the last number (since there are l+1 numbers and l+1 operators including '='). But in the multiplication/division pass, when you do `n[j] = a[i]` and then consume `a[i+1]`, you are using `a[i+1]` which is valid, but then you increment `i` so that the outer loop skips the next number. However, the next number (e.g., 30) is never independently added to `n` — which is correct because it's part of the product. But the problem arises with the indexing of `n` and `m`. After processing `20 * 30`, you store the result in `n[j]`, increment `j`, and then the next token is '-', which goes into the else branch: `m[t++]=b[i]` (which is '-'), and `n[j++]=a[i]` — but `a[i]` here is `a[i]` where `i` is the index of the '-' operator, and `a[i]` is actually the number that came before '-', which is 30 — but 30 was already consumed in the multiplication! So `a[i]` is stale. The arrays `a` and `b` are built such that `a[k]` corresponds to the k-th number, and `b[k]` is the operator after it. So for "10+20*30-40/5=", we have:
a = [10,20,30,40,5]
b = ['+','*','-','/','=']
l = 4 (since j-1, and j=5 operators)
Then in the mul/div pass:
i=0: b[0]='+' → else: m[0]='+', n[0]=a[0]=10
i=1: b[1]='*' → enter if: n[1]=a[1]=20; then while: b[1]='*' → n[1]=20*a[2]=600; i becomes 2; then b[2]='-' → break; i-- → i=1; j=2
Then i increments to 2 in outer loop.
i=2: b[2]='-' → else: m[1]='-', n[2]=a[2]=30 ← HERE IS THE ERROR! a[2] is 30, but 30 was already used in multiplication. It should not appear again. The correct next number after 600 is 40, but because the indexing is off, 30 is incorrectly inserted as a separate term. Then i=3: b[3]='/' → process: n[3]=a[3]=40; then 40/a[4]=8; i becomes 4; i-- → i=3; j=4
Then i=4: b[4]='=' → else: m[2]='=', n[4]=a[4]=5 ← again, 5 was already used!
So n = [10,600,30,8,5], m = ['+','-','=']
Then sum = n[0]=10
i=0: m[0]='+' → sum=10+n[1]=610
i=1: m[1]='-' → sum=610 - n[2]=610-30=580 → which matches the buggy output.
Thus, the error is that after processing a multiplication/division chain starting at position i, the code should NOT process the numbers that were consumed in that chain again. But in the current logic, when the outer loop continues, it will hit the operator after the chain (e.g., '-' at i=2), and then in the else branch, it adds a[i] (which is the number at position i, i.e., the second operand of the multiplication) as a new term — which is wrong because that number was already incorporated into the product.
The fix would require that after processing a * or / sequence from position i, the next number to consider is the one after the entire chain, but the current structure doesn't skip those numbers properly in the outer loop. Specifically, the else branch should only add a[i] when the operator b[i] is +, -, or =, but a[i] must be the correct current number. However, the way the loop is structured, i corresponds to the operator index, and a[i] is the number before that operator. But when you process a * chain starting at operator i (which is '*'), you consume a[i] and a[i+1], ..., up to some a[k], and the result should replace the entire block from a[i] to a[k]. Then the next operator to consider is b[k], and the next number is a[k]. But in the current code, after processing, the outer loop index i ends up at k-1 (due to i--), so the next iteration is i=k, and if b[k] is '+' or '-', it will take a[k] — which is correct only if a[k] hasn't been consumed. But in reality, a[k] was the last number in the multiplication chain and should not be treated as a standalone term. The fundamental flaw is that the multiplication/division processing does not remove the consumed numbers from the sequence, leading to double-counting.
Therefore, the error occurs in the logic of the multiplication/division handling loop and the subsequent else branch that adds numbers unconditionally. The specific line where the incorrect value is added is in the else branch: `n[j++]=a[i];` — because `a[i]` may have already been consumed in a prior multiplication/division operation.]

return 0;
}