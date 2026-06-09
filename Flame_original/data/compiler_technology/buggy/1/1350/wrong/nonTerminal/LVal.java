package nonTerminal;

import frontend.Lexer;
import frontend.SymbolTable;
import frontend.Token;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class LVal {
    private Token identifier;
    private Token lbrack;
    private Exp exp;
    private Token rbrack;
    private boolean isArr;
    private int lineCnt;

    public LVal() {
        this.identifier = null;
        this.lbrack = null;
        this.exp = null;
        this.rbrack = null;
        this.isArr = false;
        this.lineCnt = 0;
    }

    public void parser(Lexer lexer) {
        identifier = lexer.now();
        lexer.move();
        if (lexer.now().getType() == Token.Type.LBRACK) {
            lbrack = lexer.now();
            lexer.move();
            exp = new Exp();
            exp.parser(lexer);
            if (lexer.now().getType() == Token.Type.RBRACK) {
                rbrack = lexer.now();
                lexer.move();
            } else {
                rbrack = new Token(Token.Type.RBRACK, "]", exp.getLineCnt());
                rbrack.setIsCorrect(false);
            }
        }
        lineCnt = identifier.getLineCnt();
    }

    public int getLineCnt() {
        return lineCnt;
    }

    public Token getIdentifier() {
        return identifier;
    }

    public Token getLbrack() {
        return lbrack;
    }

    public void analyze(SymbolTable symbolTable) {
        String name = identifier.getContent();
        if (!symbolTable.contains(name)) {
            symbolTable.addError(identifier.getLineCnt() + " c");
        }
        if (exp != null) {
            exp.analyze(symbolTable);
            if (!rbrack.getIsCorrect()) {
                symbolTable.addError(rbrack.getLineCnt() + " k");
            }
        }
    }
}