package fronted.Parser;

import fronted.Lexer.Error;
import fronted.Lexer.Token;
import fronted.Lexer.TokenType;
import fronted.Lexer.TokensIterator;
import fronted.Parser.SyntaxTree.*;
import fronted.Parser.SyntaxTree.Character;
import fronted.Parser.SyntaxTree.Number;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

/**
 * @author
 * @Description:
 * @date 2024/10/11 15:53
 */
public class Parser {
    private TokensIterator iterator;
    private ArrayList<Token> tokenList;
    private List<Error> errors = new ArrayList<>();
    private CompUnit compUnit;

    public Parser(ArrayList<Token> tokens){
        this.tokenList = tokens;
        iterator = new TokensIterator(tokenList);
    }

    public List<Error> getErrors() {
        return errors;
    }

    public void output() throws IOException {
        //没有错误正常情况输出时
        try (BufferedWriter writer = new BufferedWriter(new FileWriter("parser.txt"))) {
            writer.write(this.compUnit.output());
        }catch (IOException e) {
            System.err.println("Error writing to file: " + e.getMessage());
        }

    }
    public void parse(){
        this.compUnit = parseCompUnit();
    }
    private CompUnit parseCompUnit(){
        CompUnit compUnit = new CompUnit(new ArrayList<>(),new ArrayList<>(),null);

        /* parse decls */
        Token next = iterator.readNextToken();
        Token nNext = iterator.readNextToken();
        while (iterator.hasNext()) {
            Token nNNext = iterator.readNextToken();
            if (nNNext.getType().equals(TokenType.LPARENT)) {
                iterator.unReadToken(3);
                break;
            } else {
                iterator.unReadToken(1);
            }
            if ((next.getType().equals(TokenType.CONSTTK) &&
                    nNext.getType().equals(TokenType.INTTK)) ||
                    (next.getType().equals(TokenType.CONSTTK) &&
                            nNext.getType().equals(TokenType.CHARTK))||
                    (next.getType().equals(TokenType.CHARTK) &&
                            nNext.getType().equals(TokenType.IDENFR))||
                    (next.getType().equals(TokenType.INTTK) &&
                            nNext.getType().equals(TokenType.IDENFR))) {
                /* next -> const && nNext -> int */
                /* next -> const && nNext -> char */
                /* next -> int && nNext -> IDENFR */
                /* next -> char && nNext -> IDENFR */
                iterator.unReadToken(2);
                compUnit.addDecl(parseDecl());
            } else {
                iterator.unReadToken(2);
                break;
            }
            next = iterator.readNextToken();
            nNext = iterator.readNextToken();
        }

        /* parse FuncDefs */
        next = iterator.readNextToken();
        nNext = iterator.readNextToken();
        while (iterator.hasNext()) {
            if ((next.getType().equals(TokenType.INTTK) ||
                    next.getType().equals(TokenType.VOIDTK)||
                    next.getType().equals(TokenType.CHARTK)) &&
                    nNext.getType().equals(TokenType.IDENFR)) {
                /* next -> int/void/char && nNext -> IDENFR */
                iterator.unReadToken(2);
                FuncDef funcDef = parseFuncDef();
                compUnit.addFuncDef(funcDef);
            } else {
                iterator.unReadToken(2);
                break;
            }
            next = iterator.readNextToken();
            nNext = iterator.readNextToken();
        }

        /* parse MainFuncDef */
        Token intTk; // 'int'
        Token mainTk; // 'main'
        Token leftParent; // '('
        Token rightParent = null; // ')'
        Block block;

        intTk = iterator.readNextToken();
        mainTk = iterator.readNextToken();
        leftParent = iterator.readNextToken();
        Token token = iterator.readNextToken();
        if(!token.getType().equals(TokenType.RPARENT)){
            errors.add(new Error(iterator.peekPreviousToken().getLine(), "j"));
            iterator.unReadToken(1);
        }else{
            rightParent = token;
        }
        block = parseBlock();
        MainFuncDef mainFuncDef = new MainFuncDef(intTk,mainTk,leftParent,rightParent,block);
        compUnit.setMainFuncDef(mainFuncDef);

        return compUnit;
    }

    private FuncDef parseFuncDef(){
        FuncType funcType;
        Token ident;
        Token leftParent; // '(
        FuncFParams funcFParams = null; // may
        Token rightParent = null; // ')'
        Block block;

        funcType = new FuncType(iterator.readNextToken());
        ident = iterator.readNextToken();
        leftParent = iterator.readNextToken();
        Token token = iterator.readNextToken();
        if(token.getType().equals(TokenType.INTTK)||
                token.getType().equals(TokenType.CHARTK)){
            iterator.unReadToken(1);
            // FuncFParams
            funcFParams = parserFuncFParams();
            token = iterator.readNextToken();
            if(token.getType().equals(TokenType.RPARENT)){
                rightParent = token;
            }
            else{
                errors.add(new Error(iterator.peekPreviousToken().getLine(), "j"));
                iterator.unReadToken(1);
            }

        }else if(token.getType().equals(TokenType.RPARENT)){
            rightParent = token;
        }
        else{
            errors.add(new Error(iterator.peekPreviousToken().getLine(), "j"));
            iterator.unReadToken(1);
        }

        block = parseBlock();

        return new FuncDef(funcType,ident,leftParent,funcFParams,rightParent,block);
    }

