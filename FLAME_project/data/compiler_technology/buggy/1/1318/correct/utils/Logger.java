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
        // logs 按照第一个数字排序
        logs.sort((o1, o2) -> {
            int i1 = Integer.parseInt(o1.split(" ")[0]);
            int i2 = Integer.parseInt(o2.split(" ")[0]);
            return Integer.compare(i1, i2);
        });
        WriteFile("error.txt", logs);
    }
}
