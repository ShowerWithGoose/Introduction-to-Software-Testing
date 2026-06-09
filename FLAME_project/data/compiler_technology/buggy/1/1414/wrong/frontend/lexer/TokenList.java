package frontend.lexer;

import error.ErrorType;
import error.Mistake;
import frontend.Config;
import utils.OutputTool;
import utils.Panic;

import java.io.IOException;
import java.util.Arrays;
import java.util.List;

public class TokenList {
    private final List<Token> tokens;
    private int cur;
    public static Token preToken = null;

    public TokenList(List<Token> tokens) {
        this.tokens = tokens;
        cur = 0;
    }

    public int getCur() {
        return cur;
    }

    public void setCur(int cur) {
        this.cur = cur;
        preToken = tokens.get(cur - 1);
    }

    public List<Token> getTokens() {
        return tokens;
    }

    public void reset() {
        this.cur = 0;
    }

    public Token pop() {
        cur++;
        if (Config.emitSyntaxTree) {
            OutputTool.writeToFile(Config.syntaxTreeWriter, tokens.get(cur - 1).toString() + '\n');
        }
        preToken = tokens.get(cur - 1);
        return tokens.get(cur - 1);
    }

    public Token top() {
        return tokens.get(cur);
    }

    public Token top(int i) {
        assert(cur + i >= 0 && cur + i < tokens.size());
        return tokens.get(cur + i);
    }

    public boolean hasNext() {
        return cur < tokens.size();
    }

    public boolean check(TokenType... type) {
        for (TokenType t : type) {
            if (tokens.get(cur).getType().equals(t)) {
                return true;
            }
        }
        return false;
    }

    public boolean tryNext(TokenType... type) {
        for (TokenType t : type) {
            if (tokens.get(cur).getType().equals(t)) {
                cur++;
                preToken = tokens.get(cur - 1);
                if (Config.emitSyntaxTree) {
                    OutputTool.writeToFile(Config.syntaxTreeWriter, tokens.get(cur - 1).toString() + '\n');
                }
                return true;
            }
        }
        return false;
    }

    public void popAndCheck(TokenType... type) {
        for (TokenType t : type) {
            if (tokens.get(cur).getType().equals(t)) {
                cur++;
                preToken = tokens.get(cur - 1);
                if (Config.emitSyntaxTree) {
                    OutputTool.writeToFile(Config.syntaxTreeWriter, tokens.get(cur - 1).toString() + '\n');
                }
                return;
            }
        }
        if (type.length == 1 && Config.emitError && preToken != null) {
            if (type[0].equals(TokenType.SEMICN)) {
                OutputTool.mistakeList.add(new Mistake(ErrorType.i, preToken.getLine()));
            } else if (type[0].equals(TokenType.RPARENT)) {
                OutputTool.mistakeList.add(new Mistake(ErrorType.j, preToken.getLine()));
            } else if (type[0].equals(TokenType.RBRACK)) {
                OutputTool.mistakeList.add(new Mistake(ErrorType.k, preToken.getLine()));
            }
            else {
                Panic.panic("Expected token: " + Arrays.toString(type) +
                        " but found: " + tokens.get(cur).getType());
            }
        } else {
            Panic.panic("Expected token: " + Arrays.toString(type) +
                    " but found: " + tokens.get(cur).getType());
        }
    }
}
