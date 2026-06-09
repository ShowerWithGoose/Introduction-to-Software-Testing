package frontend.parser.expression.multiexp;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

// EqExp -> RelExp | EqExp ( '==' | '!=' ) RelExp
public class EqExpParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;

    public EqExpParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public EqExp parseEqExp() {
        Queue<EqExp> eqExpQueue = new LinkedList<>();
        Queue<Token> tokenQueue = new LinkedList<>();
        Queue<RelExp> relExpQueue = new LinkedList<>();

        RelExpParser relExpParser = new RelExpParser(tokenList);
        RelExp first = relExpParser.parseRelExp();
        relExpQueue.add(first);
        Token token = tokenList.getNextToken();
        while (token.getType() == TokenType.EQL || token.getType() == TokenType.NEQ) {
            tokenQueue.add(token);
            RelExpParser relExpParser2 = new RelExpParser(tokenList);
            RelExp relExp = relExpParser2.parseRelExp();
            relExpQueue.add(relExp);
            token = tokenList.getNextToken();
        }
        tokenList.fallbackToken(1);

        RelExp relExp = relExpQueue.poll();
        ArrayList<Node> firstNodes = new ArrayList<>();
        firstNodes.add(relExp);
        EqExp eqExp = new EqExp(relExp.getStarttLine(), relExp.getEndLine(), "<EqExp>", firstNodes);
        eqExpQueue.add(eqExp);

        while (!relExpQueue.isEmpty()) {
            EqExp eqExp1 = eqExpQueue.poll();
            Token token1 = tokenQueue.poll();
            RelExp relExp1 = relExpQueue.poll();
            ArrayList<Node> curNodes = new ArrayList<>();
            curNodes.add(eqExp1);
            curNodes.add(token1);
            curNodes.add(relExp1);
            EqExp eqExp2 = new EqExp(eqExp1.getStarttLine(), relExp1.getEndLine(), "<EqExp>", curNodes);
            eqExpQueue.add(eqExp2);
        }

        return eqExpQueue.poll();
    }
}
