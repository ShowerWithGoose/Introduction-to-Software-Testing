package Fronted.parser;

import Fronted.lexer.LexerType;
import Fronted.lexer.Token;
import Fronted.lexer.TokenList;
import Error.ErrorType;
import Error.ErrorList;
import Fronted.parser.syntax.*;
import Fronted.parser.syntax.Number;
import Fronted.parser.syntax.Character;

import java.util.ArrayList;

public class Parser {

    private static final Parser parser = new Parser();

    private static TokenList tokenList;

    private static ErrorList errorList;

    private static CompUnit compUnit;

    private static int curPos;

    public static Parser getParser() {
        return parser;
    }

    private Parser() {
        this.tokenList = TokenList.getTokenList();
        this.errorList = ErrorList.getErrorList();
        this.compUnit = CompUnit.getCompUnit();
        curPos = -1;
    }

    public static LexerType getType(int index) {
        return tokenList.get(index).getType();
    }

    public static int getLine() {
        return tokenList.get(curPos).getLine();
    }
    
    public static Token getNextToken() {
        curPos++;
        return tokenList.get(curPos);
    }

    public static void set(ArrayList<Decl> declList, ArrayList<FuncDef> funcDefList, MainFuncDef mainFuncDef) {
        compUnit.setDeclList(declList);
        compUnit.setFuncDefList(funcDefList);
        compUnit.setMainFuncDef(mainFuncDef);
    }
    // CompUnit → {Decl} {FuncDef} MainFuncDef
    public static void compUnit() {
        ArrayList<Decl> declList = new ArrayList<Decl>();
        ArrayList<FuncDef> funcDefList = new ArrayList<FuncDef>();
        MainFuncDef mainFuncDef = null;
        while (!getType(curPos + 3).equals(LexerType.LPARENT)) { //decl
            declList.add(decl());
        }
        while (!getType(curPos + 2).equals(LexerType.MAINTK)) { //fundef
            funcDefList.add(funcDef());
        }
        mainFuncDef = mainFuncDef();
        set(declList, funcDefList, mainFuncDef);
    }

    // Decl → ConstDecl | VarDecl
    public static Decl decl(){
        if (getType(curPos + 1) == LexerType.CONSTTK) {
            return new Decl(constDecl());
        } else {
            return new Decl(varDecl());
        }
    }

    // ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';'
    public static ConstDecl constDecl(){
        Token token = getNextToken();
        BType bType = bType();
        ArrayList<ConstDef> constDefList = new ArrayList<ConstDef>();
        ArrayList<Token> commaList = new ArrayList<Token>();
        constDefList.add(constDef());
        while (getType(curPos + 1).equals(LexerType.COMMA)) {
            commaList.add(getNextToken());
            constDefList.add(constDef());
        }
        Token semicn = null;
        if(getType(curPos+1).equals(LexerType.SEMICN)) semicn = getNextToken();
        else {
            errorList.add(getLine(), ErrorType.i);
            //System.out.println(getLine() + " i\n");
        }
        return new ConstDecl(token, bType, constDefList, commaList, semicn);
    }


    //  BType → 'int' | 'char'
    public static BType bType(){
        return new BType(getNextToken());
    }

    //ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal
    public static ConstDef constDef() {
        Token ident = getNextToken();
        Token lbrack = null;
        ConstExp constExp = null;
        Token rbrack = null;
        if (getType(curPos + 1).equals(LexerType.LBRACK)) {
            lbrack = getNextToken();
            constExp = constExp();
            if (getType(curPos + 1).equals(LexerType.RBRACK)) {
                rbrack = getNextToken();
            } else {
                errorList.add(getLine(), ErrorType.k);
                //System.out.println(getLine() + " k\n");
            }
        }
        Token assign = getNextToken();
        ConstInitVal constInitVal = constInitVal();
        return new ConstDef(ident, lbrack, constExp, rbrack, assign, constInitVal);
    }
    
    // ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
    public static ConstInitVal constInitVal() {
        ArrayList<ConstExp> constExpList = new ArrayList<ConstExp>();
        ArrayList<Token> commaList = new ArrayList<Token>();
        if (getType(curPos + 1).equals(LexerType.LBRACE)) {
            Token lbrace = getNextToken();
            if (!getType(curPos + 1).equals(LexerType.RBRACE)) {
                constExpList.add(constExp());
                while (getType(curPos + 1).equals(LexerType.COMMA)) {
                    commaList.add(getNextToken());
                    constExpList.add(constExp());
                }
            }
            Token rbrace = getNextToken();

            return new ConstInitVal(lbrace, constExpList, commaList, rbrace);
        } else if (getType(curPos + 1).equals(LexerType.STRCON)){
            return new ConstInitVal(getNextToken());
        } else {
            constExpList.add(constExp());
            return new ConstInitVal(constExpList);
        }
    }

    // VarDecl → BType VarDef { ',' VarDef } ';'
    public static VarDecl varDecl(){
        BType bType = bType();
        ArrayList<VarDef> varDefList = new ArrayList<VarDef>();
        ArrayList<Token> commaList = new ArrayList<Token>();
        varDefList.add(varDef());
        while (getType(curPos + 1).equals(LexerType.COMMA)) {
            commaList.add(getNextToken());
            varDefList.add(varDef());
        }
        Token semicn = null;
        if(getType(curPos+1).equals(LexerType.SEMICN)) semicn = getNextToken();
        else {
            errorList.add(getLine(), ErrorType.i);
            //System.out.println(getLine() + " i\n");
        }
        return new VarDecl(bType, varDefList, commaList, semicn);
    }

    // VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal
    public static VarDef varDef() {
        Token ident = getNextToken();
        Token lbrack = null;
        ConstExp constExp = null;
        Token rbrack = null;
        Token assign = null;
        if (getType(curPos + 1).equals(LexerType.LBRACK)) {
            lbrack = getNextToken();
            constExp = constExp();
            if (getType(curPos + 1).equals(LexerType.RBRACK)) {
                rbrack = getNextToken();
            } else {
                errorList.add(getLine(), ErrorType.k);
                //System.out.println(getLine() + " k\n");
            }
        }
        if (getType(curPos + 1).equals(LexerType.ASSIGN)) {
            assign = getNextToken();
            InitVal initVal = initVal();
            return new VarDef(ident, lbrack, constExp, rbrack, assign, initVal);
        }
        return new VarDef(ident, lbrack, constExp, rbrack);
    }

    // InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
    public static InitVal initVal() {
        ArrayList<Exp> expList = new ArrayList<Exp>();
        ArrayList<Token> commaList = new ArrayList<Token>();
        if (getType(curPos + 1).equals(LexerType.LBRACE)) {
            Token lbrace = getNextToken();
            if (!getType(curPos + 1).equals(LexerType.RBRACE)) {
                expList.add(exp());
                while (getType(curPos + 1).equals(LexerType.COMMA)) {
                    commaList.add(getNextToken());
                    expList.add(exp());
                }
            }
            Token rbrace = getNextToken();
            return new InitVal(lbrace, expList, commaList, rbrace);
        } else if (getType(curPos + 1).equals(LexerType.STRCON)) {
            return new InitVal(getNextToken());
        } else {
            expList.add(exp());
            return new InitVal(expList);
        }
    }

    // FuncDef → FuncType Ident '(' [FuncFParams] ')' Block
    public static FuncDef funcDef() {
        FuncType funcType = funcType();
        Token ident = getNextToken();
        Token lparent = getNextToken();
        Token rparent = null;
        FuncFParams funcFParams = null;
        if (!getType(curPos + 1).equals(LexerType.RPARENT)) {
            if (!getType(curPos + 1).equals(LexerType.LBRACE))
            funcFParams = funcFParams();
        }
        if (getType(curPos + 1).equals(LexerType.RPARENT)) {
            rparent = getNextToken();
        } else {
            errorList.add(getLine(), ErrorType.j);
            //System.out.println(getLine() + " j\n");
        }
        Block block = block();
        return new FuncDef(funcType, ident, lparent, funcFParams, rparent, block);
    }

    //  MainFuncDef → 'int' 'main' '(' ')' Block
    public static MainFuncDef mainFuncDef() {
        Token intTK = getNextToken();
        Token mainTK = getNextToken();
        Token lparent = getNextToken();
        Token rparent = null;
        if (getType(curPos + 1).equals(LexerType.RPARENT)) {
            rparent = getNextToken();
        } else {
            errorList.add(getLine(), ErrorType.j);
            //System.out.println(getLine() + " j\n");
        }
        Block block = block();
        return new MainFuncDef(intTK, mainTK, lparent, rparent, block);
    }

