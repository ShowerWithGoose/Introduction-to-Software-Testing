package frontend;

import java.util.ArrayList;
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
//                System.out.println(t+" "+m.group(0)+rf.now_line_num);
                Token token = new Token(t,rf.now_line_num,m.group(0));
//                System.out.println(rf.now_column_num);
//                System.out.println(rf.get_now_char());
                this.rf.movehead(m.group(0).length());
//                System.out.println(rf.now_column_num);
//                System.out.println(rf.get_now_char());
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




}


enum TokenType {
        MAINTK(true, "main"),
        CONSTTK(true, "const"),
        INTTK(true, "int"),
        CHARTK(true, "char"),
        BREAKTK(true, "break"),
        CONTINUETK(true, "continue"),
        IFTK(true, "if"),
        ELSETK(true, "else"),
        FORTK(true, "for"),
        GETINTTK(true, "getint"),
        GETCHARTK(true, "getchar"),
        PRINTFTK(true, "printf"),
        RETURNTK(true, "return"),
        VOIDTK(true, "void"),
        IDENFR(false, "[_A-Za-z][_A-Za-z0-9]*"),
        INTCON(false, "[0-9]+"),
        STRCON(false, "(\\\"[^\\\"]*\\\")"),
        CHRCON(false, "('([ !#$%&()*+,\\-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ\\]\\[^_abcdefghijklmnopqrstuvwxyz{|}~])'|'(\\\\[\\\\abtn\"vf'0])')"),
        LEQ(false, "<="),
        LSS(false, "<"),
        GEQ(false, ">="),
        GRE(false, ">"),
        EQL(false, "=="),
        NEQ(false, "!="),
        PLUS(false, "\\+"),
        MINU(false, "-"),
        MULT(false, "\\*"),
        DIV(false, "/"),
        NOT(false, "!"),
        AND(false, "&&"),
        OR(false, "\\|\\|"),
        MOD(false, "%"),
        ASSIGN(false, "="),
        SEMICN(false, ";"),
        COMMA(false, ","),
        LPARENT(false, "\\("),
        RPARENT(false, "\\)"),
        LBRACK(false, "\\["),
        RBRACK(false, "]"),
        LBRACE(false, "\\{"),
        RBRACE(false, "}"),
        ERROR_A(false,"[&|]");
    private TokenType(boolean isGreed, String patternString){
        this.isGreed = isGreed;
        this.patternString = patternString;
        if(this.isGreed){
            this.pattern = Pattern.compile("^"+this.patternString+"(?![_A-Za-z0-9])");
        }else{
            this.pattern = Pattern.compile("^"+this.patternString);
        }
    }

    private boolean isGreed;
    private String patternString;
    private Pattern pattern;

    public Pattern getPattern(){
        return this.pattern;
    }

    @Override
    public String toString(){return this.name();}

}