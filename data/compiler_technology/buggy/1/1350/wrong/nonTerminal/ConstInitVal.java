package nonTerminal;

import frontend.Lexer;
import frontend.SymbolTable;
import frontend.Token;

import java.util.ArrayList;

public class ConstInitVal {
    private ConstExp constExp;
    private Token lbrace;
    private ConstExp arrConstExp;
    private ArrayList<Token> commas;
    private ArrayList<ConstExp> arrConstExps;
    private Token rbrace;
    private Token strcon;
    private int lineCnt;

    public ConstInitVal() {
        this.constExp = null;
        this.lbrace = null;
        this.arrConstExp = null;
        this.commas = new ArrayList<>();
        this.arrConstExps = new ArrayList<>();
        this.rbrace = null;
        this.strcon = null;
        this.lineCnt = 0;
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
                arrConstExp = new ConstExp();
                arrConstExp.parser(lexer);
                while (lexer.now().getType() == Token.Type.COMMA) {
                    Token comma = lexer.now();
                    commas.add(comma);
                    lexer.move();
                    ConstExp temptConstExp = new ConstExp();
                    temptConstExp.parser(lexer);
                    arrConstExps.add(temptConstExp);
                }
                rbrace = lexer.now();
                lexer.move();
            }
            lineCnt = lbrace.getLineCnt();
        } else {
            constExp = new ConstExp();
            constExp.parser(lexer);
            lineCnt = constExp.getLineCnt();
        }
    }

    public int getLineCnt() {
        return lineCnt;
    }

    public void analyze(SymbolTable symbolTable) {
        if (constExp != null) {
            constExp.analyze(symbolTable);
        }
        if (arrConstExp != null) {
            arrConstExp.analyze(symbolTable);
            for (ConstExp thisConstExp : arrConstExps) {
                thisConstExp.analyze(symbolTable);
            }
        }
    }
}
