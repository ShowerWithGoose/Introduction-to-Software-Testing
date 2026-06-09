package frontend;

import error.ErrorType;
import frontend.AST.*;
import frontend.AST.Character;
import frontend.AST.Decl.ConstDecl;
import frontend.AST.Decl.Decl;
import frontend.AST.Decl.VarDecl;
import frontend.AST.Def.ConstDef;
import frontend.AST.Def.FuncDef;
import frontend.AST.Def.MainFuncDef;
import frontend.AST.Def.VarDef;
import frontend.AST.Exp.*;
import frontend.AST.Number;
import frontend.AST.Val.ConstInitVal;
import frontend.AST.Val.InitVal;
import frontend.AST.Val.LVal;

import java.util.ArrayList;

public class Parser {
    private ArrayList<Token> tokens; //词法解析的tokens

    private ArrayList<Token> errors = new ArrayList<>();
    public ArrayList<Token> getErrors() {
        return errors;
    }
    private  int pos = 0;

    public Parser(ArrayList<Token> tokens) {
        this.tokens = tokens;
    }
    public boolean isDeclare(LexType type){
        boolean b1 = type == LexType.INTTK || type == LexType.CHARTK || type == LexType.CONSTTK;
        boolean b2 = tokens.get(pos + 1).getLexType() != LexType.MAINTK;
        boolean b3 = tokens.get(pos + 2).getLexType() != LexType.LPARENT;
        return  b1 && b2 && b3;
    }
    public boolean isFuncDeclare(LexType type){
        boolean b1 = type == LexType.INTTK || type == LexType.CHARTK || type == LexType.VOIDTK;
        boolean b2 = tokens.get(pos + 1).getLexType() != LexType.MAINTK;
        boolean b3 = tokens.get(pos + 2).getLexType() == LexType.LPARENT;
        return  b1 && b2 && b3;
    }

    public boolean isExpHead(LexType type){
        boolean b1 = type == LexType.PLUS || type==LexType.MINU || type == LexType.NOT;
        boolean b2 = type == LexType.INTCON || type == LexType.CHRCON || type == LexType.LPARENT || type == LexType.IDENFR;
        return b1 || b2;
    }
    public CompUnit parseCompUnit() {   //CompUnit → {Decl} {FuncDef} MainFuncDef
        ArrayList<Decl> declares = new ArrayList<>();
        ArrayList<FuncDef> functionDefList = new ArrayList<>();
        while(isDeclare(tokens.get(pos).getLexType())) {
            declares.add(parseDecl());
        }
        while(isFuncDeclare(tokens.get(pos).getLexType())) {
            functionDefList.add(parseFuncDef());
        }
        MainFuncDef mainFuncDef = parseMainFuncDef();
        return new CompUnit(declares,functionDefList,mainFuncDef);
    }

    public Decl parseDecl() { //Decl → ConstDecl | VarDecl
        if (tokens.get(pos).getLexType() == LexType.CONSTTK) {
            return new Decl(parseConstDecl());
        }
        else {
            return new Decl(parseVarDecl());
        }
    }

    private FuncDef parseFuncDef() { // FuncDef → FuncType Ident '(' [FuncFParams] ')' Block // j
        FuncType funcType = parseFuncType();
        Token iDent = tokens.get(pos++);
        Token lParent = tokens.get(pos++);
        //FuncFParams funcFParams = parseFuncFParams();
        if (tokens.get(pos).getLexType() == LexType.RPARENT)
        {
            Token rParent = tokens.get(pos++);
            Block block = parseBlock();
            return new FuncDef(funcType,iDent,lParent,rParent,block);
        }
        else if (tokens.get(pos).getLexType() == LexType.INTTK || tokens.get(pos).getLexType() == LexType.CHARTK){
            FuncFParams funcFParams = parseFuncFParams();
            if (tokens.get(pos).getLexType() == LexType.RPARENT) {
                Token rParent = tokens.get(pos++);
                Block block = parseBlock();
                return new FuncDef(funcType, iDent, lParent, rParent, block, funcFParams);
            }
            else {
                Token errorToken = new Token(ErrorType.LACK_OF_RPARENT,tokens.get(pos-1).getLineNum(),"");
                errors.add(errorToken);
                Block block = parseBlock();
                return new FuncDef(funcType,iDent,lParent,null,block,funcFParams);
            }
        }
        else {
            Token errorToken = new Token(ErrorType.LACK_OF_RPARENT,tokens.get(pos-1).getLineNum(),"");
            errors.add(errorToken);
            Block block = parseBlock();
            return new FuncDef(funcType,iDent,lParent,null,block);
        }
    }

