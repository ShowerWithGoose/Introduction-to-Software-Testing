package frontend.lexer;

import java.util.ArrayList;

public class TokenList {
    private ArrayList<Token> tokens;
    private ArrayList<Integer> errors;//本题只有一个error，但是防备一下，准备多个,Integer是行号
    private Boolean isError;

    public TokenList() {
        this.tokens = new ArrayList<>();
        this.errors = new ArrayList<>();
        this.isError = false;
    }
    public void addToken(Token token){
        tokens.add(token);
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Token token : tokens) {
            sb.append(token.getType()).append(" ").append(token.getContent()).append("\n");
        }
        if (!sb.isEmpty() && sb.charAt(sb.length() - 1) == '\n') {
            sb.deleteCharAt(sb.length() - 1); // 删除最后一个字符(换行)
            //其实没啥必要
        }
        return sb.toString();
    }

    public Boolean getIsError() {
        return isError;
    }

    public ArrayList<Integer> getErrors() {
        return this.errors;
    }

    public void addError(int errorLine) {
        isError = true;
        errors.add(errorLine);
    }
}
