package parse;

public class UnaryExp implements PrintInter{
    private final String name = "<UnaryExp>";
    private UnaryExpEle unaryExpEle;

    public String getName() {
        return name;
    }

    public UnaryExpEle getUnaryExpEle() {
        return unaryExpEle;
    }

    public void setUnaryExpEle(UnaryExpEle unaryExpEle) {
        this.unaryExpEle = unaryExpEle;
    }

    public UnaryExp(TokenList list,WrongList wrongs) {
        Token x = list.readNextToken();
        Token y = list.readNextToken();
        if (x.getType().equals("IDENFR") &&
                y.getType().equals("LPARENT")) {
            list.unReadToken(2);
            this.unaryExpEle = new UnaryExpFunc(list,wrongs);
        } else if (x.getType().equals("LPARENT") ||
                x.getType().equals("IDENFR") ||
                x.getType().equals("INTCON") ||
                x.getType().equals("CHRCON") ) {
            list.unReadToken(2);
            this.unaryExpEle = new PrimaryExp(list,wrongs);
        } else if (x.getType().equals("PLUS") ||
                x.getType().equals("MINU") ||
                x.getType().equals("NOT")) {
            list.unReadToken(2);
            this.unaryExpEle = new UnaryExpOp(list,wrongs);
        }
        else {
//            System.out.println(x.getLinenumber() +" "+ x.getType() + "" + x.getContent() + "\n" + y.getType());
        }
    }

    public String printout() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.unaryExpEle.printout());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