    private Block parseBlock(){
        Token leftBrace; // '{'
        ArrayList<BlockItem> blockItems = new ArrayList<>();  //may empty
        Token rightBrace; // '}'
        leftBrace = iterator.readNextToken();
        Token token = iterator.readNextToken();
        while (!token.getType().equals(TokenType.RBRACE)) {
            iterator.unReadToken(1);
            blockItems.add(parseBlockItem());
            token = iterator.readNextToken();
        }
        rightBrace = token;
        return new Block(leftBrace,blockItems,rightBrace);
    }

    private BlockItem parseBlockItem(){
        Token token = iterator.readNextToken();
        if (token.getType().equals(TokenType.CONSTTK) ||
                token.getType().equals(TokenType.INTTK)||
                token.getType().equals(TokenType.CHARTK)) {
            // decl
            iterator.unReadToken(1);
            return new BlockItem(parseDecl());
        } else {
            // stmt
            iterator.unReadToken(1);
            return new BlockItem(parseStmt());
        }
    }

    private Stmt parseStmt(){
        Token token = iterator.readNextToken();
        if(token.getType().equals(TokenType.IFTK)){
            // if
            Token ifTk; // 'if'
            Token leftParent; // '('
            Cond cond;
            Token rightParent = null; // ')'
            Stmt ifStmt;
            Token elseTk = null; // 'else' MAY exist
            Stmt elseStmt = null; // MAY exist

            ifTk = token;
            leftParent = iterator.readNextToken();
            cond = parseCond();
            token = iterator.readNextToken();
            if(!token.getType().equals(TokenType.RPARENT)){
                errors.add(new Error(iterator.peekPreviousToken().getLine(), "j"));
                iterator.unReadToken(1);
            }else{
                rightParent = token;
            }
            ifStmt = parseStmt();
            token = iterator.readNextToken();
            if(token.getType().equals(TokenType.ELSETK)){
                elseTk = token;
                elseStmt = parseStmt();
            }else{
                iterator.unReadToken(1);
            }
            StmtNodeOfIf stmtNodeOfIf = new StmtNodeOfIf(ifTk,leftParent,cond,rightParent,ifStmt,elseTk,elseStmt);
            return new Stmt(stmtNodeOfIf);
        }
        else if(token.getType().equals(TokenType.FORTK)){
            Token forTk ; // for
            Token leftParent; // '('
            ForStmt firstForStmt = null;  // may
            Token firstSemicn; // ';'
            Cond cond= null;  //may
            Token secondSemicn; // ';'
            ForStmt secondForStmt= null;  // may
            Token rightParent= null; // ')'
            Stmt stmt;

            forTk =token;
            leftParent = iterator.readNextToken();
            token = iterator.readNextToken();
            if(!token.getType().equals(TokenType.SEMICN)){
                iterator.unReadToken(1);
                firstForStmt = parseForStmt();
                firstSemicn = iterator.readNextToken();
            }else{
                firstSemicn = token;
            }
            token = iterator.readNextToken();
            if(!token.getType().equals(TokenType.SEMICN)){
                iterator.unReadToken(1);
                cond = parseCond();
                secondSemicn = iterator.readNextToken();
            }else{
                secondSemicn = token;
            }
            token = iterator.readNextToken();
            if(token.getType().equals(TokenType.IDENFR)){
                // secondForStmt
                iterator.unReadToken(1);
                secondForStmt = parseForStmt();
                token = iterator.readNextToken();
            }
            if(!token.getType().equals(TokenType.RPARENT)){
                errors.add(new Error(iterator.peekPreviousToken().getLine(), "j"));
                iterator.unReadToken(1);
            }else{
                rightParent = token;
            }
            stmt = parseStmt();
            StmtNodeOfFor stmtNodeOfFor = new StmtNodeOfFor(forTk,leftParent,firstForStmt,
                    firstSemicn,cond,secondSemicn,secondForStmt,rightParent,stmt);
            return new Stmt(stmtNodeOfFor);
        }
        else if(token.getType().equals(TokenType.BREAKTK)){
            Token breakTk; // break
            Token semicn = null;
            breakTk = token;
            token = iterator.readNextToken();
            if(!token.getType().equals(TokenType.SEMICN)){
                errors.add(new Error(iterator.peekPreviousToken().getLine(), "i"));
                iterator.unReadToken(1);
            }else{
                semicn = token;
            }

            StmtNodeOfBC stmtNodeOfBC = new StmtNodeOfBC(breakTk,semicn);
            return new Stmt(stmtNodeOfBC);
        }
        else if(token.getType().equals(TokenType.CONTINUETK)){
            Token continueTk; // continue
            Token semicn = null;
            continueTk = token;
            token = iterator.readNextToken();
            if(!token.getType().equals(TokenType.SEMICN)){
                errors.add(new Error(iterator.peekPreviousToken().getLine(), "i"));
                iterator.unReadToken(1);
            }else{
                semicn = token;
            }

            StmtNodeOfBC stmtNodeOfBC = new StmtNodeOfBC(continueTk,semicn);
            return new Stmt(stmtNodeOfBC);
        }
        else if(token.getType().equals(TokenType.RETURNTK)){
            Token returnTk; // return
            Exp exp = null; //may
            Token semicn = null; // ';'

            returnTk = token;
            token = iterator.readNextToken();
            if(isMatchExp(token)){
                iterator.unReadToken(1);
                exp = parseExp();
                token = iterator.readNextToken();
            }

            if(!token.getType().equals(TokenType.SEMICN)){
                errors.add(new Error(iterator.peekPreviousToken().getLine(), "i"));
                iterator.unReadToken(1);
            }else{
                semicn = token;
            }
            StmtNodeOfReturn stmtNodeOfReturn = new StmtNodeOfReturn(returnTk,exp,semicn);
            return new Stmt(stmtNodeOfReturn);
        }
        else if(token.getType().equals(TokenType.PRINTFTK)){
            Token printfTk;
            Token leftParent; // '('
            StringConst stringConst;
            ArrayList<Token> commmas = new ArrayList<>(); // ',' MAY exist
            ArrayList<Exp> exps = new ArrayList<>();
            Token rightParent = null; // ')'
            Token semicn = null; // ';'

            printfTk = token;
            leftParent = iterator.readNextToken();
            stringConst = new StringConst(iterator.readNextToken());
            token = iterator.readNextToken();
            while (token.getType().equals(TokenType.COMMA)) {
                commmas.add(token);
                exps.add(parseExp());
                token = iterator.readNextToken();
            }
            if(token.getType().equals(TokenType.RPARENT)){
                rightParent = token;
            }else{
                errors.add(new Error(iterator.peekPreviousToken().getLine(), "j"));
                iterator.unReadToken(1);
            }

            token = iterator.readNextToken();
            if(token.getType().equals(TokenType.SEMICN)){
                semicn = token;
            }else{
                errors.add(new Error(iterator.peekPreviousToken().getLine(), "i"));
                iterator.unReadToken(1);
            }
            StmtNodeOfPrintf stmtNodeOfPrintf = new StmtNodeOfPrintf(printfTk,leftParent,
                    stringConst,commmas,exps,rightParent,semicn);
            return new Stmt(stmtNodeOfPrintf);
        }
        else if(token.getType().equals(TokenType.SEMICN)){
            Exp exp = null;  // may
            Token semicn;  // ';'

            semicn = token;
            StmtNodeOfExp stmtNodeOfExp = new StmtNodeOfExp(exp,semicn);
            return new Stmt(stmtNodeOfExp);
        }
        else if(token.getType().equals(TokenType.LBRACE)){
            // block
            iterator.unReadToken(1);
            Block block = parseBlock();
            return new Stmt(block);
        }
        else if(token.getType().equals(TokenType.IDENFR)){
            /* need to distinguish LVal = Exp, LVal = getint and [Exp] */
            int num = 1;
            int mode = 0; // 0:assign 1:inputint 2:inputchar
            boolean flag = false; // LVal = Exp; || LVal = getint();
            while (!token.getType().equals(TokenType.SEMICN)) {
                token = iterator.readNextToken();
                num += 1;
                if (token.getType().equals(TokenType.ASSIGN)) {
                    flag = true;
                }
                if (token.getType().equals(TokenType.GETINTTK)) {
                    mode = 1;
                }
                else if (token.getType().equals(TokenType.GETCHARTK)) {
                    mode = 2;
                }
            }
            iterator.unReadToken(num);
            if (flag) {
                if (mode == 0) {
                    // LVal '=' Exp ';'
                    LVal lVal;
                    Token equal;  // '='
                    Exp exp;
                    Token semicn = null;  // ';'

                    lVal = parseLVal();
                    equal  =iterator.readNextToken();
                    exp = parseExp();
                    token = iterator.readNextToken();
                    if(token.getType().equals(TokenType.SEMICN)){
                        semicn = token;
                    }else{
                        errors.add(new Error(iterator.peekPreviousToken().getLine(), "i"));
                        iterator.unReadToken(1);
                    }
                    StmtNodeOfAssign stmtNodeOfAssign = new StmtNodeOfAssign(lVal,equal,exp,semicn);
                    return new Stmt(stmtNodeOfAssign);
                } else if (mode == 1) {
                    //  LVal '=' 'getint''('')'';'
                    LVal lVal;
                    Token equal;
                    Token getintTk;
                    Token leftParent; // '('
                    Token rightParent = null; // ')'
                    Token semicn = null; // ';'

                    lVal = parseLVal();
                    equal  =iterator.readNextToken();
                    getintTk = iterator.readNextToken();
                    leftParent = iterator.readNextToken();
                    token = iterator.readNextToken();
                    if(token.getType().equals(TokenType.RPARENT)){
                        rightParent = token;
                    }else{
                        errors.add(new Error(iterator.peekPreviousToken().getLine(), "j"));
                        iterator.unReadToken(1);
                    }
                    token = iterator.readNextToken();
                    if(token.getType().equals(TokenType.SEMICN)){
                        semicn = token;
                    }else{
                        errors.add(new Error(iterator.peekPreviousToken().getLine(), "i"));
                        iterator.unReadToken(1);
                    }

                    StmtNodeOfGetint stmtNodeOfGetint = new StmtNodeOfGetint(lVal,equal ,getintTk,leftParent,rightParent,semicn);
                    return new Stmt(stmtNodeOfGetint);
                }else if (mode == 2) {
                    //  LVal '=' 'getchar''('')'';'
                    LVal lVal;
                    Token equal;
                    Token getcharTk;
                    Token leftParent; // '('
                    Token rightParent = null; // ')'
                    Token semicn = null; // ';'

                    lVal = parseLVal();
                    equal  =iterator.readNextToken();
                    getcharTk = iterator.readNextToken();
                    leftParent = iterator.readNextToken();
                    token = iterator.readNextToken();
                    if(token.getType().equals(TokenType.RPARENT)){
                        rightParent = token;
                    }else{
                        errors.add(new Error(iterator.peekPreviousToken().getLine(), "j"));
                        iterator.unReadToken(1);
                    }
                    token = iterator.readNextToken();
                    if(token.getType().equals(TokenType.SEMICN)){
                        semicn = token;
                    }else{
                        errors.add(new Error(iterator.peekPreviousToken().getLine(), "i"));
                        iterator.unReadToken(1);
                    }

                    StmtNodeOfGetchar stmtNodeOfGetchar = new StmtNodeOfGetchar(lVal,equal ,getcharTk,leftParent,rightParent,semicn);
                    return new Stmt(stmtNodeOfGetchar);
                }
                else {
                    System.out.println("REACHED UNEXPECTED BRANCH");
                }
            } else {
                // [Exp] ';'
                Exp exp = null;  // may
                Token semicn = null;  // ';'

                exp = parseExp();
                token = iterator.readNextToken();
                if(token.getType().equals(TokenType.SEMICN)){
                    semicn = token;
                }else{
                    errors.add(new Error(iterator.peekPreviousToken().getLine(), "i"));
                    iterator.unReadToken(1);
                }
                StmtNodeOfExp stmtNodeOfExp = new StmtNodeOfExp(exp,semicn);
                return new Stmt(stmtNodeOfExp);
            }
        }
        else if(isMatchExp(token)){
            iterator.unReadToken(1);
            Exp exp = null;  // may
            Token semicn = null;  // ';'

            exp = parseExp();
            token = iterator.readNextToken();
            if(token.getType().equals(TokenType.SEMICN)){
                semicn = token;
            }else{
                errors.add(new Error(iterator.peekPreviousToken().getLine(), "i"));
                iterator.unReadToken(1);
            }
            StmtNodeOfExp stmtNodeOfExp = new StmtNodeOfExp(exp,semicn);
            return new Stmt(stmtNodeOfExp);
        }
        else{
            errors.add(new Error(iterator.peekPreviousToken().getLine(), "i"));
            iterator.unReadToken(1);
            StmtNodeOfExp stmtNodeOfExp = new StmtNodeOfExp(null,null);
            return new Stmt(stmtNodeOfExp);
        }
        return null;
    }


