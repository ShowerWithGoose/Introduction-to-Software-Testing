package frontend.ParserPart.decl.variable.varinitval;

import frontend.Factor;
import frontend.ParserPart.expr.Exp;
import frontend.ParserPart.term.StringConst;
import frontend.TokenPart.TokenList;
import frontend.TokenPart.TokenType;

public class InitVal implements Factor {
    private String name = "<InitVal>";
    private TokenList tokenList;
    private InitValInterface initValInterface;

    public InitVal(TokenList tokenList){
        this.tokenList = tokenList;
        initValInterface = null;
    }
    public void parseInitVal(){
        if (tokenList.peek().getType().equals(TokenType.STRCON)){
            //如果是stringconst情况
            StringConst stringConst = new StringConst(tokenList);
            stringConst.parseStringConst();
            initValInterface = stringConst;
        } else if (tokenList.peek().getType().equals(TokenType.LBRACE)) {
            //如果是左{开头情况
            InitValMul initValMul = new InitValMul(tokenList);
            initValMul.parseInitValMul();
            initValInterface = initValMul;
        }else {
            //第一种情况
            Exp exp = new Exp(tokenList);
            exp.parseExp();
            initValInterface = exp;
        }
    }
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(initValInterface.toString());
        sb.append(name);
        sb.append("\n");
        return sb.toString();
    }
}
