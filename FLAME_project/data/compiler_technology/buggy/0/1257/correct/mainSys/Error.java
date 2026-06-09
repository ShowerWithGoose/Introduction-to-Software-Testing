package mainSys;

public class Error {
    char type;
    int line;
    // toString
    public String toString() {
        return line +" " + type;
    }

    public Error(char type, int line) {
        this.type = type;
        this.line = line;
    }
}
