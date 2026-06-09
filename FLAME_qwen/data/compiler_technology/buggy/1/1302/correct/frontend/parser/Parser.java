package frontend.parser;

import frontend.error.ErrorList;
import frontend.lexer.LexType;
import frontend.lexer.Token;
import frontend.tree.CompUnit;
import frontend.tree.Node;
import frontend.tree.decl.*;
import frontend.tree.exp.*;
import frontend.tree.exp.Character;
import frontend.tree.exp.Number;
import frontend.tree.func.*;

import java.util.ArrayList;

public class Parser {
    private final ArrayList<Token> tokens;
    private int curTokenIndex;
    private Token curToken;

    public Parser(ArrayList<Token> tokens) {
        this.tokens = tokens;
        curTokenIndex = 0;
        curToken = tokens.get(curTokenIndex);
    }

    public void next() {
        curTokenIndex++;
        if (curTokenIndex < tokens.size()) {
            curToken = tokens.get(curTokenIndex);
        } else {
            curToken = null;
        }
    }

    public void backTo(int index) {
        curTokenIndex = index;
        curToken = tokens.get(curTokenIndex);
    }

    public Token peekOffset(int i) {
        if (curTokenIndex + i < tokens.size()) {
            return tokens.get(curTokenIndex + i);
        } else {
            return null;
        }
    }

    /**
     * CompUnit → {Decl} {FuncDef} MainFuncDef
     * @return CompUnit
     */
    public Node parseCompUnit() {
        Node root = new CompUnit(); root.setBeginLine(curToken.getLineNum());
        while (curToken != null) {
            Node child = null;
            if (peekOffset(1).getLexType() == LexType.MAINTK) {
                child = parseMainFuncDef();
            } else if(peekOffset(2).getLexType() == LexType.LPARENT) {
                child = parseFuncDef();
            } else if (curToken.getLexType() == LexType.CONSTTK) {
                child = parseConstDecl();
            } else if (isBType(curToken.getLexType())) {
                child = parseVarDecl();
            } else {
                System.out.println("Error: parseCompUnit error");
            }

            if (child != null) {
                root.addChild(child);
            }
        }
        root.setEndLine(peekOffset(-1).getLineNum());
        return root;
    }

    /**
     *  ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';'
     *  Error: i
     * @return ConstDecl
     */
    private Node parseConstDecl() {
        Node root = new ConstDecl(); root.setBeginLine(curToken.getLineNum());
        root.addChild(curToken); next(); // const
        root.addChild(curToken); next(); // int | char
        Node child = parseConstDef();
        root.addChild(child);
        while (curToken.getLexType() == LexType.COMMA) {
            root.addChild(curToken); next(); // ,
            child = parseConstDef();
            root.addChild(child);
        }
        if (curToken.getLexType() == LexType.SEMICN) {
            root.addChild(curToken); next();
        } else {
            ErrorList.getInstance().addError("i", peekOffset(-1).getLineNum());
        }
        root.setEndLine(peekOffset(-1).getLineNum());
        return root;
    }

    /**
     * ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal
     * Error: (b) k
     * @return ConstDef
     */
    public Node parseConstDef() {
        Node root = new ConstDef(); root.setBeginLine(curToken.getLineNum());
        root.addChild(curToken); next(); // identifier
        if (curToken.getLexType() == LexType.LBRACK) { // [
            root.addChild(curToken); next();
            Node child = parseConstExp(); // ConstExp
            root.addChild(child);
            if (curToken.getLexType() == LexType.RBRACK) { // ]
                root.addChild(curToken); next();
            } else {
                ErrorList.getInstance().addError("k", peekOffset(-1).getLineNum());
            }
        }
        root.addChild(curToken); next(); // =
        Node child = parseConstInitVal(); // ConstInitVal
        root.addChild(child);
        root.setEndLine(peekOffset(-1).getLineNum());
        return root;
    }

