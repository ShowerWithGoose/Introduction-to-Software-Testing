package frontend;

import error.ErrorCode;
import error.ErrorType;
import node.SyntaxTreeNode;
import token.Token;
import token.TokenType;
import node.NodeType;

import java.util.*;

public class Parser {
    private final Lexer lexer;
    private Map<Integer,ErrorCode> errors;

    public Parser(Lexer lexer) {
        this.lexer = lexer;
        this.errors = new TreeMap<>();
    }
    public SyntaxTreeNode parseCompUnit() {
        List<SyntaxTreeNode> subNodes = new ArrayList<>();
        while (getTokenByOff(0).getType() == TokenType.CONSTTK
                || ((getTokenByOff(0).getType() == TokenType.INTTK || getTokenByOff(0).getType() == TokenType.CHARTK)
                && getTokenByOff(1).getType() == TokenType.IDENFR && getTokenByOff(2).getType() != TokenType.LPARENT)) {
                if (getTokenByOff(0).getType() == TokenType.CONSTTK) {
                    subNodes.add(parseConstDecl());
                } else {
                    subNodes.add(parseVarDecl());
                }
        }
        while ((getTokenByOff(0).getType() == TokenType.INTTK || getTokenByOff(0).getType() == TokenType.CHARTK
                || getTokenByOff(0).getType() == TokenType.VOIDTK) && getTokenByOff(1).getType() != TokenType.MAINTK) {
            subNodes.add(parseFuncDef());
        }
        subNodes.add(parseMainFuncDef());
        return new SyntaxTreeNode(NodeType.COMP_UNIT,subNodes);
    }

    private SyntaxTreeNode parseMainFuncDef() {
        //MainFuncDef → 'int' 'main' '(' ')' Block // j
        List<SyntaxTreeNode> subNodes = new ArrayList<>();
        match(TokenType.INTTK,subNodes);
        match(TokenType.MAINTK,subNodes);
        match(TokenType.LPARENT,subNodes);
        match(TokenType.RPARENT,subNodes);
        subNodes.add(parseBlock());
        return new SyntaxTreeNode(NodeType.MAIN_FUNC_DEF,subNodes);
    }

    private SyntaxTreeNode parseBlock() {
        // Block → '{' { (ConstDecl | VarDecl | Stmt) } '}'
        List<SyntaxTreeNode> subNodes = new ArrayList<>();
        match(TokenType.LBRACE,subNodes);
        while (getTokenByOff(0).getType() != TokenType.RBRACE) {
            if (getTokenByOff(0).getType() == TokenType.CONSTTK) {
                subNodes.add(parseConstDecl());
            } else if (getTokenByOff(0).getType() == TokenType.INTTK || getTokenByOff(0).getType() == TokenType.CHARTK){
                subNodes.add(parseVarDecl());
            } else {
                subNodes.add(parseStmt());
            }
        }
        match(TokenType.RBRACE,subNodes);
        return new SyntaxTreeNode(NodeType.BLOCK,subNodes);
    }

