package frontend;

import error.Error;
import error.ErrorList;
import error.ErrorType;
import struct.*;
import struct.Character;
import struct.Number;
import token.TokenType;
import token.Token;

import java.util.ArrayList;
import java.util.List;

public class Parser {
    private static Parser instance;
    private CompUnit root;
    private List<Token> tokenList;
    private Token curToken;
    private int index = 0;

    public static Parser getInstance() {
        if (instance == null) {
            instance = new Parser();
        }
        return instance;
    }

    public CompUnit getAST() {
        return root;
    }

    public String getASTAsString() {
        return root.toString();
    }

    public void setTokenList(List<Token> tokenList) {
        this.tokenList = tokenList;
        this.curToken = tokenList.get(index);
    }

    public void parse() {
        /* 递归向下子程序，从头开始构建抽象语法树 */
        root = _CompUnit();
    }

    private CompUnit _CompUnit() {
        /* CompUnit → {Decl} {FuncDef} MainFuncDef
        * Decl:         char a;         |   const int a = 1;
        * FuncDef:      int fun() {}    |   void fun(int a) {}
        * MainFuncDef:  int main() {}
        *                ^~~~curToken
        */
        List<Decl> decl = new ArrayList<>();
        List<FuncDef> funcDef = new ArrayList<>();
        MainFuncDef mainFuncDef;

        while (tokenList.get(index + 1).getTokenType() != TokenType.MAINTK && tokenList.get(index + 2).getTokenType() != TokenType.LPARENT) {
            decl.add(_Decl());
        }
        while (tokenList.get(index + 1).getTokenType() != TokenType.MAINTK) {
            funcDef.add((_FuncDef()));
        }
        mainFuncDef = _MainFuncDef();
        return new CompUnit(decl, funcDef, mainFuncDef);
    }

    private Decl _Decl() {
        /* Decl → ConstDecl | VarDecl */
        if (curToken.getTokenType() == TokenType.CONSTTK) {
            return new Decl(_ConstDecl());
        } else {
            return new Decl(_varDecl());
        }
    }

    private ConstDecl _ConstDecl() {
        /* ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';' */
        Token constToken;
        BType bType;
        List<ConstDef> constDef = new ArrayList<>();
        List<Token> commaToken = new ArrayList<>();
        Token semicnToken;

        constToken = _match(TokenType.CONSTTK);
        bType = _BType();
        constDef.add(_ConstDef());
        while (curToken.getTokenType() == TokenType.COMMA) {
            commaToken.add(_match(TokenType.COMMA));
            constDef.add(_ConstDef());
        }
        semicnToken = _match(TokenType.SEMICN);
        return new ConstDecl(constToken, bType, constDef, commaToken, semicnToken);
    }

    private BType _BType() {
        /* BType → 'int' | 'char' */
        Token type;

        if (curToken.getTokenType() == TokenType.INTTK) {
            type = _match(TokenType.INTTK);
        } else {
            type = _match(TokenType.CHARTK);
        }
        return new BType(type);
    }

    private ConstDef _ConstDef() {
        /* ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal */
        Token ident;
        Token lBrackToken = null;
        ConstExp constExp = null;
        Token rBrackToken = null;
        Token assignToken;
        ConstInitVal constInitVal;

        ident = _match(TokenType.IDENFR);
        if (curToken.getTokenType() == TokenType.LBRACK) {
            lBrackToken = _match(TokenType.LBRACK);
            constExp = _ConstExp();
            rBrackToken = _match(TokenType.RBRACK);
        }
        assignToken = _match(TokenType.ASSIGN);
        constInitVal = _ConstInitVal();
        return new ConstDef(ident, lBrackToken, constExp, rBrackToken, assignToken, constInitVal);
    }

    private ConstExp _ConstExp() {
        /* ConstExp → AddExp 注：使用的 Ident 必须是常量 */
        AddExp addExp;

        addExp = _AddExp();
        return new ConstExp(addExp);
    }

