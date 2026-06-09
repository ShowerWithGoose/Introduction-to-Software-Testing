package nonTerminal;

import frontend.Lexer;
import frontend.SymbolTable;
import frontend.Token;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class InitVal {
    private Exp exp;
    private Token lbrace;
    private Exp arrExp;
    private ArrayList<Token> commas;
    private ArrayList<Exp> arrExps;
    private Token rbrace;
    private Token strcon;
    private int lineCnt;

    public InitVal() {
        exp = null;
        lbrace = null;
        arrExp = null;
        commas = new ArrayList<>();
        arrExps = new ArrayList<>();
        rbrace = null;
        strcon = null;
        lineCnt = 0;
    }

    public void parser(Lexer lexer) {
        if (lexer.now().getType() == Token.Type.STRCON) {
            strcon = lexer.now();
            lexer.move();
            lineCnt = strcon.getLineCnt();
        } else if (lexer.now().getType() == Token.Type.LBRACE) {
            lbrace = lexer.now();
            lexer.move();
            if (lexer.now().getType() == Token.Type.RBRACE) {
                rbrace = lexer.now();
                lexer.move();
            } else {
                arrExp = new Exp();
                arrExp.parser(lexer);
                while (lexer.now().getType() == Token.Type.COMMA) {
                    Token comma = lexer.now();
                    lexer.move();
                    commas.add(comma);
                    Exp temptExp = new Exp();
                    temptExp.parser(lexer);
                    arrExps.add(temptExp);
                }
                rbrace = lexer.now();
                lexer.move();
            }
            lineCnt = lbrace.getLineCnt();
        } else {
            exp = new Exp();
            exp.parser(lexer);
            lineCnt = exp.getLineCnt();
        }
    }

    public int getLineCnt() {
        return lineCnt;
    }

    public void analyze(SymbolTable symbolTable) {
        if (exp != null) {
            exp.analyze(symbolTable);
        }
        if (arrExp != null) {
            arrExp.analyze(symbolTable);
            for (Exp thisExp : arrExps) {
                thisExp.analyze(symbolTable);
            }
        }
    }
}
