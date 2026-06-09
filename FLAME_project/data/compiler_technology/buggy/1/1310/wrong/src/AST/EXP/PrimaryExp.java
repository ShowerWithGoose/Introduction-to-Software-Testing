package src.AST.EXP;

import src.AST.LVal;
import src.AST.PCharacter;
import src.AST.PNumber;
import src.AST.Type.PrimaryExpType;
import src.ErrorHandle.Errortype;
import src.fronted.LexicAnalysis.Word;
import src.fronted.LexicAnalysis.WordType;
import src.fronted.SyntaxAnalysis.SyntaxType;

import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.syntaxList;
import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.utils;

public class PrimaryExp {
    private PrimaryExpType primaryExpType;
    private Word lParent;
    private Exp exp;
    private Word rParent;
    private LVal lVal;
    private PNumber pNumber;
    private PCharacter pChar;

    public PrimaryExp() {
    }

    public PrimaryExp analyse() {
        if (utils.preRead(1) == WordType.LPARENT) {
            this.primaryExpType = PrimaryExpType.EXp;
            this.lParent = utils.read("(");
            this.exp = new Exp().analyse();
            this.rParent = utils.tryReadnext(1, ")", Errortype.j);
            //注意错误处理
        } else if (utils.preRead(1) == WordType.IDENFR) {
            this.primaryExpType = PrimaryExpType.LVAL;
            this.lVal = new LVal().analyse();
        } else if (utils.preRead(1) == WordType.INTCON) {
            this.primaryExpType = PrimaryExpType.NUMBER;
            this.pNumber = new PNumber().analyse();
        } else {
            this.primaryExpType = PrimaryExpType.CHARACTER;
            this.pChar = new PCharacter().analyse();
        }
        syntaxList.add("<" + SyntaxType.PrimaryExp + ">");
        return this;
    }
}