    private ConstInitVal _ConstInitVal() {
        /*
        * ConstInitVal → ConstExp
        * | '{' [ ConstExp { ',' ConstExp } ] '}'
        * | StringConst
        */
        List<ConstExp> constExp = new ArrayList<>();
        Token lBraceToken;
        List<Token> commaToken = new ArrayList<>();
        Token rBraceToken;
        Token stringConst;

        if (curToken.getTokenType() == TokenType.LBRACE) {
            lBraceToken = _match(TokenType.LBRACE);
            if (curToken.getTokenType() != TokenType.RBRACE) {
                constExp.add(_ConstExp());
                while (curToken.getTokenType() == TokenType.COMMA) {
                    commaToken.add(_match(TokenType.COMMA));
                    constExp.add(_ConstExp());
                }
            }
            rBraceToken = _match(TokenType.RBRACE);
            return new ConstInitVal(constExp, lBraceToken, commaToken, rBraceToken);
        } else if (curToken.getTokenType() == TokenType.STRCON) {
            stringConst = _match(TokenType.STRCON);
            return new ConstInitVal(stringConst);
        } else {
            constExp.add(_ConstExp());
            return new ConstInitVal(constExp);
        }
    }

    private AddExp _AddExp() {
        /* AddExp → MulExp { ('+' | '-') MulExp } */
        List<MulExp> mulExp = new ArrayList<>();
        List<Token> operater = new ArrayList<>();

        mulExp.add(_MulExp());
        while (curToken.getTokenType() == TokenType.PLUS || curToken.getTokenType() == TokenType.MINU) {
            if (curToken.getTokenType() == TokenType.PLUS) {
                operater.add(_match(TokenType.PLUS));
            } else {
                operater.add(_match(TokenType.MINU));
            }
            mulExp.add(_MulExp());
        }
        return new AddExp(mulExp, operater);
    }

    private MulExp _MulExp() {
        /* MulExp → UnaryExp { ('*' | '/' | '%') UnaryExp } */
        List<UnaryExp> unaryExp = new ArrayList<>();
        List<Token> operater = new ArrayList<>();

        unaryExp.add(_UnaryExp());
        while (curToken.getTokenType() == TokenType.MULT || curToken.getTokenType() == TokenType.DIV || curToken.getTokenType() == TokenType.MOD) {
            if (curToken.getTokenType() == TokenType.MULT) {
                operater.add(_match(TokenType.MULT));
            } else if (curToken.getTokenType() == TokenType.DIV) {
                operater.add(_match(TokenType.DIV));
            } else {
                operater.add(_match(TokenType.MOD));
            }
            unaryExp.add(_UnaryExp());
        }
        return new MulExp(unaryExp, operater);
    }

    private UnaryExp _UnaryExp() {
        /* UnaryExp → PrimaryExp
        * | Ident '(' [FuncRParams] ')'
        * | UnaryOp UnaryExp        **UnaryOp → '+' | '−' | '!'**
        */
        PrimaryExp primaryExp;
        Token ident;
        Token lParentToken;
        Token rParentToken;
        FuncRParams funcRParams = null;
        UnaryOp unaryOp;
        UnaryExp unaryExp;

        if (curToken.getTokenType() == TokenType.IDENFR && tokenList.get(index + 1).getTokenType() == TokenType.LPARENT) {
            ident = _match(TokenType.IDENFR);
            lParentToken = _match(TokenType.LPARENT);
            if (isExp()) {
                funcRParams = _FuncRParams();
            }
            rParentToken = _match(TokenType.RPARENT);
            return new UnaryExp(ident, lParentToken, funcRParams, rParentToken);
        } else if (curToken.getTokenType() == TokenType.PLUS || curToken.getTokenType() == TokenType.MINU || curToken.getTokenType() == TokenType.NOT) {
            unaryOp = _UnaryOp();
            unaryExp = _UnaryExp();
            return new UnaryExp(unaryOp, unaryExp);
        } else {
            primaryExp = _PrimaryExp();
            return new UnaryExp(primaryExp);
        }
    }

