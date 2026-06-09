package frontend.parser;

import frontend.lexer.LexType;
import frontend.lexer.Lexer;
import frontend.lexer.Token;
import frontend.parser.block.*;
import frontend.parser.block.statement.*;
import frontend.parser.declaration.*;
import frontend.parser.expression.*;
import frontend.parser.expression.primary.Character;
import frontend.parser.expression.primary.Number;
import frontend.parser.expression.primary.PriExp;
import frontend.parser.expression.unary.FuncExp;
import frontend.parser.expression.unary.OpExp;
import frontend.parser.expression.unary.UnaryOp;
import frontend.parser.function.*;

import java.util.ArrayList;

public class Parser {
    private Lexer lexer;

    public Parser(Lexer lexer) {
        this.lexer = lexer;
    }

    public CompUnit parseCompUnit() {
        CompUnit compUnit = new CompUnit();
        while (true) {
            Token first = lexer.getToken();
            Token second = lexer.preRead();
            Token third = lexer.prePreRead();
            if (first.getType().equals(LexType.INTTK)) {
                if (third.getType().equals(LexType.LPARENT)) {
                    if (second.getType().equals(LexType.MAINTK)) {
                        compUnit.setMainFuncDef(parseMainFuncDef());
                        break;
                    } else {
                        compUnit.addFuncDef(parseFuncDef());
                    }
                } else {
                    compUnit.addDecl(parseDecl());
                }
            } else if (first.getType().equals(LexType.CHARTK)) {
                if (third.getType().equals(LexType.LPARENT)) {
                    compUnit.addFuncDef(parseFuncDef());
                } else {
                    compUnit.addDecl(parseDecl());
                }
            } else if (first.getType().equals(LexType.VOIDTK)) {
                compUnit.addFuncDef(parseFuncDef());
            } else if (first.getType().equals(LexType.CONSTTK)) {
                compUnit.addDecl(parseDecl());
            }
        }
        return compUnit;
    }

    public Decl parseDecl() {
        if (lexer.getToken().getType().equals(LexType.CONSTTK)) {
            return new Decl(parseConstDecl());
        } else {
            return new Decl(parseVarDecl());
        }
    }

    public FuncDef parseFuncDef() {
        FuncType funcType = new FuncType(lexer.getToken());
        lexer.next();
        Token ident = lexer.getToken();
        lexer.next();
        Token lParent = lexer.getToken();
        lexer.next();
        if (!lexer.getToken().getType().equals(LexType.RPARENT)) {
            FuncFParams funcFParams = parseFuncFParams();
            Token rParent;
            if (lexer.getToken().getType().equals(LexType.RPARENT)) {
                rParent = lexer.getToken();
                lexer.next();
            } else {
                rParent = null;
            }
            Block block = parseBlock();
            return new FuncDef(funcType, ident, lParent, funcFParams, rParent, block);
        } else {
            Token rParent = lexer.getToken();
            lexer.next();
            Block block = parseBlock();
            return new FuncDef(funcType, ident, lParent, rParent, block);
        }

    }

    public MainFuncDef parseMainFuncDef() {
        FuncType funcType = new FuncType(lexer.getToken());
        lexer.next();
        Token ident = lexer.getToken();
        lexer.next();
        Token lParent = lexer.getToken();
        lexer.next();
        Token rParent;
        if (lexer.getToken().getType().equals(LexType.RPARENT)) {
            rParent = lexer.getToken();
            lexer.next();
        } else {
            rParent = null;
        }
        Block block = parseBlock();
        return new MainFuncDef(funcType, ident, lParent, rParent, block);
    }

    public FuncFParams parseFuncFParams() {
        FuncFParam param1 = parseFuncFParam();
        if (lexer.getToken().getType().equals(LexType.COMMA)) {
            ArrayList<Token> commas = new ArrayList<>();
            ArrayList<FuncFParam> funcFParams = new ArrayList<>();
            while (lexer.getToken().getType().equals(LexType.COMMA)) {
                commas.add(lexer.getToken());
                lexer.next();
                funcFParams.add(parseFuncFParam());
            }
            return new FuncFParams(param1, commas, funcFParams);
        } else {
            return new FuncFParams(param1);
        }
    }

