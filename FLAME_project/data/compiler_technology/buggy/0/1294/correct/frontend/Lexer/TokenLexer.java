package frontend.Lexer;

import frontend.Error;
import frontend.FileLexer;
import frontend.MyErrorType;

import java.util.ArrayList;
import java.util.regex.Pattern;

public class TokenLexer {
    private final String lineCommentSign = "//";
    private final String blockCommentSign1 = "/*";
    private final String blockCommentSign2 = "*/";
    private FileLexer fileLexer;
    private TokenResolved tokenResolved;
    private ArrayList<Error> errors;
    private boolean isError = false;

    public TokenLexer(FileLexer fileLexer) {
        this.fileLexer = fileLexer;
        this.tokenResolved = new TokenResolved();
        this.errors = new ArrayList<>();
        doLexer();
    }

    private void doLexer() { //开始词法分析
        while (!fileLexer.endOfFile()) {
            jumpOverBlankSpace();
            if (jumpOverComment() > 0) {
                continue;
            }
            findToken();
        }
    }

    private void jumpOverBlankSpace() {
        fileLexer.jumpOverBlankSpace();
    }

    private int jumpOverComment() { //如果跳过了注释需要返回大于0的整数
        if (fileLexer.getSubstring(2).equals(lineCommentSign)) {
            fileLexer.jumpCurrentLine();
            return 1;
        } else if (fileLexer.getSubstring(2).equals(blockCommentSign1)) {
            fileLexer.move(2);
            while (!fileLexer.endOfFile() &&
                    !fileLexer.getSubstring(2).equals(blockCommentSign2)) {
                fileLexer.move(1);
            }
            //出循环现在位于*/
            if (fileLexer.getSubstring(2).equals(blockCommentSign2)) {
                fileLexer.move(2);
                return 2;
            }
        }
        return 0;
    }

    private void findToken() {
        for (TokenType tokenType : TokenType.values()) {
            Pattern pattern = tokenType.getPattern();
            String tokenValue = fileLexer.matchTheStr(pattern);
            if (tokenValue == null) {
                continue;
            } else {
                //if(tokenValue.equals("main")){
                //    System.out.println("main");
                //}
                Token token = new Token(tokenType, fileLexer.getLineNo(), tokenValue);
                fileLexer.move(tokenValue.length());
                if (tokenType.equals(TokenType.SINGLEAND) || tokenType.equals(TokenType.SINGLEOR)) {
                    Error error = new Error(token.getLineNo(), MyErrorType.a);
                    errors.add(error);
                    this.isError = true;
                } else {
                    tokenResolved.addToken(token);
                }
                break;
            }
        }
    }

    public TokenResolved getTokenResolved() {
        return tokenResolved;
    }

    public boolean getIsError() {
        return isError;
    }

    public String errorsToString() {
        StringBuilder sb = new StringBuilder();
        for (Error error : errors) {
            sb.append(error.toString()).append("\n");
        }
        return sb.toString();
    }
}
