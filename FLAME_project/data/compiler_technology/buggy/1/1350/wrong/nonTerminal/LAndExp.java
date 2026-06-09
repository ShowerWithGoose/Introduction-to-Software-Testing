package nonTerminal;

import frontend.Lexer;
import frontend.SymbolTable;
import frontend.Token;

import java.util.ArrayList;

public class LAndExp {
    private EqExp eqExp;
    private LAndExp lAndExp;
    private Token operator;
    private EqExp operatorExp;
    private int lineCnt;

    public LAndExp() {
        eqExp = null;
        lAndExp = null;
        operator = null;
        operatorExp = null;
        lineCnt = 0;
    }

    public void parser(Lexer lexer) {
        eqExp = new EqExp();
        eqExp.parser(lexer);
        if (lexer.now().getType() == Token.Type.AND) {
            lAndExp = new LAndExp();
            lAndExp.setEqExp(eqExp);
            lAndExp.setLineCnt(eqExp.getLineCnt());
            eqExp = null;
            operator = lexer.now();
            lexer.move();
            operatorExp = new EqExp();
            operatorExp.parser(lexer);
        }
        while (lexer.now().getType() == Token.Type.AND) {
            LAndExp temptLAndExp = lAndExp;
            lAndExp = new LAndExp();
            lAndExp.setlAndExp(temptLAndExp);
            lAndExp.setOperator(operator);
            lAndExp.setOperatorExp(operatorExp);
            lAndExp.setLineCnt(temptLAndExp.getLineCnt());
            operator = lexer.now();
            lexer.move();
            operatorExp = new EqExp();
            operatorExp.parser(lexer);
        }
        if (eqExp != null) {
            lineCnt = eqExp.getLineCnt();
        } else {
            lineCnt = lAndExp.getLineCnt();
        }
    }

    public void setEqExp(EqExp eqExp) {
        this.eqExp = eqExp;
    }

    public void setlAndExp(LAndExp lAndExp) {
        this.lAndExp = lAndExp;
    }

    public void setOperator(Token operator) {
        this.operator = operator;
    }

    public void setOperatorExp(EqExp operatorExp) {
        this.operatorExp = operatorExp;
    }

    public void setLineCnt(int lineCnt) {
        this.lineCnt = lineCnt;
    }

    public int getLineCnt() {
        return lineCnt;
    }

    public void analyze(SymbolTable symbolTable) {
        if (eqExp != null) {
            eqExp.analyze(symbolTable);
        } else {
            lAndExp.analyze(symbolTable);
            if (!operator.getIsCorrect()) {
                symbolTable.addError(operator.getLineCnt() + " a");
            }
            operatorExp.analyze(symbolTable);
        }
    }
}
