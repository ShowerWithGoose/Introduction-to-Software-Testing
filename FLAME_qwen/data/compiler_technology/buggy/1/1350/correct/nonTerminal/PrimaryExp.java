package nonTerminal;

import frontend.Lexer;
import frontend.Token;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class PrimaryExp {
    public enum PrimaryExpType {
        EXP, LVAL, NUM, CHAR
    }

    private Token lparent;
    private Exp exp;
    private Token rparent;
    private LVal lVal;
    private Number number;
    private Character character;
    private PrimaryExpType primaryExpType;
    private int lineCnt;

    public PrimaryExp() {
        this.primaryExpType = null;
        this.lparent = null;
        this.exp = null;
        this.rparent = null;
        this.lVal = null;
        this.number = null;
        this.character = null;
        this.lineCnt = 0;
    }

    public void parser(Lexer lexer, ArrayList<String> errors) {
        Token.Type nowType = lexer.now().getType();
        if (nowType == Token.Type.LPARENT) {
            lparent = lexer.now();
            lexer.move();
            exp = new Exp();
            exp.parser(lexer, errors);
            if (lexer.now().getType() == Token.Type.RPARENT) {
                rparent = lexer.now();
                lexer.move();
            } else {
                errors.add(exp.getLineCnt() + " j");
            }
            lineCnt = lparent.getLineCnt();
        } else if (nowType == Token.Type.INTCON) {
            number = new Number();
            number.parser(lexer);
            lineCnt = number.getLineCnt();
        } else if (nowType == Token.Type.CHRCON) {
            character = new Character();
            character.parser(lexer);
            lineCnt = character.getLineCnt();
        } else {
            lVal = new LVal();
            lVal.parser(lexer, errors);
            lineCnt = lVal.getLineCnt();
        }
    }

    public void output(ArrayList<String> parserResult) {
        if (lparent != null) {
            parserResult.add(lparent.getType().toString() + " " + lparent.getContent());
        }
        if (exp != null) {
            exp.output(parserResult);
        }
        if (rparent != null) {
            parserResult.add(rparent.getType().toString() + " " + rparent.getContent());
        }
        if (lVal != null) {
            lVal.output(parserResult);
        }
        if (number != null) {
            number.output(parserResult);
        }
        if (character != null) {
            character.output(parserResult);
        }
        parserResult.add("<PrimaryExp>");
    }

    public int getLineCnt() {
        return lineCnt;
    }
}
