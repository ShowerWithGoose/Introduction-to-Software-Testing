package frontend;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class TokenLexer {
    private SourceLexer sourceLexer;
    private TokenList tokenList;
    private TokenList errorList;

    public TokenLexer(SourceLexer sourceLexer) {
        this.sourceLexer = sourceLexer;
        this.tokenList = new TokenList();
        this.errorList = new TokenList();
        Lexing();
    }

    private void Lexing() {
        while (!this.sourceLexer.fileIsEnd()) {
            sourceLexer.skipWhiteSpace();
            if (skipNote()) {
                continue;
            }
            addToken();
        }
    }

    private boolean skipNote() {
        String note1 = "//";
        String note2_st = "/*";
        String note2_ed = "*/";
        if (note1.equals(this.sourceLexer.getSubString(2))) {
            this.sourceLexer.next();
            return true;
        } else if (note2_st.equals(this.sourceLexer.getSubString(2))) {
            sourceLexer.move();
            sourceLexer.move();
            while (!this.sourceLexer.fileIsEnd() &&
                    !note2_ed.equals(this.sourceLexer.getSubString(2))) {
                this.sourceLexer.move();
            }
            if (note2_ed.equals(this.sourceLexer.getSubString(2))) {
                this.sourceLexer.move();
                this.sourceLexer.move();
                return true;
            }
        }
        return false;
    }

    private void addToken() {
        Matcher matcher;
        for (LexType lexType : LexType.values()) {
            Pattern pattern = lexType.getPattern();
            String tokenStr = this.sourceLexer.matchSubStr(pattern);
            if (tokenStr != null) {
                Token token = new Token(lexType, sourceLexer.getLineNum(), tokenStr);
                if (token.getType() != LexType.a) {
                    this.tokenList.addToken(token);
                } else {
                    this.errorList.addToken(token);
                }
                for (int i = 0;i < tokenStr.length();i++) {
                    this.sourceLexer.move();
                }
                //System.out.println("frontend.Token " + token.getContent() + " " + token.getType());
                break;
            }
            if (sourceLexer.fileIsEnd()) {
                break;
            }
        }
    }

    public TokenList getTokenList() {
        return tokenList;
    }

    public TokenList getErrorList() {
        return errorList;
    }
}
