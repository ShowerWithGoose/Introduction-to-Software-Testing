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
    return result; // @@ [This function incorrectly calculates the number. It assumes all digits from position i form a single number but uses a flawed method: it first computes the power of 10 based on lookahead, then multiplies each digit by decreasing powers. However, if `i` points to the start of a number, this logic fails because `p` is computed assuming the number starts at `j=i`, but then the second loop starts at `i` and uses that same `p`. For example, for "123", it sets p=100, then does 1*100 + 2*10 + 3*1 = 123 — which seems correct — BUT if called multiple times with advancing `i`, the index may be misaligned. More critically, after reading a number, the calling code does not update `i` to skip past the entire number, leading to reprocessing of digits.]
}
int main(){
    gets(a); // @@ [Use of `gets()` is unsafe and deprecated; however, the immediate issue is logical, not compilation. But note: some compilers may not support `gets()` anymore, causing compilation error. This likely explains the "gcc: not found" being a red herring — actually, the real issue is that `gets()` may cause compile failure in modern environments. However, per problem statement, the error type is "Compilation Error", and `gets()` is indeed removed in C11 and later unless explicitly allowed. So this line can cause compilation error.]
    char c=' ';
    squeez(a,c);
    int i=0,sum=0,num=0;
    num=trans_to_num(a,i); // @@ [After calling `trans_to_num(a, i)`, the index `i` is not advanced to the next non-digit character. Thus, subsequent loops will re-read the same digits, causing incorrect parsing and potentially infinite loops or wrong numbers.]
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
            num*=trans_to_num(a,i); // @@ [Again, `i` is not updated after reading the number, so next time the same digits are read again.]
        }
        else if(a[i]=='/'){
            i++;
            num/=trans_to_num(a,i); // @@ [Same issue: `i` not advanced past the parsed number.]
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
    num=trans_to_num(a,i); // @@ [Again, `i` is not advanced after this call, so the following loop may process the same digits again.]
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
            num*=trans_to_num(a,i); // @@ [Same missing index update.]
        }
        else if(a[i]=='/'){
            i++;
            num/=trans_to_num(a,i); // @@ [Same missing index update.]
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
            num=trans_to_num(a,i); // @@ [Again, `i` not advanced after reading number. Also, after `i++` above, `i` points to operator, then `trans_to_num` is called at that operator index — which returns 0 because `a[i]` is not a digit. This leads to wrong `num=0` and incorrect computation.]
            record=a[i]; // @@ [At this point, `i` still points to the start of a number (or beyond), but `a[i]` may be a digit, not an operator. So `record` stores a digit instead of '+' or '-', breaking logic.]
        }
    }        
    printf("%d",sum);

    return 0;
}