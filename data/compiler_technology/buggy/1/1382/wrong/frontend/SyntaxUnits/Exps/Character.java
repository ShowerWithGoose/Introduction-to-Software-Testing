package frontend.SyntaxUnits.Exps;


import frontend.Token;

public class Character implements PrimaryExpUnit {
    private final Token charConst;

    public Character(Token charConst) {
        this.charConst = charConst;
    }

    @Override
    public String toPrint() {
       return charConst.toPrint() + "<Character>\n";
    }
}
