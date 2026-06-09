package frontend.parser;

import frontend.lexer.*;
import frontend.parser.ast.*;
import frontend.parser.ast.decl.*;
import frontend.parser.ast.exp.*;
import frontend.parser.ast.exp.Character;
import frontend.parser.ast.exp.Number;
import frontend.parser.ast.block.*;

import java.util.ArrayList;

public class Parser {
    private static volatile Parser instance;

    private ArrayList<Token> TokenStream;
    private int cur;

    public Token curToken() {
        if (cur > TokenStream.size() - 1) {
            return null;
        }
        Token curToken = new Token();
        curToken = TokenStream.get(cur);
        return curToken;
    }

    private Parser() {
        this.TokenStream = new ArrayList<Token>();
        cur = 0;
    }

    public static Parser getInstance() {
        if (instance == null) {
            synchronized (Parser.class) {
                if (instance == null) {
                    instance = new Parser();
                }
            }
        }
        return instance;
    }

    public void setTokenStream(ArrayList<Token> tokenStream) {
        this.TokenStream = tokenStream;
        cur = 0;
    }

    public CompUnit parseCompUnit() {
        CompUnit compUnit = new CompUnit();
        Token first = null, second = null, third = null;
        while (true) {
            first = TokenStream.get(cur);
            if (cur < TokenStream.size() - 1) {
                second = TokenStream.get(cur + 1);
            }
            if (cur < TokenStream.size() - 2) {
                third = TokenStream.get(cur + 2);
            }
            if (first.getType().equals(TokenType.INTTK)) {
                if (third.getType().equals(TokenType.LPARENT)) {
                    if (second.getType().equals(TokenType.MAINTK)) {
                        compUnit.setMainFuncDef(parseMainFuncDef());
                        break;
                    } else {
                        compUnit.addFuncDef(parseFuncDef());
                    }
                } else {
                    compUnit.addDecl(parseDecl());
                }
            } else if (first.getType().equals(TokenType.CHARTK)) {
                if (third.getType().equals(TokenType.LPARENT)) {
                    compUnit.addFuncDef(parseFuncDef());
                } else {
                    compUnit.addDecl(parseDecl());
                }
            } else if (first.getType().equals(TokenType.VOIDTK)) {
                compUnit.addFuncDef(parseFuncDef());
            } else if (first.getType().equals(TokenType.CONSTTK)) {
                compUnit.addDecl(parseDecl());
            } else {
                break;
            }
        }
        return compUnit;
    }

    public Decl parseDecl() {
        if (TokenStream.get(cur).getType().equals(TokenType.CONSTTK)) {
            return new Decl(parseConstDecl());
        } else {
            return new Decl(parseVarDecl());
        }
    }

    public FuncDef parseFuncDef() {
        FuncType funcType = new FuncType(curToken());
        cur++;
        Token ident = curToken();
        cur++;
        Token lParent = curToken();
        cur++;

        if (!curToken().getType().equals(TokenType.RPARENT) && (curToken().getType().equals(TokenType.INTTK) || curToken().getType().equals(TokenType.CHARTK))) {
            FuncFParams funcFParams = parseFuncFParams();
            Token rParent;
            if (curToken().getType().equals(TokenType.RPARENT)) {
                rParent = curToken();
                cur++;
            } else {
                rParent = null;
            }
            Block block = parseBlock();
            return new FuncDef(funcType, ident, lParent, funcFParams, rParent, block);

        } else {
            Token rParent;
            if (curToken().getType().equals(TokenType.RPARENT)) {
                rParent = curToken();
                cur++;
            } else {
                rParent = null;
            }
            Block block = parseBlock();
            return new FuncDef(funcType, ident, lParent, rParent, block);
        }
    }

    public MainFuncDef parseMainFuncDef() {
        FuncType funcType = new FuncType(curToken());
        cur++;
        Token ident = curToken();
        cur++;
        Token lParent = curToken();
        cur++;
        Token rParent;
        if (curToken().getType().equals(TokenType.RPARENT)) {
            rParent = curToken();
            cur++;
        } else {
            rParent = null;
        }
        Block block = parseBlock();
        return new MainFuncDef(funcType, ident, lParent, rParent, block);
    }