    public FuncFParam parseFuncFParam() {
        BType bType = new BType(lexer.getToken());
        lexer.next();
        Token ident = lexer.getToken();
        lexer.next();
        if (lexer.getToken().getType().equals(LexType.LBRACK)) {
            Token lBracket = lexer.getToken();
            lexer.next();
            Token rBracket;
            if (lexer.getToken().getType().equals(LexType.RBRACK)) {
                rBracket = lexer.getToken();
                lexer.next();
            } else {
                rBracket = null;
            }
            return new FuncFParam(bType, ident, lBracket, rBracket);
        } else {
            return new FuncFParam(bType, ident);
        }
    }

    public Block parseBlock() {
        Token lBrace = lexer.getToken();
        lexer.next();
        ArrayList<BlockItem> blockItems = new ArrayList<>();
        while (lexer.getToken() != null && !lexer.getToken().getType().equals(LexType.RBRACE)) {
            BlockItem blockItem = parseBlockItem();
            blockItems.add(blockItem);
        }
        Token rBrace = lexer.getToken();
        lexer.next();
        return new Block(lBrace, blockItems, rBrace);
    }

    public BlockItem parseBlockItem() {
        if (lexer.getToken().getType().equals(LexType.CONSTTK) ||
                lexer.getToken().getType().equals(LexType.INTTK) ||
                lexer.getToken().getType().equals(LexType.CHARTK)) {
            return new BlockItem(parseDecl());
        } else {
            return new BlockItem(parseStmt());
        }
    }

    public Stmt parseStmt() {
        Token first = lexer.getToken();
        if (first.getType().equals(LexType.SEMICN)) {
            return new Stmt(parseStmtSemi());
        } else if (first.getType().equals(LexType.LBRACE)) {
            return new Stmt(parseStmtBlock());
        } else if (first.getType().equals(LexType.IFTK)) {
            return new Stmt(parseStmtIf());
        } else if (first.getType().equals(LexType.FORTK)) {
            return new Stmt(parseStmtFor());
        } else if (first.getType().equals(LexType.BREAKTK)) {
            return new Stmt(parseStmtBreak());
        } else if (first.getType().equals(LexType.CONTINUETK)) {
            return new Stmt(parseStmtContinue());
        } else if (first.getType().equals(LexType.RETURNTK)) {
            return new Stmt(parseStmtReturn());
        } else if (first.getType().equals(LexType.PRINTFTK)) {
            return new Stmt(parseStmtPrint());
        } else if (first.getType().equals(LexType.IDENFR)) {
            Token tk = lexer.getToken();
            int pos = lexer.getPos();
            int line = lexer.getLineno();
            LVal lVal = parseLVal();
            if (lexer.getToken().getType().equals(LexType.ASSIGN)) {
                lexer.next();
                if (lexer.getToken().getType().equals(LexType.GETINTTK)) {
                    lexer.reset(tk, pos, line);
                    return new Stmt(parseStmtGetInt());
                } else if (lexer.getToken().getType().equals(LexType.GETCHARTK)) {
                    lexer.reset(tk, pos, line);
                    return new Stmt(parseStmtGetChar());
                } else {
                    lexer.reset(tk, pos, line);
                    return new Stmt(parseStmtAssign());
                }
            } else {
                lexer.reset(tk, pos, line);
                return new Stmt(parseStmtExp());
            }
        } else {
            return new Stmt(parseStmtExp());
        }
    }

    public StmtAssign parseStmtAssign() {
        LVal lVal = parseLVal();
        lexer.next();
        Token eq = lexer.getToken();
        lexer.next();
        Exp exp = parseExp();
        Token semi;
        if (lexer.getToken().getType().equals(LexType.SEMICN)) {
            semi = lexer.getToken();
            lexer.next();
        } else {
            semi = null;
        }
        return new StmtAssign(lVal, eq, exp, semi);
    }

    public StmtBlock parseStmtBlock() {
        Block block = parseBlock();
        return new StmtBlock(block);
    }