    private Block parseBlock() { //Block → '{' { BlockItem } '}'
        ArrayList<BlockItem> blockItems = new ArrayList<>();
        Token lBrace = tokens.get(pos++);
        while (tokens.get(pos).getLexType() != LexType.RBRACE) {
            blockItems.add(parseBlockItem());
        }
        Token rBrace = tokens.get(pos++);
        return new Block(lBrace,rBrace,blockItems);
    }

    private BlockItem parseBlockItem() {//BlockItem → Decl | Stmt
        LexType type = tokens.get(pos).getLexType();
        boolean b1 = type == LexType.INTTK || type == LexType.CHARTK || type == LexType.CONSTTK;
        if (b1) {
            return new BlockItem(parseDecl());
        }
        else {
            return new BlockItem(parseStmt());
        }
    }

    private FuncFParams parseFuncFParams() {
        ArrayList<FuncFParam> funcFParamList = new ArrayList<>();
        funcFParamList.add(parseFuncFParam());
        while(tokens.get(pos).getLexType() == LexType.COMMA) {
            pos++;
            funcFParamList.add(parseFuncFParam());
        }
        return new FuncFParams(funcFParamList);
    }

    private FuncFParam parseFuncFParam() {//FuncFParam → BType Ident ['[' ']'] // k
        Token BType=tokens.get(pos++);
        Token iDent=tokens.get(pos++);
        if (tokens.get(pos).getLexType() == LexType.LBRACK) {
            Token l = tokens.get(pos++);
            if (tokens.get(pos).getLexType() == LexType.RBRACK) {
                Token r = tokens.get(pos++);
                return new FuncFParam(BType,iDent,l,r);
            }
            else {
                Token error = new Token(ErrorType.LACK_OF_RBRACK,tokens.get(pos - 1).getLineNum(),"");
                errors.add(error);
                return new FuncFParam(BType,iDent,l,null);
            }
        }
        else {
            return new FuncFParam(BType,iDent);
        }
    }

    private FuncType parseFuncType() {
        Token Type = tokens.get(pos++);
        return new FuncType(Type);
    }



    private MainFuncDef parseMainFuncDef() {//MainFuncDef → 'int' 'main' '(' ')' Block // j
        Token intTk = tokens.get(pos++);
        Token mainTk = tokens.get(pos++);
        Token l = tokens.get(pos++);
        Token r = null;
        if (tokens.get(pos).getLexType() == LexType.RPARENT) {
            r = tokens.get(pos++);
        }
        else {
            Token error = new Token(ErrorType.LACK_OF_RPARENT,tokens.get(pos - 1).getLineNum(),"");
            errors.add(error);
        }
        Block block = parseBlock();
        return new MainFuncDef(intTk,mainTk,l,r,block);
    }

    private ConstDecl parseConstDecl() {//ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';' // i
        Token constTk = tokens.get(pos++);
        Token BType = tokens.get(pos++);
        ArrayList<ConstDef> defList = new ArrayList<>();
        defList.add(parseConstDef());
        while (tokens.get(pos).getLexType() == LexType.COMMA){
            pos++;
            defList.add(parseConstDef());
        }
        if (tokens.get(pos).getLexType() == LexType.SEMICN) {
            Token semicolon = tokens.get(pos);
            pos++;
            return new ConstDecl(constTk,BType,defList,semicolon);
        }
        else {
            Token error = new Token(ErrorType.LACK_OF_SEMICN,tokens.get(pos - 1).getLineNum(),"");
            errors.add(error);
            return new ConstDecl(constTk,BType,defList,null);
        }
    }

