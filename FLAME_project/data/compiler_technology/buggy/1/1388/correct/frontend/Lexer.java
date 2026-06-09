package frontend;
import java.io.*;
import java.util.ArrayList;

public class Lexer {
    File source;
    int curPos;
    int curLine;
    public ArrayList<Token> tokens;
    public ArrayList<Error> errors;

    public Lexer(File source) {
        this.source = source;
        this.curPos = 0;
        this.curLine = 1;
        this.tokens = new ArrayList<>();
        this.errors = new ArrayList<>();
    }

    public int annotation(BufferedReader br){
       try {
           this.curPos = br.read();
           if(this.curPos != '/' && this.curPos != '*') {
               this.tokens.add(new Token("/", LexType.DIV, this.curLine)); //除号
               return 1;
           } else if(this.curPos == '/'){
               while ((this.curPos = br.read()) != -1){
                   if(this.curPos == '\n') {//行尾注释结束
                       this.curLine++;
                       break;
                   }
               }
           } else {
               this.curPos = br.read();
               while (this.curPos != -1){
                   int next = br.read();
                   if(this.curPos == '*'&&next == '/') {
                        break;//注释结束
                   }

                   if(this.curPos == '\n') this.curLine++;

                   this.curPos = next;
               }
           }
           return 0;
       } catch (IOException e) {
           throw new RuntimeException(e);
       }
    }

