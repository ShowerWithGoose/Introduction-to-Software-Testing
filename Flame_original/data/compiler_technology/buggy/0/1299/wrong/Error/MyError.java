package Error;

public class MyError {
    private char type;
    private int line;
    public MyError(char type, int line){
        this.type = type;
        this.line = line;
    }
    public String errorInformation(){
        return line + " " + type;
    }
}