    private ConstDef parseConstDef() {//ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal // k
        Token iDent = tokens.get(pos++);
        if (tokens.get(pos).getLexType() == LexType.LBRACK) {
            Token l = tokens.get(pos++);
            ConstExp constExp = parseConstExp();
            Token r;
            Token equal_sign;
            if (tokens.get(pos).getLexType() == LexType.RBRACK) {
                r = tokens.get(pos++);
                equal_sign = tokens.get(pos++);
                ConstInitVal constInitVal = parseConstInitVal();
                return new ConstDef(iDent,l,constExp,r,equal_sign,constInitVal);
            }
            else {
                Token error = new Token(ErrorType.LACK_OF_RBRACK,tokens.get(pos - 1).getLineNum(),"");
                errors.add(error);
                equal_sign = tokens.get(pos++);
                ConstInitVal constInitVal = parseConstInitVal();
                return new ConstDef(iDent,l,constExp,null,equal_sign,constInitVal);
            }
        }
        else {
            Token equal_sign = tokens.get(pos++);
            ConstInitVal constInitVal = parseConstInitVal();
            return new ConstDef(iDent,null,null,null,equal_sign,constInitVal);
        }

    }

    private ConstInitVal parseConstInitVal() {
        //ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
        if (tokens.get(pos).getLexType() == LexType.STRCON) {
            Token StringConst = tokens.get(pos++);
            return new ConstInitVal(StringConst);
        } else if (tokens.get(pos).getLexType() == LexType.LBRACE) {
            Token l = tokens.get(pos++);

            ArrayList<ConstExp> expList = new ArrayList<>();
            expList.add(parseConstExp());
            while (tokens.get(pos).getLexType() == LexType.COMMA) {
                pos++;
                expList.add(parseConstExp());
            }
            Token r = tokens.get(pos++);
            return new ConstInitVal(l,expList,r);
        } else {
            ConstExp constExp = parseConstExp();
            return new ConstInitVal(constExp);
        }
    }

    private VarDecl parseVarDecl() {//VarDecl → BType VarDef { ',' VarDef } ';' // i
        Token BType = tokens.get(pos++);
        ArrayList<VarDef> defList = new ArrayList<>();
        defList.add(parseVarDef());
        while (tokens.get(pos).getLexType() == LexType.COMMA) {
            pos++;
            defList.add(parseVarDef());
        }
        if (tokens.get(pos).getLexType() == LexType.SEMICN) {
            Token semicolon = tokens.get(pos++);
            return new VarDecl(BType,defList,semicolon);
        }
        else {
            Token error = new Token(ErrorType.LACK_OF_SEMICN,tokens.get(pos - 1).getLineNum(),"");
            errors.add(error);
            return new VarDecl(BType,defList,null);
        }
    }

    private VarDef parseVarDef() {
        // VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal // k
        Token iDent = tokens.get(pos++);
        if (tokens.get(pos).getLexType() == LexType.LBRACK) {
            Token l = tokens.get(pos++);
            ConstExp constExp = parseConstExp();
            Token r;
            Token assign_sign;
            if (tokens.get(pos).getLexType() == LexType.RBRACK) {
                r = tokens.get(pos++);
                if (tokens.get(pos).getLexType() == LexType.ASSIGN) {
                    assign_sign = tokens.get(pos++);
                    InitVal InitVal = parseInitVal();
                    return new VarDef(iDent, l, constExp, r, assign_sign, InitVal);
                }
                else {
                    return new VarDef(iDent, l, constExp, r, null, null);
                }
            }
            else {
                Token error = new Token(ErrorType.LACK_OF_RBRACK,tokens.get(pos - 1).getLineNum(),"");
                errors.add(error);
                if (tokens.get(pos).getLexType() == LexType.ASSIGN) {
                    assign_sign = tokens.get(pos++);
                    InitVal InitVal = parseInitVal();
                    return new VarDef(iDent, l, constExp, null, assign_sign, InitVal);
                }
                else {
                    return new VarDef(iDent, l, constExp, null, null, null);
                }
            }
        }
        else {
            if (tokens.get(pos).getLexType() == LexType.ASSIGN) {
                Token assign_sign = tokens.get(pos++);
                InitVal InitVal = parseInitVal();
                return new VarDef(iDent, null, null, null, assign_sign, InitVal);
            }
            else {
                return new VarDef(iDent, null, null, null, null, null);
            }
        }
    }

