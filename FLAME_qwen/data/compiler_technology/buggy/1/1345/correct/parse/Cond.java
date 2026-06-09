package parse;

public class Cond {
    private final String name = "<Cond>";
    private LOrExp lorExp;

    public String getName() {
        return name;
    }

    public LOrExp getLorExp() {
        return lorExp;
    }

    public void setLorExp(LOrExp lorExp) {
        this.lorExp = lorExp;
    }

    public Cond(TokenList list,WrongList wrongs) {
        this.lorExp = new LOrExp(list,wrongs);
    }

    public String printout() {
        StringBuilder sb = new StringBuilder();
        sb.append(lorExp.printout());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
