package frontend;

import error.error;
import error.errorList;
import frontend.nodes.*;

import java.io.IOException;
import java.util.ArrayList;

/**
 * @author
 * @Description:
 * @date 2024/9/27 14:59
 */
public class Parser {
    public token currentToken;
    private static int i = 0;
    public ArrayList<token> tokens;
    public CompUnitNode compUnitNode;
    public Parser(ArrayList<token> tokenList){
        this.tokens=tokenList;
        if(!tokenList.isEmpty())currentToken=tokenList.get(i);//首字符
    }
    public void parse(){
        this.compUnitNode=CompUnit();
    }
    public void print()throws IOException {
        compUnitNode.output();
    }
    private CompUnitNode CompUnit() {
        ArrayList<DeclNode> declNodes = new ArrayList<>();
        ArrayList<FunDefNode> funDefNodes = new ArrayList<>();
        MainFuncDefNode mainFuncDefNode;
        while (this.tokens.get(i+1).type!= token.Type.MAINTK&&
        this.tokens.get(i+2).type!= token.Type.LPARENT) {//不为main或函数声明，即为变量声明
            DeclNode declNode=Decl();
            declNodes.add(declNode);
        }
        while (this.tokens.get(i+1).type!= token.Type.MAINTK) {//不为main，即为函数声明
            FunDefNode funDefNode=FuncDef();
            funDefNodes.add(funDefNode);
        }
        mainFuncDefNode=MainFuncDef();
        return new CompUnitNode(declNodes,funDefNodes,mainFuncDefNode);
    }
    private DeclNode Decl() {
        ConstDeclNode constDeclNode = null;
        VarDeclNode varDeclNode = null;
        if(currentToken.type== token.Type.CONSTTK){
            constDeclNode=ConstDecl();
        }else {
            varDeclNode=VarDecl();
        }
        return new DeclNode(constDeclNode,varDeclNode);
    }
    private ConstDeclNode ConstDecl() {
        token constToken=consumeToken(token.Type.CONSTTK);//'const'
        BTypeNode bTypeNode=BType();
        ArrayList<ConstDefNode> constDefNodes=new ArrayList<>();
        ArrayList<token> commas=new ArrayList<>();
        token semicn;
        constDefNodes.add(ConstDef());//第一个变量
        while(currentToken.type.equals(token.Type.COMMA)){
            commas.add(consumeToken(token.Type.COMMA));
            constDefNodes.add(ConstDef());
        }
        semicn=consumeToken(token.Type.SEMICN);//;号
        return new ConstDeclNode(constToken,bTypeNode,constDefNodes,commas,semicn);
    }
    private BTypeNode BType() {
        token intToken = null;
        token charToken = null;

        if(currentToken.type.equals(token.Type.INTTK)){
            intToken=consumeToken(token.Type.INTTK);
            return new BTypeNode(intToken);
        }else {
            charToken=consumeToken(token.Type.CHARTK);
            return new BTypeNode(charToken);
        }

    }
    private ConstDefNode ConstDef() {
        //ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal
        token ident;
        token assign;//=
        token lbrack = null,rbrack = null;//[,]
        ConstExpNode constExpNode = null;
        ConstInitValNode constInitValNode;
        ident=consumeToken(token.Type.IDENFR);
        if(currentToken.type.equals(token.Type.LBRACK)){
            lbrack=consumeToken(token.Type.LBRACK);
            constExpNode=ConstExp();
            rbrack=consumeToken(token.Type.RBRACK);
        }
        assign=consumeToken(token.Type.ASSIGN);
        constInitValNode=constInitVal();
        return new ConstDefNode(ident,lbrack,constExpNode,rbrack,assign,constInitValNode);
    }

    private ConstExpNode ConstExp() {
        //ConstExp → AddExp
        AddExpNode addExpNode;
        addExpNode=AddExp();
        return new ConstExpNode(addExpNode);
    }



