package frontend;

import java.util.ArrayList;
import java.util.HashSet;

public class Error implements Comparable{
    public enum ErrorType{
        a,
        b,
        c,
        d,
        e,
        f,
        g,
        h,
        i,
        j,
        k,
        l,
        m;

        public String toString() {
            return this.name();
        }
    }
    private static ArrayList<Error> errors = new ArrayList<>();

    private static HashSet<Integer> linenos = new HashSet<>();

    public static void addError(Error error) {
//        if (linenos.contains(error.getLineno())) {
//            return;
//        }
//        linenos.add(error.getLineno());
        errors.add(error);
    }

    public static ArrayList<Error> getErrors() {
        return errors;
    }

    private ErrorType errorType;
    private int lineno;

    public Error(ErrorType errorType, int lineno) {
        this.errorType = errorType;
        this.lineno = lineno;
    }

    public String toString() {
        return lineno + " " + errorType.toString() + "\n";
    }

    public int getLineno() {
        return lineno;
    }

    @Override
    public int compareTo(Object o) {
        Error e = (Error) o;
        if (this.lineno > e.lineno) {
            return 1;
        } else {
            return -1;
        }
    }
}
