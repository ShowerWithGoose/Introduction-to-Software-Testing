#include <stdio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int a[1000005];
char  s[1000005];
int main()
{
    int i=1;
    while (scanf("%d", &a[i]) != EOF) // @@ The loop condition checks for EOF, but the input ends with '='. scanf("%d") will fail to read '=' and return 0 or EOF depending on implementation, but more importantly, the operator following the number is not consumed correctly in this structure. The logic for reading operators is flawed because it tries to read into s[i] which corresponds to the index of the number just read, but the shifting logic later assumes a specific alignment. Also, the loop doesn't break on '='.
    {
        while (s[i] == '\0' || s[i] == ' ') // @@ s[i] is uninitialized here. Accessing uninitialized memory leads to undefined behavior. It should likely be reading a character into a temporary variable or directly into s[i] after initialization, but the logic of mixing number reading and operator reading in this specific while loop structure is deeply flawed.
        {
            scanf("%c", &s[i]); // @@ This reads the operator. However, if the input is "10 + ...", after reading 10 into a[1], it reads ' ' into s[1], then loops to read '+' into s[1]. This part might work for the first operator, but the index management is tricky.
        }
        i++;
    }
printf("%c",s[1]); // @@ This line prints the first operator instead of the final result. It should be removed or replaced with the final printf for the sum. This is the direct cause of the output being "+" instead of the number.
    int h = i;
    for (i = 1; i < h; i++)
    {
        if (s[i] == '*' || s[i] == '/')
        {
            if (s[i] == '*')
                a[i] *= a[i + 1];
            else
                a[i] /= a[i + 1];
            for (int j = i+1; j < h; j++)
            {
                a[j] = a[j + 1];
                s[j - 1] = s[j];
            }
            i--;
        }
    }
    int sum=a[1];
    for(i=1; s[i-1]!='='; i++) // @@ The termination condition s[i-1]!='=' is incorrect. The operator array s does not necessarily contain '=' at the end in the way this loop expects, especially after the shifting operations. The shifting in the previous loop reduces the effective size, but 'h' is not updated. Furthermore, the original parsing didn't explicitly store '=' in s in a way that aligns with this check reliably after shifts.
    {
        if(s[i]=='+')
        {
            sum+=a[i+1];
        }
        if(s[i]=='-')
        {
            sum-=a[i+1];
        }
    }
    //printf("%d\n",sum); // @@ The final result is commented out. This prevents the correct answer from being printed.
    return 0;



}