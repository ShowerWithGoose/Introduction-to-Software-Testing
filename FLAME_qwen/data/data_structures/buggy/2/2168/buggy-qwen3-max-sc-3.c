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
    return result; // @@ [This function incorrectly calculates the number by using powers of 10 based on future digits, leading to wrong parsing. For example, for "123", it sets p=100 initially but then processes '1' * 100 + '2' * 10 + '3' * 1, which is correct, BUT the loop condition `a[j+1]` may go out of bounds and the logic fails when called at arbitrary positions during parsing because it assumes the entire remaining number is contiguous without considering operator boundaries.]
}
int main(){
    gets(a); // @@ [Use of unsafe `gets()` function which can cause buffer overflow; however, the immediate error in test case is not due to this but due to logic errors in number parsing and operator handling.]
    char c=' ';
    squeez(a,c);
    int i=0,sum=0,num=0;
    num=trans_to_num(a,i);
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
            num*=trans_to_num(a,i); // @@ [After multiplying, `i` is not advanced past the parsed number, causing re-parsing of same digits or misalignment. The `trans_to_num` function does not return how many characters were consumed, so `i` remains at operator position, leading to infinite loops or incorrect parsing.]
        }
        else if(a[i]=='/'){
            i++;
            num/=trans_to_num(a,i); // @@ [Same issue as above: `i` is not updated to skip the parsed number, so subsequent parsing starts at wrong location.]
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
    num=trans_to_num(a,i); // @@ [Again, `i` is not advanced after parsing the number, so the following loop will start parsing from the same digit again.]
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
            num*=trans_to_num(a,i); // @@ [Same core issue: `trans_to_num` doesn't update `i`, so `i` stays at operator, leading to repeated parsing of same number or invalid state.]
        }
        else if(a[i]=='/'){
            i++;
            num/=trans_to_num(a,i); // @@ [Same issue: `i` not advanced past the number, causing logic errors.]
        }
        else{
            if(record=='+'){
                sum+=num;
                i++; // @@ [Here `i` is incremented only by 1, but it should be positioned after the full number that was just processed. Since `i` was never moved past the number, this increment is insufficient and leads to parsing errors.]
            }
            else{
                sum-=num;
                i++; // @@ [Same problem: `i` is not correctly positioned after the number, so incrementing by 1 doesn't fix the misalignment.]
            }
            num=trans_to_num(a,i); // @@ [Parsing starts at incorrect position because `i` was not maintained properly through number parsing.]
            record=a[i]; // @@ [If `i` is beyond string or at unexpected location, this may read garbage or cause undefined behavior.]
        }
    }        
    printf("%d",sum);

    return 0;
}