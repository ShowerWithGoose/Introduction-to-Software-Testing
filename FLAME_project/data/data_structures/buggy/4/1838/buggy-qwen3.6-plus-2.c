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
    return strcmp(((struct word*)a)->ch,((struct word*)b)->ch); // @@ The comparison function for qsort receives pointers to the elements of the array being sorted. Since the array is of type struct word, the arguments are pointers to struct word. The original code incorrectly cast them to char*, leading to incorrect comparison and sorting behavior.
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
            flag=0; // @@ The variable 'flag' is used to indicate if a word was found in the library. It must be reset to 0 for each new word processed. In the original code, it was set to 0 only inside the if block for uppercase conversion, meaning if the first letter was lowercase, flag remained uninitialized or retained its previous value, causing logic errors in detecting new vs existing words.
            if(word_tem[0]>='A'&&word_tem[0]<='Z'){
                word_tem[0]=word_tem[0]+'a'-'A';
            }
            i=1; // @@ The index 'i' should start at 1 because word_tem[0] has already been read. Starting at 0 would overwrite the first character. Also, the loop condition checks word_tem[i], so we need to read into the next position.
            for(;(fscanf(in,"%c",&word_tem[i])!=EOF)&&((word_tem[i]>='A'&&word_tem[i]<='Z')||(word_tem[i]>='a'&&word_tem[i]<='z'));){ // @@ The original loop did not check for EOF inside the loop, which could lead to infinite loops or reading garbage if the file ends abruptly. Also, the increment of i and reading should happen carefully. The original logic `for(;...;){ i++; fscanf... }` reads into word_tem[i] after incrementing, but the condition checks word_tem[i] before it's read in that iteration. A safer approach is to read then check. However, sticking close to original structure: the original loop `for(;(word_tem[i]>='A'...);){ i++; fscanf... }` checks the *previous* character read. But initially i=0, so it checks word_tem[0] which is correct. Then i becomes 1, reads into word_tem[1]. Then checks word_tem[1]. This logic is actually okay for continuation, BUT the termination condition is flawed. When a non-letter is read, it stays in word_tem[i] but the loop terminates. The problem is `word_tem[i+1]='\0'` later. If the loop terminates because the character read was NOT a letter, that character is stored in word_tem[i]. We should NOT include it in the word. So we need to null-terminate at word_tem[i], not i+1. And we shouldn't increment i after reading the invalid char if we want to exclude it.
                i++;
                if(i >= max_word_len - 1) break; // @@ Prevent buffer overflow
                fscanf(in,"%c",&word_tem[i]);
            }
            // At this point, word_tem[i] contains the character that broke the loop (non-letter or EOF).
            // We should terminate the string BEFORE this character.
            word_tem[i]='\0'; // @@ The original code said word_tem[i+1]='\0'. If the loop breaks because word_tem[i] is not a letter, word_tem[i] contains garbage/non-letter. The word consists of characters from 0 to i-1. So null terminator should be at i. If the loop breaks because of EOF, fscanf might fail, but word_tem[i] might be unchanged or garbage. Correct logic: the valid word chars are indices 0 to i-1.
            
            // Re-evaluating the loop logic from original:
            // Original:
            // i=0;
            // for(;(word_tem[i]>='A'...);){
            //    i++;
            //    fscanf(..., &word_tem[i]);
            // }
            // Trace:
            // 1. Check word_tem[0] (valid letter). Enter loop.
            // 2. i becomes 1. Read word_tem[1].
            // 3. Check word_tem[1]. If valid, enter loop.
            // 4. i becomes 2. Read word_tem[2].
            // ...
            // Suppose word is "abc".
            // Read 'a' into [0]. Check [0] ('a') -> OK.
            // i=1. Read 'b' into [1]. Check [1] ('b') -> OK.
            // i=2. Read 'c' into [2]. Check [2] ('c') -> OK.
            // i=3. Read '.' into [3]. Check [3] ('.') -> Fail. Loop ends.
            // Word is "abc". Indices 0,1,2 are valid. Index 3 is '.'.
            // Original code: word_tem[i+1] = word_tem[4] = '\0'.
            // String becomes "abc.\0". This includes the punctuation in the string if strcmp is used? 
            // No, strcmp stops at \0. But the string content is "abc.".
            // Wait, if word_tem[3] is '.', and word_tem[4] is '\0', then the string is "abc.".
            // This explains why "life." and "you;" appeared in the buggy output. The punctuation was included in the word.
            // So, the error is indeed how the string is terminated and potentially which characters are included.
            // To fix: The valid letters are at indices 0 to i-1. The character at i is the first non-letter.
            // So we should set word_tem[i] = '\0'.
            
            for(j=0;j<=i-1;j++){ // @@ Only convert the valid part of the word to lowercase. The original loop went up to i, which included the non-letter character at index i (if it existed within buffer bounds) or uninitialized memory. Although judge() filters initial input, subsequent chars read in loop might be non-letters if the loop condition wasn't strict enough, but here the loop condition IS strict. However, at termination, word_tem[i] is the non-letter. We shouldn't process it. Also, we already lowered case for word_tem[0] manually. The loop should handle the rest.
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
    qsort(library,k,sizeof(struct word),cmp); // @@ The original code passed `library[0].ch` as the base pointer, which is a char array inside the first struct. This causes qsort to sort the raw bytes of the first few structs incorrectly, treating them as an array of chars or misaligned structs. The base pointer should be the array of structs `library`. The element size should be `sizeof(struct word)`.
    for(i=0;i<k;i++){
        printf("%s %d\n",library[i].ch,library[i].num);
    }
    fclose(in);
    return 0;
}