package frontend.Category;

public class Token {

    private final Category category;

    private final String content;

    private final int line;

    public Token(Category category,String content,int line) {
        this.category = category;
        this.content = content;
        this.line = line;
    }

    public Category GetCategory() {
        return category;
    }

    public String GetContent() {
        return content;
    }

    public int GetLine() {
        return line;
    }

    @Override
    public String toString() {
        return category.name() + " " + content;
    }
}
