package lexical_analysis;

public class Token {
    private String type;
    private String content;
    private int line;

    public Token(String type, String content, int line){
        this.type = type;
        this.content = content;
        this.line = line;
    }

    public String getType(){ return type; }
    public String getContent(){ return content; }
    public int getLine(){ return line; }
    public String tokenInformation(){
        return this.type + " " + this.content;
    }
}
