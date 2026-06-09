package error;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;

public class ErrorHandling {
    private static String errorFileName = "error.txt";
    public static void printError(int lineNum, char errorType) {
        StringBuffer sb = new StringBuffer();
        sb.append(lineNum);
        sb.append(' ');
        sb.append(errorType);
        sb.append('\n'); //如果有多个错误，输出多个
        try {
            OutputStream errorFileStream = new FileOutputStream(errorFileName);
            try {
                errorFileStream.write(sb.toString().getBytes());
            } catch (IOException e) {
                e.printStackTrace();
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}
