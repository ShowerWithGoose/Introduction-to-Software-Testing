package frontend.Parser.AST;


public class Exp extends AstNode{

    public void parse() {
        AddExp addExp = new AddExp();
        addExp.parse();
        if (print == 1) {
            stringBuilder.append("<Exp>").append("\n");
        }
    }
}
