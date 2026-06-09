package nonTerminal;

import frontend.Lexer;
import frontend.Token;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Decl {
    public enum DeclType {
        CONSTDECL, VARDECL
    }

    private ConstDecl constDecl;
    private VarDecl varDecl;
    private DeclType declType;    //const || var
    private int lineCnt;

    public Decl() {
        constDecl = null;
        varDecl = null;
        declType = null;
        lineCnt = 0;
    }

    public void parser(Lexer lexer, ArrayList<String> errors) {
        if (lexer.now().getType() == Token.Type.CONSTTK) {
            constDecl = new ConstDecl();
            constDecl.parser(lexer, errors);
            lineCnt = constDecl.getLineCnt();
        } else if (lexer.now().getType() == Token.Type.INTTK ||
                lexer.now().getType() == Token.Type.CHARTK) {
            varDecl = new VarDecl();
            varDecl.parser(lexer, errors);
            lineCnt = varDecl.getLineCnt();
        }
    }

    public void output(ArrayList<String> parserResult) {
        if (constDecl != null) {
            constDecl.output(parserResult);
        }
        if (varDecl != null) {
            varDecl.output(parserResult);
        }
    }

    public int getLineCnt() {
        return lineCnt;
    }
}
