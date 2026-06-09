package frontend.parser.stmt;

import exeptions.ErrorType;
import frontend.lexer.Token;
import frontend.lexer.TokenType;
import frontend.parser.TokenHandler;
import frontend.parser.stmt.types.*;
import frontend.parser.expr.types.*;
import frontend.parser.expr.ExpParser;
import frontend.parser.decl.DeclParser;

import java.util.ArrayList;

public class StmtParser {
    private static TokenHandler handler;
    public static void setHandler(TokenHandler newHandler) {
        handler = newHandler;
    }
    public static Block parseBlock() {
        Token lBrace = handler.getNextAndMove();
        ArrayList<BlockItem> blockItems = new ArrayList<>();
        TokenType nextType = handler.getNext().getType();
        while (true) {
            boolean blockEnd = false;
            switch (nextType) {
                case INTTK, CONSTTK, CHARTK -> blockItems.add(DeclParser.parseDecl());
                case IDENFR, LPARENT, INTCON, CHRCON, PLUS, MINU, NOT, LBRACE, SEMICN, IFTK, FORTK, BREAKTK, CONTINUETK, PRINTFTK, RETURNTK ->
                        blockItems.add(parseStmt());
                default -> blockEnd = true; // RBRACE
            }
            nextType = handler.getNext().getType();
            if (blockEnd) break;
        }
        return new Block(lBrace, blockItems, handler.getNextAndMove());
    }
    public static Stmt parseStmt() {
        TokenType nextType = handler.getNext().getType();
        switch (nextType) {
            case LBRACE -> {
                return new Stmt(parseBlock());
            }
            case IFTK -> {
                return parseIfElseStmt();
            }
            case FORTK -> {
                return parseForLoopStmt();
            }
            case BREAKTK, CONTINUETK -> {
                Token token = handler.getNextAndMove();
                Token semicn = null;
                if (handler.getNext().getType() == TokenType.SEMICN) {
                    semicn = handler.getNextAndMove();
                } else {
                    handler.addError(ErrorType.MISS_SEMICN);
                }
                return new Stmt(token, semicn);
            }
            case PRINTFTK -> {
                return parsePrintfStmt();
            }
            case RETURNTK -> {
                Token retTK = handler.getNextAndMove();
                Exp retExp = null;
                if (Exp.inFirst(handler.getNext())) {
                    retExp = ExpParser.parseExp(false);
                }
                Token semicn = null;
                if (handler.getNext().getType() == TokenType.SEMICN) {
                    semicn = handler.getNextAndMove();
                } else {
                    handler.addError(ErrorType.MISS_SEMICN);
                }
                return new Stmt(retTK, retExp, semicn);
            }
            case IDENFR -> {
                return parseLValOrExpStmt();
            }
            case SEMICN -> {
                return new Stmt(handler.getNextAndMove());
            }
            default -> {
                Token semicn = null;
                Exp exp = ExpParser.parseExp(false);
                if (handler.getNext().getType() == TokenType.SEMICN) {
                    semicn = handler.getNextAndMove();
                } else {
                    handler.addError(ErrorType.MISS_SEMICN);
                }
                return new Stmt(exp, semicn);
            }
        }
    }

    private static Stmt parseIfElseStmt() {
        Token ifTK = handler.getNextAndMove();
        // if-else
        Token lParent = handler.getNextAndMove();
        Cond cond = ExpParser.parseCond();
        Token rParent = null;
        if (handler.getNext().getType() == TokenType.RPARENT) {
            rParent = handler.getNextAndMove();
        } else {
            handler.addError(ErrorType.MISS_RPARENT);
        }
        Stmt ifStmt = parseStmt();
        if (handler.getNext().getType() == TokenType.ELSETK) {
            Token elseTK = handler.getNextAndMove();
            Stmt elseStmt = parseStmt();
            return new Stmt(ifTK, lParent, cond, rParent, ifStmt, elseTK, elseStmt);
        } else {
            return new Stmt(ifTK, lParent, cond, rParent, ifStmt);
        }
    }

