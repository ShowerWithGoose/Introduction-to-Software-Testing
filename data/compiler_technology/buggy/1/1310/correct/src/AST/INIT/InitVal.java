package src.AST.INIT;

import src.AST.EXP.ConstExp;
import src.AST.EXP.Exp;
import src.AST.Type.InitValType;
import src.fronted.LexicAnalysis.Word;
import src.fronted.LexicAnalysis.WordType;
import src.fronted.SyntaxAnalysis.SyntaxType;

import java.util.ArrayList;

import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.utils;
import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.syntaxList;

public class InitVal {
    private InitValType initValType;
    private Exp exp;
    private Word lBrace;
    private ArrayList<Word> commaList;
    private ArrayList<Exp> ExpList;
    private Word rBrace;
    private Word StringConst;

    public InitVal() {
        this.commaList = new ArrayList<>();
        this.ExpList = new ArrayList<>();
    }

    public InitVal analyse() {
        if (utils.preRead(1) == WordType.STRCON) {
            this.initValType = InitValType.StringConst;
            this.StringConst = utils.read("StringConst");
        } else if (utils.preRead(1) == WordType.LBRACE) {
            this.lBrace = utils.read("{");
            if (utils.preRead(1) == WordType.RBRACE) {
                this.initValType = InitValType.Empty;
            } else {
                //既然不为空，那就先读一个Exp
                this.ExpList.add((new Exp().analyse()));
                if (utils.preRead(1) == WordType.COMMA) {
                    this.initValType = InitValType.ExpList;
                    while (utils.preRead(1) == WordType.COMMA) {
                        this.commaList.add(utils.read(","));
                        this.ExpList.add(new Exp().analyse());
                    }
                } else {
                    this.initValType = InitValType.signalExpwithR;
                }
            }
            //if (utils.preRead(2) == WordType.COMMA) {
            //写每一步都要很注意啊，往后读两位不是逗号就一定不是ExpList吗？
            //这个参数有没有可能比较长呢？比如：a[0]
            //因为能进这个那么能不能一直往后读直到右括号，看其中有没有逗号。
            //所以最好先判断是否为空，然后读了一个Exp之后再判断
            //需要注意的是，这里不会有错误处理
//                this.initValType = InitValType.ExpList;
//                this.ExpList.add((new Exp().analyse()));
//                while (utils.preRead(1) == WordType.COMMA) {
//                    this.commaList.add(utils.read(","));
//                    this.ExpList.add(new Exp().analyse());
//                }
//            } else if (utils.preRead(1) != WordType.RBRACE) {
//                this.initValType = InitValType.signalExpwithR;
//                this.exp = new Exp().analyse();
//            } else {
//                this.initValType = InitValType.Empty;
//            }
            this.rBrace = utils.read("}");
        } else {
            this.initValType = InitValType.signalExp;
            this.exp = new Exp().analyse();
        }
        syntaxList.add("<" + SyntaxType.InitVal + ">");
        return this;
    }
}
