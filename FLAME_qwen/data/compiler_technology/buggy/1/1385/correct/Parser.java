import node.*;
import token.Errorz;
import token.Token;

import java.util.ArrayList;
import java.util.HashMap;

public class Parser {
    private int index;
    private ArrayList<Token> tokens;
    private int length;
    private ArrayList<Errorz> errors;
    
    public Parser(ArrayList<Token> tokens) {
        index = 0;
        this.tokens = tokens;
        length = tokens.size();
        errors = new ArrayList<>();
    }
    
    public ArrayList<Errorz> getErrors() {
        return errors;
    }
    
    public CompUnitNode CompUnit() {
        ArrayList<DeclNode> declNodes = new ArrayList<>();
        ArrayList<FuncDefNode> funcDefNodes = new ArrayList<>();
        while(tokens.get(index).getType().equals("CONSTTK") || !(tokens.get(index+1).getType().equals("MAINTK") || (tokens.get(index+2).getType().equals("LPARENT")))){
            // 是const或者既不是main也不是func
            declNodes.add(Decl());
        }
        while (!tokens.get(index+1).getType().equals("MAINTK")){
            funcDefNodes.add(FuncDef());
        }
        return new CompUnitNode(declNodes,funcDefNodes, MainFuncDef());
    }
    
    public DeclNode Decl() {
        if (tokens.get(index).getType().equals("CONSTTK")) {
            return new DeclNode(ConstDecl(),null);
        }
        else {
            return new DeclNode(null,VarDecl());
        }
    }
    
    public ConstDeclNode ConstDecl(){
        Token constToken = tokens.get(index);
        index+=1;
        BTypeNode bTypeNode = Btype();
        ArrayList<Token> commas = new ArrayList<>();
        ArrayList<ConstDefNode> constDefNodes = new ArrayList<>();
        constDefNodes.add(ConstDef());
        while(tokens.get(index).getType().equals("COMMA")){
            commas.add(tokens.get(index));
            index+=1;
            constDefNodes.add(ConstDef());
        }
        if (!tokens.get(index).getType().equals("SEMICN")){
            errors.add(new Errorz(tokens.get(index-1).getRowNumber(),"i"));
            Token semicn = new Token(";","SEMICN",tokens.get(index-1).getRowNumber());
            return new ConstDeclNode(constToken,bTypeNode,constDefNodes,commas,semicn);
        }
        else {
            index+=1;
            return new ConstDeclNode(constToken,bTypeNode,constDefNodes,commas,tokens.get(index-1));
        }
    }
    
    public BTypeNode Btype() {
        index+=1;
        return new BTypeNode(tokens.get(index-1));
    }
    
    public ConstDefNode ConstDef() {
        Token ident = tokens.get(index);
        index+=1;
        if (tokens.get(index).getType().equals("LBRACK")){
            Token lbrack = tokens.get(index);
            index +=1;
            ConstExpNode constExpNode = ConstExp();
            Token rbrack = null;
            if (tokens.get(index).getType().equals("RBRACK")){
                rbrack = tokens.get(index);
                index+=1;
            }
            else {
                errors.add(new Errorz(tokens.get(index-1).getRowNumber(),"k"));
                rbrack = new Token("]","RBRACK",tokens.get(index-1).getRowNumber());
            }
            Token equaltoken = tokens.get(index);
            index+=1;
            return new ConstDefNode(ident,lbrack,constExpNode,rbrack,equaltoken,ConstInitVal());
        }
        else {
            Token equaltoken = tokens.get(index);
            index+=1;
            return new ConstDefNode(ident,null,null,null,equaltoken,ConstInitVal());
        }
    }
    
    public ConstInitValNode ConstInitVal() {
        ConstExpNode constExpNode=null;
        Token leftBraceToken = null;
        ArrayList<ConstExpNode> constExpNodes = new ArrayList<>();
        ArrayList<Token> commas = new ArrayList<>();
        Token rightBraceToken = null;
        Token stringConst = null;
        if (tokens.get(index).getType().equals("STRCON")) {
            stringConst = tokens.get(index);
            index++;
        }
        else if (tokens.get(index).getType().equals("LBRACE")){
            leftBraceToken = tokens.get(index);
            index++;
            while (!tokens.get(index).getType().equals("RBRACE")){
                if (tokens.get(index).getType().equals("COMMA")){
                    commas.add(tokens.get(index));
                    index++;
                }
                else {
                    constExpNodes.add(ConstExp());
                }
            }
            rightBraceToken = tokens.get(index);
            index++;
        }
        else {
            constExpNode = ConstExp();
        }
        return new ConstInitValNode(constExpNode,leftBraceToken,constExpNodes,commas,rightBraceToken,stringConst);
    }
    
