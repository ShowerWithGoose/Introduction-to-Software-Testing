package frontend;

import treeNode.*;
import java.util.List;
import java.io.BufferedWriter;
import java.io.IOException;

import error.Error;
import error.ErrorType;

public class Parser {

    public List<Token> tokens;
    public int currentTokenIndex;

    public Parser(List<Token> tokenList, BufferedWriter writer) throws IOException {
        this.tokens = tokenList;
        this.currentTokenIndex = 0;
        parseCompUnit(writer);
    }

    public Token getCurrentToken() {
        return (currentTokenIndex < tokens.size()) ? tokens.get(currentTokenIndex) : null;
    }

    public void nextToken() {
        if (currentTokenIndex < tokens.size()) {
            currentTokenIndex++;
        }
    }

    public boolean currentLineHasToken(LexType symbol) {
        int line = tokens.get(currentTokenIndex).lineNumber;
        int originalIndex = currentTokenIndex;
        while (currentTokenIndex < tokens.size() && tokens.get(currentTokenIndex).lineNumber == line) {
            if (tokens.get(currentTokenIndex).type == symbol) {
                currentTokenIndex = originalIndex; // 恢复 index，不影响解析流程
                return true;
            }
            currentTokenIndex++;
        }
        currentTokenIndex = originalIndex; // 恢复 index，不影响解析流程
        return false;
    }

    public boolean match(LexType expectedToken) {
        if (expectedToken == this.getCurrentToken().type) {
            nextToken();
            return true;
        }else {
            return false;
        }
    }
    
    public void reportError(Token token, ErrorType errorType){
        Lexer.errorList.add(new Error(token.lineNumber,errorType));
    }

    // 解析编译单元
    public CompUnit parseCompUnit(BufferedWriter writer) throws IOException{
        return new CompUnit().parse(this,writer);
    }

    public Parser() {}
}