    private FuncRParams _FuncRParams() {
        /* FuncRParams → Exp { ',' Exp } */
        List<Exp> exp = new ArrayList<>();
        List<Token> commaToken = new ArrayList<>();

        exp.add(_Exp());
        while (curToken.getTokenType() == TokenType.COMMA) {
            commaToken.add(_match(TokenType.COMMA));
            exp.add(_Exp());
        }
        return new FuncRParams(exp, commaToken);
    }

    private UnaryOp _UnaryOp() {
        /* UnaryOp → '+' | '−' | '!' 注：'!'仅出现在条件表达式中 */
        Token operator;

        if (curToken.getTokenType() == TokenType.PLUS) {
            operator = _match(TokenType.PLUS);
        } else if (curToken.getTokenType() == TokenType.MINU) {
            operator = _match(TokenType.MINU);
        } else {
            operator = _match(TokenType.NOT);
        }
        return new UnaryOp(operator);
    }

    private PrimaryExp _PrimaryExp() {
        /* PrimaryExp → '(' Exp ')' | LVal | Number | Character
        *  LVal → Ident ['[' Exp ']']*/
        Token lParentToken;
        Token rParentToken;
        Exp exp;
        LVal lVal;
        Number number;
        Character character;

        if (curToken.getTokenType() == TokenType.LPARENT) {
            lParentToken = _match(TokenType.LPARENT);
            exp = _Exp();
            rParentToken = _match(TokenType.RPARENT);
            return new PrimaryExp(lParentToken, exp, rParentToken);
        } else if (curToken.getTokenType() == TokenType.IDENFR) {
            lVal = _LVal();
            return new PrimaryExp(lVal);
        } else if (curToken.getTokenType() == TokenType.INTCON){
            number = _Number();
            return new PrimaryExp(number);
        } else {
            character = _Character();
            return new PrimaryExp(character);
        }
    }

    private Exp _Exp() {
        /* Exp → AddExp */
        AddExp addExp;

        addExp = _AddExp();
        return new Exp(addExp);
    }

    private LVal _LVal() {
        /* LVal → Ident ['[' Exp ']'] */
        Token ident;
        Token lBrackToken = null;
        Exp exp = null;
        Token rBrackToken = null;

        ident = _match(TokenType.IDENFR);
        if (curToken.getTokenType() == TokenType.LBRACK) {
            lBrackToken = _match(TokenType.LBRACK);
            exp = _Exp();
            rBrackToken = _match(TokenType.RBRACK);
        }
        return new LVal(ident, lBrackToken, exp, rBrackToken);
    }

    private Number _Number() {
        /* Number → IntConst */
        Token intConst;

        intConst = _match(TokenType.INTCON);
        return new Number(intConst);
    }

    private Character _Character() {
        /* Character → CharConst */
        Token charConst;

        charConst = _match(TokenType.CHRCON);
        return new Character(charConst);
    }

    private VarDecl _varDecl() {
        /* VarDecl → BType VarDef { ',' VarDef } ';' */
        BType bType;
        List<VarDef> varDef = new ArrayList<>();
        List<Token> commaToken = new ArrayList<>();
        Token semicnToken;

        bType = _BType();
        varDef.add(_VarDef());
        while (curToken.getTokenType() == TokenType.COMMA) {
            commaToken.add(_match(TokenType.COMMA));
            varDef.add(_VarDef());
        }
        semicnToken = _match(TokenType.SEMICN);
        return new VarDecl(bType, varDef, commaToken, semicnToken);
    }

    private VarDef _VarDef() {
        /* VarDef → Ident [ '[' ConstExp ']' ]
        * | Ident [ '[' ConstExp ']' ] '=' InitVal
        */
        Token ident;
        Token lBrackToken = null;
        ConstExp constExp = null;
        Token rBrackToken = null;
        Token assignToken;
        InitVal initVal;

        ident = _match(TokenType.IDENFR);
        if (curToken.getTokenType() == TokenType.LBRACK) {
            lBrackToken = _match(TokenType.LBRACK);
            constExp = _ConstExp();
            rBrackToken = _match(TokenType.RBRACK);
        }
        if (curToken.getTokenType() == TokenType.ASSIGN) {
            assignToken = _match(TokenType.ASSIGN);
            initVal = _InitVal();
            return new VarDef(ident, lBrackToken, constExp, rBrackToken, assignToken, initVal);
        }
        return new VarDef(ident, lBrackToken, constExp, rBrackToken);
    }

