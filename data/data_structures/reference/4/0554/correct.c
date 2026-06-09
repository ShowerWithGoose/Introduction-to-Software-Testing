#include<stdio.h>

#include<string.h>

char word[5000][200];

int time[5000];

int divide(char ch[],int i);

int divide(char ch[],int i){

    int n=strlen(ch);

    int j,k;

    for(j=0;j<=n-1;j++){

        if(ch[j]<'A'||(ch[j]>'Z'&&ch[j]<'a')||ch[j]>'z') continue;

        for(k=0;(ch[j]>='a'&&ch[j]<='z')||(ch[j]>='A'&&ch[j]<='Z');j++,k++){

            if(ch[j]>='a'&&ch[j]<='z') word[i][k]=ch[j];

            else if(ch[j]>='A'&&ch[j]<='Z') word[i][k]=ch[j]+32;
        }

        i++;
    }

    return i;
}

int main(){

    int i,j,k;

    char *ptr1[5000],*ptr2[5000];

    FILE *in,*out;

    char ch[5000];

    in=fopen("article.txt","r");

    for(i=1;fgets(ch,4999,in)!=NULL;){

        i=divide(ch,i);
    }

    fclose(in);

    for(j=1;j<=i;j++){

        time[j]=0;

        ptr1[j]=word[j];

        for(k=1;k<=i;k++){

            if(strcmp(word[j],word[k])==0) time[j]++;
        }

        ptr2[j]=time[j];
    }

    for(j=1;j<=i;j++){

        //printf("%s %d\n",ptr1[j],ptr2[j]);
    }

    for(j=1;j<=i;j++){

        for(k=1;k<=i-j;k++){

            if(strcmp(ptr1[k],ptr1[k+1])>0){

                char *ptrhold1,*ptrhold2;

                ptrhold1=ptr1[k],ptrhold2=ptr2[k];

                ptr1[k]=ptr1[k+1],ptr2[k]=ptr2[k+1];

                ptr1[k+1]=ptrhold1,ptr2[k+1]=ptrhold2;
            }
        }
    }

    for(j=2;j<=i;j++){

        int flag=0;

        if(j>1&&strcmp(ptr1[j-1],ptr1[j])==0) continue;

        printf("%s %d\n",ptr1[j],ptr2[j]);
    }

    return 0;
}



