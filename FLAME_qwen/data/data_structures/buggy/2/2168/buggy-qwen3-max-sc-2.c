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
    return result; // @@ [This function incorrectly calculates the number by assuming all digits are processed in one go with decreasing powers of 10, but it doesn't update 'i' correctly for the caller, leading to reprocessing or skipping digits. Also, 'p' is calculated based on lookahead but then applied from the current position, which mismatches digit positions.]
}
int main(){
    gets(a); // @@ [Use of unsafe function 'gets' which is deprecated and may cause buffer overflow; however, this is not the direct cause of logical error but contributes to undefined behavior risk. The main issue is logical in expression parsing.]
    char c=' ';
    squeez(a,c);
    int i=0,sum=0,num=0;
    num=trans_to_num(a,i); // @@ [The function trans_to_num does not return the new index after parsing the number, so 'i' remains 0, causing infinite loops or incorrect parsing in subsequent steps.]
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
            num*=trans_to_num(a,i); // @@ [Again, 'i' is not updated to the end of the parsed number, so next operations start from wrong position.]
        }
        else if(a[i]=='/'){
            i++;
            num/=trans_to_num(a,i); // @@ [Same issue: 'i' not advanced past the number just parsed.]
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
    num=trans_to_num(a,i); // @@ ['i' not updated after number parsing, leading to incorrect tokenization.]
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
            num*=trans_to_num(a,i); // @@ ['i' not advanced after parsing number, causing repeated parsing of same digits or skipping operators.]
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
            num=trans_to_num(a,i); // @@ ['i' still not reflecting the end of the parsed number, breaking the entire parsing logic.]
            record=a[i];
        }
    }        
    printf("%d",sum);

    return 0;
}