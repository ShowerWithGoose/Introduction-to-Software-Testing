package Parser.Stmt;

import Lexer.Token;
import Lexer.TokenListIterator;
import Parser.ErrorP;
import Parser.ErrorPList;
import Parser.Exp.Exp;
import Parser.Exp.ExpParser;

public class StmtExpParser {
    private TokenListIterator iterator;
    /* StmtExp Attributes */
    private Exp exp = null;
    private Token semicn = null; // ';'
    private int errorLine;

    public StmtExpParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public StmtExp parseStmtExp() {
        Token first=iterator.readNextToken();
        iterator.unReadToken(1);
        this.errorLine= first.getLine();
        ExpParser expParser = new ExpParser(this.iterator);
        this.exp = expParser.expParse();
        Token token=iterator.readNextToken();
        if(token.getValue().equals(";"))
        {
            this.semicn=token;
        }else {
            iterator.unReadToken(1);
            ErrorP errorP=new ErrorP("i",this.errorLine);
            ErrorPList errorPList=ErrorPList.getInstance();
            errorPList.addErrorP(errorP);
            System.out.println("ç™«"+token.getValue());
        }
        StmtExp stmtExp = new StmtExp(this.exp, this.semicn);
        return stmtExp;
    }
}