    private SyntaxTreeNode parseStmt() {
        List<SyntaxTreeNode> subNodes = new ArrayList<>();
        if (getTokenByOff(0).getType() == TokenType.LBRACE) {
            // Block
            subNodes.add(parseBlock());
        } else if (getTokenByOff(0).getType() == TokenType.PRINTFTK) {
            // 'printf' '(' StringConst { ',' Exp } ')' ';'
            match(TokenType.PRINTFTK,subNodes);
            match(TokenType.LPARENT,subNodes);
            match(TokenType.STRCON,subNodes);
            while (getTokenByOff(0).getType() == TokenType.COMMA) {
                match(TokenType.COMMA,subNodes);
                subNodes.add(parseExp());
            }
            match(TokenType.RPARENT,subNodes);
            match(TokenType.SEMICN,subNodes);

        } else if (getTokenByOff(0).getType() == TokenType.IFTK) {
            // 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
            match(TokenType.IFTK,subNodes);
            match(TokenType.LPARENT,subNodes);
            subNodes.add(parseCond());
            match(TokenType.RPARENT,subNodes);
            subNodes.add(parseStmt());
            if (getTokenByOff(0).getType() == TokenType.ELSETK) {
                match(TokenType.ELSETK,subNodes);
                subNodes.add(parseStmt());
            }

        } else if (getTokenByOff(0).getType() == TokenType.FORTK) {
            // 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
            match(TokenType.FORTK,subNodes);
            match(TokenType.LPARENT,subNodes);
            if(getTokenByOff(0).getType() != TokenType.SEMICN) {
                subNodes.add(parseForStmt());
            }
            match(TokenType.SEMICN,subNodes);
            if(getTokenByOff(0).getType() != TokenType.SEMICN) {
                subNodes.add(parseCond());
            }
            match(TokenType.SEMICN,subNodes);
            if(getTokenByOff(0).getType() != TokenType.RPARENT) {
                subNodes.add(parseForStmt());
            }
            match(TokenType.RPARENT,subNodes);
            subNodes.add(parseStmt());
        } else if (getTokenByOff(0).getType() == TokenType.BREAKTK) {
            // 'break' ';'
            match(TokenType.BREAKTK,subNodes);
            match(TokenType.SEMICN,subNodes);

        } else if (getTokenByOff(0).getType() == TokenType.CONTINUETK) {
            // 'continue' ';'
            match(TokenType.CONTINUETK,subNodes);
            match(TokenType.SEMICN,subNodes);
        } else if (getTokenByOff(0).getType() == TokenType.RETURNTK) {
            // 'return' [Exp] ';'
            match(TokenType.RETURNTK,subNodes);
            TokenType type = getTokenByOff(0).getType();
            if (type == TokenType.PLUS || type == TokenType.MINU || type == TokenType.IDENFR
                    || type == TokenType.INTCON || type == TokenType.CHRCON || type == TokenType.LPARENT) {
                subNodes.add(parseExp());
            }
            match(TokenType.SEMICN,subNodes);

        } else {
            // 计算 assign
            boolean haveAssign = false;
            if (getTokenByOff(0).getType() == TokenType.IDENFR) {
                int thatLine = getTokenByOff(0).getLineNumber();
                int i=0;
                while(getTokenByOff(i).getLineNumber() == thatLine) {
                    if (getTokenByOff(i).getType() == TokenType.ASSIGN) {
                        haveAssign = true;
                    }
                    i++;
                }
            }
            if (haveAssign) {
                subNodes.add(parseLVal());
                match(TokenType.ASSIGN,subNodes);
                if (getTokenByOff(0).getType() == TokenType.GETINTTK) {
                    // LVal '=' 'getint' '(' ')' ';'
                    match(TokenType.GETINTTK,subNodes);
                    match(TokenType.LPARENT,subNodes);
                    match(TokenType.RPARENT,subNodes);
                    match(TokenType.SEMICN,subNodes);

                } else if (getTokenByOff(0).getType() == TokenType.GETCHARTK) {
                    // LVal '=' 'getchar''('')'';' // i j
                    match(TokenType.GETCHARTK,subNodes);
                    match(TokenType.LPARENT,subNodes);
                    match(TokenType.RPARENT,subNodes);
                    match(TokenType.SEMICN,subNodes);

                } else {
                    // LVal '=' Exp ';'
                    subNodes.add(parseExp());
                    match(TokenType.SEMICN,subNodes);
                }
            } else {
                // [Exp] ';'
                // UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp // j
                // PrimaryExp → '(' Exp ')' | LVal | Number | Character// j
                // UnaryOp → '+' | '−'
                TokenType type = getTokenByOff(0).getType();
                if (type == TokenType.PLUS || type == TokenType.MINU || type == TokenType.IDENFR
                        || type == TokenType.INTCON || type == TokenType.CHRCON || type == TokenType.LPARENT) {
                    subNodes.add(parseExp());
                }
                match(TokenType.SEMICN,subNodes);

            }
        }
        return new SyntaxTreeNode(NodeType.STMT,subNodes);
    }

