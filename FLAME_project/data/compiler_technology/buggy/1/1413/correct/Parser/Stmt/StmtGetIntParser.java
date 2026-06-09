package Parser.Stmt;

import Lexer.Token;
import Lexer.TokenListIterator;
import Parser.ErrorP;
import Parser.ErrorPList;
import Parser.LVal;
import Parser.LValParser;

public class StmtGetIntParser {
    private TokenListIterator iterator;
    /* StmtGetint Attributes */
    private LVal lval = null;
    private Token eq = null; // '='
    private Token getint = null; // 'getint'
    private Token leftParent = null; // '('
    private Token rightParent = null; // ')'
    private Token semicn = null; // ';'
    private int errorLine;

    public StmtGetIntParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public StmtGetint parseStmtGetInt() {
        LValParser lvalParser = new LValParser(this.iterator);
        this.lval = lvalParser.LValParse();
        this.eq = this.iterator.readNextToken();
        this.getint = this.iterator.readNextToken();
        this.errorLine= getint.getLine();
        this.leftParent = this.iterator.readNextToken();
        Token next=iterator.readNextToken();
        if(next.getValue().equals(")"))
        {
            this.rightParent=next;
        }else {
            iterator.unReadToken(1);
            ErrorP errorP=new ErrorP("j",this.errorLine);
            ErrorPList errorPList=ErrorPList.getInstance();
            errorPList.addErrorP(errorP);
        }
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
        StmtGetint stmtGetint = new StmtGetint(this.lval, this.eq, this.getint,
                this.leftParent, this.rightParent, this.semicn);
        return stmtGetint;
    }
}
