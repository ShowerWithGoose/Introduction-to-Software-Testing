public class Error {

    private final Type type;
    private final int line;
    private String content;


    public enum Type{
        ERROR_A,ERROR_I,ERROR_J,ERROR_K
    }

    public Error(Type type,int line,String content) {
        this.type = type;
        this.line = line;
        this.content = content;
    }

    public int getLine() {
        return line;
    }

    public String getContent() {
        return content;
    }
}