    public StmtBreak parseStmtBreak() {
        Token breakToken = lexer.getToken();
        lexer.next();
        Token semi;
        if (lexer.getToken().getType().equals(LexType.SEMICN)) {
            semi = lexer.getToken();
            lexer.next();
        } else {
            semi = null;
        }
        return new StmtBreak(breakToken, semi);
    }

    public StmtContinue parseStmtContinue() {
        Token continueToken = lexer.getToken();
        lexer.next();
        Token semi;
        if (lexer.getToken().getType().equals(LexType.SEMICN)) {
            semi = lexer.getToken();
            lexer.next();
        } else {
            semi = null;
        }
        return new StmtContinue(continueToken, semi);
    }

    public StmtExp parseStmtExp() {
        Exp exp = parseExp();
        Token semi;
        if (lexer.getToken().getType().equals(LexType.SEMICN)) {
            semi = lexer.getToken();
            lexer.next();
        } else {
            semi = null;
        }
        return new StmtExp(exp, semi);
    }

    public StmtFor parseStmtFor() {
        Token forTk = lexer.getToken();
        lexer.next();
        Token lParent = lexer.getToken();
        lexer.next();
        ForStmt stmt1;
        if (!lexer.getToken().getType().equals(LexType.SEMICN)) {
            stmt1 = parseForStmt();
        } else {
            stmt1 = null;
        }
        Token semi1 = lexer.getToken();
        lexer.next();
        Cond cond;
        if (!lexer.getToken().getType().equals(LexType.SEMICN)) {
            cond = parseCond();
        } else {
            cond = null;
        }
        Token semi2 = lexer.getToken();
        lexer.next();
        ForStmt stmt2;
        if (!lexer.getToken().getType().equals(LexType.RPARENT)) {
            stmt2 = parseForStmt();
        } else {
            stmt2 = null;
        }
        Token rParent;
        if (lexer.getToken().getType().equals(LexType.RPARENT)) {
            rParent = lexer.getToken();
            lexer.next();
        } else {
            rParent = null;
        }
        Stmt stmt = parseStmt();
        return new StmtFor(forTk, lParent, stmt1, semi1, cond, semi2, stmt2, rParent, stmt);
    }

    public StmtGetChar parseStmtGetChar() {
        LVal lVal = parseLVal();
        Token eq = lexer.getToken();
        lexer.next();
        Token getChar = lexer.getToken();
        lexer.next();
        Token lParent = lexer.getToken();
        lexer.next();
        Token rParent;
        if (lexer.getToken().getType().equals(LexType.RPARENT)) {
            rParent = lexer.getToken();
            lexer.next();
        } else {
            rParent = null;
        }
        Token semi;
        if (lexer.getToken().getType().equals(LexType.SEMICN)) {
            semi = lexer.getToken();
            lexer.next();
        } else {
            semi = null;
        }
        return  new StmtGetChar(lVal, eq, getChar, lParent, rParent, semi);
    }

    public StmtGetInt parseStmtGetInt() {
        LVal lVal = parseLVal();
        Token eq = lexer.getToken();
        lexer.next();
        Token getInt = lexer.getToken();
        lexer.next();
        Token lParent = lexer.getToken();
        lexer.next();
        Token rParent;
        if (lexer.getToken().getType().equals(LexType.RPARENT)) {
            rParent = lexer.getToken();
            lexer.next();
        } else {
            rParent = null;
        }
        Token semi;
        if (lexer.getToken().getType().equals(LexType.SEMICN)) {
            semi = lexer.getToken();
            lexer.next();
        } else {
            semi = null;
        }
        return  new StmtGetInt(lVal, eq, getInt, lParent, rParent, semi);
    }

    public StmtIf parseStmtIf() {
        Token ifTk = lexer.getToken();
        lexer.next();
        Token lParent = lexer.getToken();
        lexer.next();
        Cond cond = parseCond();
        Token rParent;
        if (lexer.getToken().getType().equals(LexType.RPARENT)) {
            rParent = lexer.getToken();
            lexer.next();
        } else {
            rParent = null;
        }
        Stmt ifStmt = parseStmt();
        if (lexer.getToken().getType().equals(LexType.ELSETK)) {
            Token elseTk = lexer.getToken();
            lexer.next();
            Stmt elseStmt = parseStmt();
            return new StmtIf(ifTk, lParent, cond, rParent, ifStmt, elseTk, elseStmt);
        } else {
            return new StmtIf(ifTk, lParent, cond, rParent, ifStmt);
        }
    }