    private ForStmt parseForStmt(){
        LVal lVal;
        Token equal;
        Exp exp;

        lVal = parseLVal();
        equal = iterator.readNextToken();
        exp = parseExp();

        return new ForStmt(lVal, equal,exp);
    }

    private Cond parseCond(){
        return new Cond(parseLOrExp());
    }

    private LOrExp parseLOrExp(){
        LAndExp necLAndExp;
        ArrayList<Token> lOrOps =new ArrayList<>(); // lOrOps  ||
        ArrayList<LAndExp> LAndExps = new ArrayList<>(); // LAndExps

        necLAndExp = parseLAndExp();
        Token token = iterator.readNextToken();
        while (token.getType().equals(TokenType.OR))  {
            lOrOps.add(token);
            LAndExps.add(parseLAndExp());
            token = iterator.readNextToken();
        }
        iterator.unReadToken(1);
        return new LOrExp(necLAndExp,lOrOps,LAndExps);
    }

    private LAndExp parseLAndExp(){
        EqExp necEqExp;
        ArrayList<Token> lAndOps = new ArrayList<>(); // lAndOps  &&
        ArrayList<EqExp> eqExps = new ArrayList<>(); // EqExps

        necEqExp = parseEqExp();
        Token token = iterator.readNextToken();
        while (token.getType().equals(TokenType.AND) )  {
            lAndOps.add(token);
            eqExps.add(parseEqExp());
            token = iterator.readNextToken();
        }
        iterator.unReadToken(1);
        return new LAndExp(necEqExp,lAndOps, eqExps);
    }

