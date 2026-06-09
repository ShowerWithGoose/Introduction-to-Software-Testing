#include<stdio.h>
#include<string.h>
int main()
{
    char num[108],ans[108];
    gets(num);
    int k;
    int i;
    int len=strlen(num);
    for(i=0;i<len;i++)
    {
        if(num[i]=='.')
        {
            k=i;
            break;
        }
        
    }
    int m,n;
    if(k==1)
    {
        if(num[0]=='0'){
        
        for(i=2;i<len;i++)
        {
            if(num[i]!='0')
            {
                m=i;
                break;
            }
        }
        ans[0]=num[m];
        if(m!=(len-1))
        {      ans[1]='.';
            for(i=m+1,n=2;i<len;i++,n++)
            {
                ans[n]=num[i];
            }
        }
        else
        {n=1;
        }
        for(int j=0;j<n;j++)
        {
            printf("%c",ans[j]);
        }
        printf("e-%d",m-1);
        
    }
    else
    {
        for(int i=0;i<len;i++){
            printf("%c",num[i]);}
            printf("e0");
        
    }
}
else 
{
    ans[0]=num[0];
    ans[1]='.';
    for(  i=1,m=2;i<len;i++)
    {   
        if(num[i]!='.')
        {
            ans[m]=num[i];
            m++;
        }
    }
    for(int i=0;i<len-1;i++) // @@ The loop condition `i<len-1` causes the last character of the significant digits (which is stored at index `len-2` in `ans` effectively, or rather, the loop stops one character short of the full mantissa) to be missed. Specifically, `m` ends up being the length of the mantissa string in `ans`. The loop should print up to `m`, not `len-1`. In the specific test case, the input has many digits. The logic `for(int i=0;i<len-1;i++)` prints characters from `ans` based on the original input length minus 1, but `ans` is constructed differently. More critically, looking at the construction: `ans` gets `num[0]`, `.`, then all other digits except `.`. So `ans` has length `len-1`. The loop `i<len-1` prints indices `0` to `len-2`. This misses the last digit stored in `ans[len-2]`? No, `ans` indices are `0` to `len-2`. Wait. Input `87899.99...`. Len = L. Dot at k. `ans` size is L-1. Indices 0 to L-2. Loop `i < L-1` prints 0 to L-2. This seems correct for printing `ans`. However, let's look closer at the failure. Input: `87899.9999999999000999`. Output: `8.7899999999999900099e4`. Expected: `8.78999999999999000999e4`. The output is missing the last '9'. The input length is 24. `k`=5. `ans` construction: `ans[0]='8'`, `ans[1]='.'`. Then copies `7`,`8`,`9`,`9`,`9`,`9`,`9`,`9`,`9`,`9`,`9`,`9`,`0`,`0`,`0`,`9`,`9`,`9`. Total digits after dot: 19. Total length of `ans` string content is 1 + 1 + 19 = 21. Indices 0..20. `len` is 24. `len-1` is 23. Loop `i<23` tries to print `ans[0]` to `ans[22]`. But `ans` only has valid data up to `ans[20]`. `ans[21]` and `ans[22]` are uninitialized/garbage. Wait, if it prints garbage, why is it missing a 9? Let's re-read the code carefully. `for( i=1,m=2;i<len;i++) { if(num[i]!='.') { ans[m]=num[i]; m++; } }`. This loop runs `i` from 1 to 23. `m` increments for every non-dot char. There are 23 non-dot chars. So `m` goes from 2 to 24. `ans` indices filled: 0, 1, then 2..23. So `ans` has 24 characters? No. `num` has 24 chars. One is dot. 23 are digits. `ans[0]` is digit. `ans[1]` is dot. 21 more digits. Total 23 chars in `ans`. Indices 0 to 22. `m` ends at 23. The printing loop: `for(int i=0;i<len-1;i++)`. `len-1` is 23. So it prints `ans[0]` to `ans[22]`. This should be correct. Why is the last 9 missing? Ah, `gets` might include newline? No, `gets` removes newline. Let's check the test case length. `87899.9999999999000999`. Count: 5 before dot, 18 after? `9999999999` (10) `000999` (6). Total 16 after? No. `9999999999000999`. 10+6=16. Total digits 5+16=21. Plus dot = 22. `len`=22. `k`=5. `ans` size: 1 (first) + 1 (dot) + 20 (remaining digits) = 22 chars. Indices 0-21. `m` ends at 22. Print loop `i < 21`. Prints 0-20. Misses `ans[21]` which is the last digit. The condition should be `i < m` or `i < len - 1` is wrong because `len-1` is 21, so `i` goes 0..20. It misses the last character. The number of characters in `ans` is `len - 1` (since we removed the dot). So indices are `0` to `len - 2`. The loop `i < len - 1` prints `0` to `len - 2`. This IS correct for the count. Wait. If `len`=22. `len-1`=21. Loop `i<21` prints 0..20. Total 21 chars. But `ans` has 22 chars? No. `num` has 22 chars. Remove dot -> 21 chars. `ans` has 21 chars. Indices 0..20. So printing 0..20 is correct. Why is output short? Maybe `len` calculation or `gets` behavior? Or maybe the input string in the problem description has different length? "87899.9999999999000999". 5 digits + dot + 16 digits = 22 chars. Output `8.7899999999999900099` has 1 digit + dot + 17 digits? `789999999999900099`. Count: 18 digits. Total 20 chars. Exponent 4. Original: 87899. 8.7899... e4. Correct. The output has 17 decimal places? `789999999999900099`. 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18. 18 digits. Input decimal part: `9999999999000999`. 16 digits. Integer part `87899`. Remaining digits `7899`. Total fractional digits in sci notation: 4 + 16 = 20? No. `8.7899...` The digits are `7,8,9,9` from integer part and `9999999999000999` from fractional. Total 4+16=20 digits after decimal point. Output has 18. It is missing 2 digits? The expected output `8.78999999999999000999` has `7899999999999000999`. Count: 19 digits. Wait. `87899`. Digits: 8,7,8,9,9. Sci: 8.7899... Exponent 4. Digits after decimal: 7,8,9,9 (from 87899) and 9999999999000999. Total 4 + 16 = 20 digits. Expected output: `8.78999999999999000999`. Let's count digits after dot: `7899999999999000999`. 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19. 19 digits. Where is the 20th? Input: `87899.9999999999000999`. Digits: 8,7,8,9,9, ., 9,9,9,9,9,9,9,9,9,9,0,0,0,9,9,9. Total 22 chars. Non-dot digits: 21. Sci notation: 1 before dot, 20 after dot. Expected output string: `8.78999999999999000999e4`. Digits after dot: `7899999999999000999`. Count: 19. Is the input truncated in my counting? `9999999999` is 10 nines. `000999` is 3 zeros 3 nines. Total 16. Plus 4 from integer part = 20. Why does expected have 19? Maybe the last 9 is cut off in expected? Or my count of input is wrong. `87899.9999999999000999`. Let's paste into counter. 87899 (5) . (1) 9999999999 (10) 000999 (6). Total 22. Okay. If expected has 19 digits after dot, it's missing one. But buggy output has 18. So buggy is missing 2 compared to expected? Or 1 compared to actual? Regardless, the loop bound `len-1` is suspicious because `ans` length is `len-1`. Indices `0` to `len-2`. Loop `i < len-1` accesses `0` to `len-2`. This is correct. HOWEVER, `ans` is not null-terminated properly or `m` tracks the end. Using `m` is safer. The error is likely that `len-1` is incorrect if `ans` length differs or if there's an off-by-one. Actually, if `len` is 22, `len-1` is 21. Loop 0..20. `ans` has 21 chars (indices 0..20). It prints all. So where is the drop? Ah, `gets` is dangerous. But assuming standard behavior. Let's look at `else` block again. `for( i=1,m=2;i<len;i++)`. If `num` has newline? No. Is it possible `strlen` includes newline? No. What if the input buffer `num` isn't cleared? No. Let's look at the Buggy Output again: `8.7899999999999900099e4`. Ends in `99`. Expected `...999e4`. Ends in `999`. It's missing exactly one `9` at the end. My count of expected digits was 19. If expected is correct, and input has 20 fractional digits, then expected is also missing one? Or maybe input has 19 fractional digits? `9999999999000999`. 10+6=16. 16+4=20. If expected has 19, then expected is wrong? No, we must match expected. If expected is `...999`, and buggy is `...99`, buggy is missing one `9`. The loop `i < len - 1` prints `len - 1` characters. `ans` contains `len - 1` characters. So it prints everything. UNLESS `len` is calculated incorrectly or `ans` is shorter. Wait! `ans` is defined as `char ans[108]`. It is not initialized. If the loop `for( i=1,m=2;i<len;i++)` fills `ans`, it relies on `num`. If `num` has a newline at the end (some judges do this if `gets` is replaced or if input format varies), `strlen` might differ. But `gets` strips newline. Is it possible the issue is `printf("%c",ans[i])` vs `puts`? No. Let's look at the variable `m`. `m` holds the next index to write. At the end of the loop, `m` is the length of the string in `ans`. The print loop uses `len-1`. If `len-1` != `m`, there's a bug. `m` starts at 2. Increments for every `i` from 1 to `len-1` where `num[i] != '.'`. There is exactly one dot. So `m` increments `len - 1` times. Start 2. End `2 + len - 1 = len + 1`. Wait. `i` goes 1 to `len-1` (inclusive? No, `i<len`). So `i` takes `len-1` values. One is dot. `len-2` are digits. `m` increments `len-2` times. Initial `m=2`. Final `m = 2 + len - 2 = len`. So `ans` has indices `0` to `len-1`. Total `len` characters? No. `ans[0]`, `ans[1]` set manually. Then `len-2` digits. Total `1 + 1 + len - 2 = len`. So `ans` has `len` characters. Indices `0` to `len-1`. The print loop `i < len - 1` prints `0` to `len-2`. It misses `ans[len-1]`, which is the last digit. THIS IS THE BUG. The condition should be `i < m` or `i < len`. Since `m` equals `len` at the end. ]
    for(int i=0;i<len-1;i++) // @@ The loop condition `i<len-1` causes the last digit of the mantissa to be skipped. The array `ans` contains `len` characters (indices 0 to len-1), but the loop only prints up to index `len-2`. It should be `i < m` or `i < len`.
    {                  
        printf("%c",ans[i]);
              
        
}
printf("e%d",k-1);
    
}
return 0;        }