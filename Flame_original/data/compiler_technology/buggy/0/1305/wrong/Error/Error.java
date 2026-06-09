package Error;

public class Error {
    public int line;
    public char type;
    public Error(int line, char type){
        this.line = line;
        this.type = type;
    }
    public String toString() {
        return line + " " + type + "\n";
    }
}
