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
    in=fopen("article.txt","r"); // @@ [If the file "article.txt" does not exist or cannot be opened, `in` will be NULL, and subsequent operations like `fgets` will cause undefined behavior or crash. The program should check if `in` is NULL after fopen.]
    int i1=0;
    while(fgets(a[i1],1000086,in)){ // @@ [The buffer size for `a[i1]` is only 2000 (from `char a[500][2000]`), but `fgets` is told to read up to 1000086 characters, which causes buffer overflow and undefined behavior. This should be `fgets(a[i1], 2000, in)` or similar.]
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
                if(j>p)s++; // @@ [After copying the word into `c[s]`, the string is not null-terminated. This leads to undefined behavior when `strcmp` or other string functions are used later on `c[s]`. A `c[s][j-p] = '\0';` is missing.]
                p=j+1;
            }
        }
        // Missing handling of last word in line if line doesn't end with non-letter
    }

//    int s=00;
//    for(int i=00;i<l;i++){
//        if(b[i][00]!='\00'){
//            strcpy(c[s],b[i]);
//            s++;
//        }
//    }
    bubble(c,s,500); // @@ [`bubble` expects strings stored contiguously as in a 1D array of fixed-width records, but `c` is a true 2D array (`char c[2000][500]`). When passed as `c`, it decays to `char (*)[500]`, not `char*`. The function signature and usage are incompatible, leading to incorrect pointer arithmetic and memory access.]
    int q=0;
    for(int i=0;i<s;i++){
        if(q==0){
            strcpy(d[q],c[i]);
            b1[0]=1; // @@ [This sets `b1[0] = 1`, but if there are multiple occurrences of the same word, the logic below does not correctly accumulate counts. Also, `b1` is uninitialized for indices >0, leading to garbage values.]
            q++;
        }
        else if(strcmp(d[q-1],c[i])==0){
            strcpy(d[q],c[i]);
            b1[q]++; // @@ [`b1[q]` was never initialized to 1 before incrementing; it contains garbage. Also, this logic duplicates words in `d` instead of counting in place.]
            q++;
        }
        else{
            b1[q-1]++; // @@ [This increments the count of the previous word even when a new distinct word is found, which is incorrect. The count should only be incremented when duplicates are found, not when transitioning to a new word.]
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