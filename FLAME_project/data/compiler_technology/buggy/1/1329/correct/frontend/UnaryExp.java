package frontend;

import java.util.ArrayList;

public class UnaryExp {
    // 一元表达式
    // PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
    // 可能出现j错误，缺右小括号
    private int leibie; //1-3
    private PrimaryExp primaryExp;
    private ArrayList<Word> words = new ArrayList<>();
    private FuncRParams funcRParams;
    private UnaryOp unaryOp;
    private UnaryExp unaryExp;

    private int wrong = 0;

    public String toString() {
        StringBuilder sb = new StringBuilder();
        int pos = 0;
        if (leibie == 1) {
            sb.append(primaryExp.toString());
        } else if (leibie == 2) {
            sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
            sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
            if (funcRParams != null) {
                sb.append(funcRParams.toString());
            }
            sb.append(words.get(pos).getLeiBie()).append(" ").append(words.get(pos++).getStr()).append("\n");
        } else if (leibie == 3) {
            sb.append(unaryOp.toString());
            sb.append(unaryExp.toString());
        }
        sb.append("<UnaryExp>");
        sb.append("\n");
        return sb.toString();
    }

    public void setWordWrong(int type) {
        if (leibie == 1) {
            primaryExp.setWordWrong(type);
        } else if (leibie == 2) {
            if (wrong == 0) {
                words.get(2).setRight(type);
            } else {
                if (funcRParams != null) {
                    funcRParams.setWordWrong(type);
                } else {
                    words.get(1).setRight(type);
                }
            }
        } else if (leibie == 3) {
            unaryExp.setWordWrong(type);
        }
    }

    public UnaryExp() {
        funcRParams = null;
    }

    public void setLeibie(int leibie) {
        this.leibie = leibie;
    }

    public void addWord(Word word) {
        words.add(word);
    }

    public void setFuncRParams(FuncRParams funcRParams) {
        this.funcRParams = funcRParams;
    }

    public void setPrimaryExp(PrimaryExp primaryExp) {
        this.primaryExp = primaryExp;
    }

    public void setUnaryExp(UnaryExp unaryExp) {
        this.unaryExp = unaryExp;
    }

    public void setUnaryOp(UnaryOp unaryOp) {
        this.unaryOp = unaryOp;
    }

    public void setWrong() {
        this.wrong = 1;
        if (funcRParams != null) {
            funcRParams.setWordWrong(-2);
        } else {
            words.get(1).setRight(-2);
        }
    }
}
