package Paser;

import Reader.Token;
import Reader.TokenStream;
import Type.SyntaxVarType;

import java.util.ArrayList;

public class Paser {
    private final TokenStream tokenStream;
    public static int p = 0;
    public static String error = "";


    public Paser(TokenStream tokenStream) {
        this.tokenStream = tokenStream;
    }

    // 编译单元 CompUnit → {Decl} {FuncDef} MainFuncDef // 1.是否存在Decl 2.是否存在FuncDef
    public Node parseUnitNode() {
        ArrayList<Node> children = new ArrayList<>();
        Node node = null;
        int startLine = tokenStream.get(p).getLineNumber();
        while (true) {
            if (p >= tokenStream.size() || tokenStream.get(p) == null) {
                break;
            } else if (tokenStream.get(p + 1).getType() == Token.TokenType.MAINTK) {
                node = parseMainFuncDef();
            }
            // parse FuncDef
            else if (tokenStream.get(p + 2).getType() == Token.TokenType.LPARENT) {
                node = parseFuncDef();
            }
            // parse ConstDecl
            else if (tokenStream.get(p).getType() == Token.TokenType.CONSTTK) {
                node = parseConstDecl();
            }
            // parse VarDecl
            else if (tokenStream.get(p).getType() == Token.TokenType.INTTK || tokenStream.get(p).getType() == Token.TokenType.CHARTK) {
                node = parseVarDecl();
            } else {
                System.err.println("Syntax Error when parse Unit: " + tokenStream.get(p).getLineNumber() + " " + tokenStream.get(p).getDescription());
                break;
            }
            children.add(node);

        }
        int endLine = tokenStream.get(p - 1).getLineNumber();
        return NodeFactory.createNode(startLine, endLine, SyntaxVarType.COMP_UNIT, children);
    }


