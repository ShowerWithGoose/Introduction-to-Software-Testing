package frontend.parser.declaration.constant.constinitval;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;
import frontend.parser.expression.ConstExp;
import frontend.parser.expression.ConstExpParser;
import frontend.parser.terminal.StringConst;
import frontend.parser.terminal.StringConstParser;

import java.util.ArrayList;

// ConstInitVal -> ConstExp | '{' [ Const { ',' ConstExp} ] '}' | StringConst
public class ConstInitValParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;

    public ConstInitValParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public ConstInitVal parseConstInitVal() {
        Token token = tokenList.getNextToken();
        // 需要分三种情况进行解析
        if (token.getType() == TokenType.LBRACE) {
            tokenList.fallbackToken(1);
            ConstInitValMultiParser constInitValMultiParser = new ConstInitValMultiParser(tokenList);
            ConstInitValMulti constInitValMulti = constInitValMultiParser.parseConstInitValMulti();
            this.nodes.add(constInitValMulti);
        } else if (token.getType() == TokenType.STRCON) {
            tokenList.fallbackToken(1);
            StringConstParser stringConstParser = new StringConstParser(tokenList);
            StringConst stringConst = stringConstParser.parseStringConst();
            this.nodes.add(stringConst);
        } else {
            tokenList.fallbackToken(1);
            ConstExpParser constExpParser = new ConstExpParser(tokenList);
            ConstExp constExp = constExpParser.parseConstExp();
            this.nodes.add(constExp);
        }
        int startLine = this.nodes.get(0).getStarttLine();
        int endLine = this.nodes.get(nodes.size() - 1).getEndLine();
        ConstInitVal constInitVal = new ConstInitVal(startLine, endLine, "<ConstInitVal>", this.nodes);
        return constInitVal;
    }


}
