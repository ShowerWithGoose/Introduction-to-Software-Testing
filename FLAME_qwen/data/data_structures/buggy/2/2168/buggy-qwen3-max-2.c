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
    return result; // @@ [The logic for converting string to number is flawed. It assumes all digits are processed in one go and uses a power-of-10 multiplier that doesn't align with digit positions. For example, "123" would be calculated as 1*100 + 2*10 + 3*1 correctly only if p starts at 100, but the loop to compute p stops at j where a[j+1] is non-digit, so p ends up being 10^(length-1). However, the second loop increments i and divides p by 10 each time, which may work, BUT if called multiple times on overlapping segments (as in main), it will read beyond intended numbers because it doesn't stop at operator boundaries. Also, after reading a number, the caller doesn't update 'i' to the end of the number, leading to reprocessing same digits or skipping operators.]
}
int main(){
    gets(a); // @@ [Using gets() is unsafe and deprecated; however, the immediate issue is not safety but logic. More critically, the program fails to correctly parse multi-digit numbers due to flawed trans_to_num usage and index management.]
    char c=' ';
    squeez(a,c);
    int i=0,sum=0,num=0;
    num=trans_to_num(a,i); // @@ [This reads the first number starting at index 0, but trans_to_num does not return the new index, so 'i' remains 0. The subsequent while loop then scans from i=0 again, causing incorrect parsing.]
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
            num*=trans_to_num(a,i); // @@ [After incrementing i, trans_to_num is called at the new i (which points to start of next number), but trans_to_num doesn't tell us how many digits were consumed, so 'i' is not advanced past the number. Next iteration will start scanning from same i, leading to infinite loop or wrong parsing.]
        }
        else if(a[i]=='/'){
            i++;
            num/=trans_to_num(a,i); // @@ [Same issue: 'i' is not updated to end of parsed number, so subsequent parsing reuses same digits or misaligns.]
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
    num=trans_to_num(a,i); // @@ [Again, 'i' is not advanced after reading the number, so the following loop starts scanning from the middle of a number or wrong position.]
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
            num*=trans_to_num(a,i); // @@ [Same core problem: no update of 'i' after number parsing, leading to incorrect state.]
        }
        else if(a[i]=='/'){
            i++;
            num/=trans_to_num(a,i); // @@ [Same issue.]
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
            num=trans_to_num(a,i); // @@ [And again here — 'i' points to an operator (e.g., '+'), then i++ makes it point to next token start, but after trans_to_num, 'i' is not moved past the number, so next scan starts inside the number.]
            record=a[i]; // @@ [If trans_to_num didn't advance 'i', then a[i] may still be part of a digit, not an operator, causing record to be a digit character, leading to undefined behavior in later comparisons.]
        }
    }        
    printf("%d",sum);

    return 0;
}