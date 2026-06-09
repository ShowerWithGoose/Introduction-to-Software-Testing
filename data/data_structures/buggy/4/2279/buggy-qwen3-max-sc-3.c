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
    in=fopen("article.txt","r"); @@ [If the file "article.txt" does not exist or cannot be opened, 'in' will be NULL, and subsequent fgets will cause undefined behavior. However, the primary compilation issue is not here.]
    int i1=0;
    while(fgets(a[i1],1000086,in)){ @@ [The buffer size for fgets exceeds the declared array size a[i1] which is only 2000 chars; this causes a buffer overflow at runtime, but not a compilation error. The actual compilation error is likely due to missing headers or environment, but based on provided info, no syntax error exists. However, note: the real issue from test output "/bin/sh: 1: gcc: not found" indicates a system/environment problem, not code error. But per instructions, we must find logical/semantic errors that would cause incorrect behavior matching the described problem.]
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
                if(j>p)s++; @@ [This increments s after copying a word, but the copied word may be empty if j==p (e.g., consecutive non-letter chars). Also, the null terminator is not added to c[s], leading to undefined behavior in strcmp later.]
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
    bubble(c,s,500); @@ [The bubble function expects strings of max length N=500, but c is declared as c[2000][500], so each string is 500 chars. However, words were copied without null terminators, so strcmp in bubble will read beyond intended word boundaries, causing undefined behavior.]
    int q=0;
    for(int i=0;i<s;i++){
        if(q==0){
            strcpy(d[q],c[i]);
            b1[0]=1; @@ [b1[0] is set to 1, but if s==0, this writes to b1[0] unnecessarily. More critically, b1 array is not initialized, so if q>0 and we hit the 'else' branch, b1[q-1]++ operates on uninitialized value.]
            q++;
        }
        else if(strcmp(d[q-1],c[i])==0){
            strcpy(d[q],c[i]);
            b1[q]++; @@ [b1[q] is used before being initialized. It should be set to 1 first, not incremented. Also, d[q] is overwritten but previous d[q] might be garbage. Logic for counting is flawed.]
            q++;
        }
        else{
            b1[q-1]++; @@ [This increments count for previous word when a new word is found, but it should have been counted already during its run. This leads to overcounting. Also, b1[q-1] may be uninitialized.]
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