package frontend;

import Nodes.*;
import Nodes.Character;
import Nodes.Number;
import Token.Token;
import java.util.*;
import Error.ErrorType;
import Error.CompileException;
import Error.ErrorHandler;
import Utils.IO;
/**
 * @Description:
 * @author
 * @date 2024/9/28 19:02
 */

/**
 * @author:
 * TODO  
 * 2024/9/28 19:02
 */
public class Parser {

    private Token now;
    private int index=0;
    private List<Token> tokens=new ArrayList<>();
    public static final Map<NodeType,String> nodeTypes;
    private CompUnit compUnit;
//    单例模式
    private static Parser parser=new Parser();
    private Parser(){}
    public static Parser getInstance(){
        return parser;
    }

//    初始化输出nodeType Map
    static{
        Map<NodeType,String> tempMap=new HashMap<>();
        tempMap.put(NodeType.AddExp,"<AddExp>\n");
        tempMap.put(NodeType.BType,"<BType>\n");
        tempMap.put(NodeType.Block,"<Block>\n");
        tempMap.put(NodeType.BlockItem,"<BlockItem>\n");
        tempMap.put(NodeType.Character,"<Character>\n");
        tempMap.put(NodeType.CompUnit,"<CompUnit>\n");
        tempMap.put(NodeType.Cond,"<Cond>\n");
        tempMap.put(NodeType.ConstDecl,"<ConstDecl>\n");
        tempMap.put(NodeType.ConstDef,"<ConstDef>\n");
        tempMap.put(NodeType.ConstExp,"<ConstExp>\n");
        tempMap.put(NodeType.ConstInitVal,"<ConstInitVal>\n");
        tempMap.put(NodeType.Decl,"<Decl>\n");
        tempMap.put(NodeType.EqExp,"<EqExp>\n");
        tempMap.put(NodeType.Exp,"<Exp>\n");
        tempMap.put(NodeType.ForStmt,"<ForStmt>\n");
        tempMap.put(NodeType.FuncDef,"<FuncDef>\n");
        tempMap.put(NodeType.FuncFParam,"<FuncFParam>\n");
        tempMap.put(NodeType.FuncFParams,"<FuncFParams>\n");
        tempMap.put(NodeType.FuncRParams,"<FuncRParams>\n");
        tempMap.put(NodeType.FuncType,"<FuncType>\n");
        tempMap.put(NodeType.InitVal,"<InitVal>\n");
        tempMap.put(NodeType.LAndExp,"<LAndExp>\n");
        tempMap.put(NodeType.LOrExp,"<LOrExp>\n");
        tempMap.put(NodeType.LVal,"<LVal>\n");
        tempMap.put(NodeType.MainFuncDef,"<MainFuncDef>\n");
        tempMap.put(NodeType.MulExp,"<MulExp>\n");
        tempMap.put(NodeType.Number,"<Number>\n");
        tempMap.put(NodeType.PrimaryExp,"<PrimaryExp>\n");
        tempMap.put(NodeType.RelExp,"<RelExp>\n");
        tempMap.put(NodeType.Stmt,"<Stmt>\n");
        tempMap.put(NodeType.UnaryExp,"<UnaryExp>\n");
        tempMap.put(NodeType.UnaryOp,"<UnaryOp>\n");
        tempMap.put(NodeType.VarDecl,"<VarDecl>\n");
        tempMap.put(NodeType.VarDef,"<VarDef>\n");
        nodeTypes=Collections.unmodifiableMap(tempMap);
    }

//    收token
    public void setTokens(){
        this.tokens=Lexer.getInstance().getTokens();
        now=tokens.get(index);
    }

