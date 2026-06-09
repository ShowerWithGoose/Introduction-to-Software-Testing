package frontend.check;

import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.TreeMap;

public class ErrorMap {
    private final HashMap<Integer, ErrorType> errorMap;
    private static final ErrorMap INSTANCE = new ErrorMap();  
    
    private ErrorMap() {
        this.errorMap = new HashMap<>();
    }  
  
    public static ErrorMap getInstance() {  
        return INSTANCE;  
    } 
    
    public void addError(int lineNum, ErrorType errorType) {
        errorMap.put(lineNum, errorType);
    }
    
    public boolean hasError() {
        return !errorMap.isEmpty();
    }
    
    public void printError(OutputStream outputStream) {
        PrintWriter writer = new PrintWriter(outputStream);
        TreeMap<Integer, ErrorType> sortedMap = new TreeMap<>(errorMap);
        for (Map.Entry<Integer, ErrorType> entry : sortedMap.entrySet()) {
            int lineNum = entry.getKey();
            ErrorType errorType = entry.getValue();
            writer.println(lineNum + " " + errorType.getType());
        }
        
        // 刷新输出流确保输出完整
        writer.flush();
    }
}