    public VarDeclNode VarDecl() {
        BTypeNode bTypeNode = Btype();
        ArrayList<VarDefNode> varDefNodes = new ArrayList<>();
        ArrayList<Token> commas = new ArrayList<>();
        varDefNodes.add(VarDef());
        while(tokens.get(index).getType().equals("COMMA")) {
            commas.add(tokens.get(index));
            index++;
            varDefNodes.add(VarDef());
        }
        if (tokens.get(index).getType().equals("SEMICN")){
            Token semicn = tokens.get(index);
            index++;
            return new VarDeclNode(bTypeNode,varDefNodes,commas,semicn);
        }
        else {
            errors.add(new Errorz(tokens.get(index-1).getRowNumber(),"i"));
            Token semicn = new Token(";","SEMICN",tokens.get(index-1).getRowNumber());
            return new VarDeclNode(bTypeNode,varDefNodes,commas,semicn);
        }
    }
    
    public VarDefNode VarDef(){
        Token ident = tokens.get(index);
        index++;
        if (tokens.get(index).getType().equals("LBRACK")) {
            Token leftBracket = tokens.get(index);
            index++;
            ConstExpNode constExpNode = ConstExp();
            Token rightBracket = null;
            if (tokens.get(index).getType().equals("RBRACK")) {
                rightBracket = tokens.get(index);
                index++;
            }
            else {
                errors.add(new Errorz(tokens.get(index-1).getRowNumber(),"k"));
                rightBracket = new Token("]","RBRACK",tokens.get(index-1).getRowNumber());
            }
            if (tokens.get(index).getType().equals("ASSIGN")){
                Token assign = tokens.get(index);
                index++;
                return new VarDefNode(ident,leftBracket,constExpNode,rightBracket,assign,InitVal());
            }
            else {
                return new VarDefNode(ident,leftBracket,constExpNode,rightBracket,null,null);
            }
        }
        else {
            if (tokens.get(index).getType().equals("ASSIGN")){
                Token assign = tokens.get(index);
                index++;
                return new VarDefNode(ident,null,null,null,assign,InitVal());
            }
            else {
                return new VarDefNode(ident,null,null,null,null,null);
            }
        }
        
        
    }
    
    public InitValNode InitVal() {
        ExpNode expNode = null;
        Token leftBraceToken = null;
        ArrayList<ExpNode> expNodes = new ArrayList<>();
        ArrayList<Token> commas = new ArrayList<>();
        Token rightBraceToken = null;
        Token stringConst = null;
        if (tokens.get(index).getType().equals("STRCON")) {
            stringConst = tokens.get(index);
            index++;
        } else if (tokens.get(index).getType().equals("LBRACE")) {
            leftBraceToken = tokens.get(index);
            index++;
            if (tokens.get(index).getType().equals("RBRACE")) {
                rightBraceToken = tokens.get(index);
                index++;
            }
            else {
                expNodes.add(Exp());
                while (tokens.get(index).getType().equals("COMMA")){
                    commas.add(tokens.get(index));
                    index++;
                    expNodes.add(Exp());
                }
                rightBraceToken = tokens.get(index);
                index++;
            }
        }
        else {
            expNode = Exp();
        }
        return new InitValNode(expNode,leftBraceToken,expNodes,commas,rightBraceToken,stringConst);
    }
    
    public FuncDefNode FuncDef() {
        FuncTypeNode funcTypeNode = null;
        Token ident = null;
        Token leftParentToken = null;
        FuncFParamsNode funcFParamsNode = null;
        Token rightParentToken = null;
        BlockNode blockNode = null;
        funcTypeNode = FuncType();
        ident = tokens.get(index);
        index++;
        leftParentToken = tokens.get(index);
        index++;
        if (tokens.get(index).getType().equals("INTTK") || tokens.get(index).getType().equals("CHARTK")) {
            funcFParamsNode = FuncFParams();
        }
        if (tokens.get(index).getType().equals("RPARENT")) {
            rightParentToken = tokens.get(index);
            index++;
        }
        else {
            errors.add(new Errorz(tokens.get(index-1).getRowNumber(),"j"));
            rightParentToken = new Token(")","RPARENT",tokens.get(index-1).getRowNumber());
        }
        blockNode = Block();
        return new FuncDefNode(funcTypeNode,ident,leftParentToken,funcFParamsNode,rightParentToken,blockNode);
    }
    