    private SyntaxTreeNode parseForStmt() {
        // ForStmt → LVal '=' Exp
        List<SyntaxTreeNode> subNodes = new ArrayList<>();
        subNodes.add(parseLVal());
        match(TokenType.ASSIGN,subNodes);
        subNodes.add(parseExp());
        return new SyntaxTreeNode(NodeType.FOR_STMT,subNodes);
    }

    private SyntaxTreeNode parseCond() {
        // Cond → LOrExp
        List<SyntaxTreeNode> subNodes = new ArrayList<>();
        subNodes.add(parseLOrExp());
        return new SyntaxTreeNode(NodeType.COND,subNodes);
    }

    private SyntaxTreeNode parseLOrExp() {
        // LOrExp → LAndExp { '||' LAndExp }
        List<SyntaxTreeNode> subNodes = new ArrayList<>();
        SyntaxTreeNode lowestExp = new SyntaxTreeNode(NodeType.L_OR_EXP,subNodes);
        lowestExp.addChild(parseLAndExp());
        SyntaxTreeNode finalTree = lowestExp;
        while (getTokenByOff(0).getType() == TokenType.OR) {
            List<SyntaxTreeNode> tmpNodes = new ArrayList<>();
            SyntaxTreeNode tmpExp = new SyntaxTreeNode(NodeType.L_OR_EXP,tmpNodes);
            tmpExp.addChild(finalTree);
            tmpExp.addChild(new SyntaxTreeNode(NodeType.LEAF_NODE,getTokenByOff(0)));
            lexer.move();
            tmpNodes.add(parseLAndExp());
            finalTree = tmpExp;
        }
        return finalTree;
    }

    private SyntaxTreeNode parseLAndExp() {
        // LAndExp → EqExp { '&&' EqExp }
        List<SyntaxTreeNode> subNodes = new ArrayList<>();
        SyntaxTreeNode lowestExp = new SyntaxTreeNode(NodeType.L_AND_EXP,subNodes);
        lowestExp.addChild(parseEqExp());
        SyntaxTreeNode finalTree = lowestExp;
        while (getTokenByOff(0).getType() == TokenType.AND) {
            List<SyntaxTreeNode> tmpNodes = new ArrayList<>();
            SyntaxTreeNode tmpExp = new SyntaxTreeNode(NodeType.L_AND_EXP,tmpNodes);
            tmpExp.addChild(finalTree);
            tmpExp.addChild(new SyntaxTreeNode(NodeType.LEAF_NODE,getTokenByOff(0)));
            lexer.move();
            tmpNodes.add(parseEqExp());
            finalTree = tmpExp;
        }
        return finalTree;
    }

