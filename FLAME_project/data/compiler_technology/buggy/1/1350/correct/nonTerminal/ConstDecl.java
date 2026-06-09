package nonTerminal;

import frontend.Lexer;
import frontend.Token;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class ConstDecl {
    private Token consttk;
    private BType bType;
    private ConstDef constDef;
    private ArrayList<Token> commas;
    private ArrayList<ConstDef> constDefs;
    private Token semicn;
    private int lineCnt;

    public ConstDecl() {
        consttk = null;
        bType = null;
        constDef = null;
        commas = new ArrayList<>();
        constDefs = new ArrayList<>();
        semicn = null;
        lineCnt = 0;
    }

    public void parser(Lexer lexer, ArrayList<String> errors) {
        consttk = lexer.now();
        lexer.move();
        bType = new BType();
        bType.parser(lexer);
        constDef = new ConstDef();
        constDef.parser(lexer, errors);
        while (lexer.now().getType() == Token.Type.COMMA) {
            commas.add(lexer.now());
            lexer.move();
            ConstDef constDef = new ConstDef();
            constDef.parser(lexer, errors);
            constDefs.add(constDef);
        }
        if (lexer.now().getType() == Token.Type.SEMICN) {
            semicn = lexer.now();
            lexer.move();
        } else {
            if (constDefs.isEmpty()) {
                errors.add(constDef.getLineCnt() + " i");
            } else {
                int last = constDefs.size() - 1;
                errors.add(constDefs.get(last).getLineCnt() + " i");
            }
        }
        lineCnt = consttk.getLineCnt();
    }

    public void output(ArrayList<String> parserResult) {
        parserResult.add(consttk.getType().toString() + " " + consttk.getContent());
        bType.output(parserResult);
        constDef.output(parserResult);
        for (int i = 0; i < constDefs.size(); i++) {
            parserResult.add(commas.get(i).getType().toString() + " " + commas.get(i).getContent());
            constDefs.get(i).output(parserResult);
        }
        parserResult.add(semicn.getType().toString() + " " + semicn.getContent());
        parserResult.add("<ConstDecl>");
    }

    public int getLineCnt() {
        return lineCnt;
    }
}
