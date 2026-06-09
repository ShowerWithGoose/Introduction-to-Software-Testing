package nonTerminal;

import frontend.Lexer;
import frontend.SymbolTable;
import frontend.SymbolTableItem;
import frontend.Token;

import java.util.ArrayList;

public class ConstDecl {
    private Token consttk;

    private BType bType;

    private ConstDef constDef;

    private ArrayList<Token> commas;

    private ArrayList<ConstDef> constDefs;

    private Token semicn;

    private int lineCnt;

    public ConstDecl() {
        consttk = null;
        bType = null;
        constDef = null;
        commas = new ArrayList<>();
        constDefs = new ArrayList<>();
        semicn = null;
        lineCnt = 0;
    }

    public void parser(Lexer lexer) {
        consttk = lexer.now();
        lexer.move();
        bType = new BType();
        bType.parser(lexer);
        constDef = new ConstDef();
        constDef.parser(lexer);
        while (lexer.now().getType() == Token.Type.COMMA) {
            commas.add(lexer.now());
            lexer.move();
            ConstDef constDef = new ConstDef();
            constDef.parser(lexer);
            constDefs.add(constDef);
        }
        if (lexer.now().getType() == Token.Type.SEMICN) {
            semicn = lexer.now();
            lexer.move();
        } else {
            if (constDefs.isEmpty()) {
                semicn = new Token(Token.Type.SEMICN, ";", constDef.getLineCnt());
            } else {
                int last = constDefs.size() - 1;
                semicn = new Token(Token.Type.SEMICN, ";", constDefs.get(last).getLineCnt());
            }
            semicn.setIsCorrect(false);
        }
        lineCnt = consttk.getLineCnt();
    }

    public int getLineCnt() {
        return lineCnt;
    }

    public void analyze(SymbolTable symbolTable) {
        String type;
        if (bType.getBType().getType() == Token.Type.INTTK) {
            type = "ConstInt";
        } else {
            type = "ConstChar";
        }
        constDef.analyze(symbolTable, type);
        for (ConstDef thisConstDef : constDefs) {
            thisConstDef.analyze(symbolTable, type);
        }
        if (!semicn.getIsCorrect()) {
            symbolTable.addError(semicn.getLineCnt() + " i");
        }
    }
}
