package node;

import token.Token;

/**
 * ClassName: PrimaryExp
 * Package: node
 * Description:
 *
 * @Author
 * @Create 2024/10/4 11:31
 * @Version 1.0
 */
public class PrimaryExp extends Node {
    // PrimaryExp -> '(' Exp ')' | LVal | Number | Character
    public Token lparent;
    public Token rparent;
    public Exp exp;
    public LVal lVal;
    public Number number;
    public Character character;

    // PrimaryExp -> '(' Exp ')'
    public PrimaryExp(Token lparent, Token rparent, Exp exp) {
        this.lparent = lparent;
        this.rparent = rparent;
        this.exp = exp;
        setLineNo(lparent);
    }

    // PrimaryExp -> LVal
    public PrimaryExp(LVal lVal) {
        this.lVal = lVal;
        setLineNo(lVal);
    }

    // PrimaryExp -> Number
    public PrimaryExp(Number number) {
        this.number = number;
        setLineNo(number);
    }

    // PrimaryExp -> Character
    public PrimaryExp(Character character) {
        this.character = character;
        setLineNo(character);
    }

    public StringBuilder getPrintInfo() {
        StringBuilder info = new StringBuilder();
        if (exp != null) {
            info.append(lparent.getPrintInfo());
            info.append(exp.getPrintInfo());
            info.append(rparent.getPrintInfo());
        } else if (lVal != null) {
            info.append(lVal.getPrintInfo());
        } else if (number != null) {
            info.append(number.getPrintInfo());
        } else {
            info.append(character.getPrintInfo());
        }
        info.append("<PrimaryExp>\n");
        return info;
    }
}
