package frontend.lexer;

import middle.error.Error;
import middle.error.ErrorTable;

import java.util.ArrayList;

public class TokenList {
    private ArrayList<Token> tokens;
    private ArrayList<Integer> errors;//本题只有一个error，但是防备一下，准备多个,Integer是行号
    //no need
    private Boolean isError;//no need
    //这里只储存& && 和| || 的a类错误
    private int location;//指的是当前语义分析即将解读的下一个字符，比如初始为0，我要解读第0个
    //我都用数组了，遍历两遍，想看哪个位置看哪个，不需要读字符，返字符，

    public TokenList() {
        this.tokens = new ArrayList<>();
        this.errors = new ArrayList<>();
        this.isError = false;
        this.location = 0;
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

    public Boolean hasNext() {
        return location < tokens.size();
    }

    public Token getNextToken() {
        return tokens.get(location++);
    }

    public Token seeAfterToken(int num){
        int location1 = this.location + num;
        if (location1 < 0 || location1 >= tokens.size()){
            return new Token(TokenType.END,0,null);
        }
        return tokens.get(location1);
    }

    public void locationSubOne() {
        this.location--;
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

        Error error = new Error(errorLine,"a");
        ErrorTable.addError(error);
    }

    public void resetLocation(){
        this.location = 0;//无用，以防万一进行parse的时候不在初始位置
    }
}