    public MainFuncDefNode MainFuncDef() {
        Token intToken = null;
        Token mainToken = null;
        Token leftParentToken = null;
        Token rightParentToken = null;
        BlockNode blockNode = null;
        intToken = tokens.get(index);
        index++;
        mainToken = tokens.get(index);
        index++;
        leftParentToken = tokens.get(index);
        index++;
        if (tokens.get(index).getType().equals("RPARENT")) {
            rightParentToken = tokens.get(index);
            index++;
        }
        else {
            errors.add(new Errorz(tokens.get(index-1).getRowNumber(),"j"));
            rightParentToken = new Token(")","RPARENT",tokens.get(index-1).getRowNumber());
        }
        blockNode = Block();
        return new MainFuncDefNode(intToken,mainToken,leftParentToken,rightParentToken,blockNode);
    }
    
    public FuncTypeNode FuncType() {
        index++;
        return new FuncTypeNode(tokens.get(index-1));
    }
    
    public FuncFParamsNode FuncFParams() {
        ArrayList<FuncFParamNode> funcFParamNodes = new ArrayList<>();
        ArrayList<Token> commas = new ArrayList<>();
        funcFParamNodes.add(FuncFParam());
        while (tokens.get(index).getType().equals("COMMA")) {
            commas.add(tokens.get(index));
            index++;
            funcFParamNodes.add(FuncFParam());
        }
        return new FuncFParamsNode(funcFParamNodes,commas);
    }
    
    public FuncFParamNode FuncFParam() {
        //  FuncFParam → BType Ident ['[' ']']
        BTypeNode bTypeNode = null;
        Token ident = null;
        Token leftBracket = null;
        Token rightBracket = null;
        bTypeNode = Btype();
        ident = tokens.get(index);
        index++;
        if (tokens.get(index).getType().equals("LBRACK")) {
            leftBracket = tokens.get(index);
            index++;
            if (tokens.get(index).getType().equals("RBRACK")) {
                rightBracket = tokens.get(index);
                index++;
            }
            else {
                errors.add(new Errorz(tokens.get(index-1).getRowNumber(),"k"));
                rightBracket = new Token("]","RBRACK",tokens.get(index-1).getRowNumber());
            }
        }
        return new FuncFParamNode(bTypeNode,ident,leftBracket,rightBracket);
    }
    
    public BlockNode Block() {
        Token leftBraceToken = null;
        ArrayList<BlockItemNode> blockItemNodes = new ArrayList<>();
        Token rightBraceToken = null;
        leftBraceToken = tokens.get(index);
        index++;
        if (tokens.get(index).getType().equals("RBRACE")) {
            rightBraceToken = tokens.get(index);
            index++;
        }
        else {
            while (!tokens.get(index).getType().equals("RBRACE")) {
                blockItemNodes.add(BlockItem());
            }
            rightBraceToken = tokens.get(index);
            index++;
        }
        return new BlockNode(leftBraceToken,blockItemNodes,rightBraceToken);
    }
    
    public BlockItemNode BlockItem() {
        if (tokens.get(index).getType().equals("CONSTTK") || tokens.get(index).getType().equals("INTTK") || tokens.get(index).getType().equals("CHARTK")) {
            return new BlockItemNode(Decl(),null);
        }
        else {
            return new BlockItemNode(null,Stmt());
        }
    }
    
