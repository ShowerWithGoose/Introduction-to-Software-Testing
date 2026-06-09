package frontend.parser.Exp;

import frontend.lexer.TokenList;
import frontend.parser.Exp.CombineExp.AddExp;

public class ConstExp {
    private AddExp addExp; //使用的 Ident 必须是常量
    private TokenList tokens;
    private int errorNum;
    private String nonTerminalName = "ConstExp";

    public ConstExp(TokenList tokens) {
        this.addExp = null;
        this.tokens = tokens;
        this.errorNum = 0;
    }

    public int parse() { //return error num
        addExp = new AddExp(tokens);
        errorNum += addExp.parse();
        return errorNum;
    }

    public String toSyntaxTree() {
        StringBuilder sb = new StringBuilder();
        sb.append(addExp.toSyntaxTree());
        sb.append('<').append(this.nonTerminalName).append('>').append('\n');
        return sb.toString();
    }
}
