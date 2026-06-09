package parser;

import token.Token;
import token.TokenType;

import java.util.List;

import AST.ASTNode;

import error.Error;

public class Parser {
    private List<Token> tokens;
    private int curPos;

    public Parser() {}
    public Parser(List<Token> tokens) {
        this.tokens = tokens;
        this.curPos = 0;
    }

    public ASTNode buildAST() {
        return CompUnit();
    }

    private Token getTok() { return tokens.get(curPos++); }

    private String sym() { return tokens.get(curPos).getContent(); }
    private String nextSym() { return tokens.get(curPos+1).getContent(); }
    private String nextNextSym() { return tokens.get(curPos+2).getContent(); }
    private TokenType type() { return tokens.get(curPos).getType(); }
    private TokenType nextType() { return tokens.get(curPos+1).getType(); }

    private ASTNode buildLeaf() {
        ASTNode leaf = new ASTNode();
        Token token = getTok();
        leaf.setTerminator(token);
        System.out.println("---" + token.getContent() + "---");
        return leaf;
    }; 

    private boolean isLVal(int pos) {
        int curLine, line;
        Token tok;

        tok = tokens.get(pos);
        line = tok.getLineNum();
        curLine = line;

        while (true) {
            if (line > curLine) return false;
            if (tok.getContent().equals(";")) return false;
            else if (tok.getContent().equals("=")) return true;

            pos += 1;
            tok = tokens.get(pos);
            line = tok.getLineNum();
        }
    }
    
    /* syntax */
    private ASTNode CompUnit() {
        // System.out.println("CompUnit");
        ASTNode node = new ASTNode(); 
        node.setNonTerminator("CompUnit");
        
        while ((sym().equals("const")) || ((sym().equals("int") || sym().equals("char")) && nextType() == TokenType.IDENFR && !nextNextSym().equals("("))) {
            node.addChild(Decl());
        }

        while ((sym().equals("void") || sym().equals("int") || sym().equals("char")) && nextType() == TokenType.IDENFR && nextNextSym().equals("(")) {
            node.addChild(FuncDef());
        }
        
        if (sym().equals("int") && nextSym().equals("main")) {
            node.addChild(MainFuncDef());
        } else {}
        
         System.out.println("CompUnit");
        return node;
    }

    private ASTNode Decl() {
        // System.out.println("Decl");
        ASTNode node = new ASTNode();
        node.setNonTerminator("Decl");

        if (sym().equals("const")) {
            node.addChild(ConstDecl());
        } else {
            node.addChild(VarDecl());
        }

         System.out.println("Decl");
        return node;
    }

    private ASTNode ConstDecl() {
        // System.out.println("ConstDecl");
        ASTNode node = new ASTNode();
        node.setNonTerminator("ConstDecl");

        if (sym().equals("const")) {
            node.addChild(buildLeaf());
        } else {}

        node.addChild(BType());
        node.addChild(ConstDef());

        while (sym().equals(",")) {
            node.addChild(buildLeaf());
            node.addChild(ConstDef());
        }

        if (sym().equals(";")) {
            node.addChild(buildLeaf());
        } else {
            Error.addError(tokens.get(curPos-1).getLineNum(), 'i');
        }

        System.out.println("ConstDecl");
        return node;
    }

    private ASTNode BType() {
        // System.out.println("BType");
        ASTNode node = new ASTNode();
        node.setNonTerminator("Btype");

        if (sym().equals("char")) { 
            node.addChild(buildLeaf());
        } else if (sym().equals("int")) {
            node.addChild(buildLeaf());
        } else {}

        System.out.println("BType");
        return node;
    }

    private ASTNode ConstDef() {
        // System.out.println("ConstDef");
        ASTNode node = new ASTNode();
        node.setNonTerminator("ConstDef");

        if (type() == TokenType.IDENFR) {
            node.addChild(buildLeaf());
        } else {}

        while (sym().equals("[")) {
            node.addChild(buildLeaf());
            node.addChild(ConstExp());
            if (sym().equals("]")) {
                node.addChild(buildLeaf());
            } else {
                Error.addError(tokens.get(curPos-1).getLineNum(), 'k');
            }
        }

        if (sym().equals("=")) {
            node.addChild(buildLeaf());
        } else {}
        node.addChild(ConstInitval());

        System.out.println("ConstDef");
        return node;
    }

