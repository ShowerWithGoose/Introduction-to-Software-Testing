package frontend.paser;

import frontend.AST.Const.ConstDecl;
import frontend.AST.Const.ConstDef;
import frontend.AST.Const.ConstInitVal;
import frontend.AST.Exp.*;
import frontend.AST.Func.*;
import frontend.AST.Node;
import frontend.AST.NumChar.Character;
import frontend.AST.NumChar.Number;
import frontend.AST.Other.Block;
import frontend.AST.Other.CompUnit;
import frontend.AST.Other.For_Stmt;
import frontend.AST.Other.TokenNode;
import frontend.AST.Stmt.*;
import frontend.AST.SyntaxVarType;
import frontend.AST.Var.InitVal;
import frontend.AST.Var.VarDecl;
import frontend.AST.Var.VarDef;
import frontend.ErrorType;
import frontend.Printer;
import frontend.lexer.TokenStream;
import frontend.lexer.Token;
import frontend.lexer.TokenType;

import java.io.IOException;
import java.util.ArrayList;

public class Parser {
    private TokenStream tokenStream;
    private Token curToken;

    public Parser(TokenStream tokenStream) {
        this.tokenStream = tokenStream;
        curToken = tokenStream.getToken();
    }

    private void advance() {
        curToken = tokenStream.getToken();
    }

    /*************************CompUnit***************************/
    //CompUnit -> {Decl} {FunDef} MainFuncDef
    //Decl -> ConstDecl | VarDecl

    public Node parseCompUnit() throws IOException {
        ArrayList<Node> childNodes = new ArrayList<>();//存储解析到的子节点
        int startLineNum = curToken.getLineNum();//当前编译单元的起始行号
        Node node = null;//暂时存放当前解析的节点

        while(true) {
            if (curToken == null) {
                break;
            }
            //如果下一个Token类型为MAINTK，说明接下来会是MainFuncDef
            //MainFuncDef -> 'int' 'main' '(' ')' Block
            //parse MainFuncDef
            //TODO: pos总比curToken超前一个
            else if (tokenStream.detect(1).getType() == TokenType.MAINTK) {
                node = parseMainFuncDef();
            }
            //如果之后第二个Token是'('，说明是函数定义
            //FuncDef -> FuncType Ident '(' [FuncFParams] ')' Block
            //parse FuncDef
            else if (tokenStream.detect(2).getType() == TokenType.LPARENT) {
                node = parseFuncDef();
            }
            //如果当前Token类型为CONSTTK，说明是常量声明
            //parse ConstDecl
            else if (curToken.getType() == TokenType.CONSTTK) {
                node = parseConstDecl();
            }
            //如果当前Token类型为INTTK或者CHARTK，说明是变量声明
            //parse VarDecl
            else if (curToken.getType() == TokenType.INTTK ||
                    curToken.getType() == TokenType.CHARTK) {
                node = parseVarDecl();
            }
            else {
                break;
            }
            childNodes.add(node);
        }
        //TODO：为什么是-1
        int endLineNum = tokenStream.detect(-1).getLineNum();
        Printer.getInstance().printSyntaxVarType(SyntaxVarType.COMP_UNIT);
        return new CompUnit(startLineNum, endLineNum,
                SyntaxVarType.COMP_UNIT, childNodes);
    }

    /********************变量声明*******************/
    //VarDecl -> BType VarDef { ',' VarDef } ';'
    //i型错误：缺省分号
    public Node parseVarDecl() throws IOException{
        ArrayList<Node> childNodes = new ArrayList<>();
        int starlineNum = curToken.getLineNum();
        Node node = null;

        //parse BType(int or char)
        Printer.getInstance().printToken(curToken);
        node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                SyntaxVarType.TOKEN, childNodes, curToken);
        childNodes.add(node);
        advance();
        //parse VarDef
        node = parseVarDef();
        childNodes.add(node);

