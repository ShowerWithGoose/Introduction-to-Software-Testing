package node;

import token.Token;

import java.io.IOException;
import java.util.List;

import static utils.IO.writeParser;

public class PrimaryExp {
    private String nodeName;
    private Token lparentToken;
    private Exp exp;
    private Token rparentToken;
    private LVal lVal;
    private Number number;
    private Character character;

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
        if(lparentToken!=null){
            writeParser(lparentToken.toString());
            exp.print();
            writeParser(rparentToken.toString());
        }
        else if(lVal!=null)
            lVal.print();
        else if(number!=null)
            number.print();
        else
            character.print();
        writeParser(nodeName);
    }
}