    private EqExp parseEqExp(){
        RelExp necRelExp;
        ArrayList<Token> eqOps= new ArrayList<>(); // eqOps  == / !=
        ArrayList<RelExp> relExps = new ArrayList<>(); // relExps

        necRelExp = parseRelExp();
        Token token = iterator.readNextToken();
        while (token.getType().equals(TokenType.EQL) || // ==
                token.getType().equals(TokenType.NEQ) ) { // !=
            eqOps.add(token);
            relExps.add(parseRelExp());
            token = iterator.readNextToken();
        }
        iterator.unReadToken(1);
        return new EqExp(necRelExp,eqOps, relExps);
    }

    private RelExp parseRelExp(){
        AddExp necAddExp;
        ArrayList<Token> relOps = new ArrayList<>(); // relOps  > / < / >= / <=
        ArrayList<AddExp> addExps = new ArrayList<>(); // addExps

        necAddExp = parseAddExp();
        Token token = iterator.readNextToken();
        while (token.getType().equals(TokenType.LSS) || // <
                token.getType().equals(TokenType.GRE) || // >
                token.getType().equals(TokenType.LEQ) || // <=
                token.getType().equals(TokenType.GEQ)) { // >=
            relOps.add(token);
            addExps.add(parseAddExp());
            token = iterator.readNextToken();
        }
        iterator.unReadToken(1);
        return new RelExp(necAddExp,relOps, addExps);
    }

