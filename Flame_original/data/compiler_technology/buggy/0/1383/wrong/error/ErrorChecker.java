package error;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

/**
 * @Description ErrorChecker
 */

public class ErrorChecker {

    private static ArrayList<String> errorList = new ArrayList<>();

    public static void addError(ErrorType errorType, int lineNum) {
        errorList.add(lineNum + " " + errorType);
    }

    public static void clearError() {
        errorList.clear();
    }

    public static void printErrorToFile(String filePath) throws IOException {
        File file = new File(filePath);
        if (!file.exists()) {
            file.createNewFile();
        }
        FileWriter writer = new FileWriter(file);
        for (String error : errorList) {
            writer.write(error + "\n");
        }
        writer.close();
    }
}
