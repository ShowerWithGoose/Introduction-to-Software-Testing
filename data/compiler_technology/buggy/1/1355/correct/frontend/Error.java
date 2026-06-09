package frontend;

public class Error implements Comparable<Error>{
    int line = 0;
    String type;
    public Error(int line, String type) {
        this.line = line;
        this.type = type;
    }
    @Override
    public int compareTo(Error o) {
        return this.line - o.line;
    }
}