    /**
     *  ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
     * @return ConstInitVal
     */
    public Node parseConstInitVal() {
        Node root = new ConstInitVal(); root.setBeginLine(curToken.getLineNum());
        if (isConstExpFirst(curToken.getLexType())) {
            root.addChild(parseConstExp());
        } else if (curToken.getLexType() == LexType.LBRACE) {
            root.addChild(curToken); next(); // {
            if (isConstExpFirst(curToken.getLexType())) {
                root.addChild(parseConstExp());
                while (curToken.getLexType() == LexType.COMMA) {
                    root.addChild(curToken); next();// ,
                    root.addChild(parseConstExp());
                }
            }
            root.addChild(curToken); next(); // }
        } else if (curToken.getLexType() == LexType.STRCON) {
            root.addChild(curToken); next(); // StringConst
        } else {
            System.out.println("Error: parseConstInitVal at line " + curToken.getLineNum());;
        }
        root.setEndLine(peekOffset(-1).getLineNum());
        return root;
    }

    /**
     * VarDecl → BType VarDef { ',' VarDef } ';'
     * Error: i
     * @return VarDecl
     */
    private Node parseVarDecl() {
        Node root = new VarDecl(); root.setBeginLine(curToken.getLineNum());
        root.addChild(curToken); next(); // int | char
        Node child = parseVarDef();
        root.addChild(child);
        while (curToken.getLexType() == LexType.COMMA) {
            root.addChild(curToken); next(); // ,
            child = parseVarDef();
            root.addChild(child);
        }
        if (curToken.getLexType() == LexType.SEMICN) {
            root.addChild(curToken); next(); // ;
        } else {
            ErrorList.getInstance().addError("i", peekOffset(-1).getLineNum());
        }
        return root;
    }

    /**
     * VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal
     * Error: (b) k
     * @return VarDef
     */
    private Node parseVarDef() {
        Node root = new VarDef(); root.setBeginLine(curToken.getLineNum());
        root.addChild(curToken); // identifier
        next();
        if (curToken.getLexType() == LexType.LBRACK) { // [
            root.addChild(curToken); next(); // [
            Node child = parseConstExp(); // ConstExp
            root.addChild(child);
            if (curToken.getLexType() == LexType.RBRACK) { // ]
                root.addChild(curToken);
                next();
            } else {
                ErrorList.getInstance().addError("k", peekOffset(-1).getLineNum());
            }
        }
        if (curToken.getLexType() == LexType.ASSIGN) { // =
            root.addChild(curToken); next(); // =
            Node child = parseInitVal(); // InitVal
            root.addChild(child);
        }
        root.setEndLine(peekOffset(-1).getLineNum());
        return root;
    }

    /**
     * InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
     * @return InitVal
     */
    private Node parseInitVal() {
        Node root = new InitVal(); root.setBeginLine(curToken.getLineNum());
        if (isExpFirst(curToken.getLexType())) {
            root.addChild(parseExp());
        } else if (curToken.getLexType() == LexType.LBRACE) {
            root.addChild(curToken); next(); // {
            root.addChild(parseExp());
            while (curToken.getLexType() == LexType.COMMA) {
                root.addChild(curToken); next(); // ,
                root.addChild(parseExp());
            }
            root.addChild(curToken); next(); // }
        } else if (curToken.getLexType() == LexType.STRCON) {
            root.addChild(curToken); next();
        } else {
            System.out.println("Error: parseInitVal at line " + curToken.getLineNum());
        }
        root.setEndLine(peekOffset(-1).getLineNum());
        return root;
    }

    /**
     * FuncDef → FuncType Ident '(' [FuncFParams] ')' Block
     * Error: (b) (g) j
     * @return FuncDef
     */
    private Node parseFuncDef() {
        Node root = new FuncDef(); root.setBeginLine(curToken.getLineNum());
        FuncType funcType = parseFuncType();
        root.addChild(funcType); // FuncType
        root.addChild(curToken); next(); // identifier
        if (curToken.getLexType() == LexType.LPARENT) {
            root.addChild(curToken); next(); // (
            if (isFuncFParamsFirst(curToken.getLexType())) {
                root.addChild(parseFuncFParams());
            }
            if (curToken.getLexType() == LexType.RPARENT) {
                root.addChild(curToken); next(); // )
            } else {
                ErrorList.getInstance().addError("j", peekOffset(-1).getLineNum());
            }
        }
        Node child = parseBlock();
        root.addChild(child);
//        if (funcType.hasReturn() && ((Block) child).hasReturn()) {
//            root.addChild(child);
//        } else {
//            ErrorList.getInstance().addError("k", peekOffset(-1).getLineNum());
//        }
        root.setEndLine(peekOffset(-1).getLineNum());
        return root;
    }

