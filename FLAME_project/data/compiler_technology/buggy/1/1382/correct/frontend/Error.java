package frontend;

import java.io.FileWriter;
import java.io.IOException;

public class Error {
    private final int lineNum;
    private final char type;

    public Error(int lineNum, char type) {
        this.lineNum = lineNum;
        this.type = type;
    }

    public int getLineNum() {
        return lineNum;
    }

    public void toPrint() {
        try {
            FileWriter fw = new FileWriter("error.txt", true);
            fw.write(lineNum + " " + type +"\n");
            fw.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