    private InitVal _InitVal() {
        /*
        * InitVal → Exp
        * | '{' [ Exp { ',' Exp } ] '}'
        * | StringConst
        */
        List<Exp> exp = new ArrayList<>();
        Token lBraceToken;
        List<Token> commaToken = new ArrayList<>();
        Token rBraceToken;
        Token stringConst;

        if (curToken.getTokenType() == TokenType.LBRACE) {
            lBraceToken = _match(TokenType.LBRACE);
            if (curToken.getTokenType() != TokenType.RBRACE) {
                exp.add(_Exp());
                while (curToken.getTokenType() == TokenType.COMMA) {
                    commaToken.add(_match(TokenType.COMMA));
                    exp.add(_Exp());
                }
            }
            rBraceToken = _match(TokenType.RBRACE);
            return new InitVal(exp, lBraceToken, commaToken, rBraceToken);
        } else if (curToken.getTokenType() == TokenType.STRCON) {
            stringConst = _match(TokenType.STRCON);
            return new InitVal(stringConst);
        } else {
            exp.add(_Exp());
            return new InitVal(exp);
        }
    }

    private FuncDef _FuncDef() {
        /* FuncDef → FuncType Ident '(' [FuncFParams] ')' Block */
        FuncType funcType;
        Token ident;
        Token lParentToken;
        FuncFParams funcFParams = null;
        Token rParentToken;
        Block block;

        funcType = _FuncType();
        ident = _match(TokenType.IDENFR);
        lParentToken = _match(TokenType.LPARENT);
        if (curToken.getTokenType() == TokenType.INTTK || curToken.getTokenType() == TokenType.CHARTK) {
            funcFParams = _FuncFParams();
        }
        rParentToken = _match(TokenType.RPARENT);
        block = _Block();
        return new FuncDef(funcType, ident, lParentToken, funcFParams, rParentToken, block);
    }

    private FuncType _FuncType() {
        /* FuncType → 'void' | 'int' | 'char' */
        Token type;

        if (curToken.getTokenType() == TokenType.VOIDTK) {
            type = _match(TokenType.VOIDTK);
        } else if (curToken.getTokenType() == TokenType.INTTK) {
            type = _match(TokenType.INTTK);
        } else {
            type = _match(TokenType.CHARTK);
        }
        return new FuncType(type);
    }

    private FuncFParams _FuncFParams() {
        /* FuncFParams → FuncFParam { ',' FuncFParam } */
        List<FuncFParam> funcFParam = new ArrayList<>();
        List<Token> commaToken = new ArrayList<>();

        funcFParam.add(_FuncFParam());
        while (curToken.getTokenType() == TokenType.COMMA) {
            commaToken.add(_match(TokenType.COMMA));
            funcFParam.add(_FuncFParam());
        }
        return new FuncFParams(funcFParam, commaToken);
    }

    private FuncFParam _FuncFParam() {
        /* FuncFParam → BType Ident ['[' ']'] */
        BType bType;
        Token ident;
        Token lBrackToken = null;
        Token rBrackToken = null;

        bType = _BType();
        ident = _match(TokenType.IDENFR);
        if (curToken.getTokenType() == TokenType.LBRACK) {
            lBrackToken = _match(TokenType.LBRACK);
            rBrackToken = _match(TokenType.RBRACK);
        }
        return new FuncFParam(bType, ident, lBrackToken, rBrackToken);
    }

    private Block _Block() {
        /* Block → '{' { BlockItem } '}' */
        Token lBraceToken;
        List<BlockItem> blockItem = new ArrayList<>();
        Token rBraceToken;

        lBraceToken = _match(TokenType.LBRACE);
        while (curToken.getTokenType() != TokenType.RBRACE) {
            blockItem.add(_BlockItem());
        }
        rBraceToken = _match(TokenType.RBRACE);
        return new Block(lBraceToken, blockItem, rBraceToken);
    }

