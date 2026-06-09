package nonTerminal;

import frontend.Lexer;
import frontend.SymbolTable;
import frontend.SymbolTableItem;
import frontend.Token;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class FuncFParam {
    private BType bType;
    private Token identifier;
    private Token lbrack;
    private Token rbrack;
    private int lineCnt;

    public FuncFParam() {
        bType = null;
        identifier = null;
        lbrack = null;
        rbrack = null;
        lineCnt = 0;
    }

    public void parser(Lexer lexer) {
        bType = new BType();
        bType.parser(lexer);
        identifier = lexer.now();
        lexer.move();
        if (lexer.now().getType() == Token.Type.LBRACK) {
            lbrack = lexer.now();
            lexer.move();
            if (lexer.now().getType() == Token.Type.RBRACK) {
                rbrack = lexer.now();
                lexer.move();
            } else {
                rbrack = new Token(Token.Type.RBRACK, "]", lbrack.getLineCnt());
                rbrack.setIsCorrect(false);
            }
        }
        lineCnt = bType.getLineCnt();
    }

    public int getLineCnt() {
        return lineCnt;
    }

    public BType getBType() {
        return bType;
    }

    public Token getLbrack() {
        return lbrack;
    }

    public void analyze(SymbolTable symbolTable) {
        String name = identifier.getContent();
        String thisType;
        int domainNum = symbolTable.getDomainNum();
        if (bType.getBType().getType() == Token.Type.INTTK) {
            thisType = "Int";
        } else {
            thisType = "Char";
        }
        if (lbrack != null) {
            thisType  += "Array";
        }
        if (symbolTable.containsName(name, domainNum)) {
            symbolTable.addError(identifier.getLineCnt() + " b");
        } else {
            SymbolTableItem item = new SymbolTableItem(name, thisType, domainNum);
            symbolTable.addItem(item);
        }
        if (rbrack != null && !rbrack.getIsCorrect()) {
            symbolTable.addError(rbrack.getLineCnt() + " k");
        }
    }
}
