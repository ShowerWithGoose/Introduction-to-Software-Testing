package frontend.parser.expression.multiexp;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

// 先判断是不是MulExp，如果是的话就不会一直左递归
// AddExp -> MulExp | AddExp ( '+' | '-' ) MulExp
// AddExp -> MulExp { ('+'|'-') MulExp}
public class AddExpParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;

    public AddExpParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public AddExp parseAddExp() {
        Queue<AddExp> addExpQueue = new LinkedList<>();
        Queue<Token> tokenQueue = new LinkedList<>();
        Queue<MulExp> mulExpQueue = new LinkedList<>();

        MulExpParser mulExpParser = new MulExpParser(this.tokenList);
        MulExp first = mulExpParser.parseMulExp();
        mulExpQueue.add(first);
        Token token = tokenList.getNextToken();
        while (token.getType() == TokenType.PLUS || token.getType() == TokenType.MINU) {
            tokenQueue.add(token);
            MulExpParser mulExpParser2 = new MulExpParser(tokenList);
            MulExp mulExp = mulExpParser2.parseMulExp();
            mulExpQueue.add(mulExp);
            token = tokenList.getNextToken();
        }
        tokenList.fallbackToken(1);

        // 我所得到的所有mulExp中的第一个,其自身就是一个AddExp
        MulExp mulExp = mulExpQueue.poll();
        ArrayList<Node> firstNodes = new ArrayList<>();
        firstNodes.add(mulExp);
        AddExp addExp = new AddExp(mulExp.getStarttLine(), mulExp.getEndLine(), "<AddExp>", firstNodes);
        addExpQueue.add(addExp);

        while (!mulExpQueue.isEmpty()) {
            AddExp addExp1 = addExpQueue.poll();
            Token token1 = tokenQueue.poll();
            MulExp mulExp1 = mulExpQueue.poll();
            ArrayList<Node> curNodes = new ArrayList<>();
            curNodes.add(addExp1);
            curNodes.add(token1);
            curNodes.add(mulExp1);
            AddExp addExp2 = new AddExp(addExp1.getStarttLine(), mulExp1.getEndLine(), "<AddExp>", curNodes);
            addExpQueue.add(addExp2);
        }
        return addExpQueue.poll();
    }
}
