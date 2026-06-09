package frontend;

public class PrimaryExp {
    // '(' Exp ')' | LVal | Number | Character
    // 可能出现j错误，缺右小括号
    private int leibie; //1-4
    private Word zuo;
    private Word you;
    private Exp exp;
    private LVal lVal;
    private Number number;
    private Characte character;

    private int wrong = 0;

    public PrimaryExp() {}

    public void setWordWrong(int type) {
        if (leibie == 1) {
            if (wrong == 0) {
                you.setRight(type);
            } else {
                exp.setWordWrong(type);
            }
        } else if (leibie == 2) {
            lVal.setWordWrong(type);
        } else if (leibie == 3) {
            number.setWordWrong(type);
        } else if (leibie == 4) {
            character.setWordWrong(type);
        }
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        if (leibie == 1) {
            sb.append(zuo.getLeiBie()).append(" ").append(zuo.getStr()).append("\n");
            sb.append(exp.toString());
            if (wrong == 0) {
                sb.append(you.getLeiBie()).append(" ").append(you.getStr()).append("\n");
            }
        } else if (leibie == 2) {
            sb.append(lVal.toString());
        } else if (leibie == 3) {
            sb.append(number.toString());
        } else if (leibie == 4) {
            sb.append(character.toString());
        }
        sb.append("<PrimaryExp>");
        sb.append("\n");
        return sb.toString();
    }

    public void setExp(Exp exp) {
        this.exp = exp;
    }

    public void setlVal(LVal lVal) {
        this.lVal = lVal;
    }

    public void setLeibie(int leibie) {
        this.leibie = leibie;
    }

    public void setZuo(Word zuo) {
        this.zuo = zuo;
    }

    public void setYou(Word you) {
        this.you = you;
    }

    public void setCharacter(Characte character) {
        this.character = character;
    }

    public void setNumber(Number number) {
        this.number = number;
    }

    public void setWrong() {
        this.wrong = 1;
        exp.setWordWrong(-2);
    }
}
