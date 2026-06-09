package frontend.treenode;

import frontend.token.Token;

import java.io.IOException;

import static frontend.executor.Parser.writeParser;

public class PrimaryExp {
    public String nodeName;
    public Token lparentToken, rparentToken;
    public Exp exp;
    public LVal lVal;
    public Number number;
    public Character character;

    public PrimaryExp(String nodeName, Token lparentToken, Exp exp, Token rparentToken, LVal lVal, Number number, Character character) {
        this.nodeName = nodeName;
        this.lparentToken = lparentToken;
        this.exp = exp;
        this.rparentToken = rparentToken;
        this.lVal = lVal;
        this.number = number;
        this.character = character;
    }

    public void print() throws IOException {
        if (lparentToken != null) {
            writeParser(lparentToken.getTypeAndContent());
            exp.print();
            writeParser(rparentToken.getTypeAndContent());
        } else if (lVal != null)
            lVal.print();
        else if (number != null)
            number.print();
        else
            character.print();
        writeParser(nodeName);
    }
}
