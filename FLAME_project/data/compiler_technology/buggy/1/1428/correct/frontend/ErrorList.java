package frontend;

import java.util.ArrayList;
import java.util.TreeMap;

public class ErrorList {
    private TreeMap<Integer, String> errors;

    public ErrorList() {
        this.errors = new TreeMap<>();
    }

    public void addError(int lineNum, String errorType) {
        this.errors.put(lineNum, errorType);
    }

    public String toString() {
        String string = "";
        for (Integer line : this.errors.keySet()) {
            string += line + " " + this.errors.get(line) + "\n";
        }
        return string;
    }
}
