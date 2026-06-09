package nonTerminal;

import frontend.Lexer;
import frontend.SymbolTable;
import frontend.SymbolTableItem;
import frontend.Token;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Decl {

    private ConstDecl constDecl;

    private VarDecl varDecl;

    private int lineCnt;

    public Decl() {
        constDecl = null;
        varDecl = null;
        lineCnt = 0;
    }

    public void parser(Lexer lexer) {
        if (lexer.now().getType() == Token.Type.CONSTTK) {
            constDecl = new ConstDecl();
            constDecl.parser(lexer);
            lineCnt = constDecl.getLineCnt();
        } else if (lexer.now().getType() == Token.Type.INTTK ||
                lexer.now().getType() == Token.Type.CHARTK) {
            varDecl = new VarDecl();
            varDecl.parser(lexer);
            lineCnt = varDecl.getLineCnt();
        }
    }

    public int getLineCnt() {
        return lineCnt;
    }

    public void analyze(SymbolTable symbolTable) {
        if (constDecl != null) {
            constDecl.analyze(symbolTable);
        }
        if (varDecl != null) {
            varDecl.analyze(symbolTable);
        }
    }
}