    //  FuncType → 'void' | 'int' | 'char'
    public static FuncType funcType() {
        return new FuncType(getNextToken());
    }

    //  FuncFParams → FuncFParam { ',' FuncFParam }
    public static FuncFParams funcFParams() {
        ArrayList<FuncFParam> funcFParamList = new ArrayList<FuncFParam>();
        ArrayList<Token> commaList = new ArrayList<Token>();
        funcFParamList.add(funcFParam());
        while (getType(curPos + 1).equals(LexerType.COMMA)) {
            commaList.add(getNextToken());
            funcFParamList.add(funcFParam());
        }
        return new FuncFParams(funcFParamList, commaList);
    }

    //  FuncFParam → BType Ident ['[' ']']
    public static FuncFParam funcFParam() {
        BType bType = bType();
        Token ident = getNextToken();
        Token lbrack = null;
        Token rbrack = null;
        if (getType(curPos + 1).equals(LexerType.LBRACK)) {
            lbrack = getNextToken();
            if (getType(curPos + 1).equals(LexerType.RBRACK)) {
                rbrack = getNextToken();
            } else {
                errorList.add(getLine(), ErrorType.k);
                //System.out.println(getLine() + " k\n");
            }
        }
        return new FuncFParam(bType, ident, lbrack, rbrack);
    }

    // Block → '{' { BlockItem } '}'
    public static Block block() {
        Token lbrace = getNextToken();
        ArrayList<BlockItem> blockItemList = new ArrayList<BlockItem>();
        while (!getType(curPos + 1).equals(LexerType.RBRACE)) {
            blockItemList.add(blockItem());
        }
        Token rbrace = getNextToken();
        return new Block(lbrace, blockItemList, rbrace);
    }

    // BlockItem → Decl | Stmt
    public static BlockItem blockItem() {
        if (getType(curPos + 1).equals(LexerType.INTTK) || getType(curPos + 1).equals(LexerType.CHARTK) || getType(curPos + 1).equals(LexerType.CONSTTK)) {
            return new BlockItem(decl());
        } else {
            return new BlockItem(stmt());
        }
    }

