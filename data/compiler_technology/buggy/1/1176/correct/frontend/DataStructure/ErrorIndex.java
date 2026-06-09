package frontend.DataStructure;

import java.util.ArrayList;
import java.util.List;

public class ErrorIndex {
    public int lexIndex;
    public int lineNum;
    public char errType;

    public ErrorIndex(int lexIndex,int lineNum, char errType){
        this.lexIndex = lexIndex;
        this.lineNum = lineNum;
        this.errType = errType;
    }

    public static List<ErrorIndex> errorList = new ArrayList<>();

    public static boolean isCorrect(){
        return errorList.isEmpty();
    }

}
