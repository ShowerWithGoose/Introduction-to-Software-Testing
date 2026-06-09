package frontend;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;

public class ErrorList {
    private ArrayList<Error> errors;
    public ErrorList(ArrayList<Error> errors) {
        this.errors = errors;
    }
    public String errorsToString(){
        StringBuilder sb = new StringBuilder();
        Error[] errors = this.errors.toArray(new Error[0]);
        Arrays.sort(errors, Comparator.comparingInt(Error::getErrorLineNo));
        for (Error error : errors) {
            sb.append(error.toString()).append("\n");
        }
        return sb.toString();
    }
}