    /**
     * MainFuncDef → 'int' 'main' '(' ')' Block
     * Error: (g) j
     * @return
     */
    private Node parseMainFuncDef() {
        Node root = new MainFuncDef(); root.setBeginLine(curToken.getLineNum());
        root.addChild(curToken); next(); // int
        root.addChild(curToken); next(); // main
        root.addChild(curToken); next(); // (
        if (curToken.getLexType() == LexType.RPARENT) {
            root.addChild(curToken); next(); // )
        } else {
            ErrorList.getInstance().addError("j", peekOffset(-1).getLineNum());
        }
        Node child = parseBlock();
        root.addChild(child);
        root.setEndLine(peekOffset(-1).getLineNum());
        return root;
    }

    /**
     * FuncType → 'int' | 'char' | 'void'
     * @return FuncType
     */
    public FuncType parseFuncType() {
        FuncType root = new FuncType(); root.setBeginLine(curToken.getLineNum());
        if (curToken.getLexType() == LexType.INTTK) {
            root.addChild(curToken); next(); // int
        } else if (curToken.getLexType() == LexType.CHARTK) {
            root.addChild(curToken); next(); // char
        } else if (curToken.getLexType() == LexType.VOIDTK) {
            root.addChild(curToken); next(); // void
        } else {
            System.out.println("Error: parseFuncType at line " + curToken.getLineNum());
        }
        root.setEndLine(peekOffset(-1).getLineNum());
        return root;
    }

    /**
     * FuncFParams → FuncFParam { ',' FuncFParam }
     * @return FuncFParams
     */
    private Node parseFuncFParams() {
        Node root = new FuncFParams(); root.setBeginLine(curToken.getLineNum());
        Node child = parseFuncFParam();
        root.addChild(child);
        while (curToken.getLexType() == LexType.COMMA) {
            root.addChild(curToken); next(); // ,
            child = parseFuncFParam();
            root.addChild(child);
        }
        root.setEndLine(peekOffset(-1).getLineNum());
        return root;
    }

    /**
     *  FuncFParam → BType Ident ['[' ']']
     *  Error: (b) k
     *  @return FuncFParam
     */
    public Node parseFuncFParam() {
        Node root = new FuncFParam(); root.setBeginLine(curToken.getLineNum());
        root.addChild(curToken); next(); // int | char
        root.addChild(curToken); next(); // identifier
        if (curToken.getLexType() == LexType.LBRACK) { // [
            root.addChild(curToken); next(); // [
            if (curToken.getLexType() == LexType.RBRACK) {
                root.addChild(curToken); next(); // ]
            } else {
                ErrorList.getInstance().addError("k", peekOffset(-1).getLineNum());
            }
        }
        root.setEndLine(peekOffset(-1).getLineNum());
        return root;
    }

    /**
     * Block → '{' { BlockItem } '}'
     * @return Block
     */
    public Node parseBlock() {
        Node root = new Block(); root.setBeginLine(curToken.getLineNum());
        root.addChild(curToken); next(); // {
        while (curToken.getLexType() != LexType.RBRACE) {
            if (curToken.getLexType() == LexType.CONSTTK) {
                root.addChild(parseConstDecl());
            } else if (isBType(curToken.getLexType())) {
                root.addChild(parseVarDecl());
            } else {
                root.addChild(parseStmt());
            }
        }
        root.addChild(curToken); next(); // }
        root.setEndLine(peekOffset(-1).getLineNum());
        return root;
    }

