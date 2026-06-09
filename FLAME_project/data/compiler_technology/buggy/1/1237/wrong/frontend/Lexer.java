package frontend;

import java.util.ArrayList;
import java.util.regex.Pattern;
import error.Error;
import error.ErrorTable;
import error.ErrorType;

public class Lexer {
    private final SrcReader srcReader;
    private final TokenList tokenList;

    public Lexer(SrcReader srcReader) {
        this.srcReader = srcReader;
        this.tokenList = new TokenList();
        tokenize();
    }

    private void tokenize() {
        int lastPosition = -1;  // 用于跟踪文件指针位置
        while (!this.srcReader.isEndOfFile()) {
            int currentPosition = this.srcReader.getCurrentPosition();  // 获取当前文件指针位置

            skipWhiteSpace();
            if (skipComment()) {
                continue;
            }
            addToken();

            if (currentPosition == this.srcReader.getCurrentPosition()) {
                // 如果文件指针没有前进，记录错误并退出
                System.err.println("Potential infinite loop at position " + currentPosition + "--" + srcReader.currentLine());
                break;
            }

            lastPosition = currentPosition;
        }
    }

    private void skipWhiteSpace() {
        this.srcReader.skipWhitespace();
    }

    private boolean skipComment() {
        String lineComment = "//";
        String blockCommentSt = "/*";
        if (lineComment.equals(this.srcReader.peekNextSubstring(2))) {
            this.srcReader.moveToNextLine();
            return true;
        } else if (blockCommentSt.equals(this.srcReader.peekNextSubstring(2))) {
            srcReader.advancePosition(blockCommentSt.length());
            String blockCommentEd = "*/";
            while (!this.srcReader.isEndOfFile() && !blockCommentEd.equals(this.srcReader.peekNextSubstring(2))) {
                this.srcReader.advancePosition(1);
            }
            if (blockCommentEd.equals(this.srcReader.peekNextSubstring(2))) {
                this.srcReader.advancePosition(blockCommentEd.length());
                return true;
            }
        }
        return false;
    }

    private void addToken() {
        String nextTwoChars = this.srcReader.peekNextSubstring(2);  // 预览下两个字符

        // 如果 nextTwoChars 的长度不够，直接返回，避免错误
        if (nextTwoChars.isEmpty()) {
            return; // 文件可能已经结束或者遇到了空行，直接返回
        }

        if (nextTwoChars.length() == 2) {  // 当有至少两个字符时
            // 处理逻辑运算符
            if (nextTwoChars.equals("&&")) {
                this.tokenList.addToken(new Token(TokenType.AND, srcReader.getCurrentLineNumber(), "&&"));
                this.srcReader.advancePosition(2); // 跳过两个字符
                return;
            } else if (nextTwoChars.equals("||")) {
                this.tokenList.addToken(new Token(TokenType.OR, srcReader.getCurrentLineNumber(), "||"));
                this.srcReader.advancePosition(2); // 跳过两个字符
                return;
            }
        }

        // 如果只剩下一个字符，或前两个字符不是逻辑运算符
        String currentChar = nextTwoChars.substring(0, 1); // 获取第一个字符
        if (currentChar.equals("&") || currentChar.equals("|")) {
            handleLogicalOperatorError(currentChar); // 处理单个符号的错误
            return;
        }

        for (TokenType tokenType : TokenType.values()) {
            Pattern pattern = tokenType.getPattern();
            String tokenStr = this.srcReader.matchPattern(pattern);
            if (tokenStr != null) {
                Token token = new Token(tokenType, srcReader.getCurrentLineNumber(), tokenStr);
                this.srcReader.advancePosition(tokenStr.length());
                this.tokenList.addToken(token);
                break;
            }
        }
    }

    private void handleLogicalOperatorError(String operator) {
        int currentLine = srcReader.getCurrentLineNumber();

        if (operator.equals("&") || operator.equals("|")) {
            // 记录行号和错误类型 "a"
            Error error = new Error(currentLine, ErrorType.ILLEGAL_CHAR);  // 使用 ErrorType.INVALID_SYMBOL 表示非法符号
            ErrorTable.addError(error);
        }

        this.srcReader.advancePosition(1); // 移动位置以避免无限循环
    }

    public TokenList getTokenList() {
        return this.tokenList;
    }
}