    private InitVal parseInitVal() { //InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
        if (tokens.get(pos).getLexType() == LexType.STRCON) {
            Token StringConst = tokens.get(pos++);
            return new InitVal(StringConst);
        } else if (tokens.get(pos).getLexType() == LexType.LBRACE) {
            Token l = tokens.get(pos++);
            ArrayList<Exp> expList = new ArrayList<>();
            expList.add(parseExp());
            while (tokens.get(pos).getLexType() == LexType.COMMA) {
                pos++;
                expList.add(parseExp());
            }
            Token r = tokens.get(pos++);
            return new InitVal(l,expList,r);
        } else {
            Exp exp = parseExp();
            return new InitVal(exp);
        }
    }

    private AddExp parseAddExp() {
        //AddExp → MulExp | AddExp ('+' | '−') MulExp
        ArrayList<MulExp> mulExpList = new ArrayList<>();
        ArrayList<Token> addMinusList = new ArrayList<>();
        MulExp mulExp = parseMulExp();
        while(tokens.get(pos).getLexType() == LexType.PLUS ||tokens.get(pos).getLexType() == LexType.MINU) {
            addMinusList.add(tokens.get(pos));
            pos++;
            mulExpList.add(parseMulExp());
        }
        int i = 0;
        AddExp addExp = new AddExp(mulExp);
        while (i < mulExpList.size()) {
            addExp = new AddExp(mulExpList.get(i),addExp,addMinusList.get(i));
            i++;
        }
        return addExp;
    }

    private ConstExp parseConstExp() {
        return new ConstExp(parseAddExp());
    }

    private EqExp parseEqExp() {
        ArrayList<RelExp> RelExpList = new ArrayList<>();
        ArrayList<Token> NEQList = new ArrayList<>();
        RelExp relExp = parseRelExp();
        while(tokens.get(pos).getLexType() == LexType.EQL || tokens.get(pos).getLexType() == LexType.NEQ) {
            NEQList.add(tokens.get(pos));
            pos++;
            RelExpList.add(parseRelExp());
        }
        int i = 0;
        EqExp eqExp = new EqExp(relExp);
        while (i < RelExpList.size()) {
            eqExp = new EqExp(RelExpList.get(i),eqExp,NEQList.get(i));
            i++;
        }
        return eqExp;
    }

    private Exp parseExp() {
        //Exp → AddExp
        return new Exp(parseAddExp());
    }

    private LAndExp parseLAndExp() {
        //LAndExp → EqExp | LAndExp '&&' EqExp
        ArrayList<EqExp> EqExpList = new ArrayList<>();
        ArrayList<Token> AndList = new ArrayList<>();
        EqExp eqExp = parseEqExp();
        while(tokens.get(pos).getLexType() == LexType.AND) {
            AndList.add(tokens.get(pos));
            pos++;
            EqExpList.add(parseEqExp());
        }
        int i = 0;
        LAndExp lAndExp = new LAndExp(eqExp);
        while (i < EqExpList.size()) {
            lAndExp = new LAndExp(EqExpList.get(i),lAndExp,AndList.get(i));
            i++;
        }
        return lAndExp;
    }

    private LOrExp parseLOrExp() {
        ArrayList<LAndExp> LAndExpList = new ArrayList<>();
        ArrayList<Token> OrList = new ArrayList<>();
        LAndExp lAndExp = parseLAndExp();
        while(tokens.get(pos).getLexType() == LexType.OR) {
            OrList.add(tokens.get(pos));
            pos++;
            LAndExpList.add(parseLAndExp());
        }
        int i = 0;
        LOrExp lorExp = new LOrExp(lAndExp);
        while (i < LAndExpList.size()) {
            lorExp = new LOrExp(LAndExpList.get(i),lorExp,OrList.get(i));
            i++;
        }
        return lorExp;
    }

    private MulExp parseMulExp() { //MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
        ArrayList<UnaryExp> unaryExpList = new ArrayList<>();
        ArrayList<Token> mulDivList = new ArrayList<>();
        UnaryExp unaryExp = parseUnaryExp();
        while(tokens.get(pos).getLexType() == LexType.DIV
                ||tokens.get(pos).getLexType() == LexType.MULT
                    ||tokens.get(pos).getLexType() == LexType.MOD) {
            mulDivList.add(tokens.get(pos));
            pos++;
            unaryExpList.add(parseUnaryExp());
        }
        int i = 0;
        MulExp mulExp = new MulExp(unaryExp);
        while (i < unaryExpList.size()) {
            mulExp = new MulExp(unaryExpList.get(i),mulExp,mulDivList.get(i));
            i++;
        }
        return mulExp;
    }

