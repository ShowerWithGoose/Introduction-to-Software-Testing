package nonTerminal;

import frontend.Lexer;
import frontend.Token;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class ConstInitVal {
    private ConstExp constExp;
    private Token lbrace;
    private ConstExp arrConstExp;
    private ArrayList<Token> commas;
    private ArrayList<ConstExp> arrConstExps;
    private Token rbrace;
    private Token strcon;
    private String type;//const,arr,str
    private int lineCnt;

    public ConstInitVal() {
        this.constExp = null;
        this.lbrace = null;
        this.arrConstExp = null;
        this.commas = new ArrayList<>();
        this.arrConstExps = new ArrayList<>();
        this.rbrace = null;
        this.strcon = null;
        this.type = null;
        this.lineCnt = 0;
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
                arrConstExp = new ConstExp();
                arrConstExp.parser(lexer, errors);
                while (lexer.now().getType() == Token.Type.COMMA) {
                    Token comma = lexer.now();
                    commas.add(comma);
                    lexer.move();
                    ConstExp temptConstExp = new ConstExp();
                    temptConstExp.parser(lexer, errors);
                    arrConstExps.add(temptConstExp);
                }
                rbrace = lexer.now();
                lexer.move();
            }
            lineCnt = lbrace.getLineCnt();
        } else {
            constExp = new ConstExp();
            constExp.parser(lexer, errors);
            lineCnt = constExp.getLineCnt();
        }
    }

    public void output(ArrayList<String> parserResult) {
        if (constExp != null) {
            constExp.output(parserResult);
        }
        if (lbrace != null) {
            parserResult.add(lbrace.getType().toString() + " " + lbrace.getContent());
        }
        if (arrConstExp != null) {
            arrConstExp.output(parserResult);
        }
        for (int i = 0; i < arrConstExps.size(); i++) {
            parserResult.add(commas.get(i).getType().toString() + " " + commas.get(i).getContent());
            arrConstExps.get(i).output(parserResult);
        }
        if (rbrace != null) {
            parserResult.add(rbrace.getType().toString() + " " + rbrace.getContent());
        }
        if (strcon != null) {
            parserResult.add(strcon.getType().toString() + " " + strcon.getContent());
        }
        parserResult.add("<ConstInitVal>");
    }

    public int getLineCnt() {
        return lineCnt;
    }
}
