package frontend.parser.expression.primaryexp;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.expression.Exp;
import frontend.parser.terminal.Ident;
import middle.error.Error;
import middle.error.ErrorTable;

import java.util.ArrayList;

public class LVal implements PrimaryExpIFace{
    private final String name = "<LVal>";
    private Ident ident;
    private ArrayList<Token> leftBrackets;
    private ArrayList<Exp> exps;
    private ArrayList<Token> rightBrackets;
    //实际上不需要Arraylist 懒得改了
    private TokenList tokenList;

    public LVal(TokenList tokenList) {
        this.tokenList = tokenList;
        this.leftBrackets = new ArrayList<>();
        this.exps = new ArrayList<>();
        this.rightBrackets = new ArrayList<>();
    }

    public void parseLVal(){
        this.ident = new Ident(tokenList);
        this.ident.parseIdent();
        if (tokenList.seeAfterToken(0).getType().equals(TokenType.LBRACK)){
            this.leftBrackets.add(tokenList.getNextToken());
            Exp exp = new Exp(tokenList);
            exp.parseExp();
            this.exps.add(exp);


            if (tokenList.seeAfterToken(0).getType().equals(TokenType.RBRACK)){
                this.rightBrackets.add(tokenList.getNextToken());
            } else {
                //handle error k
                Token token1 = tokenList.seeAfterToken(-1);
                int lineNum = token1.getLineNum();
                middle.error.Error error = new Error(lineNum,"k");
                ErrorTable.addError(error);
                this.rightBrackets.add(new Token(TokenType.RBRACK,lineNum,"]"));
                //自己捏造个)放这，防止以后分析到这，再出错
            }
        }
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(ident.syntaxOutput());
        if (leftBrackets != null && exps != null && rightBrackets != null &&
                leftBrackets.size() == exps.size() && exps.size() == rightBrackets.size()) {
            int len = leftBrackets.size();
            for (int i = 0; i < len; i++) {
                sb.append(leftBrackets.get(i).syntaxOutput());
                sb.append(exps.get(i).syntaxOutput());
                sb.append(rightBrackets.get(i).syntaxOutput());
            }
        }
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
