package frontend.ErrorPart;

public class Error implements Comparable<Error>{
    private ErrorType type;
    private int line;
    public Error(ErrorType type,int line){
        this.type = type;
        this.line = line;
    }
    public ErrorType getType(){
        return type;
    }
    public int getLine() {
        return line;
    }

    @Override
    public int compareTo(Error o) {
        return Integer.compare(line,o.getLine());
    }
}
