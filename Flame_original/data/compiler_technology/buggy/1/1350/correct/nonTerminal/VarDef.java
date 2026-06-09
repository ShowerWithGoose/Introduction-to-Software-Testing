package nonTerminal;

import frontend.Lexer;
import frontend.Token;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class VarDef {
    private Token identifier;
    private Token lbrack;
    private ConstExp constExp;
    private Token rbrack;
    private Token assign;
    private InitVal initVal;
    private int lineCnt;

    public VarDef() {
        identifier = null;
        lbrack = null;
        constExp = null;
        rbrack = null;
        assign = null;
        initVal = null;
        lineCnt = 0;
    }

    public void parser(Lexer lexer, ArrayList<String> errors) {
        identifier = lexer.now();
        lexer.move();
        if (lexer.now().getType() == Token.Type.LBRACK) {
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
        }
        if (lexer.now().getType() == Token.Type.ASSIGN) {
            assign = lexer.now();
            lexer.move();
            initVal = new InitVal();
            initVal.parser(lexer, errors);
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
        if (assign != null) {
            parserResult.add(assign.getType().toString() + " " + assign.getContent());
        }
        if (initVal != null) {
            initVal.output(parserResult);
        }
        parserResult.add("<VarDef>");
    }

    public int getLineCnt() {
        return lineCnt;
    }
}