    public StmtNode Stmt() {
        StmtNode stmtNode = new StmtNode();
        if (tokens.get(index).getType().equals("IDENFR") && !tokens.get(index+1).getType().equals("LPARENT")) {
            int preIndex = index;
            LValNode lValNode = LVal();
            if (tokens.get(index).getType().equals("ASSIGN")) {
                stmtNode.setlValNode(lValNode);
                stmtNode.setAssignToken(tokens.get(index));
                index++;
                if (tokens.get(index).getType().equals("GETINTTK")){
                    stmtNode.setGetintToken(tokens.get(index));
                    index++;
                    stmtNode.setLeftParentToken(tokens.get(index));
                    index++;
                    if (tokens.get(index).getType().equals("RPARENT")){
                        stmtNode.setRightParentToken(tokens.get(index));
                        index++;
                    }
                    else {
                        errors.add(new Errorz(tokens.get(index-1).getRowNumber(),"j"));
                        Token rightParentToken = new Token(")","RPARENT",tokens.get(index-1).getRowNumber());
                        stmtNode.setRightParentToken(rightParentToken);
                    }
                    if (tokens.get(index).getType().equals("SEMICN")){
                        stmtNode.setSemicnToken(tokens.get(index));
                        index++;
                    }
                    else {
                        errors.add(new Errorz(tokens.get(index-1).getRowNumber(),"i"));
                        Token semicn = new Token(";","SEMICN",tokens.get(index-1).getRowNumber());
                        stmtNode.setSemicnToken(semicn);
                    }
                    stmtNode.setType(StmtNode.StmtType.GetInt);
                }
                else if(tokens.get(index).getType().equals("GETCHARTK")){
                    stmtNode.setGetcharToken(tokens.get(index));
                    index++;
                    stmtNode.setLeftParentToken(tokens.get(index));
                    index++;
                    if (tokens.get(index).getType().equals("RPARENT")){
                        stmtNode.setRightParentToken(tokens.get(index));
                        index++;
                    }
                    else {
                        errors.add(new Errorz(tokens.get(index-1).getRowNumber(),"j"));
                        Token rightParentToken = new Token(")","RPARENT",tokens.get(index-1).getRowNumber());
                        stmtNode.setRightParentToken(rightParentToken);
                    }
                    if (tokens.get(index).getType().equals("SEMICN")){
                        stmtNode.setSemicnToken(tokens.get(index));
                        index++;
                    }
                    else {
                        errors.add(new Errorz(tokens.get(index-1).getRowNumber(),"i"));
                        Token semicn = new Token(";","SEMICN",tokens.get(index-1).getRowNumber());
                        stmtNode.setSemicnToken(semicn);
                    }
                    stmtNode.setType(StmtNode.StmtType.GetChar);
                }
                else {
                    stmtNode.setExpNode(Exp());
                    if (tokens.get(index).getType().equals("SEMICN")){
                        stmtNode.setSemicnToken(tokens.get(index));
                        index++;
                    }
                    else {
                        errors.add(new Errorz(tokens.get(index-1).getRowNumber(),"i"));
                        Token semicn = new Token(";","SEMICN",tokens.get(index-1).getRowNumber());
                        stmtNode.setSemicnToken(semicn);
                    }
                    stmtNode.setType(StmtNode.StmtType.LValExp);
                }
            }
            else {
                index = preIndex;
                stmtNode.setExpNode(Exp());
                if (tokens.get(index).getType().equals("SEMICN")){
                    stmtNode.setSemicnToken(tokens.get(index));
                    index++;
                }
                else {
                    errors.add(new Errorz(tokens.get(index-1).getRowNumber(),"i"));
                    Token semicn = new Token(";","SEMICN",tokens.get(index-1).getRowNumber());
                    stmtNode.setSemicnToken(semicn);
                }
                stmtNode.setType(StmtNode.StmtType.Exp);
            }
        }
        else if (tokens.get(index).getType().equals("LBRACE")){
            stmtNode.setBlockNode(Block());
            stmtNode.setType(StmtNode.StmtType.Block);
        }
        else if (tokens.get(index).getType().equals("IFTK")) {
            stmtNode.setIfToken(tokens.get(index));
            index++;
            stmtNode.setLeftParentToken(tokens.get(index));
            index++;
            stmtNode.setCondNode(Cond());
            if (tokens.get(index).getType().equals("RPARENT")) {
                stmtNode.setRightParentToken(tokens.get(index));
                index++;
            }
            else {
                errors.add(new Errorz(tokens.get(index-1).getRowNumber(),"j"));
                Token rightParentToken = new Token(")","RPARENT",tokens.get(index-1).getRowNumber());
                stmtNode.setRightParentToken(rightParentToken);
            }
            stmtNode.setIfStmtNode(Stmt());
            if(tokens.get(index).getType().equals("ELSETK")) {
                stmtNode.setElseToken(tokens.get(index));
                index++;
                stmtNode.setElseStmtNode(Stmt());
            }
            stmtNode.setType(StmtNode.StmtType.If);
        }
        else if (tokens.get(index).getType().equals("FORTK")) {
            stmtNode.setForToken(tokens.get(index));
            index++;
            stmtNode.setLeftParentToken(tokens.get(index));
            index++;
            if (!tokens.get(index).getType().equals("SEMICN")) {
                stmtNode.setForStmtNode1(ForStmt());
            }
            stmtNode.setSemicnToken1(tokens.get(index));
            index++;
            if (!tokens.get(index).getType().equals("SEMICN")) {
                stmtNode.setCondNode(Cond());
            }
            stmtNode.setSemicnToken2(tokens.get(index));
            index++;
            if (!tokens.get(index).getType().equals("RPARENT")){
                stmtNode.setForStmtNode2(ForStmt());
            }
            stmtNode.setRightParentToken(tokens.get(index));
            index++;
            stmtNode.setStmtNode(Stmt());
            stmtNode.setType(StmtNode.StmtType.For);
        }
        else if (tokens.get(index).getType().equals("BREAKTK")) {
            stmtNode.setBreakToken(tokens.get(index));
            index++;
            if (tokens.get(index).getType().equals("SEMICN")) {
                stmtNode.setSemicnToken(tokens.get(index));
                index++;
            }
            else {
                errors.add(new Errorz(tokens.get(index-1).getRowNumber(),"i"));
                Token semicn = new Token(";","SEMICN",tokens.get(index-1).getRowNumber());
                stmtNode.setSemicnToken(semicn);
            }
            stmtNode.setType(StmtNode.StmtType.Break);
        }
        else if (tokens.get(index).getType().equals("CONTINUETK")) {
            stmtNode.setContinueToken(tokens.get(index));
            index++;
            if (tokens.get(index).getType().equals("SEMICN")) {
                stmtNode.setSemicnToken(tokens.get(index));
                index++;
            }
            else {
                errors.add(new Errorz(tokens.get(index-1).getRowNumber(),"i"));
                Token semicn = new Token(";","SEMICN",tokens.get(index-1).getRowNumber());
                stmtNode.setSemicnToken(semicn);
            }
            stmtNode.setType(StmtNode.StmtType.Continue);
        }
        else if (tokens.get(index).getType().equals("RETURNTK")) {
            stmtNode.setReturnToken(tokens.get(index));
            index++;
            if (tokens.get(index).getType().equals("LPARENT") || tokens.get(index).getType().equals("IDENFR") || tokens.get(index).getType().equals("INTCON") || tokens.get(index).getType().equals("CHRCON")
            || tokens.get(index).getType().equals("PLUS") || tokens.get(index).getType().equals("MINU")|| tokens.get(index).getType().equals("NOT")) {
                stmtNode.setExpNode(Exp());
            }
            if (tokens.get(index).getType().equals("SEMICN")) {
                stmtNode.setSemicnToken(tokens.get(index));
                index++;
            }
            else {
                errors.add(new Errorz(tokens.get(index-1).getRowNumber(),"i"));
                Token semicn = new Token(";","SEMICN",tokens.get(index-1).getRowNumber());
                stmtNode.setSemicnToken(semicn);
            }
            stmtNode.setType(StmtNode.StmtType.Return);
        }
        else if (tokens.get(index).getType().equals("PRINTFTK")) {
            stmtNode.setPrintfToken(tokens.get(index));
            index++;
            stmtNode.setLeftParentToken(tokens.get(index));
            index++;
            stmtNode.setStringConst(tokens.get(index));
            index++;
            ArrayList<Token> commas = new ArrayList<>();
            ArrayList<ExpNode> expNodes = new ArrayList<>();
            while (tokens.get(index).getType().equals("COMMA")) {
                commas.add(tokens.get(index));
                index++;
                expNodes.add(Exp());
            }
            stmtNode.setCommas(commas);
            stmtNode.setExpNodes(expNodes);
            if (tokens.get(index).getType().equals("RPARENT")) {
                stmtNode.setRightParentToken(tokens.get(index));
                index++;
            }
            else {
                errors.add(new Errorz(tokens.get(index-1).getRowNumber(),"j"));
                Token rightParentToken = new Token(")","RPARENT",tokens.get(index-1).getRowNumber());
                stmtNode.setRightParentToken(rightParentToken);
            }
            if (tokens.get(index).getType().equals("SEMICN")) {
                stmtNode.setSemicnToken(tokens.get(index));
                index++;
            }
            else {
                errors.add(new Errorz(tokens.get(index-1).getRowNumber(),"i"));
                Token semicn = new Token(";","SEMICN",tokens.get(index-1).getRowNumber());
                stmtNode.setSemicnToken(semicn);
            }
            stmtNode.setType(StmtNode.StmtType.Printf);
        }
        else {
            if (tokens.get(index).getType().equals("LPARENT") || tokens.get(index).getType().equals("IDENFR") || tokens.get(index).getType().equals("INTCON") || tokens.get(index).getType().equals("CHRCON")
                    || tokens.get(index).getType().equals("PLUS") || tokens.get(index).getType().equals("MINU")|| tokens.get(index).getType().equals("NOT")) {
                stmtNode.setExpNode(Exp());
            }
            if (tokens.get(index).getType().equals("SEMICN")) {
                stmtNode.setSemicnToken(tokens.get(index));
                index++;
            }
            else {
                errors.add(new Errorz(tokens.get(index-1).getRowNumber(),"i"));
                Token semicn = new Token(";","SEMICN",tokens.get(index-1).getRowNumber());
                stmtNode.setSemicnToken(semicn);
            }
            stmtNode.setType(StmtNode.StmtType.Exp);
        }
        return stmtNode;
    }
    
