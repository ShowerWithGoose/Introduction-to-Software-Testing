package frontend.Parser;

import frontend.Token.Token;
import frontend.Token.TokenType;
import frontend.Wrong;

import java.io.*;
import java.security.KeyStore;
import java.util.ArrayList;


public class Parser {
    public ArrayList<Token> tokens; //所有单词
    public Token currentToken;
    public int index; //第几个tokens
    public int total;//tokens个数
    public Component compUnit;

    private ArrayList<Wrong> wrongs;

    static class IntWrapper {//用于处理歧义的结构体
        public int value;//存储选项的开头

        public IntWrapper(int value) {
            this.value = value;
        }
    }

    public Parser(ArrayList<Token> tokens, ArrayList<Wrong> wrongs){
        this.tokens=tokens;
        this.index=0;
        this.total=tokens.size();
        this.currentToken=tokens.get(0);
        this.wrongs=wrongs;
        this.compUnit=parse_CompUnit();
        try {
            print();
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
    }
    public void addWrong(String type,int line){
        Wrong wrong =new Wrong(type,line);
        wrongs.add(wrong);
    }


    public void next_Token(){
        index++;
        if(index<total){
            currentToken = this.tokens.get(index);
        }else{
            currentToken = null;
        }
    }
    public Component match(TokenType type,ArrayList<Component> components){ //匹配token
        if((currentToken!=null)&&(currentToken.type==type)){
            Component tokenComponent = currentToken;
            next_Token();
            components.add(tokenComponent);
            return tokenComponent;
        }
        return null;
    }
    public boolean matchC(Component component,ArrayList<Component> components){
        if(component==null)
            return false;
        else{
            components.add(component);
            return true;
        }
    }

    public void jump(IntWrapper start){//在多条规则情况下，若不符合一个，jump到start
        index=start.value;
        currentToken=tokens.get(index);
    }


    public void postOrderTraversal(Component component,PrintWriter writer) {
        if (component == null) {
            return;
        }
        // 遍历所有子组件
        if(component.components!=null) {
            for (Component child : component.components) {
                postOrderTraversal(child, writer);
            }
        }
        if(component.componentType==ComponentType.Leaf){
            Token token=(Token)component;
            writer.println(token.type.toString()+" "+token.content);
        }else{
            if((component.componentType!=ComponentType.BType) && (component.componentType!=ComponentType.Decl) && (component.componentType!=ComponentType.BlockItem))
            writer.println("<"+component.componentType+">");
        }
    }

    public void print() throws FileNotFoundException {
        OutputStream out = new BufferedOutputStream(new FileOutputStream("parser.txt"));
        PrintWriter writer = new PrintWriter(out);
        Component root=new Component();
        root=this.compUnit;
        postOrderTraversal(root,writer);
        writer.flush();
        writer.close();
    }


    public Component parse_CompUnit(){
        ArrayList<Component> components=new ArrayList<Component>();
        IntWrapper start= new IntWrapper(index);
        while(matchC(parse_Decl(),components)==true);
        while(matchC(parse_FuncDef(),components)==true);
        if(matchC(parse_MainFuncDef(),components)==false){
            jump(start);
            return null;
        }
        Component compUnit=new Component(ComponentType.CompUnit,components);
        return compUnit;
    }

    public Component parse_Decl(){
        ArrayList<Component> components=new ArrayList<Component>();
        IntWrapper start= new IntWrapper(index);
        if(matchC(parse_ConstDecl(),components)==false) {
            if(matchC(parse_VarDecl(),components)==false){
                jump(start);
                return null;
            }
        }
        Component decl=new Component(ComponentType.Decl,components);
        return decl;
    }
    public Component parse_ConstDecl(){
        ArrayList<Component> components=new ArrayList<Component>();
        IntWrapper start= new IntWrapper(index);
        if(match(TokenType.CONSTTK,components)==null){
            jump(start);
            return null;
        }
        if(matchC(parse_BType(),components)==false){
            jump(start);
            return null;
        }
        if(matchC(parse_ConstDef(),components)==false){
            jump(start);
            return null;
        }
        while(match(TokenType.COMMA,components)!=null){
            if(matchC(parse_ConstDef(),components)==false){
                jump(start);
                return null;
            }
        }
        if(match(TokenType.SEMICN,components)==null){
            addWrong("i",tokens.get(index-1).lineno);
        }
        Component constDecl=new Component(ComponentType.ConstDecl,components);
        return constDecl;
    }

    public Component parse_BType(){
        ArrayList<Component> components=new ArrayList<Component>();
        Component component;
        IntWrapper start= new IntWrapper(index);
        if(match(TokenType.INTTK,components)==null){
            if(match(TokenType.CHARTK,components)==null){
                jump(start);
                return null;
            }
        }
        Component bType=new Component(ComponentType.BType,components);
        return bType;
    }
    public Component parse_ConstDef(){
        ArrayList<Component> components=new ArrayList<Component>();
        IntWrapper start= new IntWrapper(index);
        if(match(TokenType.IDENFR,components)==null){
            jump(start);
            return null;
        }
        if(match(TokenType.LBRACK,components)!=null){
            if(matchC(parse_ConstExp(),components)==false){
                jump(start);
                return null;
            }
            if(match(TokenType.RBRACK,components)==null){
                addWrong("k",tokens.get(index-1).lineno);
            }
        }
        if(match(TokenType.ASSIGN,components)==null){
            jump(start);
            return null;
        }
        if(matchC(parse_ConstInitVal(),components)==false){
            jump(start);
            return null;
        }
        Component constDef=new Component(ComponentType.ConstDef,components);
        return constDef;
    }
    public Component parse_ConstInitVal(){
        ArrayList<Component> components=new ArrayList<Component>();
        IntWrapper start= new IntWrapper(index);
        if(matchC(parse_ConstExp(),components)==false){
            if(match(TokenType.LBRACE,components)==null){
                if(match(TokenType.STRCON,components)==null){
                    jump(start);
                    return null;
                }
            }else{
                if(matchC(parse_ConstExp(),components)==true){
                    while(match(TokenType.COMMA,components)!=null){
                        if(matchC(parse_ConstExp(),components)==false){
                            jump(start);
                            return null;
                        }
                    }
                }
                if(match(TokenType.RBRACE,components)==null){
                    jump(start);
                    return null;
                }
            }
        }
        Component constInitVal=new Component(ComponentType.ConstInitVal,components);
        return constInitVal;
    }
    public Component parse_VarDecl(){
        ArrayList<Component> components=new ArrayList<Component>();
        Component component;
        IntWrapper start= new IntWrapper(index);
        if(matchC(parse_BType(),components)==false){
            jump(start);
            return null;
        }
        if(matchC(parse_VarDef(),components)==false){
            jump(start);
            return null;
        }
        while(match(TokenType.COMMA,components)!=null){
            if(matchC(parse_VarDef(),components)==false){
                jump(start);
                return null;
            }
        }
        if(match(TokenType.SEMICN,components)==null){
            if(currentToken.type==TokenType.LPARENT)
                return null;
            addWrong("i",tokens.get(index-1).lineno);
        }
        Component varDecl=new Component(ComponentType.VarDecl,components);
        return varDecl;
    }
    public Component parse_VarDef(){
        ArrayList<Component> components=new ArrayList<Component>();
        IntWrapper start= new IntWrapper(index);
        if(match(TokenType.IDENFR,components)==null){
            jump(start);
            return null;
        }
        if(match(TokenType.LBRACK,components)!=null){
            if(matchC(parse_ConstExp(),components)==false){
                jump(start);
                return null;
            }
            if(match(TokenType.RBRACK,components)==null){
                addWrong("k",tokens.get(index-1).lineno);
            }
        }
        if(match(TokenType.ASSIGN,components)!=null){
            if(matchC(parse_InitVal(),components)==false){
                jump(start);
                return null;
            }
        }
        Component varDef=new Component(ComponentType.VarDef,components);
        return varDef;
    }
    public Component parse_InitVal(){
        ArrayList<Component> components=new ArrayList<Component>();
        IntWrapper start= new IntWrapper(index);
        if(matchC(parse_Exp(),components)==false){
            if(match(TokenType.LBRACE,components)==null){
                if(match(TokenType.STRCON,components)==null){
                    jump(start);
                    return null;
                }
            }else{
                if(matchC(parse_Exp(),components)==true){
                    while(match(TokenType.COMMA,components)!=null){
                        if(matchC(parse_Exp(),components)==false){
                            jump(start);
                            return null;
                        }
                    }
                }
                if(match(TokenType.RBRACE,components)==null){
                    jump(start);
                    return null;
                }
            }
        }
        Component initVal=new Component(ComponentType.InitVal,components);
        return initVal;
    }
    public Component parse_FuncDef(){
        ArrayList<Component> components=new ArrayList<Component>();
        IntWrapper start= new IntWrapper(index);
        if(matchC(parse_FuncType(),components)==false){
            jump(start);
            return null;
        }
        if(match(TokenType.IDENFR,components)==null){
            jump(start);
            return null;
        }
        if(match(TokenType.LPARENT,components)==null){
            jump(start);
            return null;
        }
        matchC(parse_FuncFParams(),components);
        if(match(TokenType.RPARENT,components)==null){
            addWrong("j",tokens.get(index-1).lineno);
        }
        if(matchC(parse_Block(),components)==false){
            jump(start);
            return null;
        }
        Component funcDef=new Component(ComponentType.FuncDef,components);
        return funcDef;
    }
    public Component parse_MainFuncDef(){
        ArrayList<Component> components=new ArrayList<Component>();
        IntWrapper start= new IntWrapper(index);
        if(match(TokenType.INTTK,components)==null){
            jump(start);
            return null;
        }
        if(match(TokenType.MAINTK,components)==null){
            jump(start);
            return null;
        }
        if(match(TokenType.LPARENT,components)==null){
            jump(start);
            return null;
        }
        if(match(TokenType.RPARENT,components)==null){
            addWrong("j",tokens.get(index-1).lineno);
        }
        if(matchC(parse_Block(),components)==false){
            jump(start);
            return null;
        }
        Component mainFuncDef=new Component(ComponentType.MainFuncDef,components);
        return mainFuncDef;
    }
    public Component parse_FuncType(){
        ArrayList<Component> components=new ArrayList<Component>();
        IntWrapper start= new IntWrapper(index);
        if(match(TokenType.VOIDTK,components)==null){
            if(match(TokenType.INTTK,components)==null){
                if(match(TokenType.CHARTK,components)==null){
                    jump(start);
                    return null;
                }
            }
        }
        Component funcType=new Component(ComponentType.FuncType,components);
        return funcType;
    }
    public Component parse_FuncFParams(){
        ArrayList<Component> components=new ArrayList<Component>();
        IntWrapper start= new IntWrapper(index);
        if(matchC(parse_FuncFParam(),components)==false){
            jump(start);
            return null;
        }
        while(match(TokenType.COMMA,components)!=null){
            if(matchC(parse_FuncFParam(),components)==false){
                jump(start);
                return null;
            }
        }
        Component funcFParams=new Component(ComponentType.FuncFParams,components);
        return funcFParams;
    }
    public Component parse_FuncFParam(){
        ArrayList<Component> components=new ArrayList<Component>();
        IntWrapper start= new IntWrapper(index);
        if(matchC(parse_BType(),components)==false){
            jump(start);
            return null;
        }
        if(match(TokenType.IDENFR,components)==null){
            jump(start);
            return null;
        }
        if(match(TokenType.LBRACK,components)!=null){
            if(match(TokenType.RBRACK,components)==null){
                addWrong("k",tokens.get(index-1).lineno);
            }
        }
        Component funcFParam=new Component(ComponentType.FuncFParam,components);
        return funcFParam;
    }
    public Component parse_Block(){
        ArrayList<Component> components=new ArrayList<Component>();
        IntWrapper start= new IntWrapper(index);
        if(match(TokenType.LBRACE,components)==null){
            jump(start);
            return null;
        }
        while(matchC(parse_BlockItem(),components)==true);
        if(match(TokenType.RBRACE,components)==null){
            jump(start);
            return null;
        }
        Component block=new Component(ComponentType.Block,components);
        return block;
    }
    public Component parse_BlockItem(){
        ArrayList<Component> components=new ArrayList<Component>();
        IntWrapper start= new IntWrapper(index);
        if(matchC(parse_Decl(),components)==false){
            if(matchC(parse_Stmt(),components)==false){
                jump(start);
                return null;
            }
        }
        Component blockItem=new Component(ComponentType.BlockItem,components);
        return blockItem;
    }
    public Component parse_Stmt(){
        ArrayList<Component> components=new ArrayList<Component>();
        IntWrapper start= new IntWrapper(index);
        //第一种
        if(matchC(parse_LVal(),components)==true) {
            if (match(TokenType.ASSIGN, components)!=null) {
                if (matchC(parse_Exp(), components)==true) {
                    if (match(TokenType.SEMICN, components)!=null) {
                        Component Stmt=new Component(ComponentType.Stmt,components);
                        return Stmt;
                    }else{
                        addWrong("i",tokens.get(index-1).lineno);
                        Component Stmt=new Component(ComponentType.Stmt,components);
                        return Stmt;
                    }
                }
            }
        }
        //第二种
        components.clear();
        jump(start);
        boolean t;
        t=matchC(parse_Exp(),components);
        if (match(TokenType.SEMICN, components)!=null) {
            Component Stmt=new Component(ComponentType.Stmt,components);
            return Stmt;
        }else{
            if((t==true)&&(currentToken.type!=TokenType.ASSIGN)){
                addWrong("i",tokens.get(index-1).lineno);
                Component Stmt=new Component(ComponentType.Stmt,components);
                return Stmt;
            }
        }
        //第三种
        components.clear();
        jump(start);
        if(matchC(parse_Block(),components)==true){
            Component Stmt=new Component(ComponentType.Stmt,components);
            return Stmt;
        }
        //4
        components.clear();
        jump(start);
        if(match(TokenType.IFTK, components)!=null){
            if(match(TokenType.LPARENT, components)!=null){
                if(matchC(parse_Cond(),components)==true){
                    if(match(TokenType.RPARENT, components)!=null){
                        if(matchC(parse_Stmt(),components)==true){
                            if((match(TokenType.ELSETK, components)!=null) && (matchC(parse_Stmt(),components)==false)){
                                components.clear();
                                jump(start);
                            }else{
                                Component Stmt=new Component(ComponentType.Stmt,components);
                                return Stmt;
                            }
                        }
                    }else{
                        addWrong("j",tokens.get(index-1).lineno);
                        Component Stmt=new Component(ComponentType.Stmt,components);
                        return Stmt;
                    }
                }
            }
        }
        //5
        components.clear();
        jump(start);
        if(match(TokenType.FORTK, components)!=null){
            if(match(TokenType.LPARENT, components)!=null){
                matchC(parse_ForStmt(),components);
                if(match(TokenType.SEMICN, components)!=null){
                    matchC(parse_Cond(),components);
                    if(match(TokenType.SEMICN, components)!=null){
                        matchC(parse_ForStmt(),components);
                        if(match(TokenType.RPARENT, components)!=null){
                            if(matchC(parse_Stmt(),components)==true){
                                Component Stmt=new Component(ComponentType.Stmt,components);
                                return Stmt;
                            }
                        }else{
                            addWrong("j",tokens.get(index-1).lineno);
                            Component Stmt=new Component(ComponentType.Stmt,components);
                            return Stmt;
                        }
                    }
                }
            }
        }
        components.clear();
        jump(start);
        if(match(TokenType.BREAKTK, components)!=null){
            if(match(TokenType.SEMICN, components)!=null){
                Component Stmt=new Component(ComponentType.Stmt,components);
                return Stmt;
            }else{
                addWrong("i",tokens.get(index-1).lineno);
                Component Stmt=new Component(ComponentType.Stmt,components);
                return Stmt;
            }
        }
        components.clear();
        jump(start);
        if(match(TokenType.CONTINUETK, components)!=null){
            if(match(TokenType.SEMICN, components)!=null){
                Component Stmt=new Component(ComponentType.Stmt,components);
                return Stmt;
            }else{
                addWrong("i",tokens.get(index-1).lineno);
                Component Stmt=new Component(ComponentType.Stmt,components);
                return Stmt;
            }
        }
        components.clear();
        jump(start);
        if(match(TokenType.RETURNTK, components)!=null){
            matchC(parse_Exp(),components);
            if(match(TokenType.SEMICN, components)!=null){
                Component Stmt=new Component(ComponentType.Stmt,components);
                return Stmt;
            }else{
                addWrong("i",tokens.get(index-1).lineno);
                Component Stmt=new Component(ComponentType.Stmt,components);
                return Stmt;
            }
        }
        components.clear();
        jump(start);
        if(matchC(parse_LVal(),components)==true){
            if(match(TokenType.ASSIGN, components)!=null){
                if(match(TokenType.GETINTTK, components)!=null){
                    if(match(TokenType.LPARENT, components)!=null){
                        if(match(TokenType.RPARENT, components)!=null){
                            if(match(TokenType.SEMICN, components)!=null){
                                Component Stmt=new Component(ComponentType.Stmt,components);
                                return Stmt;
                            }else{
                                addWrong("i",tokens.get(index-1).lineno);
                                Component Stmt=new Component(ComponentType.Stmt,components);
                                return Stmt;
                            }
                        }else{
                            addWrong("j",tokens.get(index-1).lineno);
                            Component Stmt=new Component(ComponentType.Stmt,components);
                            return Stmt;
                        }
                    }
                }
            }
        }
        components.clear();
        jump(start);
        if(matchC(parse_LVal(),components)==true){
            if(match(TokenType.ASSIGN, components)!=null){
                if(match(TokenType.GETCHARTK, components)!=null){
                    if(match(TokenType.LPARENT, components)!=null){
                        if(match(TokenType.RPARENT, components)!=null){
                            if(match(TokenType.SEMICN, components)!=null){
                                Component Stmt=new Component(ComponentType.Stmt,components);
                                return Stmt;
                            }else{
                                addWrong("i",tokens.get(index-1).lineno);
                                Component Stmt=new Component(ComponentType.Stmt,components);
                                return Stmt;
                            }
                        }else{
                            addWrong("j",tokens.get(index-1).lineno);
                            Component Stmt=new Component(ComponentType.Stmt,components);
                            return Stmt;
                        }
                    }
                }
            }
        }
        components.clear();
        jump(start);
        if(match(TokenType.PRINTFTK, components)!=null){
            if(match(TokenType.LPARENT, components)!=null){
                if(match(TokenType.STRCON, components)!=null){
                    while(match(TokenType.COMMA, components)!=null){
                        if(matchC(parse_Exp(),components)==false){
                            jump(start);
                            return null;
                        }
                    }
                    if(match(TokenType.RPARENT, components)!=null){
                        if(match(TokenType.SEMICN, components)!=null){
                            Component Stmt=new Component(ComponentType.Stmt,components);
                            return Stmt;
                        }else{
                            addWrong("i",tokens.get(index-1).lineno);
                            Component Stmt=new Component(ComponentType.Stmt,components);
                            return Stmt;
                        }
                    }else{
                        addWrong("j",tokens.get(index-1).lineno);
                        Component Stmt=new Component(ComponentType.Stmt,components);
                        return Stmt;
                    }
                }
            }
        }
        jump(start);
        return null;
    }
    public Component parse_ForStmt(){
        ArrayList<Component> components=new ArrayList<Component>();
        IntWrapper start= new IntWrapper(index);
        if(matchC(parse_LVal(),components)==false){
            jump(start);
            return null;
        }
        if(match(TokenType.ASSIGN,components)==null){
            jump(start);
            return null;
        }
        if(matchC(parse_Exp(),components)==false){
            jump(start);
            return null;
        }
        Component forStmt=new Component(ComponentType.ForStmt,components);
        return forStmt;

    }
    public Component parse_Exp(){
        ArrayList<Component> components=new ArrayList<Component>();
        IntWrapper start= new IntWrapper(index);
        if(matchC(parse_AddExp(),components)==false){
            jump(start);
            return null;
        }
        Component exp=new Component(ComponentType.Exp,components);
        return exp;
    }
    public Component parse_Cond(){
        ArrayList<Component> components=new ArrayList<Component>();
        IntWrapper start= new IntWrapper(index);
        if(matchC(parse_LOrExp(),components)==false){
            jump(start);
            return null;
        }
        Component cond =new Component(ComponentType.Cond,components);
        return cond;
    }
    public Component parse_LVal(){
        ArrayList<Component> components=new ArrayList<Component>();
        IntWrapper start= new IntWrapper(index);
        if(match(TokenType.IDENFR,components)==null){
            jump(start);
            return null;
        }
        if(match(TokenType.LBRACK,components)!=null){
            if(matchC(parse_Exp(),components)==false){
                jump(start);
                return null;
            }
            if(match(TokenType.RBRACK,components)==null){
                addWrong("k",tokens.get(index-1).lineno);
            }
        }
        Component lVal =new Component(ComponentType.LVal,components);
        return lVal;
    }
    public Component parse_PrimaryExp(){
        ArrayList<Component> components=new ArrayList<Component>();
        IntWrapper start= new IntWrapper(index);
        if(matchC(parse_LVal(),components)==false){
            if(matchC(parse_Number(),components)==false){
                if(matchC(parse_Character(),components)==false){
                    if(match(TokenType.LPARENT,components)==null){
                        jump(start);
                        return null;
                    }
                    if(matchC(parse_Exp(),components)==false){
                        jump(start);
                        return null;
                    }
                    if(match(TokenType.RPARENT,components)==null){
                        addWrong("j",tokens.get(index-1).lineno);
                    }
                }
            }
        }
        Component primaryExp =new Component(ComponentType.PrimaryExp,components);
        return primaryExp;
    }
    public Component parse_Number(){
        ArrayList<Component> components=new ArrayList<Component>();
        IntWrapper start= new IntWrapper(index);
        if(match(TokenType.INTCON,components)==null){
            jump(start);
            return null;
        }
        Component number =new Component(ComponentType.Number,components);
        return number;
    }
    public Component parse_Character(){
        ArrayList<Component> components=new ArrayList<Component>();
        IntWrapper start= new IntWrapper(index);
        if(match(TokenType.CHRCON,components)==null){
            jump(start);
            return null;
        }
        Component character =new Component(ComponentType.Character,components);
        return character;
    }
    public Component parse_UnaryExp(){
        ArrayList<Component> components=new ArrayList<Component>();
        IntWrapper start= new IntWrapper(index);
        if(match(TokenType.IDENFR,components)!=null){
            if(match(TokenType.LPARENT,components)!=null){
                matchC(parse_FuncRParams(),components);
                if(match(TokenType.RPARENT,components)!=null){
                    Component unaryExp =new Component(ComponentType.UnaryExp,components);
                    return unaryExp;
                }else{
                    addWrong("j",tokens.get(index-1).lineno);
                    Component unaryExp =new Component(ComponentType.UnaryExp,components);
                    return unaryExp;
                }
            }
        }
        components.clear();
        jump(start);
        if(matchC(parse_PrimaryExp(),components)==true){
            Component unaryExp =new Component(ComponentType.UnaryExp,components);
            return unaryExp;
        }
        components.clear();
        jump(start);
        if(matchC(parse_UnaryOp(),components)==true){
            if(matchC(parse_UnaryExp(),components)==true){
                Component unaryExp =new Component(ComponentType.UnaryExp,components);
                return unaryExp;
            }
        }
        jump(start);
        return null;

    }

    public Component parse_UnaryOp(){
        ArrayList<Component> components=new ArrayList<Component>();
        IntWrapper start= new IntWrapper(index);
        if(match(TokenType.PLUS,components)==null){
            if(match(TokenType.MINU,components)==null){
                if(match(TokenType.NOT,components)==null){
                    jump(start);
                    return null;
                }
            }
        }
        Component unaryOp =new Component(ComponentType.UnaryOp,components);
        return unaryOp;
    }
    public Component parse_FuncRParams(){
        ArrayList<Component> components=new ArrayList<Component>();
        IntWrapper start= new IntWrapper(index);
        if(matchC(parse_Exp(),components)==false){
            jump(start);
            return null;
        }
        while(match(TokenType.COMMA,components)!=null){
            if(matchC(parse_Exp(),components)==false){
                jump(start);
                return null;
            }
        }
        Component funcRParams =new Component(ComponentType.FuncRParams,components);
        return funcRParams;
    }
    public Component parse_MulExp(){
        ArrayList<Component> components=new ArrayList<Component>();
        IntWrapper start= new IntWrapper(index);
        if(matchC(parse_UnaryExp(),components)==false){
            jump(start);
            return null;
        }
        if((currentToken.type==TokenType.MULT)||(currentToken.type==TokenType.DIV)||(currentToken.type==TokenType.MOD)){
            Component c=new Component(ComponentType.MulExp,components);
            components=new ArrayList<Component>();
            components.add(c);
        }
        while((match(TokenType.MULT,components)!=null)||(match(TokenType.DIV,components)!=null)||(match(TokenType.MOD,components)!=null)){
            if(matchC(parse_UnaryExp(),components)==false){
                jump(start);
                return null;
            }
            if((currentToken.type==TokenType.MULT)||(currentToken.type==TokenType.DIV)||(currentToken.type==TokenType.MOD)){
                Component c=new Component(ComponentType.MulExp,components);
                components=new ArrayList<Component>();
                components.add(c);
            }
        }
        Component mulExp =new Component(ComponentType.MulExp,components);
        return mulExp;
    }
    public Component parse_AddExp(){
        ArrayList<Component> components=new ArrayList<Component>();
        IntWrapper start= new IntWrapper(index);
        if(matchC(parse_MulExp(),components)==false){
            jump(start);
            return null;
        }
        if((currentToken.type==TokenType.PLUS)||(currentToken.type==TokenType.MINU)){
            Component c=new Component(ComponentType.AddExp,components);
            components=new ArrayList<Component>();
            components.add(c);
        }
        while((match(TokenType.PLUS,components)!=null)||(match(TokenType.MINU,components)!=null)){
            if(matchC(parse_MulExp(),components)==false){
                jump(start);
                return null;
            }
            if((currentToken.type==TokenType.PLUS)||(currentToken.type==TokenType.MINU)){
                Component c=new Component(ComponentType.AddExp,components);
                components=new ArrayList<Component>();
                components.add(c);
            }
        }
        Component addExp =new Component(ComponentType.AddExp,components);
        return addExp;
    }

    public Component parse_RelExp(){
        ArrayList<Component> components=new ArrayList<Component>();
        IntWrapper start= new IntWrapper(index);
        if(matchC(parse_AddExp(),components)==false){
            jump(start);
            return null;
        }
        if((currentToken.type==TokenType.LSS)||(currentToken.type==TokenType.GRE)||(currentToken.type==TokenType.LEQ)||(currentToken.type==TokenType.GEQ)){
            Component c=new Component(ComponentType.RelExp,components);
            components=new ArrayList<Component>();
            components.add(c);
        }
        while((match(TokenType.LSS,components)!=null)||(match(TokenType.GRE,components)!=null)||(match(TokenType.LEQ,components)!=null)||(match(TokenType.GEQ,components)!=null)){
            if(matchC(parse_AddExp(),components)==false){
                jump(start);
                return null;
            }
            if((currentToken.type==TokenType.LSS)||(currentToken.type==TokenType.GRE)||(currentToken.type==TokenType.LEQ)||(currentToken.type==TokenType.GEQ)){
                Component c=new Component(ComponentType.RelExp,components);
                components=new ArrayList<Component>();
                components.add(c);
            }
        }
        Component relExp =new Component(ComponentType.RelExp,components);
        return relExp;
    }
    public Component parse_EqExp(){
        ArrayList<Component> components=new ArrayList<Component>();
        IntWrapper start= new IntWrapper(index);
        if(matchC(parse_RelExp(),components)==false){
            jump(start);
            return null;
        }
        if((currentToken.type==TokenType.EQL)||(currentToken.type==TokenType.NEQ)){
            Component c=new Component(ComponentType.EqExp,components);
            components=new ArrayList<Component>();
            components.add(c);
        }
        while((match(TokenType.EQL,components)!=null)||(match(TokenType.NEQ,components)!=null)){
            if(matchC(parse_RelExp(),components)==false){
                jump(start);
                return null;
            }
            if((currentToken.type==TokenType.EQL)||(currentToken.type==TokenType.NEQ)){
                Component c=new Component(ComponentType.EqExp,components);
                components=new ArrayList<Component>();
                components.add(c);
            }
        }
        Component eqExp =new Component(ComponentType.EqExp,components);
        return eqExp;
    }

    public Component parse_LAndExp(){
        ArrayList<Component> components=new ArrayList<Component>();
        IntWrapper start= new IntWrapper(index);
        if(matchC(parse_EqExp(),components)==false){
            jump(start);
            return null;
        }
        if((currentToken.type==TokenType.AND)){
            Component c=new Component(ComponentType.LAndExp,components);
            components=new ArrayList<Component>();
            components.add(c);
        }
        while(match(TokenType.AND,components)!=null){
            if(matchC(parse_EqExp(),components)==false){
                jump(start);
                return null;
            }
            if((currentToken.type==TokenType.AND)){
                Component c=new Component(ComponentType.LAndExp,components);
                components=new ArrayList<Component>();
                components.add(c);
            }
        }
        Component lAndExp =new Component(ComponentType.LAndExp,components);
        return lAndExp;
    }
    public Component parse_LOrExp(){
        ArrayList<Component> components=new ArrayList<Component>();
        IntWrapper start= new IntWrapper(index);
        if(matchC(parse_LAndExp(),components)==false){
            jump(start);
            return null;
        }
        if(currentToken.type==TokenType.OR){
            Component c=new Component(ComponentType.LOrExp,components);
            components=new ArrayList<Component>();
            components.add(c);
        }
        while(match(TokenType.OR,components)!=null){
            if(matchC(parse_LAndExp(),components)==false){
                jump(start);
                return null;
            }
            if(currentToken.type==TokenType.OR){
                Component c=new Component(ComponentType.LOrExp,components);
                components=new ArrayList<Component>();
                components.add(c);
            }
        }
        Component lOrExp =new Component(ComponentType.LOrExp,components);
        return lOrExp;
    }
    public Component parse_ConstExp(){
        ArrayList<Component> components=new ArrayList<Component>();
        IntWrapper start= new IntWrapper(index);
        if(matchC(parse_AddExp(),components)==false){
            jump(start);
            return null;
        }
        Component constExp =new Component(ComponentType.ConstExp,components);
        return constExp;
    }
}
