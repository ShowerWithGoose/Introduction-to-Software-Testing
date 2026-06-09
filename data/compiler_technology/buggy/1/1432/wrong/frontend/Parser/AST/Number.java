package frontend.Parser.AST;

public class Number extends AstNode {
    public void parse() {
        append(1);
        if (print == 1) {
            stringBuilder.append("<Number>").append("\n");
        }
    }
}
