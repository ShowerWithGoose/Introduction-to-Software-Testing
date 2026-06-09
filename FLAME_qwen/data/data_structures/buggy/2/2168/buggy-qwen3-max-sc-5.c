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
    return result; // @@ [This function incorrectly calculates the number by assuming all digits are processed in one go with decreasing powers of 10, but it doesn't update the index `i` in the caller, leading to reprocessing or skipping digits. Also, `p` is computed based on lookahead but then applied from the current position, which mismatches digit positions.]
}
int main(){
    gets(a); // @@ [`gets` is unsafe and deprecated; however, the immediate error is that the program fails to compile because `gets` may not be available in modern C libraries without defining macros, but more critically, the logic errors below cause incorrect evaluation. However, the reported error is "gcc: not found", which is environment-related, but per instructions we focus on logical/semantic errors causing wrong output. The real issue is in parsing and operator precedence handling.]
    char c=' ';
    squeez(a,c);
    int i=0,sum=0,num=0;
    num=trans_to_num(a,i); // @@ [The `trans_to_num` function returns a number but does not tell the caller how many characters were consumed, so `i` remains 0, causing infinite loops or incorrect parsing.]
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
            num*=trans_to_num(a,i); // @@ [Again, `i` is not advanced past the parsed number, so subsequent parsing starts at the same digit, leading to incorrect values or infinite loops.]
        }
        else if(a[i]=='/'){
            i++;
            num/=trans_to_num(a,i); // @@ [Same issue: `i` is not updated after reading the number, so parsing is broken.]
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
    num=trans_to_num(a,i); // @@ [Same problem: `i` not advanced after number parsing.]
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
            num*=trans_to_num(a,i); // @@ [Index `i` not updated after number parsing, leading to repeated use of same digit(s).]
        }
        else if(a[i]=='/'){
            i++;
            num/=trans_to_num(a,i); // @@ [Same indexing issue.]
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
            num=trans_to_num(a,i); // @@ [Again, `i` not advanced after this call, so next loop iteration may reprocess same digits.]
            record=a[i]; // @@ [If `trans_to_num` doesn't advance `i`, `a[i]` may still be a digit, causing `record` to be a digit instead of an operator, breaking logic.]
        }
    }        
    printf("%d",sum);

    return 0;
}