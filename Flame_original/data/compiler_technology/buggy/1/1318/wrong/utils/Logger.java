package utils;

import java.util.ArrayList;

import static utils.File.WriteFile;

public class Logger {
    //记录词法分析log
    public static Logger logger = new Logger();
    private boolean success = true;
    private ArrayList<String> logs = new ArrayList<>();

    private Logger() {
    }

    public void error(String message) {
        success = false;
        logs.add(message);
    }

    // 记录词法分析log，为consume方法添加
    public <T> T check(T value, String errorMessage) {
        if (value == null) {
            error(errorMessage);
        }
        return value;
    }

    public boolean isSuccess() {
        return success;
    }

    public void print() {
        WriteFile("error.txt", logs);
    }
}
