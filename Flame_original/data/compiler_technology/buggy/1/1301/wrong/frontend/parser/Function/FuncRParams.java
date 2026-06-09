package frontend.parser.Function;

import frontend.lexer.LexType;
import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.parser.Exp.CombineExp.LAndExp;
import frontend.parser.Exp.Exp;

import java.util.ArrayList;

public class FuncRParams {
    private Exp firstExp;
    private ArrayList<Token> commas; //,可以没有
    private ArrayList<Exp> exps; //可以没有
    private TokenList tokens;
    private int errorNum;
    private String nonTerminalName = "FuncRParams";

    public FuncRParams(TokenList tokens) {
        this.firstExp = null;
        this.commas = new ArrayList<>();
        this.exps = new ArrayList<>();
        this.tokens = tokens;
        this.errorNum = 0;
    }

    public int parse() { //return error num
        firstExp = new Exp(tokens);
        errorNum += firstExp.parse();
        Token token = tokens.nextToken();
        while (token.equals(LexType.COMMA)) {
            commas.add(token);
            Exp exp = new Exp(tokens);
            errorNum += exp.parse();
            exps.add(exp);
            token = tokens.nextToken();
        }
        tokens.rollBack(1);
        return errorNum;
    }

    public String toSyntaxTree() {
        StringBuilder sb = new StringBuilder();
        sb.append(firstExp.toSyntaxTree());
        for (int i = 0;i < exps.size();i++) {
            sb.append(commas.get(i)).append(exps.get(i).toSyntaxTree());
        }
        sb.append('<').append(this.nonTerminalName).append('>').append('\n');
        return sb.toString();
    }
}
