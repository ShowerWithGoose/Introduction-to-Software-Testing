package frontend.parser.declaration.constant.constinitval;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;
import frontend.parser.expression.ConstExp;
import frontend.parser.terminal.StringConst;

public class ConstInitVal implements Node {
    private final String name = "<ConstInitVal>";
    private ConstInitValIFace constInitValIFace;
    private TokenList tokenList;

    public ConstInitVal(TokenList tokenList) {
        this.tokenList = tokenList;
    }

    public void parseConstInitVal(){
        Token first = tokenList.seeAfterToken(0);
        if (first.getType().equals(TokenType.LBRACE)){//'{'
            ConstInitValMulti constInitValMulti = new ConstInitValMulti(tokenList);
            constInitValMulti.parseConstInitValMulti();
            this.constInitValIFace = constInitValMulti;
        } else if (first.getType().equals(TokenType.STRCON)){ // 字符串常量
            StringConst stringConst = new StringConst(tokenList);
            stringConst.parseStringConst();
            this.constInitValIFace = stringConst;
        } else {
            ConstExp constExp = new ConstExp(tokenList);
            constExp.parseConstExp();
            this.constInitValIFace = constExp;

        }
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(constInitValIFace.syntaxOutput());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