    public StmtPrint parseStmtPrint() {
        Token print = lexer.getToken();
        lexer.next();
        Token lParent = lexer.getToken();
        lexer.next();
        Token strCon = lexer.getToken();
        lexer.next();
        ArrayList<Token> commas = new ArrayList<>();
        ArrayList<Exp> exps = new ArrayList<>();
        while (lexer.getToken().getType().equals(LexType.COMMA)) {
            commas.add(lexer.getToken());
            lexer.next();
            exps.add(parseExp());
        }
        Token rParent;
        if (lexer.getToken().getType().equals(LexType.RPARENT)) {
            rParent = lexer.getToken();
            lexer.next();
        } else {
            rParent = null;
        }
        Token semi;
        if (lexer.getToken().getType().equals(LexType.SEMICN)) {
            semi = lexer.getToken();
            lexer.next();
        } else {
            semi = null;
        }
        if (commas.isEmpty()) {
            return new StmtPrint(print, lParent, strCon, rParent, semi);
        } else {
            return new StmtPrint(print, lParent, strCon, commas, exps, rParent, semi);
        }
    }

    public StmtReturn parseStmtReturn() {
        Token returnTk = lexer.getToken();
        lexer.next();
        if (!lexer.getToken().getType().equals(LexType.SEMICN)) {
            Exp exp = parseExp();
            Token semi;
            if (lexer.getToken().getType().equals(LexType.SEMICN)) {
                semi = lexer.getToken();
                lexer.next();
            } else {
                semi = null;
            }
            return new StmtReturn(returnTk, exp, semi);
        } else {
            Token semi = lexer.getToken();
            lexer.next();
            return new StmtReturn(returnTk, semi);
        }
    }

    public StmtSemi parseStmtSemi() {
        Token semi = lexer.getToken();
        lexer.next();
        return new StmtSemi(semi);
    }

    public LVal parseLVal() {
        Token ident = lexer.getToken();
        lexer.next();
        if (lexer.getToken().getType().equals(LexType.LBRACK)) {
            Token lBracket = lexer.getToken();
            lexer.next();
            Exp exp = parseExp();
            Token rBracket;
            if (lexer.getToken().getType().equals(LexType.RBRACK)) {
                rBracket = lexer.getToken();
                lexer.next();
            } else {
                rBracket = null;
            }
            return new LVal(ident, lBracket, exp, rBracket);
        } else {
            return new LVal(ident);
        }
    }

    public ForStmt parseForStmt() {
        LVal lVal = parseLVal();
        Token eq = lexer.getToken();
        lexer.next();
        Exp exp = parseExp();
        return new ForStmt(lVal, eq, exp);
    }

    public Cond parseCond() {
        LOrExp lOrExp = parseLOrExp();
        return new Cond(lOrExp);
    }

    public ConstDecl parseConstDecl() {
        Token constTk = lexer.getToken();
        lexer.next();
        BType bType = new BType(lexer.getToken());
        lexer.next();
        ConstDef constDef = parseConstDef();
        if (lexer.getToken().getType().equals(LexType.COMMA)){
            ArrayList<Token> commas = new ArrayList<>();
            ArrayList<ConstDef> constDefs = new ArrayList<>();
            while (lexer.getToken().getType().equals(LexType.COMMA)) {
                commas.add(lexer.getToken());
                lexer.next();
                constDefs.add(parseConstDef());
            }
            Token semi;
            if (lexer.getToken().getType().equals(LexType.SEMICN)) {
                semi = lexer.getToken();
                lexer.next();
            } else {
                semi = null;
            }
            return new ConstDecl(constTk, bType, constDef, commas, constDefs, semi);
        } else {
            Token semi;
            if (lexer.getToken().getType().equals(LexType.SEMICN)) {
                semi = lexer.getToken();
                lexer.next();
            } else {
                semi = null;
            }
            return new ConstDecl(constTk, bType, constDef, semi);
        }
    }

