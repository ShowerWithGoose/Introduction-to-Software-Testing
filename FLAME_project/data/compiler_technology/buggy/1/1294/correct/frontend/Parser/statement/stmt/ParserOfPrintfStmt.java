package frontend.Parser.statement.stmt;

import frontend.Error;
import frontend.Lexer.Token;
import frontend.Lexer.TokenListManager;
import frontend.Lexer.TokenType;
import frontend.MyErrorType;
import frontend.Parser.expression.Exp;
import frontend.Parser.expression.ParserOfExp;
import frontend.Parser.terminal.StringConst;

import java.util.ArrayList;

public class ParserOfPrintfStmt {
    private TokenListManager tokenListManager;
    private Token printfTk;
    private Token lParent;
    private StringConst stringConst;
    private ArrayList<Token> commas;
    private ArrayList<Exp> exps;
    private Token rParent;
    private Token semicn;
    private ArrayList<Error> errors;

    public ParserOfPrintfStmt(TokenListManager tokenListManager) {
        this.tokenListManager = tokenListManager;
    }

    public PrintfStmt parsePrintfStmt() {
        this.commas = new ArrayList<>();
        this.exps = new ArrayList<>();
        this.errors = new ArrayList<>();
        Token token = tokenListManager.getTokenAndMove();
        if (token.getTokenType().equals(TokenType.PRINTFTK)) {
            this.printfTk = token;
        } else {
            System.out.println("not printf Token in printfStmt");
        }
        token = tokenListManager.getTokenAndMove();
        if (token.getTokenType().equals(TokenType.LPARENT)) {
            this.lParent = token;
        } else {
            System.out.println("not LPARENT Token in printfStmt");
        }
        token = tokenListManager.getTokenAndMove();
        this.stringConst = new StringConst(token);
        Token first = tokenListManager.getTokenAndMove();
        while (first.getTokenType().equals(TokenType.COMMA)) {
            this.commas.add(first);
            ParserOfExp parser = new ParserOfExp(tokenListManager);
            Exp exp = parser.parseExp();
            this.errors.addAll(parser.getErrors());
            this.exps.add(exp);
            first = tokenListManager.getTokenAndMove();
        }
        if (first.getTokenType().equals(TokenType.RPARENT)) {
            this.rParent = first;
        } else {
            tokenListManager.lookBackToken(2);
            token = tokenListManager.getTokenAndMove();
            Error error = new Error(token.getLineNo(), MyErrorType.j);
            this.errors.add(error);
            System.out.println("not RPARENT Token in printfStmt");
        }
        token = tokenListManager.getTokenAndMove();
        if (token.getTokenType().equals(TokenType.SEMICN)) {
            this.semicn = token;
        } else {
            tokenListManager.lookBackToken(2);
            token = tokenListManager.getTokenAndMove();
            Error error = new Error(token.getLineNo(), MyErrorType.i);
            this.errors.add(error);
            System.out.println("not SEMICN Token in printfStmt");
        }
        return new PrintfStmt(this.printfTk, this.lParent, this.stringConst,
                this.commas, this.exps, this.rParent, this.semicn);
    }

    public ArrayList<Error> getErrors() {
        return errors;
    }
}
