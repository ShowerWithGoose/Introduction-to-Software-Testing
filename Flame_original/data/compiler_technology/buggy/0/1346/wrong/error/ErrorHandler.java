package error;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

/**
 * @author
 * @Description:
 * @date 2024/9/29 17:23
 */
public class ErrorHandler {
    //单例模式
    private static final ErrorHandler instance = new ErrorHandler();
    public static ErrorHandler getInstance() {
        return instance;
    }
    //错误列表
    private List<Error> errors = new ArrayList<>();
    //用于在其他地方添加error
    public void addError(Error newError) {
        for (Error error : errors) {
            if (error.equals(newError)) {
                return;
            }
        }
        errors.add(newError);
    }
    public void printErrors(String filename) {
        //按行号排序
        Collections.sort(errors, Comparator.comparingInt(Error::getLineNumber));
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filename))) {
            for (Error error : errors) {
                writer.write(error.toString());
            }
        } catch (IOException e) {
            System.err.println("Can not open " + filename);
        }
    }
}
