package exceptions;

public class FatalErrorException extends Exception {
    private final int line;
    private final String errMsg;

    public FatalErrorException(int line, String errMsg) {
        this.line = line;
        this.errMsg = errMsg;
    }

    @Override
    public String toString() {
        return line + " " + errMsg;
    }
}
