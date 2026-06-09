package frontend.Parser.Stmt;

import frontend.Error;
import frontend.Lexer.LexType;
import frontend.Lexer.TokenList;
import frontend.Parser.Del.DelParser;
import frontend.Parser.Exp.ExpParser;
import frontend.Parser.Exp.Type.Cond;
import frontend.Parser.Exp.Type.Exp;
import frontend.Parser.Exp.Type.LVal;
import frontend.Parser.Stmt.Type.*;

import java.util.ArrayList;
import java.util.Objects;

public class StmtParser {
    public TokenList tokens;
    public Error errorLog;

    public StmtParser(TokenList tokens, Error errorLog)
    {
        this.tokens = tokens;
        this.errorLog = errorLog;
    }

    public Stmt parseStmt() {
        LexType token = tokens.getToken();
        return switch (token.getType()) {
            case IFTK -> new Stmt(parseIfStmt());
            case FORTK -> new Stmt(parseForStmt());
            case BREAKTK, CONTINUETK -> new Stmt(parseBCStmt(), tokens);
            case RETURNTK -> new Stmt(parseReturnStmt(), tokens);
            case PRINTFTK -> new Stmt(parsePrintStmt(), tokens);
            case LBRACE -> new Stmt(parseBlockStmt());
            case SEMICN -> new Stmt(null, tokens);
            default -> parseAssignmentOrExpStmt(token);
        };
    }

    private Stmt parseAssignmentOrExpStmt(LexType ident) {
        int step = 0;
        ArrayList<LexType> symbols = new ArrayList<>();
        LexType token = tokens.getAndMove();
        step++;

        while (true) {
            token = tokens.getAndMove();
            step++;

            if (token.getType() == LexType.TokenType.ASSIGN) {
                tokens.retreat(step);
                LVal lVal = new ExpParser(tokens, errorLog).parserLVal();
                LexType assign = tokens.getAndMove();
                symbols.add(assign);

                token = tokens.getToken();
                if (token.getType() == LexType.TokenType.GETINTTK ||
                        token.getType() == LexType.TokenType.GETCHARTK) {
                    return parseGetStmt(lVal, symbols);
                } else {
                    return parseAssignStmt(lVal, assign);
                }
            } else if (token.getType() == LexType.TokenType.SEMICN) {
                tokens.retreat(step);
                ExpStmt expStmt = new ExpStmt(new ExpParser(tokens, errorLog).parserExp());
                return new Stmt(expStmt, tokens);
            } else if (!Objects.equals(token.getLine(), ident.getLine())) {
                tokens.retreat(step);
                ExpStmt expStmt = new ExpStmt(new ExpParser(tokens, errorLog).parserExp());
                errorLog.add(tokens.getlastToken(1).getLine(), 'i');
                return new Stmt(expStmt, tokens);
            }
        }
    }

    private Stmt parseGetStmt(LVal lVal, ArrayList<LexType> symbols) {
        symbols.add(tokens.getAndMove()); // 'getint' or 'getchar'
        symbols.add(tokens.getAndMove()); // '('

        if (tokens.getToken().getType() != LexType.TokenType.RPARENT) {
            errorLog.add(tokens.getlastToken(1).getLine(), 'j');
        } else {
            symbols.add(tokens.getAndMove()); // ')'
        }

        if (tokens.getToken().getType() != LexType.TokenType.SEMICN) {
            errorLog.add(tokens.getlastToken(1).getLine(), 'i');
        }

        return new Stmt(new GetStmt(lVal, symbols), tokens);
    }

    private Stmt parseAssignStmt(LVal lVal, LexType assign) {
        Exp exp = new ExpParser(tokens, errorLog).parserExp();

        if (tokens.getToken().getType() != LexType.TokenType.SEMICN) {
            errorLog.add(tokens.getlastToken(1).getLine(), 'i');
        }

        return new Stmt(new AssignStmt(lVal, assign, exp), tokens);
    }


    // 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
    public IfStmt parseIfStmt() {
        LexType iFtoken = tokens.getAndMove();
        LexType left = tokens.getAndMove();
        Cond cond = new ExpParser(tokens, errorLog).parseCond();
        LexType right = tokens.getAndMove();
        if (right.getType() != LexType.TokenType.RPARENT) {
            errorLog.add(tokens.getlastToken(1).getLine(), 'j');
            right = null;
            tokens.retreat(1);
        }
        ArrayList<Stmt> stmts = new ArrayList<>();
        Stmt stmt = parseStmt();
        stmts.add(stmt);
        LexType elseToken = tokens.getToken();
        if (elseToken.getType() == LexType.TokenType.ELSETK) {
            elseToken = tokens.getAndMove();
            stmts.add(parseStmt());
            return new IfStmt(iFtoken, left, cond, right, stmts, elseToken);
        }
        return new IfStmt(iFtoken, left, cond, right, stmts, null);
    }

