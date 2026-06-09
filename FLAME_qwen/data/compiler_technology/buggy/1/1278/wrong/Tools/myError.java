package Tools;

import java.util.TreeMap;

public class myError {
    public enum ErrorType {
        ERROR_A, ERROR_I, ERROR_J, ERROR_K
    }

    public myError(myError.ErrorType type, int lineno) {
        this.type = type;
        this.lineno = lineno;
    }

    static TreeMap<Integer, myError> errorTreeMap = new TreeMap<>();
    private myError.ErrorType type;
    private int lineno;

    public static void newError(myError.ErrorType type, int lineno) {
        errorTreeMap.put(lineno, new myError(type, lineno));
    }

    public static TreeMap<Integer, myError> getErrorTreeMap() {
        return errorTreeMap;
    }

    @Override
    public String toString() {
        switch (type) {
            case ERROR_A:
                return "a";
            case ERROR_I:
                return "i";
            case ERROR_J:
                return "j";
            case ERROR_K:
                return "k";
            default:
                return "UN_ERROR";
        }
    }
}