    private ConstInitValNode constInitVal() {
        //ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
        ConstExpNode constExpNode = null;
        ArrayList<ConstExpNode> constExpNodes = new ArrayList<>();
        token lbraceToken = null;//{
        token rbraceToken = null;//}
        ArrayList<token> commas = new ArrayList<>();
        token stringConst = null;
        if(currentToken.type.equals(token.Type.LBRACE)){
            lbraceToken=consumeToken(token.Type.LBRACE);
            if(!currentToken.type.equals(token.Type.RBRACE)){
                constExpNodes.add(ConstExp());
                while (currentToken.type.equals(token.Type.COMMA)) {
                    commas.add(consumeToken(token.Type.COMMA));
                    constExpNodes.add(ConstExp());
                }
            }
            rbraceToken=consumeToken(token.Type.RBRACE);
        }else if(currentToken.type.equals(token.Type.STRCON)){
            stringConst=consumeToken(token.Type.STRCON);
        }else {
            constExpNode=ConstExp();
        }
        return new ConstInitValNode(constExpNode,lbraceToken,constExpNodes,rbraceToken,commas,stringConst);
    }

    private VarDeclNode VarDecl() {
        //VarDecl → BType VarDef { ',' VarDef } ';'
        BTypeNode bTypeNode;
        ArrayList<VarDefNode> varDefNodes = new ArrayList<>();
        ArrayList<token> commas = new ArrayList<>();
        token semicn;
        bTypeNode=BType();
        varDefNodes.add(VarDef());
        while(currentToken.type.equals(token.Type.COMMA)){
            commas.add(consumeToken(token.Type.COMMA));
            varDefNodes.add(VarDef());
        }
        semicn=consumeToken(token.Type.SEMICN);
        return new VarDeclNode(bTypeNode,varDefNodes,commas,semicn);
    }

    private VarDefNode VarDef() {
        //VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal
        token ident;
        token lbrack = null;
        ConstExpNode constExpNode = null;
        token rbrack = null;
        token assign = null;
        InitValNode initValNode = null;
        ident=consumeToken(token.Type.IDENFR);
        if(currentToken.type.equals(token.Type.LBRACK)){
            lbrack=consumeToken(token.Type.LBRACK);
            constExpNode=ConstExp();
            rbrack=consumeToken(token.Type.RBRACK);
        }
        if(currentToken.type.equals(token.Type.ASSIGN)){
            assign=consumeToken(token.Type.ASSIGN);
            initValNode=InitVal();
        }
        return new VarDefNode(ident,lbrack,constExpNode,rbrack,assign,initValNode);
    }

    private InitValNode InitVal() {
        // InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
        ExpNode expNode = null;
        token lbrace = null;
        ArrayList<ExpNode> expNodes = new ArrayList<>();
        ArrayList<token> commas=new ArrayList<>();
        token rbrace = null;
        token string = null;
        if(currentToken.type.equals(token.Type.LBRACE)){
            lbrace=consumeToken(token.Type.LBRACE);
            if (!currentToken.type.equals(token.Type.RBRACE)) {
                expNodes.add(Exp());
                while (!currentToken.type.equals(token.Type.RBRACE)) {
                    commas.add(consumeToken(token.Type.COMMA));
                    expNodes.add(Exp());
                }
            }
            rbrace=consumeToken(token.Type.RBRACE);
        }else if(currentToken.type.equals(token.Type.STRCON)){
            string=consumeToken(token.Type.STRCON);
        }else {
            expNode=Exp();
        }
        return new InitValNode(expNode,lbrace,expNodes,commas,rbrace,string);
    }

    private ExpNode Exp() {
        //Exp → AddExp
        AddExpNode addExpNode;
        addExpNode=AddExp();
        return new ExpNode(addExpNode);
    }