    public FuncFParams parseFuncFParams() {
        FuncFParam firstParam = parseFuncFParam();
        if (curToken().getType().equals(TokenType.COMMA)) {
            ArrayList<Token> commas = new ArrayList<Token>();
            ArrayList<FuncFParam> params = new ArrayList<FuncFParam>();
            while (curToken().getType().equals(TokenType.COMMA)) {
                commas.add(curToken());
                cur++;
                params.add(parseFuncFParam());
            }
            return new FuncFParams(firstParam, commas, params);
        } else {
            return new FuncFParams(firstParam);
        }
    }

    public FuncFParam parseFuncFParam() {
        BType bType = new BType(curToken());
        cur++;
        Token ident = curToken();
        cur++;
        if (curToken().getType().equals(TokenType.LBRACK)) {
            Token lBracket = curToken();
            cur++;
            Token rBracket;
            if (curToken().getType().equals(TokenType.RBRACK)) {
                rBracket = curToken();
                cur++;
            } else {
                rBracket = null;
            }
            return new FuncFParam(bType, ident, lBracket, rBracket);
        } else {
            return new FuncFParam(bType, ident);
        }
    }
    
    public ConstDecl parseConstDecl() {
        Token constToken = curToken();
        cur++;
        BType bType = new BType(curToken());
        cur++;
        ConstDef firstDef = parseConstDef();
        if (curToken().getType().equals(TokenType.COMMA)) {
            ArrayList<Token> commas = new ArrayList<Token>();
            ArrayList<ConstDef> defs = new ArrayList<ConstDef>();
            while (curToken().getType().equals(TokenType.COMMA)) {
                commas.add(curToken());
                cur++;
                defs.add(parseConstDef());
            }
            Token semicolon;
            if (curToken().getType().equals(TokenType.SEMICN)) {
                semicolon = curToken();
                cur++;
            } else {
                semicolon = null;
            }
            return new ConstDecl(constToken, bType, firstDef, commas, defs, semicolon);
        } else {
            Token semicolon;
            if (curToken().getType().equals(TokenType.SEMICN)) {
                semicolon = curToken();
                cur++;
            } else {
                semicolon = null;
            }
            return new ConstDecl(constToken, bType, firstDef, semicolon);
        }
    }

    public ConstDef parseConstDef() {
        Token ident = curToken();
        cur++;
        if (curToken().getType().equals(TokenType.LBRACK)) {
            Token lBracket = curToken();
            cur++;
            ConstExp constExp = parseConstExp();
            Token rBracket;
            if (curToken().getType().equals(TokenType.RBRACK)) {
                rBracket = curToken();
                cur++;
            } else {
                rBracket = null;
            }
            Token eql = curToken();
            cur++;
            ConstInitVal constInitVal = parseConstInitVal();
            return new ConstDef(ident, lBracket, constExp, rBracket, eql, constInitVal);
        } else {
            Token eql = curToken();
            cur++;
            ConstInitVal constInitVal = parseConstInitVal();
            return new ConstDef(ident, eql, constInitVal);
        }
    }

    public ConstExp parseConstExp() {
        return new ConstExp(parseAddExp());
    }

    public ConstInitVal parseConstInitVal() {
        if (curToken().getType().equals(TokenType.LBRACE)) {
            Token lBrace = curToken();
            cur++;
            if (!curToken().getType().equals(TokenType.RBRACE)) {
                ConstExp firstExp = parseConstExp();
                if (curToken().getType().equals(TokenType.COMMA)) {
                    ArrayList<Token> commas = new ArrayList<Token>();
                    ArrayList<ConstExp> exps = new ArrayList<ConstExp>();
                    while (curToken().getType().equals(TokenType.COMMA)) {
                        commas.add(curToken());
                        cur++;
                        exps.add(parseConstExp());
                    }
                    Token rBrace = curToken();
                    cur++;
                    return new ConstInitVal(lBrace, firstExp, commas, exps, rBrace);
                } else {
                    Token rBrace = curToken();
                    cur++;
                    return new ConstInitVal(lBrace, firstExp, rBrace);
                }
            } else {
                Token rBrace = curToken();
                cur++;
                return new ConstInitVal(lBrace, rBrace);
            }
        } else if (curToken().getType().equals(TokenType.STRCON)) {
            Token stringConst = curToken();
            cur++;
            return new ConstInitVal(stringConst);
        } else {
            ConstExp constExp = parseConstExp();
            return new ConstInitVal(constExp);
        }
    }

