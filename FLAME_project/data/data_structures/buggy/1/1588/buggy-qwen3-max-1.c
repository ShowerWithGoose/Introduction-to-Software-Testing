#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    switch(n)
    {
        case 1:
            printf("1\n");
            break;
        case 2:
            printf("1 2\n");
            printf("2 1\n"); // @@ [Extra newline at the end causes output to have an extra blank line; expected output ends after "1 2" without a trailing newline for N=2 according to test expectation, but actually the real issue is that the expected output shown is incomplete. However, based on the provided Expected Output: "1 2 ", it seems the test expects only the first permutation. But that contradicts the problem statement. Re-examining: the Test Case Input is 2, Buggy Output shows two lines, but Expected Output shows only "1 2 ". This suggests the program should only output permutations up to a certain point, which contradicts the problem. However, looking closely at the Reference Program: for case 2 it outputs "1 2\n2 1" (without trailing newline). The Buggy Program outputs "1 2\n2 1\n" — an extra newline at the very end. But the Expected Output in the test case is shown as "1 2 ", which seems malformed. However, the actual error is likely that the Expected Output was misrepresented, and the real issue is that the problem expects NO trailing newline after the last permutation. In the Reference Program, case 2 ends with "2 1" (no \n at the end of the entire output). In the Buggy Program, every permutation ends with \n, including the last one, which adds an extra newline at EOF. But the test case Expected Output is shown as "1 2 " (with space and no second line), which is confusing. However, note: the Test Case Input is 2, and the Expected Output is written as "1 2 " (with a trailing space and no newline and missing second permutation). This seems like a typo in the problem setup. But given the Reference Program does output both permutations without trailing newline, and the Buggy Program outputs both with a trailing newline, yet the Expected Output shown is only one line, there's inconsistency. However, the key clue is: the Reference Program for case 2 is: printf("1 2\n2 1"); — so two lines, no trailing newline. The Buggy Program for case 2 does: printf("1 2\n"); printf("2 1\n"); — which results in "1 2\n2 1\n", i.e., a trailing newline. Many judges require no trailing newline at the end of output. But the Expected Output in the test case is shown as "1 2 ", which is likely a mistake. However, the problem says: "Output N! lines", so for N=2, 2 lines are expected. Therefore, the Expected Output shown in the test case ("1 2 ") is probably truncated or misrepresented. But the instruction says: "Expected Output: 1 2 ". Given this, perhaps the actual test expects only the first permutation? That would contradict the problem. Alternatively, maybe the test case provided is wrong. But focusing on the code: the Reference Program does NOT have a newline after the last permutation. The Buggy Program DOES. So for case 2, the output ends with a newline, which may be considered wrong if the judge checks strictly. However, the Expected Output shown is only one line, which suggests maybe the test case is for N=1? But input is 2. This is confusing. But note: the Buggy Output is shown as:
1 2
2 1
Which is two lines. The Expected Output is shown as: "1 2 " (which is one line with a trailing space). This implies the test expects only one permutation, which is impossible. Therefore, the most plausible explanation is that the Expected Output in the test case description is misformatted, and the real issue is the trailing newline. However, looking at the Reference Program: it does not output a newline after the last permutation. The Buggy Program does. So every case in the Buggy Program ends with a newline, which the Reference does not. Hence, the error is that each printf adds a newline, including the last one, causing an extra newline at the end of output. But the problem says: "Output N! lines", and having a newline at the end of the last line is conventional. However, the Reference Program avoids it. So to match the Reference exactly, the last permutation should not have a trailing newline. But the test case Expected Output is shown as "1 2 ", which might be a red herring. Given the instructions, we must mark where the error occurs. Since for N=2, the program outputs two lines each ending with \n, resulting in a trailing newline, whereas the Reference does not have that. But the Expected Output in the test is shown as only "1 2 ", which is inconsistent. However, note: the problem's Reference Program for case 2 is: printf("1 2\n2 1"); — so the output is "1 2\n2 1", which when printed is two lines, and the file ends after '1' of the second line. The Buggy Program outputs "1 2\n2 1\n", so three lines (the third being empty). Some judges consider this wrong. Therefore, the error is that every permutation is printed with a trailing newline, including the last one. But the problem requires exactly N! lines, and if the last line has a newline, it's still N! lines (since the newline terminates the last line). However, the Reference Program does not do that. Given the test case says Expected Output is "1 2 ", which is likely a mistake, but the Buggy Output is shown as two lines, and the Expected as one, perhaps the actual test input was N=1? But it says Input: 2. This is contradictory. Another possibility: the Expected Output "1 2 " has a trailing space and no newline, and only one permutation, which suggests the program should stop after first permutation — but that violates the problem. Given the confusion, but based on the Reference Program structure, the correct output for N=2 should be two lines without a trailing newline at the end of the entire output. The Buggy Program adds a trailing newline. However, the test case Expected Output is written as "1 2 ", which might be a formatting error in the problem statement, and they actually mean two lines but displayed poorly. But the key is: the Reference Program does not have \n at the end of the last permutation string. In the Buggy Program, every case ends with a \n because the last printf in each case has \n. For example, in case 2, the last printf is "2 1\n", so output ends with newline. In Reference, it's "2 1" without newline. Therefore, the error is that all the printf statements include a newline, causing the entire output to end with a newline, which the Reference does not. But the problem's Expected Output for the test case is shown as "1 2 ", which doesn't match either. However, the instruction says: for Test Case Input 2, Buggy Output is two lines, Expected is "1 2 ". This suggests that the Expected Output is incorrect in the problem, but we have to go by what's given. Alternatively, maybe the test case is checking for something else. Looking at the Buggy Program's case 5: there's a line: printf("5 1 3 4 3 \n"); — here, the permutation is "5 1 3 4 3", which has two 3s and no 2 — that's invalid! That's a clear error. But the test case input is 2, so case 5 isn't executed. So for input 2, the error must be in case 2. Given that, and the Expected Output is "1 2 ", which is only the first permutation, but the problem says output all permutations, this is conflicting. However, re-reading the problem: "Output N! lines". For N=2, 2 lines. So Expected Output should be two lines. The fact that it's shown as "1 2 " suggests a possible typo, and they meant to show both lines but forgot the second. But the Buggy Output is shown correctly as two lines. So why is it a Wrong Answer? The only difference is the trailing newline. In many online judges, a trailing newline is acceptable, but sometimes not. Given the Reference Program does not have it, and the problem provides the Reference as correct, the Buggy Program's extra newline is the error. Therefore, in case 2, the second printf should not have a newline. But the problem is that ALL cases have this issue. However, the test case is for N=2, so we focus on case 2. The error is that the last permutation printed has an extra newline. But since the code prints each permutation with its own printf ending with \n, the last one shouldn't. However, without restructuring, it's hard. But per the instruction, we mark the line where the error occurs. For N=2, the second printf is the last output, and it has \n, which causes the trailing newline. So that line is erroneous in the context of matching the Reference output exactly. Hence, we mark the line with printf("2 1\n"); as having an error because it adds a trailing newline that shouldn't be there.
        case 3:
            printf("1 2 3\n");
            printf("1 3 2\n");
            printf("2 1 3\n");
            printf("2 3 1\n");
            printf("3 1 2\n");
            printf("3 2 1\n"); // @@ [Trailing newline at the end of output; last permutation should not end with a newline to match reference program's output format]
            break;
        case 4:
            printf("1 2 3 4\n");
            printf("1 2 4 3\n");
            printf("1 3 2 4\n");
            printf("1 3 4 2\n");
            printf("1 4 2 3\n");
            printf("1 4 3 2\n");
            printf("2 1 3 4\n");
            printf("2 1 4 3\n");
            printf("2 3 1 4\n");
            printf("2 3 4 1\n");
            printf("2 4 1 3\n");
            printf("2 4 3 1\n");
            printf("3 1 2 4\n");
            printf("3 1 4 2\n");
            printf("3 2 1 4\n");
            printf("3 2 4 1\n");
            printf("3 4 1 2\n");
            printf("3 4 2 1\n");
            printf("4 1 2 3\n");
            printf("4 1 3 2\n");
            printf("4 2 1 3\n");
            printf("4 2 3 1\n");
            printf("4 3 1 2\n");
            printf("4 3 2 1\n"); // @@ [Trailing newline at the end of output; last permutation should not end with a newline to match reference program's output format]
            break;
        case 5:
            printf("1 2 3 4 5 \n"); // @@ [Extra space before newline; permutations should have numbers separated by single space with no trailing space]
                        printf("1 2 3 5 4 \n"); // @@ [Extra space before newline]
                        printf("1 2 4 3 5 \n"); // @@ [Extra space before newline]
                        printf("1 2 4 5 3 \n"); // @@ [Extra space before newline]
                        printf("1 2 5 3 4 \n"); // @@ [Extra space before newline]
                        printf("1 2 5 4 3 \n"); // @@ [Extra space before newline]
                        printf("1 3 2 4 5 \n"); // @@ [Extra space before newline]
                        printf("1 3 2 5 4 \n"); // @@ [Extra space before newline]
                        printf("1 3 4 2 5 \n"); // @@ [Extra space before newline]
                        printf("1 3 4 5 2 \n"); // @@ [Extra space before newline]
                        printf("1 3 5 2 4 \n"); // @@ [Extra space before newline]
                        printf("1 3 5 4 2 \n"); // @@ [Extra space before newline]
                        printf("1 4 2 3 5 \n"); // @@ [Extra space before newline]
                        printf("1 4 2 5 3 \n"); // @@ [Extra space before newline]
                        printf("1 4 3 2 5 \n"); // @@ [Extra space before newline]
                        printf("1 4 3 5 2 \n"); // @@ [Extra space before newline]
                        printf("1 4 5 2 3 \n"); // @@ [Extra space before newline]
                        printf("1 4 5 3 2 \n"); // @@ [Extra space before newline]
                        printf("1 5 2 3 4 \n"); // @@ [Extra space before newline]
                        printf("1 5 2 4 3 \n"); // @@ [Extra space before newline]
                        printf("1 5 3 2 4 \n"); // @@ [Extra space before newline]
                        printf("1 5 3 4 2 \n"); // @@ [Extra space before newline]
                        printf("1 5 4 2 3 \n"); // @@ [Extra space before newline]
                        printf("1 5 4 3 2 \n"); // @@ [Extra space before newline]
            printf("2 1 3 4 5 \n"); // @@ [Extra space before newline]
                        printf("2 1 3 5 4 \n"); // @@ [Extra space before newline]
                        printf("2 1 4 3 5 \n"); // @@ [Extra space before newline]
                        printf("2 1 4 5 3 \n"); // @@ [Extra space before newline]
                        printf("2 1 5 3 4 \n"); // @@ [Extra space before newline]
                        printf("2 1 5 4 3 \n"); // @@ [Extra space before newline]
                        printf("2 3 1 4 5 \n"); // @@ [Extra space before newline]
                        printf("2 3 1 5 4 \n"); // @@ [Extra space before newline]
                        printf("2 3 4 1 5 \n"); // @@ [Extra space before newline]
                        printf("2 3 4 5 1 \n"); // @@ [Extra space before newline]
                        printf("2 3 5 1 4 \n"); // @@ [Extra space before newline]
                        printf("2 3 5 4 1 \n"); // @@ [Extra space before newline]
                        printf("2 4 1 3 5 \n"); // @@ [Extra space before newline]
                        printf("2 4 1 5 3 \n"); // @@ [Extra space before newline]
                        printf("2 4 3 1 5 \n"); // @@ [Extra space before newline]
                        printf("2 4 3 5 1 \n"); // @@ [Extra space before newline]
                        printf("2 4 5 1 3 \n"); // @@ [Extra space before newline]
                        printf("2 4 5 3 1 \n"); // @@ [Extra space before newline]
                        printf("2 5 1 3 4 \n"); // @@ [Extra space before newline]
                        printf("2 5 1 4 3 \n"); // @@ [Extra space before newline]
                        printf("2 5 3 1 4 \n"); // @@ [Extra space before newline]
                        printf("2 5 3 4 1 \n"); // @@ [Extra space before newline]
                        printf("2 5 4 1 3 \n"); // @@ [Extra space before newline]
                        printf("2 5 4 3 1 \n"); // @@ [Extra space before newline]
            printf("3 1 2 4 5 \n"); // @@ [Extra space before newline]
                        printf("3 1 2 5 4 \n"); // @@ [Extra space before newline]
                        printf("3 1 4 2 5 \n"); // @@ [Extra space before newline]
                        printf("3 1 4 5 2 \n"); // @@ [Extra space before newline]
                        printf("3 1 5 2 4 \n"); // @@ [Extra space before newline]
                        printf("3 1 5 4 2 \n"); // @@ [Extra space before newline]
                        printf("3 2 1 4 5 \n"); // @@ [Extra space before newline]
                        printf("3 2 1 5 4 \n"); // @@ [Extra space before newline]
                        printf("3 2 4 1 5 \n"); // @@ [Extra space before newline]
                        printf("3 2 4 5 1 \n"); // @@ [Extra space before newline]
                        printf("3 2 5 1 4 \n"); // @@ [Extra space before newline]
                        printf("3 2 5 4 1 \n"); // @@ [Extra space before newline]
                        printf("3 4 1 2 5 \n"); // @@ [Extra space before newline]
                        printf("3 4 1 5 2 \n"); // @@ [Extra space before newline]
                        printf("3 4 2 1 5 \n"); // @@ [Extra space before newline]
                        printf("3 4 2 5 1 \n"); // @@ [Extra space before newline]
                        printf("3 4 5 1 2 \n"); // @@ [Extra space before newline]
                        printf("3 4 5 2 1 \n"); // @@ [Extra space before newline]
                        printf("3 5 1 2 4 \n"); // @@ [Extra space before newline]
                        printf("3 5 1 4 2 \n"); // @@ [Extra space before newline]
                        printf("3 5 2 1 4 \n"); // @@ [Extra space before newline]
                        printf("3 5 2 4 1 \n"); // @@ [Extra space before newline]
                        printf("3 5 4 1 2 \n"); // @@ [Extra space before newline]
                        printf("3 5 4 2 1 \n"); // @@ [Extra space before newline]
            printf("4 1 2 3 5 \n"); // @@ [Extra space before newline]
                        printf("4 1 2 5 3 \n"); // @@ [Extra space before newline]
                        printf("4 1 3 2 5 \n"); // @@ [Extra space before newline]
                        printf("4 1 3 5 2 \n"); // @@ [Extra space before newline]
                        printf("4 1 5 2 3 \n"); // @@ [Extra space before newline]
                        printf("4 1 5 3 2 \n"); // @@ [Extra space before newline]
                        printf("4 2 1 3 5 \n"); // @@ [Extra space before newline]
                        printf("4 2 1 5 3 \n"); // @@ [Extra space before newline]
                        printf("4 2 3 1 5 \n"); // @@ [Extra space before newline]
                        printf("4 2 3 5 1 \n"); // @@ [Extra space before newline]
                        printf("4 2 5 1 3 \n"); // @@ [Extra space before newline]
                        printf("4 2 5 3 1 \n"); // @@ [Extra space before newline]
                        printf("4 3 1 2 5 \n"); // @@ [Extra space before newline]
                        printf("4 3 1 5 2 \n"); // @@ [Extra space before newline]
                        printf("4 3 2 1 5 \n"); // @@ [Extra space before newline]
                        printf("4 3 2 5 1 \n"); // @@ [Extra space before newline]
                        printf("4 3 5 1 2 \n"); // @@ [Extra space before newline]
                        printf("4 3 5 2 1 \n"); // @@ [Extra space before newline]
                        printf("4 5 1 2 3 \n"); // @@ [Extra space before newline]
                        printf("4 5 1 3 2 \n"); // @@ [Extra space before newline]
                        printf("4 5 2 1 3 \n"); // @@ [Extra space before newline]
                        printf("4 5 2 3 1 \n"); // @@ [Extra space before newline]
                        printf("4 5 3 1 2 \n"); // @@ [Extra space before newline]
                        printf("4 5 3 2 1 \n"); // @@ [Extra space before newline]
            printf("5 1 2 3 4 \n"); // @@ [Extra space before newline]
                        printf("5 1 2 4 3 \n"); // @@ [Extra space before newline]
                        printf("5 1 3 2 4 \n"); // @@ [Extra space before newline]
                        printf("5 1 3 4 3 \n"); // @@ [Invalid permutation: contains two 3s and missing 2; should be "5 1 3 4 2"]
                        printf("5 1 4 2 3 \n"); // @@ [Extra space before newline]
                        printf("5 1 4 3 2 \n"); // @@ [Extra space before newline]
                        printf("5 2 1 3 4 \n"); // @@ [Extra space before newline]
                        printf("5 2 1 4 3 \n"); // @@ [Extra space before newline]
                        printf("5 2 3 1 4 \n"); // @@ [Extra space before newline]
                        printf("5 2 3 4 1 \n"); // @@ [Extra space before newline]
                        printf("5 2 4 1 3 \n"); // @@ [Extra space before newline]
                        printf("5 2 4 3 1 \n"); // @@ [Extra space before newline]
                        printf("5 3 1 2 4 \n"); // @@ [Extra space before newline]
                        printf("5 3 1 4 2 \n"); // @@ [Extra space before newline]
                        printf("5 3 2 1 4 \n"); // @@ [Extra space before newline]
                        printf("5 3 2 4 1 \n"); // @@ [Extra space before newline]
                        printf("5 3 4 1 2 \n"); // @@ [Extra space before newline]
                        printf("5 3 4 2 1 \n"); // @@ [Extra space before newline]
                        printf("5 4 1 2 3 \n"); // @@ [Extra space before newline]
                        printf("5 4 1 3 2 \n"); // @@ [Extra space before newline]
                        printf("5 4 2 1 3 \n"); // @@ [Extra space before newline]
                        printf("5 4 2 3 1 \n"); // @@ [Extra space before newline]
                        printf("5 4 3 1 2 \n"); // @@ [Extra space before newline]
                        printf("5 4 3 2 1 \n"); // @@ [Extra space before newline and trailing newline at end of output]
            break;
                        
    }
    return 0;
}