    private FunDefNode FuncDef() {
        //FuncDef → FuncType Ident '(' [FuncFParams] ')' Block
        FuncTypeNode funcTypeNode;
        token ident;
        token lparent;
        FuncFParamsNode funcFParamsNode = null;
        token rparent;
        BlockNode blockNode;
        funcTypeNode=FuncType();
        ident=consumeToken(token.Type.IDENFR);
        lparent=consumeToken(token.Type.LPARENT);
        if(currentToken.type.equals(token.Type.INTTK)||currentToken.type.equals(token.Type.CHARTK)){
            funcFParamsNode=FuncFParams();
        }
        rparent=consumeToken(token.Type.RPARENT);
        blockNode=Block();
        return new FunDefNode(funcTypeNode,ident,lparent,funcFParamsNode,rparent,blockNode);
    }
    private FuncFParamsNode FuncFParams() {
        // FuncFParams → FuncFParam { ',' FuncFParam }
        ArrayList<FuncFParamNode> funcFParamNodes = new ArrayList<>();
        ArrayList<token> commas = new ArrayList<>();
        funcFParamNodes.add(FuncFParam());
        while(currentToken.type.equals(token.Type.COMMA)){
            commas.add(consumeToken(token.Type.COMMA));
            funcFParamNodes.add(FuncFParam());
        }
        return new FuncFParamsNode(funcFParamNodes,commas);
    }

    private FuncFParamNode FuncFParam() {
        // FuncFParam → BType Ident ['[' ']']
        BTypeNode bTypeNode;
        token ident;
        token lbrack = null;
        token rbrack = null;
        bTypeNode=BType();
        ident=consumeToken(token.Type.IDENFR);
        if(currentToken.type.equals(token.Type.LBRACK)){
            lbrack=consumeToken(token.Type.LBRACK);
            rbrack=consumeToken(token.Type.RBRACK);
        }
        return new FuncFParamNode(bTypeNode,ident,lbrack,rbrack);
    }

    private FuncTypeNode FuncType() {
        // FuncType → 'void' | 'int' | 'char'
        token voidToken = null;
        token intToken = null;
        token charToken = null;
        if(currentToken.type.equals(token.Type.VOIDTK)){
            voidToken=consumeToken(token.Type.VOIDTK);
            return new FuncTypeNode(voidToken);
        }else if(currentToken.type.equals(token.Type.INTTK)){
            intToken=consumeToken(token.Type.INTTK);
            return new FuncTypeNode(intToken);
        }else {
            charToken=consumeToken(token.Type.CHARTK);
            return new FuncTypeNode(charToken);
        }
    }
    private MainFuncDefNode MainFuncDef() {
        //MainFuncDef → 'int' 'main' '(' ')' Block
        token intToken;
        token mainToken;
        token lparent;
        token rparent;
        BlockNode blockNode;
        intToken=consumeToken(token.Type.INTTK);
        mainToken=consumeToken(token.Type.MAINTK);
        lparent=consumeToken(token.Type.LPARENT);
        rparent=consumeToken(token.Type.RPARENT);
        blockNode=Block();
        return new MainFuncDefNode(intToken,mainToken,lparent,rparent,blockNode);
    }
    

    
    private BlockNode Block() {
        //Block → '{' { BlockItem } '}'
        token lbrace;
        token rbrace;
        ArrayList<BlockItemNode> blockItemNodes = new ArrayList<>();
        lbrace=consumeToken(token.Type.LBRACE);
        while(!currentToken.type.equals(token.Type.RBRACE)){
            blockItemNodes.add(BlockItem());
        }
        rbrace=consumeToken(token.Type.RBRACE);
        return new BlockNode(lbrace,blockItemNodes,rbrace);
    }

    private BlockItemNode BlockItem() {
        // BlockItem → Decl | Stmt
        DeclNode declNode = null;
        StmtNode stmtNode = null;
        if(currentToken.type.equals(token.Type.CONSTTK)||
                currentToken.type.equals(token.Type.INTTK)||
                currentToken.type.equals(token.Type.CHARTK)){
            declNode=Decl();
        }else {
            stmtNode=Stmt();
        }
        return new BlockItemNode(declNode,stmtNode);
    }

