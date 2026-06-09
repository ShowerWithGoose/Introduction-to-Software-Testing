#include<stdio.h>
#include<string.h>
char s[10010]={'\0'},b[100010]={'\0'};
int main(){
    int i,j=0;
    gets(s);
    for(i=0;i<strlen(s);i++,j++){
        b[j]=s[i];
        if(s[i]=='-'&&s[i+1]>s[i-1]){
            if((s[i-1]-'0'<=9&&s[i-1]-'0'>=0&&s[i+1]-'0'>=0&&s[i+1]-'\0'<=9)||(s[i-1]-'A'<=25&&s[i-1]-'A'>=0&&s[i+1]-'A'>=0&&s[i+1]-'A'<=25)||(s[i-1]-'a'<=25&&s[i-1]-'a'>=0&&s[i+1]-'a'>=0&&s[i+1]-'a'<=25)){
                for(int k=1;k<s[i+1]-s[i-1];k++){
                    b[j]=s[i-1]+k; // @@ [This overwrites the current position in b (which holds '-'), but should append after it. Also, j is incremented inside loop but initial b[j] was already set to '-', causing misplacement.]
                    j++;
                }
                b[j]=s[i+1]; // @@ [This writes the end character, but skips handling of the '-' and next char correctly; also, i++ at end skips next char, but logic doesn't account for already copying s[i+1].]
                i++;
            }    
            
        }
    }
    puts(b);
    return 0;
}