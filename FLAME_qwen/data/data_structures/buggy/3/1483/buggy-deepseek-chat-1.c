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
        printf("e%d",em-1); // @@ [Error: When em==0, em-1 is -1, but the exponent should be 0 for numbers like 0.1234 (e.g., 0.1234 -> 1.234e-1, not e-1). The logic for computing exponent when the integer part is 0 and there are no leading zeros after decimal is incorrect; it should be -1 (since moving decimal point one place right gives exponent -1), but here em-1 = -1, which is correct for 0.1234? Actually for 0.1234, the first non-zero digit is at position 1 after decimal, so exponent should be -1, but em=0 gives -1, which is correct. However, the problem expects no trailing zeros and significant digits, so this might be okay, but the main error is that the exponent calculation for the case ep==0 and em==0 is wrong because it should be -1, not em-1 (which is -1, so it's accidentally correct? Wait, let's re-check: For input "0.1234", dot=1, end=6, numxiao="1234", em=0, ep=0. The output should be "1.234e-1". The code prints numxiao[0]='1', then '.' and rest, then "e-1". That's correct. But for input "0.00123", dot=1, end=7, numxiao="00123", em=2, ep=0, then it goes to else if (ep==0 && em>0) branch, which prints "1.23e-3" (since em+1=3). That's correct. So the error is not here. The actual error is in the integer case (flag==0) where it always prints a decimal point even for single-digit integers like "5" -> should output "5e0" but code outputs "5.e0"? Actually problem says if it's an integer, it contains only one significant digit without a decimal point. So for "5", output should be "5e0", not "5.e0". That's one error. Also, the code does not handle negative numbers at all. The problem input has no sign, but the reference program handles negative? Actually problem says input has no sign, so negative not needed. But the main error is that for integer input like "123", the code outputs "1.23e2" which is correct? Wait, "123" should become "1.23e2"? Actually 123 in scientific notation is 1.23e2, yes. But the code prints "1.23e2" correctly? Let's check: flag==0, numf[0]='1', then loop from m=1 prints '2','3', ez=2, prints "e2". So output "1.23e2" correct. But for "5", output "5.e0" which is wrong because it has a decimal point. The problem says if it's an integer (only one digit), it should be without decimal point. So that's an error. Also, for input like "0.0"? But problem says all digits are significant and no trailing zeros, so "0.0" not allowed. Another error: In the integer case, the code does not handle the case where the number is just "0"? But input has digits before and after decimal point, so "0" alone not allowed. However, the main logical error is in the integer branch: it always prints a decimal point after the first digit, which is incorrect for single-digit integers. Also, the code uses gets() which is unsafe and deprecated, but that's not a logical error. The most critical error is that for numbers like "0.00123", the code works, but for "0.1234" it also works. However, there is a bug in the integer branch: for input "10", dot=1, flag=1, so goes to else branch. ep>0? numf[0]='1', so ep=1, numzheng[0]='1', then prints "1.", then loop c from 1 to dot-1 (c<1) does nothing, then prints numxiao (which is "0"), so output "1.0e0"? Actually ep-1=0, so "1.0e0". But expected output for "10" is "1e1"? Wait, 10 in scientific notation is 1e1 (or 1.0e1? Usually 1e1). The problem says base can be integer or decimal with one digit before and after decimal point. So "1.0e1" is acceptable? But the problem says if it's a decimal, it must have one significant digit before and after the decimal point, and no trailing zeros. "1.0" has a trailing zero after decimal, which is not allowed because all digits are significant and no trailing zeros. So "10" should become "1e1" (integer base) or "1.0e1" is invalid because of trailing zero. So the code incorrectly outputs "1.0e0" which is wrong exponent and wrong base. The correct output for "10" should be "1e1". So the error is in the handling of numbers where the integer part has more than one digit and the decimal part is zero? But input has no trailing zeros, so "10" is not allowed because it has a trailing zero after decimal? Actually "10" has no decimal point, so it's an integer. The problem says input has digits before and after the decimal point, so "10" is not a valid input because it has no decimal point. So the integer branch is for inputs without decimal point, which according to problem description should not occur because input always has a decimal point. So the integer branch is unnecessary and incorrect. The main error is that the program does not handle the case where the integer part is zero and the first non-zero digit is after the decimal point correctly for all cases? Actually it seems to work for the given test cases? But the test case input is empty? The buggy output shows "gcc: not found" which is a compilation error due to missing compiler, not a logical error. The user says "Error type: Compilation Error" but the provided code has no syntax errors. The buggy output is from the shell, not from the program. So the actual error is that the program fails to compile? But the code compiles fine. Perhaps the issue is that the program uses gets() which is removed in C11, causing a compilation error in some environments. That is a compilation error. So the error is on the line with gets(). Also, the code has a logical error in the integer branch as described, but the main error causing compilation failure is gets(). So I will mark the gets() line.
}
return 0;
}