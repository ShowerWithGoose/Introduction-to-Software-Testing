package frontend.Parser.AST;

public class UnaryOp extends AstNode {
    public void parse() {
        append(1);
        if (print == 1) {
            stringBuilder.append("<UnaryOp>").append("\n");
        }
    }
}
