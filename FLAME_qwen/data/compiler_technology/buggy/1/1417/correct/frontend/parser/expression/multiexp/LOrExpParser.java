package frontend.parser.expression.multiexp;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

// LOrExp -> LOrExp '||' LAndExp | LAndExp
public class LOrExpParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;

    public LOrExpParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public LOrExp parseLOrExp() {
        Queue<LOrExp> lOrExpQueue = new LinkedList<>();
        Queue<Token> tokenQueue = new LinkedList<>();
        Queue<LAndExp> lAndExpQueue = new LinkedList<>();

        LAndExpParser lAndExpParser = new LAndExpParser(tokenList);
        LAndExp first = lAndExpParser.parseLAndExp();
        lAndExpQueue.add(first);
        Token token = tokenList.getNextToken();
        // LAndExp -> EqExp && EqExp && ...
        if (token.getType() == TokenType.OR) {
            while (token.getType() == TokenType.OR) {
                tokenQueue.add(token);
                LAndExpParser lAndExpParser2 = new LAndExpParser(tokenList);
                LAndExp lAndExp = lAndExpParser2.parseLAndExp();
                lAndExpQueue.add(lAndExp);
                token = tokenList.getNextToken();
            }
        }
        // LAndExp -> EqExp
        tokenList.fallbackToken(1);

        LAndExp lAndExp = lAndExpQueue.poll();
        ArrayList<Node> firstNodes = new ArrayList<>();
        firstNodes.add(lAndExp);
        LOrExp lOrExp = new LOrExp(lAndExp.getStarttLine(), lAndExp.getEndLine(), "<LOrExp>", firstNodes);
        lOrExpQueue.add(lOrExp);

        while (!lAndExpQueue.isEmpty()){
            LOrExp lOrExp1 = lOrExpQueue.poll();
            Token token1 = tokenQueue.poll();
            LAndExp lAndExp1 = lAndExpQueue.poll();
            ArrayList<Node> curNodes = new ArrayList<>();
            curNodes.add(lOrExp1);
            curNodes.add(token1);
            curNodes.add(lAndExp1);
            LOrExp lOrExp2 = new LOrExp(lOrExp1.getStarttLine(), lAndExp1.getEndLine(), "<LOrExp>", curNodes);
            lOrExpQueue.add(lOrExp2);
        }

        return lOrExpQueue.poll();
    }
}
