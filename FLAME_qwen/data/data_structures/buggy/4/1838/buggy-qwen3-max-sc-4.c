#include<stdio.h>
#include<string.h>
#define max_word_len 20
#define max_word_num 100
struct word{
    char ch[max_word_len];
    int num;
};
int cmp(const void*a, const void*b)
{
    return strcmp((char*)a,(char*)b); // @@ [The comparison function should cast to struct word*, not char*. This causes incorrect sorting and potential undefined behavior.]
}
int main(){
    FILE*in=fopen("article.txt","r");
    int i,j,k;
    int flag;
    char word_tem[max_word_len];
    struct word library[max_word_num];
    k=0;
    while(fscanf(in,"%c",&word_tem[0])!=EOF){
        if((word_tem[0]>='A'&&word_tem[0]<='Z')||(word_tem[0]>='a'&&word_tem[0]<='z')){
            flag=0;
            if(word_tem[0]>='A'&&word_tem[0]<='Z'){
                word_tem[0]=word_tem[0]+'a'-'A';
            }
            i=0;
            for(;(word_tem[i]>='A'&&word_tem[i]<='Z')||(word_tem[i]>='a'&&word_tem[i]<='z');){
                i++;
                fscanf(in,"%c",&word_tem[i]); // @@ [This may read beyond the bounds of word_tem if a word is longer than max_word_len-1, causing buffer overflow.]
            }
            word_tem[i+1]='\0'; // @@ [Should be word_tem[i]='\0'; because the loop exits when word_tem[i] is non-letter, so the valid characters are from 0 to i-1, and null terminator should be at i.]
            for(j=0;j<=i;j++){
                if(word_tem[j]>='A'&&word_tem[j]<='Z'){
                    word_tem[j]=word_tem[j]+'a'-'A';
                }
            }
            for(j=0;j<k;j++){
                if(strcmp(word_tem,library[j].ch)==0){
                    flag=1;
                    library[j].num++;
                }
            }
            if(flag==0){
                strcpy(library[k].ch,word_tem);
                library[k].num=1;
                k++;
            }
        }
    }
    qsort(library[0].ch,k,sizeof(library[0]),cmp); // @@ [Incorrect first argument to qsort; should be library, not library[0].ch. Also, the size should be sizeof(struct word), but more critically, the base pointer is wrong.]
    for(i=0;i<k;i++){
        printf("%s %d\n",library[i].ch,library[i].num);
    }
    fclose(in);
    return 0;
}