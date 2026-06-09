#include<stdio.h>
#include<string.h>
int main() {
    FILE *in=fopen("article.txt","r");
    char c,word[77][17]; // @@ c should be declared as int to correctly store and compare with EOF returned by fgetc, otherwise it may cause infinite loops or comparison failures.
    int i=0,j=0,flag=0,book[77]= {0};
    while((c=fgetc(in))!=EOF) {
        if(c<=90&&c>=65) {
            flag=0;
            word[i][j++]=c+32;
        } else if(c<=122&&c>=97) {
            flag=0;
            word[i][j++]=c;
        } else if(flag==0) {
            word[i++][j]='\0';
            flag=1;
            j=0;
        } else; // @@ Empty else statement is syntactically valid but logically redundant and indicates missing handling for consecutive non-letter characters.
    } // @@ Missing logic to null-terminate and count the last word if the file ends with an alphabetic character.
    for(int t=0; t<i; t++) { // @@ Declaring loop variable inside for is C99-specific and may cause a compilation error in C89/C90 environments; additionally, the code lacks sorting logic required for lexicographical output.
        if(book[t]==0) {
            int num=0;
            for(int p=t; p<i; p++) {
                if(strcmp(word[t],word[p])==0) {
                    num++;
                    book[p]=1;
                }
            }
            printf("%s %d\n",word[t],num); // @@ Outputs words in their original order of appearance instead of the required lexicographical order.
        }
    }
    fclose(in);
    return 0;
}