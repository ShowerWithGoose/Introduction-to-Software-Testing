package parse;

public class Token {
    private String type;
    private int linenumber;
    private String content;
    public Token(String type,int num,String content){
        this.type = type;
        this.linenumber = num;
        this.content = content;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public int getLinenumber() {
        return linenumber;
    }

    public void setLinenumber(int linenumber) {
        this.linenumber = linenumber;
    }

    public String getContent() {
        return content;
    }

    public void setContent(String content) {
        this.content = content;
    }

    public String printout() {
        StringBuilder sb = new StringBuilder();
        sb.append(type + " " + content + "\n");
        return sb.toString();
    }
}
