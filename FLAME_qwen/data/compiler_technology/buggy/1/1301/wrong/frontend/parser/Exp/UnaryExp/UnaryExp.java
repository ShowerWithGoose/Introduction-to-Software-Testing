package frontend.parser.Exp.UnaryExp;

import error.ErrorHandling;
import frontend.lexer.LexType;
import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.parser.Function.FuncRParams;

import java.util.ArrayList;

public class UnaryExp {
    private ArrayList<UnaryOp> unaryOps; //+-!可以没有
    //case 1
    private PrimaryExp primaryExp;
    //case 2
    private Token ident;
    private Token lparent;
    private FuncRParams funcRParams; //可能没有
    private Token rparent;
    //share by all cases
    private TokenList tokens;
    private int errorNum;
    private String nonTerminalName = "UnaryExp";

    public UnaryExp(TokenList tokens) {
        this.unaryOps = new ArrayList<>();
        this.primaryExp = null;
        this.ident = null;
        this.lparent = null;
        this.funcRParams = null;
        this.rparent = null;
        this.tokens = tokens;
        this.errorNum = 0;
    }

    public int parse() { //return error num
        Token token = tokens.nextToken();
        while (token.equals(LexType.PLUS) || token.equals(LexType.MINU) || token.equals(LexType.NOT)) {
            tokens.rollBack(1);
            UnaryOp unaryOp = new UnaryOp(tokens);
            errorNum += unaryOp.parse();
            unaryOps.add(unaryOp);
            token = tokens.nextToken();
        }
        Token second = tokens.nextToken();
        if (token.equals(LexType.IDENFR) && second.equals(LexType.LPARENT)) { //case 2
            ident = token;
            lparent = second;
            Token third = tokens.nextToken();
            if (startIsExp(third)) { //有FuncRParams
                tokens.rollBack(1);
                funcRParams = new FuncRParams(tokens);
                errorNum += funcRParams.parse();
                third = tokens.nextToken();
            }
            if (third.equals(LexType.RPARENT)) {
                rparent = third;
            } else {
                ErrorHandling.printError(tokens.preNonTerminalLineNum(),'j');
                errorNum++;
                tokens.rollBack(1);
            }
        } else { //case 1
            tokens.rollBack(2);
            primaryExp = new PrimaryExp(tokens);
            errorNum += primaryExp.parse();
        }
        return errorNum;
    }

    private boolean startIsExp(Token token) {
        if (token.equals(LexType.PLUS) || token.equals(LexType.MINU) || token.equals(LexType.NOT)) {
            return true; //unaryOp
        }
        if (token.equals(LexType.LPARENT) || token.equals(LexType.IDENFR) || token.equals(LexType.INTCON) || token.equals(LexType.CHRCON)) {
            return true; //primaryExp and function
        }
        return false;
    }

    public String toSyntaxTree() {
        StringBuilder sb = new StringBuilder();
        for (UnaryOp unaryOp : unaryOps) {
            sb.append(unaryOp.toSyntaxTree());
        }
        if (primaryExp != null) { //case 1
            sb.append(primaryExp.toSyntaxTree());
        } else { //case 2
            sb.append(ident).append(lparent);
            if (funcRParams != null) {
                sb.append(funcRParams.toSyntaxTree());
            }
            if (rparent != null) {
                sb.append(rparent);
            }
        }
        //改造右递归文法，但输出语法树时仍需按照右递归规则输出
        for (int i = 0;i < unaryOps.size() + 1;i++) {
            sb.append('<').append(this.nonTerminalName).append('>').append('\n');
        }
        return sb.toString();
    }
}
