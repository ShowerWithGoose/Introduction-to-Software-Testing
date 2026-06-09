package frontend.parser;

import exeptions.Error;
import exeptions.ErrorList;
import exeptions.ErrorType;
import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;

public class TokenHandler {
    private final Token endToken;
    private final TokenList tokenList;
    private final ErrorList errorList = new ErrorList();
    private int pointer = 0;
    public TokenHandler(TokenList tokenList) {
        this.tokenList = tokenList;
        this.endToken = new Token("", TokenType.END, tokenList.getLast().getLine());
        // 结尾Token
    }
    public TokenList getTokenList() {
        return this.tokenList;
    }
    public Token getNext() {
        if (!reachEnd()) {
            return this.tokenList.get(pointer);
        } else {
            return endToken;
        }
    }

    public Token getByOffset(int step) {
        return this.tokenList.get(Math.min(Math.max(pointer + step, 0), tokenList.getSize()));
    }
    public Token getNextAndMove() {
        if (!reachEnd()) {
            return this.tokenList.get(pointer++);
        } else {
            return endToken;
        }
    }
    public int getPointer() {
        return this.pointer;
    }
    public void setPointer(int pointer) {
        this.pointer = pointer;
    }
    public boolean reachEnd() {
        return this.pointer >= tokenList.getSize();
    }

    public void addError(ErrorType errorType) {
        errorList.add(new Error(errorType, getByOffset(-1).getLine()));
    }
    public ErrorList getErrorList() {
        return errorList;
    }
}
