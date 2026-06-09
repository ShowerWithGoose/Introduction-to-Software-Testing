package frontend.Parser.AST;

public class Cond extends AstNode{
    public void parse() {
        LOrExp lorExp = new LOrExp();
        lorExp.parse();
        stringBuilder.append("<Cond>").append("\n");
    }
}