    /**
     * Stmt → LVal '=' Exp ';' // i
     * | [Exp] ';' // i
     * | Block
     * | 'if' '(' Cond ')' Stmt [ 'else' Stmt ] // j
     * | 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
     * | 'break' ';' | 'continue' ';' // i
     * | 'return' [Exp] ';' // i
     * | LVal '=' 'getint''('')'';' // i j
     * | LVal '=' 'getchar''('')'';' // i j
     * | 'printf''('StringConst {','Exp}')'';' // i j
     * 注意：LVal {Ident ['[' Exp ']']}和Exp{LVal, Ident '(' [FuncRParams] ')'）}的First集合有相同的Token
     * Error: (f) (h) i j (m)
     * @return Stmt
     */
    public Node parseStmt() {
        Node root = new Stmt(); root.setBeginLine(curToken.getLineNum());
        if (curToken.getLexType() == LexType.IDENFR && peekOffset(1).getLexType() != LexType.LPARENT) {
            int flagIndex = curTokenIndex;
            Node child = parseLVal();
            root.addChild(child);
            if (curToken.getLexType() == LexType.ASSIGN) {
                root.addChild(curToken); next(); // =
                if (curToken.getLexType() == LexType.GETINTTK || curToken.getLexType() == LexType.GETCHARTK) {
                    root.addChild(curToken);
                    next(); // getint | getchar
                    root.addChild(curToken);
                    next(); // (
                    if (curToken.getLexType() == LexType.RPARENT) {
                        root.addChild(curToken);
                        next(); // )
                    } else {
                        ErrorList.getInstance().addError("j", peekOffset(-1).getLineNum());
                    }
                } else {
                    root.addChild(parseExp());
                }
                if (curToken.getLexType() == LexType.SEMICN) {
                    root.addChild(curToken);
                    next(); // ;
                } else {
                    ErrorList.getInstance().addError("i", peekOffset(-1).getLineNum());
                }
            } else { // Exp
                backTo(flagIndex); root.removeChild(child); //回退
                root.addChild(parseExp());
                if (curToken.getLexType() == LexType.SEMICN) {
                    root.addChild(curToken); next(); // ;
                } else {
                    ErrorList.getInstance().addError("i", peekOffset(-1).getLineNum());
                }
            }
        } else if (curToken.getLexType() == LexType.LBRACE) {
            root.addChild(parseBlock());
        } else if (curToken.getLexType() == LexType.IFTK) {
            root.addChild(curToken); next(); // if
            root.addChild(curToken); next(); // (
            Node child = parseCond(); // Cond
            root.addChild(child);
            if (curToken.getLexType() == LexType.RPARENT) {
                root.addChild(curToken); next(); // )
            } else {
                ErrorList.getInstance().addError("j", peekOffset(-1).getLineNum());
            }
            Node child2 = parseStmt(); // Stmt
            root.addChild(child2);
            if (curToken.getLexType() == LexType.ELSETK) {
                root.addChild(curToken); next(); // else
                Node child3 = parseStmt(); // Stmt
                root.addChild(child3);
            }
        } else if (curToken.getLexType() == LexType.FORTK) {
            root.addChild(curToken); next(); // for
            root.addChild(curToken); next(); // (
            if (curToken.getLexType() != LexType.SEMICN) {
                root.addChild(parseForStmt());
            }
            root.addChild(curToken); next(); // ;
            if (curToken.getLexType() != LexType.SEMICN) {
                root.addChild(parseCond());
            }
            root.addChild(curToken); next(); // ;
            if (curToken.getLexType() != LexType.RPARENT) {
                root.addChild(parseForStmt());
            }
            root.addChild(curToken); next(); // )
            Node child = parseStmt(); // Stmt
            root.addChild(child);
        } else if (curToken.getLexType() == LexType.BREAKTK || curToken.getLexType() == LexType.CONTINUETK) {
            root.addChild(curToken); next(); // break | continue
            if (curToken.getLexType() == LexType.SEMICN) {
                root.addChild(curToken); next(); // ;
            } else {
                ErrorList.getInstance().addError("i", peekOffset(-1).getLineNum());
            }
        } else if (curToken.getLexType() == LexType.RETURNTK) {
            root.addChild(curToken); next(); // return
            if (isExpFirst(curToken.getLexType())) {
                root.addChild(parseExp());
            }
            if (curToken.getLexType() == LexType.SEMICN) {
                root.addChild(curToken);
                next(); // ;
            } else {
                ErrorList.getInstance().addError("i", peekOffset(-1).getLineNum());
            }
        } else if (curToken.getLexType() == LexType.PRINTFTK) {
            root.addChild(curToken); next(); // printf
            root.addChild(curToken); next(); // (
            root.addChild(curToken); next(); // StringConst
            while (curToken.getLexType() == LexType.COMMA) {
                root.addChild(curToken); next(); // ,
                root.addChild(parseExp());
            }
            if (curToken.getLexType() == LexType.RPARENT) {
                root.addChild(curToken); next(); // )
            } else {
                ErrorList.getInstance().addError("j", peekOffset(-1).getLineNum());
            }
            if (curToken.getLexType() == LexType.SEMICN) {
                root.addChild(curToken); next(); // ;
            } else {
                ErrorList.getInstance().addError("i", peekOffset(-1).getLineNum());
            }
        } else if (isExpFirst(curToken.getLexType())) {
            root.addChild(parseExp());
            if (curToken.getLexType() == LexType.SEMICN) {
                root.addChild(curToken); next(); // ;
            } else {
                ErrorList.getInstance().addError("i", peekOffset(-1).getLineNum());
            }
        } else if (curToken.getLexType() == LexType.SEMICN) {
            root.addChild(curToken); next(); // ;
        } else {
            System.out.println("Error: parseStmt error at line" + curToken.getLineNum());
        }
        return root;
    }

