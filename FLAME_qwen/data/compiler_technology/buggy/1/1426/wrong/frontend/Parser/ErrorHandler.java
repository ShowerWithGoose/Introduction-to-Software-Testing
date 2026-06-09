package frontend.Parser;

import java.util.ArrayList;
import java.util.List;

public class ErrorHandler {
    private static ErrorHandler instance = null;
    private boolean hasError = false;
    private static List<String> errors = new ArrayList<>();

    // 私有构造函数，确保外部不能直接实例化
    private ErrorHandler() {
        errors = new ArrayList<>();
    }
    public static ErrorHandler getInstance() {
        if (instance == null) {
            synchronized (ErrorHandler.class) {
                if (instance == null) {
                    instance = new ErrorHandler();
                }
            }
        }
        return instance;
    }

    public void reportError(int line, String message) {
        hasError = true;
        errors.add(String.valueOf(line) + " " + message);
    }

    public boolean hasErrorOccurred() {
        return hasError;
    }


    public List<String> getErrors() {
        return errors;
    }
}
