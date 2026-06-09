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
    struct stu s[1000]; // @@ [Error] Array of structs is uninitialized, leading to garbage values in ss fields. Should be zero-initialized or explicitly null-terminated.
    FILE*in;
    in=fopen("article.txt","r");
    int cnt=0;
    char mid[1000]= {};
    while(~fscanf(in,"%s",mid)) { // @@ [Error] Using ~ on fscanf return value is non-standard and unsafe; should check against EOF. Also lacks NULL check for file pointer.
        int len=strlen(mid);
        int pos=0;
        for(int i=0; i<len; i++) {
            mid[i]=tolower(mid[i]);
            if(mid[i]<='z'&&mid[i]>='a')
                s[cnt].ss[pos++]=mid[i];
            else{
                pos=0;cnt++; // @@ [Error] Fails to null-terminate the current word (s[cnt-1].ss[pos]='\0'), causing undefined behavior in strcmp. Also increments cnt on every non-letter.
            }
        }
        cnt++; // @@ [Error] Unconditionally increments cnt, causing off-by-one errors and skipping the last word if it ends with a letter. The last word is also not null-terminated.
    }
    /*for(int i=0;i<cnt;i++){
        puts(s[i].ss);
    }*/
    qsort(s,cnt,sizeof(struct stu),cmp);
    for(int i=0; i<cnt; i++) {
        if(s[i].ss[0]==' ') continue; // @@ [Error] Incorrect condition to skip empty/invalid words. Should check for null terminator (s[i].ss[0] == '\0') or zero length.
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