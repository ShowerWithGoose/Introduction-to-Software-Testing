#include <stdio.h>
char a[1000],b[1000],c[1000][1000];
int d[1000]={0};
int num(int i0,int i)
{
    int k1,j=0;
    for(k1=i0+1;k1<i;k1++)
    {
        j=j*10+b[k1]-'0';
    }
    return j;
    
}
int main()
{
    int i,j=0,i0=-1,m=0,n=1,len;
    gets(a); 
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]==' ')
        {
            continue;
        }
        else
        {
            b[j]=a[i];
            j++;
        }
    }
    //b[j]ÎŞ¿Õ
    len=strlen(b);
    
    for(i=0;i<len;i++)
    {
        if(b[i]>='0'&&b[i]<='9')
        {
            continue;
        }
        else
        {
            d[n]=num(i0,i);//»¹Ô­Êı×Ö 
            
            i0=i;n++;
    
            if(b[i]=='+'||b[i]=='-')
            {
            m++;    c[2][m]=b[i];//´æ´¢¼Ó¼õ·ûºÅ ,mÊÇ·ûºÅÎ»ÖÃ 
    
                
            }
            else if(b[i]=='*'||b[i]=='/') 
            {
                m++;c[1][m]=b[i];//´æ³Ë³ı 
            }
            else
            {
                d[n]=num(i0,i);
                break;
            }
            
            
        }
        
    }
    for(i=1;i<=m;i++) // @@ The loop should start from 1 because operators are stored starting at index 1 in c[1] and c[2]. Also, the logic below accesses d[i] and d[i+1], which corresponds to operands around operator i.
    {
        if(c[1][i]=='*')
        {
            d[i+1]=d[i]*d[i+1]; // @@ This updates the right operand with the result.
            d[i]=0; // @@ Marking the left operand as used/zero is a strategy, but subsequent addition logic needs to handle this correctly.
        }
        if(c[1][i]=='/')
        {
            d[i+1]=d[i]/d[i+1];
            d[i]=0;
        }
    }
    // The previous loop modifies d in place. For 10 + 20 * 30 - 40 / 5:
    // Initial d: [?, 10, 20, 30, 40, 5] (indices 0..5, n goes up to 5)
    // Operators at m=1..4.
    // i=2 ('*'): d[3] = 20*30=600, d[2]=0. d: [?, 10, 0, 600, 40, 5]
    // i=4 ('/'): d[5] = 40/5=8, d[4]=0. d: [?, 10, 0, 600, 0, 8]
    
    for(i=1;i<=m;i++) // @@ Loop should start from 1 to match operator storage.
    {
        if(c[2][i]=='+')
        {
             // The original logic here is deeply flawed. It tries to skip zeros which represent consumed operands from * or /
             // However, simply adding d[i] to d[i+1] is correct IF d[i] is the accumulated sum so far or the left operand.
             // In our trace: i=1 is '+'. d[1]=10, d[2]=0.
             // The code does: while(d[i+1]==0...) -> d[2]==0. d[2]+=d[1] => d[2]=10. i becomes 2.
             // Then loop condition check again? No, it's a while inside an if.
             // After while: d[i+1] += d[i]. 
             // This logic is extremely confusing and incorrect for general cases.
             
             // Let's look at what SHOULD happen.
             // We have terms separated by + or -.
             // The array d now holds: 10, 0, 600, 0, 8 at indices 1, 2, 3, 4, 5.
             // Operators: c[2][1]='+', c[2][2] is empty/zero (was *), c[2][3]='-', c[2][4] is empty/zero (was /).
             // Actually, c[2] only stores + and -. c[1] stores * and /.
             // So at i=1, c[2][1] is '+'.
             // At i=3, c[2][3] is '-'.
             
             // Correct approach for second pass:
             // Accumulate result.
             // But sticking to fixing the existing structure:
             
             // The bug in the original code's second loop:
             // 1. Iteration range.
             // 2. Logic for handling subtraction and addition with the "zeroed out" operands.
             
             // Let's try to fix the specific logical error causing the wrong answer.
             // The provided solution output is 8. Expected 602.
             // 10 + 600 - 8 = 602.
             
             // In the buggy code:
             // i=1. c[2][1]=='+'. 
             // while(d[2]==0 && 1<=5) -> True. d[2]+=d[1] -> d[2]=10. i++ -> i=2.
             // Check while again: d[3]==600 != 0. False.
             // d[3]+=d[2] -> d[3] = 600+10 = 610.
             
             // Next iteration of FOR loop: i increments to 3? No, i was modified inside.
             // The for loop increments i. So i becomes 3.
             // i=3. c[2][3]=='-'.
             // while(d[4]==0 && 3<=5) -> True. d[4]=d[3]-d[4] -> d[4]=610-0=610. i++ -> i=4.
             // Check while again: d[5]==8 != 0. False.
             // d[5]=d[4]-d[5] -> d[5]=610-8=602.
             
             // Next iteration of FOR loop: i increments to 5.
             // i=5. c[2][5] is likely 0 or garbage.
             
             // Finally printf("%d", d[i]). i is 5? Or 6?
             // If the loop finishes, i will be m+1 = 5.
             // So it prints d[5]. Which is 602.
             
             // Wait, why did it output 8?
             // Let's re-read the buggy code carefully.
             
             /*
             for(i=0;i<=m;i++) // Original loop starts at 0
             {
                 if(c[2][i]=='+') ...
                 if(c[1][i]=='-') ... // BUG: Checks c[1] for '-' instead of c[2]
             }
             */
             
             // Ah, the second `if` checks `c[1][i]=='-'`. But `-` is stored in `c[2]`.
             // So subtraction is never performed!
             // And the first `if` checks `c[2][i]=='+'.
             
             // Let's re-trace with the bug:
             // i=0: c[2][0] is empty. c[1][0] is empty.
             // i=1: c[2][1]=='+'. 
             //   while(d[2]==0) -> d[2]=10, i=2.
             //   d[3]+=d[2] -> d[3]=610.
             // i=2: c[2][2] is empty. c[1][2]=='*' (not '-').
             // i=3: c[2][3]=='-'. 
             //   First if fails.
             //   Second if: c[1][3] is empty (it was '-', stored in c[2]). So this fails too.
             //   So subtraction is skipped entirely.
             // i=4: c[1][4] is empty.
             
             // Result in d[5] is still 8? 
             // Wait, in the multiplication/division pass:
             // d[5] became 8.
             // In the addition pass:
             // d[3] became 610.
             // d[5] remained 8 because the subtraction step was skipped.
             
             // The final print is `printf("%d",d[i]);`.
             // After the loop, i is m+1 = 5.
             // So it prints d[5], which is 8.
             
             // To fix this:
             // 1. Change `c[1][i]=='-'` to `c[2][i]=='-'`.
             // 2. Ensure the loop bounds and index usage are consistent.
             
             // Annotated lines below will reflect these fixes.
        }
        if(c[2][i]=='-') // @@ Changed from c[1][i]=='-' to c[2][i]=='-' because subtraction operators are stored in c[2], not c[1].
        {
            while(d[i+1]==0&&i<=m+1) // @@ Logic relies on d[i+1] being 0 for consumed operands.
            {
                d[i+1]=d[i]-d[i+1];
                i++;
            }
            d[i+1]=d[i]-d[i+1];
        }
    }
    printf("%d",d[m+1]); // @@ Changed d[i] to d[m+1] because i is modified inside the loop and its value after the loop is unreliable/incorrect for indexing the final result. The final result accumulates at the last operand index.
    
    return 0;
}