    private SyntaxTreeNode parseEqExp() {
        // EqExp → RelExp { ('==' | '!=') RelExp  }
        List<SyntaxTreeNode> subNodes = new ArrayList<>();
        SyntaxTreeNode lowestExp = new SyntaxTreeNode(NodeType.EQ_EXP,subNodes);
        lowestExp.addChild(parseRelExp());
        SyntaxTreeNode finalTree = lowestExp;
        while (getTokenByOff(0).getType() == TokenType.EQL
                || getTokenByOff(0).getType() == TokenType.NEQ) {
            List<SyntaxTreeNode> tmpNodes = new ArrayList<>();
            SyntaxTreeNode tmpExp = new SyntaxTreeNode(NodeType.EQ_EXP,tmpNodes);
            tmpExp.addChild(finalTree);
            tmpExp.addChild(new SyntaxTreeNode(NodeType.LEAF_NODE,getTokenByOff(0)));
            lexer.move();
            tmpNodes.add(parseRelExp());
            finalTree = tmpExp;
        }
        return finalTree;
    }
    private SyntaxTreeNode parseRelExp() {
        // RelExp → AddExp {[ ('<' | '>' | '<=' | '>=') AddExp ]}

        List<SyntaxTreeNode> subNodes = new ArrayList<>();
        SyntaxTreeNode lowestExp = new SyntaxTreeNode(NodeType.REL_EXP,subNodes);
        lowestExp.addChild(parseAddExp());
        SyntaxTreeNode finalTree = lowestExp;
        while (getTokenByOff(0).getType() == TokenType.LSS
                || getTokenByOff(0).getType() == TokenType.GRE
                || getTokenByOff(0).getType() == TokenType.LEQ
                || getTokenByOff(0).getType() == TokenType.GEQ) {
            List<SyntaxTreeNode> tmpNodes = new ArrayList<>();
            SyntaxTreeNode tmpExp = new SyntaxTreeNode(NodeType.REL_EXP,tmpNodes);
            tmpExp.addChild(finalTree);
            tmpExp.addChild(new SyntaxTreeNode(NodeType.LEAF_NODE,getTokenByOff(0)));
            lexer.move();
            tmpNodes.add(parseAddExp());
            finalTree = tmpExp;
        }
        return finalTree;
    }
    private SyntaxTreeNode parseLVal() {
        // LVal → Ident ['[' Exp ']'] // k
        List<SyntaxTreeNode> subNodes = new ArrayList<>();
        match(TokenType.IDENFR,subNodes);
        if (getTokenByOff(0).getType() == TokenType.LBRACK) {
            match(TokenType.LBRACK,subNodes);
            subNodes.add(parseExp());
            match(TokenType.RBRACK,subNodes);
        }
        return new SyntaxTreeNode(NodeType.LVAL,subNodes);
    }

    private SyntaxTreeNode parseExp() {
        // Exp → AddExp
        List<SyntaxTreeNode> subNodes = new ArrayList<>();
        subNodes.add(parseAddExp());
        return new SyntaxTreeNode(NodeType.EXP,subNodes);
    }

    private SyntaxTreeNode parseFuncDef() {
        // FuncDef → FuncType Ident '(' [FuncFParams] ')' Block // j
        List<SyntaxTreeNode> subNodes = new ArrayList<>();
        subNodes.add(parseFuncType());
        match(TokenType.IDENFR,subNodes);
        match(TokenType.LPARENT,subNodes);
        if (getTokenByOff(0).getType() != TokenType.RPARENT) {
            subNodes.add(parseFuncFParams());
        }
        match(TokenType.RPARENT,subNodes);
        subNodes.add(parseBlock());
        return new SyntaxTreeNode(NodeType.FUNC_DEF,subNodes);
    }

    private SyntaxTreeNode parseFuncFParams() {
        //FuncFParams → FuncFParam { ',' FuncFParam }
        List<SyntaxTreeNode> subNodes = new ArrayList<>();
        subNodes.add(parseFuncFParam());
        while (getTokenByOff(0).getType() == TokenType.COMMA) {
            match(TokenType.COMMA,subNodes);
            subNodes.add(parseFuncFParam());
        }
        return new SyntaxTreeNode(NodeType.FUNC_FPARAMS,subNodes);
    }
    private SyntaxTreeNode parseFuncRParams() {
        // FuncRParams → Exp { ',' Exp }
        List<SyntaxTreeNode> subNodes = new ArrayList<>();
        subNodes.add(parseExp());
        while (getTokenByOff(0).getType() == TokenType.COMMA) {
            match(TokenType.COMMA,subNodes);
            subNodes.add(parseExp());
        }
        return new SyntaxTreeNode(NodeType.FUNC_RPARAMS,subNodes);
    }

    private SyntaxTreeNode parseFuncFParam() {
        // FuncFParam → ('int' | 'char') Ident ['[' ']'] // k
        List<SyntaxTreeNode> subNodes = new ArrayList<>();
        if (getTokenByOff(0).getType() == TokenType.INTTK) {
            match(TokenType.INTTK,subNodes);
        } else if (getTokenByOff(0).getType() == TokenType.CHARTK) {
            match(TokenType.CHARTK,subNodes);
        }
        match(TokenType.IDENFR,subNodes);
        if (getTokenByOff(0).getType() == TokenType.LBRACK) {
            match(TokenType.LBRACK,subNodes);
            match(TokenType.RBRACK,subNodes);
        }
        return new SyntaxTreeNode(NodeType.FUNC_FPARAM,subNodes);
    }

