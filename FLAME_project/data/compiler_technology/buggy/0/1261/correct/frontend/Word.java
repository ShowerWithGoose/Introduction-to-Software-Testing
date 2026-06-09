package frontend;

public class Word {
    private WordType type;
    private String name;
    private int lineNum;
    public Word(WordType type,String name,int lineNum) {
        this.type = type;
        this.name = name;
        this.lineNum = lineNum;
    }
    public WordType getType() {
        return type;
    }
    public String getName() {
        return name;
    }
}
