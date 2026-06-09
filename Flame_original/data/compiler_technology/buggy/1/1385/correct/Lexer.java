import token.Errorz;
import token.Token;
import java.util.ArrayList;
import java.util.HashMap;

public class Lexer {
    private ArrayList<Token> tokens;
    private ArrayList<Errorz> errors;
    
    Lexer() {
        tokens = new ArrayList<>();
        errors = new ArrayList<>();
    }
    
    public ArrayList<Errorz> getErrors() {
        return errors;
    }
    
    public ArrayList<Token> getTokens(ArrayList<String> lines) {
        for(int i = 0;i<lines.size();i++){
            String line = lines.get(i);
            int curPos = 0;
            while(curPos < line.length()) {
                while(curPos < line.length() &&(line.charAt(curPos) == ' ' || line.charAt(curPos)=='\t')) {
                    curPos++;
                }
                if (curPos>=line.length()) {
                    break;
                }
                String word = "";
                char c = line.charAt(curPos);
                if (Character.isDigit(c)) {
                    word+=c;
                    curPos++;
                    while (curPos < line.length() && Character.isDigit(line.charAt(curPos))) {
                        word+=line.charAt(curPos);
                        curPos++;
                    }
                    Token token = new Token(word,"INTCON",i+1);
                    tokens.add(token);
                }
                else if (Character.isLetter(c) || c == '_') {
                    word+=c;
                    curPos++;
                    while (curPos < line.length() && (Character.isLetterOrDigit(line.charAt(curPos))||line.charAt(curPos)=='_')){
                        word+=line.charAt(curPos);
                        curPos++;
                    }
                    Token token = new Token(word,"IDENFR",i+1);
                    tokens.add(token);
                }
                else if (c=='\''){
                    word+=c;
                    curPos++;
                    if (line.charAt(curPos)=='\\' && (curPos+1)<line.length() && line.charAt(curPos+1)=='\''){
                        word+="\\\'";
                        curPos+=2;
                    }
                    while(line.charAt(curPos)!='\''){
                        word+=line.charAt(curPos);
                        curPos++;
                    }
                    word+='\'';
                    curPos++;
                    Token token = new Token(word,"CHRCON",i+1);
                    tokens.add(token);
                }
                else if (c=='\"'){
                    word+=c;
                    curPos++;
                    while(line.charAt(curPos)!='\"'){
                        word+=line.charAt(curPos);
                        curPos++;
                    }
                    word+='\"';
                    curPos++;
                    Token token = new Token(word,"STRCON",i+1);
                    tokens.add(token);
                }
                else if(c=='|'){
                    Token token = new Token("||","OR",i+1);
                    if (curPos+1<line.length()&&line.charAt(curPos+1)=='|'){
                        curPos+=2;
                    }
                    else {
                        token.setError("a");
                        errors.add(new Errorz(i+1,"a"));
                        curPos+=1;
                    }
                    tokens.add(token);
                }
                else if(c=='&'){
                    Token token = new Token("&&","AND",i+1);
                    if (curPos+1<line.length()&&line.charAt(curPos+1)=='&'){
                        curPos+=2;
                    }
                    else {
                        token.setError("a");
                        errors.add(new Errorz(i+1,"a"));
                        curPos+=1;
                    }
                    tokens.add(token);
                }
                else if (c=='/'){
                    if (curPos+1<line.length()&&line.charAt(curPos+1)=='/'){
                        curPos=line.length();
                    }
                    else if (curPos+1<line.length()&&line.charAt(curPos+1)=='*'){
                        curPos+=2;
                        if (curPos>=line.length()){
                            curPos=0;
                            i++;
                            line = lines.get(i);
                        }
                        while (!(curPos<line.length() && line.charAt(curPos)=='*' && curPos+1 < line.length() && line.charAt(curPos+1)=='/')){
                            curPos++;
                            if (curPos>=line.length()){
                                curPos=0;
                                i++;
                                line = lines.get(i);
                            }
                        }
                        curPos+=2;
                    }
                    else {
                        Token token = new Token("/","DIV",i+1);
                        tokens.add(token);
                        curPos++;
                    }
                }
                else if(c=='<'){
                    if (line.charAt(curPos+1)=='='){
                        Token token = new Token("<=","LEQ",i+1);
                        tokens.add(token);
                        curPos+=2;
                    }
                    else {
                        Token token = new Token("<","LSS",i+1);
                        tokens.add(token);
                        curPos++;
                    }
                }
                else if(c=='>'){
                    if (line.charAt(curPos+1)=='='){
                        Token token = new Token(">=","GEQ",i+1);
                        tokens.add(token);
                        curPos+=2;
                    }
                    else {
                        Token token = new Token(">","GRE",i+1);
                        tokens.add(token);
                        curPos++;
                    }
                }
                else if(c=='='){
                    if (line.charAt(curPos+1)=='='){
                        Token token = new Token("==","EQL",i+1);
                        tokens.add(token);
                        curPos+=2;
                    }
                    else {
                        Token token = new Token("=","ASSIGN",i+1);
                        tokens.add(token);
                        curPos++;
                    }
                }
                else if(c=='!'){
                    if (line.charAt(curPos+1)=='='){
                        Token token = new Token("!=","NEQ",i+1);
                        tokens.add(token);
                        curPos+=2;
                    }
                    else {
                        Token token = new Token("!","NOT",i+1);
                        tokens.add(token);
                        curPos++;
                    }
                }
                else if (c=='+'){
                    Token token = new Token("+","PLUS",i+1);
                    tokens.add(token);
                    curPos++;
                }
                else if (c=='-'){
                    Token token = new Token("-","MINU",i+1);
                    tokens.add(token);
                    curPos++;
                }
                else if (c=='*'){
                    Token token = new Token("*","MULT",i+1);
                    tokens.add(token);
                    curPos++;
                }
                else if (c=='%'){
                    Token token = new Token("%","MOD",i+1);
                    tokens.add(token);
                    curPos++;
                }
                else if (c==';'){
                    Token token = new Token(";","SEMICN",i+1);
                    tokens.add(token);
                    curPos++;
                }
                else if (c==','){
                    Token token = new Token(",","COMMA",i+1);
                    tokens.add(token);
                    curPos++;
                }
                else if (c=='('){
                    Token token = new Token("(","LPARENT",i+1);
                    tokens.add(token);
                    curPos++;
                }
                else if (c==')'){
                    Token token = new Token(")","RPARENT",i+1);
                    tokens.add(token);
                    curPos++;
                }
                else if (c=='['){
                    Token token = new Token("[","LBRACK",i+1);
                    tokens.add(token);
                    curPos++;
                }
                else if (c==']'){
                    Token token = new Token("]","RBRACK",i+1);
                    tokens.add(token);
                    curPos++;
                }
                else if (c=='{'){
                    Token token = new Token("{","LBRACE",i+1);
                    tokens.add(token);
                    curPos++;
                }
                else if (c=='}'){
                    Token token = new Token("}","RBRACE",i+1);
                    tokens.add(token);
                    curPos++;
                }
            }
        }
        return tokens;
    }
    
}
