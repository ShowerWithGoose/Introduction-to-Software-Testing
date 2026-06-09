/********************************************************************************
 * @FileName     : ErrorHandler.java
 * @Author       :
 * @Description  : 错误处理类
 * @Notice       : None
 * @Time         : 2024-10-03 21:22
 * @Version      : 0.0
 ********************************************************************************/

package error;

import frontend.Token;

import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Comparator;

public class ErrorHandler {
    private static ArrayList<Error> errorLists = new ArrayList<>();

    public static void recordError(Error error) {
        errorLists.add(error);
    }

    public static void recordError(ErrorType errorType, int lineNumber) {
        recordError(new Error(errorType, lineNumber));
    }

    // 获取全部错误信息，按行号顺序输出
    public static String getErrorsAllOrder() {
        StringBuilder output = new StringBuilder();
        errorLists.sort(Comparator.comparingInt(Error::getLineNumber));
        for (Error error : errorLists) {
            output.append(error.toString()).append("\n");
        }
        return output.toString();
    }

    // 获取全部错误信息，按行输出
    public static String getErrorsAll() {
        StringBuilder output = new StringBuilder();
        for (Error error : errorLists) {
            output.append(error.toString()).append("\n");
        }
        return output.toString();
    }

    // 获取错误信息，按行输出，一行只输出一个
    public static String getErrorsEveryRow() {
        StringBuilder output = new StringBuilder();
        int lastErrorLine = 0;
        for (Error error : errorLists) {
            if (error.lineNumber != lastErrorLine)
                output.append(error.toString()).append("\n");
            lastErrorLine = error.lineNumber;
        }
        return output.toString();
    }


    /**
     * 判断是否无错误
     *
     * @return boolean true:无错误，false:有错误
     */
    public static boolean isEmpty() {
        return errorLists.isEmpty();
    }

    /**
     * 判断是否无错误
     *
     * @return boolean true:无错误，false:有错误
     */
    public static boolean withoutError() {
        return ErrorHandler.isEmpty();
    }
}
