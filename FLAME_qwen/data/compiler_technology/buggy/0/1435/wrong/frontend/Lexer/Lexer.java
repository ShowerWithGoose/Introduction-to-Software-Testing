package frontend.Lexer;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;

public class Lexer {
    private boolean isComment = false;
    private int lineNum;
    private TokenList tokenList;
    private ArrayList<String> errorList;
    private int pos;
    private String line;

    public Lexer(String line){
        TokenType tokenType = new TokenType();
//        this.tokenTypeMap = tokenType.getTokenMap();
        this.tokenList = new TokenList();
        this.errorList = new ArrayList<>();
        this.pos = 0;
        this.lineNum = 1;
        this.line =  line;
    }

    public boolean isWord(char ch){
        return Character.isLetter(ch) || ch == '_';
    }

    public void doLexer(){
        while(pos < line.length()){
            char ch = line.charAt(pos);
//            System.out.println(ch);

            //处理注释
            if(ch == '/' && pos + 1 <line.length()){
                char nextch = line.charAt(pos + 1);
                if(nextch == '/'){
                    pos++;
                    pos++;
                    while(pos < line.length() && line.charAt(pos) != '\n'){
                        pos++;
                    }

                    if(pos < line.length() && line.charAt(pos) == '\n'){
                        pos++;
                        lineNum++;
                    }
                }
                else if(nextch == '*'){
                    pos++;
                    pos++;
                    while(pos < line.length()){
                        if(line.charAt(pos) == '\n'){
                            lineNum++;
                        }

                        if(line.charAt(pos) != '*' && pos + 1 < line.length() && line.charAt(pos + 1) == '/'){
                            pos++;
                            pos++;
                            break;
                        }

                        pos++;
                    }
                }else{
                    Token token = new Token(TokenType.tokenMap.get("/"), "/", lineNum);
                    tokenList.addToken(token);
                    pos++;
                }
            }

            if(Character.isDigit(ch)){
                StringBuilder sb = new StringBuilder();
                while(pos < line.length() && Character.isDigit(line.charAt(pos))){
                    sb.append(line.charAt(pos));
                    pos++;
                }
                Token token = new Token(TokenType.tokenMap.get("int const"), sb.toString(), lineNum);
                tokenList.addToken(token);

                System.out.println("digit");
            }
            else if(ch == '\''){
                StringBuilder sb = new StringBuilder();
                sb.append(ch);
                pos++;

                while(pos < line.length() && line.charAt(pos) != '\''){
                    if(line.charAt(pos) == '\\'){
                        sb.append(line.charAt(pos));
                        pos++;
                        sb.append(line.charAt(pos));
                    }else{
                        sb.append(line.charAt(pos));
                    }
                    pos++;
                }

                if(pos < line.length() && line.charAt(pos) == '\''){
                    sb.append(line.charAt(pos));
                    pos++;
                }
                Token token = new Token(TokenType.tokenMap.get("char const"), sb.toString(), lineNum);
                tokenList.addToken(token);
            }
            else if(ch == '\"'){
                StringBuilder sb = new StringBuilder();
                sb.append(ch);
                pos++;

                while(pos < line.length() && line.charAt(pos) != '\"'){
                    if(line.charAt(pos) == '\\'){
                        sb.append(line.charAt(pos));
                        pos++;
                        sb.append(line.charAt(pos));
                    }else{
                        sb.append(line.charAt(pos));
                    }
                    pos++;
                }
                if(pos < line.length() && line.charAt(pos) == '\"'){
                    sb.append(line.charAt(pos));
                    pos++;
                }
                Token token = new Token(TokenType.tokenMap.get("string const"), sb.toString(), lineNum);
                tokenList.addToken(token);
            }
            else if(isWord(ch)){
                StringBuilder sb = new StringBuilder();
                while(pos < line.length() && isWord(line.charAt(pos))){
                    sb.append(line.charAt(pos));
                    pos++;
                }

                if(TokenType.keyWord.containsKey(sb.toString())){
                    Token token = new Token(TokenType.tokenMap.get(sb.toString()), sb.toString(), lineNum);
                    tokenList.addToken(token);
                }
                else{
                    Token token = new Token(TokenType.tokenMap.get("ident"), sb.toString(), lineNum);
                    tokenList.addToken(token);
                }
//                System.out.println("word");
            }
            else if(ch == ' ' || ch == '\t' || ch == '\r'){
                pos++;
            }
            else if(ch == '\n') {
                lineNum++;
                pos++;
            }
            else{
                if((ch == '<' || ch == '>' || ch == '=' || ch == '!') && pos + 1 < line.length() && line.charAt(pos + 1) == '='){
                    char nextch = line.charAt(pos + 1);
                    if(nextch == '='){
                        pos++;
                        StringBuilder sb = new StringBuilder();
                        sb.append(ch);
                        sb.append('=');
                        pos++;
                        Token token = new Token(TokenType.tokenMap.get(sb.toString()), sb.toString(), lineNum);
                        tokenList.addToken(token);
                    }
                }
                else if( ch == '|' ){
                    if(pos + 1 < line.length() && line.charAt(pos + 1) == '|'){
                        pos++;
                        pos++;
                        Token token = new Token(TokenType.tokenMap.get("||"), "||", lineNum);
                        tokenList.addToken(token);
                    }else{
                        pos++;
                        errorList.add((lineNum) + " " + "a");
                    }
                }
                else if( ch == '&' ){
                    if(pos + 1 < line.length() && line.charAt(pos + 1) == '&'){
                        pos++;
                        pos++;
                        Token token = new Token(TokenType.tokenMap.get("&&"), "&&", lineNum);
                        tokenList.addToken(token);
                    }else{
                        pos++;
                        errorList.add((lineNum) + " " + "a");
                    }
                }
                else{
                    StringBuilder sb = new StringBuilder();
                    sb.append(ch);
                    pos++;
                    Token token = new Token(TokenType.tokenMap.get(sb.toString()), sb.toString(), lineNum);
                    tokenList.addToken(token);
                }
            }
        }
//        System.out.println(tokenList.getTokenList().get(0).getValue());
//        System.out.println(errorList.size());
    }

    public TokenList getTokenList(){
        return this.tokenList;
    }

    public ArrayList<String> getErrorList(){
        return this.errorList;
    }
}
