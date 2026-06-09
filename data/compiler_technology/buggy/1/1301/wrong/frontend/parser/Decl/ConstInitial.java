package frontend.parser.Decl;

import frontend.lexer.LexType;
import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.parser.Exp.ConstExp;

import java.util.ArrayList;

public class ConstInitial {
    //case 1
    private ConstExp onlyConstExp;
    //case 2
    private Token lbrace;
    private ConstExp firstConstExp; //可能没有
    private ArrayList<Token> commas; //可能没有
    private ArrayList<ConstExp> constExps; //可能没有
    private Token rbrace;
    //case 3
    private Token stringConst;
    //share by all cases
    private TokenList tokens;
    private int errorNum;
    private String nonTerminalName = "ConstInitVal";

    public ConstInitial(TokenList tokens) {
        this.onlyConstExp = null;
        this.lbrace = null;
        this.firstConstExp = null;
        this.commas = new ArrayList<>();
        this.constExps = new ArrayList<>();
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
                firstConstExp = new ConstExp(tokens);
                errorNum += firstConstExp.parse();
                first = tokens.nextToken();
                while (first.equals(LexType.COMMA)) {
                    commas.add(first);
                    ConstExp constExp = new ConstExp(tokens);
                    errorNum += constExp.parse();
                    constExps.add(constExp);
                    first = tokens.nextToken();
                }
                rbrace = first;
            }
        } else if (first.equals(LexType.STRCON)) { //case 3
            stringConst = first;
        } else { //case 1
            tokens.rollBack(1);
            onlyConstExp = new ConstExp(tokens);
            errorNum += onlyConstExp.parse();
        }
        return errorNum;
    }

    public String toSyntaxTree() {
        StringBuilder sb = new StringBuilder();
        if (onlyConstExp != null) { //case 1
            sb.append(onlyConstExp.toSyntaxTree());
        } else if (lbrace != null) { //case 2
            sb.append(lbrace);
            if (firstConstExp != null) {
                sb.append(firstConstExp.toSyntaxTree());
                for (int i = 0;i < constExps.size();i++) {
                    sb.append(commas.get(i)).append(constExps.get(i).toSyntaxTree());
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
