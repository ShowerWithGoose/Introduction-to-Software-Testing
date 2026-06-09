package frontend.Parser.AST;

public class ForStmt extends AstNode {

    public void parse() {
        LVal lVal = new LVal();
        lVal.parse();
        append(1);
        Exp exp = new Exp();
        exp.parse();
        stringBuilder.append("<ForStmt>").append("\n");
    }
}
