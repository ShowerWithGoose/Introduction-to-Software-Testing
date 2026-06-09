package frontend.parser.expression.primaryexp;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;

import java.util.ArrayList;

// PrimaryExp -> '(' Exp ')' | LVal | Number | Character
public class PrimaryExpParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;
    public PrimaryExpParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public PrimaryExp parsePrimaryExp() {
        Token token = tokenList.getNextToken();
        // '(' Exp ')'
        if (token.getType() == TokenType.LPARENT) {
            tokenList.fallbackToken(1);
            PrimaryExpExpParser primaryExpExpParser = new PrimaryExpExpParser(tokenList);
            PrimaryExpExp primaryExpExp = primaryExpExpParser.parsePrimaryExpExp();
            this.nodes.add(primaryExpExp);
        }
        // LVal
        else if (token.getType() == TokenType.IDENFR) {
            tokenList.fallbackToken(1);
            LValParser lValParser = new LValParser(tokenList);
            LVal lVal = lValParser.parseLVal();
            this.nodes.add(lVal);
        }
        // Number
        else if (token.getType() == TokenType.INTCON) {
            tokenList.fallbackToken(1);
            NumberParser numberParser = new NumberParser(tokenList);
            Number number = numberParser.parseNumber();
            this.nodes.add(number);
        }
        // Character
        else if (token.getType() == TokenType.CHRCON) {
            tokenList.fallbackToken(1);
            CharacterParser characterParser = new CharacterParser(tokenList);
            Character character = characterParser.parseCharacter();
            this.nodes.add(character);
        }
        int startLine = nodes.get(0).getStarttLine();
        int endLine = nodes.get(nodes.size() - 1).getEndLine();
        PrimaryExp primaryExp = new PrimaryExp(startLine, endLine, "<PrimaryExp>", this.nodes);
        return primaryExp;
    }

}
