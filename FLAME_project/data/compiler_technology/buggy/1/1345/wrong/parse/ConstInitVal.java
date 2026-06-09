package parse;

import parse.Token;

public class ConstInitVal {
    private final String name = "<ConstInitVal>";
    private ConstInitValEle constInitValEle;

    public String getName() {
        return name;
    }

    public ConstInitVal(TokenList list,WrongList wrongs) {
        Token token = list.readNextToken();
        if (token.getType().equals("LBRACE")) {
            list.unReadToken(1);
            this.constInitValEle = new ConstInitValMulti(list,wrongs);
        } else if(token.getType().equals("STRCON")){
            list.unReadToken(1);
            this.constInitValEle = new StringConst(list,wrongs);
        } else {
            list.unReadToken(1);
            this.constInitValEle = new ConstExp(list,wrongs);
        }
    }

    public String printout() {
        StringBuilder sb = new StringBuilder();
        sb.append(constInitValEle.printout());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
