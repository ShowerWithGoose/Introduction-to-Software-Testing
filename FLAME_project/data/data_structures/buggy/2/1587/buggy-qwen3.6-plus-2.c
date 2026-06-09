#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main(){
char s[100];
gets(s);
int i=0;
int j=0;
int k=0;
int len;
int digit[100];
char operater[100];
while(s[i++]!='\0'){
 
   if(isdigit(s[i-1])){
     int p=i-1;
     int res=s[p]-'0';
    p++;
     while (s[p]==' '||isdigit(s[p]))
     {
      if(isdigit(s[p])){
     res=res*10+s[p]-'0';
     }
     p++;
     }

     digit[j++]=res;
     i=p;
     
  }
  else if(s[i-1]!=' '){
    operater[k++]=s[i-1];
  }
}
operater[k]='\0';
j=0;
k=0;
while (operater[k]!='\0')
{
  if(operater[k]=='*'){
    digit[k+1]=digit[k]*digit[k+1];
    digit[k]=0;

  }
  else if(operater[k]=='/'){
    digit[k+1]=digit[k]/digit[k+1];
    digit[k]=0;
  }
  k++;
}
len=k;
k=0;
while (operater[k]!='\0')
{
  if(operater[k]=='+'){
    j=k;
    while (digit[++j]==0)
    {
      ;
    }
    digit[j]=digit[k]+digit[j];
    
  }
  else if(operater[k]=='-'){
    j=k;
while (digit[++j]==0)
{
  ;
}
digit[j]=digit[k]-digit[j];


  }
  k++;
}