    public void Parser_Main(){
        setTokens();
        this.compUnit=compUnit();
    }

//    CompUnit → {Decl} {FuncDef} MainFuncDef
    public CompUnit compUnit(){
        List<Decl> declList=new ArrayList<>();
        List<FuncDef> funcDefList=new ArrayList<>();
        MainFuncDef mainFuncDef=null;
        while(tokens.get(index+1).getLexType()!=LexType.MAINTK && tokens.get(index+2).getLexType()!=LexType.LPARENT){
            Decl decl=decl();
            declList.add(decl);
        }
        while(tokens.get(index+1).getLexType()!=LexType.MAINTK){
            FuncDef funcDef=funcDef();
            funcDefList.add(funcDef);
        }
        mainFuncDef=mainFuncDef();
        return new CompUnit(declList,funcDefList,mainFuncDef);
    }

//    Decl → ConstDecl | VarDecl
    public Decl decl(){
        ConstDecl constDecl=null;
        VarDecl varDecl=null;
        if(now.getLexType()==LexType.CONSTTK){
            constDecl=constDecl();
        }
        else{
            varDecl=varDecl();
        }
        return new Decl(constDecl,varDecl);
    }

//    ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';' // i
    public ConstDecl constDecl(){
        Token consttk=null;
        BType bType=null;
        List<ConstDef> constDefs=new ArrayList<>();
        List<Token> commaList=new ArrayList<>();
        Token semicn=null;

        consttk=match(LexType.CONSTTK);
        bType=bType();
        constDefs.add(constDef());
        while(now.getLexType()==LexType.COMMA){
            commaList.add(match(LexType.COMMA));
            constDefs.add(constDef());
        }
        semicn=match(LexType.SEMICN);

        return new ConstDecl(consttk,bType,constDefs,commaList,semicn);
    }

//    BType → 'int' | 'char'
    public BType bType(){
        Token inttk=null;
        Token chartk=null;
//        error为了帮助未知错误，也就是哪个都没匹配上（文法里面没有这个错误）
        Token error=null;

        if(now.getLexType()==LexType.INTTK){
            inttk=match(LexType.INTTK);
        }
        else if(now.getLexType()==LexType.CHARTK){
            chartk=match(LexType.CHARTK);
        }else{
            error=match(LexType.INTTK);
        }

        return new BType(inttk,chartk);
    }

//     ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal // b k
    public ConstDef constDef(){
        Token ident=null;
        Token lbrack=null;
        ConstExp constExp=null;
        Token rbrack=null;
        Token assign=null;
        ConstInitVal constInitVal=null;

        ident=match(LexType.IDENFR);
        if(now.getLexType()==LexType.LBRACK){
            lbrack=match(LexType.LBRACK);
            constExp=constExp();
            rbrack=match(LexType.RBRACK);
        }
        assign=match(LexType.ASSIGN);
        constInitVal=constInitVal();
        return new ConstDef(ident,lbrack,constExp,rbrack,assign,constInitVal);
    }

//     ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
    public ConstInitVal constInitVal(){
        List<ConstExp> constExps=new ArrayList<>();
        List<Token> commaList=new ArrayList<>();
        Token lbrace=null;
        Token rbrace=null;
        Token strcon=null;

        if(now.getLexType()==LexType.STRCON){
            strcon=match(LexType.STRCON);
        }
        else if(now.getLexType()==LexType.LBRACE){
            lbrace=match(LexType.LBRACE);
            if(now.getLexType()!=LexType.RBRACE){
                constExps.add(constExp());
                while(now.getLexType()==LexType.COMMA){
                    commaList.add(match(LexType.COMMA));
                    constExps.add(constExp());
                }
            }
            rbrace=match(LexType.RBRACE);
        }
        else{
            constExps.add(constExp());
        }
        return new ConstInitVal(constExps,lbrace,commaList,rbrace,strcon);
    }

//    VarDecl → BType VarDef { ',' VarDef } ';' // i
    public VarDecl varDecl(){
        BType bType=null;
        List<VarDef> varDefs=new ArrayList<>();
        List<Token> commaList=new ArrayList<>();
        Token semicn=null;

        bType = bType();
        varDefs.add(varDef());
        while (now.getLexType() == LexType.COMMA) {
            commaList.add(match(LexType.COMMA));
            varDefs.add(varDef());
        }
        semicn = match(LexType.SEMICN);
        return new VarDecl(bType,varDefs,commaList,semicn);
    }

//    VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal // b k
    public VarDef varDef(){
        Token ident=null;
        Token lbrack=null;
        Token rbrack=null;
        ConstExp constExp=null;
        Token assign=null;
        InitVal initVal=null;

        ident=match(LexType.IDENFR);
        if(now.getLexType()==LexType.LBRACK){
            lbrack=match(LexType.LBRACK);
            constExp=constExp();
            rbrack=match(LexType.RBRACK);
        }
        if(now.getLexType()==LexType.ASSIGN){
            assign=match(LexType.ASSIGN);
            initVal=initVal();
        }
        return new VarDef(ident,lbrack,constExp,rbrack,assign,initVal);
    }

//    InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
    public InitVal initVal(){
        List<Exp> exps=new ArrayList<>();
        Token lbrace=null;
        Token rbrace=null;
        List<Token> commaList=new ArrayList<>();
        Token strcon=null;

        if(now.getLexType()==LexType.STRCON){
            strcon=match(LexType.STRCON);
        }
        else if(now.getLexType()== LexType.LBRACE){
            lbrace=match(LexType.LBRACE);
            if(now.getLexType()!=LexType.RBRACE){
                exps.add(exp());
                while(now.getLexType()==LexType.COMMA){
                    commaList.add(match(LexType.COMMA));
                    exps.add(exp());
                }
            }
            rbrace=match(LexType.RBRACE);
        }
        else{
            exps.add(exp());
        }
        return new InitVal(exps,lbrace,commaList,rbrace,strcon);
    }

//    FuncDef → FuncType Ident '(' [FuncFParams] ')' Block // b g j
    public FuncDef funcDef(){
        FuncType funcType=null;
        Token ident=null;
        Token lparent=null;
        FuncFParams funcFParams=null;
        Token rparent=null;
        Block block=null;

        funcType=funcType();
        ident=match(LexType.IDENFR);
        lparent=match(LexType.LPARENT);
        if(now.getLexType()!= LexType.RPARENT){
            funcFParams=funcFParams();
        }
        rparent=match(LexType.RPARENT);
        block=block();
        return new FuncDef(funcType,ident,lparent,funcFParams,rparent,block);
    }

//    MainFuncDef → 'int' 'main' '(' ')' Block
    public MainFuncDef mainFuncDef(){
        Token inttk=null;
        Token maintk=null;
        Token lparent=null;
        Token rparent=null;
        Block block=null;

        inttk=match(LexType.INTTK);
        maintk=match(LexType.MAINTK);
        lparent=match(LexType.LPARENT);
        rparent=match(LexType.RPARENT);
        block=block();
        return new MainFuncDef(inttk,maintk,lparent,rparent,block);
    }

//     FuncType → 'void' | 'int' | 'char'
    public FuncType funcType(){
        Token voidtk=null;
        Token inttk=null;
        Token chartk=null;

        if(now.getLexType()==LexType.VOIDTK){
            voidtk=match(LexType.VOIDTK);
        }
        else if(now.getLexType()==LexType.INTTK){
            inttk=match(LexType.INTTK);
        }
        else{
            chartk=match(LexType.CHARTK);
        }
        return new FuncType(voidtk,inttk,chartk);
    }

//    FuncFParams → FuncFParam { ',' FuncFParam }
    public FuncFParams funcFParams(){
        List<FuncFParam> funcFParams=new ArrayList<>();
        List<Token> commaList=new ArrayList<>();

        funcFParams.add(funcFParam());
        while(now.getLexType()== LexType.COMMA){
            commaList.add(match(LexType.COMMA));
            funcFParams.add(funcFParam());
        }
        return new FuncFParams(funcFParams,commaList);
    }

//    FuncFParam → BType Ident ['[' ']'] // b k
    public FuncFParam funcFParam(){
        BType bType=null;
        Token ident=null;
        Token lbrack=null;
        Token rbrack=null;

        bType=bType();
        ident=match(LexType.IDENFR);
        if(now.getLexType()==LexType.LBRACK){
            lbrack= match(LexType.LBRACK);
            rbrack= match(LexType.RBRACK);
        }
        return new FuncFParam(bType,ident,lbrack,rbrack);
    }

//    Block → '{' { BlockItem } '}'
    public Block block(){
        List<BlockItem> blockItems=new ArrayList<>();
        Token lbrace=null;
        Token rbrace=null;

        lbrace=match(LexType.LBRACE);
        while(now.getLexType()!=LexType.RBRACE){
            blockItems.add(blockItem());
        }
        rbrace=match(LexType.RBRACE);
        return new Block(lbrace,blockItems,rbrace);
    }

//    BlockItem → Decl | Stmt
    public BlockItem blockItem(){
        Decl decl=null;
        Stmt stmt=null;
        if(now.getLexType()== LexType.INTTK || now.getLexType()== LexType.CHARTK || now.getLexType()==LexType.CONSTTK){
            decl=decl();
        }
        else{
            stmt=stmt();
        }
        return new BlockItem(decl,stmt);
    }
/*Stmt → LVal '=' Exp ';' // h i
| [Exp] ';' // i
| Block
| 'if' '(' Cond ')' Stmt [ 'else' Stmt ] // j
| 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt // h
| 'break' ';' | 'continue' ';' // i m
| 'return' [Exp] ';' // f i
| LVal '=' 'getint''('')'';' // h i j
| LVal '=' 'getchar''('')'';' // h i j
| 'printf''('StringConst {','Exp}')'';' // i j l
*/
    public Stmt stmt(){
        if(now.getLexType()==LexType.LBRACE){
//            Block
            Block block=block();
            return new Stmt(Stmt.StmtType.Block,block);
        }
        else if(now.getLexType()==LexType.IFTK){
//            'if' '(' Cond ')' Stmt [ 'else' Stmt ] // j
            Token iftk=null;
            Token lparent=null;
            Token rparent=null;
            Cond cond=null;
            List<Stmt> stmts=new ArrayList<>();
            Token elsetk=null;

            iftk=match(LexType.IFTK);
            lparent=match(LexType.LPARENT);
            cond=cond();
            rparent=match(LexType.RPARENT);
            stmts.add(stmt());
            if(now.getLexType()==LexType.ELSETK){
                elsetk=match(LexType.ELSETK);
                stmts.add(stmt());
            }
            return new Stmt(Stmt.StmtType.If,iftk,lparent,cond,rparent,elsetk,stmts);
        }
        else if(now.getLexType()==LexType.FORTK){
//            'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt // h
            Token fortk=null;
            Token lparent=null;
            ForStmt forStmt1=null;
            List<Token> semicnList=new ArrayList<>();
            Cond cond=null;
            ForStmt forStmt2=null;
            Token rparent=null;
            Stmt stmt=null;

            fortk=match(LexType.FORTK);
            lparent=match(LexType.LPARENT);
            if(now.getLexType()!= LexType.SEMICN){
                forStmt1=forStmt();
            }
            semicnList.add(match(LexType.SEMICN));
            if(now.getLexType()!= LexType.SEMICN){
                cond=cond();
            }
            semicnList.add(match(LexType.SEMICN));
            if(now.getLexType()!= LexType.RPARENT){
                forStmt2=forStmt();
            }
            rparent=match(LexType.RPARENT);
            stmt=stmt();
            return new Stmt(Stmt.StmtType.For,fortk,lparent,forStmt1,semicnList,cond,forStmt2,rparent,stmt);
        }
        else if(now.getLexType()== LexType.BREAKTK){
//            'break' ';'
            Token breaktk=null;
            Token semicn=null;

            breaktk=match(LexType.BREAKTK);
            semicn=match(LexType.SEMICN);
            return new Stmt(Stmt.StmtType.BC,breaktk,semicn);
        }
        else if(now.getLexType()== LexType.CONTINUETK){
//            'continue' ';'
            Token continuetk=null;
            Token semicn=null;

            continuetk=match(LexType.CONTINUETK);
            semicn=match(LexType.SEMICN);
            return new Stmt(Stmt.StmtType.BC,continuetk,semicn);
        }
        else if(now.getLexType()==LexType.RETURNTK){
//            'return' [Exp] ';' // f i
            Token returntk=null;
            Exp exp=null;
            Token semicn=null;

            returntk=match(LexType.RETURNTK);
            if(now.getLexType()!=LexType.SEMICN){
                exp=exp();
            }
            semicn=match(LexType.SEMICN);
            return new Stmt(Stmt.StmtType.Return,returntk,exp,semicn);
        }
        else if(now.getLexType()==LexType.PRINTFTK){
//            'printf''('StringConst {','Exp}')'';' // i j l
            Token printftk=null;
            Token lparent=null;
            Token strcon=null;
            List<Token> commaList=new ArrayList<>();
            List<Exp> exps=new ArrayList<>();
            Token rparent=null;
            Token semicn=null;

            printftk=match(LexType.PRINTFTK);
            lparent=match(LexType.LPARENT);
            strcon=match(LexType.STRCON);
            while(now.getLexType()== LexType.COMMA){
                commaList.add(match(LexType.COMMA));
                exps.add(exp());
            }
            rparent=match(LexType.RPARENT);
            semicn=match(LexType.SEMICN);
            return new Stmt(Stmt.StmtType.Printf,printftk,lparent,commaList,exps,strcon,rparent,semicn);
        }
//        LVal '=' Exp ';'
//        [Exp] ';' // i
//        LVal '=' 'getint''('')'';' // h i j
//        LVal '=' 'getchar''('')'';' // h i j
        else{
            int flag=0;
            for (int i = index; i < tokens.size() && tokens.get(i).getLineNumber() == now.getLineNumber(); i++) {
                if (tokens.get(i).getLexType() == LexType.ASSIGN) {
                    flag=1;
                    break;
                }
            }
            if(flag==0){
//                [Exp] ';' // i
                Exp exp=null;
                Token semicn=null;

                if(now.getLexType()!=LexType.SEMICN){
                    exp=exp();
                }
                semicn=match(LexType.SEMICN);
                return new Stmt(Stmt.StmtType.Exp,exp,semicn);
            }
            else{
                LVal lVal=null;
                Token assign=null;

                lVal=lVal();
                assign=match(LexType.ASSIGN);
                if(now.getLexType()==LexType.GETINTTK || now.getLexType()==LexType.GETCHARTK){
                    Token gettk=null;
                    Token lparent=null;
                    Token rparent=null;
                    Token semicn=null;

                    if(now.getLexType()==LexType.GETINTTK){
                        gettk=match(LexType.GETINTTK);
                    }
                    else{
                        gettk=match(LexType.GETCHARTK);
                    }
                    lparent=match(LexType.LPARENT);
                    rparent=match(LexType.RPARENT);
                    semicn=match(LexType.SEMICN);
                    return new Stmt(Stmt.StmtType.LValGetIC,lVal,assign,gettk,lparent,rparent,semicn);
                }
                else{
                    Exp exp=null;
                    Token semicn=null;

                    exp=exp();
                    semicn=match(LexType.SEMICN);
                    return new Stmt(Stmt.StmtType.LValExp,lVal,assign,exp,semicn);
                }
            }
        }
    }


//     ForStmt → LVal '=' Exp // h
    public ForStmt forStmt(){
        LVal lVal=null;
        Token assign=null;
        Exp exp=null;

        lVal=lVal();
        assign=match(LexType.ASSIGN);
        exp=exp();
        return new ForStmt(lVal,assign,exp);
    }

//    Exp → AddExp
    public Exp exp(){
        AddExp addExp=null;
        addExp=addExp();
        return new Exp(addExp);
    }

//    Cond → LOrExp
    public Cond cond(){
        LOrExp lOrExp=null;
        lOrExp=lOrExp();
        return new Cond(lOrExp);
    }

//     LVal → Ident ['[' Exp ']'] // c k
    public LVal lVal(){
        Token ident=null;
        Token lbrack=null;
        Token rbrack=null;
        Exp exp=null;

        ident=match(LexType.IDENFR);
        if(now.getLexType()== LexType.LBRACK){
            lbrack=match(LexType.LBRACK);
            exp=exp();
            rbrack=match(LexType.RBRACK);
        }
        return new LVal(ident,lbrack,exp,rbrack);
    }

//    PrimaryExp → '(' Exp ')' | LVal | Number | Character// j
    public PrimaryExp primaryExp(){
        Token lparent=null;
        Exp exp=null;
        Token rparent=null;
        LVal lVal=null;
        Number number=null;
        Character character=null;

        if(now.getLexType()== LexType.LPARENT){
            lparent=match(LexType.LPARENT);
            exp=exp();
            rparent=match(LexType.RPARENT);
        }
        else if(now.getLexType()== LexType.IDENFR){
            lVal=lVal();
        }
        else if(now.getLexType()== LexType.INTCON){
            number=number();
        }
        else if(now.getLexType()==LexType.CHRCON){
            character=character();
        }
        return new PrimaryExp(lparent,exp,rparent,lVal,number,character);
    }

//     Number → IntConst
    public Number number(){
        Token intcon=null;
        intcon=match(LexType.INTCON);
        return new Number(intcon);
    }

//    Character → CharConst
    public Character character(){
        Token charcon=null;
        charcon=match(LexType.CHRCON);
        return new Character(charcon);
    }

//     UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp // c d e j
    public UnaryExp unaryExp(){
        PrimaryExp primaryExp=null;
        Token ident=null;
        Token lparent=null;
        Token rparent=null;
        FuncRParams funcRParams=null;
        UnaryOp unaryOp=null;
        UnaryExp unaryExp=null;

        if(now.getLexType()==LexType.IDENFR && tokens.get(index+1).getLexType()== LexType.LPARENT){
            ident=match(LexType.IDENFR);
            lparent=match(LexType.LPARENT);
            if(now.getLexType()!= LexType.RPARENT){
                funcRParams=funcRParams();
            }
            rparent=match(LexType.RPARENT);
        }
        else if (now.getLexType()== LexType.PLUS || now.getLexType()== LexType.MINU || now.getLexType()== LexType.NOT) {
            unaryOp=unaryOp();
            unaryExp=unaryExp();
        }
        else{
            primaryExp=primaryExp();
        }
        return new UnaryExp(primaryExp,ident,lparent,rparent,funcRParams,unaryOp,unaryExp);
    }

//    UnaryOp → '+' | '−' | '!'
    public UnaryOp unaryOp(){
        Token option=null;

        if(now.getLexType()== LexType.PLUS){
            option=match(LexType.PLUS);
        }
        else if(now.getLexType()== LexType.MINU){
            option=match(LexType.MINU);
        }
        else{
            option=match(LexType.NOT);
        }
        return new UnaryOp(option);
    }

//    FuncRParams → Exp { ',' Exp }
    public FuncRParams funcRParams(){
        List<Exp> exps=new ArrayList<>();
        List<Token> commaList=new ArrayList<>();

        exps.add(exp());
        while(now.getLexType()==LexType.COMMA){
            commaList.add(match(LexType.COMMA));
            exps.add(exp());
        }
        return new FuncRParams(exps,commaList);
    }

//    MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
//    MulExp -> UnaryExp { ('*' | '/' | '%') UnaryExp }
    public MulExp mulExp(){
        List<UnaryExp> unaryExps=new ArrayList<>();
        List<Token> options=new ArrayList<>();

        unaryExps.add(unaryExp());
        while(now.getLexType()==LexType.MULT || now.getLexType()==LexType.DIV || now.getLexType()==LexType.MOD){
            if(now.getLexType()==LexType.MULT){
                options.add(match(LexType.MULT));
            }
            else if(now.getLexType()==LexType.DIV){
                options.add(match(LexType.DIV));
            }
            else{
                options.add(match(LexType.MOD));
            }
            unaryExps.add(unaryExp());
        }
        return new MulExp(unaryExps,options);
    }

//    AddExp → MulExp | AddExp ('+' | '−') MulExp
//    AddExp -> MulExp { ('+' | '−') MulExp }
    public AddExp addExp(){
        List<MulExp> mulExps=new ArrayList<>();
        List<Token> options=new ArrayList<>();

        mulExps.add(mulExp());
        while(now.getLexType()==LexType.PLUS || now.getLexType()==LexType.MINU){
            if(now.getLexType()==LexType.PLUS){
                options.add(match(LexType.PLUS));
            }
            else{
                options.add(match(LexType.MINU));
            }
            mulExps.add(mulExp());
        }
        return new AddExp(mulExps,options);
    }

//     RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
//    RelExp -> AddExp { ('<' | '>' | '<=' | '>=') AddExp }
    public RelExp relExp(){
        List<AddExp> addExps=new ArrayList<>();
        List<Token> options=new ArrayList<>();

        addExps.add(addExp());
        while(now.getLexType()==LexType.LSS || now.getLexType()==LexType.LEQ || now.getLexType()==LexType.GRE || now.getLexType()==LexType.GEQ){
            if(now.getLexType()==LexType.LSS){
                options.add(match(LexType.LSS));
            }
            else if(now.getLexType()==LexType.LEQ){
                options.add(match(LexType.LEQ));
            }
            else if(now.getLexType()==LexType.GRE){
                options.add(match(LexType.GRE));
            }
            else{
                options.add(match(LexType.GEQ));
            }
            addExps.add(addExp());
        }
        return new RelExp(addExps,options);
    }

//     EqExp → RelExp | EqExp ('==' | '!=') RelExp
//    EqExp -> RelExp { ('==' | '!=') RelExp }
    public EqExp eqExp(){
        List<RelExp> relExps=new ArrayList<>();
        List<Token> options=new ArrayList<>();

        relExps.add(relExp());
        while(now.getLexType()==LexType.EQL || now.getLexType()==LexType.NEQ){
            if(now.getLexType()==LexType.EQL){
                options.add(match(LexType.EQL));
            }
            else{
                options.add(match(LexType.NEQ));
            }
            relExps.add(relExp());
        }
        return new EqExp(relExps,options);
    }

//    LAndExp → EqExp | LAndExp '&&' EqExp
//    LAndExp -> EqExp { '&&' EqExp }
    public LAndExp lAndExp(){
        List<EqExp> eqExps=new ArrayList<>();
        List<Token> andList=new ArrayList<>();

        eqExps.add(eqExp());
        while(now.getLexType()==LexType.AND){
            andList.add(match(LexType.AND));
            eqExps.add(eqExp());
        }
        return new LAndExp(eqExps,andList);
    }

//    LOrExp → LAndExp | LOrExp '||' LAndExp
//    LOrExp -> LAndExp { '||' LAndExp }
    public LOrExp lOrExp(){
        List<LAndExp> lAndExps=new ArrayList<>();
        List<Token> orList=new ArrayList<>();

        lAndExps.add(lAndExp());
        while(now.getLexType()==LexType.OR){
            orList.add(match(LexType.OR));
            lAndExps.add(lAndExp());
        }
        return new LOrExp(lAndExps,orList);
    }

//     ConstExp → AddExp
    public ConstExp constExp(){
        AddExp addExp=null;
        addExp=addExp();
        return new ConstExp(addExp);
    }

