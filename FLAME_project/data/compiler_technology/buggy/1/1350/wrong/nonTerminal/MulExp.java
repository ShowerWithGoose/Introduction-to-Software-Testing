package nonTerminal;

import frontend.Lexer;
import frontend.SymbolTable;
import frontend.Token;

import java.util.ArrayList;

public class MulExp {
    private UnaryExp unaryExp;
    private MulExp mulExp;
    private Token operator;
    private UnaryExp operatorExp;
    private int lineCnt;

    public MulExp() {
        unaryExp = null;
        mulExp = null;
        operator = null;
        operatorExp = null;
        lineCnt = 0;
    }

    public void parser(Lexer lexer) {
        unaryExp = new UnaryExp();
        unaryExp.parser(lexer);
        if (lexer.now().getType() == Token.Type.MULT ||
                lexer.now().getType() == Token.Type.DIV ||
                lexer.now().getType() == Token.Type.MOD) {
            mulExp = new MulExp();
            mulExp.setUnaryExp(unaryExp);
            mulExp.setLineCnt(unaryExp.getLineCnt());
            unaryExp = null;
            operator = lexer.now();
            lexer.move();
            operatorExp = new UnaryExp();
            operatorExp.parser(lexer);
        }
        while (lexer.now().getType() == Token.Type.MULT ||
                lexer.now().getType() == Token.Type.DIV ||
                lexer.now().getType() == Token.Type.MOD) {
            MulExp temptMulExp = mulExp;
            mulExp = new MulExp();
            mulExp.setMulExp(temptMulExp);
            mulExp.setOperator(operator);
            mulExp.setOperatorExp(operatorExp);
            mulExp.setLineCnt(temptMulExp.getLineCnt());
            operator = lexer.now();
            lexer.move();
            operatorExp = new UnaryExp();
            operatorExp.parser(lexer);
        }
        if (unaryExp != null) {
            lineCnt = unaryExp.getLineCnt();
        } else {
            lineCnt = mulExp.getLineCnt();
        }
    }

    public void setUnaryExp(UnaryExp unaryExp) {
        this.unaryExp = unaryExp;
    }

    public void setMulExp(MulExp mulExp) {
        this.mulExp = mulExp;
    }

    public void setOperator(Token operator) {
        this.operator = operator;
    }

    public void setOperatorExp(UnaryExp operatorExp) {
        this.operatorExp = operatorExp;
    }

    public void setLineCnt(int lineCnt) {
        this.lineCnt = lineCnt;
    }

    public int getLineCnt() {
        return lineCnt;
    }

    public void analyze(SymbolTable symbolTable) {
        if (unaryExp != null) {
            unaryExp.analyze(symbolTable);
        } else {
            mulExp.analyze(symbolTable);
            operatorExp.analyze(symbolTable);
        }
    }

    public UnaryExp getUnaryExp() {
        return unaryExp;
    }
}