package Parser.Stmt;

import Lexer.Token;
import Lexer.TokenListIterator;
import Parser.ErrorP;
import Parser.ErrorPList;
import Parser.Exp.Exp;
import Parser.Exp.ExpParser;
import Parser.LVal;
import Parser.LValParser;

public class StmtAssignParser {
    private TokenListIterator iterator;
    /* StmtAssign Attributes */
    private LVal lval = null;
    private Token eq; // '='
    private Exp exp;
    private Token semicn; // ';'
    private int errorLine;

    public StmtAssignParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public StmtAssign parseStmtAssign() {
        LValParser lvalParser = new LValParser(this.iterator);
        this.lval = lvalParser.LValParse();
        Token next=iterator.readNextToken();
        if (!next.getType().equals("ASSIGN")) {
            System.out.println("EXPECT = HERE"+next.getValue()+next.getLine());
        }else {
            this.eq=next;
            this.errorLine=next.getLine();
        }
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
        }
        StmtAssign stmtAssign = new StmtAssign(this.lval, this.eq, this.exp, this.semicn);
        return stmtAssign;
    }
}
