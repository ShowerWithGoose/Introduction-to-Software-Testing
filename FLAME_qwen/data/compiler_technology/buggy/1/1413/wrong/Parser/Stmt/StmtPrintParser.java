package Parser.Stmt;

import Lexer.Token;
import Lexer.TokenListIterator;
import Parser.ErrorP;
import Parser.ErrorPList;
import Parser.Exp.Exp;
import Parser.Exp.ExpParser;

import java.util.ArrayList;

public class StmtPrintParser {
    private TokenListIterator iterator;
    /* StmtPrint Attributes */
    private Token printf; // 'printf'
    private Token leftParent; // '('
    private Token stringConst;
    private ArrayList<Token> commmas = new ArrayList<>(); // ','
    private ArrayList<Exp> exps = new ArrayList<>();
    private Token rightParent; // ')'
    private Token semicn; // ';'
    private int errorLine;

    public StmtPrintParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public StmtPrint parseStmtPrint() {
        this.commmas = new ArrayList<>();
        this.exps = new ArrayList<>();
        Token first = this.iterator.readNextToken();
        if (!first.getType().equals("PRINTFTK")) {
            System.out.println("EXPEXT PRINTF IN STMTPRINTFPARSER");
        }
        this.errorLine= first.getLine();
        this.printf=first;
        Token next = this.iterator.readNextToken();
        if(next.getValue().equals("("))
        {
            this.leftParent=next;
            next=iterator.readNextToken();
            if(next.getType().equals("STRCON"))
            {
                this.stringConst=next;
                next=iterator.readNextToken();
                while(next.getValue().equals(","))
                {
                    this.commmas.add(next);
                    ExpParser expParser = new ExpParser(this.iterator);
                    this.exps.add(expParser.expParse());
                    next = this.iterator.readNextToken();
                }
                if(next.getValue().equals(")"))
                {
                    this.rightParent=next;
                    next=iterator.readNextToken();
                    if(next.getValue().equals(";"))
                    {
                        this.semicn=next;
                    }else {
                        iterator.unReadToken(1);
                        ErrorP errorP=new ErrorP("i",this.errorLine);
                        ErrorPList errorPList=ErrorPList.getInstance();
                        errorPList.addErrorP(errorP);
                    }
                }else {
                    iterator.unReadToken(1);
                    ErrorP errorP=new ErrorP("j",this.errorLine);
                    ErrorPList errorPList=ErrorPList.getInstance();
                    errorPList.addErrorP(errorP);
                }
            }
        }
        else
        {
            System.out.println("stmt print 没有左小括号");
        }
        StmtPrint stmtPrint = new StmtPrint(this.printf, this.leftParent, this.stringConst, this.commmas, this.exps, this.rightParent, this.semicn);
        return stmtPrint;

    }
}
