#include <stdio.h>
struct unit
{
    int factor;
    int pow;
};
int main()
{
    struct unit expression1[100];
    struct unit expression2[100];
    struct unit ans[100]; // @@ The array size is too small. The product of two polynomials can have up to N*M terms. If the input polynomials have many terms, or if the intermediate results before merging exceed 100, this will cause a buffer overflow. More critically, the problem states coefficients and exponents can be large, but the number of terms isn't explicitly bounded to 10. However, the main issue here is likely integer overflow or logic. Let's look closer. Actually, the primary error causing "Runtime Error" or incorrect output for large exponents like 1000000000 is often integer overflow during addition if `int` is 32-bit. 1000000000 + 1000000000 = 2000000000, which fits in signed 32-bit int (max ~2.14 billion). So overflow isn't the immediate crash cause. 
    // Wait, the provided "Source Code" in the prompt is different from the "Reference Program". The prompt asks to identify errors in the program *below*. The program below is the one starting with `#include <stdio.h>` and `struct unit`. 
    // Let's re-read the prompt carefully. "Based on the problem description... identify the location of the errors in the program below."
    // The "Reference Program" is listed first, then "Error type: Runtime Error", then "Test Case Input", then "Source Code".
    // Usually, in these tasks, the "Source Code" at the bottom is the buggy code to analyze. The "Reference Program" at the top is often a distractor or a correct version (though the reference program provided also looks buggy/complex). 
    // Let's analyze the "Source Code" at the bottom.
    
    // Test Case:
    // Poly 1: 8x^1000000000
    // Poly 2: 15x^1000000000
    // Expected: 120 2000000000
    
    // The code uses `int` for `pow`.
    // `ans[flag++].pow = expression1[i].pow + expression2[j].pow;`
    // 1000000000 + 1000000000 = 2000000000. This fits in a standard 32-bit signed int (max 2,147,483,647).
    
    // Why Runtime Error?
    // The arrays are fixed size 100.
    // If the input has more than 10 terms per polynomial, `flag1` or `flag2` could exceed bounds? No, `fgets` reads line. `strtok` parses.
    // If `flag1` is 1 and `flag2` is 1, `flag` becomes 1. `ans` size 100 is fine.
    
    // Let's look at `printf("%d ", ans[i].pow);`.
    
    // Is there a segmentation fault?
    // `strtok` modifies the string. `fgets` includes newline.
    
    // Let's look at the sorting loop:
    // `for(int i=0;i<flag1*flag2-1;i++)`
    // If `flag1*flag2` is 0, this loop runs with negative bound? `i < -1`. False. OK.
    
    // What if `flag1*flag2` is large?
    
    // Actually, looking at the provided "Reference Program" vs "Source Code".
    // The prompt structure is:
    // 1. Problem Description
    // 2. Reference Program (This looks like a complex linked list implementation)
    // 3. Error Type: Runtime Error
    // 4. Test Case
    // 5. Source Code (This is the simple array implementation)
    
    // The instruction says: "identify the location of the errors in the program below."
    // And "Here is an example... the annotated line..."
    // And "Enclose your entire source code output...".
    
    // The "Source Code" provided at the end is the one I need to annotate.
    
    // Let's re-evaluate the "Runtime Error".
    // In C, `int` is typically 32-bit.
    // The sum of exponents 2,000,000,000 is valid.
    
    // However, many online judges use 32-bit integers.
    // If the problem implies that the result might exceed `int`, but the struct uses `int`.
    // The problem says: "coefficients and the maximum degree ... will not exceed the range of the `int` type."
    // It does NOT say the SUM of degrees will fit in int. But 2*10^9 fits.
    
    // Is it possible the error is in the `ans` array size?
    // If the input polynomials are dense, e.g., degree 1000, the number of terms could be large.
    // But the input format is "non-zero terms".
    
    // Let's look at `sscanf(token, "%d", &expression1[flag1].factor);`
    // If `token` is NULL, the loop breaks.
    
    // There is a subtle bug in `strtok` usage if the line is empty or just newline.
    
    // But the most likely cause for "Runtime Error" in student code with fixed arrays is Buffer Overflow.
    // `struct unit ans[100];`
    // If poly1 has 10 terms and poly2 has 10 terms, ans has 100 terms.
    // If poly1 has 11 terms, flag1=11. flag2=1. ans needs 11.
    // If poly1 has 20 terms and poly2 has 5 terms, ans needs 100.
    // If poly1 has 20 terms and poly2 has 6 terms, ans needs 120. **Buffer Overflow**.
    // The problem does not restrict the number of terms, only the value of coeffs/exponents.
    // Therefore, `ans[100]` is insufficient and causes a stack buffer overflow (Runtime Error) for inputs with many terms.
    
    // Also, `expression1[100]` and `expression2[100]` might be too small if a single polynomial has >100 non-zero terms.
    
    // Another potential issue: `printf("%d ", ans[i].pow)` prints a trailing space. The problem says "A space after the last exponent is optional." So that's fine.
    
    // So the error is the fixed small array size.

    int flag1 = 0;
    int flag2 = 0;
    char line[1000];

    fgets(line, sizeof(line), stdin);
    char *token = strtok(line, " ");
    while (token != NULL) {
        sscanf(token, "%d", &expression1[flag1].factor);
        token = strtok(NULL, " ");
        if (token != NULL) {
            sscanf(token, "%d", &expression1[flag1].pow);
            token = strtok(NULL, " ");
            flag1++;
        }
    }

    fgets(line, sizeof(line), stdin);
    token = strtok(line, " ");
    while (token != NULL ) {
        sscanf(token, "%d", &expression2[flag2].factor);
        token = strtok(NULL, " ");
        if (token != NULL) {
            sscanf(token, "%d", &expression2[flag2].pow);
            token = strtok(NULL, " ");
            flag2++;
        }
    }

    int flag=0;
    for(int i=0;i<flag1;++i)
    {
        for(int j=0;j<flag2;++j)
        {
            ans[flag].factor=expression1[i].factor*expression2[j].factor;
            ans[flag++].pow=expression1[i].pow+expression2[j].pow; // @@ Potential buffer overflow if flag1*flag2 > 100. The array `ans` is fixed at size 100, but the number of product terms is flag1*flag2. If the input polynomials have enough terms such that their product exceeds 100 terms, this write will go out of bounds, causing a Runtime Error.
        }
    }
    for(int i=0;i<flag1*flag2;++i)
    {
        for(int j=i+1;j<flag1*flag2;++j)
        {
            if(ans[i].pow==ans[j].pow)
            {
                ans[i].factor+=ans[j].factor;
                ans[j].factor=0;
            }
        }
    }
    for(int i=0;i<flag1*flag2-1;i++)
    {
        for(int j=0;j<flag1*flag2-1-i;++j)
        {
            if(ans[j].pow<ans[j+1].pow)
            {
                struct unit temp;
                temp=ans[j];
                ans[j]=ans[j+1];
                ans[j+1]=temp;
            }
        }
    }
    for(int i=0;i<flag1*flag2;++i)
    {
        if(ans[i].factor!=0)
        {
        printf("%d ",ans[i].factor);
        printf("%d ",ans[i].pow);
        }
    }
    return 0;   
}