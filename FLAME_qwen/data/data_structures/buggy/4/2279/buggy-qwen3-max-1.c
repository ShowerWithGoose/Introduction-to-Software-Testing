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
    in=fopen("article.txt","r"); // @@ [If the file "article.txt" does not exist or cannot be opened, `in` will be NULL, and subsequent operations like `fgets` will cause undefined behavior. The program should check if `in` is NULL after fopen.]
    int i1=0;
    while(fgets(a[i1],1000086,in)){ // @@ [The buffer size for `a[i1]` is only 2000, but `fgets` is told to read up to 1000086 characters, which causes buffer overflow and undefined behavior.]
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
                if(j>p)s++; // @@ [This condition may miss the last word in a line if the line doesn't end with a non-letter character (e.g., ends with newline or EOF). Also, it doesn't null-terminate the extracted word in `c[s]`.]
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
    bubble(c,s,500); // @@ [`bubble` expects each string to be of fixed width `N=500`, but `c` is declared as `c[2000][500]`, so passing `c` as `char*` and using stride 500 is correct in layout, but the words in `c` were never null-terminated, leading to undefined behavior in `strcmp` and `strcpy`.]
    int q=0;
    for(int i=0;i<s;i++){
        if(q==0){
            strcpy(d[q],c[i]);
            b1[0]=1; // @@ [This sets b1[0] = 1, but if there are duplicate words later, the logic below does not correctly count frequencies. Also, `b1` is uninitialized for indices >0.]
            q++;
        }
        else if(strcmp(d[q-1],c[i])==0){
            strcpy(d[q],c[i]);
            b1[q]++; // @@ [`b1[q]` is used before being initialized. This leads to undefined behavior. Also, the counting logic is flawed: it increments `b1[q]` but doesn't consolidate counts for the same word.]
            q++;
        }
        else{
            b1[q-1]++; // @@ [This increments the previous count when a new word is found, which is incorrect. It should finalize the previous group, not increment again.]
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