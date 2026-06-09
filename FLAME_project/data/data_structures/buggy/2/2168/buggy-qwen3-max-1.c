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
    return result; // @@ [This function incorrectly calculates the number by reversing digit weights. For example, "123" becomes 1*100 + 2*10 + 3*1 in normal parsing, but this code computes it as 1*1 + 2*10 + 3*100 due to incorrect power assignment.]
}
int main(){
    gets(a);
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
            num*=trans_to_num(a,i);
        }
        else if(a[i]=='/'){
            i++;
            num/=trans_to_num(a,i);
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
    num=trans_to_num(a,i);
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
            num*=trans_to_num(a,i);
        }
        else if(a[i]=='/'){
            i++;
            num/=trans_to_num(a,i);
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
            num=trans_to_num(a,i); // @@ [After consuming an operator like '+' or '-', the index `i` is incremented, but `trans_to_num` is called with the new `i` which points to the next digit. However, the logic does not correctly advance `i` past the entire number after parsing it, leading to re-parsing or skipping digits.]
            record=a[i]; // @@ [This reads the next operator without ensuring that `i` is at an operator position; if `trans_to_num` didn't advance `i` correctly, `a[i]` may be part of a number, causing `record` to store a digit instead of an operator.]
        }
    }        
    printf("%d",sum);

    return 0;
}