    private SyntaxTreeNode parseFuncType() {
        // FuncType → 'void' | 'int' | 'char'
        List<SyntaxTreeNode> subNodes = new ArrayList<>();
        subNodes.add(new SyntaxTreeNode(NodeType.LEAF_NODE,getTokenByOff(0)));
        lexer.move();
        return new SyntaxTreeNode(NodeType.FUNC_TYPE,subNodes);
    }

    private SyntaxTreeNode parseVarDecl() {
        // VarDecl → ('int' | 'char') VarDef { ',' VarDef } ';' // i
        List<SyntaxTreeNode> subNodes = new ArrayList<>();
        subNodes.add(new SyntaxTreeNode(NodeType.LEAF_NODE,getTokenByOff(0)));
        lexer.move();
        subNodes.add(parseVarDef());
        while (getTokenByOff(0).getType() == TokenType.COMMA) {
            match(TokenType.COMMA,subNodes);
            subNodes.add(parseVarDef());
        }
        match(TokenType.SEMICN,subNodes);
        return new SyntaxTreeNode(NodeType.VAR_DECL,subNodes);
    }

    private SyntaxTreeNode parseVarDef() {
        // VarDef → Ident [ '[' ConstExp ']' ] ['=' InitVal ] // k
        List<SyntaxTreeNode> subNodes = new ArrayList<>();
        match(TokenType.IDENFR,subNodes);
        if (getTokenByOff(0).getType() == TokenType.LBRACK) {
            match(TokenType.LBRACK,subNodes);
            subNodes.add(parseConstExp());
            match(TokenType.RBRACK,subNodes);
        }
        if (getTokenByOff(0).getType() == TokenType.ASSIGN) {
            match(TokenType.ASSIGN,subNodes);
            subNodes.add(parseInitVal());
        }
        return new SyntaxTreeNode(NodeType.VAR_DEF,subNodes);
    }

    private SyntaxTreeNode parseInitVal() {
        // InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
        List<SyntaxTreeNode> subNodes = new ArrayList<>();
        if (getTokenByOff(0).getType() == TokenType.STRCON) {
            match(TokenType.STRCON,subNodes);
        } else if (getTokenByOff(0).getType() == TokenType.LBRACE) {
            match(TokenType.LBRACE,subNodes);
            if (getTokenByOff(0).getType() != TokenType.RBRACE) {
                subNodes.add(parseExp());
                while (getTokenByOff(0).getType() == TokenType.COMMA) {
                    match(TokenType.COMMA,subNodes);
                    subNodes.add(parseExp());
                }
            }
            match(TokenType.RBRACE,subNodes);
        } else {
            subNodes.add(parseExp());
        }
        return new SyntaxTreeNode(NodeType.INIT_VAL,subNodes);
    }

    private SyntaxTreeNode parseConstDecl() {
        List<SyntaxTreeNode> subNodes = new ArrayList<>();
        // ConstDecl → 'const' ('int' | 'char') ConstDef { ',' ConstDef } ';' // i
        match(TokenType.CONSTTK,subNodes);
        subNodes.add(new SyntaxTreeNode(NodeType.LEAF_NODE,getTokenByOff(0)));
        lexer.move();
        subNodes.add(parseConstDef());
        while (getTokenByOff(0).getType() == TokenType.COMMA) {
            match(TokenType.COMMA,subNodes);
            subNodes.add(parseConstDef());
        }
        match(TokenType.SEMICN,subNodes);
        return new SyntaxTreeNode(NodeType.CONST_DECL,subNodes);
    }