    public ConstDef parseConstDef() {
        Token ident = lexer.getToken();
        lexer.next();
        if (lexer.getToken().getType().equals(LexType.LBRACK)) {
            Token lBracket = lexer.getToken();
            lexer.next();
            ConstExp constExp = parseConstExp();
            Token rBracket;
            if (lexer.getToken().getType().equals(LexType.RBRACK)) {
                rBracket = lexer.getToken();
                lexer.next();
            } else {
                rBracket = null;
            }
            Token eq = lexer.getToken();
            lexer.next();
            ConstInitVal constInitVal = parseConstInitVal();
            return new ConstDef(ident, lBracket, constExp, rBracket, eq, constInitVal);
        } else {
            Token eq = lexer.getToken();
            lexer.next();
            ConstInitVal constInitVal = parseConstInitVal();
            return new ConstDef(ident, eq, constInitVal);
        }
    }

    public ConstExp parseConstExp() {
        return new ConstExp(parseAddExp());
    }

    public ConstInitVal parseConstInitVal() {
        if (lexer.getToken().getType().equals(LexType.LBRACE)) {
            Token lBrace = lexer.getToken();
            lexer.next();
            if (!lexer.getToken().getType().equals(LexType.RBRACE)) {
                ConstExp first = parseConstExp();
                if (lexer.getToken().getType().equals(LexType.COMMA)) {
                    ArrayList<Token> commas = new ArrayList<>();
                    ArrayList<ConstExp> constExps = new ArrayList<>();
                    while (lexer.getToken().getType().equals(LexType.COMMA)) {
                        commas.add(lexer.getToken());
                        lexer.next();
                        constExps.add(parseConstExp());
                    }
                    Token rBrace = lexer.getToken();
                    lexer.next();
                    return new ConstInitVal(lBrace, first, commas, constExps, rBrace);
                } else {
                    Token rBrace = lexer.getToken();
                    lexer.next();
                    return new ConstInitVal(lBrace, first, rBrace);
                }
            } else {
                Token rBrace = lexer.getToken();
                lexer.next();
                return new ConstInitVal(lBrace, rBrace);
            }
        } else if (lexer.getToken().getType().equals(LexType.STRCON)) {
            Token strCon = lexer.getToken();
            lexer.next();
            return new ConstInitVal(strCon);
        } else {
            ConstExp constExp = parseConstExp();
            return new ConstInitVal(constExp);
        }
    }

    public VarDecl parseVarDecl() {
        BType bType = new BType(lexer.getToken());
        lexer.next();
        VarDef varDef = parseVarDef();
        if (lexer.getToken().getType().equals(LexType.COMMA)){
            ArrayList<Token> commas = new ArrayList<>();
            ArrayList<VarDef> varDefs = new ArrayList<>();
            while (lexer.getToken().getType().equals(LexType.COMMA)) {
                commas.add(lexer.getToken());
                lexer.next();
                varDefs.add(parseVarDef());
            }
            Token semi;
            if (lexer.getToken().getType().equals(LexType.SEMICN)) {
                semi = lexer.getToken();
                lexer.next();
            } else {
                semi = null;
            }
            return new VarDecl(bType, varDef, commas, varDefs, semi);
        } else {
            Token semi;
            if (lexer.getToken().getType().equals(LexType.SEMICN)) {
                semi = lexer.getToken();
                lexer.next();
            } else {
                semi = null;
            }
            return new VarDecl(bType, varDef, semi);
        }
    }

    public VarDef parseVarDef() {
        Token ident = lexer.getToken();
        lexer.next();
        if (lexer.getToken().getType().equals(LexType.LBRACK)) {
            Token lBracket = lexer.getToken();
            lexer.next();
            ConstExp constExp = parseConstExp();
            Token rBracket;
            if (lexer.getToken().getType().equals(LexType.RBRACK)) {
                rBracket = lexer.getToken();
                lexer.next();
            } else {
                rBracket = null;
            }
            if (lexer.getToken().getType().equals(LexType.ASSIGN)) {
                Token eq = lexer.getToken();
                lexer.next();
                InitVal initVal = parseInitVal();
                return new VarDef(ident, lBracket, constExp, rBracket, eq, initVal);
            } else {
                return new VarDef(ident, lBracket, constExp, rBracket);
            }
        } else {
            if (lexer.getToken().getType().equals(LexType.ASSIGN)) {
                Token eq = lexer.getToken();
                lexer.next();
                InitVal initVal = parseInitVal();
                return new VarDef(ident, eq, initVal);
            } else {
                return new VarDef(ident);
            }
        }
    }

