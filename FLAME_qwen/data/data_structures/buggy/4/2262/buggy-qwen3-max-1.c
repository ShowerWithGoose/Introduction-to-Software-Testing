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
                pos=0;cnt++; // @@ [When a non-letter character is encountered, the current word is terminated and cnt is incremented, but the partially built word is discarded (pos reset to 0) without saving it. Also, after the loop, cnt is incremented again unconditionally, leading to double increment and uninitialized entries.]
            }
        }
        cnt++; // @@ [This unconditional increment adds an extra empty or incomplete entry for every input token, even if the last character was a letter. This causes empty strings or garbage to be included in the word list.]
    }
    /*for(int i=0;i<cnt;i++){
        puts(s[i].ss);
    }*/
    qsort(s,cnt,sizeof(struct stu),cmp);
    for(int i=0; i<cnt; i++) {
        if(s[i].ss[0]==' ') continue; // @@ [This check for space is incorrect because words are composed only of letters (after filtering), so they should never start with a space. However, due to logic errors above, some entries may be empty (ss[0] == '\0'), not space. This leads to skipping valid empty strings incorrectly or not handling them properly. Also, empty strings should be excluded earlier.]
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