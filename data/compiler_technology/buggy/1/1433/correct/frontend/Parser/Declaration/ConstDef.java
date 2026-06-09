package frontend.Parser.Declaration;

import frontend.Lexer.Token;
import frontend.Parser.ASTNode;
import frontend.Parser.Expression.ConstExp;

public class ConstDef implements ASTNode {
    // 普通变量 一维数组
    // 必须初始化
    private Ident ident;
    private Token lbrackToken;
    private ConstExp constExp;
    private Token rbrackToken;
    private Token assignToken;
    private ConstInitVal constInitVal;

    public ConstDef(Ident ident,
                    Token lbrackToken,
                    ConstExp constExp,
                    Token rbrackToken,
                    Token assignToken,
                    ConstInitVal constInitVal) {
        this.ident = ident;
        this.lbrackToken = lbrackToken;
        this.constExp = constExp;
        this.rbrackToken = rbrackToken;
        this.assignToken = assignToken;
        this.constInitVal = constInitVal;
    }

    @Override
    public String printString() {
        StringBuilder sb = new StringBuilder();
        sb.append(ident.printString());
        if (lbrackToken != null) {
            sb.append(lbrackToken);
            sb.append(constExp.printString());
            if (rbrackToken != null) {
                sb.append(rbrackToken);
            }
        }
        sb.append(assignToken);
        sb.append(constInitVal.printString());
        sb.append("<" + "ConstDef" + ">\n");
        return sb.toString();
    }
}
