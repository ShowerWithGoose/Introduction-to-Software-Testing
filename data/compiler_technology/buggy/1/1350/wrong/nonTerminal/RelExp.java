package nonTerminal;

import frontend.Lexer;
import frontend.SymbolTable;
import frontend.Token;

import java.util.ArrayList;

public class RelExp {
    private AddExp addExp;
    private RelExp relExp;
    private Token operator;
    private AddExp operatorExp;
    private int lineCnt;

    public RelExp() {
        addExp = null;
        relExp = null;
        operator = null;
        operatorExp = null;
        lineCnt = 0;
    }

    public void parser(Lexer lexer) {
        addExp = new AddExp();
        addExp.parser(lexer);
        if (lexer.now().getType() == Token.Type.LSS ||
                lexer.now().getType() == Token.Type.GRE ||
                lexer.now().getType() == Token.Type.LEQ ||
                lexer.now().getType() == Token.Type.GEQ) {
            relExp = new RelExp();
            relExp.setAddExp(addExp);
            relExp.setLineCnt(addExp.getLineCnt());
            addExp = null;
            operator = lexer.now();
            lexer.move();
            operatorExp = new AddExp();
            operatorExp.parser(lexer);
        }
        while (lexer.now().getType() == Token.Type.LSS ||
                lexer.now().getType() == Token.Type.GRE ||
                lexer.now().getType() == Token.Type.LEQ ||
                lexer.now().getType() == Token.Type.GEQ) {
            RelExp temptRelExp = relExp;
            relExp = new RelExp();
            relExp.setRelExp(temptRelExp);
            relExp.setOperator(operator);
            relExp.setOperatorExp(operatorExp);
            relExp.setLineCnt(temptRelExp.getLineCnt());
            operator = lexer.now();
            lexer.move();
            operatorExp = new AddExp();
            operatorExp.parser(lexer);
        }
        if (addExp != null) {
            lineCnt = addExp.getLineCnt();
        } else {
            lineCnt = relExp.getLineCnt();
        }
    }

    public void setAddExp(AddExp addExp) {
        this.addExp = addExp;
    }

    public void setRelExp(RelExp relExp) {
        this.relExp = relExp;
    }

    public void setOperator(Token operator) {
        this.operator = operator;
    }

    public void setOperatorExp(AddExp operatorExp) {
        this.operatorExp = operatorExp;
    }

    public void setLineCnt(int lineCnt) {
        this.lineCnt = lineCnt;
    }

    public int getLineCnt() {
        return lineCnt;
    }

    public void analyze(SymbolTable symbolTable) {
        if (addExp != null) {
            addExp.analyze(symbolTable);
        } else {
            relExp.analyze(symbolTable);
            operatorExp.analyze(symbolTable);
        }
    }
}