    private StmtNode Stmt() {
        /*
         Stmt → LVal '=' Exp ';'
         | [Exp] ';'
         | Block -----------------------------------------1
         | 'if' '(' Cond ')' Stmt [ 'else' Stmt ]-----------------------1
         | 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt----------1
         | 'break' ';' | 'continue' ';'---------------------------------1
         | 'return' [Exp] ';'-------------------------------------------1
         | LVal '=' 'getint''('')'';'
         | LVal '=' 'getchar''('')'';'
         | 'printf''('StringConst {','Exp}')'';'-------------------------1
        */
        if(currentToken.type.equals(token.Type.LBRACE)){
            //Block
            BlockNode blockNode=Block();
            return new StmtNode(StmtNode.stmtType.Block,blockNode);
        }else if(currentToken.type.equals(token.Type.IFTK)){
            //'if' '(' Cond ')' Stmt [ 'else' Stmt ]
            token ifToken=consumeToken(token.Type.IFTK);
            token leftParentToken=consumeToken(token.Type.LPARENT);
            CondNode condNode=Cond();
            token rightParentToken=consumeToken(token.Type.RPARENT);
            StmtNode ifStmt=Stmt();
            token elseToken = null;
            StmtNode elseStmt = null;
            if(currentToken.type.equals(token.Type.ELSETK)){
                elseToken=consumeToken(token.Type.ELSETK);
                elseStmt=Stmt();
            }
            return new StmtNode(StmtNode.stmtType.If,ifToken,leftParentToken,condNode,rightParentToken,ifStmt,elseToken,elseStmt);
        }else if(currentToken.type.equals(token.Type.FORTK)){
            //'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
            token forToken=consumeToken(token.Type.FORTK);
            token leftParentToken=consumeToken(token.Type.LPARENT);
            ForStmtNode condStmt1 = null,condStmt2 = null;
            CondNode condNode = null;
            StmtNode stmtNode;
            ArrayList<token> semicns = new ArrayList<>();
            if(!currentToken.type.equals(token.Type.SEMICN)) condStmt1 = ForStmt();
            semicns.add(consumeToken(token.Type.SEMICN));
            if(!currentToken.type.equals(token.Type.SEMICN)) condNode = Cond();
            semicns.add(consumeToken(token.Type.SEMICN));
            if(!currentToken.type.equals(token.Type.RPARENT)) condStmt2 = ForStmt();
            token rightParentToken=consumeToken(token.Type.RPARENT);
            stmtNode=Stmt();
            return new StmtNode(StmtNode.stmtType.For,forToken,leftParentToken,condStmt1,semicns,condNode,
                    condStmt2,rightParentToken,stmtNode);
        }else if(currentToken.type.equals(token.Type.BREAKTK)){
            //'break' ';' | 'continue' ';'
            token breakOrContinueToken=consumeToken(token.Type.BREAKTK);
            token semicn=consumeToken(token.Type.SEMICN);
            return new StmtNode(StmtNode.stmtType.Break,breakOrContinueToken,semicn);
        }else if(currentToken.type.equals(token.Type.CONTINUETK)){
            //'break' ';' | 'continue' ';'
            token breakOrContinueToken=consumeToken(token.Type.CONTINUETK);
            token semicn=consumeToken(token.Type.SEMICN);
            return new StmtNode(StmtNode.stmtType.Continue,breakOrContinueToken,semicn);
        }else if(currentToken.type.equals(token.Type.RETURNTK)){
            //'return' [Exp] ';'
            token returnToken=consumeToken(token.Type.RETURNTK);
            ExpNode expNode = null;
            token semicn;
            if(!currentToken.type.equals(token.Type.SEMICN)) {
                if(isExp()){
                    expNode=Exp();
                }
            }
            semicn=consumeToken(token.Type.SEMICN);
            return new StmtNode(StmtNode.stmtType.Return,returnToken,expNode,semicn);
        }else if(currentToken.type.equals(token.Type.PRINTFTK)){
            //'printf''('StringConst {','Exp}')'';'
            token printfToken=consumeToken(token.Type.PRINTFTK);
            token leftParentToken=consumeToken(token.Type.LPARENT);
            token formatString=consumeToken(token.Type.STRCON);
            ArrayList<token> commas = new ArrayList<>();
            ArrayList<ExpNode> expNodes = new ArrayList<>();
            while(currentToken.type.equals(token.Type.COMMA)){
                commas.add(consumeToken(token.Type.COMMA));
                expNodes.add(Exp());
            }
            token rightParentToken=consumeToken(token.Type.RPARENT);
            token semicn=consumeToken(token.Type.SEMICN);
            return new StmtNode(StmtNode.stmtType.Printf,printfToken,leftParentToken,formatString,commas,expNodes,rightParentToken,semicn);
        }else {
            int index=i;
            for(int j=i;j<tokens.size();j++){
                if(tokens.get(j).lineno!=currentToken.lineno)break;
                if(tokens.get(j).type.equals(token.Type.ASSIGN))index=j;
            }
            if(index>i){
                //LVal '=' Exp ';'
                //LVal '=' 'getint''('')'';'
                //LVal '=' 'getchar''('')'';'
                LvalNode lvalNode=Lval();
                token assign=consumeToken(token.Type.ASSIGN);
                if(currentToken.type.equals(token.Type.GETINTTK)){
                    token getintToken=consumeToken(token.Type.GETINTTK);
                    token leftParentToken=consumeToken(token.Type.LPARENT);
                    token rightParentToken=consumeToken(token.Type.RPARENT);
                    token semicn=consumeToken(token.Type.SEMICN);
                    return new StmtNode(StmtNode.stmtType.Getint,lvalNode,assign,getintToken,leftParentToken,rightParentToken,semicn);
                }else if(currentToken.type.equals(token.Type.GETCHARTK)){
                    token getcharToken=consumeToken(token.Type.GETCHARTK);
                    token leftParentToken=consumeToken(token.Type.LPARENT);
                    token rightParentToken=consumeToken(token.Type.RPARENT);
                    token semicn=consumeToken(token.Type.SEMICN);
                    return new StmtNode(StmtNode.stmtType.Getchar,lvalNode,assign,getcharToken,leftParentToken,rightParentToken,semicn);
                }else {
                    ExpNode  expNode=null;
                    if(isExp()){
                        expNode=Exp();
                    }
                    token semicn=consumeToken(token.Type.SEMICN);
                    return new StmtNode(StmtNode.stmtType.Lval,lvalNode,assign,expNode,semicn);
                }
            }else {
                //[Exp] ';'
                ExpNode expNode = null;
                if(isExp()){
                    expNode=Exp();
                }
                token semicn=consumeToken(token.Type.SEMICN);
                return new StmtNode(StmtNode.stmtType.Exp,expNode,semicn);
            }
        }
    }

