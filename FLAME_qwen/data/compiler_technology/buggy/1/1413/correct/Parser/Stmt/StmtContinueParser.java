package Parser.Stmt;

import Lexer.Token;
import Lexer.TokenListIterator;
import Parser.ErrorP;
import Parser.ErrorPList;

public class StmtContinueParser {
    private TokenListIterator iterator;
    /* StmtContinue Attributes */
    private Token continueTk; // 'continue'
    private Token semicn; // ';'
    private int errorLine;

    public StmtContinueParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public StmtContinue parseStmtContinue() {
        this.continueTk = this.iterator.readNextToken();
        if (!this.continueTk.getType().equals("CONTINUETK")) {
            System.out.println("EXPECT CONTINUETK IN STMTCONTINUEPARSER");
        }
        this.errorLine=this.continueTk.getLine();
        Token token=iterator.readNextToken();
        if(token.getValue().equals(";"))
        {
            this.semicn=token;
        }else {
            iterator.unReadToken(1);
            ErrorP errorP=new ErrorP("i",this.errorLine);
            ErrorPList errorPList=ErrorPList.getInstance();
            errorPList.addErrorP(errorP);
        }
        StmtContinue stmtContinue = new StmtContinue(this.continueTk, this.semicn);
        return stmtContinue;
    }
}
