package frontend.lexer;

import frontend.SourceFileLexer;

import java.util.ArrayList;
import java.util.regex.Pattern;

/**
 * @author
 * 词法成分分析器
 */
public class TokenLexer {
    private SourceFileLexer sourceFileLexer;
    private TokenList tokenList;
    private ErrorList errorList;
    private final String lineComment = "//";
    private final String blockCommentSt = "/*";
    private final String blockCommentEd = "*/";

    public TokenLexer(SourceFileLexer sourceFileLexer) {
        this.sourceFileLexer = sourceFileLexer;
        this.tokenList = new TokenList();
        this.errorList = new ErrorList();
        tokenize();
    }

    /**
     * 对源程序进行一遍词法分析，得到单词表
     */
    private void tokenize() {
        while (!this.sourceFileLexer.endOfFile()) {
            // 跳过空白符
            if (skipWhiteSpace()) {
                continue;
            };
            // 判断是否是注释，注释直接跳过
            if (skipComment()) {
                continue;
            }
            // 否则开始匹配 token 的逻辑
            addToken();
        }
    }

    /**
     * 跳过 whitespace
     * @return 是否有跳过 whitespace
     */
    private boolean skipWhiteSpace() {
        return this.sourceFileLexer.skipWhiteSpace();
    }

    /**
     * 若当前要处理的字符是注释则跳过
     * 包括单行 '//' 和多行 '/*'
     * @return 当前要处理的字符是否是注释
     */
    private boolean skipComment() {
        if (lineComment.equals(this.sourceFileLexer.peekSubStr(2))) { // 单行注释
            this.sourceFileLexer.nextLine();
            return true;
        } else if (blockCommentSt.equals(this.sourceFileLexer.peekSubStr(2))) { // 多行注释
            sourceFileLexer.moveForward(this.blockCommentSt.length()); // 先跳过注释头
            while (!this.sourceFileLexer.endOfFile() &&
                    !blockCommentEd.equals(this.sourceFileLexer.peekSubStr(2))) {
                this.sourceFileLexer.moveForward(1);
            } // 一直去找是否到了注释尾
            if (blockCommentEd.equals(this.sourceFileLexer.peekSubStr(2))) { // 如果到了注释尾
                this.sourceFileLexer.moveForward(2);
                return true;
            }
            // TODO：如果读到了文件末尾怎么处理？
        }
        return false;
    }

    /**
     * 匹配 token 的操作
     * 1. 用所有的 TokenType 去尝试匹配 token
     * 2. 调用 tokenList 的方法来加入单词表
     *   2-a. 若匹配失败，则进行错误处理
     * 特殊情况：
     * 1. == 与 =、< 与 <=，> 与 >= 通过 TokenType 里面的顺序来保证
     * TODO：一些特殊情况的补充？
     */
    private void addToken() {
        boolean isPared = false; // 用来记录是否配对成功
        // 用所有的 TokenType 去尝试匹配 token
        for (TokenType tokenType : TokenType.values()) {
            Pattern pattern = tokenType.getPattern();
            String tokenStr = this.sourceFileLexer.hitSubStr(pattern);
            if (tokenStr == null) { // 与该 TokenType 不匹配
                continue;
            } else {
                Token token = new Token(tokenType, sourceFileLexer.getLineNum(), tokenStr);
                this.sourceFileLexer.moveForward(tokenStr.length()); // 光标往前移
                this.tokenList.addToken(token); // 调用 tokenList 的方法来加入单词表
                isPared = true;
                break; // 跳出 for 循环
            }
        }
        // 没有配对成功，进行异常处理
        if (!isPared) {
//            char test = this.sourceFileLexer.peekChar();
//            System.out.println(this.sourceFileLexer.peekChar());
            errorList.addError(new Error(ErrorType.ILLEGALCHAR, sourceFileLexer.getLineNum()));
            this.sourceFileLexer.moveForward(1);
        }
    }

    /**
     * 获取单词表
     * @return 单词表
     */
    public TokenList getTokenList() {
        return tokenList;
    }

    /**
     * 获取错误表
     * @return 错误表
     */
    public ErrorList getErrorList() {
        return errorList;
    }

    /**
     * 判断错误表是否为空
     * @return 错误表
     */
    public boolean ifErrorListEmpty() {
        return errorList.isEmpty();
    }
}
