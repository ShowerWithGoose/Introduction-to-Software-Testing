import java.util.ArrayList;

public class Lexer {
    private ArrayList<Word> words;
    private int errorRow;
    private String error;
    
    Lexer() {
        words = new ArrayList<>();
        errorRow = 0;
    }
    
    public boolean hasError() {
        if (errorRow!=0) {
            return true;
        }
        else {
            return false;
        }
    }
    
    public int getErrorRow() {
        return errorRow;
    }
    
    public String getError() {
        return error;
    }
    
    public ArrayList<Word> getWords(ArrayList<String> lines) {
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
                String token = "";
                char c = line.charAt(curPos);
                if (Character.isDigit(c)) {
                    token+=c;
                    curPos++;
                    while (curPos < line.length() && Character.isDigit(line.charAt(curPos))) {
                        token+=line.charAt(curPos);
                        curPos++;
                    }
                    Word word = new Word(token,"INTCON",i+1);
                    words.add(word);
                }
                else if (Character.isLetter(c) || c == '_') {
                    token+=c;
                    curPos++;
                    while (curPos < line.length() && (Character.isLetterOrDigit(line.charAt(curPos))||line.charAt(curPos)=='_')){
                        token+=line.charAt(curPos);
                        curPos++;
                    }
                    Word word = new Word(token,"IDENFR",i+1);
                    words.add(word);
                }
                else if (c=='\''){
                    token+=c;
                    curPos++;
                    if (line.charAt(curPos)=='\\' && (curPos+1)<line.length() && line.charAt(curPos+1)=='\''){
                        token+="\\\'";
                        curPos+=2;
                    }
                    while(line.charAt(curPos)!='\''){
                        token+=line.charAt(curPos);
                        curPos++;
                    }
                    token+='\'';
                    curPos++;
                    Word word = new Word(token,"CHRCON",i+1);
                    words.add(word);
                }
                else if (c=='\"'){
                    token+=c;
                    curPos++;
                    while(line.charAt(curPos)!='\"'){
                        token+=line.charAt(curPos);
                        curPos++;
                    }
                    token+='\"';
                    curPos++;
                    Word word = new Word(token,"STRCON",i+1);
                    words.add(word);
                }
                else if(c=='|'){
                    Word word = new Word("||","OR",i+1);
                    if (curPos+1<line.length()&&line.charAt(curPos+1)=='|'){
                        curPos+=2;
                    }
                    else {
                        word.setError("a");
                        error = "a";
                        errorRow = i;
                        curPos+=1;
                    }
                    words.add(word);
                }
                else if(c=='&'){
                    Word word = new Word("&&","AND",i+1);
                    if (curPos+1<line.length()&&line.charAt(curPos+1)=='&'){
                        curPos+=2;
                    }
                    else {
                        word.setError("a");
                        error = "a";
                        errorRow = i;
                        curPos+=1;
                    }
                    words.add(word);
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
                        while (!(line.charAt(curPos)=='*'&&line.charAt(curPos+1)=='/')){
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
                        Word word = new Word("/","DIV",i+1);
                        words.add(word);
                        curPos++;
                    }
                }
                else if(c=='<'){
                    if (line.charAt(curPos+1)=='='){
                        Word word = new Word("<=","LEQ",i+1);
                        words.add(word);
                        curPos+=2;
                    }
                    else {
                        Word word = new Word("<","LSS",i+1);
                        words.add(word);
                        curPos++;
                    }
                }
                else if(c=='>'){
                    if (line.charAt(curPos+1)=='='){
                        Word word = new Word(">=","GEQ",i+1);
                        words.add(word);
                        curPos+=2;
                    }
                    else {
                        Word word = new Word(">","GRE",i+1);
                        words.add(word);
                        curPos++;
                    }
                }
                else if(c=='='){
                    if (line.charAt(curPos+1)=='='){
                        Word word = new Word("==","EQL",i+1);
                        words.add(word);
                        curPos+=2;
                    }
                    else {
                        Word word = new Word("=","ASSIGN",i+1);
                        words.add(word);
                        curPos++;
                    }
                }
                else if(c=='!'){
                    if (line.charAt(curPos+1)=='='){
                        Word word = new Word("!=","NEQ",i+1);
                        words.add(word);
                        curPos+=2;
                    }
                    else {
                        Word word = new Word("!","NOT",i+1);
                        words.add(word);
                        curPos++;
                    }
                }
                else if (c=='+'){
                    Word word = new Word("+","PLUS",i+1);
                    words.add(word);
                    curPos++;
                }
                else if (c=='-'){
                    Word word = new Word("-","MINU",i+1);
                    words.add(word);
                    curPos++;
                }
                else if (c=='*'){
                    Word word = new Word("*","MULT",i+1);
                    words.add(word);
                    curPos++;
                }
                else if (c=='%'){
                    Word word = new Word("%","MOD",i+1);
                    words.add(word);
                    curPos++;
                }
                else if (c==';'){
                    Word word = new Word(";","SEMICN",i+1);
                    words.add(word);
                    curPos++;
                }
                else if (c==','){
                    Word word = new Word(",","COMMA",i+1);
                    words.add(word);
                    curPos++;
                }
                else if (c=='('){
                    Word word = new Word("(","LPARENT",i+1);
                    words.add(word);
                    curPos++;
                }
                else if (c==')'){
                    Word word = new Word(")","RPARENT",i+1);
                    words.add(word);
                    curPos++;
                }
                else if (c=='['){
                    Word word = new Word("[","LBRACK",i+1);
                    words.add(word);
                    curPos++;
                }
                else if (c==']'){
                    Word word = new Word("]","RBRACK",i+1);
                    words.add(word);
                    curPos++;
                }
                else if (c=='{'){
                    Word word = new Word("{","LBRACE",i+1);
                    words.add(word);
                    curPos++;
                }
                else if (c=='}'){
                    Word word = new Word("}","RBRACE",i+1);
                    words.add(word);
                    curPos++;
                }
            }
        }
        return words;
    }
    
}
