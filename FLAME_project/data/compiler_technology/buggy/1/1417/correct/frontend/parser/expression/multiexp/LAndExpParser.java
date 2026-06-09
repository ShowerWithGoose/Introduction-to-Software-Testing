package frontend.parser.expression.multiexp;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

// LAndExp -> LAndExp '&&' EqExp | EqExp
// LAndExp -> EqExp { '&&' EqExp }
public class LAndExpParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;

    public LAndExpParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public LAndExp parseLAndExp() {
        Queue<LAndExp> lAndExpQueue = new LinkedList<>();
        Queue<Token> tokenQueue = new LinkedList<>();
        Queue<EqExp> eqExpQueue = new LinkedList<>();

        EqExpParser expParser = new EqExpParser(tokenList);
        EqExp first = expParser.parseEqExp();
        eqExpQueue.add(first);
        Token token = tokenList.getNextToken();
        // LAndExp -> EqExp && EqExp && ...
        if (token.getType() == TokenType.AND) {
            while (token.getType() == TokenType.AND) {
                tokenQueue.add(token);
                EqExpParser expParser2 = new EqExpParser(tokenList);
                EqExp eqExp = expParser2.parseEqExp();
                eqExpQueue.add(eqExp);
                token = tokenList.getNextToken();
            }

        }
        tokenList.fallbackToken(1);

        EqExp eqExp = eqExpQueue.poll();
        ArrayList<Node> firstNodes = new ArrayList<>();
        firstNodes.add(eqExp);
        LAndExp lAndExp = new LAndExp(eqExp.getStarttLine(), eqExp.getEndLine(), "<LAndExp>", firstNodes);
        lAndExpQueue.add(lAndExp);

        while (!eqExpQueue.isEmpty()) {
            LAndExp lAndExp1 = lAndExpQueue.poll();
            Token token1 = tokenQueue.poll();
            EqExp eqExp1 = eqExpQueue.poll();
            ArrayList<Node> curNodes = new ArrayList<>();
            curNodes.add(lAndExp1);
            curNodes.add(token1);
            curNodes.add(eqExp1);
            LAndExp lAndExp2 = new LAndExp(lAndExp1.getStarttLine(), eqExp1.getEndLine(), "<LAndExp>", curNodes);
            lAndExpQueue.add(lAndExp2);
        }
        return lAndExpQueue.poll();
    }
}
