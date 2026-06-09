#include<stdio.h>
#include<ctype.h>
#include<string.h>

struct stu{
    char ss[1000];
    int num;
};
int cmp(const void*a,const void *b){
    struct stu*p1=(struct stu*)a;
    struct stu*p2=(struct stu*)b;
    return (strcmp(p1->ss,p2->ss));
}
int main()
{
    struct stu s[1000];
    FILE*in;
    in=fopen("article.txt","r");
    int cnt=0;
    char mid[1000]= {};
    while(~fscanf(in,"%s",mid)) {
        int len=strlen(mid);
        int pos=0;
        for(int i=0; i<len; i++) {
            mid[i]=tolower(mid[i]);
            if(mid[i]<='z'&&mid[i]>='a')
                s[cnt].ss[pos++]=mid[i];
            else{
                if(pos > 0) { // @@ The original code increments cnt and resets pos when a non-letter is encountered, but fails to null-terminate the current word string before moving to the next slot. Also, it unconditionally increments cnt at the end of the loop, leading to empty or invalid entries.
                    s[cnt].ss[pos] = '\0'; // @@ Need to null-terminate the string before considering the word complete.
                    cnt++; // @@ Only increment word count if a valid word was formed.
                    pos = 0; // @@ Reset position for the next potential word.
                }
            }
        }
        if(pos > 0) { // @@ Handle the case where the last token in the file ends with a letter (no trailing punctuation/space to trigger the else block).
            s[cnt].ss[pos] = '\0'; // @@ Null-terminate the final word.
            cnt++; // @@ Increment count for the final word.
        }
    }
    /*for(int i=0;i<cnt;i++){
        puts(s[i].ss);
    }*/
    qsort(s,cnt,sizeof(struct stu),cmp);
    for(int i=0; i<cnt; i++) {
        if(s[i].ss[0]=='\0') continue; // @@ Check for empty strings instead of space, as uninitialized or cleared entries might be empty.
        int t=0;
        for(int j=i;j<cnt;j++){
            if(strcmp(s[i].ss,s[j].ss)!=0) break;
            else t++;
        }
        printf("%s %d\n",s[i].ss,t);
        i=i+t-1;
    }
    return 0;
}