    // MainFuncDef → 'int' 'main' '(' ')' Block
    private Node parseMainFuncDef() {
        ArrayList<Node> children = new ArrayList<>();
        Node node = null;
        int startLine = tokenStream.get(p).getLineNumber();
        if (tokenStream.get(p).getType() == Token.TokenType.INTTK) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        }
        if (tokenStream.get(p).getType() == Token.TokenType.MAINTK) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        }
        if (tokenStream.get(p).getType() == Token.TokenType.LPARENT) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        }
        if (tokenStream.get(p).getType() == Token.TokenType.RPARENT) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        } else {
            children.add(NodeFactory.createNode(new Token(")", Token.TokenType.RPARENT, tokenStream.get(p).getLineNumber())));
            error += tokenStream.get(p - 1).getLineNumber() + " " + "j\n";
        }
        node = parseBlock();
        children.add(node);
        int endLine = tokenStream.get(p - 1).getLineNumber();
        return NodeFactory.createNode(startLine, endLine, SyntaxVarType.MAIN_FUNC_DEF, children);
    }

    // 语句块 Block → '{' { BlockItem } '}' // 1.花括号内重复0次 2.花括号内重复多次
    private Node parseBlock() {
        ArrayList<Node> children = new ArrayList<>();
        Node node = null;
        int startLine = tokenStream.get(p).getLineNumber();
        if (tokenStream.get(p).getType() == Token.TokenType.LBRACE) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        }
        while (true) {
            if (tokenStream.get(p).getType() == Token.TokenType.RBRACE) {
                children.add(NodeFactory.createNode(tokenStream.get(p)));
                p++;
                break;
            }
            if (tokenStream.get(p).getType() == Token.TokenType.CONSTTK) {
                node = parseConstDecl();
            } else if (tokenStream.get(p).getType() == Token.TokenType.INTTK || tokenStream.get(p).getType() == Token.TokenType.CHARTK) {
                node = parseVarDecl();
            } else {
                node = parseStmt();
            }
            children.add(node);
        }
        int endLine = tokenStream.get(p - 1).getLineNumber();
        return NodeFactory.createNode(startLine, endLine, SyntaxVarType.BLOCK, children);
    }

    /*
     Stmt → LVal '=' Exp ';' // h i
    | [Exp] ';' // i
    | Block
    | 'if' '(' Cond ')' Stmt [ 'else' Stmt ] // j
    | 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt // h
    | 'break' ';' | 'continue' ';' // i m
    | 'return' [Exp] ';' // f i
    | LVal '=' 'getint''('')'';' // h i j
    | LVal '=' 'getchar''('')'';' // h i j
    | 'printf''('StringConst {','Exp}')'';'
    */
    private Node parseStmt() {
        ArrayList<Node> children = new ArrayList<>();
        Node node = null;
        int startLine = tokenStream.get(p).getLineNumber();
        if (tokenStream.get(p).getType() == Token.TokenType.IFTK) {
            return parseIfStmt();
        } else if (tokenStream.get(p).getType() == Token.TokenType.FORTK) {
            return parseForStmt();
        } else if (tokenStream.get(p).getType() == Token.TokenType.BREAKTK) {
            return parseBreakStmt();
        } else if (tokenStream.get(p).getType() == Token.TokenType.CONTINUETK) {
            return parseContinueStmt();
        } else if (tokenStream.get(p).getType() == Token.TokenType.RETURNTK) {
            return parseReturnStmt();
        } else if (tokenStream.get(p).getType() == Token.TokenType.PRINTFTK) {
            return parsePrintfStmt();
        } else if (tokenStream.get(p).getType() == Token.TokenType.LBRACE) {
            return parseBlockStmt();
        }
        int tmpp = p;
        int flag = 0;
        while (tmpp < tokenStream.size() && tokenStream.get(tmpp).getType() != Token.TokenType.SEMICN && tokenStream.get(tmpp).getLineNumber() == tokenStream.get(p).getLineNumber()) {
            if (tokenStream.get(tmpp).getType() == Token.TokenType.ASSIGN && tokenStream.get(tmpp + 1).getType() == Token.TokenType.GETINTTK) {
                flag = 1;
                break;
            } else if (tokenStream.get(tmpp).getType() == Token.TokenType.ASSIGN && tokenStream.get(tmpp + 1).getType() == Token.TokenType.GETCHARTK) {
                flag = 2;
                break;
            } else if (tokenStream.get(tmpp).getType() == Token.TokenType.ASSIGN) {
                flag = 3;
                break;
            }
            tmpp++;
        }
        if (flag == 0) {
            return parseExpStmt();
        } else if (flag == 1) {
            return parseGetIntStmt();
        } else if (flag == 2) {
            return parseGetCharStmt();
        } else if (flag == 3) {
            return parseAssignStmt();
        }

        children.add(node);
        int endLine = tokenStream.get(p - 1).getLineNumber();
        return NodeFactory.createNode(startLine, endLine, SyntaxVarType.STMT, children);
    }

    // AssignStmt → LVal '=' Exp ';'
    private Node parseAssignStmt() {
        ArrayList<Node> children = new ArrayList<>();
        Node node = null;
        int startLine = tokenStream.get(p).getLineNumber();
        node = parseLValExp();
        children.add(node);
        if (tokenStream.get(p).getType() == Token.TokenType.ASSIGN) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        }
        node = parseExp();
        children.add(node);
        if (tokenStream.get(p).getType() == Token.TokenType.SEMICN) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        } else {
            children.add(NodeFactory.createNode(new Token(";", Token.TokenType.SEMICN, tokenStream.get(p).getLineNumber())));
            error += tokenStream.get(p - 1).getLineNumber() + " " + "i\n";
        }
        int endLine = tokenStream.get(p - 1).getLineNumber();
        return NodeFactory.createNode(startLine, endLine, SyntaxVarType.ASSIGN_STMT, children);
    }

    // GetCharStmt → LVal '=' 'getchar''('')'';'
    private Node parseGetCharStmt() {
        ArrayList<Node> children = new ArrayList<>();
        Node node = null;
        int startLine = tokenStream.get(p).getLineNumber();
        node = parseLValExp();
        children.add(node);
        if (tokenStream.get(p).getType() == Token.TokenType.ASSIGN) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        }
        if (tokenStream.get(p).getType() == Token.TokenType.GETCHARTK) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        }
        if (tokenStream.get(p).getType() == Token.TokenType.LPARENT) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        }
        if (tokenStream.get(p).getType() == Token.TokenType.RPARENT) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        } else {
            children.add(NodeFactory.createNode(new Token(")", Token.TokenType.RPARENT, tokenStream.get(p).getLineNumber())));
            error += tokenStream.get(p - 1).getLineNumber() + " " + "j\n";
        }
        if (tokenStream.get(p).getType() == Token.TokenType.SEMICN) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        } else {
            children.add(NodeFactory.createNode(new Token(";", Token.TokenType.SEMICN, tokenStream.get(p).getLineNumber())));
            error += tokenStream.get(p - 1).getLineNumber() + " " + "i\n";
        }
        int endLine = tokenStream.get(p - 1).getLineNumber();
        return NodeFactory.createNode(startLine, endLine, SyntaxVarType.GETCHAR_STMT, children);
    }

    // GetintStmt → LVal '=' 'getint''('')'';'
    private Node parseGetIntStmt() {
        ArrayList<Node> children = new ArrayList<>();
        Node node = null;
        int startLine = tokenStream.get(p).getLineNumber();
        node = parseLValExp();
        children.add(node);
        if (tokenStream.get(p).getType() == Token.TokenType.ASSIGN) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        }
        if (tokenStream.get(p).getType() == Token.TokenType.GETINTTK) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        }
        if (tokenStream.get(p).getType() == Token.TokenType.LPARENT) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        }
        if (tokenStream.get(p).getType() == Token.TokenType.RPARENT) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        } else {
            children.add(NodeFactory.createNode(new Token(")", Token.TokenType.RPARENT, tokenStream.get(p).getLineNumber())));
            error += tokenStream.get(p - 1).getLineNumber() + " " + "j\n";
        }
        if (tokenStream.get(p).getType() == Token.TokenType.SEMICN) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        } else {
            children.add(NodeFactory.createNode(new Token(";", Token.TokenType.SEMICN, tokenStream.get(p).getLineNumber())));
            error += tokenStream.get(p - 1).getLineNumber() + " " + "i\n";
        }
        int endLine = tokenStream.get(p - 1).getLineNumber();
        return NodeFactory.createNode(startLine, endLine, SyntaxVarType.GETINT_STMT, children);
    }

    private Node parseExpStmt() {
        ArrayList<Node> children = new ArrayList<>();
        Node node = null;
        int startLine = tokenStream.get(p).getLineNumber();

        if (tokenStream.get(p).getType() == Token.TokenType.IDENFR || tokenStream.get(p).getType() == Token.TokenType.INTCON || tokenStream.get(p).getType() == Token.TokenType.CHRCON || tokenStream.get(p).getType() == Token.TokenType.LPARENT || tokenStream.get(p).getType() == Token.TokenType.PLUS || tokenStream.get(p).getType() == Token.TokenType.MINU || tokenStream.get(p).getType() == Token.TokenType.NOT) {
            node = parseExp();
            children.add(node);
        }
        if (tokenStream.get(p).getType() == Token.TokenType.SEMICN) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        } else {
            // System.out.println(111);
            children.add(NodeFactory.createNode(new Token(";", Token.TokenType.SEMICN, tokenStream.get(p).getLineNumber())));
            error += tokenStream.get(p - 1).getLineNumber() + " " + "i\n";
        }

        int endLine = tokenStream.get(p - 1).getLineNumber();
        return NodeFactory.createNode(startLine, endLine, SyntaxVarType.EXP_STMT, children);
    }

    private Node parseBlockStmt() {
        ArrayList<Node> children = new ArrayList<>();
        Node node = null;
        int startLine = tokenStream.get(p).getLineNumber();
        node = parseBlock();
        children.add(node);
        int endLine = tokenStream.get(p - 1).getLineNumber();
        return NodeFactory.createNode(startLine, endLine, SyntaxVarType.BLOCK_STMT, children);
    }


    //  'printf''('StringConst {','Exp}')'';'
    private Node parsePrintfStmt() {
        ArrayList<Node> children = new ArrayList<>();
        Node node = null;
        int startLine = tokenStream.get(p).getLineNumber();
        if (tokenStream.get(p).getType() == Token.TokenType.PRINTFTK) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        }
        if (tokenStream.get(p).getType() == Token.TokenType.LPARENT) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        }
        if (tokenStream.get(p).getType() == Token.TokenType.STRCON) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        }
        while (tokenStream.get(p).getType() == Token.TokenType.COMMA) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
            node = parseExp();
            children.add(node);
        }
        if (tokenStream.get(p).getType() == Token.TokenType.RPARENT) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        } else {
            children.add(NodeFactory.createNode(new Token(")", Token.TokenType.RPARENT, tokenStream.get(p).getLineNumber())));
            error += tokenStream.get(p - 1).getLineNumber() + " " + "j\n";
        }
        if (tokenStream.get(p).getType() == Token.TokenType.SEMICN) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        } else {
            children.add(NodeFactory.createNode(new Token(";", Token.TokenType.SEMICN, tokenStream.get(p).getLineNumber())));
            error += tokenStream.get(p - 1).getLineNumber() + " " + "i\n";
            //
        }
        int endLine = tokenStream.get(p - 1).getLineNumber();
        return NodeFactory.createNode(startLine, endLine, SyntaxVarType.PRINTF_STMT, children);
    }

    // 'return' [Exp] ';'
    private Node parseReturnStmt() {
        ArrayList<Node> children = new ArrayList<>();
        Node node = null;
        int startLine = tokenStream.get(p).getLineNumber();
        if (tokenStream.get(p).getType() == Token.TokenType.RETURNTK) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        }

        if (tokenStream.get(p).getType() == Token.TokenType.IDENFR || tokenStream.get(p).getType() == Token.TokenType.INTCON || tokenStream.get(p).getType() == Token.TokenType.CHRCON || tokenStream.get(p).getType() == Token.TokenType.LPARENT || tokenStream.get(p).getType() == Token.TokenType.PLUS || tokenStream.get(p).getType() == Token.TokenType.MINU || tokenStream.get(p).getType() == Token.TokenType.NOT) {
            node = parseExp();
            children.add(node);
        }
        if (tokenStream.get(p).getType() == Token.TokenType.SEMICN) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        } else {
            children.add(NodeFactory.createNode(new Token(";", Token.TokenType.SEMICN, tokenStream.get(p).getLineNumber())));
            error += tokenStream.get(p - 1).getLineNumber() + " " + "i\n";
        }

        int endLine = tokenStream.get(p - 1).getLineNumber();
        return NodeFactory.createNode(startLine, endLine, SyntaxVarType.RETURN_STMT, children);
    }

    private Node parseBreakStmt() {
        ArrayList<Node> children = new ArrayList<>();
        Node node = null;
        int startLine = tokenStream.get(p).getLineNumber();
        if (tokenStream.get(p).getType() == Token.TokenType.BREAKTK) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        }
        if (tokenStream.get(p).getType() == Token.TokenType.SEMICN) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        } else {
            children.add(NodeFactory.createNode(new Token(";", Token.TokenType.SEMICN, tokenStream.get(p).getLineNumber())));
            error += tokenStream.get(p - 1).getLineNumber() + " " + "i\n";
        }
        int endLine = tokenStream.get(p - 1).getLineNumber();
        return NodeFactory.createNode(startLine, endLine, SyntaxVarType.BREAK_STMT, children);
    }

    private Node parseContinueStmt() {
        ArrayList<Node> children = new ArrayList<>();
        Node node = null;
        int startLine = tokenStream.get(p).getLineNumber();
        if (tokenStream.get(p).getType() == Token.TokenType.CONTINUETK) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        }
        if (tokenStream.get(p).getType() == Token.TokenType.SEMICN) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        } else {
            children.add(NodeFactory.createNode(new Token(";", Token.TokenType.SEMICN, tokenStream.get(p).getLineNumber())));
            error += tokenStream.get(p - 1).getLineNumber() + " " + "i\n";
        }
        int endLine = tokenStream.get(p - 1).getLineNumber();
        return NodeFactory.createNode(startLine, endLine, SyntaxVarType.CONTINUE_STMT, children);
    }

    //  'for' '(' [ForStmtExp] ';' [Cond] ';' [ForStmtExp] ')' Stmt
    private Node parseForStmt() {
        ArrayList<Node> children = new ArrayList<>();
        Node node = null;
        int startLine = tokenStream.get(p).getLineNumber();
        if (tokenStream.get(p).getType() == Token.TokenType.FORTK) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        }
        if (tokenStream.get(p).getType() == Token.TokenType.LPARENT) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        }
        if (tokenStream.get(p).getType() == Token.TokenType.SEMICN) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        } else {
            if (isExp(p)) {
                node = parseForStmtExp();
                children.add(node);
            }
            if (tokenStream.get(p).getType() == Token.TokenType.SEMICN) {
                children.add(NodeFactory.createNode(tokenStream.get(p)));
                p++;
            } else {
                children.add(NodeFactory.createNode(new Token(";", Token.TokenType.SEMICN, tokenStream.get(p).getLineNumber())));
                error += tokenStream.get(p - 1).getLineNumber() + " " + "i\n";
            }
        }

        if (tokenStream.get(p).getType() == Token.TokenType.SEMICN) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        } else {
            node = parseCondExp();
            children.add(node);

            if (tokenStream.get(p).getType() == Token.TokenType.SEMICN) {
                children.add(NodeFactory.createNode(tokenStream.get(p)));
                p++;
            } else {
                children.add(NodeFactory.createNode(new Token(";", Token.TokenType.SEMICN, tokenStream.get(p).getLineNumber())));
                error += tokenStream.get(p - 1).getLineNumber() + " " + "i\n";
            }
        }

        if (tokenStream.get(p).getType() == Token.TokenType.RPARENT) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        } else {
            if (isExp(p)) {
                node = parseForStmtExp();
                children.add(node);
            }
            if (tokenStream.get(p).getType() == Token.TokenType.RPARENT) {
                children.add(NodeFactory.createNode(tokenStream.get(p)));
                p++;
            } else {
                children.add(NodeFactory.createNode(new Token(")", Token.TokenType.RPARENT, tokenStream.get(p).getLineNumber())));
                error += tokenStream.get(p - 1).getLineNumber() + " " + "j\n";
            }
        }
        node = parseStmt();
        children.add(node);
        int endLine = tokenStream.get(p - 1).getLineNumber();
        return NodeFactory.createNode(startLine, endLine, SyntaxVarType.FOR_STMT, children);
    }

    // ForStmtExp →  LVal '=' Exp
    private Node parseForStmtExp() {
        ArrayList<Node> children = new ArrayList<>();
        Node node = null;
        int startLine = tokenStream.get(p).getLineNumber();
        node = parseLValExp();
        children.add(node);
        if (tokenStream.get(p).getType() == Token.TokenType.ASSIGN) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        }
        node = parseExp();
        children.add(node);
        int endLine = tokenStream.get(p - 1).getLineNumber();
        return NodeFactory.createNode(startLine, endLine, SyntaxVarType.FOR_STMT_EXP, children);
    }

    // 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
    private Node parseIfStmt() {
        ArrayList<Node> children = new ArrayList<>();
        Node node = null;
        int startLine = tokenStream.get(p).getLineNumber();
        if (tokenStream.get(p).getType() == Token.TokenType.IFTK) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        }
        if (tokenStream.get(p).getType() == Token.TokenType.LPARENT) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        }
        node = parseCondExp();
        children.add(node);
        if (tokenStream.get(p).getType() == Token.TokenType.RPARENT) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        } else {
            children.add(NodeFactory.createNode(new Token(")", Token.TokenType.RPARENT, tokenStream.get(p).getLineNumber())));
            error += tokenStream.get(p - 1).getLineNumber() + " " + "j\n";
        }
        node = parseStmt();
        children.add(node);
        if (tokenStream.get(p).getType() == Token.TokenType.ELSETK) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
            node = parseStmt();
            children.add(node);
        }
        int endLine = tokenStream.get(p - 1).getLineNumber();
        return NodeFactory.createNode(startLine, endLine, SyntaxVarType.IF_STMT, children);
    }

    // Cond → LOrExp
    private Node parseCondExp() {
        ArrayList<Node> children = new ArrayList<>();
        Node node = null;
        int startLine = tokenStream.get(p).getLineNumber();
        node = parseLOrExp();
        children.add(node);
        int endLine = tokenStream.get(p - 1).getLineNumber();
        return NodeFactory.createNode(startLine, endLine, SyntaxVarType.COND_EXP, children);
    }

    //  LOrExp → LAndExp | LOrExp '||' LAndExp, 严格按照给出的语法建树
    private Node parseLOrExp() {
        ArrayList<Node> children = new ArrayList<>();
        Node node = null;
        Node nodep = null;
        int startLine = tokenStream.get(p).getLineNumber();
        node = parseLAndExp();
        children.add(node);
        node = NodeFactory.createNode(startLine, tokenStream.get(p - 1).getLineNumber(), SyntaxVarType.LOR_EXP, children);
        while (tokenStream.get(p).getType() == Token.TokenType.OR) {
            ArrayList<Node> childrentmp = new ArrayList<>();
            childrentmp.add(node);
            childrentmp.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
            nodep = parseLAndExp();
            childrentmp.add(nodep);
            node = NodeFactory.createNode(startLine, tokenStream.get(p - 1).getLineNumber(), SyntaxVarType.LOR_EXP, childrentmp);

        }
        return node;
    }

    //  LAndExp → EqExp | LAndExp '&&' EqExp
    private Node parseLAndExp() {
        ArrayList<Node> children = new ArrayList<>();
        Node node = null;
        Node nodep = null;
        int startLine = tokenStream.get(p).getLineNumber();
        node = parseEqExp();
        children.add(node);
        node = NodeFactory.createNode(startLine, tokenStream.get(p - 1).getLineNumber(), SyntaxVarType.LAND_EXP, children);
        while (tokenStream.get(p).getType() == Token.TokenType.AND) {
            ArrayList<Node> childrentmp = new ArrayList<>();
            childrentmp.add(node);
            childrentmp.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
            nodep = parseEqExp();
            childrentmp.add(nodep);
            node = NodeFactory.createNode(startLine, tokenStream.get(p - 1).getLineNumber(), SyntaxVarType.LAND_EXP, childrentmp);
        }
        return node;
    }

    // EqExp → RelExp | EqExp ('==' | '!=') RelExp
    private Node parseEqExp() {
        ArrayList<Node> children = new ArrayList<>();
        Node node = null;
        Node nodep = null;
        int startLine = tokenStream.get(p).getLineNumber();
        node = parseRelExp();
        children.add(node);
        node = NodeFactory.createNode(startLine, tokenStream.get(p - 1).getLineNumber(), SyntaxVarType.EQ_EXP, children);
        while (tokenStream.get(p).getType() == Token.TokenType.EQL || tokenStream.get(p).getType() == Token.TokenType.NEQ) {
            ArrayList<Node> childrentmp = new ArrayList<>();
            childrentmp.add(node);
            childrentmp.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
            nodep = parseRelExp();
            childrentmp.add(nodep);
            node = NodeFactory.createNode(startLine, tokenStream.get(p - 1).getLineNumber(), SyntaxVarType.EQ_EXP, childrentmp);
        }
        return node;
    }

    // RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
    private Node parseRelExp() {
        ArrayList<Node> children = new ArrayList<>();
        Node node = null;
        Node nodep = null;
        int startLine = tokenStream.get(p).getLineNumber();
        node = parseAddExp();
        children.add(node);
        node = NodeFactory.createNode(startLine, tokenStream.get(p - 1).getLineNumber(), SyntaxVarType.REL_EXP, children);
        while (tokenStream.get(p).getType() == Token.TokenType.LSS || tokenStream.get(p).getType() == Token.TokenType.LEQ || tokenStream.get(p).getType() == Token.TokenType.GRE || tokenStream.get(p).getType() == Token.TokenType.GEQ) {
            ArrayList<Node> childrentmp = new ArrayList<>();
            childrentmp.add(node);
            childrentmp.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
            nodep = parseAddExp();
            childrentmp.add(nodep);
            node = NodeFactory.createNode(startLine, tokenStream.get(p - 1).getLineNumber(), SyntaxVarType.REL_EXP, childrentmp);
        }
        return node;
    }


    // VarDecl → 'int' VarDef { ',' VarDef } ';' | 'char' VarDef { ',' VarDef } ';'
    private Node parseVarDecl() {
        ArrayList<Node> children = new ArrayList<>();
        Node node = null;
        int startLine = tokenStream.get(p).getLineNumber();
        if (tokenStream.get(p).getType() == Token.TokenType.INTTK) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        } else if (tokenStream.get(p).getType() == Token.TokenType.CHARTK) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        }
        node = parseVarDef();
        children.add(node);
        while (tokenStream.get(p).getType() == Token.TokenType.COMMA) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
            node = parseVarDef();
            children.add(node);
        }
        if (tokenStream.get(p).getType() == Token.TokenType.SEMICN) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        } else {
            children.add(NodeFactory.createNode(new Token(";", Token.TokenType.SEMICN, tokenStream.get(p).getLineNumber())));
            error += tokenStream.get(p - 1).getLineNumber() + " " + "i\n";
        }
        int endLine = tokenStream.get(p - 1).getLineNumber();
        return NodeFactory.createNode(startLine, endLine, SyntaxVarType.VAR_DECL, children);
    }

    // VarDef → Ident [ '[' ConstExp ']' ] [ '=' InitVal ]
    private Node parseVarDef() {
        ArrayList<Node> children = new ArrayList<>();
        Node node = null;
        int startLine = tokenStream.get(p).getLineNumber();
        if (tokenStream.get(p).getType() == Token.TokenType.IDENFR) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        }
        if (tokenStream.get(p).getType() == Token.TokenType.LBRACK) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
            if (isExp(p)) {
                node = parseConstExp();
                children.add(node);
            }
            if (tokenStream.get(p).getType() == Token.TokenType.RBRACK) {
                children.add(NodeFactory.createNode(tokenStream.get(p)));
                p++;
            } else {
                children.add(NodeFactory.createNode(new Token("]", Token.TokenType.RBRACK, tokenStream.get(p).getLineNumber())));
                error += tokenStream.get(p - 1).getLineNumber() + " " + "k\n";
            }
        }
        if (tokenStream.get(p).getType() == Token.TokenType.ASSIGN) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
            node = parseInitVal();
            children.add(node);
        }
        int endLine = tokenStream.get(p - 1).getLineNumber();
        return NodeFactory.createNode(startLine, endLine, SyntaxVarType.VAR_DEF, children);
    }

    //  InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
    private Node parseInitVal() {
        ArrayList<Node> children = new ArrayList<>();
        Node node = null;
        int startLine = tokenStream.get(p).getLineNumber();
        if (tokenStream.get(p).getType() == Token.TokenType.LBRACE) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
            if (tokenStream.get(p).getType() == Token.TokenType.RBRACE) {
                children.add(NodeFactory.createNode(tokenStream.get(p)));
                p++;
            } else {
                node = parseExp();
                children.add(node);
                while (tokenStream.get(p).getType() == Token.TokenType.COMMA) {
                    children.add(NodeFactory.createNode(tokenStream.get(p)));
                    p++;
                    node = parseExp();
                    children.add(node);
                }
                if (tokenStream.get(p).getType() == Token.TokenType.RBRACE) {
                    children.add(NodeFactory.createNode(tokenStream.get(p)));
                    p++;
                }
            }
        } else if (tokenStream.get(p).getType() == Token.TokenType.STRCON) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        } else {
            node = parseExp();
            children.add(node);
        }
        int endLine = tokenStream.get(p - 1).getLineNumber();
        return NodeFactory.createNode(startLine, endLine, SyntaxVarType.INIT_VAL, children);
    }

    // ConstExp → AddExp
    private Node parseExp() {
        ArrayList<Node> children = new ArrayList<>();
        Node node = null;
        int startLine = tokenStream.get(p).getLineNumber();
        node = parseAddExp();
        children.add(node);
        int endLine = tokenStream.get(p - 1).getLineNumber();
        return NodeFactory.createNode(startLine, endLine, SyntaxVarType.EXP, children);
    }

    // AddExp → MulExp | AddExp ('+' | '−') MulExp
    private Node parseAddExp() {
        ArrayList<Node> children = new ArrayList<>();
        Node node = null;
        Node nodep = null;
        int startLine = tokenStream.get(p).getLineNumber();
        node = parseMulExp();
        children.add(node);
        node = NodeFactory.createNode(startLine, tokenStream.get(p - 1).getLineNumber(), SyntaxVarType.ADD_EXP, children);
        while (tokenStream.get(p).getType() == Token.TokenType.PLUS || tokenStream.get(p).getType() == Token.TokenType.MINU) {
            ArrayList<Node> childrentmp = new ArrayList<>();
            childrentmp.add(node);
            childrentmp.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
            nodep = parseMulExp();
            childrentmp.add(nodep);
            node = NodeFactory.createNode(startLine, tokenStream.get(p - 1).getLineNumber(), SyntaxVarType.ADD_EXP, childrentmp);
        }
        return node;
    }

    // MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
    private Node parseMulExp() {
        ArrayList<Node> children = new ArrayList<>();
        Node node = null;
        Node nodep = null;
        int startLine = tokenStream.get(p).getLineNumber();
        node = parseUnaryExp();
        children.add(node);
        node = NodeFactory.createNode(startLine, tokenStream.get(p - 1).getLineNumber(), SyntaxVarType.MUL_EXP, children);
        while (tokenStream.get(p).getType() == Token.TokenType.MULT || tokenStream.get(p).getType() == Token.TokenType.DIV || tokenStream.get(p).getType() == Token.TokenType.MOD) {
            ArrayList<Node> childrentmp = new ArrayList<>();
            childrentmp.add(node);
            childrentmp.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
            nodep = parseUnaryExp();
            childrentmp.add(nodep);
            node = NodeFactory.createNode(startLine, tokenStream.get(p - 1).getLineNumber(), SyntaxVarType.MUL_EXP, childrentmp);
        }
        return node;
    }

    // 一元表达式 UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
    private Node parseUnaryExp() {
        ArrayList<Node> children = new ArrayList<>();
        Node node = null;
        int startLine = tokenStream.get(p).getLineNumber();
        // System.out.println(p+" "+tokenStream.get(p).getDescription());
        if (tokenStream.get(p).getType() == Token.TokenType.IDENFR && tokenStream.get(p + 1).getType() == Token.TokenType.LPARENT) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
            if (tokenStream.get(p).getType() == Token.TokenType.LPARENT) {
                children.add(NodeFactory.createNode(tokenStream.get(p)));
                p++;
                if (tokenStream.get(p).getType() == Token.TokenType.RPARENT) {
                    children.add(NodeFactory.createNode(tokenStream.get(p)));
                    p++;
                } else {
                    if (isExp(p)) {
                        node = parseFuncRParams();
                        children.add(node);
                    }
                    if (tokenStream.get(p).getType() == Token.TokenType.RPARENT) {
                        children.add(NodeFactory.createNode(tokenStream.get(p)));
                        p++;
                    } else {
                        children.add(NodeFactory.createNode(new Token(")", Token.TokenType.RPARENT, tokenStream.get(p).getLineNumber())));
                        error += tokenStream.get(p - 1).getLineNumber() + " " + "j\n";
                    }
                }
            }
        } else if (tokenStream.get(p).getType() == Token.TokenType.PLUS ||
                tokenStream.get(p).getType() == Token.TokenType.MINU ||
                tokenStream.get(p).getType() == Token.TokenType.NOT) {
            node = parseUnaryOp();
            children.add(node);
            // p++;
            node = parseUnaryExp();
            children.add(node);
        } else {
            node = parsePrimaryExp();
            children.add(node);
        }
        int endLine = tokenStream.get(p - 1).getLineNumber();
        return NodeFactory.createNode(startLine, endLine, SyntaxVarType.UNARY_EXP, children);
    }

    private Node parseNumber() {
        ArrayList<Node> children = new ArrayList<>();
        Node node = null;
        int startLine = tokenStream.get(p).getLineNumber();
        children.add(NodeFactory.createNode(tokenStream.get(p)));
        p++;
        int endLine = tokenStream.get(p - 1).getLineNumber();
        return NodeFactory.createNode(startLine, endLine, SyntaxVarType.NUMBER, children);
    }

    private Node parseCharacter() {
        ArrayList<Node> children = new ArrayList<>();
        Node node = null;
        int startLine = tokenStream.get(p).getLineNumber();
        children.add(NodeFactory.createNode(tokenStream.get(p)));
        p++;
        int endLine = tokenStream.get(p - 1).getLineNumber();
        return NodeFactory.createNode(startLine, endLine, SyntaxVarType.CHARACTER, children);
    }

    // PrimaryExp → '(' Exp ')' | LVal | Number | Character
    private Node parsePrimaryExp() {
        ArrayList<Node> children = new ArrayList<>();
        Node node = null;
        int startLine = tokenStream.get(p).getLineNumber();
        if (tokenStream.get(p).getType() == Token.TokenType.INTCON) {
            node = parseNumber();
            children.add(node);
        } else if (tokenStream.get(p).getType() == Token.TokenType.CHRCON) {
            node = parseCharacter();
            children.add(node);
        } else if (tokenStream.get(p).getType() == Token.TokenType.LPARENT) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
            if (isExp(p)) {
                node = parseExp();
                children.add(node);
            }
            if (tokenStream.get(p).getType() == Token.TokenType.RPARENT) {
                children.add(NodeFactory.createNode(tokenStream.get(p)));
                p++;
            } else {
                children.add(NodeFactory.createNode(new Token(")", Token.TokenType.RPARENT, tokenStream.get(p).getLineNumber())));
                error += tokenStream.get(p - 1).getLineNumber() + " " + "j\n";
            }
        } else {
            node = parseLValExp();
            children.add(node);
        }
        int endLine = tokenStream.get(p - 1).getLineNumber();
        return NodeFactory.createNode(startLine, endLine, SyntaxVarType.PRIMARY_EXP, children);
    }

    // LVal → Ident [ '[' Exp ']' ]
    private Node parseLValExp() {
        ArrayList<Node> children = new ArrayList<>();
        Node node = null;
        int startLine = tokenStream.get(p).getLineNumber();
        if (tokenStream.get(p).getType() == Token.TokenType.IDENFR) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        }
        if (tokenStream.get(p).getType() == Token.TokenType.LBRACK) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
            if (isExp(p)) {
                node = parseExp();
                children.add(node);
            }
            if (tokenStream.get(p).getType() == Token.TokenType.RBRACK) {
                children.add(NodeFactory.createNode(tokenStream.get(p)));
                p++;
            } else {
                children.add(NodeFactory.createNode(new Token("]", Token.TokenType.RBRACK, tokenStream.get(p).getLineNumber())));
                error += tokenStream.get(p - 1).getLineNumber() + " " + "k\n";
            }
        }
        int endLine = tokenStream.get(p - 1).getLineNumber();
        return NodeFactory.createNode(startLine, endLine, SyntaxVarType.LVAL_EXP, children);
    }

    // UnaryOp → '+' | '−' | '!'
    private Node parseUnaryOp() {
        ArrayList<Node> children = new ArrayList<>();
        Node node = null;
        int startLine = tokenStream.get(p).getLineNumber();
        if (tokenStream.get(p).getType() == Token.TokenType.PLUS) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        } else if (tokenStream.get(p).getType() == Token.TokenType.MINU) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        } else if (tokenStream.get(p).getType() == Token.TokenType.NOT) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        }
        int endLine = tokenStream.get(p - 1).getLineNumber();
        return NodeFactory.createNode(startLine, endLine, SyntaxVarType.UNARY_OP, children);
    }

    // FuncRParams → Exp { ',' Exp }
    private Node parseFuncRParams() {
        ArrayList<Node> children = new ArrayList<>();
        Node node = null;
        int startLine = tokenStream.get(p).getLineNumber();
        node = parseExp();
        children.add(node);
        while (tokenStream.get(p).getType() == Token.TokenType.COMMA) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
            node = parseExp();
            children.add(node);
        }
        int endLine = tokenStream.get(p - 1).getLineNumber();
        return NodeFactory.createNode(startLine, endLine, SyntaxVarType.FUNC_REAL_PARAMS, children);
    }

    //  ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';' // i
    private Node parseConstDecl() {
        ArrayList<Node> children = new ArrayList<>();
        Node node = null;
        int startLine = tokenStream.get(p).getLineNumber();
        if (tokenStream.get(p).getType() == Token.TokenType.CONSTTK) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        }
        if (tokenStream.get(p).getType() == Token.TokenType.INTTK) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        } else if (tokenStream.get(p).getType() == Token.TokenType.CHARTK) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        }
        node = parseConstDef();
        children.add(node);
        while (tokenStream.get(p).getType() == Token.TokenType.COMMA) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
            node = parseConstDef();
            children.add(node);
        }
        if (tokenStream.get(p).getType() == Token.TokenType.SEMICN) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        } else {
            children.add(NodeFactory.createNode(new Token(";", Token.TokenType.SEMICN, tokenStream.get(p).getLineNumber())));
            error += tokenStream.get(p - 1).getLineNumber() + " " + "i\n";
        }
        int endLine = tokenStream.get(p - 1).getLineNumber();
        return NodeFactory.createNode(startLine, endLine, SyntaxVarType.CONST_DECL, children);
    }

    // ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal
    private Node parseConstDef() {
        ArrayList<Node> children = new ArrayList<>();
        Node node = null;
        int startLine = tokenStream.get(p).getLineNumber();
        if (tokenStream.get(p).getType() == Token.TokenType.IDENFR) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        }
        if (tokenStream.get(p).getType() == Token.TokenType.LBRACK) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
            if (isExp(p)) {
                node = parseConstExp();
                children.add(node);
            }
            if (tokenStream.get(p).getType() == Token.TokenType.RBRACK) {
                children.add(NodeFactory.createNode(tokenStream.get(p)));
                p++;
            } else {
                children.add(NodeFactory.createNode(new Token("]", Token.TokenType.RBRACK, tokenStream.get(p).getLineNumber())));
                error += tokenStream.get(p - 1).getLineNumber() + " " + "k\n";
            }
        }
        if (tokenStream.get(p).getType() == Token.TokenType.ASSIGN) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
            node = parseConstInitVal();
            children.add(node);
        }
        int endLine = tokenStream.get(p - 1).getLineNumber();
        return NodeFactory.createNode(startLine, endLine, SyntaxVarType.CONST_DEF, children);
    }

    // ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
    private Node parseConstInitVal() {
        ArrayList<Node> children = new ArrayList<>();
        Node node = null;
        int startLine = tokenStream.get(p).getLineNumber();
        if (tokenStream.get(p).getType() == Token.TokenType.LBRACE) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
            if (tokenStream.get(p).getType() == Token.TokenType.RBRACE) {
                children.add(NodeFactory.createNode(tokenStream.get(p)));
                p++;
            } else {
                node = parseConstExp();
                children.add(node);
                while (tokenStream.get(p).getType() == Token.TokenType.COMMA) {
                    children.add(NodeFactory.createNode(tokenStream.get(p)));
                    p++;
                    node = parseConstExp();
                    children.add(node);
                }
                if (tokenStream.get(p).getType() == Token.TokenType.RBRACE) {
                    children.add(NodeFactory.createNode(tokenStream.get(p)));
                    p++;
                }
            }
        } else if (tokenStream.get(p).getType() == Token.TokenType.STRCON) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        } else {
            node = parseConstExp();
            children.add(node);
        }
        int endLine = tokenStream.get(p - 1).getLineNumber();
        return NodeFactory.createNode(startLine, endLine, SyntaxVarType.CONST_INITVAL, children);
    }


    private Node parseConstExp() {
        ArrayList<Node> children = new ArrayList<>();
        Node node = null;
        int startLine = tokenStream.get(p).getLineNumber();
        node = parseAddExp();
        children.add(node);
        int endLine = tokenStream.get(p - 1).getLineNumber();
        return NodeFactory.createNode(startLine, endLine, SyntaxVarType.CONST_EXP, children);
    }

    // FuncDef → FuncType Ident '(' [FuncFParams] ')' Block
    private Node parseFuncDef() {
        ArrayList<Node> children = new ArrayList<>();
        Node node = null;
        int startLine = tokenStream.get(p).getLineNumber();
        node = parseFuncType();
        children.add(node);
        if (tokenStream.get(p).getType() == Token.TokenType.IDENFR) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        }
        if (tokenStream.get(p).getType() == Token.TokenType.LPARENT) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
            if (tokenStream.get(p).getType() == Token.TokenType.RPARENT) {
                children.add(NodeFactory.createNode(tokenStream.get(p)));
                p++;
            } else if (tokenStream.get(p).getType() == Token.TokenType.LBRACE) {
                children.add(NodeFactory.createNode(new Token(")", Token.TokenType.RPARENT, tokenStream.get(p).getLineNumber())));
                error += tokenStream.get(p - 1).getLineNumber() + " " + "j\n";
            } else {
                node = parseFuncFParams();
                children.add(node);
                if (tokenStream.get(p).getType() == Token.TokenType.RPARENT) {
                    children.add(NodeFactory.createNode(tokenStream.get(p)));
                    p++;
                } else {
                    children.add(NodeFactory.createNode(new Token(")", Token.TokenType.RPARENT, tokenStream.get(p).getLineNumber())));
                    error += tokenStream.get(p - 1).getLineNumber() + " " + "j\n";
                }
            }
        }
        node = parseBlock();
        children.add(node);
        int endLine = tokenStream.get(p - 1).getLineNumber();
        return NodeFactory.createNode(startLine, endLine, SyntaxVarType.FUNC_DEF, children);

    }

    //  FuncFParams → FuncFParam { ',' FuncFParam }
    private Node parseFuncFParams() {
        ArrayList<Node> children = new ArrayList<>();
        Node node = null;
        int startLine = tokenStream.get(p).getLineNumber();
        node = parseFuncFParam();
        children.add(node);
        while (tokenStream.get(p).getType() == Token.TokenType.COMMA) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
            node = parseFuncFParam();
            children.add(node);
        }
        int endLine = tokenStream.get(p - 1).getLineNumber();
        return NodeFactory.createNode(startLine, endLine, SyntaxVarType.FUNC_FORMAL_PARAMS, children);
    }

    //  FuncFParam → BType Ident ['[' ']']
    private Node parseFuncFParam() {
        ArrayList<Node> children = new ArrayList<>();
        Node node = null;
        int startLine = tokenStream.get(p).getLineNumber();

        if (tokenStream.get(p).getType() == Token.TokenType.INTTK) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        } else if (tokenStream.get(p).getType() == Token.TokenType.CHARTK) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        }
        if (tokenStream.get(p).getType() == Token.TokenType.IDENFR) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        }
        if (tokenStream.get(p).getType() == Token.TokenType.LBRACK) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
            if (tokenStream.get(p).getType() == Token.TokenType.RBRACK) {
                children.add(NodeFactory.createNode(tokenStream.get(p)));
                p++;
            } else {
                children.add(NodeFactory.createNode(new Token("]", Token.TokenType.RBRACK, tokenStream.get(p).getLineNumber())));
                error += tokenStream.get(p - 1).getLineNumber() + " " + "k\n";
            }
        }
        int endLine = tokenStream.get(p - 1).getLineNumber();
        return NodeFactory.createNode(startLine, endLine, SyntaxVarType.FUNC_FORMAL_PARAM, children);
    }

    private Node parseFuncType() {
        ArrayList<Node> children = new ArrayList<>();
        Node node = null;
        int startLine = tokenStream.get(p).getLineNumber();
        if (tokenStream.get(p).getType() == Token.TokenType.INTTK) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        } else if (tokenStream.get(p).getType() == Token.TokenType.CHARTK) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        } else if (tokenStream.get(p).getType() == Token.TokenType.VOIDTK) {
            children.add(NodeFactory.createNode(tokenStream.get(p)));
            p++;
        }
        int endLine = tokenStream.get(p - 1).getLineNumber();
        return NodeFactory.createNode(startLine, endLine, SyntaxVarType.FUNC_TYPE, children);
    }

    public Boolean isExp(int i) {
        if (tokenStream.get(i).getType() == Token.TokenType.PLUS
                || tokenStream.get(i).getType() == Token.TokenType.MINU ||
                tokenStream.get(i).getType() == Token.TokenType.NOT ||
                tokenStream.get(i).getType() == Token.TokenType.IDENFR ||
                tokenStream.get(i).getType() == Token.TokenType.INTCON ||
                tokenStream.get(i).getType() == Token.TokenType.CHRCON ||
                tokenStream.get(i).getType() == Token.TokenType.LPARENT) {
            return true;
        }
        return false;
    }
}