    private BlockItem _BlockItem() {
        /* BlockItem → Decl | Stmt
        * Decl -> 'const' ... | BType ...
        */
        Decl decl;
        Stmt stmt;

        if (curToken.getTokenType() == TokenType.CONSTTK || curToken.getTokenType() == TokenType.INTTK || curToken.getTokenType() == TokenType.CHARTK) {
            decl = _Decl();
            return new BlockItem(decl);
        } else {
            stmt = _Stmt();
            return new BlockItem(stmt);
        }
    }

    private Stmt _Stmt() {
        /*
        * Stmt → LVal '=' Exp ';'
        * | LVal '=' 'getint' '(' ')' ';'
        * | LVal '=' 'getchar' '(' ')' ';'
        * | [ Exp ] ';'
        * | Block
        * | 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
        * | 'for' '(' [ ForStmt ] ';' [ Cond ] ';' [ ForStmt ] ')' Stmt
        * | 'break' ';'
        * | 'continue' ';'
        * | 'return' [ Exp ] ';'
        * | 'printf' '(' StringConst { ',' Exp } ')' ';'
        */
        LVal lVal;
        Token assignToken = null;
        List<Exp> exp = new ArrayList<>();
        List<Token> semicnToken = new ArrayList<>();
        Token getintToken = null;
        Token getcharToken = null;
        Token lParentToken;
        Token rParentToken;
        Block block;
        Token ifToken;
        Cond cond = null;
        Token elseToken = null;
        List<Stmt> stmt = new ArrayList<>();
        Token forToken;
        ForStmt forStmt_1 = null;
        ForStmt forStmt_2 = null;
        Token breakToken = null;
        Token continueToken = null;
        Token returnToken;
        Token printfToken;
        Token stringConst;
        List<Token> commaToken = new ArrayList<>();

        if (curToken.getTokenType() == TokenType.IFTK) {
            ifToken = _match(TokenType.IFTK);
            lParentToken = _match(TokenType.LPARENT);
            cond = _Cond();
            rParentToken = _match(TokenType.RPARENT);
            stmt.add(_Stmt());
            if (curToken.getTokenType() == TokenType.ELSETK) {
                elseToken = _match(TokenType.ELSETK);
                stmt.add(_Stmt());
            }
            return new Stmt(ifToken, lParentToken, cond, rParentToken, stmt, elseToken);
        } else if (curToken.getTokenType() == TokenType.FORTK) {
            forToken = _match(TokenType.FORTK);
            lParentToken = _match(TokenType.LPARENT);
            if (curToken.getTokenType() != TokenType.SEMICN) {
                forStmt_1 = _ForStmt();
            }
            semicnToken.add(_match(TokenType.SEMICN));
            if (curToken.getTokenType() != TokenType.SEMICN) {
                cond = _Cond();
            }
            semicnToken.add(_match(TokenType.SEMICN));
            if (curToken.getTokenType() != TokenType.RPARENT) {
                forStmt_2 = _ForStmt();
            }
            rParentToken = _match(TokenType.RPARENT);
            stmt.add(_Stmt());
            return new Stmt(forToken, lParentToken, forStmt_1, semicnToken, cond, forStmt_2, rParentToken, stmt);
        } else if (curToken.getTokenType() == TokenType.BREAKTK) {
            breakToken = _match(TokenType.BREAKTK);
            semicnToken.add(_match(TokenType.SEMICN));
            return new Stmt(breakToken, continueToken, semicnToken);
        } else if (curToken.getTokenType() == TokenType.CONTINUETK) {
            continueToken = _match(TokenType.CONTINUETK);
            semicnToken.add(_match(TokenType.SEMICN));
            return new Stmt(breakToken, continueToken, semicnToken);
        } else if (curToken.getTokenType() == TokenType.RETURNTK) {
            returnToken = _match(TokenType.RETURNTK);
            if (isExp()) {
                exp.add(_Exp());
            }
            semicnToken.add(_match(TokenType.SEMICN));
            return new Stmt(returnToken, exp, semicnToken);
        } else if (curToken.getTokenType() == TokenType.PRINTFTK) {
            printfToken = _match(TokenType.PRINTFTK);
            lParentToken = _match(TokenType.LPARENT);
            stringConst = _match(TokenType.STRCON);
            while (curToken.getTokenType() == TokenType.COMMA) {
                commaToken.add(_match(TokenType.COMMA));
                exp.add(_Exp());
            }
            rParentToken = _match(TokenType.RPARENT);
            semicnToken.add(_match(TokenType.SEMICN));
            return new Stmt(printfToken, lParentToken, stringConst, commaToken, exp, rParentToken, semicnToken);
        } else if (curToken.getTokenType() == TokenType.LBRACE) {
            block = _Block();
            return new Stmt(block);
        } else {
            /* Search assignToken '=' */
            for (int i = index; i < tokenList.size(); i++) {
                if (tokenList.get(i).getLine() != curToken.getLine() || curToken.getTokenType() == TokenType.SEMICN) {
                    break;
                }
                if (tokenList.get(i).getTokenType() == TokenType.ASSIGN) {
                    assignToken = curToken;
                    break;
                }
            }
            if (assignToken != null) {
                lVal = _LVal();
                assignToken = _match(TokenType.ASSIGN);
                if (curToken.getTokenType() == TokenType.GETINTTK) {
                    getintToken = _match(TokenType.GETINTTK);
                    lParentToken = _match(TokenType.LPARENT);
                    rParentToken = _match(TokenType.RPARENT);
                    semicnToken.add(_match(TokenType.SEMICN));
                    return new Stmt(lVal, assignToken, getintToken, getcharToken, lParentToken, rParentToken, semicnToken);
                } else if (curToken.getTokenType() == TokenType.GETCHARTK) {
                    getcharToken = _match(TokenType.GETCHARTK);
                    lParentToken = _match(TokenType.LPARENT);
                    rParentToken = _match(TokenType.RPARENT);
                    semicnToken.add(_match(TokenType.SEMICN));
                    return new Stmt(lVal, assignToken, getintToken, getcharToken, lParentToken, rParentToken, semicnToken);
                } else {
                    exp.add(_Exp());
                    semicnToken.add(_match(TokenType.SEMICN));
                    return new Stmt(lVal, assignToken, exp, semicnToken);
                }
            } else {
                if (isExp()) {
                    exp.add(_Exp());
                }
                semicnToken.add(_match(TokenType.SEMICN));
                return new Stmt(exp, semicnToken);
            }
        }
    }

