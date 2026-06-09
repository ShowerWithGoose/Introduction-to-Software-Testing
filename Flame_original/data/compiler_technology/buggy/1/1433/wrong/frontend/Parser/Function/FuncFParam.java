package frontend.Parser.Function;

import frontend.Lexer.Token;
import frontend.Parser.ASTNode;
import frontend.Parser.Terminators.BType;
import frontend.Parser.Declaration.Ident;

public class FuncFParam implements ASTNode {
    private BType bType;
    private Ident ident;
    private Token lbrackToken;    // 可选
    private Token rbrackToken;    // 可选

    public FuncFParam(BType bType, Ident ident, Token lbrackToken, Token rbrackToken) {
        this.bType = bType;
        this.ident = ident;
        this.lbrackToken = lbrackToken;
        this.rbrackToken = rbrackToken;
    }

    @Override
    public String printString() {
        StringBuilder sb = new StringBuilder();
        sb.append(bType.printString());
        sb.append(ident.printString());
        if (lbrackToken != null) {
            sb.append(lbrackToken);
            if (rbrackToken != null) {
                sb.append(rbrackToken);
            }
        }
        sb.append("<" + "FuncFParam" + ">\n");
        return sb.toString();
    }
}
