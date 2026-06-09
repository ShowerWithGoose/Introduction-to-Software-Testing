package frontend.error;

import java.io.BufferedWriter;

public class MyError{
    private int line;
    private ErrorType type;
    private BufferedWriter writer;

    public MyError(int line, ErrorType type) {
        this.line = line;
        this.type = type;
    }

    public void printError() {

    }

    @Override
    public String toString() {
        return line + " " + type;
    }


}
