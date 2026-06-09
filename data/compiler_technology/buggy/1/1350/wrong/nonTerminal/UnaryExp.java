package nonTerminal;

import frontend.Lexer;
import frontend.SymbolTable;
import frontend.SymbolTableItem;
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

    public void parser(Lexer lexer) {
        Token.Type nowType = lexer.now().getType();
        if (nowType == Token.Type.PLUS ||
                nowType == Token.Type.MINU ||
                nowType == Token.Type.NOT) {
            unaryOp = new UnaryOp();
            unaryOp.parser(lexer);
            unaryExp = new UnaryExp();
            unaryExp.parser(lexer);
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
                    funcRParams.parser(lexer);
                }
                if (lexer.now().getType() == Token.Type.RPARENT) {
                    rparent = lexer.now();
                    lexer.move();
                } else {
                    if (funcRParams != null) {
                        rparent = new Token(Token.Type.RPARENT, ")", funcRParams.getLineCnt());
                    } else {
                        rparent = new Token(Token.Type.RPARENT, ")", lparent.getLineCnt());
                    }
                    rparent.setIsCorrect(false);
                }
                lineCnt = identifier.getLineCnt();
            } else {
                lexer.back();
                primaryExp = new PrimaryExp();
                primaryExp.parser(lexer);
                lineCnt = primaryExp.getLineCnt();
            }
        } else {
            primaryExp = new PrimaryExp();
            primaryExp.parser(lexer);
            lineCnt = primaryExp.getLineCnt();
        }
    }

    public int getLineCnt() {
        return lineCnt;
    }

    public void analyze(SymbolTable symbolTable) {
        if (primaryExp != null) {
            primaryExp.analyze(symbolTable);
        }
        if (identifier != null) {
            String name = identifier.getContent();
            if (!symbolTable.contains(name)) {
                symbolTable.addError(identifier.getLineCnt() + " c");
            } else {
                SymbolTableItem item = symbolTable.getItem(name);
                if (funcRParams != null) {
                    funcRParams.analyze(symbolTable);
                    if (item.getFuncInfo() == null) {
                        symbolTable.addError(identifier.getLineCnt() + " d");
                    } else if (item.getFuncInfo().getParaSize() != funcRParams.getSize()) {
                        symbolTable.addError(identifier.getLineCnt() + " d");
                    } else {
                        ArrayList<Exp.ExpType> thisTypes = new ArrayList<>();
                        ArrayList<String> types = symbolTable.getItem(name).getFuncInfo().getTypes();
                        for (String type : types) {
                            if (type.equals("Int") ||type.equals("Char")) {
                                thisTypes.add(Exp.ExpType.VAR);
                            } else if (type.equals("IntArray")) {
                                thisTypes.add(Exp.ExpType.INTARR);
                            } else if (type.equals("CharArray")) {
                                thisTypes.add(Exp.ExpType.CHARARR);
                            }
                        }
                        ArrayList<Exp.ExpType> paramTypes = funcRParams.getExpTypes(symbolTable);
                        if (!thisTypes.equals(paramTypes)) {
                            symbolTable.addError(identifier.getLineCnt() + " e");
                        }
                    }
                } else {
                    if (item.getFuncInfo() != null) {
                        symbolTable.addError(identifier.getLineCnt() + " d");
                    }
                }
            }
            if (!rparent.getIsCorrect()) {
                symbolTable.addError(rparent.getLineCnt() + " j");
            }
        }
        if (unaryExp != null) {
            unaryExp.analyze(symbolTable);
        }
    }

    public PrimaryExp getPrimaryExp() {
        return primaryExp;
    }
}