printf("%d\n",digit[len]); // @@ The final result is stored in the last non-zero element of the digit array after reductions, not necessarily at index len. Also, the logic for accumulating + and - is flawed because it doesn't update the "current" value correctly for chained operations (e.g., A-B+C). It modifies a future digit but leaves the current digit[k] as is (or 0 from previous step), and subsequent steps might skip it or use wrong indices. The primary issue for the specific test case `10 + 20 * 30 - 40 / 5 =` is that the multiplication/division pass sets `digit[k]=0`. So `digit` becomes `[0, 600, 0, 8]`. `operater` is `['+', '*', '/', '\0']`? No, `operater` was parsed as `+`, `*`, `-`, `/`. Wait, the parsing loop puts operators in `operater`. `10+20*30-40/5=`. Operators: `+`, `*`, `-`, `/`. Digits: `10`, `20`, `30`, `40`, `5`.
// Pass 1 (* and /):
// k=0 ('+'): skip.
// k=1 ('*'): digit[2] = 20*30=600. digit[1]=0. Digits: [10, 0, 600, 40, 5].
// k=2 ('-'): skip.
// k=3 ('/'): digit[4] = 40/5=8. digit[3]=0. Digits: [10, 0, 600, 0, 8].
// len = 4.
// Pass 2 (+ and -):
// k=0 ('+'): j starts at 0. digit[++j] -> digit[1]==0. digit[++j] -> digit[2]==600 (non-zero). digit[2] = digit[0] + digit[2] = 10 + 600 = 610.
// k=1 ('*'): skip.
// k=2 ('-'): j starts at 2. digit[++j] -> digit[3]==0. digit[++j] -> digit[4]==8 (non-zero). digit[4] = digit[2] - digit[4] = 610 - 8 = 602.
// k=3 ('/'): skip.
// End loop.
// printf("%d\n", digit[len]) -> digit[4]. digit[4] is 602.
// Wait, the expected output is 602. The buggy output is 0.
// Let's re-read the code carefully.
// In the first pass, `digit[k]=0` is set for the left operand.
// In the second pass, for `+`, it finds the next non-zero digit to the right.
// For `10 + ...`, k=0. j=0. ++j -> 1. digit[1] is 0. ++j -> 2. digit[2] is 600.
// digit[2] = digit[0] + digit[2] = 10 + 600 = 610.
// For `-`, k=2. operater[2] is `-`.
// j=2. ++j -> 3. digit[3] is 0. ++j -> 4. digit[4] is 8.
// digit[4] = digit[2] - digit[4] = 610 - 8 = 602.
// So digit[4] is 602.
// Why is the output 0?
// Ah, `len=k` after the first while loop. The first while loop runs until `operater[k]!='\0'`.
// The operators are `+`, `*`, `-`, `/`. Indices 0, 1, 2, 3.
// Loop runs for k=0, 1, 2, 3. Then k becomes 4. `operater[4]` is `\0`. Loop terminates.
// So `len` is 4.
// `printf("%d\n", digit[len])` prints `digit[4]`.
// If the logic above is correct, it should print 602.
// Is there an issue with `digit` initialization? `int digit[100];` is uninitialized.
// If `digit` contains garbage, `digit[++j]==0` might behave unexpectedly if garbage is 0? No, it checks for equality to 0. If garbage is non-zero, it stops early.
// However, `digit` is local. Uninitialized local variables have indeterminate values.
// If `digit[1]` happened to be non-zero garbage, the `+` step would use it.
// But the specific symptom is Output 0.
// If `digit[4]` was 0, it means the subtraction didn't happen or overwrote it?
// Or maybe `len` is wrong?
// Let's look at the parsing.
// `10 + 20 * 30 - 40 / 5 =`
// i=0, s[0]='1'. digit. p=0. res=1. p=1. s[1]='0'. res=10. p=2. s[2]=' '. Loop ends. digit[0]=10. i=2.
// i=2, s[2]=' '. Not digit, not non-space. i becomes 3.
// i=3, s[3]='+'. Not digit, is non-space. operater[0]='+'. k=1. i=4.
// i=4, s[4]=' '. Skip. i=5.
// i=5, s[5]='2'. digit. p=5. res=2. p=6. s[6]='0'. res=20. p=7. s[7]=' '. End. digit[1]=20. i=7.
// i=7, s[7]=' '. Skip. i=8.
// i=8, s[8]='*'. operater[1]='*'. k=2. i=9.
// i=9, s[9]=' '. Skip. i=10.
// i=10, s[10]='3'. digit. p=10. res=3. p=11. s[11]='0'. res=30. p=12. s[12]=' '. End. digit[2]=30. i=12.
// i=12, s[12]=' '. Skip. i=13.
// i=13, s[13]='-'. operater[2]='-'. k=3. i=14.
// i=14, s[14]=' '. Skip. i=15.
// i=15, s[15]='4'. digit. p=15. res=4. p=16. s[16]='0'. res=40. p=17. s[17]=' '. End. digit[3]=40. i=17.
// i=17, s[17]=' '. Skip. i=18.
// i=18, s[18]='/'. operater[3]='/'. k=4. i=19.
// i=19, s[19]=' '. Skip. i=20.
// i=20, s[20]='5'. digit. p=20. res=5. p=21. s[21]='='. Not space, not digit. End. digit[4]=5. i=21.
// i=21, s[21]='='. Not digit, not non-space (it is non-space? '=' != ' ').
// Wait. `else if(s[i-1]!=' ')`. s[21] is '='. It is not ' '. So it goes into else if.
// operater[4]='='. k=5.
// So `operater` is `"+*-/="`.
// First while loop: `while (operater[k]!='\0')`.
// k=0 ('+'). Skip.
// k=1 ('*'). digit[2]=20*30=600. digit[1]=0.
// k=2 ('-'). Skip.
// k=3 ('/'). digit[4]=40/5=8. digit[3]=0.
// k=4 ('='). Skip.
// k=5. operater[5] is '\0' (uninitialized? No, `operater` is local, uninitialized. But we wrote up to index 4. Index 5 is garbage.
// The loop condition `operater[k]!='\0'` relies on `operater` being null-terminated.
// We did `operater[k]='\0'` after the parsing loop?
// Let's check the code:
// `operater[k]='\0';` is present after the parsing `while` loop.
// At that point, k was 5. So `operater[5]='\0'`.
// So the loop `while (operater[k]!='\0')` with k=0 initially:
// It processes indices 0, 1, 2, 3, 4.
// At k=4, operater[4] is '='. It is not '*' or '/'. So nothing happens.
// Loop finishes. len=k. k is now 5. So len=5.
// Second while loop: `while (operater[k]!='\0')` with k=0 initially.
// k=0 ('+'). j=0. digit[1]==0. digit[2]==600. digit[2]=10+600=610.
// k=1 ('*'). Skip.
// k=2 ('-'). j=2. digit[3]==0. digit[4]==8. digit[4]=610-8=602.
// k=3 ('/'). Skip.
// k=4 ('='). Skip.
// k=5. Loop ends.
// printf("%d\n", digit[len]) -> digit[5].
// digit[5] was never written to. It is uninitialized garbage.
// If the garbage happens to be 0, the output is 0.
// The error is using `digit[len]` where `len` is the number of operators (including '='), which corresponds to an index in `digit` that was not calculated as a final result. The final result is in `digit[4]`.
// Generally, the result is in the last valid digit slot.
// Since `len` is 5, and valid digits are 0..4, `digit[5]` is out of bounds/unused.

return 0;
}