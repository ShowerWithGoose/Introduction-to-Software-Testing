package Parser;

import Parser.Decl.*;
import Parser.Expr.*;
import Parser.Expr.Character;
import Parser.Expr.Number;
import Parser.FuncDef.*;
import Parser.Lexer.ErrorLog;
import Parser.Lexer.Token;
import Parser.Stmt.*;

import java.util.*;

public class Parser {
    private ArrayList<Token> tokens;
    private ArrayList<ErrorLog> errorLogs;
    private CompUnit compUnit;
    private int pos;


    public Parser(ArrayList<Token> tokens) {
        ArrayList<ErrorLog> newErrorLogs = new ArrayList<>();
        this.tokens = tokens;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens.get(i).isError()) {
                ErrorLog errorLog = new ErrorLog(tokens.get(i).getLineNum(), 'a', i);
                newErrorLogs.add(errorLog);
            }
        }
        this.errorLogs = newErrorLogs;
        this.pos = 0;
        this.compUnit = null;
        parseCompUnit();
    }

    public boolean isEnd() {
        if (pos >= tokens.size()) {
            return true;
        } else {
            return false;
        }
    }

    public Token getToken() {
        if (!isEnd()) {
            return this.tokens.get(pos);
        } else {
            return null;
        }
    }

    public void next() {
        pos++;
    }

    public void back() {
        if (pos > 0) {
            pos--;
        }
    }

    public void backto(int ans) {
        pos = ans;
    }

    public CompUnit getCompUnit() {
        return this.compUnit;
    }

    public void parseCompUnit() {
        ArrayList<Decl> decls = new ArrayList<>();
        ArrayList<FuncDef> funcDefs = new ArrayList<>();
        next();
        next();//验证第三个Token是不是（
        Token token1 = getToken();
        if (!token1.getType().equals(Token.TokenType.LPARENT.toString())) {//处理Decls
            while (!isEnd()) {
                back();
                back();
                decls.add(parseDecl());
                next();
                next();
                if (getToken().getType().equals(Token.TokenType.LPARENT.toString())) {
                    back();
                    back();
                    break;
                }
            }
        } else {
            back();
            back();
        }
        next();//验证第二个Token是不是MAINTK
        Token token2 = getToken();
        if (!token2.getType().equals(Token.TokenType.MAINTK.toString())) {//处理Decls
            while (!isEnd()) {
                back();
                funcDefs.add(parseFuncDef());
                next();
                if (getToken().getType().equals(Token.TokenType.MAINTK.toString())) {
                    back();
                    break;
                }
            }
        } else {
            back();
        }
        MainFuncDef mainFuncDef = parseMainFuncDef();
        this.compUnit = new CompUnit(decls, funcDefs, mainFuncDef);
    }

    public Decl parseDecl() {
        Syntax syntax;                  //ConstDecl | VarDecl
        if (getToken().getType().equals(Token.TokenType.CONSTTK.toString())) {
            syntax = parseConstDecl();
        } else {
            syntax = parseVarDecl();
        }
        return new Decl(syntax);
    }

    public ConstDecl parseConstDecl() {
        ArrayList<Syntax> syntaxes = new ArrayList<>();
        syntaxes.add(getToken());
        next();
        syntaxes.add(parseBType());
        syntaxes.add(parseConstDef());
        while (getToken().getType().equals(Token.TokenType.COMMA.toString())) {
            syntaxes.add(getToken());
            next();
            syntaxes.add(parseConstDef());
        }
        if (getToken().getType().equals(Token.TokenType.SEMICN.toString())) {
            syntaxes.add(getToken());
            next();
        } else {//没有分号
            back();
            ErrorLog errorLog = new ErrorLog(getToken().getLineNum(), 'i', pos);
            errorLogs.add(errorLog);
            next();
        }
        return new ConstDecl(syntaxes, syntaxes.size());
    }

    public ConstDef parseConstDef() {
        ArrayList<Syntax> syntaxes = new ArrayList<>();
        syntaxes.add(getToken());
        next();//Ident
        if (getToken().getType().equals(Token.TokenType.LBRACK.toString())) {
            syntaxes.add(getToken());
            next();//[
            syntaxes.add(parseConstExp());
            if (getToken().getType().equals(Token.TokenType.RBRACK.toString())) {
                syntaxes.add(getToken());
                next();
            } else {//没有中括号
                back();
                ErrorLog errorLog = new ErrorLog(getToken().getLineNum(), 'k', pos);
                errorLogs.add(errorLog);
                next();
            }
        }
        syntaxes.add(getToken());//=
        next();
        syntaxes.add(parseConstInitVal());
        return new ConstDef(syntaxes);
    }

    public BType parseBType() {
        Token token = getToken();
        next();
        return new BType(token);
    }

    public ConstInitVal parseConstInitVal() {
        ArrayList<Syntax> syntaxes = new ArrayList<>();
        if (getToken().getType().equals(Token.TokenType.STRCON.toString())) {
            syntaxes.add(getToken());
            next();
        } else if (getToken().getType().equals(Token.TokenType.LBRACE.toString())) {
            syntaxes.add(getToken());
            next();
            if (getToken().getType().equals(Token.TokenType.RBRACE.toString())) {
                syntaxes.add(getToken());
                next();
            } else {
                syntaxes.add(parseConstExp());
                while (!getToken().getType().equals(Token.TokenType.RBRACE.toString())) {
                    syntaxes.add(getToken());
                    next();
                    syntaxes.add(parseConstExp());
                }
                syntaxes.add(getToken());
                next();
            }

        } else {
            syntaxes.add(parseConstExp());
        }
        return new ConstInitVal(syntaxes);
    }

    public VarDecl parseVarDecl() {
        ArrayList<Syntax> syntaxes = new ArrayList<>();
        syntaxes.add(parseBType());//Btype
        syntaxes.add(parseVarDef());
        while (getToken().getType().equals(Token.TokenType.COMMA.toString())) {
            syntaxes.add(getToken());
            next();
            syntaxes.add(parseVarDef());
        }
        if (getToken().getType().equals(Token.TokenType.SEMICN.toString())) {
            syntaxes.add(getToken());
            next();
        } else {//没有分号
            back();
            ErrorLog errorLog = new ErrorLog(getToken().getLineNum(), 'i', pos);
            errorLogs.add(errorLog);
            next();
        }
        return new VarDecl(syntaxes);
    }

    public VarDef parseVarDef() {
        ArrayList<Syntax> syntaxes = new ArrayList<>();
        syntaxes.add(getToken());
        next();//Ident
        if (getToken().getType().equals(Token.TokenType.LBRACK.toString())) {
            syntaxes.add(getToken());
            next();//[
            syntaxes.add(parseConstExp());
            if (getToken().getType().equals(Token.TokenType.RBRACK.toString())) {
                syntaxes.add(getToken());
                next();
            } else {//没有中括号
                back();
                ErrorLog errorLog = new ErrorLog(getToken().getLineNum(), 'k', pos);
                errorLogs.add(errorLog);
                next();
            }
        }
        if (getToken().getType().equals(Token.TokenType.ASSIGN.toString())) {
            syntaxes.add(getToken());//=
            next();
            syntaxes.add(parseInitVal());
        }
        return new VarDef(syntaxes);
    }

    public InitVal parseInitVal() {
        ArrayList<Syntax> syntaxes = new ArrayList<>();
        if (getToken().getType().equals(Token.TokenType.STRCON.toString())) {
            syntaxes.add(getToken());
            next();
        } else if (getToken().getType().equals(Token.TokenType.LBRACE.toString())) {
            syntaxes.add(getToken());
            next();
            if (getToken().getType().equals(Token.TokenType.RBRACE.toString())) {
                syntaxes.add(getToken());
                next();
            } else {
                syntaxes.add(parseExp());
                while (!getToken().getType().equals(Token.TokenType.RBRACE.toString())) {
                    syntaxes.add(getToken());
                    next();
                    syntaxes.add(parseExp());
                }
                syntaxes.add(getToken());
                next();
            }
        } else {
            syntaxes.add(parseExp());
        }
        return new InitVal(syntaxes);
    }

    public MainFuncDef parseMainFuncDef() {
        ArrayList<Syntax> syntaxes = new ArrayList<>();
        for (int i = 0; i < 3; i++) {//int main(
            syntaxes.add(getToken());
            next();
        }
        if (getToken().getType().equals(Token.TokenType.RPARENT.toString())) {
            syntaxes.add(getToken());
            next();
        } else {//没有小括号
            back();
            ErrorLog errorLog = new ErrorLog(getToken().getLineNum(), 'j', pos);
            errorLogs.add(errorLog);
            next();
        }
        syntaxes.add(parseBlock());
        return new MainFuncDef(syntaxes);
    }

    public Block parseBlock() {
        ArrayList<Syntax> syntaxes = new ArrayList<>();
        syntaxes.add(getToken());//{
        next();
        while (!getToken().getType().equals(Token.TokenType.RBRACE.toString())) {
            syntaxes.add(parseBlockItem());
        }
        syntaxes.add(getToken());//}
        next();
        return new Block(syntaxes);
    }

    public BlockItem parseBlockItem() {
        ArrayList<Syntax> syntaxes = new ArrayList<>();
        if (getToken().getType().equals(Token.TokenType.INTTK.toString())
                || getToken().getType().equals(Token.TokenType.CHARTK.toString())
                || getToken().getType().equals(Token.TokenType.CONSTTK.toString())) {
            syntaxes.add(parseDecl());
        } else {
            syntaxes.add(parseStmt());
        }
        return new BlockItem(syntaxes);
    }

    public Stmt parseStmt() {
        ArrayList<Syntax> syntaxes = new ArrayList<>();
        if (getToken().getType().equals(Token.TokenType.IDENFR.toString())) {//LVal
            int flag = 0;
            int initPos = pos;
            if (getToken().getType().equals(Token.TokenType.SEMICN.toString())) {//只有分号
                flag = 1;
                syntaxes.add(getToken());
                next();
                return new Stmt(syntaxes);
            }
            parseExp();
            if (getToken().getType().equals(Token.TokenType.ASSIGN.toString())) {//有等号
                flag = 1;
                next();
            }
            backto(initPos);
            if (flag == 0) { //这种符合[Exp];的情况，单独讨论一下
                syntaxes.add(parseExp());
                if (getToken().getType().equals(Token.TokenType.SEMICN.toString())) {
                    syntaxes.add(getToken());
                    next();
                } else {//没有分号
                    back();
                    ErrorLog errorLog = new ErrorLog(getToken().getLineNum(), 'i', pos);
                    errorLogs.add(errorLog);
                    next();
                }
                return new Stmt(syntaxes);
            }
            syntaxes.add(parseLVal());
            syntaxes.add(getToken());// '='
            next();

            if (getToken().getType().equals(Token.TokenType.GETINTTK.toString())
                    || getToken().getType().equals(Token.TokenType.GETCHARTK.toString())) {
                //LVal '=' 'getint''('')'';' (1)
                //| LVal '=' 'getchar''('')'';' (2)
                syntaxes.add(getToken());// 'getint'||'getchar'
                next();
                syntaxes.add(getToken());// (
                next();
                if (getToken().getType().equals(Token.TokenType.RPARENT.toString())) {
                    syntaxes.add(getToken());
                    next();
                } else {//没有小括号
                    back();
                    ErrorLog errorLog = new ErrorLog(getToken().getLineNum(), 'j', pos);
                    errorLogs.add(errorLog);
                    next();
                }
                if (getToken().getType().equals(Token.TokenType.SEMICN.toString())) {
                    syntaxes.add(getToken());
                    next();
                } else {//没有分号
                    back();
                    ErrorLog errorLog = new ErrorLog(getToken().getLineNum(), 'i', pos);
                    errorLogs.add(errorLog);
                    next();
                }
            } else {// Stmt → LVal '=' Exp ';'  (3)
                syntaxes.add(parseExp());
                if (getToken().getType().equals(Token.TokenType.SEMICN.toString())) {
                    syntaxes.add(getToken());
                    next();
                } else {//没有分号
                    back();
                    ErrorLog errorLog = new ErrorLog(getToken().getLineNum(), 'i', pos);
                    errorLogs.add(errorLog);
                    next();
                }
            }
        } else if (getToken().getType().equals(Token.TokenType.LBRACE.toString())) { //Block (4)
            syntaxes.add(parseBlock());
        } else if (getToken().getType().equals(Token.TokenType.BREAKTK.toString())) {//'break' ';' (5) {
            syntaxes.add(getToken());// break
            next();
            if (getToken().getType().equals(Token.TokenType.SEMICN.toString())) {
                syntaxes.add(getToken());
                next();
            } else {//没有分号
                back();
                ErrorLog errorLog = new ErrorLog(getToken().getLineNum(), 'i', pos);
                errorLogs.add(errorLog);
                next();
            }
        } else if (getToken().getType().equals(Token.TokenType.CONTINUETK.toString())) {//'continue' ';' (6) {
            syntaxes.add(getToken());// continue
            next();
            if (getToken().getType().equals(Token.TokenType.SEMICN.toString())) {
                syntaxes.add(getToken());
                next();
            } else {//没有分号
                back();
                ErrorLog errorLog = new ErrorLog(getToken().getLineNum(), 'i', pos);
                errorLogs.add(errorLog);
                next();
            }
        } else if (getToken().getType().equals(Token.TokenType.RETURNTK.toString())) {//'return' [Exp] ';' (7)
            syntaxes.add(getToken());// return
            next();
            if (!getToken().getType().equals(Token.TokenType.SEMICN.toString())) {
                syntaxes.add(parseExp());
            }
            if (getToken().getType().equals(Token.TokenType.SEMICN.toString())) {
                syntaxes.add(getToken());
                next();
            } else {//没有分号
                back();
                ErrorLog errorLog = new ErrorLog(getToken().getLineNum(), 'i', pos);
                errorLogs.add(errorLog);
                next();
            }
        } else if (getToken().getType().equals(Token.TokenType.PRINTFTK.toString())) {
            // 'printf''('StringConst {','Exp}')'';' (8)
            syntaxes.add(getToken());// printf
            next();
            syntaxes.add(getToken());// (
            next();
            syntaxes.add(getToken());// StringConst
            next();
            while (getToken().getType().equals(Token.TokenType.COMMA.toString())) {
                syntaxes.add(getToken());// ,
                next();
                syntaxes.add(parseExp());
            }
            if (getToken().getType().equals(Token.TokenType.RPARENT.toString())) {
                syntaxes.add(getToken());
                next();
            } else {//没有小括号
                back();
                ErrorLog errorLog = new ErrorLog(getToken().getLineNum(), 'j', pos);
                errorLogs.add(errorLog);
                next();
            }
            if (getToken().getType().equals(Token.TokenType.SEMICN.toString())) {
                syntaxes.add(getToken());
                next();
            } else {//没有分号
                back();
                ErrorLog errorLog = new ErrorLog(getToken().getLineNum(), 'i', pos);
                errorLogs.add(errorLog);
                next();
            }
        } else if (getToken().getType().equals(Token.TokenType.IFTK.toString())) {
            // 'if' '(' Cond ')' Stmt [ 'else' Stmt ] (9)
            syntaxes.add(getToken());// if
            next();
            syntaxes.add(getToken());// (
            next();
            syntaxes.add(parseCond());
            if (getToken().getType().equals(Token.TokenType.RPARENT.toString())) {
                syntaxes.add(getToken());
                next();
            } else {//没有小括号
                back();
                ErrorLog errorLog = new ErrorLog(getToken().getLineNum(), 'j', pos);
                errorLogs.add(errorLog);
                next();
            }
            syntaxes.add(parseStmt());
            if (getToken().getType().equals(Token.TokenType.ELSETK.toString())) {
                syntaxes.add(getToken());// else
                next();
                syntaxes.add(parseStmt());
            }
        } else if (getToken().getType().equals(Token.TokenType.FORTK.toString())) {
            // 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt (10)
            syntaxes.add(getToken());// for
            next();
            syntaxes.add(getToken());// (
            next();
            if (getToken().getType().equals(Token.TokenType.IDENFR.toString())) {
                syntaxes.add(parseForStmt());
            }
            if (getToken().getType().equals(Token.TokenType.SEMICN.toString())) {
                syntaxes.add(getToken());
                next();
            } else {//没有分号
                back();
                ErrorLog errorLog = new ErrorLog(getToken().getLineNum(), 'i', pos);
                errorLogs.add(errorLog);
                next();
            }
            if (!getToken().getType().equals(Token.TokenType.SEMICN.toString())) {
                syntaxes.add(parseCond());
            }
            if (getToken().getType().equals(Token.TokenType.SEMICN.toString())) {
                syntaxes.add(getToken());
                next();
            } else {//没有分号
                back();
                ErrorLog errorLog = new ErrorLog(getToken().getLineNum(), 'i', pos);
                errorLogs.add(errorLog);
                next();
            }
            if (getToken().getType().equals(Token.TokenType.RPARENT.toString())) {
                syntaxes.add(getToken());
                next();
            } else {
                syntaxes.add(parseForStmt());
                if (getToken().getType().equals(Token.TokenType.RPARENT.toString())) {
                    syntaxes.add(getToken());
                    next();
                } else {//没有小括号
                    back();
                    ErrorLog errorLog = new ErrorLog(getToken().getLineNum(), 'j', pos);
                    errorLogs.add(errorLog);
                    next();
                }
            }

            syntaxes.add(parseStmt());
        } else { //   [Exp] ';'(11)
            if (getToken().getType().equals(Token.TokenType.SEMICN.toString())) { //只有;
                syntaxes.add(getToken());
                next();
                return new Stmt(syntaxes);
            }
            syntaxes.add(parseExp());
            if (getToken().getType().equals(Token.TokenType.SEMICN.toString())) {
                syntaxes.add(getToken());
                next();
            } else {//没有分号
                back();
                ErrorLog errorLog = new ErrorLog(getToken().getLineNum(), 'i', pos);
                errorLogs.add(errorLog);
                next();
            }
        }

        return new Stmt(syntaxes);
    }

    public ForStmt parseForStmt() {
        ArrayList<Syntax> syntaxes = new ArrayList<>();
        syntaxes.add(parseLVal());
        syntaxes.add(getToken()); // =
        next();
        syntaxes.add(parseExp());
        return new ForStmt(syntaxes);
    }

    public Cond parseCond() {
        ArrayList<Syntax> syntaxes = new ArrayList<>();
        syntaxes.add(parseLOrExp());
        return new Cond(syntaxes);
    }

    public FuncDef parseFuncDef() {
        ArrayList<Syntax> syntaxes = new ArrayList<>();
        syntaxes.add(parseFuncType());
        syntaxes.add(getToken());//Ident
        next();
        syntaxes.add(getToken());//(
        next();
        if (getToken().getType().equals(Token.TokenType.CHARTK.toString())
                || getToken().getType().equals(Token.TokenType.INTTK.toString())) {
            syntaxes.add(parseFuncFParams());
        }
        if (getToken().getType().equals(Token.TokenType.RPARENT.toString())) {
            syntaxes.add(getToken());
            next();
        } else {//没有小括号
            back();
            ErrorLog errorLog = new ErrorLog(getToken().getLineNum(), 'j', pos);
            errorLogs.add(errorLog);
            next();
        }
        syntaxes.add(parseBlock());
        return new FuncDef(syntaxes);
    }

    public FuncType parseFuncType() {
        ArrayList<Syntax> syntaxes = new ArrayList<>();
        syntaxes.add(getToken());// 'void' | 'int' | 'char'
        next();
        return new FuncType(syntaxes);
    }

    public FuncFParams parseFuncFParams() {
        ArrayList<Syntax> syntaxes = new ArrayList<>();
        syntaxes.add(parseFuncFParam());
        if (getToken().getType().equals(Token.TokenType.COMMA.toString())) {
            while (getToken().getType().equals(Token.TokenType.COMMA.toString())) {
                syntaxes.add(getToken());//[
                next();
                syntaxes.add(parseFuncFParam());
            }
        }
        return new FuncFParams(syntaxes);
    }

    public FuncFParam parseFuncFParam() {
        ArrayList<Syntax> syntaxes = new ArrayList<>();
        syntaxes.add(parseBType());//Btype
        syntaxes.add(getToken());//Ident
        next();
        if (getToken().getType().equals(Token.TokenType.LBRACK.toString())) {
            syntaxes.add(getToken());//[
            next();
            if (getToken().getType().equals(Token.TokenType.RBRACK.toString())) {
                syntaxes.add(getToken());
                next();
            } else {//没有中括号
                back();
                ErrorLog errorLog = new ErrorLog(getToken().getLineNum(), 'k', pos);
                errorLogs.add(errorLog);
                next();
            }
        }
        return new FuncFParam(syntaxes);
    }

    public ConstExp parseConstExp() {
        ArrayList<Syntax> syntaxes = new ArrayList<>();
        syntaxes.add(parseAddExp());//IntConst
        return new ConstExp(syntaxes);
    }

    public Exp parseExp() {
        ArrayList<Syntax> syntaxes = new ArrayList<>();
        int initPos = pos;
        ArrayList<Integer> posList = new ArrayList<>();
        parseAddExp();
        for (int i = initPos; i < pos; i++) {
            if (tokens.get(i).getType().equals(Token.TokenType.PLUS.toString())
                    || tokens.get(i).getType().equals(Token.TokenType.MINU.toString())) {
                tokens.get(i).setUnused();
            }
        }
        backto(initPos);
        syntaxes.add(parseAddExp());//IntConst
        return new Exp(syntaxes);
    }

    public Number parseNumber() {
        ArrayList<Syntax> syntaxes = new ArrayList<>();
        syntaxes.add(getToken());//IntConst
        next();
        return new Number(syntaxes);
    }

    public Character parseCharacter() {
        ArrayList<Syntax> syntaxes = new ArrayList<>();
        syntaxes.add(getToken());//CharConst
        next();
        return new Character(syntaxes);
    }

    public LVal parseLVal() {
        ArrayList<Syntax> syntaxes = new ArrayList<>();
        syntaxes.add(getToken());//Ident
        next();
        if (getToken().getType().equals(Token.TokenType.LBRACK.toString())) {
            syntaxes.add(getToken());//[
            next();
            syntaxes.add(parseExp());
            if (getToken().getType().equals(Token.TokenType.RBRACK.toString())) {
                syntaxes.add(getToken());
                next();
            } else {//没有中括号
                back();
                ErrorLog errorLog = new ErrorLog(getToken().getLineNum(), 'k', pos);
                errorLogs.add(errorLog);
                next();
            }
        }
        return new LVal(syntaxes);
    }

    public PrimaryExp parsePrimaryExp() {
        ArrayList<Syntax> syntaxes = new ArrayList<>();
        if (getToken().getType().equals(Token.TokenType.LPARENT.toString())) { //'(' Exp ')'
            syntaxes.add(getToken());//(
            next();
            syntaxes.add(parseExp());
            if (getToken().getType().equals(Token.TokenType.RPARENT.toString())) {
                syntaxes.add(getToken());
                next();
            } else {//没有小括号
                back();
                ErrorLog errorLog = new ErrorLog(getToken().getLineNum(), 'j', pos);
                errorLogs.add(errorLog);
                next();
            }
        } else if (getToken().getType().equals(Token.TokenType.IDENFR.toString())) { // LVal
            syntaxes.add(parseLVal());
        } else if (getToken().getType().equals(Token.TokenType.INTCON.toString())) { // Number
            syntaxes.add(parseNumber());
        } else if (getToken().getType().equals(Token.TokenType.CHRCON.toString())) { // Number
            syntaxes.add(parseCharacter());
        }
        return new PrimaryExp(syntaxes);
    }

    public UnaryExp parseUnaryExp() {
        ArrayList<Syntax> syntaxes = new ArrayList<>();
        next();
        Token token = getToken();
        back();
        if (getToken().getType().equals(Token.TokenType.IDENFR.toString())
                && token.getType().equals(Token.TokenType.LPARENT.toString())) { //Ident '(' [FuncRParams] ')'
            syntaxes.add(getToken());//Ident
            next();
            syntaxes.add(getToken());//(
            next();
            if (getToken().getType().equals(Token.TokenType.RPARENT.toString())) {
                syntaxes.add(getToken());
                next();
            } else {
                syntaxes.add(parseFuncRParams());
                if (getToken().getType().equals(Token.TokenType.RPARENT.toString())) {
                    syntaxes.add(getToken());
                    next();
                } else {//没有小括号
                    back();
                    ErrorLog errorLog = new ErrorLog(getToken().getLineNum(), 'j', pos);
                    errorLogs.add(errorLog);
                    next();
                }
            }

        } else if (getToken().getType().equals(Token.TokenType.PLUS.toString())
                || getToken().getType().equals(Token.TokenType.MINU.toString())
                || getToken().getType().equals(Token.TokenType.NOT.toString())) { // UnaryOp UnaryExp
            syntaxes.add(parseUnaryOp());
            syntaxes.add(parseUnaryExp());
        } else { //primaryExp
            syntaxes.add(parsePrimaryExp());
        }
        return new UnaryExp(syntaxes);
    }

    public UnaryOp parseUnaryOp() {
        ArrayList<Syntax> syntaxes = new ArrayList<>();
        syntaxes.add(getToken());//'+' | '−' | '!'
        next();
        return new UnaryOp(syntaxes);
    }

    public FuncRParams parseFuncRParams() {
        ArrayList<Syntax> syntaxes = new ArrayList<>();
        syntaxes.add(parseExp());
        while (getToken().getType().equals(Token.TokenType.COMMA.toString())) {
            syntaxes.add(getToken()); //,
            next();
            syntaxes.add(parseExp());
        }
        return new FuncRParams(syntaxes);
    }

    public MulExp parseMulExp() {
        ArrayList<Syntax> syntaxes = new ArrayList<>();
        ArrayList<Syntax> tmpsyntaxes = new ArrayList<>();
        int initPos = pos;
        tmpsyntaxes.add(parseUnaryExp());
        while (!getToken().isUsed() &&
                (getToken().getType().equals(Token.TokenType.MULT.toString())
                        || getToken().getType().equals(Token.TokenType.DIV.toString())
                        || getToken().getType().equals(Token.TokenType.MOD.toString()))) {
            tmpsyntaxes.add(getToken()); //('*' | '/' | '%')
            next();
            tmpsyntaxes.add(parseUnaryExp());
        }
        while (getToken().getType().equals(Token.TokenType.MULT.toString())
                || getToken().getType().equals(Token.TokenType.DIV.toString())
                || getToken().getType().equals(Token.TokenType.MOD.toString())) {
            //('*' | '/' | '%')
            next();
            parseUnaryExp();
        }
        if (tmpsyntaxes.size() == 1) {
            syntaxes.add(tmpsyntaxes.get(0));
            return new MulExp(syntaxes);
        } else {
            int size = tmpsyntaxes.size();
            Syntax syntax1 = tmpsyntaxes.get(size - 1);
            Syntax syntax2 = tmpsyntaxes.get(size - 2);
            if (syntax2 instanceof Token) {
                ((Token) syntax2).setUsed();
            }
            backto(initPos);
            syntaxes.add(parseMulExp());
            syntaxes.add(syntax2);
            syntaxes.add(syntax1);
            return new MulExp(syntaxes);
        }
    }

    public AddExp parseAddExp() {
        ArrayList<Syntax> syntaxes = new ArrayList<>();
        ArrayList<Syntax> tmpsyntaxes = new ArrayList<>();
        int initPos = pos;
        ArrayList<Integer> posList = new ArrayList<>();
        posList.addAll(clearMulExp());
        while (getToken().getType().equals(Token.TokenType.PLUS.toString())
                || getToken().getType().equals(Token.TokenType.MINU.toString())) {
            next();
            posList.addAll(clearMulExp());
        }
        for (Integer i : posList) {
            tokens.get(i).setUnused();
        }
        backto(initPos);
        tmpsyntaxes.add(parseMulExp());
        while (!getToken().isUsed() &&
                (getToken().getType().equals(Token.TokenType.PLUS.toString())
                        || getToken().getType().equals(Token.TokenType.MINU.toString()))) {
            tmpsyntaxes.add(getToken()); //('+' | '-')
            next();
            tmpsyntaxes.add(parseMulExp());
        }
        while (getToken().getType().equals(Token.TokenType.PLUS.toString())
                || getToken().getType().equals(Token.TokenType.MINU.toString())) {
            //('+' | '-')
            next();
            parseMulExp();
        }
        if (tmpsyntaxes.size() == 1) {
            syntaxes.add(tmpsyntaxes.get(0));
            return new AddExp(syntaxes);
        } else {
            int size = tmpsyntaxes.size();
            Syntax syntax1 = tmpsyntaxes.get(size - 1);
            Syntax syntax2 = tmpsyntaxes.get(size - 2);
            if (syntax2 instanceof Token) {
                ((Token) syntax2).setUsed();
            }
            backto(initPos);
            syntaxes.add(parseAddExp());
            syntaxes.add(syntax2);
            syntaxes.add(syntax1);
            return new AddExp(syntaxes);
        }
    }

    public RelExp parseRelExp() {
        ArrayList<Syntax> syntaxes = new ArrayList<>();
        ArrayList<Syntax> tmpsyntaxes = new ArrayList<>();
        int initPos = pos;
        ArrayList<Integer> posList = new ArrayList<>();
        posList.addAll(clearAddExp());
        while (getToken().getType().equals(Token.TokenType.LSS.toString())
                || getToken().getType().equals(Token.TokenType.GRE.toString())
                || getToken().getType().equals(Token.TokenType.LEQ.toString())
                || getToken().getType().equals(Token.TokenType.GEQ.toString())) {
            next();
            posList.addAll(clearAddExp());
        }
        for (Integer i : posList) {
            tokens.get(i).setUnused();
        }
        backto(initPos);
        tmpsyntaxes.add(parseAddExp());
        while (!getToken().isUsed() &&
                (getToken().getType().equals(Token.TokenType.LSS.toString())
                        || getToken().getType().equals(Token.TokenType.GRE.toString())
                        || getToken().getType().equals(Token.TokenType.LEQ.toString())
                        || getToken().getType().equals(Token.TokenType.GEQ.toString()))) {
            tmpsyntaxes.add(getToken()); //'<' | '>' | '<=' | '>='
            next();
            tmpsyntaxes.add(parseAddExp());
        }
        while (getToken().getType().equals(Token.TokenType.LSS.toString())
                || getToken().getType().equals(Token.TokenType.GRE.toString())
                || getToken().getType().equals(Token.TokenType.LEQ.toString())
                || getToken().getType().equals(Token.TokenType.GEQ.toString())) {
            //'<' | '>' | '<=' | '>='
            next();
            parseAddExp();
        }
        if (tmpsyntaxes.size() == 1) {
            syntaxes.add(tmpsyntaxes.get(0));
            return new RelExp(syntaxes);
        } else {
            int size = tmpsyntaxes.size();
            Syntax syntax1 = tmpsyntaxes.get(size - 1);
            Syntax syntax2 = tmpsyntaxes.get(size - 2);
            if (syntax2 instanceof Token) {
                ((Token) syntax2).setUsed();
            }
            backto(initPos);
            syntaxes.add(parseRelExp());
            syntaxes.add(syntax2);
            syntaxes.add(syntax1);
            return new RelExp(syntaxes);
        }
    }

    public EqExp parseEqExp() {
        ArrayList<Syntax> syntaxes = new ArrayList<>();
        ArrayList<Syntax> tmpsyntaxes = new ArrayList<>();
        int initPos = pos;
        ArrayList<Integer> posList = new ArrayList<>();
        posList.addAll(clearRelExp());
        while (getToken().getType().equals(Token.TokenType.EQL.toString())
                || getToken().getType().equals(Token.TokenType.NEQ.toString())) {
            next();
            posList.addAll(clearRelExp());
        }
        for (Integer i : posList) {
            tokens.get(i).setUnused();
        }
        backto(initPos);
        tmpsyntaxes.add(parseRelExp());
        while (!getToken().isUsed() &&
                (getToken().getType().equals(Token.TokenType.EQL.toString())
                        || getToken().getType().equals(Token.TokenType.NEQ.toString()))) {
            tmpsyntaxes.add(getToken()); //('==' | '!=')
            next();
            tmpsyntaxes.add(parseRelExp());
        }
        while (getToken().getType().equals(Token.TokenType.EQL.toString())
                || getToken().getType().equals(Token.TokenType.NEQ.toString())) {
            //('==' | '!=')
            next();
            parseRelExp();
        }
        if (tmpsyntaxes.size() == 1) {
            syntaxes.add(tmpsyntaxes.get(0));
            return new EqExp(syntaxes);
        } else {
            int size = tmpsyntaxes.size();
            Syntax syntax1 = tmpsyntaxes.get(size - 1);
            Syntax syntax2 = tmpsyntaxes.get(size - 2);
            if (syntax2 instanceof Token) {
                ((Token) syntax2).setUsed();
            }
            backto(initPos);
            syntaxes.add(parseEqExp());
            syntaxes.add(syntax2);
            syntaxes.add(syntax1);
            return new EqExp(syntaxes);
        }
    }

    public LOrExp parseLOrExp() {
        ArrayList<Syntax> syntaxes = new ArrayList<>();
        ArrayList<Syntax> tmpsyntaxes = new ArrayList<>();
        int initPos = pos;
        ArrayList<Integer> posList = new ArrayList<>();
        posList.addAll(clearLAndExp());
        while (getToken().getType().equals(Token.TokenType.OR.toString())) {
            next();
            posList.addAll(clearLAndExp());
        }
        for (Integer i : posList) {
            tokens.get(i).setUnused();
        }
        backto(initPos);
        tmpsyntaxes.add(parseLAndExp());
        while (!getToken().isUsed() &&
                (getToken().getType().equals(Token.TokenType.OR.toString()))) {
            tmpsyntaxes.add(getToken()); //'||'
            next();
            tmpsyntaxes.add(parseLAndExp());
        }
        while (getToken().getType().equals(Token.TokenType.OR.toString())) {
            //"&&"
            next();
            parseLAndExp();
        }
        if (tmpsyntaxes.size() == 1) {
            syntaxes.add(tmpsyntaxes.get(0));
            return new LOrExp(syntaxes);
        } else {
            int size = tmpsyntaxes.size();
            Syntax syntax1 = tmpsyntaxes.get(size - 1);
            Syntax syntax2 = tmpsyntaxes.get(size - 2);
            if (syntax2 instanceof Token) {
                ((Token) syntax2).setUsed();
            }
            backto(initPos);
            syntaxes.add(parseLOrExp());
            syntaxes.add(syntax2);
            syntaxes.add(syntax1);
            return new LOrExp(syntaxes);
        }
    }

    public LAndExp parseLAndExp() {
        ArrayList<Syntax> syntaxes = new ArrayList<>();
        ArrayList<Syntax> tmpsyntaxes = new ArrayList<>();
        int initPos = pos;
        ArrayList<Integer> posList = new ArrayList<>();
        posList.addAll(clearEqExp());
        while (getToken().getType().equals(Token.TokenType.AND.toString())) {
            next();
            posList.addAll(clearEqExp());
        }
        for (Integer i : posList) {
            tokens.get(i).setUnused();
        }
        backto(initPos);
        tmpsyntaxes.add(parseEqExp());
        while (!getToken().isUsed() &&
                (getToken().getType().equals(Token.TokenType.AND.toString()))) {
            tmpsyntaxes.add(getToken()); //'&&'
            next();
            tmpsyntaxes.add(parseEqExp());
        }
        while (getToken().getType().equals(Token.TokenType.AND.toString())) {
            //"&&"
            next();
            parseEqExp();
        }
        if (tmpsyntaxes.size() == 1) {
            syntaxes.add(tmpsyntaxes.get(0));
            return new LAndExp(syntaxes);
        } else {
            int size = tmpsyntaxes.size();
            Syntax syntax1 = tmpsyntaxes.get(size - 1);
            Syntax syntax2 = tmpsyntaxes.get(size - 2);
            if (syntax2 instanceof Token) {
                ((Token) syntax2).setUsed();
            }
            backto(initPos);
            syntaxes.add(parseLAndExp());
            syntaxes.add(syntax2);
            syntaxes.add(syntax1);
            return new LAndExp(syntaxes);
        }
    }

    public ArrayList<Integer> clearMulExp() {
        ArrayList<Integer> posList = new ArrayList<>();
        parseUnaryExp();
        while (getToken().getType().equals(Token.TokenType.MULT.toString())
                || getToken().getType().equals(Token.TokenType.DIV.toString())
                || getToken().getType().equals(Token.TokenType.MOD.toString())) {
            posList.add(pos);
            next();
            parseUnaryExp();
        }
        return posList;
    }

    public ArrayList<Integer> clearAddExp() {
        ArrayList<Integer> posList = new ArrayList<>();
        parseMulExp();
        while (getToken().getType().equals(Token.TokenType.PLUS.toString())
                || getToken().getType().equals(Token.TokenType.MINU.toString())) {
            posList.add(pos);
            next();
            parseMulExp();
        }
        return posList;
    }

    public ArrayList<Integer> clearRelExp() {
        ArrayList<Integer> posList = new ArrayList<>();
        parseAddExp();
        while (getToken().getType().equals(Token.TokenType.LSS.toString())
                || getToken().getType().equals(Token.TokenType.GRE.toString())
                || getToken().getType().equals(Token.TokenType.LEQ.toString())
                || getToken().getType().equals(Token.TokenType.GEQ.toString())) {
            posList.add(pos);
            next();
            parseAddExp();
        }
        return posList;
    }

    public ArrayList<Integer> clearEqExp() {
        ArrayList<Integer> posList = new ArrayList<>();
        parseRelExp();
        while (getToken().getType().equals(Token.TokenType.EQL.toString())
                || getToken().getType().equals(Token.TokenType.NEQ.toString())
        ) {
            posList.add(pos);
            next();
            parseRelExp();
        }
        return posList;
    }

    public ArrayList<Integer> clearLAndExp() {
        ArrayList<Integer> posList = new ArrayList<>();
        parseEqExp();
        while (getToken().getType().equals(Token.TokenType.AND.toString())
        ) {
            posList.add(pos);
            next();
            parseEqExp();
        }
        return posList;
    }

    public ArrayList<Integer> clearLOrExp() {
        ArrayList<Integer> posList = new ArrayList<>();
        parseLAndExp();
        while (getToken().getType().equals(Token.TokenType.OR.toString())
        ) {
            posList.add(pos);
            next();
            parseLAndExp();
        }
        return posList;
    }

    public String getErrorOutput() {
        StringBuilder sb = new StringBuilder();
        Collections.sort(errorLogs, new Comparator<ErrorLog>() {
            @Override
            public int compare(ErrorLog o1, ErrorLog o2) {
                int lineCompare = Integer.compare(o1.getLineNum(), o2.getLineNum());
                if (lineCompare != 0) {
                    return lineCompare;
                } else {
                    return Integer.compare(o1.getPos(), (o2.getPos()));
                }
            }
        });
        for (ErrorLog errorLog : errorLogs) {
            sb.append(errorLog.getLineNum() + " " + errorLog.getType() + "\n");
        }
        return sb.toString();
    }


}
