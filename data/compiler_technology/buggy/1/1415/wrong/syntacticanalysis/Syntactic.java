package syntacticanalysis;

import lexicalanalysis.ErrorInfo;
import lexicalanalysis.Token;
import syntacticanalysis.node.Block;
import syntacticanalysis.node.BlockItem;
import syntacticanalysis.node.CompUnit;
import syntacticanalysis.node.LVal;
import syntacticanalysis.node.expression.*;
import syntacticanalysis.node.function.*;
import syntacticanalysis.node.init.*;
import syntacticanalysis.node.singal.CharacterTk;
import syntacticanalysis.node.singal.NumberTk;
import syntacticanalysis.node.singal.UnaryOp;
import syntacticanalysis.node.stmts.*;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Syntactic {
    private final ArrayList<Token> words;
    private int cur;
    private ErrorInfo errorInfo;

    public Syntactic(ArrayList<Token> words,ErrorInfo errorInfo) {
        this.words = words;
        this.cur = 0;
        this.errorInfo = errorInfo;
    }

    public void syntax_print() {
        CompUnit compUnit = parseCompUnit();
        if (!errorInfo.isEmpty()) {
            errorInfo.printError();
        } else {
            String content = compUnit.syntaxOutput();
            String filePath = "parser.txt"; // 指定文件路径
            try (FileWriter writer = new FileWriter(filePath)) {
                writer.write(content);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    public void move() {
        cur++;
    }

    public Token now() {
        return words.get(cur);
    }

    public Token getNext(int index) {
        return words.get(cur + index);
    }

    public Token getPre() {
        return words.get(cur - 1);
    }

    public boolean notEnd() {
        return cur < words.size();
    }

    public CompUnit parseCompUnit() {
        ArrayList<Decl> decls = parseDecls();
        ArrayList<FuncDef> funcDefs = parseFuncDefs();
        MainFuncDef mainFuncDef = parseMainFuncDef();
        return new CompUnit(decls, funcDefs, mainFuncDef);
    }

    public ArrayList<Decl> parseDecls() {
        ArrayList<Decl> decls = new ArrayList<>();
        while (notEnd()) {
            if (getNext(2).getType() != Token.Type.LPARENT) {
                decls.add(parseDecl());
            } else {
                break;
            }
        }
        return decls;
    }

    public Decl parseDecl() {
        Decl decl;
        if (now().getType() == Token.Type.CONSTTK) {
            Token constTk = now();
            move();
            Token btype = now();
            move();
            ArrayList<ConstDef> constDefs = parseConstDefs();
            if (now().getType() == Token.Type.SEMICN) {
                Token semiCn = now();
                move();
                decl = new ConstDecl(constTk, btype, constDefs, semiCn);
            } else {
                Token semiCn = new Token(Token.Type.SEMICN, ";", getPre().getLine());
                errorInfo.addError('i', getPre().getLine());
                decl = new ConstDecl(constTk, btype, constDefs, semiCn);
            }
        } else {
            Token btype = now();
            move();
            ArrayList<VarDef> varDefs = parseVarDefs();
            if (now().getType() == Token.Type.SEMICN) {
                Token semiCn = now();
                move();
                decl = new VarDecl(btype, varDefs, semiCn);
            } else {
                Token semiCn = new Token(Token.Type.SEMICN, ";", getPre().getLine());
                errorInfo.addError('i', getPre().getLine());
                decl = new VarDecl(btype, varDefs, semiCn);
            }
        }
        return decl;
    }

    public ArrayList<ConstDef> parseConstDefs() {
        ArrayList<ConstDef> constDefs = new ArrayList<>();
        constDefs.add(parseConstDef());
        while (notEnd() && now().getType() == Token.Type.COMMA) {
            move();
            constDefs.add(parseConstDef());
        }
        return constDefs;
    }

    public ConstDef parseConstDef() {
        Token ident = now();
        move();
        if (now().getType() == Token.Type.LBRACK) {
            Token lbrack = now();
            move();
            ConstExp constExp = parseConstExp();
            Token rbrack;
            if (now().getType() != Token.Type.RBRACK) {
                rbrack = new Token(Token.Type.RBRACK, "]", getPre().getLine());
                errorInfo.addError('k', getPre().getLine());
            } else {
                rbrack = now();
                move();
            }
            Token assign = now();
            move();
            return new ConstDef(ident, lbrack, constExp, rbrack, assign, parseConstInitVal());
        } else {
            Token assign = now();
            move();
            return new ConstDef(ident, null, null, null, assign, parseConstInitVal());
        }
    }

    public ConstExp parseConstExp() {
        return new ConstExp(parseAddExp());
    }

    public ConstInitVal parseConstInitVal() {
        if (now().getType() == Token.Type.LBRACE) {
            Token lbrace = now();
            move();
            ArrayList<ConstExp> constExps = new ArrayList<>();
            if (now().getType() != Token.Type.RBRACE) {
                constExps = parseConstExps();
            }
            Token rbrace = now();
            move();
            return new ConstInitVal2(lbrace, constExps, rbrace);
        } else if (now().getType() == Token.Type.STRCON) {
            Token stringConst = now();
            move();
            return new ConstInitVal3(stringConst);
        } else {
            return new ConstInitVal1(parseConstExp());
        }
    }

    public ArrayList<ConstExp> parseConstExps() {
        ArrayList<ConstExp> constExps = new ArrayList<>();
        constExps.add(parseConstExp());
        while (notEnd() && now().getType() == Token.Type.COMMA) {
            move();
            constExps.add(parseConstExp());
        }
        return constExps;
    }

    public ArrayList<VarDef> parseVarDefs() {
        ArrayList<VarDef> varDefs = new ArrayList<>();
        varDefs.add(parseVarDef());
        while (notEnd() && now().getType() == Token.Type.COMMA) {
            move();
            varDefs.add(parseVarDef());
        }
        return varDefs;
    }

    public VarDef parseVarDef() {
        Token ident = now();
        move();
        if (now().getType() == Token.Type.LBRACK) {
            Token lbrack = now();
            move();
            ConstExp constExp = parseConstExp();
            Token rbrack;
            if (now().getType() != Token.Type.RBRACK) {
                rbrack = new Token(Token.Type.RBRACK, "]", getPre().getLine());
                errorInfo.addError('k', getPre().getLine());
            } else {
                rbrack = now();
                move();
            }
            if (now().getType() == Token.Type.ASSIGN) {
                Token assign = now();
                move();
                return new VarDef(ident, lbrack, constExp, rbrack, assign, parseInitVal());
            } else {
                return new VarDef(ident, lbrack, constExp, rbrack, null, null);
            }
        } else {
            if (now().getType() == Token.Type.ASSIGN) {
                Token assign = now();
                move();
                return new VarDef(ident, null, null, null, assign, parseInitVal());
            } else {
                return new VarDef(ident, null, null, null, null, null);
            }
        }
    }

    public InitVal parseInitVal() {
        if (now().getType() == Token.Type.LBRACE) {
            Token lbrace = now();
            move();
            ArrayList<Exp> exps = parseExps();
            Token rbrace = now();
            move();
            return new InitVal2(lbrace, exps, rbrace);
        } else if (now().getType() == Token.Type.STRCON) {
            Token stringConst = now();
            move();
            return new InitVal3(stringConst);
        } else {
            return new InitVal1(parseExp());
        }
    }

    public ArrayList<FuncDef> parseFuncDefs() {
        ArrayList<FuncDef> funcDefs = new ArrayList<>();
        while (notEnd() && getNext(1).getType() == Token.Type.IDENFR) {
            funcDefs.add(parseFuncDef());
        }
        return funcDefs;
    }

    public FuncDef parseFuncDef() {
        FuncType funcType = parseFuncType();
        Token ident = now();
        move();
        Token lparent = now();
        move();
        FuncFParams funcFParams = null;
        if (now().getType() != Token.Type.RPARENT  && now().getType() != Token.Type.LBRACE) {
            funcFParams = parseFuncFParams();
        }
        Token rparent;
        if (now().getType() != Token.Type.RPARENT) {
            rparent = new Token(Token.Type.RPARENT, ")", getPre().getLine());
            errorInfo.addError('j', getPre().getLine());
        } else {
            rparent = now();
            move();
        }
        Block block = parseBlock();
        return new FuncDef(funcType, ident, lparent, funcFParams, rparent, block);
    }

    public FuncType parseFuncType() {
        Token type = now();
        move();
        return new FuncType(type);
    }

    public FuncFParams parseFuncFParams() {
        if (now().getType() == Token.Type.RPARENT) {
            return new FuncFParams(null);
        } else {
            ArrayList<FuncFParam> funcFParams = new ArrayList<>();
            funcFParams.add(parseFuncFParam());
            while (notEnd() && now().getType() == Token.Type.COMMA) {
                move();
                funcFParams.add(parseFuncFParam());
            }
            return new FuncFParams(funcFParams);
        }
    }

    public FuncFParam parseFuncFParam() {
        Token btype = now();
        move();
        Token ident = now();
        move();
        if (now().getType() == Token.Type.LBRACK) {
            Token lbrack = now();
            move();
            Token rbrack;
            if (now().getType() != Token.Type.RBRACK) {
                rbrack = new Token(Token.Type.RBRACK, "]", getPre().getLine());
                errorInfo.addError('k', getPre().getLine());
            } else {
                rbrack = now();
                move();
            }
            return new FuncFParam(btype, ident, lbrack, rbrack);
        } else {
            return new FuncFParam(btype, ident, null, null);
        }
    }

    public MainFuncDef parseMainFuncDef() {
        Token intTk = now();
        move();
        Token mainTk = now();
        move();
        Token lparent = now();
        move();
        Token rparent;
        if (now().getType() != Token.Type.RPARENT) {
            rparent = new Token(Token.Type.RPARENT, ")", getPre().getLine());
            errorInfo.addError('j', getPre().getLine());
        } else {
            rparent = now();
            move();
        }
        Block block = parseBlock();
        return new MainFuncDef(intTk, mainTk, lparent, rparent, block);
    }

    public Block parseBlock() {
        Token lbrace = now();
        move();
        if (now().getType() == Token.Type.RBRACE) {
            Token rbrace = now();
            move();
            return new Block(lbrace, null, rbrace);
        } else {
            ArrayList<BlockItem> blockItems = new ArrayList<>();
            blockItems.add(parseBlockItem());
            while (notEnd() && now().getType() != Token.Type.RBRACE) {
                blockItems.add(parseBlockItem());
            }
            Token rbrace = now();
            move();
            return new Block(lbrace, blockItems, rbrace);
        }
    }

    public BlockItem parseBlockItem() {
        if (now().getType() == Token.Type.CONSTTK || now().getType() == Token.Type.INTTK
                || now().getType() == Token.Type.CHARTK) {
            return parseDecl();
        } else {
            return parseStmt();
        }
    }

    public boolean isLval() {
        int curTmp = cur;
        while (curTmp < words.size()) {
            if (words.get(curTmp).getType() == Token.Type.ASSIGN
                    || words.get(curTmp).getType() == Token.Type.SEMICN) {
                break;
            }
            curTmp++;
        }
        return words.get(curTmp).getType() == Token.Type.ASSIGN;
    }

    public boolean isExp() {
        return now().getType() == Token.Type.IDENFR || now().getType() == Token.Type.PLUS
                || now().getType() == Token.Type.MINU || now().getType() == Token.Type.NOT
                || now().getType() == Token.Type.LPARENT || now().getType() == Token.Type.INTCON
                 || now().getType() == Token.Type.CHRCON;
    }

    public Stmt parseStmt() {
        if (now().getType() == Token.Type.IDENFR && isLval()) {
            LVal lval = parseLVal();
            Token assign = now();
            move();
            if (now().getType() == Token.Type.GETINTTK) {
                Token getIntTk = now();
                move();
                Token lparent = now();
                move();
                Token rparent;
                if (now().getType() != Token.Type.RPARENT) {
                    rparent = new Token(Token.Type.RPARENT, ")", getPre().getLine());
                    errorInfo.addError('j', getPre().getLine());
                } else {
                    rparent = now();
                    move();
                }
                Token semicn;
                if (now().getType() != Token.Type.SEMICN) {
                    semicn = new Token(Token.Type.SEMICN, ";", getPre().getLine());
                    errorInfo.addError('i', getPre().getLine());
                } else {
                    semicn = now();
                    move();
                }
                return new Stmt8(lval, assign, getIntTk, lparent, rparent, semicn);
            } else if (now().getType() == Token.Type.GETCHARTK) {
                Token getCharTk = now();
                move();
                Token lparent = now();
                move();
                Token rparent;
                if (now().getType() != Token.Type.RPARENT) {
                    rparent = new Token(Token.Type.RPARENT, ")", getPre().getLine());
                    errorInfo.addError('j', getPre().getLine());
                } else {
                    rparent = now();
                    move();
                }
                Token semicn;
                if (now().getType() != Token.Type.SEMICN) {
                    semicn = new Token(Token.Type.SEMICN, ";", getPre().getLine());
                    errorInfo.addError('i', getPre().getLine());
                } else {
                    semicn = now();
                    move();
                }
                return new Stmt9(lval, assign, getCharTk, lparent, rparent, semicn);
            } else {
                Exp exp = parseExp();
                Token semicn;
                if (now().getType() != Token.Type.SEMICN) {
                    semicn = new Token(Token.Type.SEMICN, ";", getPre().getLine());
                    errorInfo.addError('i', getPre().getLine()); } else {
                    semicn = now();
                    move(); }
                return new Stmt1(lval, assign, exp, semicn);
            }
        } else if (now().getType() == Token.Type.LBRACE) {
            Block block = parseBlock();
            return new Stmt3(block);
        } else if (now().getType() == Token.Type.IFTK) {
            Token ifTk = now();
            move();
            Token lparent = now();
            move();
            Cond cond = parseCond();
            Token rparent;
            if (now().getType() != Token.Type.RPARENT) {
                rparent = new Token(Token.Type.RPARENT, ")", getPre().getLine());
                errorInfo.addError('j', getPre().getLine());
            } else {
                rparent = now();
                move();
            }
            Stmt stmt1 = parseStmt();
            if (now().getType() == Token.Type.ELSETK) {
                Token elseTk = now();
                move();
                Stmt stmt2 = parseStmt();
                return new Stmt4(ifTk, lparent, cond, rparent, stmt1, elseTk, stmt2);
            } else {
                return new Stmt4(ifTk, lparent, cond, rparent, stmt1, null, null);
            }
        } else if (now().getType() == Token.Type.FORTK) {
            Token forTk = now();
            move();
            Token lparent = now();
            move();
            boolean flag1 = false;
            ForStmt forStmt1 = null;
            if (now().getType() != Token.Type.SEMICN) {
                forStmt1 = parseForStmt();
                flag1 = true;
            }
            Token semicn1 = now();
            move();
            boolean flag2 = false;
            Cond cond = null;
            if (now().getType() != Token.Type.SEMICN) {
                cond = parseCond();
                flag2 = true;
            }
            Token semicn2 = now();
            move();
            boolean flag3 = false;
            ForStmt forStmt2 = null;
            if (now().getType() != Token.Type.RPARENT) {
                forStmt2 = parseForStmt();
                flag3 = true;
            }
            Token rparent = now();
            move();
            Stmt stmt = parseStmt();
            return new Stmt5(forTk, lparent,flag1 ? forStmt1 : null,semicn1,flag2 ? cond : null
                    ,semicn2,flag3 ? forStmt2 : null,rparent,stmt);
        } else if (now().getType() == Token.Type.BREAKTK ||
                now().getType() == Token.Type.CONTINUETK) {
            Token breakcontinuetk = now();
            move();
            Token semicn;
            if (now().getType() != Token.Type.SEMICN) {
                semicn = new Token(Token.Type.SEMICN, ";", getPre().getLine());
                errorInfo.addError('i', getPre().getLine());
            } else {
                semicn = now();
                move();
            }
            return new Stmt6(breakcontinuetk, semicn);
        } else if (now().getType() == Token.Type.RETURNTK) {
            Token returnTk = now();
            move();
            if (now().getType() != Token.Type.SEMICN && isExp()) {
                Exp exp = parseExp();
                Token semicn;
                if (now().getType() != Token.Type.SEMICN) {
                    semicn = new Token(Token.Type.SEMICN, ";", getPre().getLine());
                    errorInfo.addError('i', getPre().getLine());
                } else {
                    semicn = now();
                    move();
                }
                return new Stmt7(returnTk, exp, semicn);
            } else {
                Token semicn;
                if (now().getType() != Token.Type.SEMICN) {
                    semicn = new Token(Token.Type.SEMICN, ";", getPre().getLine());
                    errorInfo.addError('i', getPre().getLine());
                } else {
                    semicn = now();
                    move();
                }
                return new Stmt7(returnTk, null, semicn);
            }
        } else if (now().getType() == Token.Type.PRINTFTK) {
            Token printfTk = now();
            move();
            Token lparent = now();
            move();
            Token strCon = now();
            move();
            if (now().getType() == Token.Type.COMMA) {
                move();
                ArrayList<Exp> exps = parseExps();
                Token rparent;
                if (now().getType() != Token.Type.RPARENT) {
                    rparent = new Token(Token.Type.RPARENT, ")", getPre().getLine());
                    errorInfo.addError('j', getPre().getLine());
                } else {
                    rparent = now();
                    move();
                }
                Token semicn;
                if (now().getType() != Token.Type.SEMICN) {
                    semicn = new Token(Token.Type.SEMICN, ";", getPre().getLine());
                    errorInfo.addError('i', getPre().getLine());
                } else {
                    semicn = now();
                    move();
                }
                return new Stmt10(printfTk, lparent, strCon, exps, rparent, semicn);
            } else {
                Token rparent;
                if (now().getType() != Token.Type.RPARENT) {
                    rparent = new Token(Token.Type.RPARENT, ")", getPre().getLine());
                    errorInfo.addError('j', getPre().getLine());
                } else {
                    rparent = now();
                    move();
                }
                Token semicn;
                if (now().getType() != Token.Type.SEMICN) {
                    semicn = new Token(Token.Type.SEMICN, ";", getPre().getLine());
                    errorInfo.addError('i', getPre().getLine());
                } else {
                    semicn = now();
                    move();
                }
                return new Stmt10(printfTk, lparent, strCon, null, rparent, semicn);
            }
        } else {
            if (now().getType() == Token.Type.SEMICN) {
                Token semicn = now();
                move();
                return new Stmt2(null, semicn);
            } else {
                Exp exp = null;
                if (isExp()) {
                    exp = parseExp();
                }
                Token semicn;
                if (now().getType() != Token.Type.SEMICN) {
                    semicn = new Token(Token.Type.SEMICN, ";", getPre().getLine());
                    errorInfo.addError('i', getPre().getLine());
                } else {
                    semicn = now();
                    move();
                }
                return new Stmt2(exp, semicn);
            }
        }
    }

    public ForStmt parseForStmt() {
        LVal lval = parseLVal();
        Token assign = now();
        move();
        Exp exp = parseExp();
        return new ForStmt(lval, assign, exp);
    }

    public LVal parseLVal() {
        Token ident = now();
        move();
        if (now().getType() == Token.Type.LBRACK) {
            Token lbrack = now();
            move();
            Exp exp = parseExp();
            Token rbrack;
            if (now().getType() != Token.Type.RBRACK) {
                rbrack = new Token(Token.Type.RBRACK, "]", getPre().getLine());
                errorInfo.addError('k', getPre().getLine());
            } else {
                rbrack = now();
                move();
            }
            return new LVal(ident, lbrack, exp, rbrack);
        } else {
            return new LVal(ident, null, null, null);
        }
    }

    public Cond parseCond() {
        return new Cond(parseLOrExp());
    }

    public LOrExp parseLOrExp() {
        ArrayList<LAndExp> landExps = new ArrayList<>();
        landExps.add(parseLAndExp());
        while (now().getType() == Token.Type.OR) {
            move();
            landExps.add(parseLAndExp());
        }
        return new LOrExp(landExps);
    }

    public LAndExp parseLAndExp() {
        ArrayList<EqExp> eqExps = new ArrayList<>();
        eqExps.add(parseEqExp());
        while (now().getType() == Token.Type.AND) {
            move();
            eqExps.add(parseEqExp());
        }
        return new LAndExp(eqExps);
    }

    public EqExp parseEqExp() {
        ArrayList<RelExp> relExps = new ArrayList<>();
        ArrayList<Token> ops = new ArrayList<>();
        relExps.add(parseRelExp());
        while (now().getType() == Token.Type.EQL || now().getType() == Token.Type.NEQ) {
            ops.add(now());
            move();
            relExps.add(parseRelExp());
        }
        return new EqExp(relExps, ops);
    }

    public RelExp parseRelExp() {
        ArrayList<AddExp> addExps = new ArrayList<>();
        ArrayList<Token> ops = new ArrayList<>();
        addExps.add(parseAddExp());
        while (now().getType() == Token.Type.LSS || now().getType() == Token.Type.LEQ
                || now().getType() == Token.Type.GRE || now().getType() == Token.Type.GEQ) {
            ops.add(now());
            move();
            addExps.add(parseAddExp());
        }
        return new RelExp(addExps, ops);
    }

    public AddExp parseAddExp() {
        ArrayList<MulExp> mulExps = new ArrayList<>();
        ArrayList<Token> ops = new ArrayList<>();
        mulExps.add(parseMulExp());
        while (now().getType() == Token.Type.PLUS || now().getType() == Token.Type.MINU) {
            ops.add(now());
            move();
            mulExps.add(parseMulExp());
        }
        return new AddExp(mulExps, ops);
    }

    public MulExp parseMulExp() {
        ArrayList<UnaryExp> unaryExps = new ArrayList<>();
        ArrayList<Token> ops = new ArrayList<>();
        unaryExps.add(parseUnaryExp());
        while (now().getType() == Token.Type.MULT || now().getType() == Token.Type.DIV
                || now().getType() == Token.Type.MOD) {
            ops.add(now());
            move();
            unaryExps.add(parseUnaryExp());
        }
        return new MulExp(unaryExps, ops);
    }

    public UnaryExp parseUnaryExp() {
        if (now().getType() == Token.Type.PLUS || now().getType() == Token.Type.MINU
                || now().getType() == Token.Type.NOT) {
            UnaryOp unaryOp = new UnaryOp(now());
            move();
            UnaryExp unaryExp = parseUnaryExp();
            return new UnaryExp3(unaryOp,unaryExp);
        } else if (now().getType() == Token.Type.IDENFR) {
            if (getNext(1).getType() == Token.Type.LPARENT) {
                Token ident = now();
                move();
                Token lparent = now();
                move();
                if (now().getType() != Token.Type.RPARENT && now().getType() != Token.Type.SEMICN) {
                    FuncRParams funcRParams = parseFuncRParams();
                    Token rparent;
                    if (now().getType() != Token.Type.RPARENT) {
                        rparent = new Token(Token.Type.RPARENT, ")", getPre().getLine());
                        errorInfo.addError('j', getPre().getLine());
                    } else {
                        rparent = now();
                        move();
                    }
                    return new UnaryExp2(ident, lparent, funcRParams, rparent);
                } else {
                    Token rparent;
                    if (now().getType() != Token.Type.RPARENT) {
                        rparent = new Token(Token.Type.RPARENT, ")", getPre().getLine());
                        errorInfo.addError('j', getPre().getLine());
                    } else {
                        rparent = now();
                        move();
                    }
                    return new UnaryExp2(ident, lparent, null, rparent);
                }
            } else {
                return new UnaryExp1(parsePrimaryExp());
            }
        } else {
            return new UnaryExp1(parsePrimaryExp());
        }
    }

    public FuncRParams parseFuncRParams() {
        ArrayList<Exp> exps = parseExps();
        return new FuncRParams(exps);
    }

    public PrimaryExp parsePrimaryExp() {
        if (now().getType() == Token.Type.LPARENT) {
            Token lparent = now();
            move();
            Exp exp = parseExp();
            Token rparent;
            if (now().getType() != Token.Type.RPARENT) {
                rparent = new Token(Token.Type.RPARENT, ")", getPre().getLine());
                errorInfo.addError('j', getPre().getLine());
            } else {
                rparent = now();
                move();
            }
            return new PrimaryExp1(lparent, exp, rparent);
        } else if (now().getType() == Token.Type.IDENFR) {
            return new PrimaryExp2(parseLVal());
        } else if (now().getType() == Token.Type.INTCON) {
            return new PrimaryExp3(parseNumberTk());
        } else  { //if (now().getType() == Token.Type.CHRCON)
            return new PrimaryExp4(parseCharacterTk());
        }
    }

    public NumberTk parseNumberTk() {
        Token intCon = now();
        move();
        return new NumberTk(intCon);
    }

    public CharacterTk parseCharacterTk() {
        Token chrCon = now();
        move();
        return new CharacterTk(chrCon);
    }

    public ArrayList<Exp> parseExps() {
        ArrayList<Exp> exps = new ArrayList<>();
        exps.add(parseExp());
        while (now().getType() == Token.Type.COMMA) {
            move();
            exps.add(parseExp());
        }
        return exps;
    }

    public Exp parseExp() {
        return new Exp(parseAddExp());
    }
}
