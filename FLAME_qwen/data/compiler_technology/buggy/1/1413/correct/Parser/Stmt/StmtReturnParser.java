package Parser.Stmt;


import Lexer.Token;
import Lexer.TokenListIterator;
import Parser.ErrorP;
import Parser.ErrorPList;
import Parser.Exp.Exp;
import Parser.Exp.ExpParser;

public class StmtReturnParser {
    private TokenListIterator iterator;
    /* StmtPrint Attributes */
    private Token returnTk; // 'return'
    private Exp exp=null;
    private Token semicn; // ';'
    private StmtReturn stmtReturn = null;
    private int errorLine;

    public StmtReturnParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public StmtReturn stmtReturnParse() {
        this.returnTk = this.iterator.readNextToken();
        if (!this.returnTk.getType().equals("RETURNTK")) {
            System.out.println("EXPECT RETURNTK IN STMTRETURNPARSER");
        }
        this.errorLine=returnTk.getLine();
        Token next = this.iterator.readNextToken();
        if (!next.getType().equals("SEMICN")) {
            //this.iterator.unReadToken(1);
            if(next.getValue().equals("(")||next.getType().equals("IDENFR")||next.getType().equals("INTCON")||next.getType().equals("CHRCON")||next.getValue().equals("+")||next.getValue().equals("-")||next.getValue().equals("!"))
            {
                this.iterator.unReadToken(1);
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
            }else {
                iterator.unReadToken(1);
                ErrorP errorP=new ErrorP("i",this.errorLine);
                ErrorPList errorPList=ErrorPList.getInstance();
                errorPList.addErrorP(errorP);
            }

            stmtReturn = new StmtReturn(this.returnTk, this.exp, this.semicn);
        } else {
            this.semicn=next;
            stmtReturn = new StmtReturn(this.returnTk, this.semicn);
        }
        return stmtReturn;
    }
}
