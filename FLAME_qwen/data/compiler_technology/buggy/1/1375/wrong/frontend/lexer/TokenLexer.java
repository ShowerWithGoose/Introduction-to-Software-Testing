package frontend.lexer;

import frontend.readfile;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class TokenLexer {
    public readfile rf;
    public ArrayList<Token> tokens;
    public ArrayList<Token> error_tokens;
    public TokenLexer(readfile rf) {
        this.rf = rf;
        tokens = new ArrayList<Token>();
        error_tokens = new ArrayList<Token>();
        tokenize();
    }
    public void tokenize(){
        while(this.rf.if_end()!=1) {
            this.rf.skipspace();
            if(skipComment()){
                continue;
            }
            addToken();
        }

    }
    public boolean skipComment(){
        if("//".equals(this.rf.get_now_len_str(2))){
            this.rf.nextline();
            return true;
        }
        else if("/*".equals(this.rf.get_now_len_str(2))){
            this.rf.movehead(2);
            while(this.rf.if_end()!=1 && !"*/".equals(this.rf.get_now_len_str(2))){
                this.rf.movehead(1);
            }
            if("*/".equals(this.rf.get_now_len_str(2))){
                this.rf.movehead(2);
                return true;
            }
        }
        return false;
    }
    public void addToken(){
        for(TokenType t : TokenType.values()){
            Pattern p = t.getPattern();
            String leftline = this.rf.getleftline();
            //System.out.println(leftline);
            Matcher m = p.matcher(leftline);
            if(!m.find()){
                continue;
            }
            else {
                Token token = new Token(t,rf.now_line_num,m.group(0));
                if(t.equals(TokenType.ERROR_A)) {
                    Token token2 = new Token(TokenType.AND,rf.now_line_num,m.group(0));
                    this.tokens.add(token2);
                }
                this.rf.movehead(m.group(0).length());
                if(t.equals(TokenType.ERROR_A)) {
                    this.error_tokens.add(token);
                    break;
                }
                else {
                    this.tokens.add(token);
                    break;
                }
            }
        }
    }
    public void sort_error_tokens() {
        Collections.sort(error_tokens, new Comparator<Token>() {
            @Override
            public int compare(Token t1, Token t2) {
                return Integer.compare(t1.linenum, t2.linenum);
            }
        });
    }





}


