package src.AST.EXP;

import src.AST.PARAMS.FuncRParams;
import src.AST.Ident;
import src.AST.Type.UnaryExpType;
import src.AST.Type.UnaryOp;
import src.ErrorHandle.Errortype;
import src.fronted.LexicAnalysis.Word;
import src.fronted.LexicAnalysis.WordType;
import src.fronted.SyntaxAnalysis.SyntaxType;

import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.syntaxList;
import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.utils;

public class UnaryExp {
    private UnaryExpType unaryExpType;
    private PrimaryExp primaryExp;
    private Word ident;
    private Word lParent;
    private FuncRParams funcRParams;
    private Word rParent;
    private UnaryOp unaryOp;
    private UnaryExp unaryExp;

    public UnaryExp() {
    }

    public UnaryExp analyse() {
        if (utils.preRead(1) == WordType.LPARENT
                || (utils.preRead(1) == WordType.IDENFR && utils.preRead(2) != WordType.LPARENT)
                || utils.preRead(1) == WordType.INTCON
                || utils.preRead(1) == WordType.CHRCON) {
            this.unaryExpType = UnaryExpType.PRIMARYEXP;
            this.primaryExp = new PrimaryExp().analyse();
        } else if (utils.preRead(1) == WordType.IDENFR
                && utils.preRead(2) == WordType.LPARENT) {
            this.unaryExpType = UnaryExpType.IDENT;
            this.ident = new Ident().analyse();
            this.lParent = utils.read("(");
            if (utils.haveRParams()) {
                this.funcRParams = new FuncRParams().analyse();
            }
            // j
            this.rParent = utils.tryReadnext(1, ")", Errortype.j);
            //暂时不考虑报错
        } else {
            this.unaryExpType = UnaryExpType.UNARYOP;
            if (utils.preRead(1) == WordType.PLUS) {
                utils.read("+");
                syntaxList.add("<" + SyntaxType.UnaryOp + ">");
                this.unaryOp = UnaryOp.PLUS;
            } else if (utils.preRead(1) == WordType.MINU) {
                utils.read("-");
                syntaxList.add("<" + SyntaxType.UnaryOp + ">");
                this.unaryOp = UnaryOp.MINU;
            } else {
                utils.read("!");
                syntaxList.add("<" + SyntaxType.UnaryOp + ">");
                this.unaryOp = UnaryOp.NOT;
            }
            this.unaryExp = new UnaryExp().analyse();
        }
        syntaxList.add("<" + SyntaxType.UnaryExp + ">");
        return this;
    }
}
