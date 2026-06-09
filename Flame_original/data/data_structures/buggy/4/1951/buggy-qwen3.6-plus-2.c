#include <stdio.h>
#include <string.h>
char s[100];
char c[100];
char a[100][10];
int  d[100];
int main(){
    FILE *in;
    in=fopen("article.txt","r");
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
            if(strcmp(a[x],c)==0)    // @@ c is not explicitly null-terminated before use, causing undefined behavior in strcmp
                {

                d[x]++;
                v=1;
                break;    
                }
                }
            if(v==0){
                strcpy(a[j],c);      // @@ c is not null-terminated, strcpy may copy garbage characters or cause buffer overflow
                
                d[j]=1;
                j++;
            }
            for(int w=0;w<10;w++)    // @@ Only clears the first 10 characters of c, but c has size 100; should clear up to r or set c[r]='\0'
            c[w]='\0';
            r=0;
        }    }
    }            // @@ Missing logic to process the last word if the file ends with a letter (u==1)
    int z=j;
        for(int h=0;h<j;h++)
    {if(a[h][0]>'z'||a[h][0]<'a')    // @@ Incorrect filtering condition; '\0' < 'a' marks empty slots, but logic is fragile and z decrement may be inaccurate
    {a[h][0]='~';
    z--;
    }
    }


    for(int h=0;h<z;h++)
    {int o=0;
        for(int g=0;g<j;g++){
            if(a[g][0]=='~')
            continue;
            if(strcmp(a[o],a[g])>0)  // @@ o is initialized to 0; if a[0] is marked '~', strcmp compares "~" with others, which is unreliable for finding the lexicographically smallest word
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