    private ASTNode ConstInitval() {
        // System.out.println("ConstInitval");
        ASTNode node = new ASTNode();
        node.setNonTerminator("ConstInitVal");

        if (sym().equals("(") || sym().equals("+") || sym().equals("-") || sym().equals("!") || type() == TokenType.INTCON || type() == TokenType.CHRCON || type() == TokenType.IDENFR) {
            node.addChild(ConstExp());
        } else if (sym().equals("{")) {
            node.addChild(buildLeaf());
            if (sym().equals("(") || sym().equals("+") || sym().equals("-") || sym().equals("!") || type() == TokenType.INTCON || type() == TokenType.CHRCON || type() == TokenType.IDENFR) {
                node.addChild(ConstExp());
                while (sym().equals(",")) {
                    node.addChild(buildLeaf());
                    node.addChild(ConstExp());
                }
            }
            if (sym().equals("}")) node.addChild(buildLeaf());
        } else if (type() == TokenType.STRCON) {
            node.addChild(buildLeaf());
        } else  {}

        System.out.println("ConstInival");
        return node;
    }

    private ASTNode VarDecl() {
        // System.out.println("VarDecl");
        ASTNode node = new ASTNode();
        node.setNonTerminator("VarDecl");

        node.addChild(BType());
        node.addChild(VarDef());
        while (sym().equals(",")) {
            node.addChild(buildLeaf());
            node.addChild(VarDef());
        }
        if (sym().equals(";")) {
            node.addChild(buildLeaf());
        } else {
            Error.addError(tokens.get(curPos-1).getLineNum(), 'i');
        }

        System.out.println("VarDecl");
        return node;
    }
    
    private ASTNode VarDef() {
        // System.out.println("VarDef");
        ASTNode node = new ASTNode();
        node.setNonTerminator("VarDef");

        if (type() == TokenType.IDENFR) node.addChild(buildLeaf());
        if (sym().equals("[")) {
            node.addChild(buildLeaf());
            node.addChild(ConstExp());
            if (sym().equals("]")) {
                node.addChild(buildLeaf());
            } else {
                Error.addError(tokens.get(curPos-1).getLineNum(), 'k');
            }
        }
        if (sym().equals("=")) {
            node.addChild(buildLeaf());
            node.addChild(InitVal());
        }
        
        System.out.println("VarDef");
        return node;
    }

    private ASTNode InitVal() {
        // System.out.println("InitVal");
        ASTNode node = new ASTNode();
        node.setNonTerminator("InitVal");

        if (sym().equals("(") || sym().equals("+") || sym().equals("-") || sym().equals("!") || type() == TokenType.INTCON || type() == TokenType.CHRCON || type() == TokenType.IDENFR) {
            node.addChild(Exp());
        } else if (sym().equals("{")) {
            node.addChild(buildLeaf());
            if (sym().equals("(") || sym().equals("+") || sym().equals("-") || sym().equals("!") || type() == TokenType.INTCON || type() == TokenType.CHRCON || type() == TokenType.IDENFR) {
                node.addChild(Exp());
                while (sym().equals(",")) {
                    node.addChild(buildLeaf());
                    node.addChild(Exp());
                }
                if (sym().equals("}")) node.addChild(buildLeaf());
            }   
        } else if (type() == TokenType.STRCON) {
            node.addChild(buildLeaf());
        }

        System.out.println("InitVal");
        return node;
    }

    private ASTNode FuncDef() {
        // System.out.println("FuncDef");
        ASTNode node = new ASTNode();
        node.setNonTerminator("FuncDef");

        node.addChild(FuncType());
        if (type() == TokenType.IDENFR) {
            node.addChild(buildLeaf());
        } else {}
        if (sym().equals("(")) node.addChild(buildLeaf());
        if (sym().equals("int") || sym().equals("char")) node.addChild(FuncFParams());
        if (sym().equals(")")) {
            node.addChild(buildLeaf());
        } else {
            Error.addError(tokens.get(curPos-1).getLineNum(), 'j');
        }
        node.addChild(Block());
        
        System.out.println("FuncDef");
        return node;
    }

