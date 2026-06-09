#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define MAX_LEN 100
#define MAX_ROWS 100
char ch;
char line[MAX_LEN];
    int row = 0;
char wenben[1000][1000],ci[1000][1000];
int pin[1000];
    char temp[1000];
    
int main(){
FILE *fp;
fp=fopen("article.txt","r");
row = 0;
int z=0;
     while ((fgets(line, MAX_LEN, fp))!= NULL){
        line[strcspn(line, "\n")] = '\0'; 
        strcpy(wenben[row], line);
        row++;z++;
    }
    
    int n=0,nl=0,shu=0,zi=0; int fu=0; 
    
for(int i=0;i<z;i++){
    int l=strlen(wenben[i]);
    for(int j=0;j<l-1;j++){ // @@ [Loop condition should be `j < l`, not `j < l-1`; this skips the last character of each line, causing words at line ends to be truncated or merged incorrectly.]
        switch(wenben[i][j]){
         case 'A': wenben[i][j]='a';break;
         case 'B': wenben[i][j]='b';break;
         case 'C': wenben[i][j]='c';break;
         case 'D': wenben[i][j]='d';break;
         case 'E': wenben[i][j]='e';break;
         case 'F': wenben[i][j]='f';break;
         case 'G': wenben[i][j]='g';break;
         case 'H': wenben[i][j]='h';break;
         case 'I': wenben[i][j]='i';break;
         case 'J': wenben[i][j]='j';break;
         case 'K': wenben[i][j]='k';break;
         case 'L': wenben[i][j]='l';break;
         case 'M': wenben[i][j]='m';break;
         case 'N': wenben[i][j]='n';break;
         case 'O': wenben[i][j]='o';break;
         case 'P': wenben[i][j]='p';break;
         case 'Q': wenben[i][j]='q';break;
         case 'R': wenben[i][j]='r';break;
         case 'S': wenben[i][j]='s';break;
         case 'T': wenben[i][j]='t';break;
         case 'U': wenben[i][j]='u';break;
         case 'V': wenben[i][j]='v';break;
         case 'W': wenben[i][j]='w';break;
         case 'X': wenben[i][j]='x';break;
         case 'Y': wenben[i][j]='y';break;
         case 'Z': wenben[i][j]='z';break;
     }
    
         switch(wenben[i][j]){
         case 'a': ci[n][nl]='a';fu=0,zi++,nl++;break;
         case 'b': ci[n][nl]='b';fu=0,zi++,nl++;break;
         case 'c': ci[n][nl]='c';fu=0,zi++,nl++;break;
         case 'd': ci[n][nl]='d';fu=0,zi++,nl++;break;
         case 'e': ci[n][nl]='e';fu=0,zi++,nl++;break;
         case 'f': ci[n][nl]='f';fu=0,zi++,nl++;break;
         case 'g': ci[n][nl]='g';fu=0,zi++,nl++;break;
         case 'h': ci[n][nl]='h';fu=0,zi++,nl++;break;
         case 'i': ci[n][nl]='i';fu=0,zi++,nl++;break;
         case 'j': ci[n][nl]='j';fu=0,zi++,nl++;break;
         case 'k': ci[n][nl]='k';fu=0,zi++,nl++;break;
         case 'l': ci[n][nl]='l';fu=0,zi++,nl++;break;
         case 'm': ci[n][nl]='m';fu=0,zi++,nl++;break;
         case 'n': ci[n][nl]='n';fu=0,zi++,nl++;break;
         case 'o': ci[n][nl]='o';fu=0,zi++,nl++;break;
         case 'p': ci[n][nl]='p';fu=0,zi++,nl++;break;
         case 'q': ci[n][nl]='q';fu=0,zi++,nl++;break;
         case 'r': ci[n][nl]='r';fu=0,zi++,nl++;break;
         case 's': ci[n][nl]='s';fu=0,zi++,nl++;break;
         case 't': ci[n][nl]='t';fu=0,zi++,nl++;break;
         case 'u': ci[n][nl]='u';fu=0,zi++,nl++;break;
         case 'v': ci[n][nl]='v';fu=0,zi++,nl++;break;
         case 'w': ci[n][nl]='w';fu=0,zi++,nl++;break;
         case 'x': ci[n][nl]='x';fu=0,zi++,nl++;break;
         case 'y': ci[n][nl]='y';fu=0,zi++,nl++;break;
         case 'z': ci[n][nl]='z';fu=0,zi++,nl++;break;
         default: fu++,nl=0; if(fu==1&&zi!=0){n++;}break; // @@ [This logic fails to properly terminate a word when encountering non-letter characters; it only increments `n` once per non-letter sequence and doesn't handle consecutive delimiters correctly, leading to merged words like "lifeeat".]
     }
     
     
     
    }
    zi=0,fu=0;
}

for(int j=0;j<n-1;j++){

        for(int i=0;i<n-1;i++)
        {


            if(strcmp(ci[i],ci[i+1]) > 0)//比较 
            {
                strcpy(temp, ci[i]);//小的在前 
                strcpy(ci[i], ci[i+1]);
                strcpy(ci[i+1], temp);
            }
        }
    }        


int m=0;

int que=0;
    for(int i=0;i<n;i++){
        pin[i]=1;
        
        
        for(int h=0;h<n;h++){
            if(h!=i){
            
            
                
                
                if(strcmp(ci[i],ci[h])==0){
                    pin[i]++;
                    for(int r=h;r<n;r++){
                    strcpy(ci[r],ci[r+1]); // @@ [Shifting array elements during iteration causes words to be skipped or misaligned; also modifies the array while counting, leading to incorrect frequency counts (e.g., "do" appears 3 times but counted as 2).]
                        }
                        n--,m++;
                    h=h-m; // @@ [Incorrect index adjustment after removing duplicates; `h = h - m` does not correctly reset the loop index, causing missed comparisons and wrong counts.]
                }
                
                
            
        }
    }
}
    
    
for(int i=0;i<n-1;i++){
    printf("%s %d\n",ci[i],pin[i]);
}
printf("%s %d",ci[n-1],pin[n-1]); // @@ [Missing newline at the end of the last output line violates the requirement that each line ends with a newline.]


fclose(fp);
    return 0;
}