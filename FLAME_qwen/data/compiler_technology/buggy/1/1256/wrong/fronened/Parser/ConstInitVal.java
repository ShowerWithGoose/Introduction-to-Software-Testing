package fronened.Parser;

import fronened.Lexer.Token;
import fronened.Lexer.TokenIterator;

import java.util.ArrayList;

public class ConstInitVal {
    private ConstExp constExp;
    private Token lbRace;
    private ArrayList<ConstExp> constExps;
    private ArrayList<Token> commas;
    private Token rbRace;
    private Token stringConst;

    public ConstInitVal(ConstExp constExp, Token lbRace, ArrayList<ConstExp> constExps, ArrayList<Token> commas, Token rbRace, Token stringConst) {
        this.constExp = constExp;
        this.lbRace = lbRace;
        this.constExps = constExps;
        this.commas = commas;
        this.rbRace = rbRace;
        this.stringConst = stringConst;
    }

    public String print() {
        StringBuilder sb = new StringBuilder();
        if (constExp != null) {
            sb.append(constExp.print());
        }
        if (lbRace != null) {
            sb.append(lbRace.print());
            if (!constExps.isEmpty()) {
                sb.append(constExps.get(0).print());
            }
            if (!commas.isEmpty()) {
                for (int i = 0; i < commas.size(); i++) {
                    sb.append(commas.get(i).print());
                    sb.append(constExps.get(i+1).print());
                }
            }
            sb.append(rbRace.print());
        }
        if (stringConst != null) {
            sb.append(stringConst.print());
        }
        sb.append("<ConstInitVal>\n");
        return sb.toString();
    }


    public static ConstInitVal parse(TokenIterator iterator) {
        Token token = iterator.next();
        ConstExp constExp = null;
        ArrayList<ConstExp> constExps = new ArrayList<>();
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
                constExps.add(ConstExp.parse(iterator));
                token = iterator.next();
                while (token.getType().equals(Token.Type.COMMA)) {
                    commas.add(token);
                    constExps.add(ConstExp.parse(iterator));
                    token = iterator.next();
                }
            }
            rbRace = token;
        }
        else {
            iterator.back();
            constExp = ConstExp.parse(iterator);
        }
        return new ConstInitVal(constExp, lbRace, constExps, commas, rbRace, stringConst);
    }

}