    public VarDecl parseVarDecl() {
        BType bType = new BType(curToken());
        cur++;
        VarDef firstDef = parseVarDef();
        if (curToken().getType().equals(TokenType.COMMA)) {
            ArrayList<Token> commas = new ArrayList<Token>();
            ArrayList<VarDef> defs = new ArrayList<VarDef>();
            while (curToken().getType().equals(TokenType.COMMA)) {
                commas.add(curToken());
                cur++;
                defs.add(parseVarDef());
            }
            Token semicolon;
            if (curToken().getType().equals(TokenType.SEMICN)) {
                semicolon = curToken();
                cur++;
            } else {
                semicolon = null;
            }
            return new VarDecl(bType, firstDef, commas, defs, semicolon);
        } else {
            Token semicolon;
            if (curToken().getType().equals(TokenType.SEMICN)) {
                semicolon = curToken();
                cur++;
            } else {
                semicolon = null;
            }
            return new VarDecl(bType, firstDef, semicolon);
        }
    }

    public VarDef parseVarDef() {
        Token ident = curToken();
        cur++;
        if (curToken().getType().equals(TokenType.LBRACK)) {
            Token lBracket = curToken();
            cur++;
            ConstExp constExp = parseConstExp();
            Token rBracket;
            if (curToken().getType().equals(TokenType.RBRACK)) {
                rBracket = curToken();
                cur++;
            } else {
                rBracket = null;
            }
            if (curToken().getType().equals(TokenType.ASSIGN)) {
                Token eql = curToken();
                cur++;
                InitVal initVal = parseInitVal();
                return new VarDef(ident, lBracket, constExp, rBracket, eql, initVal);
            } else {
                return new VarDef(ident, lBracket, constExp, rBracket);
            }
        } else {
            if (curToken().getType().equals(TokenType.ASSIGN)) {
                Token eql = curToken();
                cur++;
                InitVal initVal = parseInitVal();
                return new VarDef(ident, eql, initVal);
            } else {
                return new VarDef(ident);
            }
        }
    }

    public InitVal parseInitVal() {
        if (curToken().getType().equals(TokenType.LBRACE)) {
            Token lBrace = curToken();
            cur++;
            if (!curToken().getType().equals(TokenType.RBRACE)) {
                Exp firstExp = parseExp();
                if (curToken().getType().equals(TokenType.COMMA)) {
                    ArrayList<Token> commas = new ArrayList<Token>();
                    ArrayList<Exp> exps = new ArrayList<Exp>();
                    while (curToken().getType().equals(TokenType.COMMA)) {
                        commas.add(curToken());
                        cur++;
                        exps.add(parseExp());
                    }
                    Token rBrace = curToken();
                    cur++;
                    return new InitVal(lBrace, firstExp, commas, exps, rBrace);
                } else {
                    Token rBrace = curToken();
                    cur++;
                    return new InitVal(lBrace, firstExp, rBrace);
                }
            } else {
                Token rBrace = curToken();
                cur++;
                return new InitVal(lBrace, rBrace);
            }
        } else if (curToken().getType().equals(TokenType.STRCON)) {
            Token stringConst = curToken();
            cur++;
            return new InitVal(stringConst);
        } else {
            Exp exp = parseExp();
            return new InitVal(exp);
        }
    }

    public Block parseBlock() {
        Token lBrace = curToken();
        cur++;
        ArrayList<BlockItem> blockItems = new ArrayList<BlockItem>();
        while (curToken() != null && !curToken().getType().equals(TokenType.RBRACE)) {
            BlockItem blockItem = parseBlockItem();
            blockItems.add(blockItem);
        }
        Token rBrace = curToken();
        cur++;
        return new Block(lBrace, blockItems, rBrace);
    }

