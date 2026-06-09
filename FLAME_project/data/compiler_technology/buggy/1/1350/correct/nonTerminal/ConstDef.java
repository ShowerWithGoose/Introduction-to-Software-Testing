package nonTerminal;

import frontend.Lexer;
import frontend.Token;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class ConstDef {
    private Token identifier;
    private Token lbrack;
    private ConstExp constExp;
    private Token rbrack;
    private Token assign;
    private ConstInitVal constInitVal;
    private boolean isArr = false;
    private int lineCnt;

    public ConstDef() {
        this.identifier = null;
        this.lbrack = null;
        this.constExp = null;
        this.rbrack = null;
        this.assign = null;
        this.constInitVal = null;
        this.isArr = false;
        this.lineCnt = 0;
    }

    public void parser(Lexer lexer, ArrayList<String> errors) {
        identifier = lexer.now();
        lexer.move();
        if (lexer.now().getType() == Token.Type.ASSIGN) {
            assign = lexer.now();
            lexer.move();
            constInitVal = new ConstInitVal();
            constInitVal.parser(lexer, errors);
        } else {
            lbrack = lexer.now();
            lexer.move();
            constExp = new ConstExp();
            constExp.parser(lexer, errors);
            if (lexer.now().getType() == Token.Type.RBRACK) {
                rbrack = lexer.now();
                lexer.move();
            } else {
                errors.add(constExp.getLineCnt() + " k");
            }
            assign = lexer.now();
            lexer.move();
            constInitVal = new ConstInitVal();
            constInitVal.parser(lexer, errors);
        }
        lineCnt = identifier.getLineCnt();
    }

    public void output(ArrayList<String> parserResult) {
        parserResult.add(identifier.getType().toString() + " " + identifier.getContent());
        if (lbrack != null) {
            parserResult.add(lbrack.getType().toString() + " " + lbrack.getContent());
        }
        if (constExp != null) {
            constExp.output(parserResult);
        }
        if (rbrack != null) {
            parserResult.add(rbrack.getType().toString() + " " + rbrack.getContent());
        }
        parserResult.add(assign.getType().toString() + " " + assign.getContent());
        constInitVal.output(parserResult);
        parserResult.add("<ConstDef>");
    }

    public int getLineCnt() {
        return lineCnt;
    }
}
