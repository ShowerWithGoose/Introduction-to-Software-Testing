package frontend.parser.statement.stmt;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.expression.Exp;
import frontend.parser.terminal.StringConst;
import middle.error.Error;
import middle.error.ErrorTable;

import java.util.ArrayList;

public class StmtPrintf implements StmtIFace{
    private Token printf; // 'printf'
    private Token leftParent; // '('
    private StringConst formatString;
    private ArrayList<Token> commmas; // ',' MAY exist
    private ArrayList<Exp> exps;
    private Token rightParent; // ')'
    private Token semicn; // ';'


    private TokenList tokenList;

    public StmtPrintf(TokenList tokenList) {

        this.tokenList = tokenList;
        this.commmas = new ArrayList<>();
        this.exps = new ArrayList<>();
    }

    public void parseStmtPrintf(){
        this.printf = tokenList.getNextToken();
        this.leftParent = tokenList.getNextToken();
        this.formatString = new StringConst(tokenList);
        this.formatString.parseStringConst();
        while (tokenList.seeAfterToken(0).getType().equals(TokenType.COMMA)){
            this.commmas.add(tokenList.getNextToken());
            Exp exp = new Exp(tokenList);
            exp.parseExp();
            this.exps.add(exp);
        }

        if (tokenList.seeAfterToken(0).getType().equals(TokenType.RPARENT)){
            this.rightParent = tokenList.getNextToken();
        } else {
            //handle error j
            Token token1 = tokenList.seeAfterToken(-1);
            int lineNum = token1.getLineNum();
            middle.error.Error error = new Error(lineNum,"j");
            ErrorTable.addError(error);
            this.rightParent = new Token(TokenType.RPARENT,lineNum,")");
            //自己捏造个)放这，防止以后分析到这，再出错
        }


        if (tokenList.seeAfterToken(0).getType().equals(TokenType.SEMICN)){
            this.semicn = tokenList.getNextToken();
        } else {
            //handle error i
            Token token = tokenList.seeAfterToken(-1);
            int lineNum = token.getLineNum();
            middle.error.Error error = new Error(lineNum,"i");
            ErrorTable.addError(error);
            this.semicn = new Token(TokenType.SEMICN,lineNum,";");
            //自己捏造个；放这，防止以后分析到这，再出错
        }
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.printf.syntaxOutput());
        sb.append(this.leftParent.syntaxOutput());
        sb.append(this.formatString.syntaxOutput());
        if (this.commmas != null && this.exps != null &&
                this.commmas.size() == this.exps.size()) {
            int len = this.commmas.size();
            for (int i = 0; i < len; i++) {
                sb.append(this.commmas.get(i).syntaxOutput());
                sb.append(this.exps.get(i).syntaxOutput());
            }
        }
        sb.append(this.rightParent.syntaxOutput());
        sb.append(this.semicn.syntaxOutput());
        return sb.toString();
    }
}
