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
                if(j>p)s++; // @@ The logic for extracting words is flawed. It only processes a word when a non-letter character is encountered. If a line ends with a letter (which is common), the last word of that line is never extracted because the loop terminates without hitting the 'else' condition to trigger the copy. Additionally, it does not null-terminate the strings in c[s], leading to garbage data during comparison and output.
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
    bubble(c,s,500);
    int q=0;
    for(int i=0;i<s;i++){
        if(q==0){
            strcpy(d[q],c[i]);
            b1[0]=1;
            q++;
        }
        else if(strcmp(d[q-1],c[i])==0){
            strcpy(d[q],c[i]);
            b1[q]++; // @@ Logic error: When a duplicate word is found, it copies the word to the next slot d[q] and increments b1[q]. However, b1[q] was not initialized to 1, so it contains garbage or 0, then incremented. More importantly, this approach creates a new entry for every duplicate instead of just incrementing the count of the existing unique word. The standard approach is to just increment b1[q-1] and NOT create a new entry in d.
            q++;
        }
        else{
            b1[q-1]++; // @@ Logic error: This branch handles the case where the current word c[i] is different from the previous unique word d[q-1]. However, it increments the count of the *previous* word again? No, wait. The structure is: if same, add new entry (wrong). If different, increment previous? This logic is completely broken for counting frequencies. It should be: if same, increment count of current unique word. If different, start a new unique word entry with count 1.
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