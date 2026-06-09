package frontend.parser.statement;

import frontend.error.Error;
import frontend.error.ErrorList;
import frontend.lexer.Token;
import frontend.lexer.TokenIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.Exp;
import frontend.parser.expression.ExpParser;
import frontend.parser.init.StringConst;

import java.util.ArrayList;

public class PrintfStmtParser {
    private TokenIterator iterator;
    private Token printfTk;
    private Token leftParent;
    private StringConst strConst;
    private ArrayList<Token> commas = new ArrayList<>();
    private ArrayList<Exp> exps = new ArrayList<>();
    private Token rightParent;
    private Token semicn;

    public PrintfStmtParser(TokenIterator iterator) {
        this.iterator = iterator;
    }

    public PrintfStmt parsePrintfStmt() {
        // 'printf''('StringConst {','Exp}')'';'
        printfTk = iterator.getNextToken();
        leftParent = iterator.getNextToken();
        strConst = new StringConst(iterator.getNextToken());
        Token t1 = iterator.getNextToken();
        while (t1.getType() == TokenType.COMMA) {
            commas.add(t1);
            ExpParser parser = new ExpParser(iterator);
            exps.add(parser.parseExp());
            t1 = iterator.getNextToken();
        }
        if (t1.getType() != TokenType.RPARENT) {
            //缺少右括号
            iterator.ungetToken(2);
            Token t2 = iterator.getNextToken();
            Error error = new Error(t2.getLineNum(), "j");
            ErrorList.addErrorList(error);
            rightParent = null;
        } else {
            rightParent = t1;
        }
        Token t3 = iterator.getNextToken();
        if (t3.getType() != TokenType.SEMICN) {
            iterator.ungetToken(2);
            Token t4 = iterator.getNextToken();
            Error error = new Error(t4.getLineNum(), "i");
            ErrorList.addErrorList(error);
            semicn = null;
        } else {
            semicn = t3;
        }
        return new PrintfStmt(printfTk, leftParent, strConst, commas, exps, rightParent, semicn);
    }
}
