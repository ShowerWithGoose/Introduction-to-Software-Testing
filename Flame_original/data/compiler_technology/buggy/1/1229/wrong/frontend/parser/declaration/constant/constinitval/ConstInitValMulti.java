package frontend.parser.declaration.constant.constinitval;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.expression.ConstExp;

import java.util.ArrayList;

/**
 * ConstInitVal -> '{' [ <ConstExp> { ',' <ConstExp> } ] '}'
 * 无name输出,只是为了方便的中间产物
 */
public class ConstInitValMulti implements ConstInitValIFace{
    private Token leftBrace; // '{'
    private ConstExp first; // MAY exist,一定是ConstExp
    private ArrayList<Token> commas; // MAY exist
    private ArrayList<ConstExp> constExps; // MAY exist
    private Token rightBrace; // '}'

    private TokenList tokenList;

    public ConstInitValMulti(TokenList tokenList) {
        this.tokenList = tokenList;
        this.commas = new ArrayList<>();
        this.constExps = new ArrayList<>();
        first = null;
    }

    public void parseConstInitValMulti(){
        this.leftBrace = tokenList.getNextToken();
        Token token = tokenList.seeAfterToken(0);
        if (!token.getType().equals(TokenType.RBRACE)){
            ConstExp constExp = new ConstExp(tokenList);
            constExp.parseConstExp();
            this.first = constExp;
            token = tokenList.seeAfterToken(0);
            while (token.getType().equals(TokenType.COMMA)){
                this.commas.add(tokenList.getNextToken());
                ConstExp constExp1 = new ConstExp(tokenList);
                constExp1.parseConstExp();
                this.constExps.add(constExp1);
                token = tokenList.seeAfterToken(0);
            }
        }
        this.rightBrace = tokenList.getNextToken();
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.leftBrace.syntaxOutput());
        if (this.first != null) {
            sb.append(this.first.syntaxOutput());
            if (this.commas != null && this.constExps != null
                    && this.commas.size() == this.constExps.size()) {
                int len = this.commas.size();
                for (int i = 0; i < len; i++) {
                    sb.append(this.commas.get(i).syntaxOutput());
                    sb.append(this.constExps.get(i).syntaxOutput());
                }
            }
        }
        sb.append(this.rightBrace.syntaxOutput());
        return sb.toString();
    }

}
