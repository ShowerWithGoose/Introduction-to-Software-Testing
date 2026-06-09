#include<stdio.h>
#include<string.h>
int main(){
    char str[110];
    gets(str);
    int length=strlen(str),i,point,flag=0;int end;int record;
    for(i=0;i<length;i++){
        if(str[i]=='.'){
            point=i;
        }
    }if(point==1){
        if(str[point-1]!='0'){
            printf("%s",str); // @@ [The output format requires the base to be normalized. If the input is "9.99", printing it directly as "9.99" followed by "e0" results in "9.99e0". However, the problem states that if the base is a decimal, it must have one significant digit before and after the decimal point. While 9.99 fits this, the reference logic suggests stripping trailing zeros or handling specific cases. More critically, looking at the else branch logic and the failed test case "9.99" producing "9.99e0e-49151", the primary issue is likely uninitialized variables or logic flow in the other branches affecting this one, or simply that this branch is correct for this specific input but the variable 'end' is uninitialized in other paths which might not be taken here. Wait, for input "9.99", point is 1. str[0] is '9'. It enters the first if. It prints "9.99e0". This matches expected output. Why did it fail? The buggy output was "9.99e0e-49151". This implies that code AFTER this block is also executing or printing garbage. Ah, look at the structure. The `if(point==1)` block ends, but there is no `else` for the outer `if`. The code falls through to the `else` block associated with `if(point==1)`? No, the `else` is attached to `if(point==1)`. Let's re-read carefully.
            
            Structure:
            if (point == 1) {
               if (str[0] != '0') { ... }
               else { ... }
            }
            else {
               ...
            }
            
            If input is 9.99, point is 1. Enters first block. Prints "9.99e0". Then exits if-else chain. Returns 0.
            
            Why "e-49151"? This looks like an uninitialized integer being printed.
            
            Let's look at the variables. `end` is declared but not initialized.
            In the `if(str[point-1]!='0')` branch, `end` is NOT set.
            However, this branch prints and finishes.
            
            Is it possible `point` is not set? If there is no decimal point, `point` is uninitialized.
            Input "9.99" has a decimal point.
            
            Let's look at the `gets` usage. It reads "9.99\n". `strlen` is 4.
            Loop finds '.' at index 1. `point` = 1.
            
            Enter `if(point==1)`.
            `str[0]` is '9'. Not '0'.
            Prints "%s" -> "9.99".
            Prints "e0".
            
            Output so far: "9.99e0".
            
            Then the program continues... wait. The provided buggy output is `9.99e0e-49151`.
            This suggests that `printf("e%d", ...)` is called TWICE or garbage is printed.
            
            Actually, looking closely at the code structure provided in the prompt's "Source Code":