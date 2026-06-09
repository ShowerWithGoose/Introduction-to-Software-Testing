package frontend.parser.statement.stmt;

import frontend.error.Error;
import frontend.error.ErrorSet;
import frontend.error.ErrorType;
import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.Exp;
import frontend.parser.expression.ExpParser;
import frontend.parser.terminal.StringConst;

import java.util.ArrayList;

public class StmtPrintParser {
    private TokenListIterator iterator;
    /* StmtPrint Attributes */
    private Token printf; // 'printf'
    private Token leftParent; // '('
    private StringConst stringConst;
    private ArrayList<Token> commmas = new ArrayList<>(); // ','
    private ArrayList<Exp> exps = new ArrayList<>();
    private Token rightParent; // ')'
    private Token semicn; // ';'

    public StmtPrintParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public StmtPrint parseStmtPrint() {
        this.commmas = new ArrayList<>();
        this.exps = new ArrayList<>();
        this.printf = this.iterator.next();
        if (!this.printf.getTokenType().equals(TokenType.PRINTFTK)) {
            System.out.println("EXPEXT PRINTF IN STMTPRINTFPARSER");
        }
        this.leftParent = this.iterator.next();
        if (!this.leftParent.getTokenType().equals(TokenType.LPARENT)) {
            System.out.println("EXPECT LPARENT IN STMTPRINTFPARSER");
        }
        this.stringConst = new StringConst(this.iterator.next());
        Token token = this.iterator.next();
        while (token.getTokenType().equals(TokenType.COMMA)) {
            this.commmas.add(token);
            ExpParser expParser = new ExpParser(this.iterator);
            this.exps.add(expParser.parseExp());
            token = this.iterator.next();
        }
        this.rightParent = token;
        if (!this.rightParent.getTokenType().equals(TokenType.RPARENT)) {
            System.out.println("EXPEXT RPARENT IN STMTPRINTFPARSER");
            handleJError();
        }
        this.semicn = this.iterator.next();
        if (!this.semicn.getTokenType().equals(TokenType.SEMICN)) {
            System.out.println("ERROR : EXPEXT SEMICN");
            handleIError();
        }
        StmtPrint stmtPrint = new StmtPrint(this.printf, this.leftParent,
                this.stringConst, this.commmas, this.exps, this.rightParent, this.semicn);
        return stmtPrint;
    }

    /**
     * i error
     * missing ';'
     */
    private void handleIError() {
        iterator.unRead(2);
        ErrorSet.getInstance().addError(new Error(ErrorType.MISSING_SEMICN, iterator.next().getLine()));
        this.semicn = null;
    }

    /**
     * j error
     * missing ')'
     */
    private void handleJError() {
        iterator.unRead(2);
        ErrorSet.getInstance().addError(new Error(ErrorType.MISSING_RPARENT, iterator.next().getLine()));
        this.rightParent = null;
    }
}
