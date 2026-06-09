package output;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Comparator;

public class ErrorMessage implements Comparable<ErrorMessage> {
    private final int lineNo;
    private final String str;

    public ErrorMessage(int lineNo, String str) {
        this.lineNo = lineNo;
        this.str = str;
    }

    @Override
    public String toString() {
        return lineNo + " " + str + '\n';
    }


    @Override
    public int compareTo(ErrorMessage o) {
        return this.lineNo - o.lineNo;
    }
}