    /**
     *  ForStmt → LVal '=' Exp
     *  Error: h
     * @return ForStmt
     */
    public Node parseForStmt() {
        Node root = new ForStmt(); root.setBeginLine(curToken.getLineNum());
        root.addChild(parseLVal());
        root.addChild(curToken); next(); // =
        root.addChild(parseExp());
        root.setEndLine(peekOffset(-1).getLineNum());
        return root;
    }

    /**
     * Exp → AddExp
     * @return Exp
     */
    public Node parseExp() {
        Node root = new Exp(); root.setBeginLine(curToken.getLineNum());
        root.addChild(parseAddExp());
        root.setEndLine(peekOffset(-1).getLineNum());
        return root;
    }

    /**
     * Cond → LOrExp
     * @return Cond
     */
    public Node parseCond() {
        Node root = new Cond(); root.setBeginLine(curToken.getLineNum());
        root.addChild(parseLOrExp());
        root.setEndLine(peekOffset(-1).getLineNum());
        return root;
    }

    /**
     * LVal → Ident ['[' Exp ']']
     * Error: c k
     * @return LVal
     */
    public Node parseLVal() {
        Node root = new LVal();
        root.setBeginLine(curToken.getLineNum());
        root.addChild(curToken);
        next(); // identifier
        if (curToken.getLexType() == LexType.LBRACK) { // [
            root.addChild(curToken);
            next(); // [
            Node child = parseExp(); // Exp
            root.addChild(child);
            if (curToken.getLexType() == LexType.RBRACK) { // ]
                root.addChild(curToken);
                next();
            } else {
                ErrorList.getInstance().addError("k", peekOffset(-1).getLineNum());
            }
        }
        root.setEndLine(peekOffset(-1).getLineNum());
        return root;
    }

    /**
     * PrimaryExp → '(' Exp ')' | LVal | Number | Character
     * Error: j
     * @return PrimaryExp
     */
    public Node parsePrimaryExp() {
        Node root = new PrimaryExp(); root.setBeginLine(curToken.getLineNum());
        if (curToken.getLexType() == LexType.LPARENT) { // (
            root.addChild(curToken); next(); // (
            Node child = parseExp(); // Exp
            root.addChild(child);
            if (curToken.getLexType() == LexType.RPARENT) { // )
                root.addChild(curToken); next(); // )
            } else {
                ErrorList.getInstance().addError("j", peekOffset(-1).getLineNum());
            }
        } else if (curToken.getLexType() == LexType.IDENFR) {
            root.addChild(parseLVal());
        } else if (curToken.getLexType() == LexType.INTCON) {
            root.addChild(parseNumber());
        } else if (curToken.getLexType() == LexType.CHRCON) {
            root.addChild(parseCharacter());
        } else {
            System.out.println("Error: parsePrimaryExp error at line" + curToken.getLineNum());
        }
        root.setEndLine(peekOffset(-1).getLineNum());
        return root;
    }

    /**
     * Number → IntConst
     * @return Number
     */
    public Node parseNumber() {
        Node root = new Number(); root.setBeginLine(curToken.getLineNum());
        root.addChild(curToken); next(); // IntConst
        root.setEndLine(peekOffset(-1).getLineNum());
        return root;
    }