    private Cond _Cond() {
        /* Cond → LOrExp */
        LOrExp lOrExp;

        lOrExp = _LOrExp();
        return new Cond(lOrExp);
    }

    private LOrExp _LOrExp() {
        /* LOrExp → LAndExp { '||' LAndExp } */
        List<LAndExp> lAndExp = new ArrayList<>();
        List<Token> orToken = new ArrayList<>();

        lAndExp.add(_LAndExp());
        while (curToken.getTokenType() == TokenType.OR) {
            orToken.add(_match(TokenType.OR));
            lAndExp.add(_LAndExp());
        }
        return new LOrExp(lAndExp, orToken);
    }

    private LAndExp _LAndExp() {
        /* LAndExp → EqExp { '&&' EqExp } */
        List<EqExp> eqExp = new ArrayList<>();
        List<Token> andToken = new ArrayList<>();

        eqExp.add(_EqExp());
        while (curToken.getTokenType() == TokenType.AND) {
            andToken.add(_match(TokenType.AND));
            eqExp.add(_EqExp());
        }
        return new LAndExp(eqExp, andToken);
    }

    private EqExp _EqExp() {
        /* EqExp → RelExp { ('==' | '!=') RelExp } */
        List<RelExp> relExp = new ArrayList<>();
        List<Token> operater = new ArrayList<>();

        relExp.add(_RelExp());
        while (curToken.getTokenType() == TokenType.EQL || curToken.getTokenType() == TokenType.NEQ) {
            if (curToken.getTokenType() == TokenType.EQL) {
                operater.add(_match(TokenType.EQL));
            } else {
                operater.add(_match(TokenType.NEQ));
            }
            relExp.add(_RelExp());
        }
        return new EqExp(relExp, operater);
    }