    private ASTNode MainFuncDef() {
        // System.out.println("MainFuncDef");
        ASTNode node = new ASTNode();
        node.setNonTerminator("MainFuncDef");

        if (sym().equals("int")) node.addChild(buildLeaf());
        if (sym().equals("main")) node.addChild(buildLeaf());
        if (sym().equals("(")) node.addChild(buildLeaf());
        if (sym().equals(")")) {
            node.addChild(buildLeaf());
        } else {
            Error.addError(tokens.get(curPos-1).getLineNum(), 'j');
        }
        node.addChild(Block());

        System.out.println("MainFuncDef");
        return node;
    }

    private ASTNode FuncType() {
        // System.out.println("FuncType");
        ASTNode node = new ASTNode();
        node.setNonTerminator("FuncType");

        if (sym().equals("void")) {
            node.addChild(buildLeaf());
        } else if (sym().equals("int")) {
            node.addChild(buildLeaf());
        } else if (sym().equals("char")) {
            node.addChild(buildLeaf());
        }

        System.out.println("FuncType");
        return node;
    }

    private ASTNode FuncFParams() {
        // System.out.println("FuncFParams");
        ASTNode node = new ASTNode();
        node.setNonTerminator("FuncFParams");

        node.addChild(FuncFParam());
        while (sym().equals(",")) {
            node.addChild(buildLeaf());
            node.addChild(FuncFParam());
        }

        System.out.println("FuncFParams");
        return node;
    }

    private ASTNode FuncFParam() {
        // System.out.println("FuncFParam");
        ASTNode node = new ASTNode();
        node.setNonTerminator("FuncFParam");

        node.addChild(BType());
        if (type() == TokenType.IDENFR) {
            node.addChild(buildLeaf());
        }
        if (sym().equals("["))  {
            node.addChild(buildLeaf());
            if (sym().equals("]")) {
                node.addChild(buildLeaf());
            } else {
                Error.addError(tokens.get(curPos-1).getLineNum(), 'k');
            }
        }

        System.out.println("FuncFParam");
        return node;
    }

    private ASTNode Block() {
        // System.out.println("Block");
        ASTNode node = new ASTNode();
        node.setNonTerminator("Block");

        if (sym().equals("{")) node.addChild(buildLeaf());
        while (sym().equals("const") || sym().equals("int") || sym().equals("char") || type() == TokenType.IDENFR || sym().equals(";") || sym().equals("(") || sym().equals("+") || sym().equals("-") || sym().equals("!") || type() == TokenType.INTCON || type() == TokenType.CHRCON ||
               sym().equals("{") || sym().equals("if") || sym().equals("for") || sym().equals("break") || sym().equals("continue") || sym().equals("return") || sym().equals("printf")) {
            node.addChild(BlockItem());
        }
        if (sym().equals("}")) node.addChild(buildLeaf());

        System.out.println("Block");
        return node;
    }

    private ASTNode BlockItem() {
        // System.out.println("BlockItem");
        ASTNode node = new ASTNode();
        node.setNonTerminator("BlockItem");

        if (sym().equals("const") || sym().equals("int") || sym().equals("char")) {
            node.addChild(Decl());
        } else if (type() == TokenType.IDENFR || sym().equals(";") || sym().equals("(") || sym().equals("+") || sym().equals("-") || sym().equals("!") || type() == TokenType.INTCON || type() == TokenType.CHRCON ||
                   sym().equals("{") || sym().equals("if") || sym().equals("for") || sym().equals("break") || sym().equals("continue") || sym().equals("return") || sym().equals("printf")) {
            node.addChild(Stmt());
        }

        System.out.println("BlockItem");
        return node;
    }