    private PrimaryExp parsePrimaryExp() {
        //PrimaryExp → '(' Exp ')' | LVal | Number | Character// j
        Token t1 = tokens.get(pos);
        if (t1.getLexType() == LexType.LPARENT) {
            pos++;
            Exp exp = parseExp();
            if (tokens.get(pos).getLexType() == LexType.RPARENT) {
                Token r = tokens.get(pos++);
                return new PrimaryExp(t1,exp,r);
            }
            else {
                Token error = new Token(ErrorType.LACK_OF_RPARENT,tokens.get(pos - 1).getLineNum(),"");
                errors.add(error);
                return new PrimaryExp(t1,exp,null);
            }
        } else if (t1.getLexType() == LexType.IDENFR) {
            return new PrimaryExp(parseLVal());
        } else if (t1.getLexType() == LexType.INTCON) {
            return new PrimaryExp(parseNumber());
        } else if (t1.getLexType() == LexType.CHRCON) {
            return new PrimaryExp(parseCharacter());
        }
        return null;
    }

    private Character parseCharacter() {
        Token token = tokens.get(pos++);
        return new Character(token);
    }

    private Number parseNumber() {
        Token token = tokens.get(pos++);
        return new Number(token);
    }

    private RelExp parseRelExp() {
        //RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
        ArrayList<AddExp> addExpList = new ArrayList<>();
        ArrayList<Token> compareList = new ArrayList<>();
        AddExp addExp = parseAddExp();
        while(tokens.get(pos).getLexType() == LexType.GRE ||tokens.get(pos).getLexType() == LexType.GEQ
        || tokens.get(pos).getLexType() == LexType.LEQ ||tokens.get(pos).getLexType() == LexType.LSS) {
            compareList.add(tokens.get(pos));
            pos++;
            addExpList.add(parseAddExp());
        }
        int i = 0;
        RelExp relExp = new RelExp(addExp);
        while (i < addExpList.size()) {
            relExp = new RelExp(addExpList.get(i),relExp,compareList.get(i));
            i++;
        }
        return relExp;
    }

    private UnaryExp parseUnaryExp() {
        //UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp // j
        Token token1 = tokens.get(pos);
        if (token1.getLexType() == LexType.PLUS
                || token1.getLexType() == LexType.MINU
                    ||token1.getLexType() == LexType.NOT) {
            UnaryOp unaryOp = parseUnaryOp();
            UnaryExp unaryExp = parseUnaryExp();
            return new UnaryExp(unaryOp,unaryExp);
        } else if (token1.getLexType() == LexType.IDENFR && tokens.get(pos + 1).getLexType() == LexType.LPARENT) {
            pos++;
            Token l = tokens.get(pos++);
            if (tokens.get(pos).getLexType() == LexType.RPARENT) {
                Token r = tokens.get(pos++);
                return new UnaryExp(token1,l,null,r);
            } else if (isExpHead(tokens.get(pos).getLexType())){
                FuncRParams funcRParams = parseFuncRParams();
                if (tokens.get(pos).getLexType() == LexType.RPARENT){
                    Token r = tokens.get(pos++);
                    return new UnaryExp(token1,l,funcRParams,r);
                }
                else {
                    Token error = new Token(ErrorType.LACK_OF_RPARENT,tokens.get(pos - 1).getLineNum(),"");
                    errors.add(error);
                    return new UnaryExp(token1,l,funcRParams,null);
                }
            }

        } else {
            return new UnaryExp(parsePrimaryExp());
        }
        return null;
    }

    private FuncRParams parseFuncRParams() {
        ArrayList<Exp> expArrayList = new ArrayList<>();
        expArrayList.add(parseExp());
        while (tokens.get(pos).getLexType() == LexType.COMMA) {
            pos++;
            expArrayList.add(parseExp());
        }

        return new FuncRParams(expArrayList);
    }

