#include <stdio.h>
#include <string.h>
char s[100];
char c[100];
char a[100][10]; // @@ [The second dimension (10) is too small to hold words like "programming" (11 characters including null terminator), causing buffer overflow and corruption.]
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
            if(strcmp(a[x],c)==0)    
                {

                d[x]++;
                v=1;
                break;    
                }
                }
            if(v==0){
                strcpy(a[j],c); // @@ [Copying into a[j] which has only 10 chars; if c holds a word longer than 9 letters (e.g., "programming"), this overflows and corrupts memory.]
                
                d[j]=1;
                j++;
            }
            for(int w=0;w<10;w++) // @@ [Only clears first 10 chars of c, but c is size 100. However, the real issue is that c may contain long words that overflow a[][10].]
            c[w]='\0';
            r=0;
        }    }
    }
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
        printf(" %d\n",d[o]); // @@ [Missing space between word and count in format: should be "word count", but code prints word then space then count correctly—however, due to earlier corruption (e.g., "programmin~anguage"), output is wrong. Root cause is array size.]
        a[o][0]='~';
    }
    return 0;
    }