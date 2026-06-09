package frontend.Lexer;
import frontend.SrcFileLexer;

import java.util.ArrayList;
import java.util.HashMap;

public class TokenLexer {
    private SrcFileLexer srcFileLexer;
    private ArrayList<Token> tokenList;
    private HashMap<Integer,String> errorMap;
    public TokenLexer(SrcFileLexer srcFileLexer){
        this.srcFileLexer=srcFileLexer;
        tokenList=new ArrayList<>();
        errorMap=new HashMap<>();
    }
    public boolean skipComment() {
        if ("//".equals(this.srcFileLexer.getSubStr(2))) {
            this.srcFileLexer.nextLine();
            return true;
        } else if ("/*".equals(this.srcFileLexer.getSubStr(2))) {
            srcFileLexer.moveForward(2);
            while (!this.srcFileLexer.endOfFile() &&
                    !"*/".equals(this.srcFileLexer.getSubStr(2))) {
                this.srcFileLexer.moveForward(1);
            }
            if ("*/".equals(this.srcFileLexer.getSubStr(2))) {
                this.srcFileLexer.moveForward(2);
                return true;
            }
        }
        return false;
    }
    public void beginTokenLexer(){
        while (!srcFileLexer.endOfFile()){
            srcFileLexer.skipWhiteSpace();
            if(skipComment()){
                continue;
            }
            if(srcFileLexer.getRemainingLine()==null){
                srcFileLexer.nextLine();
                continue;
            }
            //TODO insure that the current  is not blankspace or // /*  */ or null-->""
            //add token to tokenList
            for(TokenType tokenType:TokenType.values()){
                String tokenStr= srcFileLexer.matchRemainingLine(tokenType.getPattern());
                if(tokenStr==null){
                    continue;
                }else if(tokenStr.equals("&")||tokenStr.equals("|")){
                    // TODO : 处理异常
                    this.srcFileLexer.moveForward(tokenStr.length());
                    this.errorMap.put(srcFileLexer.getLineNumber(),"a");
                    break;
                } else {
                    Token token = new Token(tokenType/*srcFileLexer.getLineNumber()*/, tokenStr);
                    this.srcFileLexer.moveForward(tokenStr.length());
                    this.tokenList.add(token);
                    break;
                }
            }
        }
    }
    public ArrayList<Token> getTokenList(){
        return tokenList;
    }
    public HashMap<Integer,String> getErrorMap(){
        return errorMap;
    }
}