    private ForStmtNode ForStmt() {
        // ForStmt → LVal '=' Exp
        LvalNode lvalNode=Lval();
        token assign=consumeToken(token.Type.ASSIGN);
        ExpNode expNode=Exp();
        return new ForStmtNode(lvalNode,assign,expNode);
    }

    private LvalNode Lval() {
        //LVal → Ident ['[' Exp ']']
        token ident=consumeToken(token.Type.IDENFR);
        token lbrack = null;
        token rbrack = null;
        ExpNode expNode = null;
        if(currentToken.type.equals(token.Type.LBRACK)){
            lbrack=consumeToken(token.Type.LBRACK);
            expNode=Exp();
            rbrack=consumeToken(token.Type.RBRACK);
        }
        return new LvalNode(ident,lbrack,rbrack,expNode);
    }
    private PrimaryExpNode Primary(){
        //PrimaryExp → '(' Exp ')' | LVal | Number | Character
        if(currentToken.type.equals(token.Type.LPARENT)){
            token lparent=consumeToken(token.Type.LPARENT);
            ExpNode expNode=Exp();
            token rparent=consumeToken(token.Type.RPARENT);
            return new PrimaryExpNode(lparent,rparent,expNode);
        }else if(currentToken.type.equals(token.Type.INTCON)){
            NumberNode numberNode=number();
            return  new PrimaryExpNode(numberNode);
        }else if(currentToken.type.equals(token.Type.CHRCON)){
            CharacterNode characterNode=character();
            return  new PrimaryExpNode(characterNode);
        }else {
            LvalNode lvalNode=Lval();
            return new PrimaryExpNode(lvalNode);
        }
    }