    private int number(BufferedReader br) {
        try {
            StringBuilder token = new StringBuilder();
            token.append((char) this.curPos);
            while ((this.curPos = br.read()) != -1) {
                if(Character.isDigit(this.curPos)) {
                    token.append((char) this.curPos);
                } else {
                    this.tokens.add(new Token(token.toString(), LexType.INTCON, this.curLine));
                    return 1;
                }
            }
            return 0;
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    private int word(BufferedReader br) {
        try {
            StringBuilder token = new StringBuilder();
            token.append((char) this.curPos);
            while ((this.curPos = br.read()) != -1) {
                if(Character.isDigit(this.curPos) || Character.isLetter(this.curPos) || this.curPos == '_') {
                    token.append((char) this.curPos);
                    //System.out.println(token);
                } else {
                    //System.out.println(token);
                    if(token.toString().equals("main"))
                        this.tokens.add(new Token("main", LexType.MAINTK, this.curLine));
                    else if(token.toString().equals("int"))
                        this.tokens.add(new Token("int", LexType.INTTK, this.curLine));
                    else if(token.toString().equals("char"))
                        this.tokens.add(new Token("char", LexType.CHARTK, this.curLine));
                    else if(token.toString().equals("void"))
                        this.tokens.add(new Token("void", LexType.VOIDTK, this.curLine));
                    else if(token.toString().equals("const"))
                        this.tokens.add(new Token("const", LexType.CONSTTK, this.curLine));
                    else if(token.toString().equals("break"))
                        this.tokens.add(new Token("break", LexType.BREAKTK, this.curLine));
                    else if(token.toString().equals("continue"))
                        this.tokens.add(new Token("continue", LexType.CONTINUETK, this.curLine));
                    else if(token.toString().equals("if"))
                        this.tokens.add(new Token("if", LexType.IFTK, this.curLine));
                    else if(token.toString().equals("else"))
                        this.tokens.add(new Token("else",LexType.ELSETK, this.curLine));
                    else if(token.toString().equals("for"))
                        this.tokens.add(new Token("for", LexType.FORTK, this.curLine));
                    else if(token.toString().equals("getint"))
                        this.tokens.add(new Token("getint", LexType.GETINTTK, this.curLine));
                    else if(token.toString().equals("getchar"))
                        this.tokens.add(new Token("getchar", LexType.GETCHARTK, this.curLine));
                    else if(token.toString().equals("printf"))
                        this.tokens.add(new Token("printf", LexType.PRINTFTK, this.curLine));
                    else if(token.toString().equals("return"))
                        this.tokens.add(new Token("return", LexType.RETURNTK, this.curLine));
                    else
                        this.tokens.add(new Token(token.toString(), LexType.IDENFR, this.curLine));
                    //System.out.println("a token is get");
                    return 1;
                }
            }
            return 0;
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    private int symbol(BufferedReader br) {
        try {
            if(this.curPos==',')
                this.tokens.add(new Token(",", LexType.COMMA, this.curLine));
            else if (this.curPos==';')
                this.tokens.add(new Token(";", LexType.SEMICN, this.curLine));
            else if(this.curPos == '+')
                this.tokens.add(new Token("+", LexType.PLUS, this.curLine));
            else if(this.curPos == '-')
                this.tokens.add(new Token("-", LexType.MINU, this.curLine));
            else if(this.curPos == '*')
                this.tokens.add(new Token("*", LexType.MULT, this.curLine));
            else if(this.curPos == '%')
                this.tokens.add(new Token("%", LexType.MOD, this.curLine));
            else if(this.curPos == '(')
                this.tokens.add(new Token("(", LexType.LPARENT, this.curLine));
            else if (this.curPos == ')')
                this.tokens.add(new Token(")", LexType.RPARENT, this.curLine));
            else if (this.curPos == '[')
                this.tokens.add(new Token("[", LexType.LBRACK, this.curLine));
            else if (this.curPos == ']')
                this.tokens.add(new Token("]", LexType.RBRACK, this.curLine));
            else if(this.curPos == '{')
                this.tokens.add(new Token("{", LexType.LBRACE, this.curLine));
            else if (this.curPos == '}')
                this.tokens.add(new Token("}", LexType.RBRACE, this.curLine));
            else if(this.curPos == '!'){
                this.curPos = br.read();
                if(this.curPos == '=')
                    this.tokens.add(new Token("!=", LexType.NEQ, this.curLine));
                else {
                    this.tokens.add(new Token("!", LexType.NOT, this.curLine));
                    return 1;
                }
            } else if(this.curPos == '<'){
                this.curPos = br.read();
                if(this.curPos == '=')
                    this.tokens.add(new Token("<=", LexType.LEQ, this.curLine));
                else {
                    this.tokens.add(new Token("<", LexType.LSS, this.curLine));
                    return 1;
                }
            } else if(this.curPos == '>'){
                this.curPos = br.read();
                if(this.curPos == '=')
                    this.tokens.add(new Token(">=", LexType.GEQ, this.curLine));
                else {
                    this.tokens.add(new Token(">", LexType.GRE, this.curLine));
                    return 1;
                }
            } else if(this.curPos == '='){
                this.curPos = br.read();
                if(this.curPos == '=')
                    this.tokens.add(new Token("==", LexType.EQL, this.curLine));
                else {
                    this.tokens.add(new Token("=", LexType.ASSIGN, this.curLine));
                    return 1;
                }
            } else if (this.curPos == '&') {
                this.curPos = br.read();
                if(this.curPos == '&')
                    this.tokens.add(new Token("&&", LexType.AND, this.curLine));
                else {
                    this.tokens.add(new Token("&&", LexType.AND, this.curLine));
                    this.errors.add(new Error(this.curLine, "a"));
                    return 1;
                }
            } else if (this.curPos == '|') {
                this.curPos = br.read();
                if (this.curPos == '|')
                    this.tokens.add(new Token("||", LexType.OR, this.curLine));
                else {
                    this.tokens.add(new Token("||", LexType.OR, this.curLine));
                    this.errors.add(new Error(this.curLine, "a"));
                    return 1;
                }
            }
            return 0;
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    private int string(BufferedReader br) {
        try {
            StringBuilder token = new StringBuilder();
            token.append((char) this.curPos);
            while ((this.curPos = br.read()) != -1) {
                if(this.curPos != '\"') {
                    token.append((char) this.curPos);
                } else {
                    token.append((char) this.curPos);
                    this.tokens.add(new Token(token.toString(), LexType.STRCON, this.curLine));
                    return 0;
                }
            }
            return -1;
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    private int ch(BufferedReader br) {
        try {
            StringBuilder token = new StringBuilder();
            token.append((char) this.curPos);
            this.curPos = br.read();
            token.append((char) this.curPos);
            if(this.curPos == '\\') {
                this.curPos = br.read();
                token.append((char) this.curPos);
            }
            this.curPos = br.read();
            if(this.curPos == '\'') {
                token.append((char) this.curPos);
                this.tokens.add(new Token(token.toString(), LexType.CHRCON, this.curLine));
                return 0;
            }
            return -1;
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public void wordAna() {
        BufferedReader br;
        try {
            br = new BufferedReader(new FileReader(this.source));
            this.curPos = br.read();
            while(this.curPos != -1){
                //System.out.println("i get a " + (char)curPos);
                if(this.curPos=='\n') this.curLine++;
                else if(this.curPos==' ') ;
                else if(this.curPos=='/') {
                    if(this.annotation(br) == 1)
                        continue;
                }
                else if(Character.isDigit(this.curPos)) {
                    if(this.number(br) == 1)
                        continue;
                }
                else if(Character.isLetter(this.curPos) || this.curPos == '_') {
                    if(this.word(br) == 1)
                        continue;
                }
                else if(this.curPos == '\"') this.string(br);
                else if(this.curPos == '\'') this.ch(br);
                else{
                    if(this.symbol(br) == 1)
                        continue;
                }

                this.curPos = br.read();
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }


}