    private FuncFParams parserFuncFParams(){
        FuncFParam necFuncFParam;
        ArrayList<Token> commas = new ArrayList<>(); // ','may
        ArrayList<FuncFParam> funcFParams = new ArrayList<>(); // may

        necFuncFParam = parserFuncFParam();

        Token token = iterator.readNextToken();
        while (token.getType().equals(TokenType.COMMA)) {
            /* is ',' */
            commas.add(token);
            funcFParams.add(parserFuncFParam());
            token = iterator.readNextToken();
        }
        iterator.unReadToken(1);
        return new FuncFParams(necFuncFParam,commas,funcFParams);
    }

    private FuncFParam parserFuncFParam(){
        BType bType;
        Token ident;
        Token leftBrack = null; // '['  may
        Token rightBracket = null; // ']'  may

        bType = new BType(iterator.readNextToken());
        ident = iterator.readNextToken();
        Token next = iterator.readNextToken();
        Token nNext = iterator.readNextToken();
        if (next.getType().equals(TokenType.LBRACK)){
            leftBrack = next;
            if(nNext.getType().equals(TokenType.RBRACK)){
                rightBracket = nNext;
            }else{
                errors.add(new Error(iterator.peekPreviousToken().getLine(), "k"));
                iterator.unReadToken(1);
            }
        }else{
            iterator.unReadToken(2);
        }
        return new FuncFParam(bType,ident,leftBrack,rightBracket);

    }

    private Decl parseDecl() {
        Token next = iterator.readNextToken();
        iterator.unReadToken(1);
        SyntaxNode declNode = null;
        if (next.getType().equals(TokenType.CONSTTK)) {
            declNode = parseConstDecl();
        } else if (next.getType().equals(TokenType.INTTK) || next.getType().equals(TokenType.CHARTK)) {
            declNode = parseVarDecl();
        } else {
            /* ERROR */
            System.out.println("111ERROR!!!");
        }
        Decl decl = new Decl(declNode);
        return decl;
    }

    private VarDecl parseVarDecl(){
        ArrayList<Token> commas = new ArrayList<>();
        ArrayList<VarDef> varDefs = new ArrayList<>();
        BType btype;
        VarDef necVarDef;
        Token semicn = null;

        btype = new BType(iterator.readNextToken());
        necVarDef = parseVarDef();
        Token token = iterator.readNextToken();
        while (token.getType().equals(TokenType.COMMA)) {
            /* is ',' */
            commas.add(token);
            varDefs.add(parseVarDef());
            token = iterator.readNextToken();
        }
        /* token SHOULD be ';' */
        if(!token.getType().equals(TokenType.SEMICN)){
            errors.add(new Error(iterator.peekPreviousToken().getLine(), "i"));
            iterator.unReadToken(1);
        }
        else{
            semicn = token;
        }
        return new VarDecl( btype,
                necVarDef, commas, varDefs, semicn);
    }

