package frontend;

public class LexerException{
    private final int line;
    private final char exceptionType;
    public LexerException(int line, char exceptionType){
        this.line = line;
        this.exceptionType = exceptionType;
    }
    @Override
    public String toString() {
        return line+" "+exceptionType;
    }
}
