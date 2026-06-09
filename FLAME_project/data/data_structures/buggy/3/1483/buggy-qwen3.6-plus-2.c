#include <stdio.h>
#include <string.h>
char numf[10086];
char numzheng[10086];
char numxiao[10086];
int main(){
    gets(numf);
    int ep=0;///////////////////第一位非零时e后数字 
    /////////////////////////////-----找小数点
    int dot=0; //小数点位置 
    int end=0;//字符末尾
    int flag=0; //是否有小数点 
    int i=0;
    for(i=0;numf[i]!='\0';i++){
        end++;
        if(numf[i]=='.'){
            dot=i;
            flag=1;
        }
    }
    end++;
    ////////////////////////////////////

    /////////////////////////////-----------若是整数无小数点
    if(flag==0){
        printf("%c.",numf[0]);
        int m;
        int ez=0;
        for(m=1;numf[m]!='\0';m++){
            ez++;
            printf("%c",numf[m]);
        
        }
            printf("e%d",ez);
    } 
    /////////////////////////////////////
    
    else{/////////////////若无小数点 
    //////////////////////////-------数小数点前数字
    int j=0;
    for(j=0;numf[j]!='.';j++){
        
        
        if(numf[0]=='0'){
            ep=0;
            numzheng[0]='0';
            break;
        }
        else{
            numzheng[j]=numf[j];
            ep++;
        }
        numzheng[j+1]='\0';
    }
    /////////////////////////////////
    
    ///////////////////////////////---------数小数点后数字 
    

    strcpy(numxiao,numf);

    int v;
    for(v=0;numxiao[v]!='\0';v++){
        numxiao[v]=numxiao[v+dot+1];
    }


    //////////////////////////////

    //////////////////////////////----------数小数点后0的个数
    int em=0;//小数点后0的个数 
    int a=0;
    for(a=0;numxiao[a]!='\0';a++){
        if(numxiao[a]!='0'){
            break;
        }
        em++;
    }

    ///////////////////////////////////
    

    
    
    
    ////////////////////////////////////----------输出
    
    if(ep>0){//XXXX.XXXX
        printf("%c.",numzheng[0]);
        int c;
        for(c=1;c<dot;c++){
            printf("%c",numzheng[c]);
        }
        int d;
        for(d=0;d<(end-dot-1);d++){//!!!
            printf("%c",numxiao[d]);
        }
        printf("e%d",ep-1);

    }     
    else if((ep==0)&&(em==0)){//0.XXXXXe0型 
        printf("%c",numxiao[0]);
        if(numxiao[1]!='\0'){
            printf(".");
        }
        int t;
        for(t=1;numxiao[t]!='\0';t++){
            printf("%c",numxiao[t]);
        }
        printf("e%d",em-1);
    }
    else if((ep==0)&&(em>0)){//X.XXXXXe-X型 
        printf("%c.",numxiao[em]);
        int b;
        for(b=em+1;b<(end-dot-1);b++){//!!!
            printf("%c",numxiao[b]);
            } 
            printf("e-%d",em+1); // @@ The format specifier "e-%d" prints a literal '-' followed by the positive value of em+1. While this produces the correct visual output for negative exponents, standard scientific notation usually handles the sign via the integer value itself (e.g., printf("e%d", -(em+1))). However, looking at the specific failure: Input 0.00000009123456789012. em=7. Output should be e-8. Code prints e-8. Wait, let's re-read the bug report.
            // Buggy Output: 9.123456789012 e-8 (There is a space or null char?)
            // Expected Output: 9.123456789012e-8
            // The buggy output shown in the prompt is `9.123456789012 e-8`? No, it says `9.123456789012 e-8` vs `9.123456789012e-8`.
            // Actually, looking closely at the provided "Buggy Output": `9.123456789012 e-8`. There seems to be a garbage character or space.
            // Let's look at the loop condition: `b<(end-dot-1)`.
            // `end` was calculated as length of string + 1 (because of `end++` after loop).
            // `dot` is index of '.'.
            // `numxiao` contains the fractional part.
            // The loop prints characters from `numxiao`.
            // The issue is likely that `numxiao` is not properly null-terminated or contains garbage from the `strcpy` and shift operation if the source string wasn't long enough or if the shift overwrote incorrectly.
            // However, the most obvious error in these types of problems is usually trailing zeros or incorrect bounds.
            // The problem states: "no trailing zeros after the decimal point".
            // The code prints up to `end-dot-1`. This includes all digits from the original input's fractional part.
            // If the input is `0.00000009123456789012`, `numxiao` becomes `00000009123456789012`.
            // `em` is 7. `numxiao[7]` is '9'.
            // It prints `9.` then loops `b` from 8 to `end-dot-1`.
            // The output looks correct visually in logic.
            // Let's look at the `else if((ep==0)&&(em==0))` block.
            // And the first block `if(ep>0)`.
            
            // Let's re-evaluate the `gets` and `end` calculation.
            // `gets` reads until newline.
            // Loop `for(i=0;numf[i]!='\0';i++)` increments `end` for each char.
            // After loop, `end++`. So `end` is `strlen(numf) + 1`.
            // `dot` is index of '.'.
            // `end - dot - 1` is `strlen(numf) + 1 - dot - 1` = `strlen(numf) - dot`.
            // This is the number of characters AFTER the dot, including the null terminator? No.
            // Example: `0.12`. strlen=4. dot=1. end=5.
            // `end-dot-1` = 5-1-1 = 3.
            // `numxiao` after shift: `12\0...`
            // Indices: 0:'1', 1:'2', 2:'\0'.
            // Loop `b` from `em+1` (if em=0, b=1) to `< 3`.
            // Prints `numxiao[1]` ('2') and `numxiao[2]` ('\0' or garbage?).
            // Printing `\0` might result in nothing or weird behavior depending on terminal, but typically `printf("%c", '\0')` prints nothing.
            // However, if `numxiao` has garbage after the null terminator because `strcpy` copied the whole buffer? No, `strcpy` stops at null.
            // But the shift loop: `for(v=0;numxiao[v]!='\0';v++) numxiao[v]=numxiao[v+dot+1];`
            // This relies on `numxiao` having the original string.
            // `strcpy(numxiao, numf)` copies `0.12\0`.
            // Shift:
            // v=0: `numxiao[0] = numxiao[2]` ('1'). `numxiao` is `1.12\0`? No, `numxiao` is being modified in place.
            // `numxiao` initially `0.12\0`.
            // v=0: `numxiao[0] = numxiao[0+1+1]` = `numxiao[2]` = '1'. `numxiao` becomes `1.12\0`.
            // v=1: `numxiao[1] = numxiao[1+1+1]` = `numxiao[3]` = '2'. `numxiao` becomes `12.2\0`.
            // v=2: `numxiao[2] = numxiao[2+1+1]` = `numxiao[4]` = '\0'. `numxiao` becomes `12\0\0`.
            // v=3: `numxiao[3]` is '\0'. Loop terminates.
            // So `numxiao` is `12\0`.
            // Length is 2.
            // `end-dot-1` was 3.
            // Loop prints indices 1 and 2.
            // Index 1 is '2'. Index 2 is '\0'.
            // Printing `\0` is the issue? It shouldn't print a space.
            
            // Let's look at the specific failing case: `0.00000009123456789012`
            // `numf`: `0.00000009123456789012\0`
            // `dot`: 1.
            // `strlen`: 22.
            // `end`: 23.
            // `end-dot-1`: 23-1-1 = 21.
            // `numxiao` shift:
            // Copies `00000009123456789012\0` to start of `numxiao`.
            // `numxiao` content: `00000009123456789012\0`.
            // `em`: 7 (seven zeros).
            // Print `numxiao[7]` ('9') and `.`.
            // Loop `b` from 8 to `< 21`.
            // Indices 8 to 20.
            // `numxiao` valid indices: 0 to 20 (digits), 21 is `\0`.
            // Wait, `strlen` of fractional part is 20.
            // Indices 0..19 are digits. Index 20 is `\0`.
            // The loop goes up to 20 (`< 21`).
            // So it prints `numxiao[20]` which is `\0`.
            // Does `printf("%c", '\0')` produce output? Usually no.
            // Why is there a space/garbage in "Buggy Output"?
            // Maybe the `end` calculation is wrong?
            // `end` starts at 0. Loop runs for i=0 to 21 (strlen 22). `end` becomes 22.
            // Then `end++` makes it 23.
            // Correct length of fractional part is `strlen(numf) - dot - 1` = 22 - 1 - 1 = 20.
            // The code uses `end - dot - 1` = 23 - 1 - 1 = 21.
            // It iterates one too many times, accessing the null terminator.
            // If the judge system considers printing `\0` as an error or if it manifests as a space/control char, this is the bug.
            // The fix is to use `strlen(numxiao)` or correct the bound.
            // Since I must annotate the line with the error:
            // The loop bound `b<(end-dot-1)` is incorrect because `end` includes an extra increment and potentially accesses beyond the valid string data of `numxiao` (specifically the null terminator or garbage if `numxiao` wasn't perfectly null-terminated right after the digits).
            // Actually, simpler explanation: `end` is `strlen(numf) + 1`. The number of fractional digits is `strlen(numf) - dot - 1`.
            // The code calculates limit as `strlen(numf) + 1 - dot - 1` = `strlen(numf) - dot`.
            // This is exactly 1 greater than the number of fractional digits.
            // So it prints one extra character (the null terminator).
        }
    
}
return 0;
}