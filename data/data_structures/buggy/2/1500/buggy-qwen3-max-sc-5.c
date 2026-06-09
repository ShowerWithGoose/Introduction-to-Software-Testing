#include<stdio.h>
#include<string.h>
int main(){
    int ch1[20]={-1}; // @@ [Initializing array with {-1} only sets the first element to -1, rest are zero-initialized; this causes incorrect detection of valid input numbers later]
    char ch2[20]={'0'}; // @@ [Initializing with {'0'} sets first char to '0', rest to '\0'; this interferes with detecting operator input correctly]
    int i=0,j=0,len=0,x1=0,sum=0;
    while(1){
        scanf(" %d",ch1+i); // @@ [If input fails (e.g., due to '=' appearing where a number is expected), ch1[i] remains unchanged, leading to use of uninitialized/garbage values]
        if(ch1[i]!=-1){ // @@ [This check is flawed: if the first number read is -1, it will be skipped; also, after initialization, remaining elements are 0, so any 0 input would be incorrectly treated as invalid]
            i++;
        }
        scanf(" %c",ch2+j);
        if(ch2[j]!='0'){ // @@ [This check is flawed: if operator is '0' (which shouldn't happen per problem, but logic is wrong), or if char is '\0' due to initialization, it may skip valid operators]
            j++;
        }
        if(ch2[j-1]=='='){
            break;
        }
    }len=i;
 /* for(j=0;j<i;j++){
        printf("%d",ch1[j]);}
        printf(" %s",ch2);
        printf("%d ",i);*/
        x1=ch1[0];
        j=0;
        for(i=0;i<len;i++){
            if(ch2[i]=='/'){
                x1/=ch1[i+1]; // @@ [Accesses ch1[i+1] which may be out of valid range if expression ends early or parsing was incorrect]
            }
            if(ch2[i]=='*'){
                
                x1*=ch1[i+1]; // @@ [Same issue: potential out-of-bounds access to ch1[i+1]]
                printf("%d\n",x1);
            }
            if(ch2[i]=='+'||ch2[i]=='='){ // @@ [When encountering '=', it treats it like '+', but then uses ch1[i+1] which may not exist (since '=' terminates input)]
                ch1[j]=x1;
            
                ch2[j]='+';
                j++;
                x1=ch1[i+1]; // @@ [Dangerous access to ch1[i+1] when i == len-1 (last valid index), leading to undefined behavior]
            }
            if(ch2[i]=='-'){
                ch1[j]=x1;
            
                ch2[j]='-';
                j++;
                x1=ch1[i+1]; // @@ [Same out-of-bounds risk as above]
            }

        }sum=ch1[0];
        for(i=0;i<j-1;i++){ // @@ [Loop condition should likely be i < j, not j-1, because j operators correspond to j+1 numbers, but logic here is inconsistent]
       //   printf("%d,%c\n",ch1[i],ch2[i]);
            if(ch2[i]=='+'){
                sum+=ch1[i+1];
            }
            if(ch2[i]=='-'){
                sum-=ch1[i+1];
            }
            
        }
        printf("%d",sum);
        return 0;

}