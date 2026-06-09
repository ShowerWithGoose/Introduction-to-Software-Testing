package frontend;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class Error {
    public enum ErrorType{
        a, b, c, d, e, f, g, h, i, j, k, l, m
    }

    private int lineNum;
    private ErrorType errorType;
    public static List<Error> errors = new ArrayList<>();
    public Error(int lineNum, ErrorType errorType){
        this.lineNum = lineNum;
        this.errorType = errorType;
    }
    public int getLineNum(){
        return lineNum;
    }
    public String getErrorType(){
        return errorType.toString();
    }
    public static void addError(Error error){
        errors.add(error);
    }
    public static void sortErrors() {
        errors.sort(Comparator.comparingInt(Error::getLineNum));
    }
}
