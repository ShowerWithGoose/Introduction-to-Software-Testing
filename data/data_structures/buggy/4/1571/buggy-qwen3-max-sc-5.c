#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define maxn 100005
#define m 105

int num,i;//单词个数
struct WORD{
    int time,sum;//词频，长度 
    char word[105];
}a[maxn];
char s[maxn],c;//c：从文件中读取的字符 
int cnt,i,len;//存储的单词个数，，字符串的长度 

int cmp(const void *p,const void *q){
    struct WORD *a=(struct WORD *)p;
    struct WORD *b=(struct WORD *)q;
    return strcmp(a->word+1,b->word +1);
}
int main(){
    FILE *in;
    in=fopen("article.txt","r");
    while(c=fgetc(in)!=EOF){ // @@ [Operator precedence error: assignment 'c = fgetc(in)' should be parenthesized as '(c = fgetc(in)) != EOF'; otherwise, it evaluates as 'c = (fgetc(in) != EOF)', which assigns 0 or 1 to c, not the character]
        s[++len]=c;
    }
    s[len+1]='\0';
    for(i=1;i<=len;i++){
        if(!isalpha(s[i])) continue;
        
        cnt++;
        do{
            c=(islower(s[i])?s[i]:(s[i]-'A'+'a')); // @@ [Incorrect case conversion: should use tolower(s[i]) instead of manual conversion; also, 's[i]' might be uppercase but subtraction assumes ASCII and may produce wrong results for non-ASCII systems, though more critically, this line uses 'c' unnecessarily and modifies logic flow]
            a[cnt].word[++a[cnt].sum]=c;
            a[cnt].word[a[cnt].sum+1]='\0';
        }while(isalpha(s[++i])); // @@ [Potential out-of-bounds access: after incrementing i in loop condition, s[i] may exceed array bounds when i==len]
    }
    
    qsort(a+1,cnt,sizeof(a[0]),cmp);
    
    int ans=0;
    for(i=1;i<=cnt;i++){
        if(i==1||strcmp(a[i].word +1,a[i-1].word +1)!=0){ // @@ [Unnecessary offset '+1': words are stored starting at index 1 in word[], but this skips the first character; should compare from word[0]]
            if(i!=1)
                printf("%s %d\n",a[i-1].word +1,ans); // @@ [Same issue: printing from word+1 skips first character of each word]
            ans=1;
        }else if(strcmp(a[i].word+1,a[i-1].word +1)==0) ans++;
    }
    printf("%s %d\n",a[cnt].word +1,ans); // @@ [Same issue: printing from word+1 skips first character]

    return 0;
}