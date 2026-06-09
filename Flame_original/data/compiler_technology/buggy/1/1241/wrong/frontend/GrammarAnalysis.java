package frontend;

import common.Error;
import common.GComponent;
import common.Token;
import common.TokenType;
import frontend.ast.LNode;
import frontend.ast.NLNode;
import frontend.ast.Node;


import java.util.ArrayList;
import java.util.List;

import static IO.MyWriter.getWriter;

/**
 * The type Grammar analysis.
 *
 * @author
 * @Description:  语法分析
 * @date
 */
public class GrammarAnalysis {
    private  List<Token> tokenList;
    private int index;

    /**
     * Instantiates a new Grammar analysis.
     *
     * @param tokenList the token list
     */
    public GrammarAnalysis(List<Token> tokenList) {
        this.tokenList = tokenList;
        this.index = 0;

    }

    private void next() {
        if(index + 1 < tokenList.size()){
           this.index++;}
    }

    private Token getCurToken() {
        return tokenList.get(index);
    }
    private Token preToken() {
        return tokenList.get(index-1);
    }

    /**
     * 超前读取Token
     * @param offset 提前读个数
     * @return Token
     */
    private Token peek(Integer offset) {
        if (index + offset >= tokenList.size()) {
            return new Token("out",TokenType.OUTOFBOUNDS,-1);
        }
        return tokenList.get(index + offset);
    }
    /**
     *
     *
     * @return Node
     */
    private Node matchToken(TokenType... tokenTypes) {
        //System.out.println("Checking: " + peek().getType() + " " + peek().getLineNum() + " with " + tokenTypes);
        boolean flag = false;
        for (TokenType symbol : tokenTypes) {
            if (getCurToken().getType().equals(symbol)) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            //错误处理
            if(tokenTypes[0].equals(TokenType.SEMICN)){
                Error.Error_i(preToken().getLineNum());

                return new LNode(tokenTypes[0],new Token(";",TokenType.SEMICN, preToken().getLineNum()),false);
            }else if(tokenTypes[0].equals(TokenType.RPARENT)){
                Error.Error_j(preToken().getLineNum());

                return new LNode(tokenTypes[0],new Token(")",TokenType.RPARENT, preToken().getLineNum()),false);
            }else if(tokenTypes[0].equals(TokenType.RBRACK)){
                Error.Error_k(preToken().getLineNum());
                return new LNode(tokenTypes[0],new Token("]",TokenType.RBRACK, preToken().getLineNum()),false);
            }

            return new LNode(tokenTypes[0], preToken(), false);
        } else {
            Token current = getCurToken();
            next();

            return new LNode(current.getType(), current, true);
        }

    }
    public Node analyze(){
        String s= tokenList.get(tokenList.size()-1).getStr();
        if(!tokenList.get(tokenList.size()-1).getType().equals(TokenType.RBRACE)){
            while (true){
                
            }
        }
        return  CompUnit();
    }


