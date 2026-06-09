package frontend.parser.expression.multiexp;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

// RelExp -> AddExp { ( '<' | '<=' | '>' | '>=' ) AddExp }
// RelExp -> AddExp | RelExp ('<' | '<=' | '>' | '>=') AddExp
public class RelExpParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;

    public RelExpParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public RelExp parseRelExp() {
        Queue<AddExp> addExpQueue = new LinkedList<>();
        Queue<Token> tokenQueue = new LinkedList<>();
        Queue<RelExp> relExpQueue = new LinkedList<>();

        AddExpParser addExpParser = new AddExpParser(tokenList);
        AddExp first = addExpParser.parseAddExp();
        addExpQueue.add(first);
        Token token = tokenList.getNextToken();
        // > >= < <=
        while (token.getType() == TokenType.LSS || token.getType() == TokenType.LEQ || token.getType() == TokenType.GRE || token.getType() == TokenType.GEQ) {
            tokenQueue.add(token);
            AddExpParser addExpParser2 = new AddExpParser(tokenList);
            AddExp addExp = addExpParser2.parseAddExp();
            addExpQueue.add(addExp);
            token = tokenList.getNextToken();
        }
        tokenList.fallbackToken(1);

        AddExp addExp = addExpQueue.poll();
        ArrayList<Node> firstNodes = new ArrayList<>();
        firstNodes.add(addExp);
        RelExp relExp = new RelExp(addExp.getStarttLine(), addExp.getEndLine(), "<RelExp>", firstNodes);
        relExpQueue.add(relExp);

        while (!addExpQueue.isEmpty()){
            RelExp relExp1 = relExpQueue.poll();
            Token token1 = tokenQueue.poll();
            AddExp addExp1 = addExpQueue.poll();
            ArrayList<Node> curNodes = new ArrayList<>();
            curNodes.add(relExp1);
            curNodes.add(token1);
            curNodes.add(addExp1);
            RelExp relExp2 = new RelExp(relExp1.getEndLine(), addExp1.getEndLine(), "<RelExp>", curNodes);
            relExpQueue.add(relExp2);
        }

        return relExpQueue.poll();
    }
}
