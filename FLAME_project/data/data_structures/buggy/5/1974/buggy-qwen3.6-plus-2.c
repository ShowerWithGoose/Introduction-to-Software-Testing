#include <stdio.h>
#define sf scanf
#define pf printf
#define ll long long 
#include <math.h>
#include <string.h>
#include <stdlib.h> 
#include <ctype.h>
typedef struct {
    int num;
    int xi;
}number;
 number cheng[500];
 number cheng1[500];
 number result[50000];
int compare(const void *a,const void *b){
     number *c=(number *)a;
     number *d=(number *)b;
     return c->xi-d->xi; // @@ The comparison function sorts in ascending order, but the output loop expects descending order (or vice versa). Given the output loop goes from c-1 down to 0, it expects ascending sort so that the largest exponents are at the end. However, standard qsort comparators should return negative if a<b. This implementation returns negative if a->xi < b->xi, which is correct for ascending. The logic error is likely in the merging/output phase.
    
}

int main(){

int a,b,c=0,d,i=0,j=0;


char k;

while(1){
    sf("%d%d%c",&cheng[i].num,&cheng[i].xi,&k);
    i++;
    if(k=='\n')
    break;

}
while(sf("%d%d",&cheng1[j].num,&cheng1[j].xi)!=EOF){

    j++;

}
for(a=0;a<i;a++){
    for(b=0;b<j;b++){
result[c].num=cheng[a].num*cheng1[b].num;
result[c].xi=cheng[a].xi+cheng1[b].xi;
c++;
    }
}
qsort(result,c,sizeof(result[0]),compare);
for(i=c-1;i>=0;i--){ 

    
   if((result[i].xi==result[i-1].xi)&&i>0){ // @@ Logic error: When merging terms with same exponent, it adds current to previous and decrements i. However, if the new sum becomes zero, it should ideally be skipped, but more importantly, this logic fails to print the term if it's the last one in a group or if the group reduces to a single term that isn't handled correctly in the next iteration. Specifically, if result[i] and result[i-1] merge, result[i-1] holds the sum. The loop then decrements i. The next iteration checks result[i-1] (which is now the merged sum) against result[i-2]. This part is logically okay for accumulation, BUT:
        result[i-1].num=result[i].num+result[i-1].num;
        i--;
    }
   
   if((i!=0)&&(result[i].xi!=result[i-1].xi)){ // @@ Logic error: This condition prints result[i] only if it is different from the previous one. However, if result[i] was just merged into result[i-1], result[i] is effectively "consumed" and shouldn't be printed. But if result[i] is NOT merged (i.e., unique exponent), it is printed here. The problem is when i becomes 0.
        pf("%d %d ",result[i].num,result[i].xi);
    }    
 if(i==0){
     pf("%d %d",result[i].num,result[i].xi); // @@ Logic error: If i==0, it prints result[0]. However, if result[0] was part of a merge where result[1] was added to result[0], result[0] contains the correct sum. But if result[0] had the same exponent as result[-1] (impossible) or if result[0] is just a standalone term, it prints. The major issue is that if the coefficient becomes 0 after addition, it should not be printed. Also, the previous if block might have printed result[1] if it wasn't merged with result[0], but if it WAS merged, result[0] is the sum. The logic flow is flawed because it doesn't handle the case where the merged coefficient is 0, nor does it correctly skip printing terms that have been merged into the next lower index properly in all cases. Specifically, if result[i] merges with result[i-1], we decrement i. Then we check if i!=0 and result[i].xi != result[i-1].xi. If i is now 1, and result[1].xi != result[0].xi, it prints result[1]. But result[1] was already merged INTO result[0] in the previous step? No, if i was 1, it checked result[1]==result[0]. If equal, it merged result[1] into result[0] and i became 0. Then it hits i==0 and prints result[0]. This seems okay. 
     // However, look at the expected vs buggy output. 
     // Buggy: ... 12 26 ...
     // Expected: ... 157 26 ...
     // The term with exponent 26 has coefficient 157 in expected, 12 in buggy.
     // Let's trace: 7*21=147 (exp 13+13=26? No. 7x^13 * 3x^21 = 21x^34. 7x^13 * 26x^15 = 182x^28. 7x^13 * 6x^0 = 42x^13.
     // 18x^9 * 26x^15 = 468x^24. 18x^9 * 6x^0 = 108x^9.
     // 5x^5 * 30x^47 = 150x^52. 5x^5 * 15x^32 = 75x^37. 5x^5 * 3x^21 = 15x^26. 5x^5 * 26x^15 = 130x^20. 5x^5 * 6x^0 = 30x^5.
     // So for exp 26: 15x^26 from 5*5 term.
     // Are there other terms with exp 26?
     // 10x^38... no. 2x^26 * 30x^47 = 60x^73. 2x^26 * 15x^32 = 30x^58. 2x^26 * 3x^21 = 6x^47. 2x^26 * 26x^15 = 52x^41. 2x^26 * 6x^0 = 12x^26.
     // Ah! 2x^26 * 6x^0 = 12x^26. And 5x^5 * 3x^21 = 15x^26.
     // Total coeff for x^26 should be 12 + 15 = 27? Wait.
     // Input 1: 10 38, 2 26, 7 13, 5 11, 18 9, 5 5
     // Input 2: 30 47, 15 32, 3 21, 26 15, 6 0
     // Terms for exp 26:
     // From 2x^26 (poly1) and 6x^0 (poly2): 2*6 = 12. Exp 26+0=26.
     // From 5x^5 (poly1) and 3x^21 (poly2): 5*3 = 15. Exp 5+21=26.
     // Sum = 12+15 = 27.
     // Why is expected 157?
     // Let's re-read carefully.
     // 10 38, 2 26, 7 13, 5 11, 18 9, 5 5
     // 30 47, 15 32, 3 21, 26 15, 6 0
     // Maybe I missed a term.
     // 18x^9 * ? = 26? No.
     // 7x^13 * ? = 26? 13+13=26. Is there x^13 in poly2? No.
     // 5x^11 * ? = 26? 11+15=26. 5x^11 * 26x^15 = 130x^26.
     // Ah! 5x^11 * 26x^15 = 130.
     // So terms are: 12 (from 2,26*6,0) + 15 (from 5,5*3,21) + 130 (from 5,11*26,15) = 157.
     // The buggy output has 12. This means it only found one of the terms, or failed to sum them.
     // The sorting and merging logic is flawed.
     // If qsort sorts ascending, result[0] is smallest exp.
     // Loop goes i=c-1 down to 0. So it processes largest exp first.
     // If multiple terms have same exp, they are adjacent in sorted array.
     // Example: exp 26 terms are at indices k, k+1, k+2.
     // Since sorted ascending, larger indices have larger or equal exps.
     // If they are equal, they are adjacent.
     // When i points to the last of the group (highest index among equals), it checks if result[i].xi == result[i-1].xi.
     // If yes, it adds result[i] to result[i-1] and decrements i.
     // This effectively merges upwards (from higher index to lower index).
     // Then i is decremented. Now i points to the middle element.
     // It checks if result[i].xi == result[i-1].xi.
     // If yes, it adds result[i] (which hasn't been changed yet? No, result[i] is the middle one. result[i-1] is the first one.)
     // Wait. The merge is `result[i-1].num += result[i].num`.
     // So it accumulates into the lower index.
     // After full merge, the lowest index in the group holds the sum.
     // The higher indices hold their original values.
     // The loop skips printing if it merged? No.
     // If it merged, it decrements i. Then it continues.
     // The print statement is outside the if.
     // If i!=0 and result[i].xi != result[i-1].xi, it prints.
     // If i==0, it prints.
     // Problem: If a term was merged INTO result[i-1], result[i] still exists and might be printed if the condition `result[i].xi != result[i-1].xi` is false? No, if they were equal, it entered the if block.
     // But after merging and decrementing i, the new i is the old i-1.
     // The term at the old i (now skipped) is never printed explicitly, which is good.
     // But what if the coefficient becomes 0? It still prints.
     // More critically: `if((i!=0)&&(result[i].xi!=result[i-1].xi))`
     // If i=1, and result[1].xi == result[0].xi, it merges result[1] into result[0], i becomes 0.
     // Then `if(i==0)` prints result[0]. Correct.
     // If i=2, result[2].xi == result[1].xi. Merges 2 into 1. i becomes 1.
     // Next iter: i=1. Checks result[1].xi vs result[0].xi.
     // If result[1].xi == result[0].xi, merges 1 into 0. i becomes 0. Prints result[0]. Correct.
     // If result[1].xi != result[0].xi, prints result[1].
     // But result[1] now contains the sum of original result[1] and result[2]. Correct.
     // So the merging logic seems mostly correct for summation.
     // WHY is the output wrong?
     // Look at `compare`. `return c->xi - d->xi`.
     // If c->xi < d->xi, returns negative. Ascending sort.
     // Input:
     // Poly1: 10x^38, 2x^26, 7x^13, 5x^11, 18x^9, 5x^5
     // Poly2: 30x^47, 15x^32, 3x^21, 26x^15, 6x^0
     // Max exp: 38+47=85. Min exp: 5+0=5.
     // The code reads input correctly.
     // The multiplication loop generates all pairs.
     // qsort sorts by exponent ascending.
     // The output loop iterates descending.
     // The error might be that `result` array is not initialized, but it's global so it's 0.
     // Wait, look at the second input reading loop:
     // `while(sf("%d%d",&cheng1[j].num,&cheng1[j].xi)!=EOF)`
     // This loop does NOT check for newline. It reads until EOF.
     // If the input is provided as two lines, and the program runs in an environment where stdin is closed after the second line, it works.
     // But `scanf` with `%d` skips whitespace.
     // The first loop uses `%c` to detect newline.
     // The second loop just reads pairs.
     // If there's a trailing newline, `scanf` skips it.
     // This seems fine.
     
     // Let's look at the `compare` function again.
     // `return c->xi - d->xi;`
     // This can overflow if exponents are large, but here they are small.
     
     // Is it possible that `qsort` is unstable or something? No.
     
     // Let's look at the output format.
     // `pf("%d %d ", ...)` adds a space at the end.
     // `pf("%d %d", ...)` for the last one.
     
     // The bug is likely in the merging/printing logic when coefficients cancel out or when the first term (index 0) is involved in a way that leaves garbage in higher indices? No, higher indices are skipped.
     
     // Actually, there is a subtle bug in the merging loop.
     // `if((result[i].xi==result[i-1].xi)&&i>0)`
     // If this is true, we merge and decrement i.
     // Then the code continues to the next `if`s.
     // If i became 0, it prints.
     // If i is not 0, it checks `if((i!=0)&&(result[i].xi!=result[i-1].xi))`.
     // Note that `result[i]` here is the one we just merged INTO `result[i-1]`? No.
     // We did `result[i-1].num += result[i].num`.
     // Then `i--`.
     // So `i` now points to the element that received the sum.
     // We do NOT print it immediately. We go to the next iteration? No, the `i--` is inside the `if`. The loop `for` also does `i--`?
     // NO! The `for` loop has `i--` in its update expression.
     // Inside the loop body, we have `i--`.
     // So `i` is decremented TWICE in one iteration if a merge happens.
     // This skips an element!
     // Example: Indices 2, 1, 0 have same exp.
     // i=2. Merge 2 into 1. i becomes 1.
     // End of loop body. For loop does i--. i becomes 0.
     // Next iter: i=0. Prints result[0].
     // Result[1] (which holds the sum of 1 and 2) is NEVER printed.
     // Result[0] is printed. But Result[0] was not involved in the merge of 2 and 1.
     // So the sum of 1 and 2 is lost/not printed, and 0 is printed separately.
     // This is the bug.
 }
}



    return 0;
}