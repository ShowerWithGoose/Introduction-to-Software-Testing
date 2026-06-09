package frontend.parser.declaration.variable.initval;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.expression.ConstExp;
import frontend.parser.expression.Exp;

import java.util.ArrayList;

public class InitVals implements InitValIFace{
    private Token leftBrace;
    private Exp first; // may not exist
    private ArrayList<Token> commas;
    private ArrayList<Exp> exps;
    private Token rightBrace;

    private TokenList tokenList;

    public InitVals(TokenList tokenList){
        this.tokenList = tokenList;
        this.commas = new ArrayList<>();
        this.exps = new ArrayList<>();
        first = null;
    }

    public void parseInitVals(){
        this.leftBrace = tokenList.getNextToken();
        Token token = tokenList.seeAfterToken(0);
        if (!token.getType().equals(TokenType.RBRACE)){
            Exp exp = new Exp(tokenList);
            exp.parseExp();
            this.first = exp;
            token = tokenList.seeAfterToken(0);
            while (token.getType().equals(TokenType.COMMA)){
                this.commas.add(tokenList.getNextToken());
                Exp exp1 = new Exp(tokenList);
                exp1.parseExp();
                this.exps.add(exp1);
                token = tokenList.seeAfterToken(0);
            }
        }
        this.rightBrace = tokenList.getNextToken();
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.leftBrace.syntaxOutput());
        if (first != null) {
            sb.append(this.first.syntaxOutput());
            if (this.commas != null && this.exps != null &&
                    this.commas.size() == this.exps.size()) {
                int len = this.commas.size();
                for (int i = 0; i < len; i++) {
                    sb.append(this.commas.get(i).syntaxOutput());
                    sb.append(this.exps.get(i).syntaxOutput());
                }
            }
        }
        sb.append(this.rightBrace.syntaxOutput());
        return sb.toString();
    }
}