    private UnaryOp parseUnaryOp() {
        Token token = tokens.get(pos++);
        return new UnaryOp(token);
    }

    public int judge ;
    public boolean judgeLVal(){
        judge = 1;
        int temp = pos;
        parseLVal();
        if (tokens.get(pos).getLexType()==LexType.ASSIGN){
            pos = temp;
            judge = 0;
            return true;
        } else {
            pos = temp;
            judge = 0;
            return false;
        }
    }

    private Stmt parseStmt() {
        Token first = tokens.get(pos);
        if (first.getLexType() == LexType.IDENFR) {
            if (judgeLVal()) {
                LVal lVal = parseLVal();
                Token assign = tokens.get(pos++);
                if (tokens.get(pos).getLexType() == LexType.GETCHARTK || tokens.get(pos).getLexType() == LexType.GETINTTK) {
                    Token getChar = tokens.get(pos++);
                    Token l = tokens.get(pos++);
                    if (tokens.get(pos).getLexType() == LexType.RPARENT) {
                        Token r = tokens.get(pos++);
                        if (tokens.get(pos).getLexType() == LexType.SEMICN) {
                            Token semicolon = tokens.get(pos++);
                            return new Stmt(lVal, assign, getChar, l, r, semicolon);
                        } else {
                            Token error = new Token(ErrorType.LACK_OF_SEMICN, tokens.get(pos - 1).getLineNum(), "");
                            errors.add(error);
                            return new Stmt(lVal, assign, getChar, l, r, null);
                        }
                    } else {
                        Token error = new Token(ErrorType.LACK_OF_RPARENT, tokens.get(pos - 1).getLineNum(), "");
                        errors.add(error);
                        if (tokens.get(pos).getLexType() == LexType.SEMICN) {
                            Token semi = tokens.get(pos++);
                            return new Stmt(lVal, assign, getChar, l, null, semi);
                        } else {
                            Token error1 = new Token(ErrorType.LACK_OF_SEMICN, tokens.get(pos - 1).getLineNum(), "");
                            errors.add(error1);
                            return new Stmt(lVal, assign, getChar, l, null, null);
                        }
                    }

                } else {
                    Exp exp = parseExp();
                    if (tokens.get(pos).getLexType() != LexType.SEMICN) {
                        Token error1 = new Token(ErrorType.LACK_OF_SEMICN, tokens.get(pos - 1).getLineNum(), "");
                        errors.add(error1);
                        return new Stmt(lVal, assign, exp, null);
                    } else {
                        return new Stmt(lVal, assign, exp, tokens.get(pos++));
                    }
                }
            }
            else {
                Exp e = parseExp();
                if (tokens.get(pos).getLexType() == LexType.SEMICN) {
                    Token semi = tokens.get(pos++);
                    return new Stmt(e,semi);
                }
                else {
                    Token error1 = new Token(ErrorType.LACK_OF_SEMICN,tokens.get(pos - 1).getLineNum(),"");
                    errors.add(error1);
                    return new Stmt(e,null);
                }
            }
        }
        else if (first.getLexType() == LexType.LBRACE) {
            Block block = parseBlock();
            return new Stmt(block);
        } else if (first.getLexType() == LexType.SEMICN) {
            Token semi = tokens.get(pos++);
            return new Stmt((Exp) null,semi);
        } else if (first.getLexType() == LexType.IFTK) {
            pos++;
            Token l = tokens.get(pos++);
            Cond cond = parseCond();
            Token r = null;
            Token elseTK = null;

            if (tokens.get(pos).getLexType() != LexType.RPARENT) {
                Token error1 = new Token(ErrorType.LACK_OF_RPARENT,tokens.get(pos - 1).getLineNum(),"");
                errors.add(error1);
            }
            else { r = tokens.get(pos++); }
            Stmt stmt1 = parseStmt();
            Stmt stmt2 = null;
            if (tokens.get(pos).getLexType() == LexType.ELSETK) {
                elseTK = tokens.get(pos++);
                stmt2 = parseStmt();
            }
            return new Stmt(first,l,cond,r,stmt1,elseTK,stmt2);
        } else if (first.getLexType() == LexType.FORTK) {
            pos++;
            Token l = tokens.get(pos++);
            ForStmt stmt1 = null;
            if (tokens.get(pos).getLexType() != LexType.SEMICN) {
                stmt1 = parseForStmt();
            }
            Token semi1 = tokens.get(pos++);
            Cond cond = null;
            if (tokens.get(pos).getLexType() != LexType.SEMICN) {
                cond = parseCond();
            }
            Token semi2 = tokens.get(pos++);
            ForStmt stmt2 = null;
            if (tokens.get(pos).getLexType() != LexType.RPARENT) {
                stmt2 = parseForStmt();
            }
            Token r = tokens.get(pos++);
            Stmt stmt = parseStmt();
            return new Stmt(first,l,stmt1,semi1,cond,semi2,stmt2,r,stmt);
        } else if (first.getLexType() == LexType.BREAKTK || first.getLexType() == LexType.CONTINUETK) {
            pos++;
            if (tokens.get(pos).getLexType() == LexType.SEMICN) {
                Token semi = tokens.get(pos++);
                return new Stmt(first,semi);
            }
        } else if (first.getLexType() == LexType.RETURNTK) {
            pos++;
            Exp exp = null;
            if (isExpHead(tokens.get(pos).getLexType())) {
                exp = parseExp();
            }
            if (tokens.get(pos).getLexType() != LexType.SEMICN) {
                Token error1 = new Token(ErrorType.LACK_OF_SEMICN,tokens.get(pos - 1).getLineNum(),"");
                errors.add(error1);
                return new Stmt(first,exp,null);
            } else {
                Token s = tokens.get(pos++);
                return new Stmt(first,exp,s);
            }

        } else if (first.getLexType() == LexType.PRINTFTK) {
            pos++;
            Token l = tokens.get(pos++);
            Token stringConst = tokens.get(pos++);
            ArrayList<Exp> expList = new ArrayList<>();
            while (tokens.get(pos).getLexType() == LexType.COMMA) {
                pos++;
                expList.add(parseExp());
            }
            Token r = null;
            Token semi = null;
            if (tokens.get(pos).getLexType() == LexType.RPARENT) {
                r = tokens.get(pos++);
            }
            else {
                Token error1 = new Token(ErrorType.LACK_OF_RPARENT,tokens.get(pos - 1).getLineNum(),"");
                errors.add(error1);
            }
            if (tokens.get(pos).getLexType() == LexType.SEMICN) {
                semi = tokens.get(pos++);
            }
            else {
                Token error1 = new Token(ErrorType.LACK_OF_SEMICN,tokens.get(pos - 1).getLineNum(),"");
                errors.add(error1);
            }
            return new Stmt(first,l,stringConst,expList,r,semi);
        }
        else {
            if (first.getLexType()==LexType.SEMICN){
                pos++;
                return new Stmt((Exp) null,first);
            } else {
                Exp exp1=parseExp();
                if (tokens.get(pos).getLexType()==LexType.SEMICN){
                    return new Stmt(exp1,tokens.get(pos++));
                }else {
                    Token error1 = new Token(ErrorType.LACK_OF_SEMICN,tokens.get(pos - 1).getLineNum(),"");
                    errors.add(error1);
                    return new Stmt(exp1,null);
                }
            }
        }

        return null;
    }
    private Cond parseCond() {
        return new Cond(parseLOrExp());
    }

    private ForStmt parseForStmt() {
        LVal lVal = parseLVal();
        Token assign = tokens.get(pos++);
        Exp exp = parseExp();
        return new ForStmt(lVal,assign,exp);
    }

    private LVal parseLVal() {
        //LVal → Ident ['[' Exp ']'] // k
        Token token = tokens.get(pos++);
        if (tokens.get(pos).getLexType() == LexType.LBRACK) {
            Token l = tokens.get(pos++);
            Exp exp = parseExp();
            if (tokens.get(pos).getLexType() == LexType.RBRACK) {
                Token r = tokens.get(pos++);
                return new LVal(token,l,exp,r);
            }
            else {
                Token error = new Token(ErrorType.LACK_OF_RBRACK,tokens.get(pos - 1).getLineNum(),"");
                errors.add(error);
                return new LVal(token,l,exp,null);
            }
        }
        else {
            return new LVal(token);
        }
    }
}
