package frontend.ast;

import frontend.Token;
import frontend.TokenType;

import java.io.BufferedWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Stmt implements AstNode {
    private final ArrayList<AstNode> stmts;
    private final Token stringConst;

    public enum StmtType {
        ASSIGN, EXP, NONE, IF, FOR, BLOCK, BREAK, CONTINUE, RETURN, GETINT, GETCHAR, PRINTF
    }

    private final StmtType type;

    public Stmt(ArrayList<AstNode> stmts, StmtType type) {
        this.stmts = stmts;
        this.type = type;
        stringConst = null;
    }

    public Stmt(ArrayList<AstNode> stmts, Token stringConst, StmtType type) {
        this.stmts = stmts;
        this.type = type;
        this.stringConst = stringConst;
    }

    @Override
    public String getSymbol() {
        return "<Stmt>";
    }

    @Override
    public void printToFile(BufferedWriter bw) throws IOException {
        switch (type) {
            case ASSIGN:
                stmts.get(0).printToFile(bw);
                bw.write(TokenType.ASSIGN + " =\n");
                stmts.get(1).printToFile(bw);
                bw.write(TokenType.SEMICN + " ;\n");
                break;
            case EXP:
                stmts.get(0).printToFile(bw);
                bw.write(TokenType.SEMICN + " ;\n");
                break;
            case NONE:
                bw.write(TokenType.SEMICN + " ;\n");
                break;
            case BLOCK:
                stmts.get(0).printToFile(bw);
                break;
            case IF:
                bw.write(TokenType.IFTK + " if\n");
                bw.write(TokenType.LPARENT + " (\n");
                stmts.get(0).printToFile(bw); // cond
                bw.write(TokenType.RPARENT + " )\n");
                stmts.get(1).printToFile(bw); // stmt
                if (stmts.size() > 2) {
                    bw.write(TokenType.ELSETK + " else\n");
                    stmts.get(2).printToFile(bw);
                }
                break;
            case FOR:
                bw.write(TokenType.FORTK + " for\n");
                bw.write(TokenType.LPARENT + " (\n");
                for (int i = 0; i < 3; i++) {
                    if (i < stmts.size() - 1 && stmts.get(i) != null) {
                        stmts.get(i).printToFile(bw);
                    }
                    if (i < 2) {
                        bw.write(TokenType.SEMICN + " ;\n");
                    }
                }
                bw.write(TokenType.RPARENT + " )\n");
                stmts.get(stmts.size() - 1).printToFile(bw);
                break;
            case BREAK:
                bw.write(TokenType.BREAKTK + " break\n");
                bw.write(TokenType.SEMICN + " ;\n");
                break;
            case CONTINUE:
                bw.write(TokenType.CONTINUETK + " continue\n");
                bw.write(TokenType.SEMICN + " ;\n");
                break;
            case RETURN:
                bw.write(TokenType.RETURNTK + " return\n");
                if (!stmts.isEmpty()) {
                    stmts.get(0).printToFile(bw);
                }
                bw.write(TokenType.SEMICN + " ;\n");
                break;
            case GETINT:
                stmts.get(0).printToFile(bw);
                bw.write(TokenType.ASSIGN + " =\n");
                bw.write(TokenType.GETINTTK + " getint\n");
                bw.write(TokenType.LPARENT + " (\n");
                bw.write(TokenType.RPARENT + " )\n");
                bw.write(TokenType.SEMICN + " ;\n");
                break;
            case GETCHAR:
                stmts.get(0).printToFile(bw);
                bw.write(TokenType.ASSIGN + " =\n");
                bw.write(TokenType.GETCHARTK + " getchar\n");
                bw.write(TokenType.LPARENT + " (\n");
                bw.write(TokenType.RPARENT + " )\n");
                bw.write(TokenType.SEMICN + " ;\n");
                break;
            case PRINTF:
                bw.write(TokenType.PRINTFTK + " printf\n");
                bw.write(TokenType.LPARENT + " (\n");
                bw.write(stringConst + "\n");
                for (AstNode astNode : stmts) {
                    bw.write(TokenType.COMMA + " ,\n");
                    astNode.printToFile(bw);
                }
                bw.write(TokenType.RPARENT + " )\n");
                bw.write(TokenType.SEMICN + " ;\n");
                break;
            default:
                break;
        }
        bw.write(getSymbol() + "\n");
    }
}
