package frontend.Parser.Declaration;

import frontend.Lexer.Token;
import frontend.Parser.ASTNode;
import frontend.Parser.Expression.ConstExp;

public class VarDef implements ASTNode {
    // 普通变量 一维数组
    // 可以不初始化
    private Ident ident;
    private Token lBrackToken;      // 可选
    private ConstExp constExp;      // 可选
    private Token rBrackToken;      // 可选
    private Token assignToken;      // 可选
    private InitVal initVal;        // 可选

    public VarDef(Ident ident,
                  Token lBrackToken,
                  ConstExp constExp,
                  Token rBrackToken,
                  Token assignToken,
                  InitVal initVal) {
        this.ident = ident;
        this.lBrackToken = lBrackToken;
        this.constExp = constExp;
        this.rBrackToken = rBrackToken;
        this.assignToken = assignToken;
        this.initVal = initVal;
    }

    @Override
    public String printString() {
        StringBuilder sb = new StringBuilder();
        sb.append(ident.printString());
        if (lBrackToken != null) {
            sb.append(lBrackToken);
            sb.append(constExp.printString());
            if (rBrackToken != null) {
                sb.append(rBrackToken);
            }
        }
        if (assignToken != null) {
            sb.append(assignToken);
            sb.append(initVal.printString());
        }
        sb.append("<VarDef>\n");
        return sb.toString();
    }
}
