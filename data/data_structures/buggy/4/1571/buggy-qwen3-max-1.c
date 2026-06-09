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
    return strcmp(a->word+1,b->word +1); // @@ [The comparison skips the first character of each word by using `word+1`, but words are stored starting at index 1, so this causes incorrect lexicographical ordering and potential undefined behavior if word is empty.]
}
int main(){
    FILE *in;
    in=fopen("article.txt","r");
    while(c=fgetc(in)!=EOF){ // @@ [Operator precedence error: `!=` has higher precedence than `=`, so this assigns the result of `(fgetc(in) != EOF)` (0 or 1) to `c`, not the character. Should be `while((c = fgetc(in)) != EOF)`]
        s[++len]=c;
    }
    s[len+1]='\0';
    for(i=1;i<=len;i++){
        if(!isalpha(s[i])) continue;
        
        cnt++;
        do{
            c=(islower(s[i])?s[i]:(s[i]-'A'+'a')); // @@ [Incorrect case conversion: uses 'A' and 'a' without guaranteeing s[i] is uppercase; should use tolower(s[i]). Also, 'c' is a char but used as int in assignment—minor but safe. Main issue: logic assumes s[i] is letter, which is OK due to loop condition.]
            a[cnt].word[++a[cnt].sum]=c;
            a[cnt].word[a[cnt].sum+1]='\0';
        }while(isalpha(s[++i])); // @@ [After incrementing i in condition, loop may skip non-alpha characters correctly, but if i exceeds len, s[i] is out-of-bounds (undefined behavior). Also, after last word, i may go beyond len and access uninitialized memory.]
    }
    
    qsort(a+1,cnt,sizeof(a[0]),cmp);
    
    int ans=0;
    for(i=1;i<=cnt;i++){
        if(i==1||strcmp(a[i].word +1,a[i-1].word +1)!=0){ // @@ [Again uses `word+1`; same issue as in cmp function. Also, `ans` is not initialized properly for the first unique word.]
            if(i!=1)
                printf("%s %d\n",a[i-1].word +1,ans);
            ans=1;
        }else if(strcmp(a[i].word+1,a[i-1].word +1)==0) ans++;
    }
    printf("%s %d\n",a[cnt].word +1,ans); // @@ [If cnt is 0 (no words), this accesses a[0].word+1 which is invalid. Also, always prints even if no words exist.]

    return 0;
}