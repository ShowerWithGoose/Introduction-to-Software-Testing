package frontend.Parser.AST;

import frontend.Lexer.TokenType;

public class Stmt extends AstNode{

    public void parse() {
        if (getNowTokenType() == TokenType.IDENFR) {
            int curPos = AstNode.pos;
            AstNode.print = 0;
            Exp exp = new Exp();
            exp.parse();
            AstNode.print = 1;
            if (getNowTokenType() == TokenType.ASSIGN) {
                AstNode.pos = curPos;
                LVal lVal = new LVal();
                lVal.parse();
                append(1);
                if (getNowTokenType() == TokenType.GETINTTK ||
                        getNowTokenType() == TokenType.GETCHARTK) {
                    append(2);
                    j_error();
                    i_error();
                } else {
                    exp = new Exp();
                    exp.parse();
                    i_error();
                }
            } else {
                AstNode.pos = curPos;
                while (getNowTokenType() != TokenType.SEMICN) {
                    exp = new Exp();
                    exp.parse();
                }
                i_error();
            }
        } else if (getNowTokenType() == TokenType.SEMICN) {
            append(1);
        } else if (getNowTokenType() == TokenType.LBRACE) {
            Block block = new Block();
            block.parse();
        } else if (getNowTokenType() == TokenType.IFTK) {
            append(2);
            Cond cond = new Cond();
            cond.parse();
            j_error();
            Stmt stmt = new Stmt();
            stmt.parse();
            if (getNowTokenType() == TokenType.ELSETK) {
                append(1);
                Stmt stmt1 = new Stmt();
                stmt1.parse();
            }
        } else if (getNowTokenType() == TokenType.FORTK) {
            append(2);
            if (getNowTokenType() != TokenType.SEMICN) {
                ForStmt forStmt = new ForStmt();
                forStmt.parse();
            }
            append(1);
            if (getNowTokenType() != TokenType.SEMICN) {
                Cond cond = new Cond();
                cond.parse();
            }
            append(1);
            if (getNowTokenType() != TokenType.RPARENT) {
                ForStmt forStmt = new ForStmt();
                forStmt.parse();
            }
            append(1);
            Stmt stmt = new Stmt();
            stmt.parse();
        } else if (getNowTokenType() == TokenType.BREAKTK ||
        getNowTokenType() == TokenType.CONTINUETK) {
            append(1);
            i_error();
        } else if (getNowTokenType() == TokenType.RETURNTK) {
            append(1);
            if (getNowTokenType() != TokenType.SEMICN) {
                Exp exp = new Exp();
                exp.parse();
            }
            i_error();
        } else if (getNowTokenType() == TokenType.PRINTFTK) {
            append(3);
            while (getNowTokenType() != TokenType.RPARENT) {
                append(1);
                Exp exp = new Exp();
                exp.parse();
            }
            j_error();
            i_error();
        } else if(getNowTokenType() == TokenType.LPARENT ||
                getNowTokenType() == TokenType.IDENFR ||
                getNowTokenType() == TokenType.INTCON ||
                getNowTokenType() == TokenType.CHRCON ||
                getNowTokenType() == TokenType.NOT ||
                getNowTokenType() == TokenType.PLUS ||
                getNowTokenType() == TokenType.MINU ) {
            while (getNowTokenType() != TokenType.SEMICN) {
                Exp exp = new Exp();
                exp.parse();
            }
            i_error();
        } else {
            i_error();
        }
        stringBuilder.append("<Stmt>").append("\n");
    }
}
