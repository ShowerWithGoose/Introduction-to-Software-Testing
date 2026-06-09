#include<stdio.h>
#include<string.h>
#include<ctype.h>
char str[200][20];
int count[200];
int main()
{
    FILE *bfp;
    bfp=fopen("article.txt","r");

    char ch=fgetc(bfp);
    int i=0,j=0;
    while(ch!=EOF){
        if(isalpha(ch)){
            str[i][j]=ch;
            j++;
        }
        else if(isspace(ch)||ispunct(ch)){
            str[i][j]='\0';
            i++;
            j=0;
        }
        ch=fgetc(bfp);
    }
    int n=i;
    for(i=0;i<n;i++){
        for(j=0;j<strlen(str[i]);j++){
            str[i][j]=tolower(str[i][j]);
        }
    }

    int flag;
    for(i=0;i<n-1;i++){
        flag=0;
        for(j=0;j<n-1-i;j++){
            if(strcmp(str[j],str[j+1])>0){
                char q[20];
                strcpy(q,str[j]);
                strcpy(str[j],str[j+1]);
                strcpy(str[j+1],q);
                flag=1;
            }
        }if(flag==0)break;
    }

    for(i=0;i<n;i++){
        count[i]=1;
        for(j=i+1;j<n;j++){
            if(strcmp(str[i],str[j])==0){
                count[i]++;
                str[j][0]='\0';
            }
            else{
                i=j-1;
                break;
            }
        }
    }

    for(i=0;i<n;i++){
        if(str[i][0]!='\0')
            printf("%s %d\n",str[i],count[i]);
    }
    fclose(bfp);
}