        //parse  { ',' VarDef }
        while (curToken.getType() == TokenType.COMMA) {
            //parse ','
            Printer.getInstance().printToken(curToken);
            node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                    SyntaxVarType.TOKEN, childNodes, curToken);
            childNodes.add(node);
            advance();
            //parse VaeDef
            node = parseVarDef();
            childNodes.add(node);
        }
        //parse ';'
        if (curToken.getType() == TokenType.SEMICN) {
            Printer.getInstance().printToken(curToken);
            node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                    SyntaxVarType.TOKEN, childNodes, curToken);
            childNodes.add(node);
            advance();
        } else {
            Printer.getInstance().setHasError();
            Printer.getInstance().addError(node.getEndLineNum(), ErrorType.i);
        }

        int endLineNum = tokenStream.detect(-1).getLineNum();
        Printer.getInstance().printSyntaxVarType(SyntaxVarType.VAR_DECL);
        return new VarDecl(starlineNum, endLineNum, SyntaxVarType.VAR_DECL, childNodes);
    }

    /***********************常量声明**********************/
    //ConstDecl -> 'const' BType ConstDef { ',' ConstDef } ';'
    //i型错误：缺少';'
    public Node parseConstDecl() throws IOException {
        ArrayList<Node> childNodes = new ArrayList<>();
        int starlineNum = curToken.getLineNum();
        Node node = null;
        //parse 'const' -> CONSTTK Token
        Printer.getInstance().printToken(curToken);
        node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                SyntaxVarType.TOKEN, childNodes, curToken);
        childNodes.add(node);
        advance();
        //parse BType
        Printer.getInstance().printToken(curToken);
        node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                SyntaxVarType.TOKEN, childNodes, curToken);
        childNodes.add(node);
        advance();
        //parse ConstDef
        node = parseConstDef();
        childNodes.add(node);
        //parse { ',' ConstDef }
        while (curToken.getType() == TokenType.COMMA) {
            //parse ','
            Printer.getInstance().printToken(curToken);
            node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                    SyntaxVarType.TOKEN, childNodes, curToken);
            childNodes.add(node);
            advance();
            //parse ConstDef
            node = parseConstDef();
            childNodes.add(node);
        }
        //parse ';'
        if (curToken.getType() == TokenType.SEMICN) {
            Printer.getInstance().printToken(curToken);
            node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                    SyntaxVarType.TOKEN, childNodes, curToken);
            childNodes.add(node);
            advance();
        } else {
            Printer.getInstance().setHasError();
            Printer.getInstance().addError(node.getEndLineNum(), ErrorType.i);
        }

        int endLineNum = tokenStream.detect(-1).getLineNum();
        Printer.getInstance().printSyntaxVarType(SyntaxVarType.CONST_DECL);
        return new ConstDecl(starlineNum, endLineNum, SyntaxVarType.CONST_DECL, childNodes);
    }

    /*************************常量定义************************/
    //ConstDef -> Ident [ '[' ConstExp ']' ] '=' ConstInitVal
    //k型错误：缺少']'
    public Node parseConstDef() throws IOException {
        ArrayList<Node> childNodes = new ArrayList<>();
        int starlineNum = curToken.getLineNum();
        Node node = null;
        //parse Ident
        Printer.getInstance().printToken(curToken);
        node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                SyntaxVarType.TOKEN, childNodes, curToken);
        childNodes.add(node);
        advance();
        //parse [ '[' ConstExp ']' ]
        //TODO: 为什么不用if
        if (curToken.getType() == TokenType.LBRACK) {
            //parse '['
            Printer.getInstance().printToken(curToken);
            node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                    SyntaxVarType.TOKEN, childNodes, curToken);
            childNodes.add(node);
            advance();
            //parse ConstExp
            node = parseConstExp();
            childNodes.add(node);
            //parse ']'
            if (curToken.getType() == TokenType.RBRACK) {
                Printer.getInstance().printToken(curToken);
                node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                        SyntaxVarType.TOKEN, childNodes, curToken);
                childNodes.add(node);
                advance();
            } else {
                System.out.println("add k Error");
                Printer.getInstance().setHasError();
                Printer.getInstance().addError(node.getEndLineNum(), ErrorType.k);
            }
        }
        //parse ['=' ConstInitVal]
        if (curToken.getType() == TokenType.ASSIGN) {
            //parse '='
            Printer.getInstance().printToken(curToken);
            node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                    SyntaxVarType.TOKEN, childNodes, curToken);
            childNodes.add(node);
            advance();
            //parse InitVal
            node = parseConstInitVal();
            childNodes.add(node);
        }
        int endLineNum = tokenStream.detect(-1).getLineNum();
        Printer.getInstance().printSyntaxVarType(SyntaxVarType.CONST_DEF);
        return new ConstDef(starlineNum, endLineNum, SyntaxVarType.CONST_DEF, childNodes);
    }

    /*************************常量初值**************************/
    //ConstInitVal -> ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
    public Node parseConstInitVal() throws IOException {
        ArrayList<Node> childNodes = new ArrayList<>();
        int starlineNum = curToken.getLineNum();
        Node node = null;

        //parse StringConst
        if (curToken.getType() == TokenType.STRCON) {
            Printer.getInstance().printToken(curToken);
            node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                    SyntaxVarType.TOKEN, childNodes, curToken);
            childNodes.add(node);
            advance();
        }
        //parse '{' [ ConstExp { ',' ConstExp } ] '}'
        else if (curToken.getType() == TokenType.LBRACE) {
            //parse '{'
            Printer.getInstance().printToken(curToken);
            node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                    SyntaxVarType.TOKEN, childNodes, curToken);
            childNodes.add(node);
            advance();
            //parse [ ConstExp { ',' ConstExp } ]
            if (curToken.getType() != TokenType.RBRACE) {
                //parse ConstExp
                node = parseConstExp();
                childNodes.add(node);
                //parse { ',' ConstExp }
                while (curToken.getType() == TokenType.COMMA) {
                    //parse ','
                    Printer.getInstance().printToken(curToken);
                    node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                            SyntaxVarType.TOKEN, childNodes, curToken);
                    childNodes.add(node);
                    advance();
                    //parse Exp
                    node = parseConstExp();
                    childNodes.add(node);
                }
            }
            //parse '}'
            Printer.getInstance().printToken(curToken);
            node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                    SyntaxVarType.TOKEN, childNodes, curToken);
            childNodes.add(node);
            advance();

        } else { //parse ConstExp
            node = parseConstExp();
            childNodes.add(node);
        }
        int endLineNum = tokenStream.detect(-1).getLineNum();
        Printer.getInstance().printSyntaxVarType(SyntaxVarType.CONST_INITVAL);
        return new ConstInitVal(starlineNum, endLineNum, SyntaxVarType.CONST_INITVAL, childNodes);

    }

    /*************************变量定义**************************/
    //VarDef -> Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal
    //k型错误：缺少']'
    public Node parseVarDef() throws IOException {
        ArrayList<Node> childNodes = new ArrayList<>();
        int starlineNum = curToken.getLineNum();
        Node node = null;
        //parse Ident
        Printer.getInstance().printToken(curToken);
        node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                SyntaxVarType.TOKEN, childNodes, curToken);
        childNodes.add(node);
        advance();

        //parse [ '[' ConstExp ']' ]
        //TODO: 为什么不用if
        if (curToken.getType() == TokenType.LBRACK) {
            //parse '['
            Printer.getInstance().printToken(curToken);
            node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                    SyntaxVarType.TOKEN, childNodes, curToken);
            childNodes.add(node);
            advance();
            //parse ConstExp
            node = parseConstExp();
            childNodes.add(node);
            //parse ']'
            if (curToken.getType() == TokenType.RBRACK) {
                Printer.getInstance().printToken(curToken);
                node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                        SyntaxVarType.TOKEN, childNodes, curToken);
                childNodes.add(node);
                advance();
            } else {
                Printer.getInstance().setHasError();
                Printer.getInstance().addError(node.getEndLineNum(), ErrorType.k);
            }
        }
        //parse ['=' InitVal]
        if (curToken.getType() == TokenType.ASSIGN) {
            //parse '='
            Printer.getInstance().printToken(curToken);
            node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                    SyntaxVarType.TOKEN, childNodes, curToken);
            childNodes.add(node);
            advance();
            //parse InitVal
            node = parseInitVal();
            childNodes.add(node);
        }
        int endLineNum = tokenStream.detect(-1).getLineNum();
        Printer.getInstance().printSyntaxVarType(SyntaxVarType.VAR_DEF);
        return new VarDef(starlineNum, endLineNum, SyntaxVarType.VAR_DEF, childNodes);
    }

    /**************************变量初值***************************/
    //InitVal -> Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
    public Node parseInitVal() throws IOException {
        ArrayList<Node> childNodes = new ArrayList<>();
        int starlineNum = curToken.getLineNum();
        Node node = null;

        //parse StringConst
        if (curToken.getType() == TokenType.STRCON) {
            Printer.getInstance().printToken(curToken);
            node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                    SyntaxVarType.TOKEN, childNodes, curToken);
            childNodes.add(node);
            advance();
        }
        //parse '{' [ Exp { ',' Exp } ] '}'
        else if (curToken.getType() == TokenType.LBRACE) {
            //parse '{'
            Printer.getInstance().printToken(curToken);
            node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                    SyntaxVarType.TOKEN, childNodes, curToken);
            childNodes.add(node);
            advance();
            //parse  [ Exp { ',' Exp } ]
            if (curToken.getType() != TokenType.RBRACE) {
                //parse Exp
                node = parseExp();
                childNodes.add(node);
                //parse { ',' Exp }
                while (curToken.getType() == TokenType.COMMA) {
                    //parse ','
                    Printer.getInstance().printToken(curToken);
                    node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                            SyntaxVarType.TOKEN, childNodes, curToken);
                    childNodes.add(node);
                    advance();
                    //parse Exp
                    node = parseExp();
                    childNodes.add(node);
                }
            }
            //parse '}'
            Printer.getInstance().printToken(curToken);
            node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                    SyntaxVarType.TOKEN, childNodes, curToken);
            childNodes.add(node);
            advance();
        }
        //parse Exp
        else { //parse Exp
            node = parseExp();
            childNodes.add(node);
        }
        int endLineNum = tokenStream.detect(-1).getLineNum();
        Printer.getInstance().printSyntaxVarType(SyntaxVarType.INIT_VAL);
        return new InitVal(starlineNum, endLineNum, SyntaxVarType.INIT_VAL, childNodes);
    }

    /*************************函数定义***********************/
    //FuncDef -> FuncType Ident '(' [FuncFParams] ')' Block
    //j型错误：缺少')'
    public Node parseFuncDef() throws IOException {
        ArrayList<Node> childNodes = new ArrayList<>();
        int starlineNum = curToken.getLineNum();
        Node node = null;

        //parse FuncType
        node = parseFuncType();
        childNodes.add(node);
        //parse Ident
        Printer.getInstance().printToken(curToken);
        node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                SyntaxVarType.TOKEN, childNodes, curToken);
        childNodes.add(node);
        advance();
        //parse '('
        Printer.getInstance().printToken(curToken);
        node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                SyntaxVarType.TOKEN, childNodes, curToken);
        childNodes.add(node);
        advance();
        //parse [FuncFParams]
        if (curToken.getType() == TokenType.INTTK
            || curToken.getType() == TokenType.CHARTK) {
            node = parseFuncFParams();
            childNodes.add(node);
        }
        //parse ')'
        if (curToken.getType() == TokenType.RPARENT) {
            Printer.getInstance().printToken(curToken);
            node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                    SyntaxVarType.TOKEN, childNodes, curToken);
            childNodes.add(node);
            advance();
        } else {
            Printer.getInstance().setHasError();
            Printer.getInstance().addError(node.getEndLineNum(), ErrorType.j);
        }
        //parse Block
        node = parseBlock();
        childNodes.add(node);

        int endLineNum = tokenStream.detect(-1).getLineNum();
        Printer.getInstance().printSyntaxVarType(SyntaxVarType.FUNC_DEF);
        return new FuncDef(starlineNum, endLineNum, SyntaxVarType.FUNC_DEF, childNodes);
    }

    /***********************函数类型************************/
    //FuncType -> 'void' | 'int' | 'char'
    public Node parseFuncType() throws IOException{
        ArrayList<Node> childNodes = new ArrayList<>();
        int starlineNum = curToken.getLineNum();
        Node node = null;

        Printer.getInstance().printToken(curToken);
        node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                SyntaxVarType.TOKEN, childNodes, curToken);
        childNodes.add(node);
        advance();
        int endLineNum = tokenStream.detect(-1).getLineNum();
        Printer.getInstance().printSyntaxVarType(SyntaxVarType.FUNC_TYPE);
        return new FuncType(starlineNum, endLineNum, SyntaxVarType.FUNC_TYPE, childNodes);
    }

    /*****************************语句块*************************/
    //Block -> '{' { BlockItem } '}'
    //BlockItem -> ConstDecl | VarDecl | Stmt
    public Node parseBlock() throws IOException {
        ArrayList<Node> childNodes = new ArrayList<>();
        int starlineNum = curToken.getLineNum();
        Node node = null;
        //parse '{'
        Printer.getInstance().printToken(curToken);
        node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                SyntaxVarType.TOKEN, childNodes, curToken);
        childNodes.add(node);
        advance();
        //parse  { ConstDecl | VarDecl | Stmt }
        while (curToken.getType() != TokenType.RBRACE) {
            //parse ConstDecl
            if (curToken.getType() == TokenType.CONSTTK) {
                node = parseConstDecl();
                childNodes.add(node);
            }
            //parse VarDecl
            else if (curToken.getType() == TokenType.INTTK
                        || curToken.getType() == TokenType.CHARTK) {
                node = parseVarDecl();
                childNodes.add(node);
            }
            //parse Stmt
            else {
                node = parseStmt();
                childNodes.add(node);
            }
        }
        //parse '}'
        Printer.getInstance().printToken(curToken);
        node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                SyntaxVarType.TOKEN, childNodes, curToken);
        childNodes.add(node);
        advance();

        int endLineNum = tokenStream.detect(-1).getLineNum();
        Printer.getInstance().printSyntaxVarType(SyntaxVarType.BLOCK);
        return new Block(starlineNum, endLineNum, SyntaxVarType.BLOCK, childNodes);
    }

    /***************************主函数定义**************************/
    //MainFuncDef -> 'int' 'main' '(' ')' Block
    //j型错误：缺少')'
    public Node parseMainFuncDef() throws IOException {
        ArrayList<Node> childNodes = new ArrayList<>();
        int starlineNum = curToken.getLineNum();
        Node node = null;
        //parse 'int'
        Printer.getInstance().printToken(curToken);
        node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                SyntaxVarType.TOKEN, childNodes, curToken);
        childNodes.add(node);
        advance();
        //parse 'main'
        Printer.getInstance().printToken(curToken);
        node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                SyntaxVarType.TOKEN, childNodes, curToken);
        childNodes.add(node);
        advance();
        //parse '('
        Printer.getInstance().printToken(curToken);
        node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                SyntaxVarType.TOKEN, childNodes, curToken);
        childNodes.add(node);
        advance();
        //parse ')'
        if (curToken.getType() == TokenType.RPARENT) {
            Printer.getInstance().printToken(curToken);
            node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                    SyntaxVarType.TOKEN, childNodes, curToken);
            childNodes.add(node);
            advance();
        } else {
            Printer.getInstance().setHasError();
            Printer.getInstance().addError(node.getEndLineNum(), ErrorType.j);
        }
        //parse Block
        node = parseBlock();
        childNodes.add(node);

        int endLineNum = tokenStream.detect(-1).getLineNum();
        Printer.getInstance().printSyntaxVarType(SyntaxVarType.MAIN_FUNC_DEF);
        return new MainFuncDef(starlineNum, endLineNum, SyntaxVarType.MAIN_FUNC_DEF, childNodes);
    }

    /*************************函数形参表*************************/
    //FuncFParams -> FuncFParam { ',' FuncFParam }
    public Node parseFuncFParams() throws IOException {
        ArrayList<Node> childNodes = new ArrayList<>();
        int starlineNum = curToken.getLineNum();
        Node node = null;
        //parse FuncParam
        node = parseFuncParam();
        childNodes.add(node);
        //parse { ',' FuncFParam }
        while(curToken.getType() == TokenType.COMMA) {
            //parse ','
            Printer.getInstance().printToken(curToken);
            node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                    SyntaxVarType.TOKEN, childNodes, curToken);
            childNodes.add(node);
            advance();
            //parse FuncFaram
            node = parseFuncParam();
            childNodes.add(node);
        }
        int endLineNum = tokenStream.detect(-1).getLineNum();
        Printer.getInstance().printSyntaxVarType(SyntaxVarType.FUNC_F_PARAMS);
        return new FuncFParams(starlineNum, endLineNum, SyntaxVarType.FUNC_F_PARAMS, childNodes);
    }

    /*************************函数形参***********************/
    //FuncFParam -> BType Ident [ '[' ']' ]
    //k型错误：缺少']'
    public Node parseFuncParam() throws IOException {
        ArrayList<Node> childNodes = new ArrayList<>();
        int starlineNum = curToken.getLineNum();
        Node node = null;

        //parse BType
        Printer.getInstance().printToken(curToken);
        node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                SyntaxVarType.TOKEN, childNodes, curToken);
        childNodes.add(node);
        advance();
        //parse Ident
        Printer.getInstance().printToken(curToken);
        node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                SyntaxVarType.TOKEN, childNodes, curToken);
        childNodes.add(node);
        advance();
        //parse [ '[' ']']
        if (curToken.getType() == TokenType.LBRACK) {
            //parse '['
            Printer.getInstance().printToken(curToken);
            node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                    SyntaxVarType.TOKEN, childNodes, curToken);
            childNodes.add(node);
            advance();
            //parse ']'
            if (curToken.getType() == TokenType.RBRACK) {
                Printer.getInstance().printToken(curToken);
                node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                        SyntaxVarType.TOKEN, childNodes, curToken);
                childNodes.add(node);
                advance();
            } else {
                Printer.getInstance().setHasError();
                Printer.getInstance().addError(node.getEndLineNum(), ErrorType.k);
            }
        }
        int endLineNum = tokenStream.detect(-1).getLineNum();
        Printer.getInstance().printSyntaxVarType(SyntaxVarType.FUNC_F_PARAM);
        return new FuncFParam(starlineNum, endLineNum, SyntaxVarType.FUNC_F_PARAM, childNodes);
    }

    /************************函数实参表***************************/
    //FuncRParams -> Exp {',' Exp}
    public Node parseFuncRParams() throws IOException {
        ArrayList<Node> childNodes = new ArrayList<>();
        int starlineNum = curToken.getLineNum();
        Node node = null;

        //parse Exp
        node = parseExp();
        childNodes.add(node);
        //parse {',' Exp}
        while(curToken.getType() == TokenType.COMMA) {
            //parse ','
            Printer.getInstance().printToken(curToken);
            node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                    SyntaxVarType.TOKEN, childNodes, curToken);
            childNodes.add(node);
            advance();
            //parse Exp
            node = parseExp();
            childNodes.add(node);
        }
        int endLineNum = tokenStream.detect(-1).getLineNum();
        Printer.getInstance().printSyntaxVarType(SyntaxVarType.FUNC_R_PARAMS);
        return new FuncRParams(starlineNum, endLineNum, SyntaxVarType.FUNC_R_PARAMS, childNodes);
    }

    /**************************Stmt************************/
    public Node parseStmt() throws IOException {
        switch (curToken.getType()) {
            case LBRACE:
                return parseBlockStmt();
            case IFTK:
                return parseIfStmt();
            case FORTK:
                return parseForStmt();
            case BREAKTK:
                return parseBreakStmt();
            case CONTINUETK:
                return parseContinueStmt();
            case RETURNTK:
                return parseReturnStmt();
            case PRINTFTK:
                return parsePrintfStmt();
            case SEMICN://[Exp]; 解决单个;作为语句的情况
                return parseExpStmt();
        }

        tokenStream.setBackPoint();//将当前 pos 的值保存到 watchPoint 中
        Printer.getInstance().turnOff();
        parseExp();
        Printer.getInstance().turnOn();

        if (curToken.getType() == TokenType.ASSIGN) {
            if (tokenStream.detect(1).getType() == TokenType.GETINTTK) {
                curToken = tokenStream.backToBackPoint();
                return parseGetIntStmt();
            } else if (tokenStream.detect(1).getType() == TokenType.GETCHARTK) {
                curToken = tokenStream.backToBackPoint();
                return parseGetCharStmt();
            } else {
                System.out.println("start to enter parseAssignStmt() ");
                curToken = tokenStream.backToBackPoint();
                return parseAssignStmt();
            }
        } else {
            curToken = tokenStream.backToBackPoint();
            return parseExpStmt();
        }
    }

    //LVal '=' Exp ';'
    //i型错误：缺少';'
    public Node parseAssignStmt() throws IOException {
        ArrayList<Node> childNodes = new ArrayList<>();
        int starlineNum = curToken.getLineNum();
        Node node = null;
        //parse LValExp
        node = parseLValExp();
        childNodes.add(node);

        //parse '='
        Printer.getInstance().printToken(curToken);
        node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                SyntaxVarType.TOKEN, childNodes, curToken);
        childNodes.add(node);
        advance();

        //parse Exp
        node = parseExp();
        childNodes.add(node);

        //parse ';'
        if (curToken.getType() == TokenType.SEMICN) {
            Printer.getInstance().printToken(curToken);
            node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                    SyntaxVarType.TOKEN, childNodes, curToken);
            childNodes.add(node);
            advance();
        } else {
            Printer.getInstance().setHasError();
            Printer.getInstance().addError(node.getEndLineNum(), ErrorType.i);
        }
        int endLineNum = tokenStream.detect(-1).getLineNum();
        Printer.getInstance().printSyntaxVarType(SyntaxVarType.ASSIGN_STMT);
        return new AssignStmt(starlineNum, endLineNum, SyntaxVarType.ASSIGN_STMT, childNodes);
    }

    //[Exp] ';'
    //i型错误：缺少';'
    public Node parseExpStmt() throws IOException {
        ArrayList<Node> childNodes = new ArrayList<>();
        int starlineNum = curToken.getLineNum();
        Node node = null;

        //parse [Exp]
        if (isStartOfExp()) {
            node = parseExp();
            childNodes.add(node);
        }
        //parse ';'
        if (curToken.getType() == TokenType.SEMICN) {
            Printer.getInstance().printToken(curToken);
            node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                    SyntaxVarType.TOKEN, childNodes, curToken);
            childNodes.add(node);
            advance();
        } else { //TODO：node为null时怎么办？？？？？？？
            Printer.getInstance().setHasError();
            Printer.getInstance().addError(node.getEndLineNum(), ErrorType.i);
        }
        int endLineNum = tokenStream.detect(-1).getLineNum();
        Printer.getInstance().printSyntaxVarType(SyntaxVarType.EXP_STMT);
        return new ExpStmt(starlineNum, endLineNum, SyntaxVarType.EXP_STMT, childNodes);
    }

    //BlockStmt: Block
    public Node parseBlockStmt() throws IOException {
        ArrayList<Node> childNodes = new ArrayList<>();
        int starlineNum = curToken.getLineNum();
        Node node = null;
        //parse Block
        node = parseBlock();
        childNodes.add(node);

        int endLineNum = tokenStream.detect(-1).getLineNum();
        Printer.getInstance().printSyntaxVarType(SyntaxVarType.BLOCK_STMT);
        return new BlockStmt(starlineNum, endLineNum, SyntaxVarType.BLOCK_STMT, childNodes);
    }

    //IfStmt: 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
    //j型错误：缺少')'
    public Node parseIfStmt() throws IOException {
        ArrayList<Node> childNodes = new ArrayList<>();
        int starlineNum = curToken.getLineNum();
        Node node = null;
        //parse 'if'
        Printer.getInstance().printToken(curToken);
        node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                SyntaxVarType.TOKEN, childNodes, curToken);
        childNodes.add(node);
        advance();
        //parse '('
        Printer.getInstance().printToken(curToken);
        node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                SyntaxVarType.TOKEN, childNodes, curToken);
        childNodes.add(node);
        advance();
        //parse Cond
        node = parseCondExp();
        childNodes.add(node);
        //parse ')'
        if (curToken.getType() == TokenType.RPARENT) {
            Printer.getInstance().printToken(curToken);
            node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                    SyntaxVarType.TOKEN, childNodes, curToken);
            childNodes.add(node);
            advance();
        } else {
            Printer.getInstance().setHasError();
            Printer.getInstance().addError(node.getEndLineNum(), ErrorType.j);
        }
        //parse Stmt
        node = parseStmt();
        childNodes.add(node);
        //parse [ 'else' Stmt ]
        if (curToken.getType() == TokenType.ELSETK) {
            //parse 'else'
            Printer.getInstance().printToken(curToken);
            node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                    SyntaxVarType.TOKEN, childNodes, curToken);
            childNodes.add(node);
            advance();
            //parse Stmt
            node = parseStmt();
            childNodes.add(node);
        }
        int endLineNum = tokenStream.detect(-1).getLineNum();
        Printer.getInstance().printSyntaxVarType(SyntaxVarType.IF_STMT);
        return new IfStmt(starlineNum, endLineNum, SyntaxVarType.IF_STMT, childNodes);
    }

    //ForStmt : 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
    public Node parseForStmt() throws IOException {
        ArrayList<Node> childNodes = new ArrayList<>();
        int starlineNum = curToken.getLineNum();
        Node node = null;

        //parse 'for'
        Printer.getInstance().printToken(curToken);
        node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                SyntaxVarType.TOKEN, childNodes, curToken);
        childNodes.add(node);
        advance();
        //parse '('
        Printer.getInstance().printToken(curToken);
        node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                SyntaxVarType.TOKEN, childNodes, curToken);
        childNodes.add(node);
        advance();
        //parse [ForStmt]
        if (curToken.getType() == TokenType.IDENFR) {
            node = parseFor_Stmt();
            childNodes.add(node);
        }
        //parse ';'
        Printer.getInstance().printToken(curToken);
        node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                SyntaxVarType.TOKEN, childNodes, curToken);
        childNodes.add(node);
        advance();
        //parse [Cond]
        //TODO: 怎么判断是Cond
        if (isStartOfExp()) {
            node = parseCondExp();
            childNodes.add(node);
        }
        //parse ';'
        Printer.getInstance().printToken(curToken);
        node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                SyntaxVarType.TOKEN, childNodes, curToken);
        childNodes.add(node);
        advance();
        //parse [ForStmt]
        if (curToken.getType() == TokenType.IDENFR) {
            node = parseFor_Stmt();
            childNodes.add(node);
        }
        //parse ')'
        Printer.getInstance().printToken(curToken);
        node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                SyntaxVarType.TOKEN, childNodes, curToken);
        childNodes.add(node);
        advance();
        //parse Stmt
        node = parseStmt();
        childNodes.add(node);

        int endLineNum = tokenStream.detect(-1).getLineNum();
        Printer.getInstance().printSyntaxVarType(SyntaxVarType.FOR_STMT);
        return new ForStmt(starlineNum, endLineNum, SyntaxVarType.FOR_STMT, childNodes);
    }

    //BreakStmt: 'break' ';'
    //i型错误：缺少';'
    public Node parseBreakStmt() throws IOException {
        ArrayList<Node> childNodes = new ArrayList<>();
        int starlineNum = curToken.getLineNum();
        Node node = null;
        //parse 'break'
        Printer.getInstance().printToken(curToken);
        node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                SyntaxVarType.TOKEN, childNodes, curToken);
        childNodes.add(node);
        advance();
        //parse ';'
        if (curToken.getType() == TokenType.SEMICN) {
            Printer.getInstance().printToken(curToken);
            node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                    SyntaxVarType.TOKEN, childNodes, curToken);
            childNodes.add(node);
            advance();
        } else {
            Printer.getInstance().setHasError();
            Printer.getInstance().addError(node.getEndLineNum(), ErrorType.i);
        }

        int endLineNum = tokenStream.detect(-1).getLineNum();
        Printer.getInstance().printSyntaxVarType(SyntaxVarType.BREAK_STMT);
        return new BreakStmt(starlineNum, endLineNum, SyntaxVarType.BREAK_STMT, childNodes);
    }

    //ContinueStmt: 'continue' ';'
    //i型错误：缺少';'
    public Node parseContinueStmt() throws IOException {
        ArrayList<Node> childNodes = new ArrayList<>();
        int starlineNum = curToken.getLineNum();
        Node node = null;
        //parse 'continue'
        Printer.getInstance().printToken(curToken);
        node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                SyntaxVarType.TOKEN, childNodes, curToken);
        childNodes.add(node);
        advance();
        //parse ';'
        if (curToken.getType() == TokenType.SEMICN) {
            Printer.getInstance().printToken(curToken);
            node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                    SyntaxVarType.TOKEN, childNodes, curToken);
            childNodes.add(node);
            advance();
        } else {
            Printer.getInstance().setHasError();
            Printer.getInstance().addError(node.getEndLineNum(), ErrorType.i);
        }

        int endLineNum = tokenStream.detect(-1).getLineNum();
        Printer.getInstance().printSyntaxVarType(SyntaxVarType.CONTINUE_STMT);
        return new ContinueStmt(starlineNum, endLineNum, SyntaxVarType.CONTINUE_STMT, childNodes);
    }

    //ReturnStmt: 'return' [Exp] ';'
    //i型错误：缺少';'
    public Node parseReturnStmt() throws IOException {
        ArrayList<Node> childNodes = new ArrayList<>();
        int starlineNum = curToken.getLineNum();
        Node node = null;

        //parse 'return'
        Printer.getInstance().printToken(curToken);
        node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                SyntaxVarType.TOKEN, childNodes, curToken);
        childNodes.add(node);
        advance();
        //parse [Exp]
        if (isStartOfExp()) {
            node = parseExp();
            childNodes.add(node);
        }
        //parse ';'
        if (curToken.getType() == TokenType.SEMICN) {
            Printer.getInstance().printToken(curToken);
            node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                    SyntaxVarType.TOKEN, childNodes, curToken);
            childNodes.add(node);
            advance();
        } else {
            System.out.println("return no ;");
            Printer.getInstance().setHasError();
            Printer.getInstance().addError(node.getEndLineNum(), ErrorType.i);
        }

        int endLineNum = tokenStream.detect(-1).getLineNum();
        Printer.getInstance().printSyntaxVarType(SyntaxVarType.RETURN_STMT);
        return new ReturnStmt(starlineNum, endLineNum, SyntaxVarType.RETURN_STMT, childNodes);
    }

    //GetIntStmt: LVal '=' 'getint' '(' ')' ';'
    //i型错误：缺少';'
    //j型错误：缺少')'
    public Node parseGetIntStmt() throws IOException {
        ArrayList<Node> childNodes = new ArrayList<>();
        int starlineNum = curToken.getLineNum();
        Node node = null;

        //parse LVal
        node = parseLValExp();
        childNodes.add(node);
        //parse '=' 'getint' '('
        for (int i = 0; i < 3; i++) {
            Printer.getInstance().printToken(curToken);
            node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                    SyntaxVarType.TOKEN, childNodes, curToken);
            childNodes.add(node);
            advance();
        }
        //parse ')'
        if (curToken.getType() == TokenType.RPARENT) {
            Printer.getInstance().printToken(curToken);
            node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                    SyntaxVarType.TOKEN, childNodes, curToken);
            childNodes.add(node);
            advance();
        } else {
            Printer.getInstance().setHasError();
            Printer.getInstance().addError(node.getEndLineNum(), ErrorType.j);
        }

        //parse ';'
        if (curToken.getType() == TokenType.SEMICN) {
            Printer.getInstance().printToken(curToken);
            node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                    SyntaxVarType.TOKEN, childNodes, curToken);
            childNodes.add(node);
            advance();
        } else {
            Printer.getInstance().setHasError();
            Printer.getInstance().addError(node.getEndLineNum(), ErrorType.i);
        }

        int endLineNum = tokenStream.detect(-1).getLineNum();
        Printer.getInstance().printSyntaxVarType(SyntaxVarType.GETINT_STMT);
        return new GetIntStmt(starlineNum, endLineNum, SyntaxVarType.GETINT_STMT, childNodes);

    }

    //GetCharStmt: LVal '=' 'getchar' '(' ')' ';'
    //i型错误：缺少';'
    //j型错误：缺少')'
    public Node parseGetCharStmt() throws IOException {
        ArrayList<Node> childNodes = new ArrayList<>();
        int starlineNum = curToken.getLineNum();
        Node node = null;

        //parse LVal
        node = parseLValExp();
        childNodes.add(node);
        //parse '=' 'getchar' '('
        for (int i = 0; i < 3; i++) {
            Printer.getInstance().printToken(curToken);
            node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                    SyntaxVarType.TOKEN, childNodes, curToken);
            childNodes.add(node);
            advance();
        }
        //parse ')'
        if (curToken.getType() == TokenType.RPARENT) {
            Printer.getInstance().printToken(curToken);
            node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                    SyntaxVarType.TOKEN, childNodes, curToken);
            childNodes.add(node);
            advance();
        } else {
            Printer.getInstance().setHasError();
            Printer.getInstance().addError(node.getEndLineNum(), ErrorType.j);
        }

        //parse ';'
        if (curToken.getType() == TokenType.SEMICN) {
            Printer.getInstance().printToken(curToken);
            node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                    SyntaxVarType.TOKEN, childNodes, curToken);
            childNodes.add(node);
            advance();
        } else {
            Printer.getInstance().setHasError();
            Printer.getInstance().addError(node.getEndLineNum(), ErrorType.i);
        }

        int endLineNum = tokenStream.detect(-1).getLineNum();
        Printer.getInstance().printSyntaxVarType(SyntaxVarType.GETCHAR_STMT);
        return new GetCharStmt(starlineNum, endLineNum, SyntaxVarType.GETCHAR_STMT, childNodes);
    }

    //PrintfStmt: 'printf' '(' StringConst {',' Exp} ')' ';'
    //i型错误：缺少';'
    //j型错误：缺少')'
    public Node parsePrintfStmt() throws IOException {
        ArrayList<Node> childNodes = new ArrayList<>();
        int starlineNum = curToken.getLineNum();
        Node node = null;

        //parse 'printf' '(' StringConst
        for (int i = 0; i < 3; i++) {
            Printer.getInstance().printToken(curToken);
            node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                    SyntaxVarType.TOKEN, childNodes, curToken);
            childNodes.add(node);
            advance();
        }
        //parse {',' Exp}
        while (curToken.getType() == TokenType.COMMA) {
            //parse ','
            Printer.getInstance().printToken(curToken);
            node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                    SyntaxVarType.TOKEN, childNodes, curToken);
            childNodes.add(node);
            advance();
            //parse Exp
            node = parseExp();
            childNodes.add(node);
        }
        //parse ')'
        if (curToken.getType() == TokenType.RPARENT) {
            Printer.getInstance().printToken(curToken);
            node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                    SyntaxVarType.TOKEN, childNodes, curToken);
            childNodes.add(node);
            advance();
        } else {
            Printer.getInstance().setHasError();
            Printer.getInstance().addError(node.getEndLineNum(), ErrorType.j);
        }

        //parse ';'
        if (curToken.getType() == TokenType.SEMICN) {
            Printer.getInstance().printToken(curToken);
            node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                    SyntaxVarType.TOKEN, childNodes, curToken);
            childNodes.add(node);
            advance();
        } else {
            Printer.getInstance().setHasError();
            Printer.getInstance().addError(node.getEndLineNum(), ErrorType.i);
        }

        int endLineNum = tokenStream.detect(-1).getLineNum();
        Printer.getInstance().printSyntaxVarType(SyntaxVarType.PRINTF_STMT);
        return new PrintfStmt(starlineNum, endLineNum, SyntaxVarType.PRINTF_STMT, childNodes);
    }

    /************************ForStmt********************/
    //ForStmt -> LVal '=' Exp
    public Node parseFor_Stmt() throws IOException {
        ArrayList<Node> childNodes = new ArrayList<>();
        int starlineNum = curToken.getLineNum();
        Node node = null;

        //parse LVal
        node = parseLValExp();
        childNodes.add(node);
        //parse '='
        Printer.getInstance().printToken(curToken);
        node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                SyntaxVarType.TOKEN, childNodes, curToken);
        childNodes.add(node);
        advance();
        //parse Exp
        node = parseExp();
        childNodes.add(node);

        int endLineNum = tokenStream.detect(-1).getLineNum();
        Printer.getInstance().printSyntaxVarType(SyntaxVarType.FORSTMT);
        return new For_Stmt(starlineNum, endLineNum, SyntaxVarType.FORSTMT, childNodes);
    }

    /***********************Exp*********************/
    public Node parseExp() throws IOException {
        ArrayList<Node> childNodes = new ArrayList<>();
        int starlineNum = curToken.getLineNum();
        Node node = null;
        node = parseAddExp();
        childNodes.add(node);
        int endLineNum = tokenStream.detect(-1).getLineNum();
        Printer.getInstance().printSyntaxVarType(SyntaxVarType.EXP);
        return new Exp(starlineNum, endLineNum, SyntaxVarType.EXP, childNodes);
    }
    /***************************左值表达式************************/
    // LVal -> Ident [ '[' Exp ']' ]
    //k型错误：缺少']'
    public Node parseLValExp() throws IOException {
        ArrayList<Node> childNodes = new ArrayList<>();
        int starlineNum = curToken.getLineNum();
        Node node = null;
        //parse Ident
        System.out.println("parse LVal " + curToken.toString());
        Printer.getInstance().printToken(curToken);
        node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                SyntaxVarType.TOKEN, childNodes, curToken);
        childNodes.add(node);
        advance();
        //parse [ '[' Exp ']' ]
        //TODO: 改成If
        if (curToken.getType() == TokenType.LBRACK) {
            System.out.println("enter '[' Exp ']'");
            //parse '['
            Printer.getInstance().printToken(curToken);
            node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                    SyntaxVarType.TOKEN, childNodes, curToken);
            childNodes.add(node);
            advance();
            //parse Exp
            node = parseExp();
            childNodes.add(node);
            //parse ']'
            if (curToken.getType() == TokenType.RBRACK) {
                Printer.getInstance().printToken(curToken);
                node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                        SyntaxVarType.TOKEN, childNodes, curToken);
                childNodes.add(node);
                advance();
            } else {
                System.out.println("LVal: addError k");
                Printer.getInstance().setHasError();
                Printer.getInstance().addError(node.getEndLineNum(), ErrorType.k);
            }
        }
        int endLineNum = tokenStream.detect(-1).getLineNum();
        Printer.getInstance().printSyntaxVarType(SyntaxVarType.LVAL_EXP);
        return new LvalExp(starlineNum, endLineNum, SyntaxVarType.LVAL_EXP, childNodes);
    }

    /*************************条件表达式************************/
    //Cond -> LOrExp
    public Node parseCondExp() throws IOException {
        ArrayList<Node> childNodes = new ArrayList<>();
        int starlineNum = curToken.getLineNum();
        Node node = null;
        //parse LOrExp
        node = parseLorExp();
        childNodes.add(node);
        int endLineNum = tokenStream.detect(-1).getLineNum();
        Printer.getInstance().printSyntaxVarType(SyntaxVarType.COND_EXP);
        return new LvalExp(starlineNum, endLineNum, SyntaxVarType.COND_EXP, childNodes);
    }

    /***************************基本表达式*************************/
    //PrimaryExp -> '(' Exp ')' | LVal | Number | Character
    //j型错误：缺少')'
    public Node parsePrimaryExp() throws IOException {
        ArrayList<Node> childNodes = new ArrayList<>();
        int starlineNum = curToken.getLineNum();
        Node node = null;
        //parse '(' Exp ')'
        if (curToken.getType() == TokenType.LPARENT) {
            //parse '('
            Printer.getInstance().printToken(curToken);
            node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                    SyntaxVarType.TOKEN, childNodes, curToken);
            childNodes.add(node);
            advance();
            //parse Exp
            node = parseExp();
            childNodes.add(node);
            //parse ')'
            if (curToken.getType() == TokenType.RPARENT) {
                Printer.getInstance().printToken(curToken);
                node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                        SyntaxVarType.TOKEN, childNodes, curToken);
                childNodes.add(node);
                advance();
            } else {
                Printer.getInstance().setHasError();
                Printer.getInstance().addError(node.getEndLineNum(), ErrorType.j);
            }
        }
        //parse Number
        else if (curToken.getType() == TokenType.INTCON) {
            node = parseNumber();
            childNodes.add(node);
        }
        //parse Character
        else if (curToken.getType() == TokenType.CHRCON) {
            node = parseCharacter();
            childNodes.add(node);
        }
        //parse LVal
        else {
            node = parseLValExp();
            childNodes.add(node);
        }
        int endLineNum = tokenStream.detect(-1).getLineNum();
        Printer.getInstance().printSyntaxVarType(SyntaxVarType.PRIMARY_EXP);
        return new PrimaryExp(starlineNum, endLineNum, SyntaxVarType.PRIMARY_EXP, childNodes);
    }

    /*************************一元表达式************************/
    //UnaryExp -> PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
    //j型错误：缺少')'
    public Node parseUnaryExp() throws IOException {
        ArrayList<Node> childNodes = new ArrayList<>();
        int starlineNum = curToken.getLineNum();
        Node node = null;
        //parse Ident '(' [FuncRParams] ')'
        if (curToken.getType() == TokenType.IDENFR
            && tokenStream.detect(1).getType() == TokenType.LPARENT) {
            //parse Ident '('
            for (int i = 0; i < 2; i++) {
                Printer.getInstance().printToken(curToken);
                node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                        SyntaxVarType.TOKEN, childNodes, curToken);
                childNodes.add(node);
                advance();
            }
            if (isStartOfExp()) {
                node = parseFuncRParams();
                childNodes.add(node);
            }
            //parse ')'
            if (curToken.getType() == TokenType.RPARENT) {
                Printer.getInstance().printToken(curToken);
                node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                        SyntaxVarType.TOKEN, childNodes, curToken);
                childNodes.add(node);
                advance();
            } else {
                Printer.getInstance().setHasError();
                Printer.getInstance().addError(node.getEndLineNum(), ErrorType.j);
            }
        }
        //UnaryOp UnaryExp
        else if (curToken.getType() == TokenType.PLUS
                || curToken.getType() == TokenType.MINU
                || curToken.getType() == TokenType.NOT) {
            //parse UnaryOp
            node = parseUnaryOp();
            childNodes.add(node);
            //parse UnaryExp
            node = parseUnaryExp();
            childNodes.add(node);
        }
        //parse PrimaryExp
        else {
            node = parsePrimaryExp();
            childNodes.add(node);
        }
        int endLineNum = tokenStream.detect(-1).getLineNum();
        Printer.getInstance().printSyntaxVarType(SyntaxVarType.UNARY_EXP);
        return new UnaryExp(starlineNum, endLineNum, SyntaxVarType.UNARY_EXP, childNodes);
    }

    public Node parseUnaryOp() throws IOException {
        ArrayList<Node> childNodes = new ArrayList<>();
        int starlineNum = curToken.getLineNum();
        Node node = null;
        Printer.getInstance().printToken(curToken);
        node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                SyntaxVarType.TOKEN, childNodes, curToken);
        childNodes.add(node);
        advance();
        int endLineNum = tokenStream.detect(-1).getLineNum();
        Printer.getInstance().printSyntaxVarType(SyntaxVarType.UNARY_OP);
        return new UnaryOp(starlineNum, endLineNum, SyntaxVarType.UNARY_OP, childNodes);

    }
    /*******************乘除模表达式********************/
    //MulExp -> UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
    public Node parseMulExp() throws IOException {
        ArrayList<Node> childNodes = new ArrayList<>();
        int starlineNum = curToken.getLineNum();
        Node node = null;
        //parse UnaryExp
        node = parseUnaryExp();
        childNodes.add(node);

        while (curToken.getType() == TokenType.MULT
            || curToken.getType() == TokenType.DIV
            || curToken.getType() == TokenType.MOD) {
            Printer.getInstance().printSyntaxVarType(SyntaxVarType.MUL_EXP);
            Printer.getInstance().printToken(curToken);
            node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                    SyntaxVarType.TOKEN, childNodes, curToken);
            childNodes.add(node);
            advance();
            //parse UnaryExp
            node = parseUnaryExp();
            childNodes.add(node);
        }
        int endLineNum = tokenStream.detect(-1).getLineNum();
        Printer.getInstance().printSyntaxVarType(SyntaxVarType.MUL_EXP);
        return new MulExp(starlineNum, endLineNum, SyntaxVarType.MUL_EXP, childNodes);
    }


    public Node parseAddExp() throws IOException {
        ArrayList<Node> childNodes = new ArrayList<>();
        int starlineNum = curToken.getLineNum();
        Node node = null;
        //parse MulExp
        node = parseMulExp();
        childNodes.add(node);

        while (curToken.getType() == TokenType.PLUS
                || curToken.getType() == TokenType.MINU) {
            Printer.getInstance().printSyntaxVarType(SyntaxVarType.ADD_EXP);
            Printer.getInstance().printToken(curToken);
            node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                    SyntaxVarType.TOKEN, childNodes, curToken);
            childNodes.add(node);
            advance();
            //parse MulExp
            node = parseMulExp();
            childNodes.add(node);
        }
        int endLineNum = tokenStream.detect(-1).getLineNum();
        Printer.getInstance().printSyntaxVarType(SyntaxVarType.ADD_EXP);
        return new AddExp(starlineNum, endLineNum, SyntaxVarType.ADD_EXP, childNodes);
    }

    public Node parseRelExp() throws IOException {
        ArrayList<Node> childNodes = new ArrayList<>();
        int starlineNum = curToken.getLineNum();
        Node node = null;
        //parse AddExp
        node = parseAddExp();
        childNodes.add(node);

        while (curToken.getType() == TokenType.GRE
                || curToken.getType() == TokenType.LSS
                || curToken.getType() == TokenType.LEQ
                || curToken.getType() == TokenType.GEQ ) {
            Printer.getInstance().printSyntaxVarType(SyntaxVarType.REL_EXP);
            Printer.getInstance().printToken(curToken);
            node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                    SyntaxVarType.TOKEN, childNodes, curToken);
            childNodes.add(node);
            advance();
            //parse AddExp
            node = parseAddExp();
            childNodes.add(node);
        }
        int endLineNum = tokenStream.detect(-1).getLineNum();
        Printer.getInstance().printSyntaxVarType(SyntaxVarType.REL_EXP);
        return new RelExp(starlineNum, endLineNum, SyntaxVarType.REL_EXP, childNodes);
    }

    public Node parseEqExp() throws IOException {
        ArrayList<Node> childNodes = new ArrayList<>();
        int starlineNum = curToken.getLineNum();
        Node node = null;
        //parse RelExp
        node = parseRelExp();
        childNodes.add(node);

        while (curToken.getType() == TokenType.EQL
                || curToken.getType() == TokenType.NEQ) {
            Printer.getInstance().printSyntaxVarType(SyntaxVarType.EQ_EXP);
            Printer.getInstance().printToken(curToken);
            node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                    SyntaxVarType.TOKEN, childNodes, curToken);
            childNodes.add(node);
            advance();
            //parse RelExp
            node = parseRelExp();
            childNodes.add(node);
        }
        int endLineNum = tokenStream.detect(-1).getLineNum();
        Printer.getInstance().printSyntaxVarType(SyntaxVarType.EQ_EXP);
        return new EqExp(starlineNum, endLineNum, SyntaxVarType.EQ_EXP, childNodes);
    }

    public Node parseLAndExp() throws IOException {
        ArrayList<Node> childNodes = new ArrayList<>();
        int starlineNum = curToken.getLineNum();
        Node node = null;
        //parse EqExp
        node = parseEqExp();
        childNodes.add(node);

        while (curToken.getType() == TokenType.AND) {
            Printer.getInstance().printSyntaxVarType(SyntaxVarType.LAND_EXP);
            Printer.getInstance().printToken(curToken);
            node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                    SyntaxVarType.TOKEN, childNodes, curToken);
            childNodes.add(node);
            advance();
            //parse EqExp
            node = parseEqExp();
            childNodes.add(node);
        }
        int endLineNum = tokenStream.detect(-1).getLineNum();
        Printer.getInstance().printSyntaxVarType(SyntaxVarType.LAND_EXP);
        return new LandExp(starlineNum, endLineNum, SyntaxVarType.LAND_EXP, childNodes);
    }

    public Node parseLorExp() throws IOException {
        ArrayList<Node> childNodes = new ArrayList<>();
        int starlineNum = curToken.getLineNum();
        Node node = null;
        //parse LAndExp
        node = parseLAndExp();
        childNodes.add(node);

        while (curToken.getType() == TokenType.OR) {
            Printer.getInstance().printSyntaxVarType(SyntaxVarType.LOR_EXP);
            Printer.getInstance().printToken(curToken);
            node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                    SyntaxVarType.TOKEN, childNodes, curToken);
            childNodes.add(node);
            advance();
            //parse LAndExp
            node = parseLAndExp();
            childNodes.add(node);
        }
        int endLineNum = tokenStream.detect(-1).getLineNum();
        Printer.getInstance().printSyntaxVarType(SyntaxVarType.LOR_EXP);
        return new LorExp(starlineNum, endLineNum, SyntaxVarType.LOR_EXP, childNodes);
    }

    public Node parseConstExp() throws IOException {
        ArrayList<Node> childNodes = new ArrayList<>();
        int starlineNum = curToken.getLineNum();
        Node node = null;
        node = parseAddExp();
        childNodes.add(node);
        int endLineNum = tokenStream.detect(-1).getLineNum();
        Printer.getInstance().printSyntaxVarType(SyntaxVarType.CONST_EXP);
        return new ConstExp(starlineNum, endLineNum, SyntaxVarType.CONST_EXP, childNodes);
    }

    public Node parseNumber() throws IOException {
        ArrayList<Node> childNodes = new ArrayList<>();
        int starlineNum = curToken.getLineNum();
        Node node = null;
        Printer.getInstance().printToken(curToken);
        node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                SyntaxVarType.TOKEN, childNodes, curToken);
        childNodes.add(node);
        advance();
        int endLineNum = tokenStream.detect(-1).getLineNum();
        Printer.getInstance().printSyntaxVarType(SyntaxVarType.NUMBER);
        return new Number(starlineNum, endLineNum, SyntaxVarType.NUMBER, childNodes);
    }

    public Node parseCharacter() throws IOException {
        ArrayList<Node> childNodes = new ArrayList<>();
        int starlineNum = curToken.getLineNum();
        Node node = null;
        Printer.getInstance().printToken(curToken);
        node = new TokenNode(curToken.getLineNum(), curToken.getLineNum(),
                SyntaxVarType.TOKEN, childNodes, curToken);
        childNodes.add(node);
        advance();
        int endLineNum = tokenStream.detect(-1).getLineNum();
        Printer.getInstance().printSyntaxVarType(SyntaxVarType.CHARACTER);
        return new Character(starlineNum, endLineNum, SyntaxVarType.CHARACTER, childNodes);
    }

    public boolean isStartOfExp () {
        return curToken.getType() == TokenType.PLUS ||
                curToken.getType() == TokenType.MINU ||
                curToken.getType() == TokenType.NOT ||
                curToken.getType() == TokenType.IDENFR ||
                curToken.getType() == TokenType.LPARENT ||
                curToken.getType() == TokenType.INTCON ||
                curToken.getType() == TokenType.CHRCON;
    }
}
