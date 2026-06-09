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
    return strcmp((char*)a,(char*)b); // @@ [The comparison function incorrectly casts the entire struct elements as char*, but it should cast them to struct word* and then access the 'ch' field. This will cause undefined behavior during sorting.]
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
                fscanf(in,"%c",&word_tem[i]); // @@ [This reads one character beyond the last letter of the word, but the loop condition checks word_tem[i] before it's assigned, leading to reading uninitialized memory on the first iteration of the inner loop. Also, after reading a non-letter, it's not pushed back, so the next word may miss the first character after a delimiter.]
            }
            word_tem[i+1]='\0'; // @@ [Should be word_tem[i] = '\0'; because the loop exits when word_tem[i] is not a letter, so the valid letters are from 0 to i-1, and null terminator should be at index i.]
            for(j=0;j<=i;j++){ // @@ [This loop runs from 0 to i inclusive, but only indices 0 to i-1 contain letters; index i contains a non-letter (which caused loop exit), and i+1 was set to '\0'. So this may convert a non-letter to lowercase or access out-of-bound if i == max_word_len - 1.]
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
    qsort(library[0].ch,k,sizeof(library[0]),cmp); // @@ [Incorrect use of qsort: first argument should be 'library', not 'library[0].ch'. This passes a char* instead of the array of structs, causing undefined behavior.]
    for(i=0;i<k;i++){
        printf("%s %d\n",library[i].ch,library[i].num);
    }
    fclose(in);
    return 0;
}