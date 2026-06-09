package frontend;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
public class ErrorType {
    private int lineNum;
    private String errorType;
    private int tokenIndex;

    public ErrorType(int lineNum, String errorType, int tokenIndex)
    {
        this.lineNum = lineNum;
        this.errorType = errorType;
        this.tokenIndex = tokenIndex;
    }
    public int getLineNum(){
        return lineNum;
    }
    public String getErrorType(){
        return errorType;
    }
    public int getTokenIndex(){
        return tokenIndex;
    }
    public void printError(FileWriter errorWriter) throws IOException {
        errorWriter.write(String.format("%d %s\n",lineNum, errorType));
    }
    // Method to sort the list of ErrorType objects
    public static void sortErrorTypes(List<ErrorType> errorList) {
        Collections.sort(errorList, new Comparator<ErrorType>() {
            @Override
            public int compare(ErrorType et1, ErrorType et2) {
                // First compare by lineNum
                int lineComparison = Integer.compare(et1.getLineNum(), et2.getLineNum());
                if (lineComparison != 0) {
                    return lineComparison;
                }
                // If lineNum is the same, compare by tokenIndex
                return Integer.compare(et1.getTokenIndex(), et2.getTokenIndex());
            }
        });
    }
}
