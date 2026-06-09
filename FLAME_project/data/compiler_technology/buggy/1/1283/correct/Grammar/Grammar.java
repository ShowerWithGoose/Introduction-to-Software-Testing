package Grammar;

import Lexer.Lexer;
import Lexer.Token;
import Nonterminal.*;
import Nonterminal.Character;
import Nonterminal.Number;
import Error.Error;
import Error.Errortype;

import java.io.*;
import java.util.*;
/**
 * <p>Project: Compiler - Grammar
 * <p>Powered by berry On 2024-09-28
 *
 * @author
 * @version 1.0
 */
public class Grammar {
    //构造方法
    private static Grammar grammar=new Grammar();
    private Grammar(){
        System.out.println("单例模式");
    }
    public static Grammar getGrammar(){
        return grammar;
    }
    public List<Token> tokens = new ArrayList<>();
    public void setTokens(List<Token> t){
        tokens=t;
    }
    public static Map<Nodetype, String> nodeOutput=new HashMap<Nodetype, String>();
    public boolean isError;//文件中是否有错误
    public Map<Integer, java.lang.Character> errorLine=new HashMap<Integer,  java.lang.Character>();
    public boolean isEnd;//识别到tokens结尾
    public CompUnit compUnit;
    public Token now;//现在在检查的Token
    public int curPos;

