package frontend.parser.declaration.variable.initval;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;
import frontend.parser.expression.Exp;
import frontend.parser.expression.ExpParser;
import frontend.parser.terminal.StringConst;
import frontend.parser.terminal.StringConstParser;

import java.util.ArrayList;

// InitVal -> Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
public class InitValParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;

    public InitValParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public InitVal parseInitVal() {
        Token token = tokenList.getNextToken();
        // InitVal -> '{' [ Exp { ',' Exp } ] '}'
        if (token.getType() == TokenType.LBRACE) {
            tokenList.fallbackToken(1);
            InitValMultiParser initValMultiParser = new InitValMultiParser(tokenList);
            InitValMulti initValMulti = initValMultiParser.parseInitValMulti();
            this.nodes.add(initValMulti);
        }
        // InitVal -> StringConst
        else if (token.getType() == TokenType.STRCON) {
            tokenList.fallbackToken(1);
            StringConstParser stringConstParser = new StringConstParser(tokenList);
            StringConst stringConst = stringConstParser.parseStringConst();
            this.nodes.add(stringConst);
        }
        // InitVal -> Exp
        else {
            tokenList.fallbackToken(1);
            ExpParser expParser = new ExpParser(tokenList);
            Exp exp = expParser.parseExp();
            this.nodes.add(exp);
        }
        int startLine = this.nodes.get(0).getStarttLine();
        int endLine = this.nodes.get(nodes.size() - 1).getEndLine();
        InitVal initVal = new InitVal(startLine, endLine, "<InitVal>", this.nodes);
        return initVal;
    }
}