    // 语句 Stmt → LVal '=' Exp ';' // 每种类型的语句都要覆盖 1
    //| [Exp] ';' //有无Exp两种情况 2
    //| Block 3
    // | 'if' '(' Cond ')' Stmt [ 'else' Stmt ] // 1.有else 2.无else 4
    // | 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt // 1. 无缺省，1种情况 2.
    //ForStmt与Cond中缺省一个，3种情况 3. ForStmt与Cond中缺省两个，3种情况 4. ForStmt与Cond全部
    //缺省，1种情况 5
    //| 'break' ';' | 'continue' ';' 6
    // | 'return' [Exp] ';' // 1.有Exp 2.无Exp 7
    // | LVal '=' 'getint''('')'';' 8
    // | LVal '=' 'getchar''('')'';' 9
    // | 'printf''('StringConst {','Exp}')'';' // 1.有Exp 2.无Exp 10
    public static Stmt stmt(){
        ArrayList<Exp> expList = new ArrayList<Exp>();
        if (getType(curPos + 1).equals(LexerType.IFTK)) { // 4
            Token iftk = getNextToken();
            Token lparent = getNextToken();
            Cond cond = cond();
            Token rparent = null;
            if (getType(curPos + 1).equals(LexerType.RPARENT)) {
                rparent = getNextToken();
            } else {
                errorList.add(getLine(), ErrorType.j);
                //System.out.println(getLine() + " j\n");
            }
            Stmt stmt1 = stmt();
            Token elseToken = null;
            Stmt stmt2 = null;
            if (getType(curPos + 1).equals(LexerType.ELSETK)) {
                elseToken = getNextToken();
                stmt2 = stmt();
            }
            return new Stmt(iftk, lparent, cond, rparent, stmt1, elseToken, stmt2);
        } else if (getType(curPos + 1).equals(LexerType.FORTK)) { //5
            Token fortk = getNextToken();
            Token lparent = getNextToken();
            ForStmt forStmt1 = null;
            if (!getType(curPos + 1).equals(LexerType.SEMICN)) {
                forStmt1 = forStmt();
            }
            Token semicolon = getNextToken();
            Cond cond = null;
            if (!getType(curPos + 1).equals(LexerType.SEMICN)) {
                cond = cond();
            }
            Token semicolon2 = getNextToken();
            ForStmt forStmt2 = null;
            if (!getType(curPos + 1).equals(LexerType.RPARENT)) {
                forStmt2 = forStmt();
            }
            Token rparent = getNextToken();
            Stmt stmt = stmt();
            return new Stmt(fortk, lparent, forStmt1, semicolon, cond, semicolon2, forStmt2, rparent, stmt);
        } else if (getType(curPos + 1).equals(LexerType.BREAKTK) || getType(curPos + 1).equals(LexerType.CONTINUETK)) { // 6
            Token bOrctoken = getNextToken();
            Token semicolon = null;
            if (getType(curPos + 1).equals(LexerType.SEMICN)) {
                semicolon = getNextToken();
            } else {
                errorList.add(getLine(), ErrorType.i);
                //System.out.println(getLine() + " i\n");
            }
            return new Stmt(bOrctoken, semicolon);
        } else if (getType(curPos + 1).equals(LexerType.RETURNTK))  { // 7
            Token returntk = getNextToken();
            int line = getLine();
            if (!getType(curPos + 1).equals(LexerType.SEMICN)) {
                expList.add(exp());
            }
            Token semicolon = null;
            if (getType(curPos + 1).equals(LexerType.SEMICN)) {
                semicolon = getNextToken();
            } else {
                errorList.add(line, ErrorType.i);
                //System.out.println(getLine() + " i\n");
            }
            return new Stmt(returntk, expList, semicolon);
        } else if (getType(curPos + 1).equals(LexerType.PRINTFTK)) { // 10
            Token printftk = getNextToken();
            Token lparent = getNextToken();
            Token stringConst = getNextToken();
            ArrayList<Token> commaList = new ArrayList<Token>();
            while(getType(curPos + 1).equals(LexerType.COMMA)) {
                commaList.add(getNextToken());
                expList.add(exp());
            }
            Token rparent = null;
            if(getType(curPos + 1).equals(LexerType.RPARENT)) {
                rparent = getNextToken();
            } else {
                errorList.add(getLine(), ErrorType.j);
                //System.out.println(getLine() + " j\n");
            }
            Token semicolon = null;
            if (getType(curPos + 1).equals(LexerType.SEMICN)) {
                semicolon = getNextToken();
            } else {
                errorList.add(getLine(), ErrorType.i);
                //System.out.println(getLine() + " i\n");
            }
            return new Stmt(printftk, lparent, stringConst, commaList, expList, rparent, semicolon);
        } else if (getType(curPos + 1).equals(LexerType.LBRACE)) { //3
            return new Stmt(block());
        }else {
            int flag = 0;
            if (getType(curPos + 1).equals(LexerType.IDENFR)) {
                if (getType(curPos + 2).equals(LexerType.ASSIGN)) {
                    flag = 1;
                } else if (getType(curPos+2).equals(LexerType.LBRACK)) {
                    int i = curPos+3;
                    int brackCount = 1;
                    while(brackCount > 0){
                        if(getType(i).equals(LexerType.ASSIGN)){
                            flag = 1;
                            break;
                        } else if(getType(i).equals(LexerType.SEMICN)){
                            break;
                        } else if(getType(i).equals(LexerType.RBRACK)){
                            brackCount--;
                            if(brackCount == 0 && getType(i+1).equals(LexerType.ASSIGN)){
                                flag = 1;
                            }
                        } else if(getType(i).equals(LexerType.LBRACK)) brackCount++;
                        i++;
                    }
                }
            }

            if (flag == 1) {
                LVal lVal = lVal();
                Token assign = getNextToken();
                if (getType(curPos + 1).equals(LexerType.GETINTTK) || getType(curPos + 1).equals(LexerType.GETCHARTK)) {
                    Token gettk = getNextToken();
                    Token lparent = getNextToken();
                    Token rparent = null;
                    if (getType(curPos + 1).equals(LexerType.RPARENT)) {
                        rparent = getNextToken();
                    } else {
                        errorList.add(getLine(), ErrorType.j);
                        //System.out.println(getLine() + " j\n");
                    }
                    Token semicolon = null;
                    if (getType(curPos + 1).equals(LexerType.SEMICN)) {
                        semicolon = getNextToken();
                    } else {
                        errorList.add(getLine(), ErrorType.i);
                        //System.out.println(getLine() + " i\n");
                    }
                    return new Stmt(lVal, assign, gettk, lparent, rparent, semicolon);
                } else {
                    expList.add(exp());
                    Token semicolon = null;
                    if(getType(curPos+1).equals(LexerType.SEMICN)) semicolon = getNextToken();
                    else {
                        errorList.add(getLine(), ErrorType.i);
                        //System.out.println(getLine() + " i\n");
                    }
                    return new Stmt(lVal, assign, expList, semicolon);
                }
            } else{ // [Exp] ';'
                if(!getType(curPos+1).equals(LexerType.SEMICN)){
                    expList.add(exp());
                }
                Token semicolon = null;
                if(getType(curPos+1).equals(LexerType.SEMICN)) semicolon = getNextToken();
                else {
                    errorList.add(getLine(), ErrorType.i);
                    //System.out.println(getLine() + " i\n");
                }
                return new Stmt(expList, semicolon);
            }
        }
    }

