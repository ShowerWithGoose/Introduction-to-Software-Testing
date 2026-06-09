package nonTerminal;

import frontend.Lexer;
import frontend.Token;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class UnaryExp {
    public enum UnaryExpType {
        PRIMARYEXP, FUNC, OPEXP
    }

    private UnaryExpType unaryExpType;    //primaryExp | func | opExp
    private PrimaryExp primaryExp;
    private Token identifier;
    private Token lparent;
    private FuncRParams funcRParams;
    private Token rparent;
    private UnaryOp unaryOp;
    private UnaryExp unaryExp;
    private int lineCnt;

    public UnaryExp() {
        this.unaryExpType = null;
        this.primaryExp = null;
        this.identifier = null;
        this.lparent = null;
        this.funcRParams = null;
        this.rparent = null;
        this.unaryOp = null;
        this.unaryExp = null;
        this.lineCnt = 0;
    }

    public void parser(Lexer lexer, ArrayList<String> errors) {
        Token.Type nowType = lexer.now().getType();
        if (nowType == Token.Type.PLUS ||
                nowType == Token.Type.MINU ||
                nowType == Token.Type.NOT) {
            unaryOp = new UnaryOp();
            unaryOp.parser(lexer);
            unaryExp = new UnaryExp();
            unaryExp.parser(lexer, errors);
            lineCnt = unaryOp.getLineCnt();
        } else if (nowType == Token.Type.IDENFR) {
            lexer.move();
            if (lexer.now().getType() == Token.Type.LPARENT) {
                lexer.back();
                identifier = lexer.now();
                lexer.move();
                lparent = lexer.now();
                lexer.move();
                if (lexer.now().getType() == Token.Type.PLUS ||
                        lexer.now().getType() == Token.Type.MINU ||
                        lexer.now().getType() == Token.Type.NOT ||
                        lexer.now().getType() == Token.Type.IDENFR ||
                        lexer.now().getType() == Token.Type.LPARENT ||
                        lexer.now().getType() == Token.Type.INTCON ||
                        lexer.now().getType() == Token.Type.CHRCON) {
                    funcRParams = new FuncRParams();
                    funcRParams.parser(lexer, errors);
                }
                if (lexer.now().getType() == Token.Type.RPARENT) {
                    rparent = lexer.now();
                    lexer.move();
                } else {
                    if (funcRParams != null) {
                        errors.add(funcRParams.getLineCnt() + " j");
                    } else {
                        errors.add(lparent.getLineCnt() + " j");
                    }
                }
                lineCnt = identifier.getLineCnt();
            } else {
                lexer.back();
                primaryExp = new PrimaryExp();
                primaryExp.parser(lexer, errors);
                lineCnt = primaryExp.getLineCnt();
            }
        } else {
            primaryExp = new PrimaryExp();
            primaryExp.parser(lexer, errors);
            lineCnt = primaryExp.getLineCnt();
        }
    }

    public void output(ArrayList<String> parserResult) {
        if (primaryExp != null) {
            primaryExp.output(parserResult);
        }
        if (identifier != null) {
            parserResult.add(identifier.getType().toString() + " " + identifier.getContent());
        }
        if (lparent != null) {
            parserResult.add(lparent.getType().toString() + " " + lparent.getContent());
        }
        if (funcRParams != null) {
            funcRParams.output(parserResult);
        }
        if (rparent != null) {
            parserResult.add(rparent.getType().toString() + " " + rparent.getContent());
        }
        if (unaryOp != null) {
            unaryOp.output(parserResult);
        }
        if (unaryExp != null) {
            unaryExp.output(parserResult);
        }
        parserResult.add("<UnaryExp>");
    }

    public int getLineCnt() {
        return lineCnt;
    }
}