    public ForStmtNode ForStmt() {
        LValNode lValNode = LVal();
        Token assign = tokens.get(index);
        index++;
        return new ForStmtNode(lValNode,assign,Exp());
    }
    
    public ExpNode Exp() {
        return new ExpNode(AddExp());
    }
    
    public CondNode Cond() {
        return new CondNode(LOrExp());
    }
    
    public LValNode LVal() {
        Token ident = tokens.get(index);
        index++;
        if (tokens.get(index).getType().equals("LBRACK")){
            Token lbrack = tokens.get(index);
            index++;
            ExpNode expNode = Exp();
            if (tokens.get(index).getType().equals("RBRACK")) {
                index++;
                return new LValNode(ident,lbrack,expNode,tokens.get(index-1));
            }
            else {
                errors.add(new Errorz(tokens.get(index-1).getRowNumber(),"k"));
                return new LValNode(ident,lbrack,expNode,new Token("]","RBRACK",tokens.get(index-1).getRowNumber()));
            }
        }
        else {
            return new LValNode(ident,null,null,null);
        }
    }
    
    public PrimaryExpNode PrimaryExp() {
        if (tokens.get(index).getType().equals("LPARENT")){
            Token lparent = tokens.get(index);
            index++;
            ExpNode expNode = Exp();
            if (tokens.get(index).getType().equals("RPARENT")) {
                index++;
                return new PrimaryExpNode(lparent,expNode,tokens.get(index-1));
            }
            else {
                errors.add(new Errorz(tokens.get(index-1).getRowNumber(),"j"));
                Token rightParentToken = new Token(")","RPARENT",tokens.get(index-1).getRowNumber());
                return new PrimaryExpNode(lparent,expNode,rightParentToken);
            }
        }
        else if (tokens.get(index).getType().equals("INTCON")) {
            return new PrimaryExpNode(Number());
        }
        else if (tokens.get(index).getType().equals("CHRCON")) {
            return new PrimaryExpNode(Character());
        }
        else {
            return new PrimaryExpNode(LVal());
        }
    }
    
