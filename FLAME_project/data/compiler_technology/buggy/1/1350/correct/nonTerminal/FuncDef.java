package nonTerminal;

import frontend.Lexer;
import frontend.Token;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class FuncDef {
    private FuncType funcType;
    private Token identifier;
    private Token lparent;
    private FuncFParams funcFParams;
    private Token rparent;
    private Block block;
    private int lineCnt;

    public FuncDef() {
        funcType = null;
        identifier = null;
        lparent = null;
        funcFParams = null;
        rparent = null;
        block = null;
        lineCnt = 0;
    }

    public void parser(Lexer lexer, ArrayList<String> errors) {
        funcType = new FuncType();
        funcType.parser(lexer);
        identifier = lexer.now();
        lexer.move();
        lparent = lexer.now();
        lexer.move();
        if (lexer.now().getType() == Token.Type.INTTK ||
                lexer.now().getType() == Token.Type.CHARTK) {
            funcFParams = new FuncFParams();
            funcFParams.parser(lexer, errors);
        }
        if (lexer.now().getType() == Token.Type.RPARENT) {
            rparent = lexer.now();
            lexer.move();
        } else {
            if (funcFParams == null) {
                errors.add(lparent.getLineCnt() + " j");
            } else {
                errors.add(funcFParams.getLineCnt() + " j");
            }
        }
        block = new Block();
        block.parser(lexer, errors);
        lineCnt = funcType.getLineCnt();
    }

    public void output(ArrayList<String> parserResult) {
        funcType.output(parserResult);
        parserResult.add(identifier.getType().toString() + " " + identifier.getContent());
        parserResult.add(lparent.getType().toString() + " " + lparent.getContent());
        if (funcFParams != null) {
            funcFParams.output(parserResult);
        }
        parserResult.add(rparent.getType().toString() + " " + rparent.getContent());
        block.output(parserResult);
        parserResult.add("<FuncDef>");
    }

    public int getLineCnt() {
        return lineCnt;
    }
}
