package frontend.Nodes;

import frontend.Token;

public class PrimaryExp implements Node {
    private int type;
    private Token lParent;
    private Exp exp;
    private Token rParent;
    private LVal lVal;
    private Number number;
    private Character character;

    public PrimaryExp() {
        this.type = 0;
        this.lParent = null;
        this.exp = null;
        this.rParent = null;
        this.lVal = null;
        this.number = null;
        this.character = null;
    }

    public void setType(int type) {
        this.type = type;
    }

    public void addLParent(Token lParent) {
        this.lParent = lParent;
    }

    public void addExp(Exp exp) {
        this.exp = exp;
    }

    public void addRParent(Token rParent) {
        this.rParent = rParent;
    }

    public void addLVal(LVal lVal) {
        this.lVal = lVal;
    }

    public void addNumber(Number number) {
        this.number = number;
    }

    public void addCharacter(Character character) {
        this.character = character;
    }

    public LVal getLVal() {
        return lVal;
    }

    @Override
    public String error() {
        StringBuilder sb = new StringBuilder();
        switch (type) {
            case 1:
                if (lParent != null) {
                    sb.append(lParent.error());
                }
                if (exp != null) {
                    sb.append(exp.error());
                }
                if (rParent != null) {
                    sb.append(rParent.error());
                }
                break;
            case 2:
                if (lVal != null) {
                    sb.append(lVal.error());
                }
                break;
            case 3:
                if (number != null) {
                    sb.append(number.error());
                }
                break;
            case 4:
                if (character != null) {
                    sb.append(character.error());
                }
                break;
            default:
                break;
        }
        return sb.toString();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        switch (type) {
            case 1:
                if (lParent != null) {
                    sb.append(lParent.toString());
                }
                if (exp != null) {
                    sb.append(exp.toString());
                }
                if (rParent != null) {
                    sb.append(rParent.toString());
                }
                break;
            case 2:
                if (lVal != null) {
                    sb.append(lVal.toString());
                }
                break;
            case 3:
                if (number != null) {
                    sb.append(number.toString());
                }
                break;
            case 4:
                if (character != null) {
                    sb.append(character.toString());
                }
                break;
            default:
                break;
        }
        sb.append("<PrimaryExp>\n");
        return sb.toString();
    }
}
