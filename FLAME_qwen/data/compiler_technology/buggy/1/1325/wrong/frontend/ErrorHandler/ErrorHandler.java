package frontend.ErrorHandler;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.util.HashMap;

public class ErrorHandler {
    public static ErrorHandler ERROR = new ErrorHandler();

    private HashMap<Integer, String> errMap = new HashMap<>();

    public void addError(Error error) {
        int line = error.getLine();
        if (errMap.containsKey(line)) {
            String oldErrorCode = errMap.get(line);
            errMap.replace(line, oldErrorCode + " " + error.getErrorCode());
        } else {
            errMap.put(line, error.getErrorCode());
        }
    }

    public void log(BufferedWriter err) {
        errMap.keySet().stream().sorted().forEach( line ->{
            try {
                String errCode = errMap.get(line);
                String[] errorCodes = errCode.split(" ");
                for (String errorcode : errorCodes) {
                    err.write(line + " " + errorcode + "\n");
                }
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        });
    }
}
