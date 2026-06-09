#include <stdio.h>
#include <string.h>
char s[100];
char c[100];
char a[100][10]; // @@ Array size 10 is too small for typical English words, causing potential buffer overflow when copying longer words.
int  d[100];
int main(){
    FILE *in;
    in=fopen("article.txt","r"); // @@ Missing NULL check for file pointer; will cause a segmentation fault if the file does not exist or cannot be opened.
int j=0;    
while(fgets(s,100,in)!=NULL)
{
    int b=strlen(s);
    int r=0,u=0;
    for(int i=0;i<b;i++){
        if(s[i]>='A'&&s[i]<='Z'){
            s[i]=s[i]-'A'+'a';
        }
    if(s[i]>='a'&&s[i]<='z')    
        {
            c[r]=s[i];
            r++;
            u=1;
        }
    else    if(u==1){
        int v=0;
        for(int x=0;x<j;x++)    
            {
            if(strcmp(a[x],c)==0) // @@ String 'c' is not explicitly null-terminated before comparison, which may read out of bounds and cause undefined behavior.
                {

                d[x]++;
                v=1;
                break;    
                }
                }
            if(v==0){
                strcpy(a[j],c); // @@ 'c' lacks explicit null-termination and destination array 'a[j]' is too small, leading to buffer overflow.
                
                d[j]=1;
                j++;
            }
            for(int w=0;w<10;w++) // @@ Only clears the first 10 characters of 'c'; if a word exceeds 9 characters, 'c' will not be properly null-terminated for the next iteration.
            c[w]='\0';
            r=0;
        }    }
    } // @@ Fails to process the final word if the file ends without a trailing newline or non-letter character, leaving it uncounted.
    int z=j;
        for(int h=0;h<j;h++)
    {if(a[h][0]>'z'||a[h][0]<'a')
    {a[h][0]='~';
    z--;
    }
    }


    for(int h=0;h<z;h++)
    {int o=0;
        for(int g=0;g<j;g++){
            if(a[g][0]=='~')
            continue;
            if(strcmp(a[o],a[g])>0)
            o=g;
        }
        int q=strlen(a[o]);
        for(int k=0;k<q;k++){
            printf("%c",a[o][k]);
        }
        printf(" %d\n",d[o]);
        a[o][0]='~';
    }
    return 0;
    }