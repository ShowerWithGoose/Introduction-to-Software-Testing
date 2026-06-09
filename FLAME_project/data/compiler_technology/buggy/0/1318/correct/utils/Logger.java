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

    public boolean isSuccess() {
        return success;
    }

    public void print() {
        WriteFile("error.txt", logs);
    }
}
