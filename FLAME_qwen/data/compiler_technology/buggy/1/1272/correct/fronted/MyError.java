package fronted;

public class MyError {

    private int line;

    private char err;

    public MyError(int line,char err) {
        this.line = line;
        this.err = err;
    }

    public int getLine() {
        return line;
    }

    public char getErr() {
        return err;
    }

    @Override
    public String toString() {
        return line + " " + err + "\n";
    }
}
