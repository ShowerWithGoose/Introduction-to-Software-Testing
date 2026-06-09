package AST;

import IO.*;

import java.io.IOException;

//基本表达式 PrimaryExp → '(' Exp ')' | LVal | Number | Character
public class PrimaryExp extends ASTNode {
    ASTNodes type = ASTNodes.PrimaryExp;
    ExprNode expr = null;

    LValNode lVal = null;

    NumberNode number = null;

    CharacterNode character = null;

    int t;

    public PrimaryExp(ExprNode expr) {
        this.expr = expr;
        this.t = 1;
    }

    public PrimaryExp(LValNode lVal) {
        this.lVal = lVal;
        this.t = 2;
    }

    public PrimaryExp(NumberNode number) {
        this.number = number;
        this.t = 3;
    }

    public PrimaryExp(CharacterNode character) {
        this.character = character;
        this.t = 4;
    }

    public int getT() {
        return t;
    }

    public ASTNodes getType() {
        return type;
    }

    public ExprNode getExpr() {
        return expr;
    }

    public CharacterNode getCharacter() {
        return character;
    }

    public LValNode getlVal() {
        return lVal;
    }

    public NumberNode getNumber() {
        return number;
    }

    
    public void postOrderTraversal(IO io) throws IOException {
        if (expr!= null) {
            io.getParserWriter().write("LPARENT (\n");
            expr.postOrderTraversal(io);
            io.getParserWriter().write("RPARENT )\n");
        }
        if (lVal!= null) lVal.postOrderTraversal(io);
        if (number!= null) number.postOrderTraversal(io);
        if (character!= null) character.postOrderTraversal(io);
        io.getParserWriter().write("<PrimaryExp>\n");
    }

    
    public void postOrderNoPrint() {
        if (expr!= null) {
            expr.postOrderNoPrint();
        }
        if (lVal!= null) lVal.postOrderNoPrint();
        if (number!= null) number.postOrderNoPrint();
        if (character!= null) character.postOrderNoPrint();
    }
}