    private static Stmt parseForLoopStmt() {
        Token forTK = handler.getNextAndMove();
        // for
        // 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
        Token lParent = handler.getNextAndMove();
        ForStmt lForStmt = null;
        ForStmt rForStmt = null;
        if (handler.getNext().getType() == TokenType.IDENFR) {
            lForStmt = parseForStmt();
        }
        Token lSemicn = handler.getNextAndMove();
        Cond cond = null;
        if (Cond.inFirst(handler.getNext())) {
            cond = ExpParser.parseCond();
        }
        Token rSemicn = handler.getNextAndMove();
        if (handler.getNext().getType() == TokenType.IDENFR) {
            rForStmt = parseForStmt();
        }
        Token rParent = handler.getNextAndMove();
        Stmt stmt = parseStmt();
        return new Stmt(forTK, lParent, lForStmt, lSemicn, cond, rSemicn, rForStmt, rParent, stmt);
    }

    private static Stmt parsePrintfStmt() {
        Token printfTK = handler.getNextAndMove();
        // printf
        // 'printf''('StringConst {','Exp}')'';' // i j
        Token lParent = handler.getNextAndMove();
        Token string = handler.getNextAndMove();
        ArrayList<Token> seps = new ArrayList<>();
        ArrayList<Exp> exps = new ArrayList<>();
        while (handler.getNext().getType() == TokenType.COMMA) {
            seps.add(handler.getNextAndMove());
            exps.add(ExpParser.parseExp(false));
        }
        Token rParent = null;
        if (handler.getNext().getType() == TokenType.RPARENT) {
            rParent = handler.getNextAndMove();
        } else {
            handler.addError(ErrorType.MISS_RPARENT);
        }
        Token semicn = null;
        if (handler.getNext().getType() == TokenType.SEMICN) {
            semicn = handler.getNextAndMove();
        } else {
            handler.addError(ErrorType.MISS_SEMICN);
        }
        return new Stmt(printfTK, lParent, string, seps, exps, rParent, semicn);
    }

    private static Stmt parseLValOrExpStmt() {
        int pointer = handler.getPointer();
        LVal lVal = ExpParser.parseLVal();
        if (handler.getNext().getType() != TokenType.ASSIGN) {
            handler.setPointer(pointer);
            Exp exp = ExpParser.parseExp(false);
            Token semicn = null;
            if (handler.getNext().getType() == TokenType.SEMICN) {
                semicn = handler.getNextAndMove();
            } else {
                handler.addError(ErrorType.MISS_SEMICN);
            }
            return new Stmt(exp, semicn);
        } else {
            Token assign = handler.getNextAndMove();
            if (handler.getNext().getType() != TokenType.GETCHARTK && handler.getNext().getType() != TokenType.GETINTTK) {
                Exp exp = ExpParser.parseExp(false);
                Token semicn = null;
                if (handler.getNext().getType() == TokenType.SEMICN) {
                    semicn = handler.getNextAndMove();
                } else {
                    handler.addError(ErrorType.MISS_SEMICN);
                }
                return new Stmt(lVal, assign, exp, semicn);
            } else {
                Token inputTK = handler.getNextAndMove();
                Token lParent = handler.getNextAndMove();
                Token rParent = null;
                if (handler.getNext().getType() == TokenType.RPARENT) {
                    rParent = handler.getNextAndMove();
                } else {
                    handler.addError(ErrorType.MISS_RPARENT);
                }
                Token semicn = null;
                if (handler.getNext().getType() == TokenType.SEMICN) {
                    semicn = handler.getNextAndMove();
                } else {
                    handler.addError(ErrorType.MISS_SEMICN);
                }
                return new Stmt(lVal, assign, inputTK, lParent, rParent, semicn);
            }
        }
    }

    public static ForStmt parseForStmt() {
        return new ForStmt(ExpParser.parseLVal(), handler.getNextAndMove(), ExpParser.parseExp(false));
    }
}
