package nonTerminal;

import frontend.Lexer;
import frontend.Token;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class FuncFParam {
    private BType bType;
    private Token identifier;
    private Token lbrack;
    private Token rbrack;
    private int lineCnt;

    public FuncFParam() {
        bType = null;
        identifier = null;
        lbrack = null;
        rbrack = null;
        lineCnt = 0;
    }

    public void parser(Lexer lexer, ArrayList<String> errors) {
        bType = new BType();
        bType.parser(lexer);
        identifier = lexer.now();
        lexer.move();
        if (lexer.now().getType() == Token.Type.LBRACK) {
            lbrack = lexer.now();
            lexer.move();
            if (lexer.now().getType() == Token.Type.RBRACK) {
                rbrack = lexer.now();
                lexer.move();
            } else {
                errors.add(lbrack.getLineCnt() + " k");
            }
        }
        lineCnt = bType.getLineCnt();
    }

    public void output(ArrayList<String> parserResult) {
        bType.output(parserResult);
        parserResult.add(identifier.getType().toString() + " " + identifier.getContent());
        if (lbrack != null) {
            parserResult.add(lbrack.getType().toString() + " " + lbrack.getContent());
        }
        if (rbrack != null) {
            parserResult.add(rbrack.getType().toString() + " " + rbrack.getContent());
        }
        parserResult.add("<FuncFParam>");
    }

    public int getLineCnt() {
        return lineCnt;
    }
}
