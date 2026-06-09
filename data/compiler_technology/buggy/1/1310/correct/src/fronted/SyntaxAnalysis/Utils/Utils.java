package src.fronted.SyntaxAnalysis.Utils;

import src.AST.Type.FuncType;
import src.AST.Type.StmtLValjudgeType;
import src.ErrorHandle.BaseError;
import src.ErrorHandle.Errortype;
import src.fronted.LexicAnalysis.Word;
import src.fronted.LexicAnalysis.WordType;
import src.fronted.SyntaxAnalysis.SyntaxType;


import static src.fronted.LexicAnalysis.LexicAnalysis.WordList;
import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.Syntaxcur;
import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.syntaxList;
import static src.ErrorHandle.ErrorController.ErrorList;

public class Utils {
    int LexicSize = WordList.size();

    public Utils() {

    }

    public WordType preRead(int i) {
        if (Syntaxcur + i < LexicSize) {
            return WordList.get(Syntaxcur + i).getWordType();
        } else {
            return null;
        }
    }

    public Word read(String s) {
        if (Syntaxcur + 1 < LexicSize) {
            if (s.equals(WordList.get(Syntaxcur + 1).getWordName())
                    || (s.equals("Ident") && preRead(1) == WordType.IDENFR)
                    || (s.equals("IntConst") && preRead(1) == WordType.INTCON)
                    || (s.equals("StringConst") && preRead(1) == WordType.STRCON)
                    || (s.equals("CharConst") && preRead(1) == WordType.CHRCON)) {
                syntaxList.add(WordList.get(Syntaxcur + 1).getWordType() + " " + WordList.get(Syntaxcur + 1).getWordName());
                //在这里就放到列表里了，在外面都放到语法树的数据结构里
                Syntaxcur += 1;
                return WordList.get(Syntaxcur);
            } else {
                return null;
            }
        }
        return null;
    }

    public WordType Error2WordType(Errortype e) {
        switch (e) {
            case i -> {
                return WordType.SEMICN;
            }
            case j -> {
                return WordType.RPARENT;
            }
            case k -> {
                return WordType.RBRACK;
            }
            default -> {
                return null;
            }
        }
    }

    public Word tryReadnext(int next, String s, Errortype errortype) {
        if (!WordList.get(Syntaxcur + next).getWordName().equals(s)) {
            ErrorList.add(new BaseError(WordList.get(Syntaxcur).getRow(), errortype));
            syntaxList.add(Error2WordType(errortype) + " " + s);
            //暂时还是存放进最后的列表里吧，虽然也不会输出，因为有了ErrorList就不输出syntaxList
            //但是要注意的是Syntaxcur不要加1，要返回正确结果才能存到语法树里。
            return new Word(s, Error2WordType(errortype), WordList.get(Syntaxcur).getRow(), -1);
        } else {
            return read(s);
        }
    }
    public boolean returnHasExp(){
        return preRead(1) != WordType.SEMICN && WordList.get(Syntaxcur).getRow() == WordList.get(Syntaxcur + 1).getRow();
    }

    public boolean haveRParams() {
        //我们发现如果FuncRParams存在，则首先是Exp，也就是AddExp，也就是MulExp，也就是UnaryExp.
        //进而发现开头的情况为下面几种。
        return preRead(1) == WordType.IDENFR
                || preRead(1) == WordType.LPARENT
                || preRead(1) == WordType.PLUS
                || preRead(1) == WordType.MINU
                || preRead(1) == WordType.NOT
                || preRead(1) == WordType.INTCON
                || preRead(1) == WordType.CHRCON;
    }

    public FuncType getFuncType() {
        if (preRead(1) == WordType.VOIDTK) {
            read("void");
            syntaxList.add("<" + SyntaxType.FuncType + ">");
            return FuncType.VOID;
        } else if (preRead(1) == WordType.INTTK) {
            read("int");
            syntaxList.add("<" + SyntaxType.FuncType + ">");
            return FuncType.INT;
        } else {
            read("char");
            syntaxList.add("<" + SyntaxType.FuncType + ">");
            return FuncType.CHAR;
        }
    }

    public StmtLValjudgeType StmtLValjuage() {
        int i = 1;
        int tempRow = WordList.get(Syntaxcur + 1).getRow();
        while (preRead(i) != WordType.ASSIGN
                && tempRow == WordList.get(Syntaxcur + i).getRow()) {
            i++;
        }
        if (preRead(i + 1) == WordType.GETCHARTK) {
            return StmtLValjudgeType.GETCHAR;
        } else if (preRead(i + 1) == WordType.GETINTTK) {
            return StmtLValjudgeType.GETINT;
        } else {
            return StmtLValjudgeType.EQ;
        }
//        if (preRead(i - 1) == WordType.RPARENT
//                && preRead(i - 2) == WordType.LPARENT) {
//            //即使分号前是括号，但也有可能是EXP->(EXP)
//            if (preRead(i - 3) == WordType.GETINTTK) {
//                return StmtLValjudgeType.GETINT;
//            } else if (preRead(i - 3) == WordType.GETCHARTK) {
//                return StmtLValjudgeType.GETCHAR;
//            } else {
//                return StmtLValjudgeType.EQ;
//            }
//        }
//        return StmtLValjudgeType.EQ;

    }

    public boolean containEq() {
        //这里在判断是否有等号时，Syntaxcur在上一行。所以tempRow要加一
        //但是不一定加1，因为万一中间插一个注释那就完了。
        //应该是Syntaxcur+1
        int i = 1;
        int tempRow = WordList.get(Syntaxcur + 1).getRow();
        while (WordList.get(Syntaxcur + i).getRow() == tempRow) {
            //这里要根据等号来识别，不能根据分号，否则有可能会和错误类型发生莫名的问题
            //这里要注意保证在同一行，否则可能因为漏写了;原本应该报错，但是却识别成了另一种
            if (preRead(i) == WordType.ASSIGN) {
                return true;
            }
            i++;
        }
//        while (preRead(i) != WordType.SEMICN) {
//            if (preRead(i) == WordType.ASSIGN) {
//                return true;
//            }
//            i++;
//        }
        return false;
    }

    public boolean isRelExp() {
        return preRead(1) == WordType.LSS || preRead(1) == WordType.GEQ ||
                preRead(1) == WordType.LEQ || preRead(1) == WordType.GRE;
    }

    public boolean isBType(WordType wordType) {
        return wordType == WordType.INTTK || wordType == WordType.CHARTK;
    }

}
