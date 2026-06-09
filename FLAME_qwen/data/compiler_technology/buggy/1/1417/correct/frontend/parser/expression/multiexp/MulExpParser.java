package frontend.parser.expression.multiexp;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;
import frontend.parser.expression.unaryexp.UnaryExp;
import frontend.parser.expression.unaryexp.UnaryExpParser;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

// MulExp -> UnaryExp { ('*'|'/'|'%') UnaryExp }
public class MulExpParser {
    private TokenList tokenList;
    // MulExp就是一系列的UnaryExp进行的运算，所以first一定是UnaryExp
    private ArrayList<Node> nodes;

    public MulExpParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public MulExp parseMulExp(){
        Queue<MulExp> mulExpQueue = new LinkedList<>();
        Queue<Token> tokenQueue = new LinkedList<>();
        Queue<UnaryExp> unaryExpQueue = new LinkedList<>();

        UnaryExpParser unaryExpParser = new UnaryExpParser(tokenList);
        UnaryExp first = unaryExpParser.parseUnaryExp();
        unaryExpQueue.add(first);
        Token token = tokenList.getNextToken();
        while (token != null){
            if(token.getType() == TokenType.MULT || token.getType() == TokenType.DIV || token.getType() == TokenType.MOD){
                tokenQueue.add(token);
                UnaryExpParser unaryExpParser2 = new UnaryExpParser(tokenList);
                UnaryExp unaryExp = unaryExpParser2.parseUnaryExp();
                unaryExpQueue.add(unaryExp);
                token = tokenList.getNextToken();
            }else {
                break;
            }
        }
        tokenList.fallbackToken(1);

        UnaryExp unaryExp = unaryExpQueue.poll();
        ArrayList<Node> firstNodes = new ArrayList<>();
        firstNodes.add(unaryExp);
        MulExp mulExp = new MulExp(unaryExp.getStarttLine(), unaryExp.getEndLine(), "<MulExp>", firstNodes);
        mulExpQueue.add(mulExp);

        while (!unaryExpQueue.isEmpty()){
            MulExp mulExp1 = mulExpQueue.poll();
            Token token1 = tokenQueue.poll();
            UnaryExp unaryExp1 = unaryExpQueue.poll();
            ArrayList<Node> curNodes = new ArrayList<>();
            curNodes.add(mulExp1);
            curNodes.add(token1);
            curNodes.add(unaryExp1);
            MulExp mulExp2 = new MulExp(mulExp1.getStarttLine(), unaryExp1.getEndLine(), "<MulExp>", curNodes);
            mulExpQueue.add(mulExp2);
        }

        return mulExpQueue.poll();
    }

}