    public BlockItem parseBlockItem() {
        if (curToken().getType().equals(TokenType.INTTK) || curToken().getType().equals(TokenType.CHARTK) || curToken().getType().equals(TokenType.CONSTTK)) {
            return new BlockItem(parseDecl());
        } else {
            return new BlockItem(parseStmt());
        }
    }

    public Stmt parseStmt() {
        Token first = curToken();
        if (curToken().getType().equals(TokenType.SEMICN)) {
            return new Stmt(parseStmtSemi());
        } else if (first.getType().equals(TokenType.LBRACE)) {
            return new Stmt(parseStmtBlock());
        } else if (first.getType().equals(TokenType.IFTK)) {
            return new Stmt(parseStmtIf());
        } else if (first.getType().equals(TokenType.FORTK)) {
            return new Stmt(parseStmtFor());
        } else if (first.getType().equals(TokenType.BREAKTK)) {
            return new Stmt(parseStmtBreak());
        } else if (first.getType().equals(TokenType.CONTINUETK)) {
            return new Stmt(parseStmtContinue());
        } else if (first.getType().equals(TokenType.RETURNTK)) {
            return new Stmt(parseStmtReturn());
        } else if (first.getType().equals(TokenType.PRINTFTK)) {
            return new Stmt(parseStmtPrintf());
        } else if (first.getType().equals(TokenType.IDENFR)) {
            int rewind = cur;
            LVal lVal = parseLVal();
            if (curToken().getType().equals(TokenType.ASSIGN)) {
                cur++;
                if (curToken().getType().equals(TokenType.GETINTTK)) {
                    cur = rewind;
                    return new Stmt(parseStmtGetint());
                } else if (curToken().getType().equals(TokenType.GETCHARTK)) {
                    cur = rewind;
                    return new Stmt(parseStmtGetchar());
                } else {
                    cur = rewind;
                    return new Stmt(parseStmtLVal());
                }
            } else {
                cur = rewind;
                return new Stmt(parseStmtExp());
            }
        } else {
            return new Stmt(parseStmtExp());
        }
    }

    public StmtSemi parseStmtSemi() {
        Token semicolon = curToken();
        cur++;
        return new StmtSemi(semicolon);
    }

    public StmtLVal parseStmtLVal() {
        LVal lVal = parseLVal();
        Token eql = curToken();
        cur++;
        Exp exp = parseExp();
        Token semicolon;
        if (curToken().getType().equals(TokenType.SEMICN)) {
            semicolon = curToken();
            cur++;
        } else {
            semicolon = null;
        }
        return new StmtLVal(lVal, eql, exp, semicolon);
    }

    public StmtBlock parseStmtBlock() {
        Block block = parseBlock();
        return new StmtBlock(block);
    }

    public StmtBreak parseStmtBreak() {
        Token breakToken = curToken();
        cur++;
        Token semicolon;
        if (curToken().getType().equals(TokenType.SEMICN)) {
            semicolon = curToken();
            cur++;
        } else {
            semicolon = null;
        }
        return new StmtBreak(breakToken, semicolon);
    }

    public StmtContinue parseStmtContinue() {
        Token continueToken = curToken();
        cur++;
        Token semicolon;
        if (curToken().getType().equals(TokenType.SEMICN)) {
            semicolon = curToken();
            cur++;
        } else {
            semicolon = null;
        }
        return new StmtContinue(continueToken, semicolon);
    }

    public StmtReturn parseStmtReturn() {
        Token returnToken = curToken();
        cur++;
        if (!curToken().getType().equals(TokenType.SEMICN) && curToken().isStart()) {
            Exp exp = parseExp();
            Token semicolon;
            if (curToken().getType().equals(TokenType.SEMICN)) {
                semicolon = curToken();
                cur++;
            } else {
                semicolon = null;
            }
            return new StmtReturn(returnToken, exp, semicolon);
        } else {
            Token semicolon;
            if (curToken().getType().equals(TokenType.SEMICN)) {
                semicolon = curToken();
                cur++;
            } else {
                semicolon = null;
            }
            return new StmtReturn(returnToken, semicolon);
        }
    }

