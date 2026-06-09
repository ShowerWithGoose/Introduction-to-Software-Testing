public class Message {
    private Integer lineNum;
    private Type type;
    private String mess;

    public Message(Type type, String mess, Integer lineNum) {
        this.type = type;
        this.mess = mess;
        this.lineNum = lineNum;
    }

    public void setType(Type type) {
        this.type = type;
    }

    public Integer getLineNum() {
        return lineNum;
    }

    public String getMess() {
        return mess;
    }

    public Type getType() {
        return type;
    }

    public void setLineNum(Integer lineNumber) {
        this.lineNum = lineNumber;
    }

    public void setMess(String mess) {
        this.mess = mess;
    }
}