    public InitVal parseInitVal() {
        if (lexer.getToken().getType().equals(LexType.LBRACE)) {
            Token lBrace = lexer.getToken();
            lexer.next();
            if (!lexer.getToken().getType().equals(LexType.RBRACE)) {
                Exp first = parseExp();
                if (lexer.getToken().getType().equals(LexType.COMMA)) {
                    ArrayList<Token> commas = new ArrayList<>();
                    ArrayList<Exp> exps = new ArrayList<>();
                    while (lexer.getToken().getType().equals(LexType.COMMA)) {
                        commas.add(lexer.getToken());
                        lexer.next();
                        exps.add(parseExp());
                    }
                    Token rBrace = lexer.getToken();
                    lexer.next();
                    return new InitVal(lBrace, first, commas, exps, rBrace);
                } else {
                    Token rBrace = lexer.getToken();
                    lexer.next();
                    return new InitVal(lBrace, first, rBrace);
                }
            } else {
                Token rBrace = lexer.getToken();
                lexer.next();
                return new InitVal(lBrace, rBrace);
            }
        } else if (lexer.getToken().getType().equals(LexType.STRCON)) {
            Token strCon = lexer.getToken();
            lexer.next();
            return new InitVal(strCon);
        } else {
            Exp Exp = parseExp();
            return new InitVal(Exp);
        }
    }

    public Exp parseExp() {
        return new Exp(parseAddExp());
    }

    public LOrExp parseLOrExp() {
        LAndExp first = parseLAndExp();
        ArrayList<Token> operators = new ArrayList<>();
        ArrayList<LAndExp> exps = new ArrayList<>();
        while (lexer.getToken().getType().equals(LexType.OR)) {
            operators.add(lexer.getToken());
            lexer.next();
            exps.add(parseLAndExp());
        }
        return new LOrExp(first, operators, exps);
    }

    public LAndExp parseLAndExp() {
        EqExp first = parseEqExp();
        ArrayList<Token> operators = new ArrayList<>();
        ArrayList<EqExp> exps = new ArrayList<>();
        while (lexer.getToken().getType().equals(LexType.AND)) {
            operators.add(lexer.getToken());
            lexer.next();
            exps.add(parseEqExp());
        }
        return new LAndExp(first, operators, exps);
    }

    public EqExp parseEqExp() {
        RelExp first = parseRelExp();
        ArrayList<Token> operators = new ArrayList<>();
        ArrayList<RelExp> exps = new ArrayList<>();
        while (lexer.getToken().getType().equals(LexType.EQL) ||
                lexer.getToken().getType().equals(LexType.NEQ)) {
            operators.add(lexer.getToken());
            lexer.next();
            exps.add(parseRelExp());
        }
        return new EqExp(first, operators, exps);
    }

    public RelExp parseRelExp() {
        AddExp first = parseAddExp();
        ArrayList<Token> operators = new ArrayList<>();
        ArrayList<AddExp> exps = new ArrayList<>();
        while (lexer.getToken().getType().equals(LexType.LSS) ||
                lexer.getToken().getType().equals(LexType.GRE) ||
                lexer.getToken().getType().equals(LexType.LEQ) ||
                lexer.getToken().getType().equals(LexType.GEQ)) {
            operators.add(lexer.getToken());
            lexer.next();
            exps.add(parseAddExp());
        }
        return new RelExp(first, operators, exps);
    }