    public StmtGetint parseStmtGetint() {
        LVal lVal = parseLVal();
        Token eql = curToken();
        cur++;
        Token getintToken = curToken();
        cur++;
        Token lParent = curToken();
        cur++;
        Token rParent;
        if (curToken().getType().equals(TokenType.RPARENT)) {
            rParent = curToken();
            cur++;
        } else {
            rParent = null;
        }
        Token semicolon;
        if (curToken().getType().equals(TokenType.SEMICN)) {
            semicolon = curToken();
            cur++;
        } else {
            semicolon = null;
        }

        return new StmtGetint(lVal, eql, getintToken, lParent, rParent, semicolon);
    }

    public StmtGetchar parseStmtGetchar() {
        LVal lVal = parseLVal();
        Token eql = curToken();
        cur++;
        Token getcharToken = curToken();
        cur++;
        Token lParent = curToken();
        cur++;
        Token rParent;
        if (curToken().getType().equals(TokenType.RPARENT)) {
            rParent = curToken();
            cur++;
        } else {
            rParent = null;
        }
        Token semicolon;
        if (curToken().getType().equals(TokenType.SEMICN)) {
            semicolon = curToken();
            cur++;
        } else {
            semicolon = null;
        }

        return new StmtGetchar(lVal, eql, getcharToken, lParent, rParent, semicolon);
    }

    public StmtPrintf parseStmtPrintf() {
        Token printfToken = curToken();
        cur++;
        Token lParent = curToken();
        cur++;
        Token stringConst = curToken();
        cur++;
        if (curToken().getType().equals(TokenType.COMMA)) {
            ArrayList<Token> commas = new ArrayList<>();
            ArrayList<Exp> exps = new ArrayList<>();
            while (curToken().getType().equals(TokenType.COMMA)) {
                commas.add(curToken());
                cur++;
                exps.add(parseExp());
            }
            Token rParent;
            if (curToken().getType().equals(TokenType.RPARENT)) {
                rParent = curToken();
                cur++;
            } else {
                rParent = null;
            }
            Token semicolon;
            if (curToken().getType().equals(TokenType.SEMICN)) {
                semicolon = curToken();
                cur++;
            } else {
                semicolon = null;
            }
            return new StmtPrintf(printfToken, lParent, stringConst, commas, exps, rParent, semicolon);
        } else {
            Token rParent;
            if (curToken().getType().equals(TokenType.RPARENT)) {
                rParent = curToken();
                cur++;
            } else {
                rParent = null;
            }
            Token semicolon;
            if (curToken().getType().equals(TokenType.SEMICN)) {
                semicolon = curToken();
                cur++;
            } else {
                semicolon = null;
            }
            return new StmtPrintf(printfToken, lParent, stringConst, rParent, semicolon);
        }
    }

    public StmtIf parseStmtIf() {
        Token ifToken = curToken();
        cur++;
        Token lParent = curToken();
        cur++;
        Cond cond = parseCond();
        Token rParent;
        if (curToken().getType().equals(TokenType.RPARENT)) {
            rParent = curToken();
            cur++;
        } else {
            rParent = null;
        }
        Stmt ifStmt = parseStmt();
        if (curToken().getType().equals(TokenType.ELSETK)) {
            Token elseToken = curToken();
            cur++;
            Stmt elseStmt = parseStmt();
            return new StmtIf(ifToken, lParent, cond, rParent, ifStmt, elseToken, elseStmt);
        } else {
            return new StmtIf(ifToken, lParent, cond, rParent, ifStmt);
        }
    }

