package error;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;

public class ErrorHandling {
    private static String errorFileName = "error.txt";

    public static void printError(int lineNum, char errorType) {
        Error error = new Error(lineNum,errorType);
        ErrorList.addError(error);
    }

    public static void output() {
        try {
            OutputStream errorFileStream = new FileOutputStream(errorFileName);
            try {
                errorFileStream.write(ErrorList.output().getBytes());
            } catch (IOException e) {
                e.printStackTrace();
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}
