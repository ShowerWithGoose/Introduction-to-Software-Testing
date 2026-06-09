package src.AST.STMT;

import src.AST.BLOCK.Block;
import src.AST.Type.StmtLValjudgeType;
import src.AST.Type.StmtType;
import src.ErrorHandle.Errortype;
import src.fronted.LexicAnalysis.Word;
import src.fronted.LexicAnalysis.WordType;
import src.fronted.SyntaxAnalysis.SyntaxType;

import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.syntaxList;
import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.utils;

public class Stmt {
    private StmtType stmtType;
    private StmtLVal stmtLValEq;
    //注意这里StmtLVal是一个句子而不是LVal
    //也就是说前缀为stmt的，全部都是我自己用的一个临时的非终结符，最后要填的还是Stmt
    private StmtExp stmtExp;
    private Word semicolon;
    private Block block;
    private StmtIf stmtIf;
    private StmtFor stmtFor;
    private StmtBreak stmtBreak;
    private StmtContinue stmtContinue;
    private StmtReturn stmtReturn;
    private StmtLValGetint stmtLValGetint;
    private StmtLValGetchar stmtLValGetchar;
    private StmtPrintf stmtPrintf;

    public Stmt() {
    }

    public Stmt analyse() {
        if (utils.preRead(1) == WordType.LBRACE) {
            this.stmtType = StmtType.BLOCK;
            this.block = new Block().analyse();
        } else if (utils.preRead(1) == WordType.IFTK) {
            this.stmtType = StmtType.IF;
            this.stmtIf = new StmtIf().analyse();
        } else if (utils.preRead(1) == WordType.FORTK) {
            this.stmtType = StmtType.FOR;
            this.stmtFor = new StmtFor().analyse();
        } else if (utils.preRead(1) == WordType.BREAKTK) {
            this.stmtType = StmtType.BREAK;
            this.stmtBreak = new StmtBreak().analyse();
        } else if (utils.preRead(1) == WordType.CONTINUETK) {
            this.stmtType = StmtType.CONTINUE;
            this.stmtContinue = new StmtContinue().analyse();
        } else if (utils.preRead(1) == WordType.RETURNTK) {
            this.stmtType = StmtType.RETURN;
            this.stmtReturn = new StmtReturn().analyse();
        } else if (utils.preRead(1) == WordType.PRINTFTK) {
            this.stmtType = StmtType.PRINTF;
            this.stmtPrintf = new StmtPrintf().analyse();
        } else if (utils.containEq()) {
            if (utils.StmtLValjuage() == StmtLValjudgeType.EQ) {
                this.stmtType = StmtType.LVALASSIGN;
                this.stmtLValEq = new StmtLVal().analyse();
            } else if (utils.StmtLValjuage() == StmtLValjudgeType.GETCHAR) {
                this.stmtType = StmtType.LVALGETCHAR;
                this.stmtLValGetchar = new StmtLValGetchar().analyse();
            } else {
                this.stmtType = StmtType.LVALGETINT;
                this.stmtLValGetint = new StmtLValGetint().analyse();
            }
        } else {//Exp
            this.stmtType = StmtType.EXPorSEMICN;
            this.stmtExp = new StmtExp().analyse();
        }
        syntaxList.add("<" + SyntaxType.Stmt + ">");
        return this;
    }
}
