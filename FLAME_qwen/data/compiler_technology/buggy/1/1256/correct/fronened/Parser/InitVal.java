package fronened.Parser;

import fronened.Lexer.Token;
import fronened.Lexer.TokenIterator;

import java.util.ArrayList;

public class InitVal {
    private Exp exp;
    private Token lbRace;
    private ArrayList<Exp> exps;
    private ArrayList<Token> commas;
    private Token rbRace;
    private Token stringConst;

    public InitVal(Exp exp, Token lbRace, ArrayList<Exp> exps, ArrayList<Token> commas, Token rbRace, Token stringConst) {
        this.exp = exp;
        this.lbRace = lbRace;
        this.exps = exps;
        this.commas = commas;
        this.rbRace = rbRace;
        this.stringConst = stringConst;
    }

    public String print() {
        StringBuilder sb = new StringBuilder();
        if (exp != null) {
            sb.append(exp.print());
        }
        if (lbRace != null) {
            sb.append(lbRace.print());
            if (!exps.isEmpty()) {
                sb.append(exps.get(0).print());
            }
            if (!commas.isEmpty()) {
                for (int i = 0; i < commas.size(); i++) {
                    sb.append(commas.get(i).print());
                    sb.append(exps.get(i+1).print());
                }
            }
            sb.append(rbRace.print());
        }
        if (stringConst != null) {
            sb.append(stringConst.print());
        }
        sb.append("<InitVal>\n");
        return sb.toString();
    }


    public static InitVal parse(TokenIterator iterator) {
        Token token = iterator.next();
        Exp exp = null;
        ArrayList<Exp> constExps = new ArrayList<>();
        ArrayList<Token> commas = new ArrayList<>();
        Token lbRace = null;
        Token rbRace = null;
        Token stringConst = null;
        if (token.getType().equals(Token.Type.STRCON)) {
            stringConst = token;
        }
        else if (token.getType().equals(Token.Type.LBRACE)) {
            lbRace = token;
            token = iterator.next();
            if (!token.getType().equals(Token.Type.RBRACE)) {
                iterator.back();
                constExps.add(Exp.parse(iterator));
                token = iterator.next();
                while (token.getType().equals(Token.Type.COMMA)) {
                    commas.add(token);
                    constExps.add(Exp.parse(iterator));
                    token = iterator.next();
                }
            }
            rbRace = token;
        }
        else {
            iterator.back();
            exp = Exp.parse(iterator);
        }
        return new InitVal(exp, lbRace, constExps, commas, rbRace, stringConst);
    }

}
