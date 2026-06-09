package frontend.parser.declaration.variable.initval;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;
import frontend.parser.declaration.constant.constinitval.ConstInitValMulti;
import frontend.parser.expression.ConstExp;
import frontend.parser.expression.Exp;
import frontend.parser.terminal.StringConst;

public class InitVal implements Node {
    private final String name = "<InitVal>";
    private TokenList tokenList;
    private InitValIFace initValIFace;

    public InitVal(TokenList tokenList) {
        this.tokenList = tokenList;
    }

    public void parseInitVal(){
        Token first = tokenList.seeAfterToken(0);
        if (first.getType().equals(TokenType.LBRACE)){//'{'
            InitVals initVals = new InitVals(tokenList);
            initVals.parseInitVals();
            this.initValIFace = initVals;
        } else if (first.getType().equals(TokenType.STRCON)){ // 字符串常量
            StringConst stringConst = new StringConst(tokenList);
            stringConst.parseStringConst();
            this.initValIFace = stringConst;
        } else {
            Exp exp = new Exp(tokenList);
            exp.parseExp();
            this.initValIFace = exp;
        }
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.initValIFace.syntaxOutput());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
