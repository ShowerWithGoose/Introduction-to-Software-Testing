#include<stdio.h>
#include<string.h>
#include<ctype.h>
int is_same(char a,char b)
{
    if(islower(a)>0&&islower(b)>0)
    return 1;
    else if(isupper(a)>0&&isupper(b)>0)
    return 1;
    else if(isdigit(a-'0')>0&&isdigit(b-'0')>0) // @@ [Error: isdigit expects the character itself, not (char - '0'). For digits '0'-'9', a-'0' results in 0-9. isdigit(0) is false (as 0 is NULL/non-digit). This causes digit ranges like 0-9 to fail the type check.]
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
            for(int j=i;j<i+(a[i+1]-a[i-1]);j++) // @@ [Error: The loop index j starts at i (the position of '-'). However, previous characters (0 to i-2) have already been printed by the else block in previous iterations. The start character a[i-1] was also printed in the previous iteration. This logic attempts to print the expansion starting at index i, but fails to account for the fact that the prefix has already been output, leading to duplication or misalignment if not handled carefully. More critically, in the specific failing case a-uB-F, the 'u' is printed by the else block when i points to 'u'. Then when i points to '-', it prints the expansion. But wait, if i points to '-', a[i-1] is 'u'. The previous iteration i-1 (pointing to 'u') went to else and printed 'u'. So 'u' is printed. Then here we print from 'v' onwards. This part might be okay for the first range. Let's look at the second range B-F. When i is at '-', a[i-1] is 'B'. Previous iteration printed 'B'. Here we print C,D,E,F. The issue in the buggy output "abcdefghijklmnopqrstuuBCDEFF" suggests duplicates. The duplicate 'u' and 'F' suggest that the boundary characters are being printed twice. Once by the `else` clause of the previous character, and potentially again or the loop range is off. Actually, looking closely at the loop: `j` goes from `i` to `i + diff`. The array `final` is written but `printf` prints immediately. The main issue is likely that the code doesn't skip the next character (the end of the range) properly, or the `else` block prints the character after the expansion range again. In the standard logic, if we expand a-b, we print a (in prev step), then v...z. We must ensure we don't print b again. The loop runs `a[i+1]-a[i-1]` times. If range is a-c (diff 2), it runs 2 times. Prints b, c. Next iteration i increments. If i moves to next char, it might process the end char again if not skipped. The loop structure `for(int i=0;i<n;i++)` increments i by 1 each time. If we process a range at i, we should skip i+1 (the end char). The code does not increment i extra, so when i becomes i+1 (the end char), it will fall into the `else` block (since a[i+1] is not '-') and print the end char again. This explains the duplicate last character 'u' (from a-u, u is printed by else when i was at u? No, when i is at '-', prev char u was printed. Then expansion prints v..u? No, change starts at a[i-1]+1. So v..u. Wait. a-u. change = 'v'. Loop runs 'u'-'a' = 20 times. Prints v,w...u. So 'u' is printed here. Then i increments to point to 'u' (the original end char). It is not '-'. So else prints 'u' again. Hence duplicate 'u'. Same for 'F'.]
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