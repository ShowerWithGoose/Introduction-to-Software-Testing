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
    return result; // @@ [This function incorrectly parses multi-digit numbers. It calculates the place value 'p' based on the number of digits ahead, but then uses it from the first digit onward, effectively reversing the digit order. For example, "123" becomes 1*100 + 2*10 + 3*1 = 123 in normal parsing, but this code does: p starts at 100 (for 3 digits), then result = 1*100 + 2*10 + 3*1 = 123 — which seems correct, BUT the loop condition `a[j+1]` may go out of bounds and the logic fails when called at arbitrary positions without ensuring that `i` points to the start of a number. More critically, after parsing, the caller does not update `i` to skip the parsed digits, causing re-parsing or misalignment.]
}
int main(){
    gets(a);
    char c=' ';
    squeez(a,c);
    int i=0,sum=0,num=0;
    num=trans_to_num(a,i); // @@ [The index `i` is not advanced after reading the first number. So if the first number is "24", `i` remains 0, and subsequent parsing will start again from the same position, leading to incorrect behavior.]
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
            num*=trans_to_num(a,i); // @@ [After calling trans_to_num(a,i), the index `i` is not updated to point past the parsed number. This causes the next operator or digit to be misread, as `i` still points to the start of the number just parsed.]
        }
        else if(a[i]=='/'){
            i++;
            num/=trans_to_num(a,i); // @@ [Same issue: `i` is not advanced after parsing the number, so the parser loses track of position.]
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
    num=trans_to_num(a,i); // @@ [Again, `i` is not advanced after parsing this number. The function trans_to_num reads digits starting at `i`, but `i` remains unchanged, so the following loop will reprocess the same digits.]
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
            num*=trans_to_num(a,i); // @@ [Index `i` not updated after number parsing — same critical flaw.]
        }
        else if(a[i]=='/'){
            i++;
            num/=trans_to_num(a,i); // @@ [Index `i` not updated after number parsing.]
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
            num=trans_to_num(a,i); // @@ [Index `i` not advanced after parsing number. Additionally, `record=a[i]` reads the operator, but if `i` hasn't moved past the number, `a[i]` might still be a digit or invalid.]
            record=a[i]; // @@ [This reads the operator, but because `i` was not advanced after parsing the previous number, `a[i]` may not be the operator but part of the number or garbage.]
        }
    }        
    printf("%d",sum);

    return 0;
}