    public NumberNode Number() {
        index++;
        return new NumberNode(tokens.get(index-1));
    }
    
    public CharacterNode Character() {
        index++;
        return new CharacterNode(tokens.get(index-1));
    }
    
    public UnaryExpNode UnaryExp() {
        if (tokens.get(index).getType().equals("IDENFR") && tokens.get(index+1).getType().equals("LPARENT")){
            Token ident = tokens.get(index);
            index++;
            Token lparent = tokens.get(index);
            index++;
            FuncRParamsNode funcRParamsNode = null;
            if (tokens.get(index).getType().equals("LPARENT") || tokens.get(index).getType().equals("IDENFR") || tokens.get(index).getType().equals("INTCON") || tokens.get(index).getType().equals("CHRCON")
                    || tokens.get(index).getType().equals("PLUS") || tokens.get(index).getType().equals("MINU")|| tokens.get(index).getType().equals("NOT")) {
                funcRParamsNode = FuncRParams();
            }
            if (tokens.get(index).getType().equals("RPARENT")) {
                index++;
                return new UnaryExpNode(ident,lparent,funcRParamsNode,tokens.get(index-1));
            }
            else {
                errors.add(new Errorz(tokens.get(index-1).getRowNumber(),"j"));
                Token rightParentToken = new Token(")","RPARENT",tokens.get(index-1).getRowNumber());
                return new UnaryExpNode(ident,lparent,funcRParamsNode,rightParentToken);
            }
        }
        else if (tokens.get(index).getType().equals("PLUS") || tokens.get(index).getType().equals("MINU")|| tokens.get(index).getType().equals("NOT")) {
            UnaryOpNode unaryOpNode = UnaryOp();
            return new UnaryExpNode(unaryOpNode,UnaryExp());
        }
        else {
            return new UnaryExpNode(PrimaryExp());
        }
    }
    
