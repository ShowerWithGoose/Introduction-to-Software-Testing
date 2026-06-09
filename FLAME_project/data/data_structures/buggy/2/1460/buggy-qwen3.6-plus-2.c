#include <stdio.h>
#include<string.h>
int main(int argc, const char * argv[]) {
    char c [10000];
    char b [10000];
    int a [10000];
    int d [10000];
    int j=0;
    int cnt=0;
    int k=0;
    int ans=0;
    gets(c);
    unsigned long s=strlen(c);
    
    for(int i=0;i<s;i++)//去空格
    {
        if(c[i]==' ')
        {
        }
        else
        {
            b[j]=c[i];
            j++;
        }
    }
    j=0; // @@ The variable j is reset to 0 here, but it should remain at its current value (the length of the stripped string) or be used as an index for array 'a'. Resetting it causes the parsing loop below to overwrite array 'a' incorrectly or start indexing from 0 while 'j' is intended to track the count of tokens in 'a'. Actually, looking closer, 'j' is used as the index for array 'a' in the next loop. Resetting it to 0 is correct for starting to fill 'a', but the logic inside the loop is flawed.
    unsigned long s1=strlen(b);
    
    for (int i=0;i<s1;i++)//转数字，分运算符
    {
         if(b[i]>=48&&b[i]<=57)
        {
            if(i==0)
            {
                a[j]=b[i]-'0';
            }
            else if(b[i-1]>=48&&b[i-1]<=57)
            {
                a[j]=a[j]*10+b[i]-'0';
            }
            else
            {
                a[j]=b[i]-'0'; // @@ When a new number starts (previous char was not a digit), we should increment j to move to the next slot in 'a' before assigning, or assign to a new index. Here it overwrites a[j] which might have been an operator or previous number part if logic isn't careful. More critically, if the previous character was an operator, j was incremented in the 'else' block below. If this is the first digit of a new number, j points to the correct empty slot. However, if the previous char was a digit, we are in the 'else if' branch. If the previous char was an operator, we are in this 'else' branch. But wait, if the previous char was an operator, j was incremented in the else block of the outer if. So a[j] is fresh. This part seems okay for building numbers, BUT:
            }
        }
        else
        {
            if(i==0)
            {
                
            }
            else
            {
                j++; // @@ This increments j when an operator is encountered. This assumes that the number preceding the operator has been fully processed and stored in a[j-1] or a[j]. If the number was multi-digit, a[j] holds the complete number. Then j++ moves to the next slot for the operator. This logic is slightly fragile but might work if aligned correctly.
            }
            if(b[i]=='+')
            {
                a[j]=-1;
                j++;
            }
            else if(b[i]=='-')
            {
                a[j]=-2;
                j++;
            }
            else if(b[i]=='*')
            {
                a[j]=-3;
                j++;
            }
            else if(b[i]=='/')
            {
                a[j]=-4;
                j++;
            }
            else
            {
                break;
            }
        }
    }
    
    for(int i=0;i<=sizeof(a)/4;i++)//先算乘除，后算加减
    {
        if(a[i]==-3)
        {
            a[i+1]=a[i-1]*a[i+1];
            a[i]=a[i-1]=-5;
        }
        else if (a[i]==-4)
        {
            a[i+1]=a[i-1]/a[i+1];
            a[i]=a[i-1]=-5;
        }
    }
    for(int i=0;i<s;i++) // @@ The loop bound uses 's' (length of original input string c), not the number of elements in array 'a'. This can lead to processing uninitialized memory or stopping too early/late. It should iterate based on the actual number of tokens parsed into 'a'.
    {
        if(a[i]==-5)
        {
        }
        else
        {
            d[k]=a[i];
            k++;
            cnt++;
        }
    }
    for(int i=0;i<cnt;i++)
    {
        if(d[i]==-1)
        {
            ans=d[i-1]+d[i+1];
            d[i]=0;
            d[i+1]=ans;
            i++;
        }
        else if (d[i]==-2)
        {
            ans=d[i-1]-d[i+1];
            d[i]=0;
            d[i+1]=ans;
            i++;
        }
    }
    if(cnt==1)
    {
        printf("%d\n",d[0]);
    }
    else
        printf("%d\n",ans); // @@ If the expression results in a single value after addition/subtraction, 'ans' might not hold the final result if the last operation wasn't assigned to 'ans' in the loop above (e.g., if the last token is a number). The logic for accumulating the final result is flawed. For example, if the expression is just "5", cnt=1, it prints d[0]. If it is "5+3", d becomes [5, -1, 3]. Loop i=0: d[0]!=-1. i=1: d[1]==-1. ans = 5+3=8. d[2]=8. i becomes 2. Loop ends. Prints ans=8. This works. But consider "5+3+2". d=[5,-1,3,-1,2]. i=1: ans=8, d[2]=8, i=2. Next iter i=3: d[3]==-1. ans=d[2]+d[4] = 8+2=10. d[4]=10. i=4. Loop ends. Prints 10. This seems okay for simple cases. However, the primary issue is the multiplication/division pass and the array indexing.
    return 0;
}