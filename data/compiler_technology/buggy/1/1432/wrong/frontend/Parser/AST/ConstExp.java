package frontend.Parser.AST;

public class ConstExp extends AstNode {

    public void parse() {
        AddExp addExp = new AddExp();
        addExp.parse();
        stringBuilder.append("<ConstExp>").append("\n");
    }
}
