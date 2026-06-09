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
    return strcmp((char*)a,(char*)b); // @@ [The comparison function incorrectly casts the entire struct elements as char*, but it should cast to struct word* and compare the 'ch' fields. This leads to undefined behavior during sorting.]
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
                fscanf(in,"%c",&word_tem[i]);
            }
            word_tem[i+1]='\0'; // @@ [Off-by-one error: after reading a non-letter character at position i, the loop exits, and the null terminator should be placed at word_tem[i], not i+1. This causes an uninitialized byte to be included in the string and may lead to buffer overflow if i reaches max_word_len-1.]
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
    qsort(library[0].ch,k,sizeof(library[0]),cmp); // @@ [Incorrect arguments to qsort: first argument should be 'library', not 'library[0].ch'; third argument should be 'sizeof(struct word)', not 'sizeof(library[0])' (though that part is actually correct). The main issue is passing a char* instead of the array base address, causing undefined behavior.]
    for(i=0;i<k;i++){
        printf("%s %d\n",library[i].ch,library[i].num);
    }
    fclose(in);
    return 0;
}