import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.TreeMap;

public class Error {
    private static TreeMap<Integer, String> errorMap = new TreeMap<>();

    public static void lexerError(int lineNum, String errorCode) {
        errorMap.put(lineNum, errorCode);
    }

    public static void syntaxError(int lineNum, String errorCode) {
        errorMap.put(lineNum, errorCode);
    }

    public static void writeErrorsToFile() {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter("error.txt"))) {
            for (var entry : errorMap.entrySet()) {
                writer.write(entry.getKey() + " " + entry.getValue() + "\n");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
    public static boolean hasErrors() {
        return !errorMap.isEmpty();
    }

    public static void clearErrors() {
        errorMap.clear();
    }
}