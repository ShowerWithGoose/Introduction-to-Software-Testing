package frontend.lexer;

import frontend.SourceFileLexer;
import frontend.error.Error;
import frontend.error.ErrorSet;
import frontend.error.ErrorType;

import java.util.regex.Pattern;

/**
 * 词法分析器（token分析）
 * 调用源文件词法分析器获取单词
 * 进行匹配与错误处理
 */
public class MyLexer {
    private SourceFileLexer sourceFileLexer;
    private TokenList tokenList;
    
    private final String lineComment = "//";
    private final String blockCommentStart = "/*";
    private final String blockCommentEnd = "*/";

    public MyLexer(final SourceFileLexer sourceFileLexer) {
        /* initialize */
        this.sourceFileLexer = sourceFileLexer;
        this.tokenList = new TokenList();
        /* run lexer */
        runMyLexer();
    }
    private void runMyLexer() {
        while (!sourceFileLexer.endOfFile()) {
            sourceFileLexer.skipWhitespace();
            if (skipComment()) {
                continue;
            }
            addToken();
        }
    }

    private boolean skipComment() {
        if (lineComment.equals(sourceFileLexer.getSubstr(2))) {
            sourceFileLexer.nextLine();
            return true;
        } else if (blockCommentStart.equals(sourceFileLexer.getSubstr(2))) {
            sourceFileLexer.move(blockCommentStart.length());
            while (!sourceFileLexer.endOfFile() && !blockCommentEnd.equals(sourceFileLexer.getSubstr(2))) {
                sourceFileLexer.move(1);
            }
            if (blockCommentEnd.equals(sourceFileLexer.getSubstr(2))) {
                sourceFileLexer.move(2);
                return true;
            }
        }
        return false;
    }

    private void addToken() {
        for (TokenType tokenType : TokenType.values()) {
            Pattern pattern = tokenType.getPattern();
            String tokenStr = sourceFileLexer.tryRestSubstr(pattern);
            if (tokenStr == null) {
                continue;
            } else {
                Token token = new Token(tokenType, sourceFileLexer.currentLineNum(), tokenStr);
                sourceFileLexer.move(tokenStr.length());
//                System.out.println(token.getTokenType() + " " + token.getContent());
                if (token.getTokenType() == TokenType.ERRORAND || token.getTokenType() == TokenType.ERROROR) {
                    ErrorSet.getInstance().addError(new Error(ErrorType.IEALGAL_CHAR, token.getLine()));
                }else {
                    tokenList.addToken(token);
                }
                break;
            }
        }
    }

    public TokenList getTokenList() {
        return tokenList;
    }
}
