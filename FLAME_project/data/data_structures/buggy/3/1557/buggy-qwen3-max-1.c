/*本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果*/
#include <stdio.h>
#include <string.h>

int main()
{
    char readnum[10001];
    char backnum[10001];//小数点之后的数字
    int i, j, k;
    int save_j;//储存0的个数
    
    gets(readnum);
    j = 0;
    k = 0;
    save_j = 0;
    
        if(readnum[0] == '0')
        {
            for(j = 0;j < strlen(readnum); j++)
            {
                if(readnum[j] != '0')
                {
                    save_j = j;
                }    
            }
            
            j--; // @@ [This decrements j after the loop, but j is already at strlen(readnum), so j-- makes it point to last char. However, the logic to extract significant digits is flawed. It should break at first non-zero after decimal, not find last non-zero.]
            
            for(k = 0;k < strlen(readnum); k++)
            {
                backnum[k] = readnum[j]; // @@ [This copies from position j onward, but j is near end of string; it should start copying from the first non-zero digit after leading zeros, not from j which is incorrectly set. Also, this overwrites backnum with repeated same char if j doesn't change.]
                j++;
            }
            
            if(strlen(backnum) > 1)//判断是否需要小数点
            {
                for(j = strlen(backnum) ;j > 1; j--)
                {
                    backnum[j] = backnum[j - 1]; // @@ [This shifts characters right to insert '.', but backnum was not null-terminated and contains garbage beyond copied part. Also, logic assumes all chars in backnum are valid, which they aren't.]
                }
                backnum[1] = '.';
            }
            printf("%se-%d\n", backnum, save_j-1); // @@ [Exponent is wrong: for "0.00000009...", first non-zero is at index 8 (0-based: '0','.','0'...,'9'), so exponent should be -(8-1)= -7? Actually, correct exponent is -8 because 0.00000009 = 9e-8. But save_j is index of '9', which is 8, so e-(8-1)=e-7 is wrong. Should be e-(save_j - 1) only if counting after decimal starts at index 2. Correct exponent is -(save_j - 1) when save_j is index of first non-zero, but since input starts with "0.", decimal starts at index 1, so first digit after decimal is index 2. So number of leading zeros after decimal is (save_j - 2), so exponent = -(save_j - 1). Wait: 0.00000009 -> 9e-8, and '9' is at index 8 (0:'0',1:'.',2:'0',...,8:'9'), so exponent = -(8 - 1) = -7? No: 10^-8 means 8 places after decimal before 9, so exponent is -8. The correct formula is: if first non-zero digit is at position p (0-based), and decimal point is at position 1, then exponent = -(p - 1). For p=8, exponent = -7? That contradicts. Let's count: 0.0(1)0(2)0(3)0(4)0(5)0(6)0(7)9(8)... → 8th digit after decimal is 9, so value = 9 × 10^-8. Position of '9' is index 8 (0-based in string "0.00000009..."), so number of zeros after decimal before 9 is 7, so exponent = -8. Thus exponent = -(position_of_first_nonzero - 1). Since decimal is at index 1, digits after decimal start at index 2. So if first non-zero is at index i, then its place value is 10^(1 - i). So exponent = 1 - i. For i=8, exponent = 1-8 = -7? That gives 9e-7 = 0.0000009, but we have 0.00000009 = 9e-8. So actually, digit at index 2 is 10^-1, index 3 is 10^-2, ..., index i is 10^(1 - i). So for i=8, 10^(1-8)=10^-7, but we need 10^-8. Wait: index 2 → 1st digit after decimal → 10^-1, index 3 → 2nd → 10^-2, ..., index k → (k-1)th digit → 10^-(k-1). So for '9' at index 8, it's the 7th digit after decimal? No: index 2:1st, 3:2nd, 4:3rd, 5:4th, 6:5th, 7:6th, 8:7th → 10^-7. But 0.00000009 has 7 zeros then 9 → 8 digits after decimal before 9? No: "0." then 7 zeros then 9 → total 8 digits after decimal, 9 is 8th → 10^-8. So index of '9' is 1 (for '0') + 1 (for '.') + 7 zeros + 1 = 10? Wait input is "0.00000009123456789012" — let's count: positions: 0:'0',1:'.',2:'0',3:'0',4:'0',5:'0',6:'0',7:'0',8:'0',9:'9',... So '9' is at index 9. Then exponent should be -8 because it's the 8th digit after decimal (positions 2 to 9: 8 digits, 9 is 8th). So exponent = -(9 - 1) = -8? 9-1=8, so -8. Yes! So if first non-zero is at index i, exponent = -(i - 1). In code, save_j is set to j where readnum[j]!='0', but the loop runs through entire string and save_j ends up as last non-zero, not first! That's the critical error.]
            
        }//原小数小于1；
        
        if(readnum[0] != '0')
        {
            for(j = 0;j < strlen(readnum); j++)
            {
                if(readnum[j] == '.')
                {
                    save_j = j;
                    break;
                }
            }//读取e的指数
            
            for(i = 0;i < strlen(readnum); i++)
            {
                if(readnum[i] != '.')
                {
                    backnum[k] = readnum[i];
                    k++;
                }
            }
                        
            if(k > 1)//判断是否需要小数点
            {
                for(j = strlen(backnum) ;j > 1; j--)
                {
                    backnum[j] = backnum[j - 1]; // @@ [backnum is not null-terminated, so strlen(backnum) is undefined (reads garbage). Also, shifting assumes backnum has valid length, but k is actual length. Should use k instead of strlen(backnum).]
                }
                backnum[1] = '.';
            }
                        
            if(save_j == 1)
            {
                printf("%se0", readnum); // @@ [If input is like "5.123", save_j=1 (decimal at index1), but output should be "5.123e0", but code prints original readnum which includes decimal, so that's okay. However, if input has trailing zeros, problem states there are none, so maybe okay. But major issue is in the <1 case.]
            }
            else
            {
                printf("%se%d\n", backnum, save_j-1);
            }
            
        }    
    
    return 0;
}