    /**
     * Character → CharConst
     * @return Character
     */
    public Node parseCharacter() {
        Node root = new Character(); root.setBeginLine(curToken.getLineNum());
        root.addChild(curToken); next(); // CharConst
        root.setEndLine(peekOffset(-1).getLineNum());
        return root;
    }

    /**
     * UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
     * Error: c d e j
     */
    public Node parseUnaryExp() {
        Node root = new UnaryExp(); root.setBeginLine(curToken.getLineNum());
        if (curToken.getLexType() == LexType.IDENFR && peekOffset(1).getLexType() == LexType.LPARENT) {
            root.addChild(curToken); next(); // identifier
            root.addChild(curToken); next(); // (
            if (isExpFirst(curToken.getLexType())) {
                root.addChild(parseFuncRParams());
            }
            if (curToken.getLexType() == LexType.RPARENT) {
                root.addChild(curToken); next(); // )
            } else {
                ErrorList.getInstance().addError("j", peekOffset(-1).getLineNum());
            }
        } else if (isUnaryOpFirst(curToken.getLexType())) {
            root.addChild(parseUnaryOp());
            root.addChild(parseUnaryExp());
        } else if (isPrimaryExpFirst(curToken.getLexType())) {
            root.addChild(parsePrimaryExp());
        } else {
            System.out.println("Error: parseUnaryExp error at line" + curToken.getLineNum());
        }
        root.setEndLine(peekOffset(-1).getLineNum());
        return root;
    }

    /**
     *  UnaryOp → '+' | '−' | '!' 注：'!'仅出现在条件表达式中
     *  @return UnaryOp
     */
    public Node parseUnaryOp() {
        Node root = new UnaryOp(); root.setBeginLine(curToken.getLineNum());
        root.addChild(curToken); next(); // + | - | !
        root.setEndLine(peekOffset(-1).getLineNum());
        return root;
    }

    /**
     * FuncRParams → Exp { ',' Exp }
     * @return FuncRParams
     */
    public Node parseFuncRParams() {
        Node root = new FuncRParams(); root.setBeginLine(curToken.getLineNum());
        Node child = parseExp();
        root.addChild(child);
        while (curToken.getLexType() == LexType.COMMA) {
            root.addChild(curToken); next(); // ,
            child = parseExp();
            root.addChild(child);
        }
        root.setEndLine(peekOffset(-1).getLineNum());
        return root;
    }

    /**
     *  MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
     *  @return MulExp
     */
    public Node parseMulExp() {
        Node root = new MulExp(); root.setBeginLine(curToken.getLineNum());
        Node child = parseUnaryExp();
        root.addChild(child);
        while (curToken.getLexType() == LexType.MULT || curToken.getLexType() == LexType.DIV || curToken.getLexType() == LexType.MOD) {
            Node oldRoot = root;
            root = new MulExp(); root.setBeginLine(oldRoot.getBeginLine()); root.setEndLine(oldRoot.getEndLine());
            root.addChild(oldRoot);

            root.addChild(curToken); next(); // * | / | %

            child = parseUnaryExp();
            root.addChild(child);
        }
        root.setEndLine(peekOffset(-1).getLineNum());
        return root;
    }

    /**
     * AddExp → MulExp | AddExp ('+' | '−') MulExp
     */
    public Node parseAddExp() {
        Node root = new AddExp(); root.setBeginLine(curToken.getLineNum());
        Node child = parseMulExp();
        root.addChild(child);
        while (curToken.getLexType() == LexType.PLUS || curToken.getLexType() == LexType.MINU) {
            Node oldRoot = root;
            root = new AddExp(); root.setBeginLine(oldRoot.getBeginLine()); root.setEndLine(oldRoot.getEndLine());
            root.addChild(oldRoot);

            root.addChild(curToken); next(); // + | -
            child = parseMulExp();
            root.addChild(child);
        }
        root.setEndLine(peekOffset(-1).getLineNum());
        return root;
    }

