package nonTerminal;

import frontend.Lexer;
import frontend.SymbolTable;
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

    public void parser(Lexer lexer) {
        bType = new BType();
        bType.parser(lexer);
        varDef = new VarDef();
        varDef.parser(lexer);
        while (lexer.now().getType() == Token.Type.COMMA) {
            Token comma = lexer.now();
            commas.add(comma);
            lexer.move();
            VarDef temptVarDef = new VarDef();
            temptVarDef.parser(lexer);
            varDefs.add(temptVarDef);
        }
        if (lexer.now().getType() == Token.Type.SEMICN) {
            semicn = lexer.now();
            lexer.move();
        } else {
            if (varDefs.isEmpty()) {
                semicn = new Token(Token.Type.SEMICN, ";", varDef.getLineCnt());
            } else {
                int last = varDefs.size() - 1;
                semicn = new Token(Token.Type.SEMICN, ";", varDefs.get(last).getLineCnt());
            }
            semicn.setIsCorrect(false);
        }
        lineCnt = bType.getLineCnt();
    }

    public int getLineCnt() {
        return lineCnt;
    }

    public void analyze(SymbolTable symbolTable) {
        String type;
        if (bType.getBType().getType() == Token.Type.INTTK) {
            type = "Int";
        } else {
            type = "Char";
        }
        varDef.analyze(symbolTable, type);
        for (VarDef thisVarDef : varDefs) {
            thisVarDef.analyze(symbolTable, type);
        }
        if (!semicn.getIsCorrect()) {
            symbolTable.addError(semicn.getLineCnt() + " i");
        }
    }
}
