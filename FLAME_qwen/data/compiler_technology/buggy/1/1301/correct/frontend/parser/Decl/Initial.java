package frontend.parser.Decl;

import frontend.lexer.LexType;
import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.parser.Exp.Exp;

import java.util.ArrayList;

public class Initial {
    //case 1
    private Exp onlyExp;
    //case 2
    private Token lbrace;
    private Exp firstExp; //可能没有
    private ArrayList<Token> commas; //可能没有
    private ArrayList<Exp> exps; //可能没有
    private Token rbrace;
    //case 3
    private Token stringConst;
    //share by all cases
    private TokenList tokens;
    private int errorNum;
    private String nonTerminalName = "InitVal";

    public Initial(TokenList tokens) {
        this.onlyExp = null;
        this.lbrace = null;
        this.firstExp = null;
        this.commas = new ArrayList<>();
        this.exps = new ArrayList<>();
        this.rbrace = null;
        this.stringConst = null;
        this.tokens = tokens;
        this.errorNum = 0;
    }

    public int parse() { //return error num
        Token first = tokens.nextToken();
        if (first.equals(LexType.LBRACE)) { //case 2
            lbrace = first;
            first = tokens.nextToken();
            if (first.equals(LexType.RBRACE)) {
                rbrace = first;
            } else {
                tokens.rollBack(1);
                firstExp = new Exp(tokens);
                errorNum += firstExp.parse();
                first = tokens.nextToken();
                while (first.equals(LexType.COMMA)) {
                    commas.add(first);
                    Exp exp = new Exp(tokens);
                    errorNum += exp.parse();
                    exps.add(exp);
                    first = tokens.nextToken();
                }
                rbrace = first;
            }
        } else if (first.equals(LexType.STRCON)) { //case 3
            stringConst = first;
        } else { //case 1
            tokens.rollBack(1);
            onlyExp = new Exp(tokens);
            errorNum += onlyExp.parse();
        }
        return errorNum;
    }

    public String toSyntaxTree() {
        StringBuilder sb = new StringBuilder();
        if (onlyExp != null) { //case 1
            sb.append(onlyExp.toSyntaxTree());
        } else if (lbrace != null) { //case 2
            sb.append(lbrace);
            if (firstExp != null) {
                sb.append(firstExp.toSyntaxTree());
                for (int i = 0;i < exps.size();i++) {
                    sb.append(commas.get(i)).append(exps.get(i).toSyntaxTree());
                }
            }
            sb.append(rbrace);
        } else { //case 3
            sb.append(stringConst);
        }
        sb.append('<').append(this.nonTerminalName).append('>').append('\n');
        return sb.toString();
    }


}
