#include <stdio.h>
#include <string.h>
char a[10000];
void squeez(char s[], char c) /*删除某个字符c*/{
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c){
            s[j++] = s[i];
        }
    s[j] = '\0';
}
int trans_to_num(char* a,int i){
    int p=1,result=0;
    for(int j=i;a[j+1]>='0'&&a[j+1]<='9';j++){
        p*=10;
    }
    for(;a[i]>='0'&&a[i]<='9';i++){
        result+=(a[i]-'0')*p;
        p/=10;
    }
    return result; // @@ [This function incorrectly calculates the number. It assumes all digits from position i form a single number but uses a flawed method: it first computes the power of 10 based on lookahead, then multiplies each digit by decreasing powers. However, if `i` is not at the start of a number or if the string ends unexpectedly, this leads to wrong results. Also, it doesn't update the index `i` in the caller, so parsing continues from the same digit repeatedly.]
}
int main(){
    gets(a); // @@ [Use of `gets()` is unsafe and deprecated; however, the immediate issue is that the program logic fails to correctly parse multi-digit numbers due to the flawed `trans_to_num` function. Additionally, after removing spaces, the parsing loop does not correctly advance the index past the digits of a number, causing infinite loops or incorrect reads.]
    char c=' ';
    squeez(a,c);
    int i=0,sum=0,num=0;
    num=trans_to_num(a,i); // @@ [The function `trans_to_num` returns an incorrect value because it doesn't properly handle the digit sequence starting at `i`. Moreover, `i` is not advanced to the next operator, so subsequent parsing starts at the same digit again.]
    while(1){
        while (a[i]!='='&&a[i]!='+'&&a[i]!='-'&&a[i]!='*'&&a[i]!='/'){
            i++;
        }
        if(a[i]=='='){
            sum=num;
            break;
        }
        else if(a[i]=='*'){
            i++;
            num*=trans_to_num(a,i); // @@ [Same issue: `trans_to_num` is called with current `i` pointing to a digit, but after multiplication, `i` is not updated to skip the consumed digits, leading to reprocessing the same digits or misalignment.]
        }
        else if(a[i]=='/'){
            i++;
            num/=trans_to_num(a,i); // @@ [Same as above: index `i` is not advanced past the parsed number, causing incorrect parsing in subsequent steps.]
        }
        else{
            break;
        }
    }
    if(a[i]=='='){
        printf("%d",sum);
        return 0;
    }
    sum+=num;
    num=0;
    char record=a[i];
    i++;
    num=trans_to_num(a,i); // @@ [Again, `trans_to_num` is used without updating `i` to reflect how many digits were consumed, so the following loop may start inside the middle of a number or re-read the same digit.]
    while(1){
        while(a[i]!='='&&a[i]!='+'&&a[i]!='-'&&a[i]!='*'&&a[i]!='/'){
            i++;
        }
        if(a[i]=='='){
            if(record=='+'){
                sum+=num;
            }
            else{
                sum-=num;
            }
            break;
        }
        else if(a[i]=='*'){
            i++;
            num*=trans_to_num(a,i); // @@ [Index `i` is incremented once before calling `trans_to_num`, but `trans_to_num` doesn't tell how many digits it read, so `i` remains at the first digit of the number, causing infinite loop or wrong parsing.]
        }
        else if(a[i]=='/'){
            i++;
            num/=trans_to_num(a,i); // @@ [Same indexing error: `i` is not advanced past the full number, leading to repeated processing of the same digit(s).]
        }
        else{
            if(record=='+'){
                sum+=num;
                i++;
            }
            else{
                sum-=num;
                i++;
            }
            num=trans_to_num(a,i); // @@ [Once more, `trans_to_num` is called with `i` at a digit, but after this, the loop continues without knowing how far into the string the number extended, breaking synchronization.]
            record=a[i]; // @@ [If `trans_to_num` consumed multiple digits, `i` still points to the first digit, so `record=a[i]` reads a digit instead of an operator, causing undefined behavior or incorrect logic.]
        }
    }        
    printf("%d",sum);

    return 0;
}