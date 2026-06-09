package mainSys;

public class Error {
    char type;
    int line;
    // toString
    public String toString() {
        return type + " " + line;
    }

    public Error(char type, int line) {
        this.type = type;
        this.line = line;
    }
}
