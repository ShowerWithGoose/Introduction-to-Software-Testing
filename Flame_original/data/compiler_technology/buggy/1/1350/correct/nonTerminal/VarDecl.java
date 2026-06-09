package nonTerminal;

import frontend.Lexer;
import frontend.Token;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class VarDecl {
    private BType bType;
    private VarDef varDef;
    private ArrayList<Token> commas;
    private ArrayList<VarDef> varDefs;
    private Token semicn;
    private int lineCnt;

    public VarDecl() {
        bType = null;
        varDef = null;
        commas = new ArrayList<>();
        varDefs = new ArrayList<>();
        semicn = null;
        lineCnt = 0;
    }

    public void parser(Lexer lexer, ArrayList<String> errors) {
        bType = new BType();
        bType.parser(lexer);
        varDef = new VarDef();
        varDef.parser(lexer, errors);
        while (lexer.now().getType() == Token.Type.COMMA) {
            Token comma = lexer.now();
            commas.add(comma);
            lexer.move();
            VarDef temptVarDef = new VarDef();
            temptVarDef.parser(lexer, errors);
            varDefs.add(temptVarDef);
        }
        if (lexer.now().getType() == Token.Type.SEMICN) {
            semicn = lexer.now();
            lexer.move();
        } else {
            if (varDefs.isEmpty()) {
                errors.add(varDef.getLineCnt() + " i");
            } else {
                int last = varDefs.size() - 1;
                errors.add(varDefs.get(last).getLineCnt() + " i");
            }
        }
        lineCnt = bType.getLineCnt();
    }

    public void output(ArrayList<String> parserResult) {
        bType.output(parserResult);
        varDef.output(parserResult);
        for (int i = 0; i < varDefs.size(); i++) {
            parserResult.add(commas.get(i).getType().toString() + " " + commas.get(i).getContent());
            varDefs.get(i).output(parserResult);
        }
        parserResult.add(semicn.getType().toString() + " " + semicn.getContent());
        parserResult.add("<VarDecl>");
    }

    public int getLineCnt() {
        return lineCnt;
    }
}