    /**
     * CompUnit → {Decl} {FuncDef} MainFuncDef
     *
     * @return Node
     */
    private Node CompUnit() {
        GComponent currentComponent = GComponent.CompUnit;
        NLNode result = new NLNode(currentComponent);

        while (!peek(2).getType().equals(TokenType.LPARENT)) {
            //CompUnit → {Decl}
            Node tmp = Decl();
            result.addChild(tmp);
        }

        while (!peek(1).getType().equals(TokenType.MAINTK)) {
            //CompUnit → {FuncDef}
            Node tmp = FuncDef();
            result.addChild(tmp);
        }
        //CompUnit → MainFuncDef
        Node mustNode = MainFuncDef();
        result.addChild(mustNode);



        return result;
    }
    /**
     *
     *
     * @return Node
     */
    private Node Decl() {
        GComponent  currentComponent = GComponent.Decl;
        NLNode result = new NLNode(currentComponent);


        Node tmp;
        if(getCurToken().getType().equals(TokenType.CONSTTK)){
            //Decl → ConstDecl
            tmp = ConstDecl();
        }else{
            //Decl → VarDecl
            tmp = VarDecl();
        }
        result.addChild(tmp);

        return result;
    }
    /**
     *  FuncDef → FuncType Ident '(' [FuncFParams] ')' Block
     *
     * @return Node
     */
    private Node FuncDef(){
        GComponent  currentComponent = GComponent.FuncDef;
        NLNode result = new NLNode(currentComponent);
        Node node1 = FuncType();
        Node node2 = matchToken(TokenType.IDENFR);
        Node node3 = matchToken(new TokenType[]{TokenType.LPARENT});
        result.addChild(node1);
        result.addChild(node2);
        result.addChild(node3);

        if(getCurToken().getType().equals(TokenType.RPARENT)|| getCurToken().getType().equals(TokenType.LBRACE)){
            Node node4 = matchToken(new TokenType[]{TokenType.RPARENT});
            result.addChild(node4);
        }else{
            Node node4 = FuncFParams();
            Node node5 = matchToken(new TokenType[]{TokenType.RPARENT});
            result.addChild(node4);
            result.addChild(node5);
        }
        Node node6 = Block();
        result.addChild(node6);
        return result;
    }
    /**
     * MainFuncDef → 'int' 'main' '(' ')' Block
     *
     * @return Node
     */
    private Node MainFuncDef(){
        GComponent  currentComponent = GComponent.MainFuncDef;
        NLNode result = new NLNode(currentComponent);

        Node node1 = matchToken(new TokenType[]{TokenType.INTTK});
        Node node2 = matchToken(new TokenType[]{TokenType.MAINTK});
        Node node3 = matchToken(new TokenType[]{TokenType.LPARENT});
        Node node4 = matchToken(new TokenType[]{TokenType.RPARENT});
        Node node5 = Block();
        result.addChild(node1);
        result.addChild(node2);
        result.addChild(node3);
        result.addChild(node4);
        result.addChild(node5);
        return result;
    }
    /**
     * FuncFParams → FuncFParam { ',' FuncFParam }
     *
     * @return Node
     */
    private Node FuncFParams(){
        GComponent  currentComponent = GComponent.FuncFParams;
        NLNode result = new NLNode(currentComponent);
        Node node = FuncFParam();
        result.addChild(node);
        while(getCurToken().getType().equals(TokenType.COMMA)){
            Node node1 = matchToken(new TokenType[]{TokenType.COMMA});
            Node node2 = FuncFParam();
            result.addChild(node1);
            result.addChild(node2);
        }

        return result;
    }
    /**
     *  FuncFParam → BType Ident ['[' ']']
     *
     * @return Node
     */
    private Node FuncFParam(){
        GComponent  currentComponent = GComponent.FuncFParam;
        NLNode result = new NLNode(currentComponent);
        Node node1 = BType();
        Node node2 = matchToken(new TokenType[]{TokenType.IDENFR});
        result.addChild(node1);
        result.addChild(node2);
        if(getCurToken().getType().equals(TokenType.LBRACK)){
            Node node3 = matchToken(new TokenType[]{TokenType.LBRACK});
            Node node4 = matchToken(new TokenType[]{TokenType.RBRACK});
            result.addChild(node3);
            result.addChild(node4);
        }

        return result;
    }
    /**
     *  Block → '{' { BlockItem } '}'
     *
     * @return Node
     */
    private Node Block(){
        GComponent  currentComponent = GComponent.Block;
        NLNode result = new NLNode(currentComponent);
        Node node1 = matchToken(new TokenType[]{TokenType.LBRACE});
        result.addChild(node1);
        while(!getCurToken().getType().equals(TokenType.RBRACE)){
            int currentIndex = index;
            Node node2 = BlockItem();
            if(currentIndex == tokenList.size()-1)
            {
                break;
            }
            result.addChild(node2);
        }
        Node node3 = matchToken(new TokenType[]{TokenType.RBRACE});
        result.addChild(node3);
        return result;
    }
    /**
     * BlockItem → Decl | Stmt
     *
     * @return Node
     */
    private Node BlockItem(){
        GComponent  currentComponent = GComponent.BlockItem;
        NLNode result = new NLNode(currentComponent);
        Node node;
        if(getCurToken().getType().equals(TokenType.INTTK)||getCurToken().getType().equals(TokenType.CHARTK)||getCurToken().getType().equals(TokenType.CONSTTK)){
            node = Decl();
        }else{
            int currentIndex = index;
            node = Stmt();


        }
        result.addChild(node);


        return result;
    }