    private SyntaxTreeNode parseConstDef() {
        // ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal // k
        List<SyntaxTreeNode> subNodes = new ArrayList<>();
        match(TokenType.IDENFR,subNodes);
        if (getTokenByOff(0).getType() == TokenType.LBRACK) {
            match(TokenType.LBRACK,subNodes);
            subNodes.add(parseConstExp());
            match(TokenType.RBRACK,subNodes);
        }
        match(TokenType.ASSIGN,subNodes);
        subNodes.add(parseConstInitVal());
        return new SyntaxTreeNode(NodeType.CONST_DEF,subNodes);
    }

    private SyntaxTreeNode parseConstInitVal() {
        // ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
        List<SyntaxTreeNode> subNodes = new ArrayList<>();
        if (getTokenByOff(0).getType() == TokenType.STRCON) {
            match(TokenType.STRCON,subNodes);
        } else if (getTokenByOff(0).getType() == TokenType.LBRACE) {
            match(TokenType.LBRACE,subNodes);
            if (getTokenByOff(0).getType() != TokenType.RBRACE) {
                subNodes.add(parseConstExp());
                while (getTokenByOff(0).getType() == TokenType.COMMA) {
                    match(TokenType.COMMA,subNodes);
                    subNodes.add(parseConstExp());
                }
            }
            match(TokenType.RBRACE,subNodes);
        } else {
            subNodes.add(parseConstExp());
        }
        return new SyntaxTreeNode(NodeType.CONST_INIT_VAL,subNodes);
    }

    private SyntaxTreeNode parseConstExp() {
        //ConstExp → AddExp
        List<SyntaxTreeNode> subNodes = new ArrayList<>();
        subNodes.add(parseAddExp());
        return new SyntaxTreeNode(NodeType.CONST_EXP,subNodes);
    }

    private SyntaxTreeNode parseAddExp() {
        // AddExp → MulExp {('+' | '−') MulExp}
        List<SyntaxTreeNode> subNodes = new ArrayList<>();
        SyntaxTreeNode lowestAddExp = new SyntaxTreeNode(NodeType.ADD_EXP,subNodes);
        lowestAddExp.addChild(parseMulExp());
        SyntaxTreeNode finalAddTree = lowestAddExp;
        while (getTokenByOff(0).getType() == TokenType.PLUS
                || getTokenByOff(0).getType() == TokenType.MINU) {
            List<SyntaxTreeNode> tmpNodes = new ArrayList<>();
            SyntaxTreeNode tmpAddExp = new SyntaxTreeNode(NodeType.ADD_EXP,tmpNodes);
            tmpAddExp.addChild(finalAddTree);
            tmpAddExp.addChild(new SyntaxTreeNode(NodeType.LEAF_NODE,getTokenByOff(0)));
            lexer.move();
            tmpNodes.add(parseMulExp());
            finalAddTree = tmpAddExp;
        }
        return finalAddTree;
    }

    private SyntaxTreeNode parseMulExp() {
        // MulExp → UnaryExp {('*' | '/' | '%') UnaryExp}
        List<SyntaxTreeNode> subNodes = new ArrayList<>();
        SyntaxTreeNode lowestExp = new SyntaxTreeNode(NodeType.MUL_EXP,subNodes);
        lowestExp.addChild(parseUnaryExp());
        SyntaxTreeNode finalTree = lowestExp;
        while (getTokenByOff(0).getType() == TokenType.MULT
                || getTokenByOff(0).getType() == TokenType.DIV
                || getTokenByOff(0).getType() == TokenType.MOD) {
            List<SyntaxTreeNode> tmpNodes = new ArrayList<>();
            SyntaxTreeNode tmpExp = new SyntaxTreeNode(NodeType.MUL_EXP,tmpNodes);
            tmpExp.addChild(finalTree);
            tmpExp.addChild(new SyntaxTreeNode(NodeType.LEAF_NODE,getTokenByOff(0)));
            lexer.move();
            tmpNodes.add(parseUnaryExp());
            finalTree = tmpExp;
        }
        return finalTree;
    }

