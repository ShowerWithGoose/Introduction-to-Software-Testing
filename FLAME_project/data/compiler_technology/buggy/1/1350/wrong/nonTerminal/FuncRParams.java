package nonTerminal;

import frontend.Lexer;
import frontend.SymbolTable;
import frontend.Token;

import java.util.ArrayList;

public class FuncRParams {
    private Exp exp;
    private ArrayList<Token> commas;
    private ArrayList<Exp> exps;
    private int lineCnt;

    public FuncRParams() {
        this.exp = null;
        this.commas = new ArrayList<>();
        this.exps = new ArrayList<>();
        this.lineCnt = 0;
    }

    public void parser(Lexer lexer) {
        exp = new Exp();
        exp.parser(lexer);
        while (lexer.now().getType() == Token.Type.COMMA) {
            Token comma = lexer.now();
            commas.add(comma);
            lexer.move();
            Exp temptExp = new Exp();
            temptExp.parser(lexer);
            exps.add(temptExp);
        }
        lineCnt = exp.getLineCnt();
    }

    public int getLineCnt() {
        return lineCnt;
    }

    public void analyze(SymbolTable symbolTable) {
        exp.analyze(symbolTable);
        for (Exp thisExp : exps) {
            thisExp.analyze(symbolTable);
        }
    }

    public int getSize() {
        return (exps.size() + 1);
    }

    public ArrayList<Exp.ExpType> getExpTypes(SymbolTable symbolTable) {
        ArrayList<Exp.ExpType> expTypes = new ArrayList<>();
        exp.analyzeExpType(symbolTable);
        expTypes.add(exp.getExpType());
        for (Exp thisExp : exps) {
            thisExp.analyzeExpType(symbolTable);
            expTypes.add(thisExp.getExpType());
        }
        return expTypes;
    }
}