    /**
     *  FuncType → 'void' | 'int' | 'char'
     *
     * @return Node
     */
    private Node FuncType(){
        GComponent  currentComponent = GComponent.FuncType;
        NLNode result = new NLNode(currentComponent);

        Node node = matchToken(new TokenType[]{TokenType.VOIDTK,TokenType.INTTK,TokenType.CHARTK});
        result.addChild(node);

        return result;
    }
    /**
     *  Stmt → LVal '=' Exp ';' // 每种类型的语句都要覆盖
     *  | [Exp] ';'
     *  | Block
     *  | 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
     *  | 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
     *  | 'break' ';'
     *  | 'continue' ';'
     *  | 'return' [Exp] ';'
     *  | LVal '=' 'getint''('')'';'
     *  | LVal '=' 'getchar''('')'';'
     *  | 'printf''('StringConst {','Exp}')'';'
     *
     * @return Node
     */
    private Node Stmt(){
        GComponent  currentComponent = GComponent.Stmt;
        NLNode result = new NLNode(currentComponent);
        if(getCurToken().getType().equals(TokenType.PRINTFTK)){
            Node node1 = matchToken(new TokenType[]{TokenType.PRINTFTK});
            Node node2 = matchToken(new TokenType[]{TokenType.LPARENT});
            Node node3 =  matchToken(new TokenType[]{TokenType.STRCON});
            result.addChild(node1);
            result.addChild(node2);
            result.addChild(node3);
            while(getCurToken().getType().equals(TokenType.COMMA)){
                Node node4 = matchToken(new TokenType[]{TokenType.COMMA});
                Node node5 = Exp();
                result.addChild(node4);
                result.addChild(node5);
            }
            Node node6 = matchToken(new TokenType[]{TokenType.RPARENT});
            result.addChild(node6);
            Node node7 = matchToken(new TokenType[]{TokenType.SEMICN});
            result.addChild(node7);
        }else if(getCurToken().getType().equals(TokenType.RETURNTK)){
            Node node1 = matchToken(new TokenType[]{TokenType.RETURNTK});
            result.addChild(node1);
            if(!getCurToken().getType().equals(TokenType.SEMICN)){
                Node node2 = Exp();
                result.addChild(node2);
            }
            Node node3 = matchToken(new TokenType[]{TokenType.SEMICN});
            result.addChild(node3);
        }else if(getCurToken().getType().equals(TokenType.CONTINUETK)){
            Node node1 = matchToken(new TokenType[]{TokenType.CONTINUETK});
            result.addChild(node1);
            Node node2 = matchToken(new TokenType[]{TokenType.SEMICN});
            result.addChild(node2);
        }else if(getCurToken().getType().equals(TokenType.BREAKTK)){
            Node node1 = matchToken(new TokenType[]{TokenType.BREAKTK});
            result.addChild(node1);
            Node node2 = matchToken(new TokenType[]{TokenType.SEMICN});
            result.addChild(node2);
        }else if(getCurToken().getType().equals(TokenType.FORTK)){
            Node node1 = matchToken(new TokenType[]{TokenType.FORTK});
            result.addChild(node1);
            Node node2 = matchToken(new TokenType[]{TokenType.LPARENT});
            result.addChild(node2);
            if(!getCurToken().getType().equals(TokenType.SEMICN)){
                Node node3 = ForStmt();
                result.addChild(node3);
            }
            Node node4 = matchToken(new TokenType[]{TokenType.SEMICN});
            result.addChild(node4);
            if(!getCurToken().getType().equals(TokenType.SEMICN)){
                Node node5 = Cond();
                result.addChild(node5);
            }
            Node node6 = matchToken(new TokenType[]{TokenType.SEMICN});
            result.addChild(node6);
            if(!getCurToken().getType().equals(TokenType.RPARENT)){
            Node node7 = ForStmt();
            result.addChild(node7);
            }
            Node node8 = matchToken(new TokenType[]{TokenType.RPARENT});
            result.addChild(node8);
            Node node9 = Stmt();
            result.addChild(node9);
        }else if(getCurToken().getType().equals(TokenType.IFTK)){
            Node node1 = matchToken(new TokenType[]{TokenType.IFTK});
            result.addChild(node1);
            Node node2 = matchToken(new TokenType[]{TokenType.LPARENT});
            result.addChild(node2);
            Node node3 = Cond();
            result.addChild(node3);
            Node node4 = matchToken(new TokenType[]{TokenType.RPARENT});
            result.addChild(node4);
            Node node5 = Stmt();
            result.addChild(node5);
            if(getCurToken().getType().equals(TokenType.ELSETK)){
                Node node6 = matchToken(new TokenType[]{TokenType.ELSETK});
                result.addChild(node6);
                Node node7 = Stmt();
                result.addChild(node7);
            }
        }else if(getCurToken().getType().equals(TokenType.LBRACE)){
            Node node1 = Block();
            result.addChild(node1);
        }else if(getCurToken().getType().equals(TokenType.IDENFR)&&peek(1).getType().equals(TokenType.LPARENT)){
            // UnaryExp →  Ident '(' [FuncRParams] ')' 说明是Exp
            Node node1 = Exp();
            Node node2 = matchToken(new TokenType[]{TokenType.SEMICN});
            result.addChild(node1);
            result.addChild(node2);
        }else if(getCurToken().getType().equals(TokenType.IDENFR)){
            // LVal
            int currentIndex = index;
            Node node1 = LVal();
            if(getCurToken().getType().equals(TokenType.ASSIGN)){
            //LVal = ····
            result.addChild(node1);
            Node node2 = matchToken(new TokenType[]{TokenType.ASSIGN});
            result.addChild(node2);
            if(getCurToken().getType().equals(TokenType.GETINTTK)){
                Node node3 = matchToken(new TokenType[]{TokenType.GETINTTK});
                result.addChild(node3);
                Node node4 = matchToken(new TokenType[]{TokenType.LPARENT});
                Node node5 = matchToken(new TokenType[]{TokenType.RPARENT});
                Node node6 = matchToken(new TokenType[]{TokenType.SEMICN});
                result.addChild(node4);
                result.addChild(node5);
                result.addChild(node6);
            }else if(getCurToken().getType().equals(TokenType.GETCHARTK)){
                Node node3 = matchToken(new TokenType[]{TokenType.GETCHARTK});
                result.addChild(node3);
                Node node4 = matchToken(new TokenType[]{TokenType.LPARENT});
                Node node5 = matchToken(new TokenType[]{TokenType.RPARENT});
                Node node6 = matchToken(new TokenType[]{TokenType.SEMICN});
                result.addChild(node4);
                result.addChild(node5);
                result.addChild(node6);
            }else {
                Node node3 = Exp();
                Node node4 = matchToken(new TokenType[]{TokenType.SEMICN});
                result.addChild(node3);
                result.addChild(node4);
            }
            }else {
            //Exp;
            index = currentIndex;//回退
            node1 = Exp();
            Node node2 = matchToken(new TokenType[]{TokenType.SEMICN});
            result.addChild(node1);
            result.addChild(node2);
            }
        }else {
            Node node1;
            if(getCurToken().getType().equals(TokenType.SEMICN)){
                node1 = matchToken(new TokenType[]{TokenType.SEMICN});

                result.addChild(node1);
            }else {
                node1 = Exp();
                Node node2 = matchToken(new TokenType[]{TokenType.SEMICN});
                result.addChild(node1);
                result.addChild(node2);
            }
        }
        return result;
    }



