package nonTerminal;

import frontend.Lexer;
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

    public void parser(Lexer lexer, ArrayList<String> errors) {
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
                arrExp.parser(lexer, errors);
                while (lexer.now().getType() == Token.Type.COMMA) {
                    Token comma = lexer.now();
                    lexer.move();
                    commas.add(comma);
                    Exp temptExp = new Exp();
                    temptExp.parser(lexer, errors);
                    arrExps.add(temptExp);
                }
                rbrace = lexer.now();
                lexer.move();
            }
            lineCnt = lbrace.getLineCnt();
        } else {
            exp = new Exp();
            exp.parser(lexer, errors);
            lineCnt = exp.getLineCnt();
        }
    }

    public void output(ArrayList<String> parserResult) {
        if (exp != null) {
            exp.output(parserResult);
        }
        if (lbrace != null) {
            parserResult.add(lbrace.getType().toString() + " " + lbrace.getContent());
        }
        if (arrExp != null) {
            arrExp.output(parserResult);
        }
        for (int i = 0; i < commas.size(); i++) {
            parserResult.add(commas.get(i).getType().toString() + " " + commas.get(i).getContent());
            arrExps.get(i).output(parserResult);
        }
        if (rbrace != null) {
            parserResult.add(rbrace.getType().toString() + " " + rbrace.getContent());
        }
        if (strcon != null) {
            parserResult.add(strcon.getType().toString() + " " + strcon.getContent());
        }
        parserResult.add("<InitVal>");
    }

    public int getLineCnt() {
        return lineCnt;
    }
}