    private CharacterNode character() {
        //Character → CharConst
        return new CharacterNode(consumeToken(token.Type.CHRCON));
    }

    private NumberNode number() {
        //Number → IntConst
        return new NumberNode(consumeToken(token.Type.INTCON));
    }

    private CondNode Cond() {
        //Cond → LOrExp
        LOrExpNode lOrExpNode;
        lOrExpNode=LOrExp();
        return new CondNode(lOrExpNode);
    }

    private LOrExpNode LOrExp() {
        // LOrExp → LAndExp | LOrExp '||' LAndExp
        LAndExpNode lAndExpNode=LAndExp();
        LOrExpNode lOrExpNode = null;
        token or = null;
        if(currentToken.type.equals(token.Type.OR)){
            or=consumeToken(token.Type.OR);
            lOrExpNode=LOrExp();
        }
        return new LOrExpNode(lOrExpNode,or,lAndExpNode);
    }

    private LAndExpNode LAndExp() {
        //LAndExp → EqExp | LAndExp '&&' EqExp
        EqExpNode eqExpNode = EqExp();
        LAndExpNode lAndExpNode = null;
        token and = null;
        if(currentToken.type.equals(token.Type.AND)){
            and=consumeToken(token.Type.AND);
            lAndExpNode=LAndExp();
        }
        return new LAndExpNode(eqExpNode,and,lAndExpNode);
    }

    private EqExpNode EqExp() {
        //EqExp → RelExp | EqExp ('==' | '!=') RelExp
        EqExpNode eqExpNode = null;
        RelExpNode relExpNode=RelExp();
        token equalOrNotToken = null;
        if(currentToken.type.equals(token.Type.EQL)||currentToken.type.equals(token.Type.NEQ)){
            if(currentToken.type.equals(token.Type.EQL))equalOrNotToken=consumeToken(token.Type.EQL);
            else equalOrNotToken=consumeToken(token.Type.NEQ);
            eqExpNode=EqExp();
        }
        return new EqExpNode(eqExpNode,relExpNode,equalOrNotToken);
    }

    private RelExpNode RelExp() {
        //RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
        RelExpNode relExpNode = null;
        AddExpNode addExpNode=AddExp();
        token op = null;
        if(currentToken.type.equals(token.Type.LSS)){
            op=consumeToken(token.Type.LSS);
            relExpNode=RelExp();
        }else if(currentToken.type.equals(token.Type.GRE)){
            op=consumeToken(token.Type.GRE);
            relExpNode=RelExp();
        }else if(currentToken.type.equals(token.Type.LEQ)){
            op=consumeToken(token.Type.LEQ);
            relExpNode=RelExp();
        }else if(currentToken.type.equals(token.Type.GEQ)){
            op=consumeToken(token.Type.GEQ);
            relExpNode=RelExp();
        }
        return new RelExpNode(relExpNode,addExpNode,op);
    }
    private AddExpNode AddExp() {
        //AddExp → MulExp | AddExp ('+' | '−') MulExp
        MulExpNode mulExpNode=MulExp();
        AddExpNode addExpNode = null;
        token op = null;
        if(currentToken.type.equals(token.Type.PLUS)){
            op=consumeToken(token.Type.PLUS);
            addExpNode=AddExp();
        }else if(currentToken.type.equals(token.Type.MINU)){
            op=consumeToken(token.Type.MINU);
            addExpNode=AddExp();
        }
        return new AddExpNode(mulExpNode,addExpNode,op);
    }

    private MulExpNode MulExp() {
        //MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
        UnaryExpNode unaryExpNode=UnaryExp();
        MulExpNode mulExpNode = null;
        token op = null;
        if(currentToken.type.equals(token.Type.MULT)){
            op=consumeToken(token.Type.MULT);
            mulExpNode=MulExp();
        }else if(currentToken.type.equals(token.Type.DIV)){
            op=consumeToken(token.Type.DIV);
            mulExpNode=MulExp();
        }else if(currentToken.type.equals(token.Type.MOD)){
            op=consumeToken(token.Type.MOD);
            mulExpNode=MulExp();
        }
        return new MulExpNode(unaryExpNode,mulExpNode,op);
    }