    //  ForStmt → LVal '=' Exp
    public static ForStmt forStmt(){
        LVal lVal = lVal();
        Token assign = getNextToken();
        Exp exp = exp();
        return new ForStmt(lVal, assign, exp);
    }

    // Exp → AddExp
    public static Exp exp(){
        return new Exp(addExp());
    }

    // Cond → LOrExp
    public static Cond cond(){
        return new Cond(lOrExp());
    }

    // LVal → Ident ['[' Exp ']']
    public static LVal lVal(){
        Token ident = getNextToken();
        Token lbrack = null;
        Exp exp = null;
        Token rbrack = null;
        if (getType(curPos + 1).equals(LexerType.LBRACK)) {
            lbrack = getNextToken();
            exp = exp();
            if (getType(curPos + 1).equals(LexerType.RBRACK)) {
                rbrack = getNextToken();
            } else {
                errorList.add(getLine(), ErrorType.k);
                //System.out.println(getLine() + " k\n");
            }
        }
        return new LVal(ident, lbrack, exp, rbrack);
    }

    //  PrimaryExp → '(' Exp ')' | LVal | Number | Character
    public static PrimaryExp primaryExp() {
        if (getType(curPos + 1).equals(LexerType.LPARENT)) {
            Token lparent = getNextToken();
            Exp exp = exp();
            Token rparent = null;
            if (getType(curPos + 1).equals(LexerType.RPARENT)) {
                rparent = getNextToken();
            } else {
                errorList.add(getLine(), ErrorType.j);
                //System.out.println(getLine() + " j\n");
            }
            return new PrimaryExp(lparent, exp, rparent);
        } else if (getType(curPos + 1).equals(LexerType.INTCON)) {
            return new PrimaryExp(number());
        } else if (getType(curPos + 1).equals(LexerType.CHRCON)) {
            return new PrimaryExp(character());
        } else {
            return new PrimaryExp(lVal());
        }
    }

    // Number → IntConst
    public static Number number() {
        Token intCon = getNextToken();
        return new Number(intCon);
    }

    // Character → CharConst
    public static Character character() {
        Token charCon = getNextToken();
        return new Character(charCon);
    }

    // UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
    public static UnaryExp unaryExp() {
        if (getType(curPos + 1).equals(LexerType.PLUS) || getType(curPos + 1).equals(LexerType.MINU) || getType(curPos + 1).equals(LexerType.NOT)) {
            UnaryOp unaryOp = unaryOp();
            UnaryExp unaryExp = unaryExp();
            return new UnaryExp(unaryOp, unaryExp);
        } else if (getType(curPos + 1).equals(LexerType.IDENFR) && getType(curPos + 2).equals(LexerType.LPARENT)) {
                Token ident = getNextToken();
                Token lparent = getNextToken();
                FuncRParams funcRParams = null;
            if(!getType(curPos+1).equals(LexerType.RPARENT) && !getType(curPos+1).equals(LexerType.SEMICN)){
                if(getType(curPos+1).equals(LexerType.IDENFR) || getType(curPos+1).equals(LexerType.CHRCON) || getType(curPos+1).equals(LexerType.INTCON)){
                    funcRParams = funcRParams();
                } else if(getType(curPos+1).equals(LexerType.PLUS) || getType(curPos+1).equals(LexerType.MINU) || getType(curPos+1).equals(LexerType.NOT)){
                    funcRParams = funcRParams();
                } else if (getType(curPos+1).equals(LexerType.LPARENT)) {
                    funcRParams = funcRParams();
                }
            }
                Token rparent = null;
                if(getType(curPos + 1).equals(LexerType.RPARENT)) rparent = getNextToken();
                else {
                    errorList.add(getLine(), ErrorType.j);
                    //System.out.println(getLine() + " j\n");
                }
                return new UnaryExp(ident, lparent, funcRParams, rparent);
        } else {
            return new UnaryExp(primaryExp());
        }
    }

