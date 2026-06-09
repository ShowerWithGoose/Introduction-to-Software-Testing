#include<stdio.h>
#include<string.h>
#include<ctype.h>
int is_same(char a,char b)
{
    if(islower(a)>0&&islower(b)>0)
    return 1;
    else if(isupper(a)>0&&isupper(b)>0)
    return 1;
    else if(isdigit(a-'0')>0&&isdigit(b-'0')>0) // @@ [Error: isdigit expects a character value (0-9 or '0'-'9'), but a-'0' converts the character to its integer value. For example, if a='5', a-'0'=5. isdigit(5) is false because 5 is not in the ASCII range for digits ('0'-'9' which are 48-57). It should be isdigit(a) && isdigit(b).]
    return 1;

    else{
        return 0;
    }
}
int main()
{
   char a[100]="";
   char final[100]="";
   int flag=0;
   scanf("%s",a);
   int n=strlen(a);
   for(int i=0;i<n;i++)
   {
   
    if(a[i]=='-'&&is_same(a[i-1],a[i+1])>0)
    {
        if(a[i-1]<a[i+1])
        {
            flag=1;
            // for(int j=0;j<i;j++)
            // {
            //     final[j]=a[j];
            //     printf("%c\n",final[j]);
            // }
            int change=a[i-1]+1;
            for(int j=i;j<i+(a[i+1]-a[i-1]);j++) // @@ [Error: The loop index j starts at i (the position of '-'). However, previous characters have already been printed or handled. More critically, this logic overwrites or prints into `final` using indices relative to the current position `i`, but it doesn't account for the fact that the previous character `a[i-1]` was already printed in the previous iteration of the outer loop (when `i` was `i-1`, it fell into the `else` block and printed `a[i-1]`). This causes duplication of the start character if not careful, but the main issue here is that the code prints characters directly inside the loop. Let's trace: Input `a-u`. i=1 is '-'. a[0]='a' was printed at i=0. Now at i=1, we enter this block. We print from 'b' to 'u'. This seems correct for the expansion part. However, look at the next case `B-F`. i=3 is '-'. a[2]='u' was printed? No, wait. The input is `a-uB-F`.
            // Trace:
            // i=0: 'a', else -> print 'a'.
            // i=1: '-', is_same('a','u') true. 'a'<'u'. change='b'. Loop j=1 to 1+(20)=21? No, 'u'-'a' = 20. j=1 to 20. Prints 'b'...'u'.
            // i=2: 'u', else -> print 'u'. DUPLICATION! The expansion loop printed up to 'u' (if the condition was j < i + diff, it prints diff chars. 'b' to 'u' is 20 chars. j goes 1..20. final[1]='b'...final[20]='u'. So 'u' is printed. Then i becomes 2. a[2] is 'u'. Else branch prints 'u' again. This explains the double 'u' in output `...tu u...` vs expected `...tu...`).
            // Similarly for 'F'. Expansion prints 'C'..'F'. Then i moves to index of 'F', else branch prints 'F' again.
            // The fix is to skip the end character in the subsequent iterations or adjust the printing logic. A common way is to mark processed characters or advance `i`.
            // Also, the loop condition `j<i+(a[i+1]-a[i-1])` prints exactly `end - start` characters. Start is `start+1`. So it prints `start+1` to `end`. Correct range. But the character `end` is printed here. Then the outer loop continues. The character `end` is at `i+2`. The outer loop will eventually reach `i+2` and print it again via the `else` branch because `a[i+2]` is not '-'.
            // To fix: We need to prevent the characters that were part of the expansion (specifically the end character, and potentially the start if it wasn't already printed) from being printed again. Since `a[i-1]` was already printed, we just need to skip `a[i+1]` (the end char) when the outer loop reaches it. Or simpler: don't print the end char in the expansion loop? No, the expansion includes the end char.
            // Actually, the standard approach is: if we expand, we print start+1 ... end. We already printed start. So we must ensure end is not printed again. We can do this by advancing `i` past the end character, or using a flag/array to mark printed positions.
            // Given the constraint "do not change structure", adding a skip mechanism is hard without changing structure significantly. However, looking at the bug type "Wrong Answer" and the duplication, the error is logically that the code prints the suffix character twice.
            ]
            {
                final[j]=change;
                change++;
                printf("%c",final[j]);
            }
            }
            else
            printf("%c",a[i]);
   }
   else
   printf("%c",a[i]);
   }
//    if(flag==1)
//    printf("%s",final);
//    else
//    printf("%s",a);
//     return 0;
}