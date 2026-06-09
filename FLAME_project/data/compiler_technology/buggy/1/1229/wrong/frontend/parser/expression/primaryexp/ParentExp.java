package frontend.parser.expression.primaryexp;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.expression.Exp;
import middle.error.Error;
import middle.error.ErrorTable;

public class ParentExp implements PrimaryExpIFace{
    private Token leftParent; // must be '('
    private Exp exp;
    private Token rightParent; // must be ')'

    private TokenList tokenList;

    public ParentExp(TokenList tokenList) {
        this.tokenList = tokenList;
    }

    public void parseParentExp(){
        this.leftParent = tokenList.getNextToken();
        this.exp = new Exp(tokenList);
        this.exp.parseExp();

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
    }
    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(leftParent.syntaxOutput());
        sb.append(exp.syntaxOutput());
        sb.append(rightParent.syntaxOutput());
        return sb.toString();
    }
}
