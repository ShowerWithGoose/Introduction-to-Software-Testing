#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char str[105];
int main()
{

fgets(str, 110, stdin); // @@ Buffer size mismatch: fgets uses size 110 but str is 105, potential overflow.
//gets(str);
int spot_count = 0, numb_start = 0;
int length = strlen(str);

for (int i = 0; i < length ; i++) // @@ Loop includes newline character; later output loops will print it.
{
if (str[i] == '0')continue; //

if (str[i] != '0' && str[i] != '.')//
{
if (numb_start != 0)continue; //
numb_start = i + 1;//

if (str[0] == '0')numb_start = i - 1;//
}

if (str[i] == '.')spot_count = i - 1;//
}

if (str[0] == '0')
{
     
if (numb_start + 2 >= length)// @@ Condition is off‑by‑one; should be >= length-1 to correctly detect no digits after the first significant digit.
printf("%c", str[numb_start + 1]);//
else
{printf("%c.", str[numb_start + 1]);//

 for (int i = numb_start + 2; i <= length - 1; i++)// @@ Loop includes the newline character (length-1); should stop before it, e.g., i < length-1.
 {
 printf("%c", str[i]);
 }
 }
  printf("e-%d", abs(numb_start - spot_count));//
}

//printf("%d %d", spot_count, numb_start);

if (str[0] != '0')
{
printf("%c.", str[numb_start - 1]); //
  for (int i = numb_start; i < length ; i++) // @@ Loop includes the newline character; should stop before it, i.e., i < length-1.
 {
  if (str[i] == '.')continue;
  printf("%c", str[i]);
  }
printf("e%d", spot_count); //
}
return 0;

}