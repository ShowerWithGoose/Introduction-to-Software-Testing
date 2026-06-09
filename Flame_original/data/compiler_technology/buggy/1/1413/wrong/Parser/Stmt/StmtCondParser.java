package Parser.Stmt;

import Lexer.Token;
import Lexer.TokenListIterator;
import Parser.ErrorP;
import Parser.ErrorPList;
import Parser.Exp.Cond;
import Parser.Exp.CondParser;

public class StmtCondParser {
    private TokenListIterator iterator;
    /* StmtCond Attributes */
    private Token ifTK = null; // 'if'
    private Token leftParent = null; // '('
    private Cond cond = null;
    private Token rightParent = null; // ')'
    private Stmt ifStmt = null;
    private Token elseTk = null; // MAY exist 'else'
    private Stmt elseStmt = null; // MAY exist else statement
    private StmtCond stmtCond = null;
    private int errorLine;

    public StmtCondParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public StmtCond parseStmtCond() {
        this.ifTK = this.iterator.readNextToken();
        if (!this.ifTK.getValue().equals("if")) {
            System.out.println("EXPECT IFTK IN STMTCONDPARSER");
        }
        this.errorLine=ifTK.getLine();
        this.leftParent = this.iterator.readNextToken();
        CondParser condParser = new CondParser(this.iterator);
        this.cond = condParser.parseCond();
        Token next=iterator.readNextToken();
        if (next.getType().equals("RPARENT")) {
            this.rightParent=next;
            StmtParser stmtParser = new StmtParser(this.iterator);
            this.ifStmt = stmtParser.parseStmt();
            next = iterator.readNextToken();
            if (next.getType().equals("ELSETK")) {
                //System.out.println("乌拉"+next.getLine());
                this.elseTk=next;
                this.elseStmt = stmtParser.parseStmt();
                this.stmtCond = new StmtCond(this.ifTK, this.leftParent,
                        this.cond, this.rightParent, this.ifStmt, this.elseTk, this.elseStmt);
            } else {
                this.iterator.unReadToken(1);
                this.stmtCond = new StmtCond(this.ifTK, this.leftParent,
                        this.cond, this.rightParent, this.ifStmt);
            }
        }else {
            iterator.unReadToken(1);
            ErrorP errorP=new ErrorP("j",this.errorLine);
            ErrorPList errorPList=ErrorPList.getInstance();
            errorPList.addErrorP(errorP);
        }
        return this.stmtCond;
    }
}
