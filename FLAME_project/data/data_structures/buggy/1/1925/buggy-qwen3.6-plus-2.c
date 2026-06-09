#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define PI 3.2415926536
#define eps 1e-8
#define MAX 1000005
#define arrlen(x) (sizeof(x)/sizeof(x[0]))//数组长度

//求最大值
int Max(int,int);

//整数平方longlong输出
long long mpow(int,int);

//辗转相除求最大公约
int gcd(int,int);



//转义 \ -> \\;% -> %%; ' -> \' '' -> \''

//求字符串长度len=strlen(s);

/*
    FILE *in, *out;
    in = fopen("filein.txt","r");
    out = fopen("fileout.txt","w");

    fclose(in);
    fclose(out);
*/

//while((content[i++] = fgetc(in))!=EOF);
//fputc(,out);

int SWAP(int ,int);

int pailie(int ,int );


int ans[11];

int main()
{
    int n,i;
    scanf("%d",&n);
    for(i = 0;i < n;i++)
    {
        ans[i]=i+1;
    }



    pailie(0,n-1);


    return 0;

}


long long mpow(int x,int y)
{
    long long ans = 1;
    for(int i = 0;i < y;i++)
    {
        ans *= x;
    }
    return ans;
}

int Max(int a, int b)
{
    return (a > b) ? a : b;
}

int gcd(int a,int b)
{
    return a%b?gcd(b,a%b):b;
}

int SWAP(int a,int b)
{
    int temp = ans[a];
    ans[a]=ans[b];
    ans[b]=temp;
}

int pailie(int begin, int end)
{
    int i = 0,j = 0;
    if(begin == end)
    {
        for(i = 0;i <= end;i++)
        {
            printf("%d ",ans[i]);
        }
        printf("\n");
    }
    else
    {
        for(j = begin;j <= end;j++) // @@ The loop iterates through all elements from begin to end without sorting or checking order, generating permutations in an order that is not lexicographically sorted. For N=2, it generates "1 2" then "2 1". The problem requires lexicographical order. While "1 2" then "2 1" IS lexicographical for N=2, the test case expectation "1 2 " suggests only one line or a formatting issue. However, looking at the expected output "1 2 " vs buggy "1 2 \n2 1 \n", the expected output seems truncated or the problem description implies a specific subset or format. Wait, the problem says "Output N! lines". For N=2, 2! = 2 lines. The expected output provided in the prompt is "1 2 ". This is contradictory to the problem description "Output N! lines". Let's re-read carefully. "Expected Output: 1 2 ". This looks like only the first line is expected, or there is a newline missing in the display. However, usually, these prompts imply the full output. If the expected output is strictly "1 2 ", it might mean the program should only output the first permutation? No, "generate all permutations". It is highly likely the "Expected Output" in the prompt description is just showing the first line or is malformed in the prompt itself, OR the judge system expects a specific trailing space/newline format. 
        // Actually, let's look at the Buggy Output: "1 2 \n2 1 \n". Expected: "1 2 ". 
        // If the expected output is literally just "1 2 ", then the program is printing too much. But the problem says "generate ALL permutations". 
        // Let's look at the reference program. It prints all permutations. 
        // There is a possibility that the "Expected Output" shown in the prompt is incomplete or represents a specific test case failure where the judge compares token by token and fails early? 
        // Or perhaps the issue is simpler: Lexicographical order. The standard swap-based permutation generation does NOT produce lexicographical order unless the input is sorted and specific conditions are met (it produces Heap's algorithm order or similar depending on implementation). The standard recursive swap method `pailie` generates:
        // Start: 1 2
        // Swap(0,0): 1 2 -> Recurse -> Print 1 2
        // Swap(0,1): 2 1 -> Recurse -> Print 2 1
        // This IS lexicographical for N=2. 
        // For N=3:
        // 1 2 3
        // 1 3 2
        // 2 1 3
        // 2 3 1
        // 3 2 1
        // 3 1 2
        // Lexicographical order for N=3 is:
        // 1 2 3
        // 1 3 2
        // 2 1 3
        // 2 3 1
        // 3 1 2
        // 3 2 1
        // The generated order matches lex order for N=3 as well?
        // Let's check N=3 trace:
        // begin=0, end=2.
        // j=0: Swap(0,0) -> 1 2 3. Recurse begin=1.
        //   begin=1, end=2.
        //   j=1: Swap(1,1) -> 1 2 3. Recurse begin=2.
        //     begin=2==end. Print 1 2 3.
        //   Swap(1,1) back.
        //   j=2: Swap(1,2) -> 1 3 2. Recurse begin=2.
        //     begin=2==end. Print 1 3 2.
        //   Swap(1,2) back -> 1 2 3.
        // Swap(0,0) back.
        // j=1: Swap(0,1) -> 2 1 3. Recurse begin=1.
        //   begin=1, end=2.
        //   j=1: Swap(1,1) -> 2 1 3. Recurse begin=2.
        //     Print 2 1 3.
        //   j=2: Swap(1,2) -> 2 3 1. Recurse begin=2.
        //     Print 2 3 1.
        // Swap(0,1) back -> 1 2 3.
        // j=2: Swap(0,2) -> 3 2 1. Recurse begin=1.
        //   begin=1, end=2.
        //   j=1: Swap(1,1) -> 3 2 1. Recurse begin=2.
        //     Print 3 2 1.
        //   j=2: Swap(1,2) -> 3 1 2. Recurse begin=2.
        //     Print 3 1 2.
        // Generated: 123, 132, 213, 231, 321, 312.
        // Lex Order: 123, 132, 213, 231, 312, 321.
        // Mismatch at last two: Generated 321 then 312. Expected 312 then 321.
        // So the algorithm does NOT produce lexicographical order for N>=3.
        // The error is that the simple swap recursion does not guarantee lexicographical order.
        // To fix this, one must use `next_permutation` logic or sort the results, or use a visited array approach like the reference code.
        // Given the constraint to only mark errors, the logical error is in the `pailie` function's approach.
        // However, I cannot rewrite the function. I must mark the line causing the wrong order.
        // The line `for(j = begin;j <= end;j++)` iterates in index order, swapping elements. This causes the non-lex order.
        
        SWAP(begin,j);
        pailie(begin + 1,end);
        SWAP(begin,j);
    }
}