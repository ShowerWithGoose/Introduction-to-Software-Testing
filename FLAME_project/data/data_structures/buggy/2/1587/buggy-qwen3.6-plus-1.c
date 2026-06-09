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



printf("%d\n",digit[len]); // @@ The final result is not stored in digit[len]. After processing, the accumulated result is in the last non-zero digit or needs to be summed up. Specifically, the logic for addition/subtraction updates digit[j] but leaves digit[k] (the left operand) unchanged or zeroed out incorrectly in previous steps. More critically, `digit[len]` corresponds to the slot after the last operator, which might be uninitialized or zero if the last operation was multiplication/division that zeroed out the left operand. The correct result is likely in one of the other digit slots, or the accumulation logic is flawed. For the input "10 + 20 * 30 - 40 / 5 =", digits are 10, 20, 30, 40, 5. Ops: +, *, -, /.
// Step 1 (* and /):
// k=1 ('*'): digit[2] = 20*30=600, digit[1]=0. Digits: 10, 0, 600, 40, 5.
// k=3 ('/'): digit[4] = 40/5=8, digit[3]=0. Digits: 10, 0, 600, 0, 8.
// Step 2 (+ and -):
// k=0 ('+'): j starts at 0. digit[1]==0, so j becomes 2. digit[2] = digit[0] + digit[2] = 10 + 600 = 610. Digits: 10, 0, 610, 0, 8.
// k=2 ('-'): j starts at 2. digit[3]==0, so j becomes 4. digit[4] = digit[2] - digit[4] = 610 - 8 = 602. Digits: 10, 0, 610, 0, 602.
// The result is 602, which is in digit[4]. len is 4 (number of operators). digit[len] is digit[4].
// Wait, if len=k=4, then digit[4] is indeed 602. Why did it output 0?
// Let's re-read the code carefully.
// In the first loop, `digit[k]=0` is set for * and /.
// In the second loop, for '+', `digit[j]=digit[k]+digit[j]`. It does NOT set digit[k] to 0.
// For '-', `digit[j]=digit[k]-digit[j]`. It does NOT set digit[k] to 0.
// So after '+': digit[2]=610. digit[0] is still 10.
// After '-': digit[4]=602. digit[2] is still 610.
// The printf prints digit[len], which is digit[4]. This should be 602.
// However, there is a subtle bug in `while (digit[++j]==0)`. If `digit[j]` is never 0, it works. But what if the result of an operation is 0?
// Also, `gets` is unsafe but usually works in these problems.
// Let's look at the variable `len`. `len=k` after the first while loop. `k` becomes 4.
// Is it possible `digit[len]` is not the right place?
// Actually, the main issue is often that `digit` array initialization is not guaranteed to be 0 if declared locally without initialization. `int digit[100];` contains garbage.
// When checking `while (digit[++j]==0)`, if garbage values are present, this loop behaves unpredictably.
// Initializing `digit` to 0 is crucial.

return 0;
}