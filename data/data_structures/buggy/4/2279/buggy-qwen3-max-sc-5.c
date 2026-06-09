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
    while(fgets(a[i1],1000086,in)){ @@ [The buffer size 1000086 exceeds the declared array size of a[i1] which is only 2000, causing potential buffer overflow and undefined behavior.]
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
                if(j>p)s++;
                p=j+1;
            }
        }
    }

//    int s=00;
//    for(int i=00;i<l;i++){
//        if(b[i][00]!='\00'){
//            strcpy(c[s],b[i]);
//            s++;
//        }
//    }
    bubble(c,s,500); @@ [The third argument to bubble should match the actual string length allocated per entry in c, which is 500, but c is declared as c[2000][500], so passing 500 is correct. However, the logic in bubble assumes fixed-width strings, which may not align with how words are stored (not null-padded to full width), leading to incorrect comparisons or overreads.]
    int q=0;
    for(int i=0;i<s;i++){
        if(q==0){
            strcpy(d[q],c[i]);
            b1[0]=1; @@ [b1[0] is set to 1, but if multiple identical words follow, b1[q] is incremented without initializing b1[q] first in the 'else' branch, leading to use of uninitialized values.]
            q++;
        }
        else if(strcmp(d[q-1],c[i])==0){
            strcpy(d[q],c[i]);
            b1[q]++; @@ [b1[q] is used without being initialized to 1 first. This leads to undefined behavior due to reading uninitialized memory.]
            q++;
        }
        else{
            b1[q-1]++; @@ [This increments the count for the previous word, but if the previous word was already finalized, this double-counts or miscounts. Also, new distinct words don't get b1 initialized properly.]
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