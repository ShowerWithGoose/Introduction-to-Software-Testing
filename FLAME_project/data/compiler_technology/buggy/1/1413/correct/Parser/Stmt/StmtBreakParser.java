package Parser.Stmt;

import Lexer.Token;
import Lexer.TokenListIterator;
import Parser.ErrorP;
import Parser.ErrorPList;

public class StmtBreakParser {
    private TokenListIterator iterator;
    /* StmtBreak Attributes */
    private Token breakTk; // 'break'
    private Token semicn; // ';'
    private int errorLine;

    public StmtBreakParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public StmtBreak parseStmtBreak() {
        this.breakTk = this.iterator.readNextToken();
        if (!this.breakTk.getType().equals("BREAKTK")) {
            System.out.println("EXPECT BREAKTK IN STMTBREAKPARSER");
        }
        this.errorLine=this.breakTk.getLine();
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
        StmtBreak stmtBreak = new StmtBreak(this.breakTk, this.semicn);
        return stmtBreak;
    }
}
