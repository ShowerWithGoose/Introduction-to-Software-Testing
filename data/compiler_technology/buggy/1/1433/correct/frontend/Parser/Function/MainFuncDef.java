package frontend.Parser.Function;

import frontend.Lexer.Token;
import frontend.Parser.ASTNode;
import frontend.Parser.Statement.Block;

public class MainFuncDef implements ASTNode {
    private Token intToken;
    private Token mainToken;
    private Token lparentToken;
    private Token rparentToken;
    private Block block;

    public MainFuncDef(Token intToken, 
                    Token mainToken, 
                    Token lparentToken, 
                    Token rparentToken, 
                    Block block) {
        this.intToken = intToken;
        this.mainToken = mainToken;
        this.lparentToken = lparentToken;
        this.rparentToken = rparentToken;
        this.block = block;
    }

    @Override
    public String printString() {
        StringBuilder sb = new StringBuilder();
        sb.append(intToken);
        sb.append(mainToken);
        sb.append(lparentToken);
        if (rparentToken != null) {
            sb.append(rparentToken);
        }
        sb.append(block.printString());
        sb.append("<MainFuncDef>\n");
        return sb.toString();
    }
}
