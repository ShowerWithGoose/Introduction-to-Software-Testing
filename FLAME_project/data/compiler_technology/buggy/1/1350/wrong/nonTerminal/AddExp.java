package nonTerminal;

import frontend.Lexer;
import frontend.SymbolTable;
import frontend.Token;

import java.util.ArrayList;

public class AddExp {
    private MulExp mulExp;
    private AddExp addExp;
    private Token operator;
    private MulExp operatorMulExp;
    private int lineCnt;

    public AddExp() {
        mulExp = null;
        addExp = null;
        operator = null;
        operatorMulExp = null;
        lineCnt = 0;
    }

    public void parser(Lexer lexer) {
        mulExp = new MulExp();
        mulExp.parser(lexer);
        if (lexer.now().getType() == Token.Type.PLUS ||
                lexer.now().getType() == Token.Type.MINU) {
            addExp = new AddExp();
            addExp.setMulExp(mulExp);
            addExp.setLineCnt(mulExp.getLineCnt());
            mulExp = null;
            operator = lexer.now();
            lexer.move();
            operatorMulExp = new MulExp();
            operatorMulExp.parser(lexer);
        }
        while (lexer.now().getType() == Token.Type.PLUS ||
                lexer.now().getType() == Token.Type.MINU) {
            AddExp temptAddExp = addExp;
            addExp = new AddExp();
            addExp.setAddExp(temptAddExp);
            addExp.setOperator(operator);
            addExp.setOperatorMulExp(operatorMulExp);
            addExp.setLineCnt(temptAddExp.getLineCnt());
            operator = lexer.now();
            lexer.move();
            operatorMulExp = new MulExp();
            operatorMulExp.parser(lexer);
        }
        if (mulExp != null) {
            lineCnt = mulExp.getLineCnt();
        } else {
            lineCnt = addExp.getLineCnt();
        }
    }

    public void setMulExp(MulExp mulExp) {
        this.mulExp = mulExp;
    }

    public void setAddExp(AddExp addExp) {
        this.addExp = addExp;
    }

    public void setOperator(Token operator) {
        this.operator = operator;
    }

    public void setOperatorMulExp(MulExp operatorMulExp) {
        this.operatorMulExp = operatorMulExp;
    }

    public void setLineCnt(int lineCnt) {
        this.lineCnt = lineCnt;
    }

    public int getLineCnt() {
        return lineCnt;
    }

    public void analyze(SymbolTable symbolTable) {
        if (mulExp != null) {
            mulExp.analyze(symbolTable);
        } else {
            addExp.analyze(symbolTable);
            operatorMulExp.analyze(symbolTable);
        }
    }

    public MulExp getMulExp() {
        return mulExp;
    }
}
