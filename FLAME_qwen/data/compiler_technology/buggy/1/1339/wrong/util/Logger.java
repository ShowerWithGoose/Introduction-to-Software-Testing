package util;

import frontend.Error.ErrorItem;

import java.util.ArrayList;
import java.util.Comparator;

import static util.File.writeFile;

public class Logger {
    public static Logger logger = new Logger();
    private ArrayList<ErrorItem> logs = new ArrayList<>();


    private Logger() {
    }

    public void error(ErrorItem error) {
        logs.add(error);
    }

    public <T> T check(T obj, ErrorItem error) {
        if (obj == null) {
            error(error);
        }
        return obj;
    }

    public boolean hasError() {
        return !logs.isEmpty();
    }

    public void print() {
        logs.sort(Comparator.comparingInt(ErrorItem::getLineNum));
        writeFile("error.txt", logs);
    }
}
