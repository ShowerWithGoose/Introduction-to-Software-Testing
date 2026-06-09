package frontend.parser.node;

import frontend.lexer.Token;
import frontend.parser.ParserType;
import frontend.parser.TreeNode;

public class PrimaryExp extends TreeNode {
    private Token lToken = null;
    private Token rToken = null;
    private Exp exp = null;
    private LVal lVal = null;
    private Character character = null;

    public void setlToken(Token lToken) {
        this.lToken = lToken;
    }

    public void setrToken(Token rToken) {
        this.rToken = rToken;
    }

    public void setExp(Exp exp) {
        this.exp = exp;
    }

    public void setlVal(LVal lVal) {
        this.lVal = lVal;
    }

    public void setCharacter(Character character) {
        this.character = character;
    }

    public void setNumber(Number number) {
        this.number = number;
    }

    private Number number = null;
    public PrimaryExp(ParserType parserType, Token token) {
        super(parserType, token);
    }
}
