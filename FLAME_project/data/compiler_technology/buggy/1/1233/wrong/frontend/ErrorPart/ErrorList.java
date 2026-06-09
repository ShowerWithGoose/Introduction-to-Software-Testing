package frontend.ErrorPart;

import java.util.TreeSet;

public class ErrorList {
    private ErrorList(){}
    public static TreeSet<Error> errors = new TreeSet<>();
    public static void addError(Error error){
        errors.add(error);
    }
    public static TreeSet<Error> getErrors(){
        return errors;
    }
    public static String finalOut(){
        StringBuilder sb = new StringBuilder();
        for (Error error : errors) {
            sb.append(error.getLine()+" "+error.getType()+"\n");
        }
        return sb.toString();
    }
    public static boolean hasError(){
        return !errors.isEmpty();
    }
}
