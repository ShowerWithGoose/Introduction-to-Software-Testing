package nonTerminal;

import frontend.Lexer;
import frontend.SymbolTable;
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

    public void parser(Lexer lexer) {
        Token.Type nowType = lexer.now().getType();
        if (nowType == Token.Type.LPARENT) {
            lparent = lexer.now();
            lexer.move();
            exp = new Exp();
            exp.parser(lexer);
            if (lexer.now().getType() == Token.Type.RPARENT) {
                rparent = lexer.now();
                lexer.move();
            } else {
                rparent = new Token(Token.Type.RPARENT, ")", exp.getLineCnt());
                rparent.setIsCorrect(false);
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
            lVal.parser(lexer);
            lineCnt = lVal.getLineCnt();
        }
    }

    public int getLineCnt() {
        return lineCnt;
    }

    public void analyze(SymbolTable symbolTable) {
        if (exp != null) {
            exp.analyze(symbolTable);
            if (!rparent.getIsCorrect()) {
                symbolTable.addError(rparent.getLineCnt() + " j");
            }
        }
        if (lVal != null) {
            lVal.analyze(symbolTable);
        }
    }

    public LVal getLVal() {
        return lVal;
    }
}