    public StmtFor parseStmtFor() {
        Token forToken = curToken();
        cur++;
        Token lParent = curToken();
        cur++;
        ForStmt stmt1;
        if (!curToken().getType().equals(TokenType.SEMICN)) {
            stmt1 = parseForStmt();
        } else {
            stmt1 = null;
        }
        Token semi1 = curToken();
        cur++;
        Cond cond;
        if (!curToken().getType().equals(TokenType.SEMICN)) {
            cond = parseCond();
        } else {
            cond = null;
        }
        Token semi2 = curToken();
        cur++;
        ForStmt stmt3;
        if (!curToken().getType().equals(TokenType.RPARENT)) {
            stmt3 = parseForStmt();
        } else {
            stmt3 = null;
        }
        Token rParent;
        if (curToken().getType().equals(TokenType.RPARENT)) {
            rParent = curToken();
            cur++;
        } else {
            rParent = null;
        }
        Stmt stmt = parseStmt();
        return new StmtFor(forToken, lParent, stmt1, semi1, cond, semi2, stmt3, rParent, stmt);
    }

    public StmtExp parseStmtExp() {
        Exp exp = parseExp();
        Token semicolon;
        if (curToken().getType().equals(TokenType.SEMICN)) {
            semicolon = curToken();
            cur++;
        } else {
            semicolon = null;
        }
        return new StmtExp(exp, semicolon);
    }


    public ForStmt parseForStmt() {
        LVal lVal = parseLVal();
        Token eql = curToken();
        cur++;
        Exp exp = parseExp();
        return new ForStmt(lVal, eql, exp);
    }

    public Cond parseCond() {
        LOrExp lOrExp = parseLOrExp();
        return new Cond(lOrExp);
    }

    public LVal parseLVal() {
        Token ident = curToken();
        cur++;
        if (curToken().getType().equals(TokenType.LBRACK)) {
            Token lBracket = curToken();
            cur++;
            Exp exp = parseExp();
            Token rBracket;
            if (curToken().getType().equals(TokenType.RBRACK)) {
                rBracket = curToken();
                cur++;
            } else {
                rBracket = null;
            }
            return new LVal(ident, lBracket, exp, rBracket);
        } else {
            return new LVal(ident);
        }
    }

    public Exp parseExp() {
        return new Exp(parseAddExp());
    }

    public AddExp parseAddExp() {
        MulExp firstExp = parseMulExp();
        ArrayList<Token> operators = new ArrayList<Token>();
        ArrayList<MulExp> exps = new ArrayList<MulExp>();
        while (curToken().getType().equals(TokenType.PLUS) || curToken().getType().equals(TokenType.MINU)) {
            operators.add(curToken());
            cur++;
            exps.add(parseMulExp());
        }
        return new AddExp(firstExp, operators, exps);
    }

    public MulExp parseMulExp() {
        UnaryExp firstExp = parseUnaryExp();
        ArrayList<Token> operators = new ArrayList<Token>();
        ArrayList<UnaryExp> exps = new ArrayList<UnaryExp>();
        while (curToken().getType().equals(TokenType.MULT) || curToken().getType().equals(TokenType.DIV) || curToken().getType().equals(TokenType.MOD)) {
            operators.add(curToken());
            cur++;
            exps.add(parseUnaryExp());
        }
        return new MulExp(firstExp, operators, exps);
    }

    public UnaryExp parseUnaryExp() {
        Token first = curToken();
        Token second = null;
        if (cur < TokenStream.size() - 1) {
            second = TokenStream.get(cur + 1);
        }
        if (first.getType().equals(TokenType.IDENFR)) {
            if (second.getType().equals(TokenType.LPARENT)) {
                return new UnaryExp(parseUFuncExp());
            } else {
                return new UnaryExp(parsePrimaryExp());
            }
        } else if (first.getType().equals(TokenType.PLUS) || first.getType().equals(TokenType.MINU) || first.getType().equals(TokenType.NOT)) {
            return new UnaryExp(parseUOpExp());
        } else {
            return new UnaryExp(parsePrimaryExp());
        }
    }

    public UFuncExp parseUFuncExp() {
        Token ident = curToken();
        cur++;
        Token lParent = curToken();
        cur++;
        if (!curToken().getType().equals(TokenType.RPARENT) && !curToken().getType().equals(TokenType.SEMICN)) {
            FuncRParams funcRParams = parseFuncRParams();
            Token rParent;
            if (curToken().getType().equals(TokenType.RPARENT)) {
                rParent = curToken();
                cur++;
            } else {
                rParent = null;
            }
            return new UFuncExp(ident, lParent, funcRParams, rParent);
        } else {
            Token rParent;
            if (curToken().getType().equals(TokenType.RPARENT)) {
                rParent = curToken();
                cur++;
            } else {
                rParent = null;
            }
            return new UFuncExp(ident, lParent, rParent);
        }
    }

