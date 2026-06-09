#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int comp(const void* x1, const void* x2) {
    return strcmp((char*)x1, (char*)x2);
}
char wordlist[666][88] = { 0 };
int time[666] = { 0 };
char strin[10001] = { 0 };
char strins[1001];
int main() {
    FILE* fin;
    fin = fopen("filein.txt", "r"); // @@ Error: file name must be "article.txt" as per problem specification.

    while ((fgets(strins, 10000, fin)) != NULL) { // @@ Error: buffer size argument 10000 exceeds declared size 1001, causing buffer overflow.
        strcat(strin, strins);
    }
        for (int i = 0; i < strlen(strin); i++) {
            if (strin[i] >= 'A' && strin[i] <= 'Z') {
                strin[i] = strin[i] - 'A' + 'a';
            }
        }

        int num = 0;
        for (int i = 0; i < strlen(strin); i++) {
            char word[88] = { 0 }; int len = 0;
            if (strin[i] >= 'a' && strin[i] <= 'z') {

                word[len++] = strin[i];
                for (int j = i + 1; j < strlen(strin); j++) {

                    if (strin[j] >= 'a' && strin[j] <= 'z') {
                        word[len++] = strin[j];
                    }
                    else {
                        i += len - 1;
                        break;
                    }
                }
            }int sign = 0;
            for (int j = 0; j < num; j++) {
                if (strcmp(wordlist[j], word) == 0) {
                    time[j]++;
                    sign = 1;
                    break;
                }
            }
            if (sign == 0) {
                time[num]++;
                strcpy(wordlist[num++], word);

            }


        }
        char timec[666][4] = { 0 };

        for (int i = 0; i < num; i++) {
            int slen = strlen(wordlist[i]);
            wordlist[i][slen] = ' '; // @@ Error: Modifies the word strings by appending a space and count, causing sorting to include the count in the key.
            wordlist[i][slen + 1] = '\0'; // @@ Error: Related to the above; the word list should not be altered for sorting.
            sprintf(timec[i], "%d", time[i]);
            strcat(wordlist[i], timec[i]); // @@ Error: Appending count to the word string, so the subsequent sort uses the combined string, not the word alone.
        }

        qsort(wordlist, num, 88 * sizeof(char), comp); // @@ Error: Sorting by the combined string (word + space + count) does not give the correct lexicographic order by word only.
        for (int i = 1; i < num; i++) { // @@ Error: Loop starts at i=1, skipping the first word (index 0). Should start at i=0.
            printf("%s\n", (wordlist[i]));
        }
        

    fclose(fin);
    
    return 0;
}