    /**
     * ForStmt → LVal '=' Exp
     *
     * @return Node
     */
    private Node ForStmt(){
        GComponent  currentComponent = GComponent.ForStmt;
        NLNode result = new NLNode(currentComponent);
        Node node1 = LVal();
        result.addChild(node1);
        Node node2 = matchToken(new TokenType[]{TokenType.ASSIGN});
        result.addChild(node2);
        Node node3 = Exp();
        result.addChild(node3);
        return result;
    }
    /**
     * Cond → LOrExp
     *
     * @return Node
     */
    private Node Cond(){
        GComponent  currentComponent = GComponent.Cond;
        NLNode result = new NLNode(currentComponent);

        Node node1 = LOrExp();
        result.addChild(node1);
        return result;
    }
    /**
     * ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';'
     *
     * @return Node
     */
    private Node ConstDecl(){
        GComponent  currentComponent = GComponent.ConstDecl;
        NLNode result = new NLNode(currentComponent);


        Node node1 = matchToken(new TokenType[]{TokenType.CONSTTK});
        Node node2 = BType();
        Node node3 = ConstDef();
        result.addChild(node1);
        result.addChild(node2);
        result.addChild(node3);

        while (getCurToken().getType().equals(TokenType.COMMA)){
            Node tem1 = matchToken(new TokenType[]{TokenType.COMMA});
            Node tem2 = ConstDef();
            result.addChild(tem1);
            result.addChild(tem2);
        }
        Node node4 = matchToken(new TokenType[]{TokenType.SEMICN});
        result.addChild(node4);
        return result;
    }
    /**
     *
     * VarDecl → BType VarDef { ',' VarDef } ';'
     *
     * @return Node
     */
    private Node VarDecl(){
        GComponent  currentComponent = GComponent.VarDecl;
        NLNode result = new NLNode(currentComponent);


        Node node1 = BType();
        Node node2 = VarDef();
        result.addChild(node1);
        result.addChild(node2);
        while (getCurToken().getType().equals(TokenType.COMMA)){
            Node tem1 = matchToken(new TokenType[]{TokenType.COMMA});
            Node tem2 = VarDef();
            result.addChild(tem1);
            result.addChild(tem2);
        }
        Node node3 = matchToken(new TokenType[]{TokenType.SEMICN});
        result.addChild(node3);

        return result;
    }
    /**
     *
     *
     * @return Node
     */
    private Node BType(){
        GComponent currentComponent = GComponent.BType;
        NLNode result = new NLNode(currentComponent);
        Node node = matchToken(TokenType.INTTK,TokenType.CHARTK);
        result.addChild(node);
        return result;
    }
    /**
     *ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal
     *
     * @return Node
     */
    private Node ConstDef(){

        GComponent  currentComponent = GComponent.ConstDef;
        NLNode result = new NLNode(currentComponent);


        Node node1 = matchToken(new TokenType[]{TokenType.IDENFR});
        result.addChild(node1);

        if(getCurToken().getType().equals(TokenType.LBRACK)){
            Node temp1 = matchToken(new TokenType[]{TokenType.LBRACK});
            result.addChild(temp1);
            Node temp2 = ConstExp();
            result.addChild(temp2);
            Node temp3 = matchToken(new TokenType[]{TokenType.RBRACK});
            result.addChild(temp3);
        }
        Node node2 = matchToken(new TokenType[]{TokenType.ASSIGN});
        result.addChild(node2);
        Node node3 = ConstInitVal();
        result.addChild(node3);
        return result;
    }
    /**
     *Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal
     *
     * @return Node
     */
    private Node VarDef(){
        GComponent  currentComponent = GComponent.VarDef;
        NLNode result = new NLNode(currentComponent);

        Node node1 = matchToken(new TokenType[]{TokenType.IDENFR});
        result.addChild(node1);

        if(getCurToken().getType().equals(TokenType.LBRACK)){
            Node temp1 = matchToken(new TokenType[]{TokenType.LBRACK});
            result.addChild(temp1);
            Node temp2 = ConstExp();
            result.addChild(temp2);
            Node temp3 = matchToken(new TokenType[]{TokenType.RBRACK});
            result.addChild(temp3);
        }

        if(getCurToken().getType().equals(TokenType.ASSIGN)){
            Node node2 = matchToken(new TokenType[]{TokenType.ASSIGN});
            result.addChild(node2);
            Node node3 = InitVal();
            result.addChild(node3);
        }

        return result;
    }
    /**
     * AddExp → MulExp | AddExp ('+' | '−') MulExp
     *
     * @return Node
     */
    private Node AddExp(){
        GComponent currentComponent = GComponent.AddExp;
        NLNode result = new NLNode(currentComponent);

        Node node1 = MulExp();
        result.addChild(node1);
        while(getCurToken().getType().equals(TokenType.PLUS)||getCurToken().getType().equals(TokenType.MINU)){
            //保证语法树正确
            NLNode tempResult = new NLNode(currentComponent);
            tempResult.addChild(result);
            result = tempResult;

            Node tem1 = matchToken(new TokenType[]{TokenType.PLUS,TokenType.MINU});
            Node tem2 = MulExp();

            result.addChild(tem1);
            result.addChild(tem2);
        }


        return result;
    }
    /**
    * MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
    *
    * @return Node
    */
    private Node MulExp(){
        GComponent currentComponent = GComponent.MulExp;
        NLNode result = new NLNode(currentComponent);

        Node node1 = UnaryExp();
        result.addChild(node1);
        while (getCurToken().getType().equals(TokenType.MULT)||getCurToken().getType().equals(TokenType.DIV)||getCurToken().getType().equals(TokenType.MOD)){
            //保证语法树正确
            NLNode tempResult = new NLNode(currentComponent);
            tempResult.addChild(result);
            result = tempResult;

            Node temp1 = matchToken(new TokenType[]{TokenType.MULT,TokenType.DIV,TokenType.MOD});
            Node temp2 = UnaryExp();

            result.addChild(temp1);
            result.addChild(temp2);
        }

        return result;
    }