    private VarDef parseVarDef(){
        Token ident;
        Token leftBrack = null;
        ConstExp constExp = null;
        Token rightBrack = null; // ']'
        Token equal = null; // '='
        InitVal initval = null;
        Token token;
        ident = iterator.readNextToken();
        token = iterator.readNextToken();
        if(token.getType().equals(TokenType.LBRACK)) {
            /* '[' */
            leftBrack = token;
            /* ConstExp */
            constExp = parseConstExp();
            token = iterator.readNextToken();
            /* ']' */
            if (!token.getType().equals(TokenType.RBRACK)) {
                errors.add(new Error(iterator.peekPreviousToken().getLine(), "k"));
            }
            else{
                rightBrack = token;
                token = iterator.readNextToken();
            }
        }
        if(token.getType().equals(TokenType.ASSIGN)){
            equal = token;
            initval = parseInitVal();
        }
        else{
            iterator.unReadToken(1);
        }
        return new VarDef(ident, leftBrack, constExp,
                rightBrack, equal, initval);
    }

    private InitVal parseInitVal(){
        Token next = iterator.readNextToken();
        if(next.getType().equals(TokenType.LBRACE)){
            // '{' [ Exp { ',' Exp } ] '}'
            iterator.unReadToken(1);
            InitValNodeOfExpArray initValNodeOfExpArray = parseInitValNodeOfExpArray();
            return new InitVal(initValNodeOfExpArray);
        }else if(next.getType().equals(TokenType.STRCON)){
            StringConst stringConst = new StringConst(next);
            return new InitVal(stringConst);
        }else {
            iterator.unReadToken(1);
            Exp exp = parseExp();
            return new InitVal(exp);
        }
    }

    private InitValNodeOfExpArray parseInitValNodeOfExpArray(){
        Token leftBrace; // '{'
        Exp mayExp = null; // may
        ArrayList<Token> commas = new ArrayList<>(); // may
        ArrayList<Exp> exps = new ArrayList<>(); // may
        Token rightBrace; // '}'

        leftBrace = iterator.readNextToken();
        Token token = iterator.readNextToken();
        if (!token.getType().equals(TokenType.RBRACE)) {
            iterator.unReadToken(1);
            mayExp = parseExp();
            token = iterator.readNextToken();
            while (token.getType().equals(TokenType.COMMA)) { // ','
                commas.add(token);
                exps.add(parseExp());
                token = iterator.readNextToken();
            }
            iterator.unReadToken(1);
        } else {
            iterator.unReadToken(1);
        }
        rightBrace = iterator.readNextToken();
        return new InitValNodeOfExpArray(leftBrace,mayExp,commas,exps,rightBrace);
    }

    private ConstDecl parseConstDecl(){
        ArrayList<Token> commas = new ArrayList<>();
        ArrayList<ConstDef> constDefs = new ArrayList<>();
        Token constTk = null;
        BType btype;
        ConstDef necConstDef;
        Token semicn = null;

        Token token = iterator.readNextToken();
        if (token.getType().equals(TokenType.CONSTTK)) {
            constTk = token;
        }
        else{
            error();
        }
        btype = new BType(iterator.readNextToken());
        necConstDef = parseConstDef();
        token = iterator.readNextToken();
        while (token.getType().equals(TokenType.COMMA)) {
            /* is ',' */
            commas.add(token);
            constDefs.add(parseConstDef());
            token = iterator.readNextToken();
        }
        /* token SHOULD be ';' */
        if(!token.getType().equals(TokenType.SEMICN)){
            errors.add(new Error(iterator.peekPreviousToken().getLine(), "i"));
            iterator.unReadToken(1);
        }
        else{
            semicn = token;
        }
        return new ConstDecl(constTk, btype,
                necConstDef, commas, constDefs, semicn);
    }

    private ConstDef parseConstDef(){
        Token ident;
        Token leftBrack = null;
        ConstExp constExp = null;
        Token rightBrack = null; // ']'
        Token equal; // '='
        ConstInitVal constInitval;
        Token token;
        ident = iterator.readNextToken();
        token = iterator.readNextToken();
        if(token.getType().equals(TokenType.LBRACK)) {
            /* '[' */
            leftBrack = token;
            /* ConstExp */
            constExp = parseConstExp();
            token = iterator.readNextToken();
            /* ']' */
            if (!token.getType().equals(TokenType.RBRACK)) {
                errors.add(new Error(iterator.peekPreviousToken().getLine(), "k"));
            }
            else{
                rightBrack = token;
                token = iterator.readNextToken();
            }
        }
        equal = token;
        constInitval = parseConstInitVal();
        return new ConstDef(ident, leftBrack, constExp,
                rightBrack, equal, constInitval);
    }

