package frontend.Parser.AST;

public class Character extends AstNode {
    public void parse() {
        append(1);
        if (print == 1) {
            stringBuilder.append("<Character>").append("\n");
        }
    }
}
