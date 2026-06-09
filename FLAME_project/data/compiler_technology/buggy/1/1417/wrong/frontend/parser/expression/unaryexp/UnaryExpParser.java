package frontend.parser.expression.unaryexp;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;
import frontend.parser.expression.primaryexp.PrimaryExp;
import frontend.parser.expression.primaryexp.PrimaryExpParser;

import java.util.ArrayList;

// UnaryExp -> PrimaryExp | Ident '(' FuncRParams ')' | UnaryOp UnaryExp
public class UnaryExpParser {
    private TokenList tokenList;
    private ArrayList<Node> nodes;
    public UnaryExpParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public UnaryExp parseUnaryExp() {
        Token first = tokenList.getNextToken();
        Token second = tokenList.getNextToken();
        if (isPrimaryExp(first, second)) {
            tokenList.fallbackToken(2);
            PrimaryExpParser primaryExpParser = new PrimaryExpParser(tokenList);
            PrimaryExp primaryExp = primaryExpParser.parsePrimaryExp();
            this.nodes.add(primaryExp);
        } else if (isIdent(first, second)) {
            tokenList.fallbackToken(2);
            UnaryExpFuncParser unaryExpFuncParser = new UnaryExpFuncParser(tokenList);
            UnaryExpFunc unaryExpFunc = unaryExpFuncParser.parseUnaryExpFunc();
            this.nodes.add(unaryExpFunc);
        } else if (isUnaryOp(first)) {
            tokenList.fallbackToken(2);
            UnaryOpExpParser unaryOpExpParser = new UnaryOpExpParser(tokenList);
            UnaryOpExp unaryOpExp = unaryOpExpParser.parseUnaryOpExp();
            this.nodes.add(unaryOpExp);
        }
        int startLine = nodes.get(0).getStarttLine();
        int endLine = nodes.get(nodes.size() - 1).getEndLine();
        UnaryExp unaryExp = new UnaryExp(startLine, endLine, "<UnaryExp>", nodes);
        return unaryExp;
    }

    // 判断UnaryExpEle的类型
    // PrimaryExp -> '(' Exp ')' | LVal | Number | Character
    public boolean isPrimaryExp(Token first, Token second) {
        // 其中LVal的判定需要与Ident '(' [FuncRParams] ')' 作区别
        if (first.getType() == TokenType.LPARENT
                || (first.getType() == TokenType.IDENFR && second.getType() != TokenType.LPARENT)
                || first.getType() == TokenType.INTCON
                || first.getType() == TokenType.CHRCON) {
            return true;
        }
        return false;
    }

    public boolean isIdent(Token first, Token second) {
        if (first.getType() == TokenType.IDENFR && second.getType() == TokenType.LPARENT) {
            return true;
        }
        return false;
    }

    public boolean isUnaryOp(Token first) {
        if (first.getType() == TokenType.PLUS
                || first.getType() == TokenType.MINU
                || first.getType() == TokenType.NOT) {
            return true;
        }
        return false;
    }
}
