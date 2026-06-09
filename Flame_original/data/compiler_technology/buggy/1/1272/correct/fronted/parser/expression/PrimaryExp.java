package fronted.parser.expression;

import fronted.ErrorList;
import fronted.lexer.Token;
import fronted.lexer.TokenList;
import fronted.lexer.TokenType;

public class PrimaryExp {
    //PrimaryExp â†’ '(' Exp ')' | LVal | Number | Character// j

    private static final Token leftParent = new Token(TokenType.Type.LPARENT,"(",1);

    private static final Token rightParent = new Token(TokenType.Type.RPARENT,")",1);

    private Exp exp;

    private LVal lVal;

    private Number number;

    private MyCharacter character;

    private static final String name = "<PrimaryExp>\n";

    public PrimaryExp(Exp exp,LVal lVal,Number number,MyCharacter character) {
        this.exp = exp;
        this.lVal = lVal;
        this.number = number;
        this.character = character;
    }

    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        if (exp != null) {
            sb.append(leftParent);
            sb.append(exp.toString());
            sb.append(rightParent);
        } else if (lVal != null) {
            sb.append(lVal.toString());
        } else if (number != null) {
            sb.append(number.toString());
        } else {
            sb.append(character.toString());
        }
        sb.append(name);
        return sb.toString();
    }

    public static PrimaryExp parse(TokenList list){
        Token token = list.now();
        Exp exp = null;
        LVal lVal = null;
        Number number = null;
        MyCharacter character = null;
        if (token.getType().equals(TokenType.Type.LPARENT)) {
            list.next();
            exp = Exp.parse(list);
            if (list.now().getType().equals(TokenType.Type.RPARENT)) {
                list.next();
            } else {
                ErrorList.addError(list.before().getLine(),'j');
            }
        } else if (token.getType().equals(TokenType.Type.INTCON)) {
            number = Number.parse(list);
        } else if (token.getType().equals(TokenType.Type.CHRCON)) {
            character = MyCharacter.parse(list);
        } else {
            lVal = LVal.parse(list);
        }
        return new PrimaryExp(exp,lVal,number,character);
    }
}