    /**
     * UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
     *
     * @return Node
     */
    private Node UnaryExp(){
        GComponent currentComponent = GComponent.UnaryExp;
        NLNode result = new NLNode(currentComponent);

        if(getCurToken().getType().equals(TokenType.IDENFR)&&peek(1).getType().equals(TokenType.LPARENT)){
            Node node1 = matchToken(new TokenType[]{TokenType.IDENFR});
            Node node2 = matchToken(new TokenType[]{TokenType.LPARENT});
            result.addChild(node1);
            result.addChild(node2);

            if(!getCurToken().getType().equals(TokenType.RPARENT)){

                Node node3 = FuncRParams();

                result.addChild(node3);
                Node node4 = matchToken(new TokenType[]{TokenType.RPARENT});
                result.addChild(node4);
            }else{
                Node node4 = matchToken(new TokenType[]{TokenType.RPARENT});
                result.addChild(node4);
            }
        }else if(getCurToken().getType().equals(TokenType.PLUS)||getCurToken().getType().equals(TokenType.MINU)||getCurToken().getType().equals(TokenType.NOT)){
            Node node1 = UnaryOp();
            Node node2 = UnaryExp();
            result.addChild(node1);
            result.addChild(node2);
        }else {
            Node node1 = PrimaryExp();
            result.addChild(node1);
        }

        return result;
    }
    /**
     *
     * @return Node
     */
    private Node ConstExp(){
        //ConstExp → AddExp
        GComponent currentComponent = GComponent.ConstExp;
        NLNode result = new NLNode(currentComponent);

        Node node1 = AddExp();
        result.addChild(node1);

        return result;
    }
    /**
     * Exp → AddExp
     *
     * @return Node
     */
    private Node Exp(){
        GComponent currentComponent = GComponent.Exp;
        NLNode result = new NLNode(currentComponent);
        int currentIndex = index;
        Node node1 = AddExp();

        result.addChild(node1);
        return result;
    }
    /**
     * LOrExp → LAndExp | LOrExp '||' LAndExp
     *
     * @return Node
     */
    private Node LOrExp(){
        GComponent currentComponent = GComponent.LOrExp;
        NLNode result = new NLNode(currentComponent);
        Node node1 = LAndExp();
        result.addChild(node1);
        while (getCurToken().getType().equals(TokenType.OR)){
            NLNode node2 = new NLNode(currentComponent);
            node2.addChild(result);
            result = node2;

            Node node3 = matchToken(new TokenType[]{TokenType.OR});
            result.addChild(node3);
            Node node4 = LAndExp();
            result.addChild(node4);
        }

        return result;
    }
    /**
     * LAndExp → EqExp | LAndExp '&&' EqExp
     *
     * @return Node
     */
    private Node LAndExp(){
        GComponent currentComponent = GComponent.LAndExp;
        NLNode result = new NLNode(currentComponent);
        Node node1 = EqExp();
        result.addChild(node1);
        while (getCurToken().getType().equals(TokenType.AND)){
            NLNode node2 = new NLNode(currentComponent);
            node2.addChild(result);
            result = node2;

            Node node3 = matchToken(new TokenType[]{TokenType.AND});
            result.addChild(node3);
            Node node4 = EqExp();
            result.addChild(node4);
        }

        return result;
    }
    /**
     * EqExp → RelExp | EqExp ('==' | '!=') RelExp
     *
     * @return Node
     */
    private Node EqExp(){
        GComponent currentComponent = GComponent.EqExp;
        NLNode result = new NLNode(currentComponent);
        Node node1 = RelExp();
        result.addChild(node1);
        while (getCurToken().getType().equals(TokenType.EQL)||getCurToken().getType().equals(TokenType.NEQ)){
            NLNode node2 = new NLNode(currentComponent);
            node2.addChild(result);
            result = node2;

            Node node3 = matchToken(new TokenType[]{TokenType.EQL, TokenType.NEQ});
            result.addChild(node3);
            Node node4 = RelExp();
            result.addChild(node4);
        }

        return result;
    }
    /**
     *  RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
     *
     * @return Node
     */
    private Node RelExp(){
        GComponent currentComponent = GComponent.RelExp;
        NLNode result = new NLNode(currentComponent);
        Node node1 = AddExp();
        result.addChild(node1);
        while(getCurToken().getType().equals(TokenType.LSS)||getCurToken().getType().equals(TokenType.LEQ)||getCurToken().getType().equals(TokenType.GEQ)||getCurToken().getType().equals(TokenType.GRE)){
            NLNode node2 = new NLNode(currentComponent);
            node2.addChild(result);
            result = node2;

            Node node3 = matchToken(new TokenType[]{TokenType.LEQ, TokenType.LSS,TokenType.GEQ,TokenType.GRE});
            result.addChild(node3);
            Node node4 = AddExp();
            result.addChild(node4);
        }

        return result;
    }
    /**
     * ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
     *
     * @return Node
     */
    private Node ConstInitVal(){
        GComponent currentComponent = GComponent.ConstInitVal;
        NLNode result = new NLNode(currentComponent);

        if(getCurToken().getType().equals(TokenType.STRCON)){
            Node node1 = matchToken(new TokenType[]{TokenType.STRCON});
            result.addChild(node1);
        }else if(getCurToken().getType().equals(TokenType.LBRACE)){
            Node node1 = matchToken(new TokenType[]{TokenType.LBRACE});
            result.addChild(node1);
            if(!getCurToken().getType().equals(TokenType.RBRACE)){
            Node node2 = ConstExp();
            result.addChild(node2);
            while(getCurToken().getType().equals(TokenType.COMMA)){
                Node node3 = matchToken(new TokenType[]{TokenType.COMMA});
                Node node4 = ConstExp();
                result.addChild(node3);
                result.addChild(node4);
            }
            }
            Node node5 = matchToken(new TokenType[]{TokenType.RBRACE});
            result.addChild(node5);
        }else {
            Node node1 = ConstExp();
            result.addChild(node1);
        }
        return result;
    }
    /**
     *  InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
     *
     * @return Node
     */
    private Node InitVal(){
        GComponent currentComponent = GComponent.InitVal;
        NLNode result = new NLNode(currentComponent);
        if(getCurToken().getType().equals(TokenType.STRCON)){
            Node node1 = matchToken(new TokenType[]{TokenType.STRCON});
            result.addChild(node1);
        }else if(getCurToken().getType().equals(TokenType.LBRACE)){
            Node node1 = matchToken(new TokenType[]{TokenType.LBRACE});
            result.addChild(node1);
            if(!getCurToken().getType().equals(TokenType.RBRACE)){
            Node node2 = Exp();
            result.addChild(node2);
            while(getCurToken().getType().equals(TokenType.COMMA)){
                Node node3 = matchToken(new TokenType[]{TokenType.COMMA});
                Node node4 = Exp();
                result.addChild(node3);
                result.addChild(node4);
            }
            }
            Node node5 = matchToken(new TokenType[]{TokenType.RBRACE});
            result.addChild(node5);
        }else {
            Node node1 = Exp();
            result.addChild(node1);
        }

        return result;
    }
    /**
     * FuncRParams → Exp { ',' Exp }
     *
     * @return Node
     */
    private Node FuncRParams(){
        GComponent currentComponent = GComponent.FuncRParams;
        NLNode result = new NLNode(currentComponent);

        Node node1 = Exp();
        result.addChild(node1);
        while(getCurToken().getType().equals(TokenType.COMMA)){
            Node node2 = matchToken(new TokenType[]{TokenType.COMMA});
            Node node3 = Exp();
            result.addChild(node2);
            result.addChild(node3);

        }

        return result;
    }
    /**
     *
     *  UnaryOp → '+' | '−' | '!'
     *
     * @return Node
     */
    private Node UnaryOp(){
        GComponent currentComponent = GComponent.UnaryOp;
        NLNode result = new NLNode(currentComponent);

        Node node = matchToken(new TokenType[]{TokenType.PLUS,TokenType.MINU,TokenType.NOT});
        result.addChild(node);
        return result;
    }
    /**
     * PrimaryExp → '(' Exp ')' | LVal | Number | Character
     *
     * @return Node
     */
    private Node PrimaryExp(){
        GComponent currentComponent = GComponent.PrimaryExp;
        NLNode result = new NLNode(currentComponent);

        if(getCurToken().getType().equals(TokenType.CHRCON)){
            Node node = Character();
            result.addChild(node);
        }else if(getCurToken().getType().equals(TokenType.INTCON)){
            Node node = Number();
            result.addChild(node);
        }else if(getCurToken().getType().equals(TokenType.LPARENT)){
            Node node1 = matchToken(new TokenType[]{TokenType.LPARENT});
            Node node2 = Exp();
            Node node3 = matchToken(new TokenType[]{TokenType.RPARENT});
            result.addChild(node1);
            result.addChild(node2);
            result.addChild(node3);
        }else{
            Node node = LVal();
            result.addChild(node);
        }

        return result;
    }
    /**
     * LVal → Ident ['[' Exp ']']
     *
     * @return Node
     */
    private Node LVal(){
        GComponent currentComponent = GComponent.LVal;
        NLNode result = new NLNode(currentComponent);

        Node node1 = matchToken(new TokenType[]{TokenType.IDENFR});
        result.addChild(node1);

        if(getCurToken().getType().equals(TokenType.LBRACK)){
            Node node2 = matchToken(new TokenType[]{TokenType.LBRACK});
            Node node3 = Exp();
            Node node4 = matchToken(new TokenType[]{TokenType.RBRACK});

            result.addChild(node2);
            result.addChild(node3);
            result.addChild(node4);
        }

        return result;
    }

    private Node Number(){
        GComponent currentComponent = GComponent.Number;
        NLNode result = new NLNode(currentComponent);

        Node node = matchToken(new TokenType[]{TokenType.INTCON});
        result.addChild(node);

        return result;
    }

    private Node Character(){
        GComponent currentComponent = GComponent.Character;
        NLNode result = new NLNode(currentComponent);

        Node node = matchToken(new TokenType[]{TokenType.CHRCON});
        result.addChild(node);

        return result;
    }

}