    private UnaryExpNode UnaryExp() {
        //UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
        PrimaryExpNode primaryExpNode;

        token ident;
        token lparent;
        FuncRParamsNode funcRParamsNode = null;
        token rparent;

        UnaryOpNode unaryOpNode;
        UnaryExpNode unaryExpNode;
        if(currentToken.type.equals(token.Type.PLUS)||currentToken.type.equals(token.Type.MINU)||currentToken.type.equals(token.Type.NOT)){
            //UnaryOp UnaryExp
            unaryOpNode=UnaryOp();
            unaryExpNode=UnaryExp();
            return new UnaryExpNode(unaryOpNode,unaryExpNode);
        }
        else if(currentToken.type.equals(token.Type.IDENFR)&&this.tokens.get(i+1).type.equals(token.Type.LPARENT)){
            //Ident '(' [FuncRParams] ')'
            ident=consumeToken(token.Type.IDENFR);
            lparent=consumeToken(token.Type.LPARENT);
            if(isExp()){
                funcRParamsNode=FuncRParams();
            }
            rparent=consumeToken(token.Type.RPARENT);
            return new UnaryExpNode(ident,lparent,funcRParamsNode,rparent);
        }else {
            //PrimaryExp
            primaryExpNode=Primary();
            return new UnaryExpNode(primaryExpNode);
        }
    }

    private FuncRParamsNode FuncRParams() {
        // FuncRParams → Exp { ',' Exp }
        ArrayList<ExpNode> expNodes = new ArrayList<>();
        ArrayList<token> commas = new ArrayList<>();
        expNodes.add(Exp());
        while(currentToken.type.equals(token.Type.COMMA)){
            commas.add(consumeToken(token.Type.COMMA));
            expNodes.add(Exp());
        }
        return new FuncRParamsNode(expNodes,commas);
    }

    private UnaryOpNode UnaryOp() {
        //UnaryOp → '+' | '−' | '!'
        token op;
        if(currentToken.type.equals(token.Type.PLUS)){
            op=consumeToken(token.Type.PLUS);
            return new UnaryOpNode(op);
        }else if(currentToken.type.equals(token.Type.MINU)){
            op=consumeToken(token.Type.MINU);
            return new UnaryOpNode(op);
        }else {
            op=consumeToken(token.Type.NOT);
            return new UnaryOpNode(op);
        }
    }

    private boolean isExp() {
        return  currentToken.type == token.Type.IDENFR ||
                currentToken.type == token.Type.PLUS ||
                currentToken.type == token.Type.MINU ||
                currentToken.type == token.Type.NOT ||
                currentToken.type == token.Type.LPARENT ||
                currentToken.type == token.Type.INTCON||
                currentToken.type == token.Type.CHRCON;
    }
    public token consumeToken(token.Type type){
        //提供所需要的类型消耗匹配，此时currentToken为下一个token，返回消耗的token
        if(currentToken.type.equals(type)){
            token temoToken = currentToken;
            if(i<this.tokens.size()-1){
                i=i+1;
                currentToken=this.tokens.get(i);
            }
            return temoToken;
        }else if(type== token.Type.SEMICN){
            //缺少分号
            errorList.getList().addError(new error(error.wrongType.i,this.tokens.get(i-1).lineno));
            return new token(token.Type.SEMICN,";",this.tokens.get(i-1).lineno);
        }else if(type== token.Type.RPARENT){
            //缺少右括号
            errorList.getList().addError(new error(error.wrongType.j,this.tokens.get(i-1).lineno));
            return new token(token.Type.RPARENT,"）",this.tokens.get(i-1).lineno);
        }else if(type== token.Type.RBRACK){
            //缺少右括号
            errorList.getList().addError(new error(error.wrongType.k,this.tokens.get(i-1).lineno));
            return new token(token.Type.RBRACK,"）",this.tokens.get(i-1).lineno);
        }else {
            throw new RuntimeException("wrong at"+this.tokens.get(i-1).lineno+" "+currentToken);
        }
    }
}