    private RelExp _RelExp() {
        /* RelExp → AddExp { ('<' | '>' | '<=' | '>=') AddExp } */
        List<AddExp> addExp = new ArrayList<>();
        List<Token> operater = new ArrayList<>();

        addExp.add(_AddExp());
        while (curToken.getTokenType() == TokenType.LSS || curToken.getTokenType() == TokenType.GRE || curToken.getTokenType() == TokenType.LEQ || curToken.getTokenType() == TokenType.GEQ) {
            if (curToken.getTokenType() == TokenType.LSS) {
                operater.add(_match(TokenType.LSS));
            } else if (curToken.getTokenType() == TokenType.GRE) {
                operater.add(_match(TokenType.GRE));
            } else if (curToken.getTokenType() == TokenType.LEQ) {
                operater.add(_match(TokenType.LEQ));
            } else {
                operater.add(_match(TokenType.GEQ));
            }
            addExp.add(_AddExp());
        }
        return new RelExp(addExp, operater);
    }

    private ForStmt _ForStmt() {
        /* ForStmt → LVal '=' Exp */
        LVal lVal;
        Token assignToken;
        Exp exp;

        lVal = _LVal();
        assignToken = _match(TokenType.ASSIGN);
        exp = _Exp();
        return new ForStmt(lVal, assignToken, exp);
    }

    private MainFuncDef _MainFuncDef() {
        /* MainFuncDef → 'int' 'main' '(' ')' Block */
        Token intToken;
        Token mainToken;
        Token lParentToken;
        Token rParentToken;
        Block block;

        intToken = _match(TokenType.INTTK);
        mainToken = _match(TokenType.MAINTK);
        lParentToken = _match(TokenType.LPARENT);
        rParentToken = _match(TokenType.RPARENT);
        block = _Block();
        return new MainFuncDef(intToken, mainToken, lParentToken, rParentToken, block);
    }

    private Token _match(TokenType tokenType) {
        if (curToken.getTokenType() == tokenType) {
            Token retStm = curToken;
            _nextToken();
            return retStm;
        } else if (tokenType == TokenType.SEMICN) {
            /* i 报错行号为分号前一个非终结符所在行号 */
            int line = tokenList.get(index - 1).getLine();
            ErrorList.getInstance().addError(new Error(line, ErrorType.i));
            return new Token(TokenType.SEMICN, ";", curToken.getLine());
        } else if (tokenType == TokenType.RPARENT) {
            /* j 报错行号为右小括号前一个非终结符所在行号 */
            int line = tokenList.get(index - 1).getLine();
            ErrorList.getInstance().addError(new Error(line, ErrorType.j));
            return new Token(TokenType.RPARENT, ")", curToken.getLine());
        } else if (tokenType == TokenType.RBRACK) {
            /* k 报错行号为右中括号前一个非终结符所在行号 */
            int line = tokenList.get(index - 1).getLine();
            ErrorList.getInstance().addError(new Error(line, ErrorType.k));
            return new Token(TokenType.RBRACK, "]", curToken.getLine());
        } else {
            throw new RuntimeException("Unmatched token type at line " + curToken.getLine() + ". To match: " + tokenType + "; Current token: " + curToken.toString());
        }
    }

    private void _nextToken() {
        if (index < tokenList.size() - 1) {
            index++;
            curToken = tokenList.get(index);
        }
    }

    private boolean isExp() {
        return curToken.getTokenType() == TokenType.IDENFR ||
                curToken.getTokenType() == TokenType.INTCON ||
                curToken.getTokenType() == TokenType.CHRCON ||
                curToken.getTokenType() == TokenType.PLUS ||
                curToken.getTokenType() == TokenType.MINU ||
                curToken.getTokenType() == TokenType.NOT ||
                curToken.getTokenType() == TokenType.LPARENT;
    }
}
