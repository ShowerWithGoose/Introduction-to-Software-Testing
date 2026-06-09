package Parser.Stmt;

import Lexer.Token;
import Lexer.TokenListIterator;
import Parser.Exp.Exp;
import Parser.Exp.ExpParser;
import Parser.LVal;
import Parser.LValParser;

/**
 * @Description:
 * @date 2024/10/13
 */
public class ForStmtParser {
    private TokenListIterator iterator;
    private LVal lVal;
    private Token equal;
    private Exp exp;

    public ForStmtParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }
    public ForStmt forStmtParse()
    {
        LValParser lValParser=new LValParser(iterator);
        this.lVal=lValParser.LValParse();
        Token next=iterator.readNextToken();
        if(next.getValue().equals("="))
        {
            this.equal=next;
            ExpParser expParser=new ExpParser(iterator);
            this.exp=expParser.expParse();
        }
        return new ForStmt(lVal,equal,exp);
    }

}
