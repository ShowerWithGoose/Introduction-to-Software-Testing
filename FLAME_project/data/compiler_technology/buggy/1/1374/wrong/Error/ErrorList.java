package Error;
import Fronted.lexer.Token;

import java.util.ArrayList;
import java.util.Comparator;

public class ErrorList {
    private static final ErrorList errorList = new ErrorList();

    public static ErrorList getErrorList(){
        sort();
        return errorList;
    }

    private static final ArrayList<Error> errors = new ArrayList<Error>();

    public void add(Error error){
        errors.add(error);
    }

    public static void sort() {
        errors.sort(Comparator.comparingInt(Error::getLineNum));
    }

    public void add(int line, ErrorType errorType){
        errors.add(new Error(line, errorType));
    }

    public void add(Token token, ErrorType errorType){
        errors.add(new Error(token.getLine(), errorType));
    }


    @Override
    public String toString() {
        StringBuilder out = new StringBuilder();
        for(Error error : this.errors){
            out.append(error).append("\n");
            //System.out.println(error);
        }
        return out.toString();
    }
}
