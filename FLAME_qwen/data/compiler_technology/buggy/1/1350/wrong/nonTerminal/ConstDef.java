package nonTerminal;

import frontend.Lexer;
import frontend.SymbolTable;
import frontend.SymbolTableItem;
import frontend.Token;

import java.util.ArrayList;

public class ConstDef {
    private Token identifier;
    private Token lbrack;
    private ConstExp constExp;
    private Token rbrack;
    private Token assign;
    private ConstInitVal constInitVal;
    private int lineCnt;

    public ConstDef() {
        this.identifier = null;
        this.lbrack = null;
        this.constExp = null;
        this.rbrack = null;
        this.assign = null;
        this.constInitVal = null;
        this.lineCnt = 0;
    }

    public void parser(Lexer lexer) {
        identifier = lexer.now();
        lexer.move();
        if (lexer.now().getType() == Token.Type.ASSIGN) {
            assign = lexer.now();
            lexer.move();
            constInitVal = new ConstInitVal();
            constInitVal.parser(lexer);
        } else {
            lbrack = lexer.now();
            lexer.move();
            constExp = new ConstExp();
            constExp.parser(lexer);
            if (lexer.now().getType() == Token.Type.RBRACK) {
                rbrack = lexer.now();
                lexer.move();
            } else {
                rbrack = new Token(Token.Type.RBRACK, "]", constExp.getLineCnt());
                rbrack.setIsCorrect(false);
            }
            assign = lexer.now();
            lexer.move();
            constInitVal = new ConstInitVal();
            constInitVal.parser(lexer);
        }
        lineCnt = identifier.getLineCnt();
    }

    public int getLineCnt() {
        return lineCnt;
    }

    public void analyze(SymbolTable symbolTable, String type) {
        String name = identifier.getContent();
        String thisType;
        int domainNum = symbolTable.getDomainNum();
        if (lbrack != null) {
            thisType = type + "Array";
        } else {
            thisType = type;
        }
        if (symbolTable.containsName(name, domainNum)) {
            symbolTable.addError(identifier.getLineCnt() + " b");
        } else {
            SymbolTableItem item = new SymbolTableItem(name, thisType, domainNum);
            symbolTable.addItem(item);
        }
        if (constExp != null) {
            constExp.analyze(symbolTable);
            if (!rbrack.getIsCorrect()) {
                symbolTable.addError(rbrack.getLineCnt() + " k");
            }
        }
        constInitVal.analyze(symbolTable);
    }
}
