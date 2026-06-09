package nonTerminal;

import frontend.Lexer;
import frontend.Token;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class LVal {
    private Token identifier;
    private Token lbrack;
    private Exp exp;
    private Token rbrack;
    private boolean isArr;
    private int lineCnt;

    public LVal() {
        this.identifier = null;
        this.lbrack = null;
        this.exp = null;
        this.rbrack = null;
        this.isArr = false;
        this.lineCnt = 0;
    }

    public void parser(Lexer lexer, ArrayList<String> errors) {
        identifier = lexer.now();
        lexer.move();
        if (lexer.now().getType() == Token.Type.LBRACK) {
            lbrack = lexer.now();
            lexer.move();
            exp = new Exp();
            exp.parser(lexer, errors);
            if (lexer.now().getType() == Token.Type.RBRACK) {
                rbrack = lexer.now();
                lexer.move();
            } else {
                errors.add(exp.getLineCnt() + " k");
            }
        }
        lineCnt = identifier.getLineCnt();
    }

    public void output(ArrayList<String> parserResult) {
        parserResult.add(identifier.getType().toString() + " " + identifier.getContent());
        if (lbrack != null) {
            parserResult.add(lbrack.getType().toString() + " " + lbrack.getContent());
        }
        if (exp != null) {
            exp.output(parserResult);
        }
        if (rbrack != null) {
            parserResult.add(rbrack.getType().toString() + " " + rbrack.getContent());
        }
        parserResult.add("<LVal>");
    }

    public int getLineCnt() {
        return lineCnt;
    }
}