    public Token match(LexType expect){
        Token tmp=now;
        if(now.getLexType()==expect){
            if(index<tokens.size()-1){
                now=tokens.get(++index);
            }
            return tmp;
        }
        else if (expect==LexType.SEMICN) {
            ErrorHandler.getInstance().add(new CompileException(tokens.get(index-1).getLineNumber(), ErrorType.i));
            return new Token(LexType.SEMICN,lexerTypes.get(LexType.SEMICN), tokens.get(index-1).getLineNumber());
        }
        else if (expect==LexType.RPARENT) {
            ErrorHandler.getInstance().add(new CompileException(tokens.get(index-1).getLineNumber(), ErrorType.j));
            return new Token(LexType.RPARENT,lexerTypes.get(LexType.RPARENT), tokens.get(index-1).getLineNumber());
        } else if (expect==LexType.RBRACK) {
            ErrorHandler.getInstance().add(new CompileException(tokens.get(index-1).getLineNumber(), ErrorType.k));
            return new Token(LexType.RBRACK,lexerTypes.get(LexType.RBRACK), tokens.get(index-1).getLineNumber());
        }
        else{
//            ErrorHandler.getInstance().print(new CompileException(tokens.get(index-1).getLineNumber(), ErrorType.NoneMatch));
            return new Token(expect,lexerTypes.get(expect), tokens.get(index-1).getLineNumber());
        }
    }

