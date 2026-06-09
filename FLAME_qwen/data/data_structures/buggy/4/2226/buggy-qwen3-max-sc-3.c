# include <stdio.h>
int main(int argc, const char * argv[]) 
{
    FILE *b; // @@
    char filename[32]={"article.txt"};
    char c; // @@
    if((b = fopen(filename, "r")) == NULL)
        { 
            fprintf(stderr, "%s  can¡¯t open!\n",filename); // @@
            return -1;
        }
    while((c=fgetc(b) ) != EOF) // @@
        printf("%c",c);
    printf("Hello, World!\n");
    return 0;
}