package frontend.Parser.AST;

public class MainFuncDef extends AstNode{

    public void parse() {
        append(3);
        j_error();
        Block block = new Block();
        block.parse();
        stringBuilder.append("<MainFuncDef>").append("\n");
    }
}
