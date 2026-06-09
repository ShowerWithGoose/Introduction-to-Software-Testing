
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Objects;

public class LexicalAnalyzer {
    private String text;
    private int curPos;
    private ArrayList<Token> tokens;
    private int lineNum;
    private ArrayList<Error> errors;

    public LexicalAnalyzer(String text){
        this.text=text;
        this.curPos=-1;
        this.tokens=new ArrayList<>();
        this.lineNum=1;
        this.errors=new ArrayList<>();
    }
    public char getSym(){
//        if(text.charAt(curPos)=='\n'){
//            lineNum++;
//        }
        this.curPos++;
        if (curPos<text.length())return this.text.charAt(this.curPos);
        else return '\0';

    }
    public boolean is_blank(char ch){
        if (ch==' '||ch=='\t') return true;
        else return false;
    }
    public void retract(){
        this.curPos--;
//        if(text.charAt(curPos)=='\n'){
//            lineNum--;
//        }
    }
    public boolean isValidAscii(char ch){
        if (ch>=32&&ch<=126) return true;
        else  return false;
    }
    public boolean isNoneDigitAlpha(char ch){
        if(ch=='_'||ch>='a'&&ch<='z'||ch>='A'&&ch<='Z') return true;
        else return false;
    }
    public Word reserver(String s){
        if(Objects.equals(s, "main")) return Word.MAINTK;
        else if(Objects.equals(s, "const")) return Word.CONSTTK;
        else if(Objects.equals(s, "int")) return Word.INTTK;
        else if(Objects.equals(s, "char")) return Word.CHARTK;
        else if(Objects.equals(s, "break")) return Word.BREAKTK;
        else if(Objects.equals(s, "continue")) return Word.CONTINUETK;
        else if(Objects.equals(s, "if")) return Word.IFTK;
        else if(Objects.equals(s, "else")) return Word.ELSETK;
        else if(Objects.equals(s, "for")) return Word.FORTK;
        else if(Objects.equals(s, "getint")) return Word.GETINTTK;
        else if(Objects.equals(s, "getchar")) return Word.GETCHARTK;
        else if(Objects.equals(s, "printf")) return Word.PRINTFTK;
        else if(Objects.equals(s, "return")) return Word.RETURNTK;
        else if(Objects.equals(s, "void")) return Word.VOIDTK;
        else return Word.IDENFR;
    }
    public void parse()  {
        Token curToken;

        char ch;
        char chNext;
        while (curPos<text.length()){
            ch=getSym();
            if (ch=='\0') return;
            while (is_blank(ch)){
                ch=getSym();
            }
            if(ch=='+') tokens.add(new Token(Word.PLUS,"+"));
            else if (ch=='-') tokens.add(new Token(Word.MINU,"-"));
            else if(ch=='*') tokens.add(new Token(Word.MULT,"*"));
            else if(ch==',') tokens.add(new Token(Word.COMMA,","));
            else if(ch==';') tokens.add(new Token(Word.SEMICN,";"));
            else if (ch=='(') tokens.add(new Token(Word.LPARENT,"("));
            else if(ch==')') tokens.add(new Token(Word.RPARENT,")"));
            else if(ch=='%') tokens.add(new Token(Word.MOD,"%"));
            else if(ch=='[') tokens.add(new Token(Word.LBRACK,"["));
            else if(ch==']') tokens.add(new Token(Word.RBRACK,"]"));
            else if(ch=='{') tokens.add(new Token(Word.LBRACE,"{"));
            else if(ch=='}') tokens.add(new Token(Word.RBRACE,"}"));
            else if(ch=='/') tokens.add(new Token(Word.DIV,"/"));


            else if(ch=='<'){
                chNext=getSym();
                if(chNext=='=') tokens.add(new Token(Word.LEQ,"<="));
                else{
                    retract();
                    tokens.add(new Token(Word.LSS,"<"));
                }
            }
            else if(ch=='>'){
                chNext=getSym();
                if(chNext=='=') tokens.add(new Token(Word.GEQ,">="));
                else{
                    retract();
                    tokens.add(new Token(Word.GRE,">"));
                }
            }
            else if(ch=='='){
                chNext=getSym();
                if(chNext=='=') tokens.add(new Token(Word.EQL,"=="));
                else {
                    retract();
                    tokens.add(new Token(Word.ASSIGN,"="));
                }
            }
            else if(ch=='!'){
                chNext=getSym();
                if(chNext=='=') tokens.add(new Token(Word.NEQ,"!="));
                else {
                    retract();
                    tokens.add(new Token(Word.NOT,"!"));
                }
            }
            else if(ch=='&'){
                chNext=getSym();
                if(chNext=='&') tokens.add(new Token(Word.AND,"&&"));
                else{
                    retract();
                    //throw new LexicalException(new Error('a',lineNum));
                    errors.add(new Error('a',lineNum));
                }
            }
            else if(ch=='|'){
                chNext=getSym();
                if(chNext=='|') tokens.add(new Token(Word.OR,"||"));
                else{
                    retract();
                    //throw new LexicalException(new Error('a',lineNum));
                    errors.add(new Error('a',lineNum));
                }
            }
            else if(Character.isDigit(ch)){
                StringBuilder sb=new StringBuilder();

                while (Character.isDigit(ch)){
                    sb.append(ch);
                    ch=getSym();
                }
                retract();
                tokens.add(new Token(Word.INTCON,sb.toString()));
            }
            else if(isNoneDigitAlpha(ch)){
                StringBuilder sb=new StringBuilder();
                while (isNoneDigitAlpha(ch)||Character.isDigit(ch)){
                    sb.append(ch);
                    ch=getSym();
                }
                retract();
                tokens.add(new Token(reserver(sb.toString()),sb.toString()));

            }
            else if(ch=='\''){
                ch=getSym();
                if(ch=='\\'){
                    chNext=getSym();
                    switch (chNext){
                        case 'n':
                            tokens.add(new Token(Word.CHRCON,"'\\n'"));
                            break;
                        case '"':
                            tokens.add(new Token(Word.CHRCON,"'\\\"'"));
                            break;
                        case '\'':
                            tokens.add(new Token(Word.CHRCON, "'\\''"));
                            break;
                        case '\\':
                            tokens.add(new Token(Word.CHRCON,"'\\\\'"));
                            break;
                        case 'a':
                            tokens.add(new Token(Word.CHRCON,"'\\a'"));
                            break;
                        case 'b':
                            tokens.add(new Token(Word.CHRCON,"'\\b'"));
                            break;
                        case 't':
                            tokens.add(new Token(Word.CHRCON,"'\\t'"));
                            break;
                        case 'v':
                            tokens.add(new Token(Word.CHRCON,"'\\v'"));
                            break;
                        case 'f':
                            tokens.add(new Token(Word.CHRCON,"'\\f'"));
                            break;
                        case '0':
                            tokens.add(new Token(Word.CHRCON,"'\\0'"));
                            break;
                        default:
                            break;
                    }
                }else {
                    tokens.add(new Token(Word.CHRCON,"'"+String.valueOf(ch)+"'"));
                }
                ch=getSym();
            }else if(ch=='"'){
                StringBuilder sb=new StringBuilder();
                sb.append('"');
                chNext=getSym();
                while (chNext!='"'){
                    sb.append(chNext);
                    chNext=getSym();
                }
                sb.append('"');
                tokens.add(new Token(Word.STRCON,sb.toString()));
            }else {
                if (ch=='\n') lineNum++;


            }

        }
    }

    public ArrayList<Token> getTokens(){
        return tokens;
    }
    public ArrayList<Error> getErrors(){
        return errors;
    }

}
