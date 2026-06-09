package frontend.nodes;

import frontend.*;

public class Stmt extends Node {
    public Stmt() {
        super(NodeType.STMT);
    }

    public static Node parse() {
        Stmt stmt = new Stmt();
        switch (Lexer.INSTANCE.getLexType()) {
            case LBRACE -> stmt.parseAndAdd(NodeRegistry.BLOCK);
            case IFTK -> {
                stmt.parseAndAdd(NodeRegistry.TERMINAL);
                stmt.terminalCheck(LexType.LPARENT);
                stmt.parseAndAdd(NodeRegistry.COND);
                stmt.terminalCheck(LexType.RPARENT, ErrorType.j);
                stmt.parseAndAdd(NodeRegistry.STMT);
                if (Lexer.INSTANCE.getLexType() == LexType.ELSETK) {
                    stmt.parseAndAdd(NodeRegistry.TERMINAL);
                    stmt.parseAndAdd(NodeRegistry.STMT);
                }
            }
            case FORTK -> {
                stmt.parseAndAdd(NodeRegistry.TERMINAL);
                stmt.terminalCheck(LexType.LPARENT);
                if (Lexer.INSTANCE.getLexType() == LexType.IDENFR) {
                    stmt.parseAndAdd(NodeRegistry.FOR_STMT);
                }
                stmt.terminalCheck(LexType.SEMICN);
                if (Lexer.INSTANCE.getLexType() != LexType.SEMICN) {
                    stmt.parseAndAdd(NodeRegistry.COND);
                }
                stmt.terminalCheck(LexType.SEMICN);
                if (Lexer.INSTANCE.getLexType() == LexType.IDENFR) {
                    stmt.parseAndAdd(NodeRegistry.FOR_STMT);
                }
                stmt.terminalCheck(LexType.RPARENT);
                stmt.parseAndAdd(NodeRegistry.STMT);
            }
            case BREAKTK, CONTINUETK -> {
                stmt.parseAndAdd(NodeRegistry.TERMINAL);
                stmt.terminalCheck(LexType.SEMICN, ErrorType.i);
            }
            case RETURNTK -> {
                stmt.parseAndAdd(NodeRegistry.TERMINAL);
                if (Lexer.INSTANCE.getLexType() != LexType.SEMICN) {
                    stmt.parseAndAdd(NodeRegistry.EXP);
                }
                stmt.terminalCheck(LexType.SEMICN, ErrorType.i);
            }
            case PRINTFTK -> {
                stmt.parseAndAdd(NodeRegistry.TERMINAL);
                stmt.terminalCheck(LexType.LPARENT);
                stmt.terminalCheck(LexType.STRCON);
                while (Lexer.INSTANCE.getLexType() == LexType.COMMA) {
                    stmt.parseAndAdd(NodeRegistry.TERMINAL);
                    stmt.parseAndAdd(NodeRegistry.EXP);
                }
                stmt.terminalCheck(LexType.RPARENT, ErrorType.j);
                stmt.terminalCheck(LexType.SEMICN, ErrorType.i);
            }
            case SEMICN -> stmt.parseAndAdd(NodeRegistry.TERMINAL);
            default -> {
                PRINT = false;
                stmt.parseAndAdd(NodeRegistry.EXP);
                PRINT = true;
                if (Lexer.INSTANCE.getLexType() == LexType.ASSIGN) {
                    Node temp = unpackExp(stmt.get(0));
                    temp.print();
                    stmt.set(0, temp);
                    stmt.parseAndAdd(NodeRegistry.TERMINAL);
                    if (Lexer.INSTANCE.getLexType() == LexType.GETCHARTK ||
                            Lexer.INSTANCE.getLexType() == LexType.GETINTTK) {
                        stmt.parseAndAdd(NodeRegistry.TERMINAL);
                        stmt.terminalCheck(LexType.LPARENT);
                        stmt.terminalCheck(LexType.RPARENT, ErrorType.j);
                    } else {
                        stmt.parseAndAdd(NodeRegistry.EXP);
                    }
                } else {
                    stmt.get(0).print();
                }
                stmt.terminalCheck(LexType.SEMICN, ErrorType.i);
            }
        }
        return stmt;
    }

    private static Node unpackExp(Node node) {
        return node.get(0).get(0).get(0).get(0).get(0);
    }
}