    private ASTNode Stmt() {
        // System.out.println("Stmt");
        ASTNode node = new ASTNode();
        node.setNonTerminator("Stmt");

        if (sym().equals("{")) { // Block
            node.addChild(Block());
        } else if (sym().equals("if")) { 
            node.addChild(buildLeaf());
            if (sym().equals("(")) node.addChild(buildLeaf());
            node.addChild(Cond());
            if (sym().equals(")")) {
                node.addChild(buildLeaf());
            } else {
                Error.addError(tokens.get(curPos-1).getLineNum(), 'j');
            }
            node.addChild(Stmt());
            while (sym().equals("else")) {
                node.addChild(buildLeaf());
                node.addChild(Stmt());
            }
        } else if (sym().equals("for")) {
            node.addChild(buildLeaf());
            if (sym().equals("(")) node.addChild(buildLeaf());
            if (type() == TokenType.IDENFR) {
                node.addChild(ForStmt());
            }
            if (sym().equals(";")) node.addChild(buildLeaf());
            if (sym().equals("(") || sym().equals("+") || sym().equals("-") || sym().equals("!") || type() == TokenType.INTCON || type() == TokenType.CHRCON || type() == TokenType.IDENFR) {
                node.addChild(Cond());
            }
            if (sym().equals(";")) node.addChild(buildLeaf());
            if (type() == TokenType.IDENFR) {
                node.addChild(ForStmt());
            }
            if (sym().equals(")")) node.addChild(buildLeaf());
            node.addChild(Stmt());
        } else if (sym().equals("break")) {
            node.addChild(buildLeaf());
            if (sym().equals(";")) {
                node.addChild(buildLeaf());
            } else {
                Error.addError(tokens.get(curPos-1).getLineNum(), 'i');
            }
        } else if (sym().equals("continue")) {
            node.addChild(buildLeaf());
            if (sym().equals(";")) {
                node.addChild(buildLeaf());
            } else {
                Error.addError(tokens.get(curPos-1).getLineNum(), 'i');
            }
        } else if (sym().equals("return")) {
            node.addChild(buildLeaf());
            if (sym().equals("(") || sym().equals("+") || sym().equals("-") || sym().equals("!") || type() == TokenType.INTCON || type() == TokenType.CHRCON || type() == TokenType.IDENFR) {
                node.addChild(Exp());
            }
            if (sym().equals(";")) {
                node.addChild(buildLeaf());
            } else {
                Error.addError(tokens.get(curPos-1).getLineNum(), 'i');
            }
        } else if (sym().equals("printf")) {
            node.addChild(buildLeaf());
            if (sym().equals("(")) node.addChild(buildLeaf());
            if (type() == TokenType.STRCON) node.addChild(buildLeaf());
            while (sym().equals(",")) {
                node.addChild(buildLeaf());
                node.addChild(Exp());
            }
            if (sym().equals(")")) {
                node.addChild(buildLeaf());
            } else {
                Error.addError(tokens.get(curPos-1).getLineNum(), 'j');
            }
            if (sym().equals(";")) {
                node.addChild(buildLeaf());
            } else {
                Error.addError(tokens.get(curPos-1).getLineNum(), 'i');
            }
        } else {
            if (!isLVal(curPos)) {
                if (sym().equals("(") || sym().equals("+") || sym().equals("-") || sym().equals("!") || type() == TokenType.INTCON || type() == TokenType.CHRCON || type() == TokenType.IDENFR) {
                    node.addChild(Exp());
                }
                if (sym().equals(";")) {
                    node.addChild(buildLeaf());
                } else {
                    Error.addError(tokens.get(curPos-1).getLineNum(), 'i');
                }
            } else {
                node.addChild(LVal());
                if (sym().equals("=")) node.addChild(buildLeaf());
                if (sym().equals("getint") || sym().equals("getchar")) {
                    node.addChild(buildLeaf());
                    if (sym().equals("(")) node.addChild(buildLeaf());
                    if (sym().equals(")")) {
                        node.addChild(buildLeaf());
                    } else {
                        Error.addError(tokens.get(curPos-1).getLineNum(), 'j');
                    }
                    if (sym().equals(";")) {
                        node.addChild(buildLeaf());
                    } else {
                        Error.addError(tokens.get(curPos-1).getLineNum(), 'i');
                    }
                } else {
                    node.addChild(Exp());
                    if (sym().equals(";")) {
                        node.addChild(buildLeaf());
                    } else {
                        Error.addError(tokens.get(curPos-1).getLineNum(), 'i');
                    }
                }
            }
        }

        System.out.println("Stmt");
        return node;
    }