    /**
     * RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
     * @return RelExp
     */
    public Node parseRelExp() {
        Node root = new RelExp(); root.setBeginLine(curToken.getLineNum());
        Node child = parseAddExp();
        root.addChild(child);
        while (curToken.getLexType() == LexType.LSS || curToken.getLexType() == LexType.GRE || curToken.getLexType() == LexType.LEQ || curToken.getLexType() == LexType.GEQ) {
            Node oldRoot = root;
            root = new RelExp(); root.setBeginLine(oldRoot.getBeginLine()); root.setEndLine(oldRoot.getEndLine());
            root.addChild(oldRoot);

            root.addChild(curToken); next(); // < | > | <= | >=
            child = parseAddExp();
            root.addChild(child);
        }
        root.setEndLine(peekOffset(-1).getLineNum());
        return root;
    }

    /**
     * EqExp → RelExp | EqExp ('==' | '!=') RelExp
     * @return EqExp
     */
    public Node parseEqExp() {
        Node root = new EqExp(); root.setBeginLine(curToken.getLineNum());
        Node child = parseRelExp();
        root.addChild(child);
        while (curToken.getLexType() == LexType.EQL || curToken.getLexType() == LexType.NEQ) {
            Node oldRoot = root;
            root = new EqExp(); root.setBeginLine(oldRoot.getBeginLine()); root.setEndLine(oldRoot.getEndLine());
            root.addChild(oldRoot);

            root.addChild(curToken); next(); // == | !=
            child = parseRelExp();
            root.addChild(child);
        }
        root.setEndLine(peekOffset(-1).getLineNum());
        return root;
    }

    /**
     * LAndExp → EqExp | LAndExp '&&' EqExp
     * @return LAndExp
     */
    public Node parseLAndExp() {
        Node root = new LAndExp(); root.setBeginLine(curToken.getLineNum());
        Node child = parseEqExp();
        root.addChild(child);
        while (curToken.getLexType() == LexType.AND) {
            Node oldRoot = root;
            root = new LAndExp(); root.setBeginLine(oldRoot.getBeginLine()); root.setEndLine(oldRoot.getEndLine());
            root.addChild(oldRoot);

            root.addChild(curToken); next(); // &&
            child = parseEqExp();
            root.addChild(child);
        }
        root.setEndLine(peekOffset(-1).getLineNum());
        return root;
    }

    /**
     * LOrExp → LAndExp | LOrExp '||' LAndExp
     * @return LOrExp
     */
    public Node parseLOrExp() {
        Node root = new LOrExp(); root.setBeginLine(curToken.getLineNum());
        Node child = parseLAndExp();
        root.addChild(child);
        while (curToken.getLexType() == LexType.OR) {
            Node oldRoot = root;
            root = new LOrExp(); root.setBeginLine(oldRoot.getBeginLine()); root.setEndLine(oldRoot.getEndLine());
            root.addChild(oldRoot);

            root.addChild(curToken); next(); // ||
            child = parseLAndExp();
            root.addChild(child);
        }
        root.setEndLine(peekOffset(-1).getLineNum());
        return root;
    }

    /**
     * ConstExp → AddExp 注：使用的 Ident 必须是常量
     */
    public Node parseConstExp() {
        Node root = new ConstExp(); root.setBeginLine(curToken.getLineNum());
        Node child = parseAddExp();
        root.addChild(child);
        root.setEndLine(peekOffset(-1).getLineNum());
        return root;
    }

    private boolean isBType(LexType type) {
        return type == LexType.INTTK || type == LexType.CHARTK;
    }

    private boolean isFuncFParamsFirst(LexType type) {
        return type == LexType.VOIDTK || isBType(type);
    }

    private boolean isExpFirst(LexType type) {
        return isPrimaryExpFirst(type) || isUnaryOpFirst(type);
    }

    private boolean isPrimaryExpFirst(LexType type) {
        return type == LexType.LPARENT || type == LexType.IDENFR || type == LexType.INTCON || type == LexType.CHRCON;
    }

    private boolean isUnaryOpFirst(LexType type) {
        return type == LexType.PLUS || type == LexType.MINU || type == LexType.NOT;
    }

    private boolean isConstExpFirst(LexType type) {
        return isPrimaryExpFirst(type) || type == LexType.IDENFR|| isUnaryOpFirst(type);
    }
}