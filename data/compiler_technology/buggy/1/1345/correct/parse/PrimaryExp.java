package parse;

public class PrimaryExp implements UnaryExpEle {
    private final String name = "<PrimaryExp>";
    private PrimaryExpEle primaryExpEle;

    public String getName() {
        return name;
    }

    public PrimaryExpEle getPrimaryExpEle() {
        return primaryExpEle;
    }

    public void setPrimaryExpEle(PrimaryExpEle primaryExpEle) {
        this.primaryExpEle = primaryExpEle;
    }

    public PrimaryExp(TokenList list,WrongList wrongs) {
        Token token = list.readNextToken();
        if (token.getType().equals("LPARENT")) {
            list.unReadToken(1);
            this.primaryExpEle = new PrimaryExpp(list,wrongs);
        } else if (token.getType().equals("IDENFR")) {
            list.unReadToken(1);
            this.primaryExpEle = new LVal(list,wrongs);
        } else if (token.getType().equals("INTCON")) {
            list.unReadToken(1);
            this.primaryExpEle = new Number(list,wrongs);
        } else if (token.getType().equals("CHRCON")) {
            list.unReadToken(1);
            this.primaryExpEle = new Characte(list,wrongs);
        }
        else {
//            System.out.println(token.getLinenumber() +" "+ token.getType() + "" + token.getContent() + "\n");
        }
    }

    public String printout() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.primaryExpEle.printout());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
