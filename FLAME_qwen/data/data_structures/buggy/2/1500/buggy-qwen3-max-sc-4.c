#include<stdio.h>
#include<string.h>
int main(){
    int ch1[20]={-1}; // @@ [Initializing array with {-1} only sets the first element to -1, others are zero; this causes incorrect detection of valid input numbers]
    char ch2[20]={'0'}; // @@ [Initializing with {'0'} sets first char to '0', others to '\0'; this interferes with detecting operator input correctly]
    int i=0,j=0,len=0,x1=0,sum=0;
    while(1){
        scanf(" %d",ch1+i); // @@ [Passing int* is correct, but logic assumes scanf always succeeds; also, initial -1 check fails if user inputs -1 as a valid number]
        if(ch1[i]!=-1){ // @@ [This condition is flawed: if actual input is -1, it will be skipped; also, uninitialized elements may coincidentally be -1]
            i++;
        }
        scanf(" %c",ch2+j); // @@ [Passing char* is correct, but logic assumes scanf always succeeds; also, initial '0' check fails if user inputs '0' as operator (which they won't), but more critically, space handling may cause issues]
        if(ch2[j]!='0'){ // @@ [Flawed condition: if operator is read correctly, it's never '0', so j always increments; but initial '0' in array causes misalignment when checking ch2[j-1]]
            j++;
        }
        if(ch2[j-1]=='='){ // @@ [If first operator read is '=', j=1, so ch2[0]='=', OK; but if input parsing fails or extra spaces exist, this may access uninitialized memory]
            break;
        }
    }len=i;
 /* for(j=0;j<i;j++){
        printf("%d",ch1[j]);}
        printf(" %s",ch2);
        printf("%d ",i);*/
        x1=ch1[0];
        j=0;
        for(i=0;i<len;i++){ // @@ [Loop runs for len = number of numbers, but ch2 has j operators; indexing ch2[i] may go out of sync if parsing was incorrect]
            if(ch2[i]=='/'){
                x1/=ch1[i+1]; // @@ [Assumes ch1[i+1] exists; if expression ends early, this accesses out-of-bounds memory]
            }
            if(ch2[i]=='*'){
                
                x1*=ch1[i+1]; // @@ [Same out-of-bounds risk as above]
                printf("%d\n",x1);
            }
            if(ch2[i]=='+'||ch2[i]=='='){ // @@ [When encountering '=', it treats it like '+', but '=' should terminate and not be processed as an operator in evaluation]
                ch1[j]=x1;
            
                ch2[j]='+';
                j++;
                x1=ch1[i+1]; // @@ [Again, accesses ch1[i+1] which may be out of bounds, especially when ch2[i] is '=' at the end]
            }
            if(ch2[i]=='-'){
                ch1[j]=x1;
            
                ch2[j]='-';
                j++;
                x1=ch1[i+1]; // @@ [Same out-of-bounds issue]
            }

        }sum=ch1[0];
        for(i=0;i<j-1;i++){ // @@ [Loop condition i < j-1 may skip last term if j is small; also assumes ch1 and ch2 are properly packed, which they aren't due to earlier flaws]
       //   printf("%d,%c\n",ch1[i],ch2[i]);
            if(ch2[i]=='+'){
                sum+=ch1[i+1];
            }
            if(ch2[i]=='-'){
                sum-=ch1[i+1]; // @@ [Accesses ch1[i+1]; if j is number of stored terms, ch1 may not have i+1-th element]
            }
            
        }
        printf("%d",sum);
        return 0;

}