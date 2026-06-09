package frontend.tool;

import java.io.FileWriter;
import java.io.IOException;

public class errorManager {
    private static final String errorFilePath = "error.txt";
    private static final FileWriter errorWriter;

    static {
        try {
            errorWriter = new FileWriter(errorFilePath);
            errorWriter.flush();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static void handleError(int tokenLine, String errorType) {
        try {
            errorWriter.write(tokenLine + " " + errorType + "\n");
            errorWriter.flush();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static void close() {
        try {
            errorWriter.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