    // UnaryOp → '+' | '−' | '!'
    public static UnaryOp unaryOp() {
        return new UnaryOp(getNextToken());
    }

    //  FuncRParams → Exp { ',' Exp }
    public static FuncRParams funcRParams(){
        ArrayList<Exp> expList = new ArrayList<Exp>();
        ArrayList<Token> commaList = new ArrayList<Token>();
        expList.add(exp());
        while (getType(curPos + 1).equals(LexerType.COMMA)) {
            commaList.add(getNextToken());
            expList.add(exp());
        }
        return new FuncRParams(expList, commaList);
    }

    //  MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
    public static MulExp mulExp() {
        ArrayList<UnaryExp> unaryExpList = new ArrayList<>();
        ArrayList<Token> operationList = new ArrayList<>();
        unaryExpList.add(unaryExp());
        while (getType(curPos + 1).equals(LexerType.MULT) || getType(curPos + 1).equals(LexerType.DIV) || getType(curPos + 1).equals(LexerType.MOD)) {
            operationList.add(getNextToken());
            unaryExpList.add(unaryExp());
        }
        return new MulExp(unaryExpList, operationList);
    }

    // AddExp → MulExp | AddExp ('+' | '−') MulExp
    public static AddExp addExp() {
        ArrayList<MulExp> mulExpList = new ArrayList<>();
        ArrayList<Token> operationList = new ArrayList<>();
        mulExpList.add(mulExp());
        while (getType(curPos + 1).equals(LexerType.PLUS) || getType(curPos + 1).equals(LexerType.MINU)) {
            operationList.add(getNextToken());
            mulExpList.add(mulExp());
        }
        return new AddExp(mulExpList, operationList);
    }

    // RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
    public static RelExp relExp(){
        ArrayList<AddExp> addExpList = new ArrayList<>();
        ArrayList<Token> operationList = new ArrayList<>();
        addExpList.add(addExp());
        while (getType(curPos + 1).equals(LexerType.LSS) || getType(curPos + 1).equals(LexerType.GRE) || getType(curPos + 1).equals(LexerType.LEQ) || getType(curPos + 1).equals(LexerType.GEQ)) {
            operationList.add(getNextToken());
            addExpList.add(addExp());
        }
        return new RelExp(addExpList, operationList);
    }

    //  EqExp → RelExp | EqExp ('==' | '!=') RelExp
    public static EqExp eqExp(){
        ArrayList<RelExp> relExpList = new ArrayList<>();
        ArrayList<Token> operationList = new ArrayList<>();
        relExpList.add(relExp());
        while (getType(curPos + 1).equals(LexerType.EQL) || getType(curPos + 1).equals(LexerType.NEQ)) {
            operationList.add(getNextToken());
            relExpList.add(relExp());
        }
        return new EqExp(relExpList, operationList);
    }

    //  LAndExp → EqExp | LAndExp '&&' EqExp
    public static LAndExp lAndExp(){
        ArrayList<EqExp> eqExpList = new ArrayList<>();
        ArrayList<Token> andOpList = new ArrayList<>();
        eqExpList.add(eqExp());
        while (getType(curPos + 1).equals(LexerType.AND)) {
            andOpList.add(getNextToken());
            eqExpList.add(eqExp());
        }
        return new LAndExp(eqExpList, andOpList);
    }

    // LOrExp → LAndExp | LOrExp '||' LAndExp
    public static LOrExp lOrExp(){
        ArrayList<LAndExp> lAndExpList = new ArrayList<>();
        ArrayList<Token> orOpList = new ArrayList<>();
        lAndExpList.add(lAndExp());
        while (getType(curPos + 1).equals(LexerType.OR)) {
            orOpList.add(getNextToken());
            lAndExpList.add(lAndExp());
        }
        return new LOrExp(lAndExpList, orOpList);
    }

    //  ConstExp → AddExp
    public static ConstExp constExp(){
        return new ConstExp(addExp());
    }
}