    private ASTNode ForStmt() {
        // System.out.println("ForStmt");
        ASTNode node = new ASTNode();
        node.setNonTerminator("ForStmt");

        node.addChild(LVal());
        if (sym().equals("=")) node.addChild(buildLeaf());
        node.addChild(Exp());

        System.out.println("ForStmt");
        return node;
    }

    private ASTNode Exp() {
        // System.out.println("Exp");
        ASTNode node = new ASTNode();
        node.setNonTerminator("Exp");

        node.addChild(AddExp());

        System.out.println("Exp");
        return node;
    } 

    private ASTNode Cond() {
        // System.out.println("Cond");
        ASTNode node = new ASTNode();
        node.setNonTerminator("Cond");

        node.addChild(LOrExp());

        System.out.println("Cond");
        return node;
    }

    private ASTNode LVal() {
        // System.out.println("LVal");
        ASTNode node = new ASTNode();
        node.setNonTerminator("LVal");

        if (type() == TokenType.IDENFR) node.addChild(buildLeaf());
        if (sym().equals("[")) {
            node.addChild(buildLeaf());
            node.addChild(Exp());
            if (sym().equals("]")) {
                node.addChild(buildLeaf());
            } else {
                Error.addError(tokens.get(curPos-1).getLineNum(), 'k');
            }
        }

        System.out.println("LVal");
        return node;
    }

    private ASTNode PrimaryExp() {
        // System.out.println("PrimaryExp");
        ASTNode node = new ASTNode();
        node.setNonTerminator("PrimaryExp");

        if (sym().equals("(")) {
            node.addChild(buildLeaf());
            node.addChild(Exp());
            if (sym().equals(")")) {
                node.addChild(buildLeaf());
            } else {
                Error.addError(tokens.get(curPos-1).getLineNum(), 'j');
            }
        } else if (type() == TokenType.IDENFR) {
            node.addChild(LVal());
        } else if (type() == TokenType.INTCON) {
            node. addChild(Number());
        } else if (type() == TokenType.CHRCON) {
            node.addChild(Character());
        }

        System.out.println("PrimaryExp");
        return node;
    }

    private ASTNode Number() {
        // System.out.println("Number");
        ASTNode node = new ASTNode();
        node.setNonTerminator("Number");

        if (type() == TokenType.INTCON) node.addChild(buildLeaf());

        System.out.println("Number");
        return node;
    }

    private ASTNode Character() {
        // System.out.println("Character");
        ASTNode node = new ASTNode();
        node.setNonTerminator("Character");

        if (type() == TokenType.CHRCON) node.addChild(buildLeaf());

        System.out.println("Character");
        return node;
    }

    private ASTNode UnaryExp() {
        // System.out.println("UnaryExp");
        ASTNode node = new ASTNode();
        node.setNonTerminator("UnaryExp");

        if (sym().equals("(") || (type() == TokenType.IDENFR && !nextSym().equals("(")) || type() == TokenType.INTCON || type() == TokenType.CHRCON) {
            node.addChild(PrimaryExp());
        } else if (type() == TokenType.IDENFR && nextSym().equals("(")) {
            node.addChild(buildLeaf());
            if (sym().equals("(")) node.addChild(buildLeaf());
            if (sym().equals("(") || sym().equals("+") || sym().equals("-") || sym().equals("!") || type() == TokenType.INTCON || type() == TokenType.CHRCON || type() == TokenType.IDENFR) node.addChild(FuncRParams());
            if (sym().equals(")")) {
                node.addChild(buildLeaf());
            } else {
                Error.addError(tokens.get(curPos-1).getLineNum(), 'j');
            }
        } else if (sym().equals("+") || sym().equals("-") || sym().equals("!")) {
            node.addChild(UnaryOp());
            node.addChild(UnaryExp());
        }

        System.out.println("UnaryExp");
        return node;
    }