    private ConstInitVal parseConstInitVal(){
        Token next = iterator.readNextToken();
        if(next.getType().equals(TokenType.LBRACE)){
            // '{' [ ConstExp { ',' ConstExp } ] '}'
            iterator.unReadToken(1);
            ConstInitValNodeOfExpArray constInitValNodeOfExpArray = parseConstInitValNodeOfExpArray();
            return new ConstInitVal(constInitValNodeOfExpArray);
        }else if(next.getType().equals(TokenType.STRCON)){
            StringConst stringConst = new StringConst(next);
            return new ConstInitVal(stringConst);
        }else {
            iterator.unReadToken(1);
            ConstExp constExp = parseConstExp();
            return new ConstInitVal(constExp);
        }
    }

    private ConstInitValNodeOfExpArray parseConstInitValNodeOfExpArray(){
        Token leftBrace; // '{'
        ConstExp mayConstExp = null; // may
        ArrayList<Token> commas = new ArrayList<>(); // may
        ArrayList<ConstExp> constExps = new ArrayList<>(); // may
        Token rightBrace; // '}'

        leftBrace = iterator.readNextToken();
        Token token = iterator.readNextToken();
        if (!token.getType().equals(TokenType.RBRACE)) {
            iterator.unReadToken(1);
            mayConstExp = parseConstExp();
            token = iterator.readNextToken();
            while (token.getType().equals(TokenType.COMMA)) { // ','
                commas.add(token);
                constExps.add(parseConstExp());
                token = iterator.readNextToken();
            }
            iterator.unReadToken(1);
        } else {
            iterator.unReadToken(1);
        }
        rightBrace = iterator.readNextToken();
        return new ConstInitValNodeOfExpArray(leftBrace,mayConstExp,commas,constExps,rightBrace);
    }
    private ConstExp parseConstExp(){
        AddExp addExp;
        addExp = parseAddExp();
        return new ConstExp(addExp);
    }

    private AddExp parseAddExp(){
        MulExp necMulExp;
        ArrayList<Token> addOps = new ArrayList<>(); // addOps
        ArrayList<MulExp> mulExps = new ArrayList<>(); // mulExps

        necMulExp = parseMulExp();
        Token token = iterator.readNextToken();
        while (token.getType().equals(TokenType.PLUS) ||
                token.getType().equals(TokenType.MINU)) {
            addOps.add(token);
            mulExps.add(parseMulExp());
            token = iterator.readNextToken();
        }
        iterator.unReadToken(1);
        return new AddExp(necMulExp, addOps, mulExps);
    }

    private MulExp parseMulExp(){
        UnaryExp necUnaryExp;
        ArrayList<Token> mulOps = new ArrayList<>(); // mulOps
        ArrayList<UnaryExp> UnaryExps = new ArrayList<>(); // UnaryExps

        necUnaryExp = parseUnaryExp();
        Token token = iterator.readNextToken();
        while (token.getType().equals(TokenType.MULT) ||
                token.getType().equals(TokenType.DIV)||
                token.getType().equals(TokenType.MOD)) {
            mulOps.add(token);
            UnaryExps.add(parseUnaryExp());
            token = iterator.readNextToken();
        }
        iterator.unReadToken(1);
        return new MulExp(necUnaryExp, mulOps, UnaryExps);
    }

    private UnaryExp parseUnaryExp(){
        Token next = iterator.readNextToken();
        Token nNext = iterator.readNextToken();

        if (next.getType().equals(TokenType.IDENFR) &&
                nNext.getType().equals(TokenType.LPARENT)) {
            // Ident '(' [FuncRParams] ')'
            iterator.unReadToken(2);
            UnaryExpNodeOfFunc unaryExpNodeOfFunc = parseUnaryExpNodeOfFunc();
            return new UnaryExp(unaryExpNodeOfFunc);
        } else if (next.getType().equals(TokenType.LPARENT) ||
                next.getType().equals(TokenType.IDENFR) ||
                next.getType().equals(TokenType.INTCON) ||
                next.getType().equals(TokenType.CHRCON)) {
            // PrimaryExp
            iterator.unReadToken(2);
            PrimaryExp primaryExp = parsePrimaryExp();
            return new UnaryExp(primaryExp);
        } else if (next.getType().equals(TokenType.PLUS) ||
                next.getType().equals(TokenType.MINU) ||
                next.getType().equals(TokenType.NOT)) {
            // UnaryOp UnaryExp
            iterator.unReadToken(2);
            UnaryExpNodeOfUnaryOp unaryExpNodeOfUnaryOp =parseUnaryExpNodeOfUnaryOp();
            return new UnaryExp(unaryExpNodeOfUnaryOp);
        }
        System.out.println("2222ERROR!!!");
        return null;
    }

