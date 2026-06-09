#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>


FILE *in;

char m[500];

void bubble(char *s1,int n,int N){
         for(int i=0;i<n;i++){
            for(int j=0;j<n-i-1;j++){
                 if(strcmp(s1+j*N,s1+(j+1)*N)>0){
                    strcpy(m,s1+j*N);
                     strcpy(s1+j*N,s1+(j+1)*N);
                    strcpy(s1+(j+1)*N,m);
                }
            }
         }
    }





char a[500][2000],b[2000][500],c[2000][500],d[2000][500];
int b1[2000];
int main(){
    in=fopen("article.txt","r");
    int i1=0;
    while(fgets(a[i1],1000086,in)){
        i1++;
    }
    for(int i=0;i<i1;i++){
        for(int j=0,size=strlen(a[i]);j<size;j++){
            if(a[i][j]>='A'&&a[i][j]<='Z'){
                a[i][j]=(char)(a[i][j]+'a'-'A');
            }
        }
    }

    int s=00;    
    for(int i=0;i<i1;i++){//per a[i](line)
        int p=0;
        for(int j=0,size=strlen(a[i]);j<size;j++){
            if((a[i][j]<'a'||a[i][j]>'z')){
                for(int o=0;o<j-p;o++){
                    c[s][o]=a[i][p+o];
                }
                if(j>p)s++; // @@ [This condition skips empty words correctly, but the loop does not handle the last word in a line if the line doesn't end with a non-letter character.]
                p=j+1;
            }
        }
    }
    // Missing handling of trailing word at end of line (if line ends with letters, it's never added to c[])

//    int s=00;
//    for(int i=00;i<l;i++){
//        if(b[i][00]!='\00'){
//            strcpy(c[s],b[i]);
//            s++;
//        }
//    }
    bubble(c,s,500);
    int q=0;
    for(int i=0;i<s;i++){
        if(q==0){
            strcpy(d[q],c[i]);
            b1[0]=1; // @@ [b1[0] is set to 1, but if c[0] is an empty string (e.g., from leading/trailing delimiters), it will incorrectly count it. Also, logic for counting duplicates is flawed.]
            q++;
        }
        else if(strcmp(d[q-1],c[i])==0){
            strcpy(d[q],c[i]); // @@ [This copies the same word again into a new slot instead of just incrementing the count of the existing word. This breaks frequency counting.]
            b1[q]++; // @@ [b1[q] is used before being initialized; should be incrementing b1[q-1] instead.]
            q++;
        }
        else{
            b1[q-1]++; // @@ [This increments the previous word's count even when a new distinct word is encountered, which is incorrect. Should initialize b1[q] = 1 for new word.]
        }
    }
    for(int i=0;i<q;i++){
        if(d[i][0]=='\0'){
            continue;
        }
        printf("%s %d\n",d[i],b1[i]);

    }

    return 00;
}