    public AddExp parseAddExp() {
        MulExp first = parseMulExp();
        ArrayList<Token> operators = new ArrayList<>();
        ArrayList<MulExp> exps = new ArrayList<>();
        while (lexer.getToken().getType().equals(LexType.PLUS) ||
                lexer.getToken().getType().equals(LexType.MINU)) {
            operators.add(lexer.getToken());
            lexer.next();
            exps.add(parseMulExp());
        }
        return new AddExp(first, operators, exps);
    }

    public MulExp parseMulExp() {
        UnaryExp first = parseUnaryExp();
        ArrayList<Token> operators = new ArrayList<>();
        ArrayList<UnaryExp> exps = new ArrayList<>();
        while (lexer.getToken().getType().equals(LexType.MULT) ||
                lexer.getToken().getType().equals(LexType.DIV) ||
                lexer.getToken().getType().equals(LexType.MOD)) {
            operators.add(lexer.getToken());
            lexer.next();
            exps.add(parseUnaryExp());
        }
        return new MulExp(first, operators, exps);
    }

    public FuncRParams parseFuncRParams() {
        Exp first = parseExp();
        ArrayList<Token> commas = new ArrayList<>();
        ArrayList<Exp> exps = new ArrayList<>();
        while (lexer.getToken().getType().equals(LexType.COMMA)) {
            commas.add(lexer.getToken());
            lexer.next();
            exps.add(parseExp());
        }
        if (commas.isEmpty()) {
            return new FuncRParams(first);
        } else {
            return new FuncRParams(first, commas, exps);
        }
    }

    public UnaryOp parseUnaryOp() {
        Token op = lexer.getToken();
        lexer.next();
        return new UnaryOp(op);
    }

    public UnaryExp parseUnaryExp() {
        Token first = lexer.getToken();
        Token second = lexer.preRead();
        if (first.getType().equals(LexType.IDENFR)) {
            if (second.getType().equals(LexType.LPARENT)) {
                return new UnaryExp(parseFuncExp());
            } else {
                return new UnaryExp(parsePrimaryExp());
            }
        } else if (first.getType().equals(LexType.PLUS) ||
                first.getType().equals(LexType.MINU) ||
                first.getType().equals(LexType.NOT)){
            return new UnaryExp(parseOpExp());
        } else {
            return new UnaryExp(parsePrimaryExp());
        }
    }

    public FuncExp parseFuncExp() {
        Token ident = lexer.getToken();
        lexer.next();
        Token lParent = lexer.getToken();
        lexer.next();
        FuncRParams funcRParams = null;
        if (!lexer.getToken().getType().equals(LexType.RPARENT)) {
            funcRParams = parseFuncRParams();
        }
        Token rParent;
        if (lexer.getToken().getType().equals(LexType.RPARENT)) {
            rParent = lexer.getToken();
            lexer.next();
        } else {
            rParent = null;
        }
        if (funcRParams == null) {
            return new FuncExp(ident, lParent, rParent);
        } else {
            return new FuncExp(ident, lParent, funcRParams, rParent);
        }
    }

    public OpExp parseOpExp() {
        UnaryOp op = parseUnaryOp();
        UnaryExp exp = parseUnaryExp();
        return new OpExp(op, exp);
    }

    public PrimaryExp parsePrimaryExp() {
        if (lexer.getToken().getType().equals(LexType.INTCON)) {
            return new PrimaryExp(parseNumber());
        } else if (lexer.getToken().getType().equals(LexType.CHRCON)) {
            return new PrimaryExp(parseChar());
        } else if (lexer.getToken().getType().equals(LexType.LPARENT)) {
            return new PrimaryExp(parsePriExp());
        } else {
            return new PrimaryExp(parseLVal());
        }
    }

    public PriExp parsePriExp() {
        Token lParent = lexer.getToken();
        lexer.next();
        Exp exp = parseExp();
        Token rParent;
        if (lexer.getToken().getType().equals(LexType.RPARENT)) {
            rParent = lexer.getToken();
            lexer.next();
        } else {
            rParent = null;
        }
        return new PriExp(lParent, exp, rParent);
    }

    public Character parseChar() {
        Token t = lexer.getToken();
        lexer.next();
        return new Character(t);
    }

    public Number parseNumber() {
        Token t = lexer.getToken();
        lexer.next();
        return new Number(t);
    }
}