    private ASTNode UnaryOp() {
        // System.out.println("UnaryOp");
        ASTNode node = new ASTNode();
        node.setNonTerminator("UnaryOp");

        if (sym().equals("+") || sym().equals("-") || sym().equals("!")) node.addChild(buildLeaf());

        System.out.println("UnaryOp");
        return node;
    }
    
    private ASTNode FuncRParams() {
        // System.out.println("FuncRParams");
        ASTNode node = new ASTNode();
        node.setNonTerminator("FuncRParams");

        node.addChild(Exp());
        while (sym().equals(",")) {
            node.addChild(buildLeaf());
            node.addChild(Exp());
        }

        System.out.println("FuncRParams");
        return node;
    }

    private ASTNode MulExp() {
        // System.out.println("MulExp");
        ASTNode node = new ASTNode(), tmp;
        node.setNonTerminator("MulExp");
        
        node.addChild(UnaryExp());
        while (sym().equals("*") || sym().equals("/") || sym().equals("%")) {
            tmp = node;
            node = new ASTNode();
            node.setNonTerminator("MulExp");
            node.addChild(tmp);
            node.addChild(buildLeaf());
            node.addChild(UnaryExp());
        }
        
        System.out.println("MulExp");
        return node;
    }

    private ASTNode AddExp() {
         System.out.println("AddExp");
        ASTNode node = new ASTNode(), tmp;
        node.setNonTerminator("AddExp");

        node.addChild(MulExp());
        while (sym().equals("+") || sym().equals("-")) {
            tmp = node;
            node = new ASTNode();
            node.setNonTerminator("AddExp");
            node.addChild(tmp);
            node.addChild(buildLeaf());
            node.addChild(MulExp());
        }

        System.out.println("AddExp");
        return node;
    }

    private ASTNode RelExp() {
        // System.out.println("RelExp");
        ASTNode node = new ASTNode(), tmp;
        node.setNonTerminator("RelExp");

        node.addChild(AddExp());
        while (sym().equals("<") || sym().equals(">") || sym().equals("<=") || sym().equals(">=")) {
            tmp = node;
            node = new ASTNode();
            node.setNonTerminator("RelExp");
            node.addChild(tmp);
            node.addChild(buildLeaf());
            node.addChild(AddExp());
        }

        System.out.println("RelExp");
        return node;
    }

    private ASTNode EqExp() {
        // System.out.println("EqExp");
        ASTNode node = new ASTNode(), tmp;
        node.setNonTerminator("EqExp");

        node.addChild(RelExp());
        while (sym().equals("==") || sym().equals("!=")) {
            tmp = node;
            node = new ASTNode();
            node.setNonTerminator("EqExp");
            node.addChild(tmp);
            node.addChild(buildLeaf());
            node.addChild(RelExp());
        }

        System.out.println("EqExp");
        return node;
    }

    private ASTNode LAndExp() {
         System.out.println("LAndExp");
        ASTNode node = new ASTNode(), tmp;
        node.setNonTerminator("LAndExp");

        node.addChild(EqExp());
        while (sym().equals("&&")) {
            tmp = node;
            node = new ASTNode();
            node.setNonTerminator("LAndExp");
            node.addChild(tmp);
            node.addChild(buildLeaf());
            node.addChild(EqExp());
        }

        System.out.println("LAndExp");
        return node;
    }

    private ASTNode LOrExp() {
         System.out.println("LOrExp");
        ASTNode node = new ASTNode(), tmp;
        node.setNonTerminator("LOrExp");

        node.addChild(LAndExp());
        while (sym().equals("||")) {
            tmp = node;
            node = new ASTNode();
            node.setNonTerminator("LOrExp");
            node.addChild(tmp);
            node.addChild(buildLeaf());
            node.addChild(LAndExp());
        }

        System.out.println("LOrExp");
        return node;
    }

    private ASTNode ConstExp() {
        // System.out.println("ConstExp");
        ASTNode node = new ASTNode();
        node.setNonTerminator("ConstExp");

        node.addChild(AddExp());

        System.out.println("ConstExp");
        return node;
    }
}