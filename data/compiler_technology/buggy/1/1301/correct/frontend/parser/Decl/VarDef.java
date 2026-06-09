package frontend.parser.Decl;

import error.ErrorHandling;
import frontend.lexer.LexType;
import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.parser.Exp.ConstExp;

public class VarDef {
    private Token ident;
    private Token lbrack; //[可以没有
    private ConstExp constExp; //可以没有
    private Token rbrack; //]可以没有
    private Token assign; //=可以没有
    private Initial initial; //可以没有
    private TokenList tokens;
    private int errorNum;
    private String nonTerminalName = "VarDef";

    public VarDef(TokenList tokens) {
        this.ident = null;
        this.lbrack = null;
        this.constExp = null;
        this.rbrack = null;
        this.assign = null;
        this.initial = null;
        this.tokens = tokens;
        this.errorNum = 0;
    }

    public int parse() { //return error num
        ident = tokens.nextToken();
        Token first = tokens.nextToken();
        if (first.equals(LexType.LBRACK)) { //[
            lbrack = first;
            constExp = new ConstExp(tokens);
            errorNum += constExp.parse();
            first = tokens.nextToken();
            if (first.equals(LexType.RBRACK)) { //]
                rbrack = first;
                first = tokens.nextToken();
            } else { //error k
                ErrorHandling.printError(tokens.preNonTerminalLineNum(), 'k');
                errorNum++;
            }
        }
        if (first.equals(LexType.ASSIGN)) {
            assign = first;
            initial = new Initial(tokens);
            errorNum += initial.parse();
        } else {
            tokens.rollBack(1);
        }
        return errorNum;
    }

    public String toSyntaxTree() {
        StringBuilder sb = new StringBuilder();
        sb.append(ident);
        if (lbrack != null) {
            sb.append(lbrack).append(constExp.toSyntaxTree());
            if (rbrack != null) {
                sb.append(rbrack);
            }
        }
        if (assign != null) {
            sb.append(assign).append(initial.toSyntaxTree());
        }
        sb.append('<').append(this.nonTerminalName).append('>').append('\n');
        return sb.toString();
    }
}