    public UnaryOpNode UnaryOp() {
        index++;
        return new UnaryOpNode(tokens.get(index-1));
    }
    
    public FuncRParamsNode FuncRParams() {
        ArrayList<ExpNode> expNodes = new ArrayList<>();
        ArrayList<Token> commas = new ArrayList<>();
        expNodes.add(Exp());
        while (tokens.get(index).getType().equals("COMMA")) {
            commas.add(tokens.get(index));
            index++;
            expNodes.add(Exp());
        }
        return new FuncRParamsNode(expNodes,commas);
    }
    
    public MulExpNode MulExp() {
        ArrayList<UnaryExpNode> unaryExpNodes = new ArrayList<>();
        ArrayList<Token> operators = new ArrayList<>();
        unaryExpNodes.add(UnaryExp());
        while (tokens.get(index).getType().equals("MULT") || tokens.get(index).getType().equals("DIV")|| tokens.get(index).getType().equals("MOD")) {
            operators.add(tokens.get(index));
            index++;
            unaryExpNodes.add(UnaryExp());
        }
        return new MulExpNode(unaryExpNodes,operators);
    }
    
    public AddExpNode AddExp() {
        ArrayList<MulExpNode> mulExpNodes = new ArrayList<>();
        ArrayList<Token> operators = new ArrayList<>();
        mulExpNodes.add(MulExp());
        while (tokens.get(index).getType().equals("PLUS") || tokens.get(index).getType().equals("MINU")) {
            operators.add(tokens.get(index));
            index++;
            mulExpNodes.add(MulExp());
        }
        return new AddExpNode(mulExpNodes,operators);
    }
    
    public RelExpNode RelExp() {
        ArrayList<AddExpNode> addExpNodes = new ArrayList<>();
        ArrayList<Token> operators = new ArrayList<>();
        addExpNodes.add(AddExp());
        while (tokens.get(index).getType().equals("LSS") || tokens.get(index).getType().equals("LEQ")|| tokens.get(index).getType().equals("GRE")|| tokens.get(index).getType().equals("GEQ")) {
            operators.add(tokens.get(index));
            index++;
            addExpNodes.add(AddExp());
        }
        return new RelExpNode(addExpNodes,operators);
    }
    
    public EqExpNode EqExp() {
        ArrayList<RelExpNode> relExpNodes = new ArrayList<>();
        ArrayList<Token> operators = new ArrayList<>();
        relExpNodes.add(RelExp());
        while (tokens.get(index).getType().equals("EQL") || tokens.get(index).getType().equals("NEQ")) {
            operators.add(tokens.get(index));
            index++;
            relExpNodes.add(RelExp());
        }
        return new EqExpNode(relExpNodes,operators);
    }
    
    public LAndExpNode LAndExp() {
        ArrayList<EqExpNode> eqExpNodes = new ArrayList<>();
        ArrayList<Token> andTokens = new ArrayList<>();
        eqExpNodes.add(EqExp());
        while (tokens.get(index).getType().equals("AND")) {
            andTokens.add(tokens.get(index));
            index++;
            eqExpNodes.add(EqExp());
        }
        return new LAndExpNode(eqExpNodes,andTokens);
    }
    
    public LOrExpNode LOrExp() {
        ArrayList<LAndExpNode> lAndExpNodes = new ArrayList<>();
        ArrayList<Token> orTokens = new ArrayList<>();
        lAndExpNodes.add(LAndExp());
        while (tokens.get(index).getType().equals("OR")) {
            orTokens.add(tokens.get(index));
            index++;
            lAndExpNodes.add(LAndExp());
        }
        return new LOrExpNode(lAndExpNodes,orTokens);
    }
    
    public ConstExpNode ConstExp() {
        return new ConstExpNode(AddExp());
    }
}
