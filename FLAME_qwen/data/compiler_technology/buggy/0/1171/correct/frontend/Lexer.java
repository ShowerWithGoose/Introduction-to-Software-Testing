package frontend;

import java.util.ArrayList;
import java.util.HashMap;

public class Lexer {
    public ArrayList<Token> tokenlist=new ArrayList<>();
    public ArrayList<LexerException> lexerExceptionArrayList=new ArrayList<>();
    String str;
    int line;
    int annotationFlag;
    String word = "";

    public void analyze(String str,int line,int annotationFlag){
        this.str = str;
        this.line = line;
        this.annotationFlag = annotationFlag;
        char letter[];
        letter = this.str.toCharArray();
        HashMap<String,String> definedWords = new HashMap<String,String>();
        definedWords.put("main","MAINTK");
        definedWords.put("const","CONSTTK");
        definedWords.put("int","INTTK");
        definedWords.put("char","CHARTK");
        definedWords.put("break","BREAKTK");
        definedWords.put("continue","CONTINUETK");
        definedWords.put("if","IFTK");
        definedWords.put("else","ELSETK");
        definedWords.put("for","FORTK");
        definedWords.put("getint","GETINTTK");
        definedWords.put("getchar","GETCHARTK");
        definedWords.put("printf","PRINTFTK");
        definedWords.put("return","RETURNTK");
        definedWords.put("+","PLUS");
        definedWords.put("-","MINU");
        definedWords.put("void","VOIDTK");
        definedWords.put("*","MULT");
        definedWords.put("%","MOD");
        definedWords.put("/","DIV");
        definedWords.put(";","SEMICN");
        definedWords.put(",","COMMA");
        definedWords.put("(","LPARENT");
        definedWords.put(")","RPARENT");
        definedWords.put("[","LBRACK");
        definedWords.put("]","RBRACK");
        definedWords.put("{","LBRACE");
        definedWords.put("}","RBRACE");


        for(int i = 0;i< letter.length;i++){
            if(this.annotationFlag == 1){
                if(i != letter.length-1 && letter[i] == '*' && letter[i+1] == '/') {
                    i++;
                    this.annotationFlag = 0;
                }
            }
            else{
                if(i != letter.length-1 && letter[i] =='/' && letter[i+1] =='/')
                    break;
                else if(i != letter.length-1 && letter[i] =='/' && letter[i+1] =='*'){
                    i++;
                    this.annotationFlag =1;
                }
                else if(letter[i]==' '||letter[i]=='\n'||letter[i]=='\r'||letter[i]=='\t')
                    continue;
                else if(definedWords.containsKey(String.valueOf(letter[i]))){
                    Token t = new Token(String.valueOf(letter[i]),definedWords.get(String.valueOf(letter[i])),this.line);
                    tokenlist.add(t);
                }
                else if(letter[i] == '!'){
                    if(i != letter.length-1 && letter[i+1] == '='){
                        Token t =new Token("!=","NEQ",this.line);
                        tokenlist.add(t);
                        i++;
                    }
                    else{
                        Token t = new Token("!","NOT",this.line);
                        tokenlist.add(t);
                    }
                }
                else if(letter[i] == '&'){
                    if(i != letter.length-1 && letter[i+1] == '&'){
                        Token t =new Token("&&","AND",this.line);
                        tokenlist.add(t);
                        i++;
                    }
                    else{
                        LexerException lexerException = new LexerException(this.line,'a');
                        lexerExceptionArrayList.add(lexerException);
                    }
                }
                else if(letter[i] == '|'){
                    if(i != letter.length-1 && letter[i+1] == '|'){
                        Token t =new Token("||","OR",this.line);
                        tokenlist.add(t);
                        i++;
                    }
                    else{
                        LexerException lexerException = new LexerException(this.line,'a');
                        lexerExceptionArrayList.add(lexerException);
                    }
                }
                else if(letter[i] == '<'){
                    if(i != letter.length-1 && letter[i+1] == '='){
                        Token t =new Token("<=","LEQ",this.line);
                        tokenlist.add(t);
                        i++;
                    }
                    else{
                        Token t = new Token("<","LSS",this.line);
                        tokenlist.add(t);
                    }
                }
                else if(letter[i] == '>'){
                    if(i != letter.length-1 && letter[i+1] == '='){
                        Token t =new Token(">=","GEQ",this.line);
                        tokenlist.add(t);
                        i++;
                    }
                    else{
                        Token t = new Token(">","GRE",this.line);
                        tokenlist.add(t);
                    }
                }
                else if(letter[i] == '='){
                    if(i != letter.length-1 && letter[i+1] == '='){
                        Token t =new Token("==","EQL",this.line);
                        tokenlist.add(t);
                        i++;
                    }
                    else{
                        Token t = new Token("=","ASSIGN",this.line);
                        tokenlist.add(t);
                    }
                }
                else if(letter[i] == '0'){
                    Token t = new Token("0","INTCON",this.line);
                    tokenlist.add(t);
                }
                else if(letter[i] == '\'' ){
                    this.word = this.word + letter[i];
                    i++;
                    while(i < letter.length && (letter[i] != '\'' || (letter[i] == '\'' && letter[i-1] == '\\'))){
                        this.word = this.word + letter[i];
                        i++;
                    }
                    this.word = this.word + letter[i];
                    Token t = new Token(this.word,"CHRCON",this.line);
                    tokenlist.add(t);
                    this.word ="";
                }
                else if(letter[i] == '\"' ){
                    this.word = this.word + letter[i];
                    i++;
                    while(i < letter.length && (letter[i] != '\"' || (letter[i] == '\"' && letter[i-1] == '\\'))){
                        this.word = this.word + letter[i];
                        i++;
                    }
                    this.word = this.word + letter[i];
                    Token t = new Token(this.word,"STRCON",this.line);
                    tokenlist.add(t);
                    this.word ="";
                }
                else if(letter[i] > '0' && letter[i] <='9'){
                    this.word = this.word + letter[i];
                    i++;
                    while(i < letter.length && letter[i] >= '0' && letter[i] <='9'){
                        this.word = this.word + letter[i];
                        i++;
                    }
                    Token t = new Token(this.word,"INTCON",this.line);
                    tokenlist.add(t);
                    this.word = "";
                    i--;
                }
                else if(letter[i] == '_' || (letter[i]<='z' && letter[i]>='a') ||(letter[i]<='Z' && letter[i]>='A')){
                    this.word = this.word + letter[i];
                    i++;
                    while(i < letter.length && (letter[i] == '_' || (letter[i]<='z' && letter[i]>='a') ||(letter[i]<='Z' && letter[i]>='A') || (letter[i] >= '0' && letter[i] <='9'))){
                        this.word = this.word + letter[i];
                        i++;
                    }
                    if(definedWords.containsKey(word)){
                        Token t = new Token(this.word, definedWords.get(word), this.line);
                        tokenlist.add(t);
                    }
                    else {
                        Token t = new Token(this.word, "IDENFR", this.line);
                        tokenlist.add(t);
                    }
                    this.word = "";
                    i--;
                }
                else{
                    //exception
                }

            }
        }
    }
    public int getAnnotationFlag(){
        return this.annotationFlag;
    }
    public ArrayList<Token> getTokens(){
        return  tokenlist;
    }
    public ArrayList<LexerException> getLexerExceptionArrayList(){
        return lexerExceptionArrayList;
    }
    public  int  error(){
        return lexerExceptionArrayList.size();
    }
}