    private SyntaxTreeNode parseUnaryExp() {
        // UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp // j
        // PrimaryExp → '(' Exp ')' | LVal | Number | Character// j
        // UnaryOp → '+' | '−' | '!'
        List<SyntaxTreeNode> subNodes = new ArrayList<>();
        if (getTokenByOff(0).getType() == TokenType.PLUS
                || getTokenByOff(0).getType() == TokenType.MINU
                || getTokenByOff(0).getType() == TokenType.NOT) {
            subNodes.add(parseUnaryOp());
            subNodes.add(parseUnaryExp());
        } else if (getTokenByOff(0).getType() == TokenType.IDENFR
                && getTokenByOff(1).getType() == TokenType.LPARENT) {
            match(TokenType.IDENFR,subNodes);
            match(TokenType.LPARENT,subNodes);
            if (getTokenByOff(0).getType() != TokenType.RPARENT) {
                subNodes.add(parseFuncRParams());
            }
            match(TokenType.RPARENT,subNodes);
        } else {
            subNodes.add(parsePrimaryExp());
        }
        return new SyntaxTreeNode(NodeType.UNARY_EXP,subNodes);
    }

    private SyntaxTreeNode parsePrimaryExp() {
        // PrimaryExp → '(' Exp ')' | LVal | Number | Character// j
        List<SyntaxTreeNode> subNodes = new ArrayList<>();
        if (getTokenByOff(0).getType() == TokenType.CHRCON) {
            subNodes.add(parseCharacter());
        } else if (getTokenByOff(0).getType() == TokenType.INTCON) {
            subNodes.add(parseNumber());
        } else if (getTokenByOff(0).getType() == TokenType.LPARENT) {
            match(TokenType.LPARENT,subNodes);
            subNodes.add(parseExp());
            match(TokenType.RPARENT,subNodes);
        } else {
            subNodes.add(parseLVal());
        }
        return new SyntaxTreeNode(NodeType.PRIMARY_EXP,subNodes);
    }

    private SyntaxTreeNode parseCharacter() {
        List<SyntaxTreeNode> subNodes = new ArrayList<>();
        match(TokenType.CHRCON,subNodes);
        return new SyntaxTreeNode(NodeType.CHARACTER,subNodes);
    }

    private SyntaxTreeNode parseNumber() {
        List<SyntaxTreeNode> subNodes = new ArrayList<>();
        match(TokenType.INTCON,subNodes);
        return new SyntaxTreeNode(NodeType.NUMBER,subNodes);
    }

    private SyntaxTreeNode parseUnaryOp() {
        // UnaryOp → '+' | '−' | '!'
        List<SyntaxTreeNode> subNodes = new ArrayList<>();
        subNodes.add(new SyntaxTreeNode(NodeType.LEAF_NODE,getTokenByOff(0)));
        lexer.move();
        return new SyntaxTreeNode(NodeType.UNARY_OP,subNodes);
    }

    private Token getTokenByOff(int offset) {
        return lexer.getToken(offset);
    }

    private void match(TokenType expectedKind,List<SyntaxTreeNode> subNodes){
        if (getTokenByOff(0).getType() == expectedKind) {
            subNodes.add(new SyntaxTreeNode(NodeType.LEAF_NODE,getTokenByOff(0)));
            lexer.move();
        } else if (expectedKind == TokenType.SEMICN){
            errors.put(getTokenByOff(-1).getLineNumber()
                    ,new ErrorCode(ErrorType.MISSING_SEMICOLON,getTokenByOff(-1).getLineNumber()));
        } else if (expectedKind == TokenType.RPARENT){
            errors.put(getTokenByOff(-1).getLineNumber()
                    ,new ErrorCode(ErrorType.MISSING_PARENTHESIS,getTokenByOff(-1).getLineNumber()));
        } else if (expectedKind == TokenType.RBRACK){
            errors.put(getTokenByOff(-1).getLineNumber()
                    ,new ErrorCode(ErrorType.MISSING_BRACKET,getTokenByOff(-1).getLineNumber()));
        }
    }

    public Map<Integer, ErrorCode> getErrors() {
        return errors;
    }
}