    private UnaryExpNodeOfUnaryOp parseUnaryExpNodeOfUnaryOp(){
        UnaryOp unaryOp;
        UnaryExp unaryExp;
        unaryOp = new UnaryOp(iterator.readNextToken());
        unaryExp = parseUnaryExp();
        return new UnaryExpNodeOfUnaryOp(unaryOp,unaryExp);
    }
    private PrimaryExp parsePrimaryExp(){
        SyntaxNode primaryExpNode;
        Token token = iterator.readNextToken();
        if (token.getType().equals(TokenType.LPARENT)) { // '('
            iterator.unReadToken(1);
            PrimaryExpNodeOfExp primaryExpNodeOfExp = parsePrimaryExpNodeOfExp();
            return new PrimaryExp(primaryExpNodeOfExp);
        } else if (token.getType().equals(TokenType.IDENFR)) { // LVAL
            iterator.unReadToken(1);
            LVal lVal = parseLVal();
            return new PrimaryExp(lVal);
        } else if (token.getType().equals(TokenType.INTCON)) { // INT CONST
            iterator.unReadToken(1);
            Number number = new Number(iterator.readNextToken());
            return new PrimaryExp(number);
        }else if (token.getType().equals(TokenType.CHRCON)) { // CHAR CONST
            iterator.unReadToken(1);
            Character character = new Character(iterator.readNextToken());
            return new PrimaryExp(character);
        }
        System.out.println("3333ERROR!!!");
        return null;
    }

    private LVal parseLVal(){
        Token ident;
        Token leftBrack = null; // '['
        Exp exp = null;
        Token rightBrack = null; // ']'

        ident = iterator.readNextToken();
        Token token = iterator.readNextToken();
        if(token.getType().equals(TokenType.LBRACK)){
            leftBrack = token;
            exp = parseExp();
            token = iterator.readNextToken();
            if (token.getType().equals(TokenType.RBRACK)) {
                rightBrack = token;
            } else {
                errors.add(new Error(iterator.peekPreviousToken().getLine(), "k"));
                iterator.unReadToken(1);
            }
        }
        else{
            iterator.unReadToken(1);
        }

        return new LVal(ident,leftBrack,exp,rightBrack);
    }

    private PrimaryExpNodeOfExp parsePrimaryExpNodeOfExp(){
        Token leftParent; // '('
        Exp exp;
        Token rightParent = null; // ')'
        leftParent = iterator.readNextToken();
        exp = parseExp();
        Token token = iterator.readNextToken();
        if (token.getType().equals(TokenType.RPARENT)) {
            rightParent = token;
        } else {
            errors.add(new Error(iterator.peekPreviousToken().getLine(), "j"));
            iterator.unReadToken(1);
        }
        return new PrimaryExpNodeOfExp(leftParent,exp,rightParent);
    }
    private UnaryExpNodeOfFunc parseUnaryExpNodeOfFunc(){
        Token ident = iterator.readNextToken();
        Token leftParent =  iterator.readNextToken();
        FuncRParams funcRParams = null;
        Token rightParent = null;
        Token token = iterator.readNextToken();
        if (token.getType().equals(TokenType.LPARENT)
                || token.getType().equals(TokenType.IDENFR)
                || token.getType().equals(TokenType.INTCON)
                || token.getType().equals(TokenType.CHRCON)
                || token.getType().equals(TokenType.PLUS)
                || token.getType().equals(TokenType.MINU)
                || token.getType().equals(TokenType.NOT)
        ) {
            iterator.unReadToken(1);
            funcRParams = parseFuncRParams();
            token = iterator.readNextToken();
        }
        if (token.getType().equals(TokenType.RPARENT)) {
            rightParent = token;
        } else {
            errors.add(new Error(iterator.peekPreviousToken().getLine(), "j"));
            iterator.unReadToken(1);
        }
        return new UnaryExpNodeOfFunc(ident, leftParent, funcRParams,rightParent);
    }

    private FuncRParams parseFuncRParams(){
        ArrayList<Token> commas = new ArrayList<>();
        ArrayList<Exp> exps = new ArrayList<>();
        Exp necExp = parseExp();
        Token token = iterator.readNextToken();
        while (token.getType().equals(TokenType.COMMA)) { // ','
            commas.add(token);
            exps.add(parseExp());
            token = iterator.readNextToken();
        }
        iterator.unReadToken(1);
        return new FuncRParams(necExp, commas, exps);
    }

    private Exp parseExp(){
        AddExp addExp= parseAddExp();
        return new Exp(addExp);
    }

    private boolean isMatchExp(Token token){
        return (token.getType().equals(TokenType.LPARENT)||
                token.getType().equals(TokenType.IDENFR)||
                token.getType().equals(TokenType.INTCON)||
                token.getType().equals(TokenType.CHRCON)||
                token.getType().equals(TokenType.PLUS)||
                token.getType().equals(TokenType.MINU));
    }

    private void error(){

    }
}