    public void Parser_print(){
        compUnit.print();
    }

    public static final Map<LexType,String> lexerTypes;
    static{
        Map<LexType,String> lexerMap=new HashMap<>();
        lexerMap.put(LexType.IDENFR,"Ident");
        lexerMap.put(LexType.INTCON,"IntConst");
        lexerMap.put(LexType.STRCON,"StringConst");
        lexerMap.put(LexType.CHRCON,"CharConst");
        lexerMap.put(LexType.MAINTK,"main");
        lexerMap.put(LexType.CONSTTK,"const");
        lexerMap.put(LexType.INTTK,"int");
        lexerMap.put(LexType.CHARTK,"char");
        lexerMap.put(LexType.BREAKTK,"break");
        lexerMap.put(LexType.CONTINUETK,"continue");
        lexerMap.put(LexType.IFTK,"if");
        lexerMap.put(LexType.ELSETK,"else");
        lexerMap.put(LexType.NOT,"!");
        lexerMap.put(LexType.AND,"&&");
        lexerMap.put(LexType.OR,"||");
        lexerMap.put(LexType.FORTK,"for");
        lexerMap.put(LexType.GETINTTK,"getint");
        lexerMap.put(LexType.GETCHARTK,"getchar");
        lexerMap.put(LexType.PRINTFTK,"printf");
        lexerMap.put(LexType.RETURNTK,"return");
        lexerMap.put(LexType.PLUS,"+");
        lexerMap.put(LexType.MINU,"-");
        lexerMap.put(LexType.VOIDTK,"void");
        lexerMap.put(LexType.MULT,"*");
        lexerMap.put(LexType.DIV,"/");
        lexerMap.put(LexType.MOD,"%");
        lexerMap.put(LexType.LSS,"<");
        lexerMap.put(LexType.LEQ,"<=");
        lexerMap.put(LexType.GRE,">");
        lexerMap.put(LexType.GEQ,">=");
        lexerMap.put(LexType.EQL,"==");
        lexerMap.put(LexType.NEQ,"!=");
        lexerMap.put(LexType.ASSIGN,"=");
        lexerMap.put(LexType.SEMICN,";");
        lexerMap.put(LexType.COMMA,",");
        lexerMap.put(LexType.LPARENT,"(");
        lexerMap.put(LexType.RPARENT,")");
        lexerMap.put(LexType.LBRACK,"[");
        lexerMap.put(LexType.RBRACK,"]");
        lexerMap.put(LexType.LBRACE,"{");
        lexerMap.put(LexType.RBRACE,"}");
        lexerTypes=Collections.unmodifiableMap(lexerMap);
    }
}
