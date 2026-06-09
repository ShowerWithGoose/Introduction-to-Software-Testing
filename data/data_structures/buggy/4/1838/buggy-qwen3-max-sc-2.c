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
    return strcmp((char*)a,(char*)b); // @@ [The comparison function should cast to 'struct word*' and compare the 'ch' fields, not treat the structs as char arrays. This causes undefined behavior and incorrect sorting.]
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
                fscanf(in,"%c",&word_tem[i]); // @@ [This may read beyond the buffer 'word_tem' if a word is longer than max_word_len-1, causing buffer overflow. Also, after reading a non-letter, it's stored in word_tem[i], but then word_tem[i+1] is set to '\0', which skips that character without reprocessing it.]
            }
            word_tem[i+1]='\0'; // @@ [Should be word_tem[i]='\0'; because the loop exits when word_tem[i] is not a letter, so valid letters are from 0 to i-1. Setting i+1 overwrites one extra byte and leaves word_tem[i] uninitialized (non-null), leading to garbage in the string.]
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
    qsort(library[0].ch,k,sizeof(library[0]),cmp); // @@ [First argument to qsort should be 'library', not 'library[0].ch'. This passes a char* instead of struct word*, causing qsort to sort bytes rather than structs, leading to crash or undefined behavior.]
    for(i=0;i<k;i++){
        printf("%s %d\n",library[i].ch,library[i].num);
    }
    fclose(in);
    return 0;
}