    // 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
    public ForStmt parseForStmt() {
        LexType fortoken = tokens.getAndMove();
        ArrayList<LexType> braces = new ArrayList<>();
        ArrayList<LexType> semicolons = new ArrayList<>();
        braces.add(tokens.getAndMove());
        TinyFStmt forStmt1 = null, forStmt2 = null;
        Cond cond = null;
        if (tokens.getToken().getType() != LexType.TokenType.SEMICN) {
            forStmt1 = parseTinyFStmt();
        }
        semicolons.add(tokens.getAndMove()); // first semicolon
        if (tokens.getToken().getType() != LexType.TokenType.SEMICN) {
            cond = new ExpParser(tokens, errorLog).parseCond();
        }
        semicolons.add(tokens.getAndMove()); // second semicolon
        if (tokens.getToken().getType() != LexType.TokenType.RPARENT) {
            forStmt2 = parseTinyFStmt();
        }
        braces.add(tokens.getAndMove()); // right parenthesis
        return new ForStmt(fortoken, braces, forStmt1, semicolons, cond, forStmt2, parseStmt());
    }


    // ForStmt → LVal '=' Exp
    public TinyFStmt parseTinyFStmt() {
        LVal lval = new ExpParser(tokens, errorLog).parserLVal();
        LexType assign = tokens.getAndMove();
        Exp exp = new ExpParser(tokens, errorLog).parserExp();
        return new TinyFStmt(lval, assign, exp);
    }

    // 'break' | 'continue'
    public bcStmt parseBCStmt() {
        tokens.forward(1);
        if (tokens.getToken().getType() != LexType.TokenType.SEMICN) {
            errorLog.add(tokens.getlastToken(1).getLine(), 'i');
        }
        tokens.retreat(1);
        return new bcStmt(tokens.getAndMove());
    }

    // 'return' [Exp]
    public ReturnStmt parseReturnStmt() {
        LexType returnToken = tokens.getAndMove();
        if (tokens.getToken().getType() == LexType.TokenType.SEMICN) {
            return new ReturnStmt(returnToken);
        } else if (!tokens.getToken().isFirstExp()) {
            errorLog.add(tokens.getlastToken(1).getLine(), 'i');
            return new ReturnStmt(returnToken);
        } else {
            return new ReturnStmt(returnToken, new ExpParser(tokens, errorLog).parserExp());
        }
    }

    // 'printf''('StringConst {','Exp}')'
    public PrintStmt parsePrintStmt() {
        ArrayList<LexType> all = new ArrayList<>();
        for (int i = 0; i < 3; i++) {
            all.add(tokens.getAndMove());
        }
        LexType next = tokens.getAndMove();
        ArrayList<LexType> seps = new ArrayList<>();
        ArrayList<Exp> exps = new ArrayList<>();
        while (next.getType() == LexType.TokenType.COMMA) {
            seps.add(next);
            exps.add(new ExpParser(tokens, errorLog).parserExp());
            next = tokens.getAndMove();
        }
        if (next.getType() != LexType.TokenType.RPARENT) {
            errorLog.add(tokens.getlastToken(2).getLine(), 'j');
            if (next.getType() != LexType.TokenType.SEMICN) {
                errorLog.add(tokens.getlastToken(2).getLine(), 'i');
            }
            next = null;
            tokens.retreat(1);
        } else if (tokens.getToken().getType() != LexType.TokenType.SEMICN) {
            errorLog.add(tokens.getlastToken(1).getLine(), 'i');
        }
        return new PrintStmt(all, seps, exps, next);
    }

    // Block → '{' { BlockItem } '}'
    public BlockStmt parseBlockStmt() {
        ArrayList<LexType> braces = new ArrayList<>();
        LexType left = tokens.getAndMove();
        braces.add(left);
        ArrayList<BlockItem> blockItems = new ArrayList<>();
        while (tokens.getToken().getType() != LexType.TokenType.RBRACE) {
            blockItems.add(parseBlockItem());
        }
        braces.add(tokens.getAndMove());
        return new BlockStmt(braces, blockItems);
    }

    // BlockItem → Decl | Stmt
    public BlockItem parseBlockItem() {
        LexType token = tokens.getToken();
        if (token.getType() == LexType.TokenType.CONSTTK ||
                token.getType() == LexType.TokenType.INTTK ||
                token.getType() == LexType.TokenType.CHARTK) {
            return new BlockItem(new DelParser(tokens, errorLog).parseDecl());
        } else {
            return new BlockItem(parseStmt());
        }
    }
}