    public FuncRParams parseFuncRParams() {
        Exp firstExp = parseExp();
        if (curToken().getType().equals(TokenType.COMMA)) {
            ArrayList<Token> comma = new ArrayList<Token>();
            ArrayList<Exp> exps = new ArrayList<Exp>();
            while (curToken().getType().equals(TokenType.COMMA)) {
                comma.add(curToken());
                cur++;
                exps.add(parseExp());
            }
            return new FuncRParams(firstExp, comma, exps);
        } else {
            return new FuncRParams(firstExp);
        }
    }

    public PrimaryExp parsePrimaryExp() {
        if (curToken().getType().equals(TokenType.INTCON)) {
            return new PrimaryExp(parseNumber());
        } else if (curToken().getType().equals(TokenType.CHRCON)) {
            return new PrimaryExp(parseCharacter());
        } else if (curToken().getType().equals(TokenType.LPARENT)) {
            return new PrimaryExp(parsePParentExp());
        } else {
            return new PrimaryExp(parseLVal());
        }
    }

    public UOpExp parseUOpExp() {
        UnaryOp unaryOp = parseUnaryOp();
        UnaryExp unaryExp = parseUnaryExp();
        return new UOpExp(unaryOp, unaryExp);
    }

    public UnaryOp parseUnaryOp() {
        Token op = curToken();
        cur++;
        return new UnaryOp(op);
    }

    public PParentExp parsePParentExp() {
        Token lParent = curToken();
        cur++;
        Exp exp = parseExp();
        Token rParent;
        if (curToken().getType().equals(TokenType.RPARENT)) {
            rParent = curToken();
            cur++;
        } else {
            rParent = null;
        }
        return new PParentExp(lParent, exp, rParent);
    }

    public Number parseNumber() {
        Token number = curToken();
        cur++;
        return new Number(number);
    }

    public Character parseCharacter() {
        Token character = curToken();
        cur++;
        return new Character(character);
    }

    public LOrExp parseLOrExp() {
        LAndExp firstExp = parseLAndExp();
        ArrayList<Token> operators = new ArrayList<Token>();
        ArrayList<LAndExp> exps = new ArrayList<LAndExp>();
        while (curToken().getType().equals(TokenType.OR)) {
            operators.add(curToken());
            cur++;
            exps.add(parseLAndExp());
        }
        return new LOrExp(firstExp, operators, exps);
    }

    public LAndExp parseLAndExp() {
        EqExp firstExp = parseEqExp();
        ArrayList<Token> operators = new ArrayList<Token>();
        ArrayList<EqExp> exps = new ArrayList<EqExp>();
        while (curToken().getType().equals(TokenType.AND)) {
            operators.add(curToken());
            cur++;
            exps.add(parseEqExp());
        }
        return new LAndExp(firstExp, operators, exps);
    }

    public EqExp parseEqExp() {
        RelExp firstExp = parseRelExp();
        ArrayList<Token> operators = new ArrayList<Token>();
        ArrayList<RelExp> exps = new ArrayList<RelExp>();
        while (curToken().getType().equals(TokenType.EQL) || curToken().getType().equals(TokenType.NEQ)) {
            operators.add(curToken());
            cur++;
            exps.add(parseRelExp());
        }
        return new EqExp(firstExp, operators, exps);
    }
    
    public RelExp parseRelExp() {
        AddExp firstExp = parseAddExp();
        ArrayList<Token> operators = new ArrayList<Token>();
        ArrayList<AddExp> exps = new ArrayList<AddExp>();
        while (curToken().getType().equals(TokenType.LSS) || curToken().getType().equals(TokenType.LEQ) || curToken().getType().equals(TokenType.GRE) || curToken().getType().equals(TokenType.GEQ)) {
            operators.add(curToken());
            cur++;
            exps.add(parseAddExp());
        }
        return new RelExp(firstExp, operators, exps);
    }

}