    //构建Nodetype和对应的打印
    public void createMap(){
        for (Nodetype t : Nodetype.values()){
            nodeOutput.put(t,"<"+t.toString()+">"+"\n");
        }
    }
    public void analyse(){
        this.compUnit=doCompUnit();
    }
    public Token match(Token.Type type){
        //System.out.println(now.lineno+" "+now.type+" "+now.content+" "+type+"\n");
        if(now.type==type){
            Token re=now;
            if(curPos<tokens.size()-1){
                now=tokens.get(++curPos);
            }
            return re;
        }
        else{
            isError=true;
            if(type==Token.Type.SEMICN){
                errorLine.put(tokens.get(curPos-1).lineno,'i');
                Error.getError().errors.add(new Errortype(tokens.get(curPos-1).lineno,'i'));
            }
            else if(type==Token.Type.RPARENT){
                //System.out.println(now.type);
                errorLine.put(tokens.get(curPos-1).lineno,'j');
                Error.getError().errors.add(new Errortype(tokens.get(curPos-1).lineno,'j'));
            }
            else if(type==Token.Type.RBRACK){
                errorLine.put(tokens.get(curPos-1).lineno,'k');
                Error.getError().errors.add(new Errortype(tokens.get(curPos-1).lineno,'k'));
            }
            return new Token(Token.Type.NONE,"",0);//没匹配到
        }
    }
    public CompUnit doCompUnit(){
        //{Decl} {FuncDef} MainFuncDef
        List<Decl> declList= new ArrayList<>();
        List<FuncDef> funcDefList = new ArrayList<>();
        MainFuncDef mainFuncDef;
        while(tokens.get(curPos+1).type!=Token.Type.MAINTK&&tokens.get(curPos+2).type!=Token.Type.LPARENT){
            Decl decl=doDecl();
            declList.add(decl);
        }
        while(tokens.get(curPos+1).type!=Token.Type.MAINTK){
            FuncDef funcDef = doFuncDef();
            funcDefList.add(funcDef);
        }
        mainFuncDef=doMainFuncDef();
        return new CompUnit(declList,funcDefList,mainFuncDef);
    }
    public Decl doDecl(){
        //ConstDecl | VarDecl
        ConstDecl constDecl=null;
        VarDecl varDecl=null;
        if(now.type==Token.Type.CONSTTK) constDecl=doConstDecl();
        else varDecl=doVarDecl();
        return new Decl(constDecl,varDecl);
    }
    public ConstDecl doConstDecl(){
        //'const' BType ConstDef { ',' ConstDef } ';'
        Token constToken=match(Token.Type.CONSTTK);
        BType bType=doBType();
        List<ConstDef> constDefList=new ArrayList<>();
        constDefList.add(doConstDef());
        while(now.type==Token.Type.COMMA){
            match(Token.Type.COMMA);
            constDefList.add(doConstDef());
        }
        match(Token.Type.SEMICN);
        //语义分析
        for(ConstDef constDef:constDefList){
            if(bType.isInt) constDef.type="int";
            else constDef.type="char";
        }
        return new ConstDecl(bType,constDefList);
    }
    public BType doBType(){
        //'int' | 'char'
        if(now.type==Token.Type.INTTK){//是int
            match(Token.Type.INTTK);
            return new BType(true);
        }else{
            match(Token.Type.CHARTK);
            return new BType(false);
        }
    }
    public ConstDef doConstDef(){
        //Ident [ '[' ConstExp ']' ] '=' ConstInitVal
        Token IdentToken=match(Token.Type.IDENFR);
        ConstExp constExp=null;
        ConstInitVal constInitVal;
        if(now.type==Token.Type.LBRACK){
            match(Token.Type.LBRACK);
            constExp=doConstExp();
            match(Token.Type.RBRACK);
        }
        match(Token.Type.ASSIGN);
        constInitVal=doConstInitVal();
        return new ConstDef(IdentToken,constExp,constInitVal);
    }
    public ConstInitVal doConstInitVal(){
        //ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
        List<ConstExp> constExpList=new ArrayList<>();
        Token StringConstToken=null;
        if(now.type==Token.Type.LBRACE){//'{' [ ConstExp { ',' ConstExp } ] '}'
            match(Token.Type.LBRACE);
            if(now.type!=Token.Type.RBRACE){
                constExpList.add(doConstExp());
                while(now.type==Token.Type.COMMA) {
                    match(Token.Type.COMMA);
                    constExpList.add(doConstExp());
                }
            }
            match(Token.Type.RBRACE);
            return new ConstInitVal(constExpList,StringConstToken,false);
        }
        else if(now.type==Token.Type.STRCON){
            StringConstToken=match(Token.Type.STRCON);
            return new ConstInitVal(constExpList,StringConstToken,false);
        }
        else{//ConstExp
            constExpList.add(doConstExp());
            return new ConstInitVal(constExpList,StringConstToken,true);
        }
    }
    public VarDecl doVarDecl(){
        //BType VarDef { ',' VarDef } ';'
        BType bType=doBType();
        List<VarDef> VarDefList=new ArrayList<>();
        VarDefList.add(doVarDef());
        while(now.type==Token.Type.COMMA){
            match(Token.Type.COMMA);
            VarDefList.add(doVarDef());
        }
        match(Token.Type.SEMICN);
        for(VarDef varDef:VarDefList){
            if(bType.isInt) varDef.type="int";
            else varDef.type="char";
        }
        return new VarDecl(bType,VarDefList);
    }
    public VarDef doVarDef(){
        //Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal
        Token IdentToken;
        ConstExp constExp=null;
        InitVal initVal=null;
        IdentToken=match(Token.Type.IDENFR);
        if(now.type==Token.Type.LBRACK){
            match(Token.Type.LBRACK);
            constExp=doConstExp();
            match(Token.Type.RBRACK);
        }
        if(now.type==Token.Type.ASSIGN){
            match(Token.Type.ASSIGN);
            initVal=doInitVal();
        }
        return new VarDef(IdentToken,constExp,initVal);
    }
    public InitVal doInitVal(){
        //Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
        List<Exp> ExpList=new ArrayList<>();
        Token StringConst=null;
        if(now.type==Token.Type.LBRACE){//'{' [ Exp { ',' Exp } ] '}'
            match(Token.Type.LBRACE);
            if(now.type!=Token.Type.RBRACE){
                ExpList.add(doExp());
                while(now.type==Token.Type.COMMA){
                    match(Token.Type.COMMA);
                    ExpList.add(doExp());
                }
            }
            match(Token.Type.RBRACE);
            return new InitVal(ExpList,StringConst,false);
        }
        else if(now.type==Token.Type.STRCON){
            StringConst=match(Token.Type.STRCON);
            return new InitVal(ExpList,StringConst,false);
        }
        else{
            ExpList.add(doExp());
            return new InitVal(ExpList,StringConst,true);
        }
    }
    public FuncDef doFuncDef(){
        //FuncType Ident '(' [FuncFParams] ')' Block
        FuncType funcType=doFuncType();
        Token IdentToken=match(Token.Type.IDENFR);
        FuncFParams funcFParams=null;
        match(Token.Type.LPARENT);
        if(now.type!=Token.Type.RPARENT){
            funcFParams=doFuncFParams();
        }
        match(Token.Type.RPARENT);
        Block block=doBlock();
        return new FuncDef(funcType,IdentToken,funcFParams,block);
    }
    public MainFuncDef doMainFuncDef(){
        //'int' 'main' '(' ')' Block
        match(Token.Type.INTTK);
        match(Token.Type.MAINTK);
        match(Token.Type.LPARENT);
        match(Token.Type.RPARENT);
        Block block=doBlock();
        return new MainFuncDef(block);
    }
    public FuncType doFuncType(){
        //'void' | 'int' | 'char'
        if(now.type==Token.Type.VOIDTK) {
            match(Token.Type.VOIDTK);
            return new FuncType(1);
        }
        else if(now.type==Token.Type.INTTK) {
            match(Token.Type.INTTK);
            return new FuncType(2);
        }
        else {
            match(Token.Type.CHARTK);
            return new FuncType(3);
        }
    }
    public FuncFParams doFuncFParams(){
        //FuncFParam { ',' FuncFParam }
        List<FuncFParam> FuncFParamList=new ArrayList<>();
        FuncFParamList.add(doFuncFParam());
        while(now.type==Token.Type.COMMA){
            match(Token.Type.COMMA);
            FuncFParamList.add(doFuncFParam());
        }
        return new FuncFParams(FuncFParamList);
    }
    public FuncFParam doFuncFParam(){
        //BType Ident ['[' ']']
        BType bType=doBType();
        Token IdentToken=match(Token.Type.IDENFR);
        if(now.type==Token.Type.LBRACK) {
            match(Token.Type.LBRACK);
            match(Token.Type.RBRACK);
            return new FuncFParam(bType, IdentToken, true);
        }
        else{
            return new FuncFParam(bType, IdentToken, false);
        }
    }
    public Block doBlock(){
        //'{' { BlockItem } '}'
        match(Token.Type.LBRACE);
        List<BlockItem> blockItemList = new ArrayList<>();
        while (now.type != Token.Type.RBRACE) {
            blockItemList.add(doBlockItem());
        }
        Token rbToken=match(Token.Type.RBRACE);
        return new Block(blockItemList,rbToken);
    }
    public BlockItem doBlockItem(){
        //Decl | Stmt
        Decl decl=null;
        Stmt stmt=null;
        if(now.type==Token.Type.CONSTTK||now.type==Token.Type.INTTK||now.type==Token.Type.CHARTK){
            decl=doDecl();
        }
        else stmt=doStmt();
        return new BlockItem(decl,stmt);
    }
    public Stmt doStmt(){
        //LVal '=' Exp ';' // 每种类型的语句都要覆盖
        //| [Exp] ';' //有无Exp两种情况
        //| Block
        //| 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
        //| 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
        //| 'break' ';'
        //| 'continue' ';'
        //| 'return' [Exp] ';'
        //| LVal '=' 'getint''('')'';'
        //| LVal '=' 'getchar''('')'';'
        //| 'printf''('StringConst {','Exp}')'';'
        LVal lVal=null;
        List<Exp> exp=new ArrayList<>();
        Block block=null;
        Cond cond=null;
        List<Stmt> stmt=new ArrayList<>();
        ForStmt forStmt1=null;
        ForStmt forStmt2=null;
        Token StringConst=null;
        if(now.type==Token.Type.LBRACE){
            //Block
            block = doBlock();
            return new Stmt(null,null,lVal,exp,block,cond,stmt,forStmt1,forStmt2,StringConst,3);
        }
        else if(now.type==Token.Type.IFTK){
            //'if' '(' Cond ')' Stmt [ 'else' Stmt ]
            match(Token.Type.IFTK);
            match(Token.Type.LPARENT);
            cond=doCond();
            Token t=match(Token.Type.RPARENT);
            //System.out.println(t.type);
            stmt.add(doStmt());
            if(now.type==Token.Type.ELSETK){
                match(Token.Type.ELSETK);
                stmt.add(doStmt());
            }
            return new Stmt(null,null,lVal,exp,block,cond,stmt,forStmt1,forStmt2,StringConst,4);
        }
        else if(now.type==Token.Type.FORTK){
            //'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
            match(Token.Type.FORTK);
            match(Token.Type.LPARENT);
            if(now.type==Token.Type.IDENFR){
                forStmt1=doForStmt();
            }
            match(Token.Type.SEMICN);
            if(isCond()){
                cond=doCond();
            }
            match(Token.Type.SEMICN);
            if(now.type==Token.Type.IDENFR){
                forStmt2=doForStmt();
            }
            match(Token.Type.RPARENT);
            stmt.add(doStmt());
            return new Stmt(null,null,lVal,exp,block,cond,stmt,forStmt1,forStmt2,StringConst,5);
        }
        else if(now.type==Token.Type.BREAKTK){
            //'break' ';'
            Token BCToken=match(Token.Type.BREAKTK);
            match(Token.Type.SEMICN);
            return new Stmt(null,BCToken,lVal,exp,block,cond,stmt,forStmt1,forStmt2,StringConst,6);
        }
        else if(now.type==Token.Type.CONTINUETK){
            //'continue' ';'
            Token BCToken=match(Token.Type.CONTINUETK);
            match(Token.Type.SEMICN);
            return new Stmt(null,BCToken,lVal,exp,block,cond,stmt,forStmt1,forStmt2,StringConst,7);
        }
        else if(now.type==Token.Type.RETURNTK){
            //'return' [Exp] ';'
            Token reToken=match(Token.Type.RETURNTK);
            if(isCond()){
                exp.add(doExp());
            }
            match(Token.Type.SEMICN);
            return new Stmt(reToken,null,lVal,exp,block,cond,stmt,forStmt1,forStmt2,StringConst,8);
        }
        else if(now.type==Token.Type.PRINTFTK){
            //'printf''('StringConst {','Exp}')'';'
            match(Token.Type.PRINTFTK);
            match(Token.Type.LPARENT);
            StringConst=match(Token.Type.STRCON);
            while(now.type==Token.Type.COMMA){
                match(Token.Type.COMMA);
                exp.add(doExp());
            }
            match(Token.Type.RPARENT);
            match(Token.Type.SEMICN);
            return new Stmt(null,null,lVal,exp,block,cond,stmt,forStmt1,forStmt2,StringConst,11);
        }
        //还有4个，
        else{
            boolean hasAssign=false;
            for(int i=curPos;i<tokens.size()&&tokens.get(i).lineno==now.lineno;i++){
                if(tokens.get(i).type==Token.Type.ASSIGN){
                    hasAssign=true;
                    break;
                }
            }
            if(hasAssign){
                //LVal '=' Exp ';'
                //LVal '=' 'getint''('')'';'
                //LVal '=' 'getchar''('')'';'
                lVal=doLVal();
                match(Token.Type.ASSIGN);
                if(now.type==Token.Type.GETINTTK){
                    match(Token.Type.GETINTTK);
                    match(Token.Type.LPARENT);
                    match(Token.Type.RPARENT);
                    match(Token.Type.SEMICN);
                    return new Stmt(null,null,lVal,exp,block,cond,stmt,forStmt1,forStmt2,StringConst,9);
                }
                else if(now.type==Token.Type.GETCHARTK){
                    match(Token.Type.GETCHARTK);
                    match(Token.Type.LPARENT);
                    match(Token.Type.RPARENT);
                    match(Token.Type.SEMICN);
                    return new Stmt(null,null,lVal,exp,block,cond,stmt,forStmt1,forStmt2,StringConst,10);
                }
                else{
                    exp.add(doExp());
                    match(Token.Type.SEMICN);
                    return new Stmt(null,null,lVal,exp,block,cond,stmt,forStmt1,forStmt2,StringConst,1);
                }
            }
            else{
                //[Exp] ';'
                if(isCond()){
                    exp.add(doExp());
                }
                match(Token.Type.SEMICN);
                return new Stmt(null,null,lVal,exp,block,cond,stmt,forStmt1,forStmt2,StringConst,2);
            }
        }
    }
    public ForStmt doForStmt(){
        //LVal '=' Exp
        LVal lVal=doLVal();
        match(Token.Type.ASSIGN);
        Exp exp=doExp();
        return new ForStmt(lVal,exp);
    }
    public Exp doExp(){
        //AddExp
        AddExp addExp=doAddExp();
        return new Exp(addExp);
    }
    public Cond doCond(){
        //LOrExp
        LOrExp lOrExp=doLOrExp();
        return new Cond(lOrExp);
    }
    public LVal doLVal(){
        //Ident ['[' Exp ']']
        Token IdentToken=match(Token.Type.IDENFR);
        Exp exp=null;
        if(now.type==Token.Type.LBRACK){
            match(Token.Type.LBRACK);
            exp=doExp();
            match(Token.Type.RBRACK);
        }
        return new LVal(IdentToken,exp);
    }
    public PrimaryExp doPrimaryExp(){
        //'(' Exp ')' | LVal | Number | Character
        Exp exp=null;
        LVal lVal=null;
        Number number=null;
        Character character=null;
        if(now.type== Token.Type.LPARENT){
            match(Token.Type.LPARENT);
            exp=doExp();
            match(Token.Type.RPARENT);
        }
        else if(now.type==Token.Type.IDENFR){
            lVal=doLVal();
        }
        else if(now.type==Token.Type.INTCON){
            number=doNumber();
        }
        else character=doCharacter();
        return new PrimaryExp(exp,lVal,number,character);
    }
    public Number doNumber(){
        //IntConst
        Token IntConstToken=match(Token.Type.INTCON);
        return new Number(IntConstToken);
    }
    public Character doCharacter(){
        //CharConst
        Token CharConstToken=match(Token.Type.CHRCON);
        return new Character(CharConstToken);
    }
    public UnaryExp doUnaryExp(){
        //PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
        PrimaryExp primaryExp=null;
        Token IdentToken=null;
        FuncRParams funcRParams=null;
        UnaryOp unaryOp=null;
        UnaryExp unaryExp=null;
        if (now.type == Token.Type.IDENFR && tokens.get(curPos + 1).type == Token.Type.LPARENT) {
            //Ident '(' [FuncRParams] ')'
            IdentToken=match(Token.Type.IDENFR);
            match(Token.Type.LPARENT);
            if(isCond()){
                funcRParams=doFuncRParams();
            }
            match(Token.Type.RPARENT);
        }
        else if(now.type == Token.Type.PLUS || now.type == Token.Type.MINU || now.type == Token.Type.NOT){
            //UnaryOp UnaryExp
            unaryOp=doUnaryOp();
            unaryExp=doUnaryExp();
        }
        else{
            primaryExp=doPrimaryExp();
        }
        return new UnaryExp(primaryExp,IdentToken,funcRParams,unaryOp,unaryExp);
    }
    public UnaryOp doUnaryOp(){
        //'+' | '−' | '!'
        if (now.type == Token.Type.PLUS){
            match(Token.Type.PLUS);
            return new UnaryOp(1);
        }
        else if(now.type == Token.Type.MINU){
            match(Token.Type.MINU);
            return new UnaryOp(2);
        }
        else {
            match(Token.Type.NOT);
            return new UnaryOp(3);
        }
    }
    public FuncRParams doFuncRParams(){
        //Exp { ',' Exp }
        List<Exp> Explist=new ArrayList<>();
        Explist.add(doExp());
        while(now.type==Token.Type.COMMA){
            match(Token.Type.COMMA);
            Explist.add(doExp());
        }
        return new FuncRParams(Explist);
    }
    public MulExp doMulExp(){
        //UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
        //UnaryExp{('*' | '/' | '%') UnaryExp}
        List<UnaryExp> UnaryExpList=new ArrayList<>();
        List<Token> TokenList=new ArrayList<>();
        UnaryExpList.add(doUnaryExp());
        while (now.type == Token.Type.MULT || now.type == Token.Type.DIV || now.type == Token.Type.MOD){
            TokenList.add(match(now.type));
            UnaryExpList.add(doUnaryExp());
        }
        return new MulExp(UnaryExpList,TokenList);
    }
    public AddExp doAddExp(){
        //MulExp | AddExp ('+' | '−') MulExp
        //MulExp{('+' | '−') MulExp}
        List<MulExp> MulExpList=new ArrayList<>();
        List<Token> TokenList=new ArrayList<>();
        MulExpList.add(doMulExp());
        while (now.type == Token.Type.PLUS || now.type == Token.Type.MINU){
            TokenList.add(match(now.type));
            MulExpList.add(doMulExp());
        }
        return new AddExp(MulExpList,TokenList);
    }
    public RelExp doRelExp(){
        //AddExp{('<' | '>' | '<=' | '>=') AddExp}
        List<AddExp> AddExpList=new ArrayList<>();
        List<Token> TokenList=new ArrayList<>();
        AddExpList.add(doAddExp());
        while (now.type == Token.Type.LSS || now.type == Token.Type.GRE||now.type == Token.Type.LEQ||now.type == Token.Type.GEQ){
            TokenList.add(match(now.type));
            AddExpList.add(doAddExp());
        }
        return new RelExp(AddExpList,TokenList);
    }
    public EqExp doEqExp(){
        //RelExp {('==' | '!=') RelExp}
        List<RelExp> RelExpList=new ArrayList<>();
        List<Token> TokenList=new ArrayList<>();
        RelExpList.add(doRelExp());
        while (now.type == Token.Type.EQL || now.type == Token.Type.NEQ){
            TokenList.add(match(now.type));
            RelExpList.add(doRelExp());
        }
        return new EqExp(RelExpList,TokenList);
    }
    public LAndExp doLAndExp(){
        //EqExp {'&&' EqExp}
        List<EqExp> EqExpList=new ArrayList<>();
        EqExpList.add(doEqExp());
        while(now.type == Token.Type.AND){
            match(Token.Type.AND);
            EqExpList.add(doEqExp());
        }
        return new LAndExp(EqExpList);
    }
    public LOrExp doLOrExp(){
        //LAndExp{ '||' LAndExp}
        List<LAndExp> LAndExpList=new ArrayList<>();
        LAndExpList.add(doLAndExp());
        while(now.type == Token.Type.OR){
            match(Token.Type.OR);
            LAndExpList.add(doLAndExp());
        }
        return new LOrExp(LAndExpList);
    }
    public ConstExp doConstExp(){
        //AddExp
        AddExp addExp=doAddExp();
        return new ConstExp(addExp);
    }
    public boolean isCond(){//下一个是否是Cond
        return now.type == Token.Type.INTCON ||
                now.type == Token.Type.IDENFR ||
                now.type == Token.Type.NOT ||
                now.type == Token.Type.PLUS ||
                now.type == Token.Type.MINU ||
                now.type == Token.Type.LPARENT||
                now.type == Token.Type.CHRCON;
    }
    public static void main(String[] args){
        grammar.createMap();
        System.out.println(Grammar.nodeOutput.get(Nodetype.CompUnit));
        try {
            BufferedWriter writer = new BufferedWriter(new FileWriter("./parser.txt", false));
            writer.write("<CompUnit>");
        }catch (IOException e) {
            e.printStackTrace();
        }
    }
}
