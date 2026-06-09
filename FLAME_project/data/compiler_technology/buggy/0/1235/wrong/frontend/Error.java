package frontend;

public class Error {
    private String value;
    private String type;
    private int lineNum;
    public Error(String value, String type, int lineNum){
        this.value = value;
        this.type = type;
        this.lineNum = lineNum;
    }

    public String getValue(){
        return value;
    }

    public String getType(){
        return type;
    }

    public int getLineNum(){
        return lineNum;
    }

    public String writeString(){
        return lineNum + " " + type;
    }
}
