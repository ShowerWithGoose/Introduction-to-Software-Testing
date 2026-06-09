package frontend;

import java.io.*;
import java.util.ArrayList;

import static frontend.Token.LexType.*;

public class Lexer {
    public ArrayList<Token> tokenList = new ArrayList<>();
    public void analyzeByLine(FileReader br) throws IOException {
        int chr = -1;
        int lineNum = 1;
        chr = br.read();
        char ch = (char) chr;
        while(chr != -1){
            StringBuilder sb = new StringBuilder();
            if(ch == '\n'){
                try{
                    chr = br.read();
                    ch = (char) chr;
                }catch (IOException e){
                    e.printStackTrace();
                }
                lineNum++;
            }else if((ch == '\0') || (ch == ' ') || (ch == '\t') || (ch == '\b') || (ch == '\r') || (ch == '\\')) {
                try{
                    chr = br.read();
                    ch = (char) chr;
                }catch (IOException e){
                    e.printStackTrace();
                }
            }else if((ch >='a' && ch <='z') || (ch >='A' && ch <='Z') || ch == '_'){
                while((ch >='a' && ch <='z') || (ch >='A' && ch <='Z') || (ch == '_') || (ch >= '0' && ch <= '9')){
                    sb.append(ch);
                    try{
                        chr = br.read();
                        ch = (char) chr;
                    }catch (IOException e){
                        e.printStackTrace();
                    }
                }
                Token token = new Token(sb,lineNum);
                tokenList.add(token);
            }else if(ch >= '0' && ch <= '9'){
                while(ch >='0' && ch <= '9'){
                    sb.append(ch);
                    try{
                        chr = br.read();
                        ch = (char) chr;
                    }catch (IOException e){
                        e.printStackTrace();
                    }
                }
                Token token = new Token(INTCON, sb, lineNum);
                tokenList.add(token);

            }else if(ch == '/') {
                sb.append(ch);
                try{
                    chr = br.read();
                    ch = (char) chr;
                }catch (IOException e){
                    e.printStackTrace();
                }
                if(ch == '/'){
                    try{
                        chr = br.read();
                        ch = (char) chr;
                    }catch (IOException e){
                        e.printStackTrace();
                    }
                    while(ch != '\n' && chr != -1){
                        try{
                            chr = br.read();
                            ch = (char) chr;
                        }catch (IOException e){
                            e.printStackTrace();
                        }
                    }
                }else if(ch == '*'){
                    try{
                        chr = br.read();
                        ch = (char) chr;
                    }catch (IOException e){
                        e.printStackTrace();
                    }
                    while(chr != -1){
                        if(ch == '*'){
                            try{
                                chr = br.read();
                                ch = (char) chr;
                            }catch (IOException e){
                                e.printStackTrace();
                            }
                            if(ch == '/'){
                                try{
                                    chr = br.read();
                                    ch = (char) chr;
                                }catch (IOException e){
                                    e.printStackTrace();
                                }
                                break;
                            }else{
                                continue;
                            }
                        }else if (ch == '\n'){
                            lineNum++;
                        }
                        try{
                            chr = br.read();
                            ch = (char) chr;
                        }catch (IOException e){
                            e.printStackTrace();
                        }
                    }
                }else{
                    Token token = new Token(sb, lineNum);
                    tokenList.add(token);
                }
            }else if((ch == '!') || (ch == '>') || (ch == '<') || (ch == '=')){
                sb.append(ch);
                try{
                    chr = br.read();
                    ch = (char) chr;
                }catch (IOException e){
                    e.printStackTrace();
                }
                if(ch == '='){
                    sb.append(ch);
                    Token token = new Token(sb, lineNum);
                    tokenList.add(token);
                    try{
                        chr = br.read();
                        ch = (char) chr;
                    }catch (IOException e){
                        e.printStackTrace();
                    }
                }else {
                    Token token = new Token(sb, lineNum);
                    tokenList.add(token);
                }
            }else if(ch == '&'){
                sb.append(ch);
                try{
                    chr = br.read();
                    ch = (char) chr;
                }catch (IOException e){
                    e.printStackTrace();
                }
                if(ch == '&'){
                    sb.append(ch);
                    Token token = new Token(sb, lineNum);
                    tokenList.add(token);
                    try{
                        chr = br.read();
                        ch = (char) chr;
                    }catch (IOException e){
                        e.printStackTrace();
                    }
                }else{
                    sb.append('&');
                    Token token = new Token(sb, lineNum);
                    tokenList.add(token);
                    Error.addError(new Error(lineNum, Error.ErrorType.a));
                }

            }else if(ch == '|'){
                sb.append(ch);
                try{
                    chr = br.read();
                    ch = (char) chr;
                }catch (IOException e){
                    e.printStackTrace();
                }
                if(ch == '|'){
                    sb.append(ch);
                    Token token = new Token(sb, lineNum);
                    tokenList.add(token);
                    try{
                        chr = br.read();
                        ch = (char) chr;
                    }catch (IOException e){
                        e.printStackTrace();
                    }
                }else{
                    sb.append('|');
                    Token token = new Token(sb, lineNum);
                    tokenList.add(token);
                    Error.addError(new Error(lineNum, Error.ErrorType.a));
                }
            }else if(ch == '\''){
                sb.append(ch);
                try{
                    chr = br.read();
                    ch = (char) chr;
                }catch (IOException e){
                    e.printStackTrace();
                }
                while(ch != '\''){
                    sb.append(ch);
                    if(ch == '\\'){
                        try{
                            chr = br.read();
                            ch = (char) chr;
                        }catch (IOException e){
                            e.printStackTrace();
                        }
                        sb.append(ch);
                        try{
                            chr = br.read();
                            ch = (char) chr;
                        }catch (IOException e){
                            e.printStackTrace();
                        }
                        continue;
                    }
                    try{
                        chr = br.read();
                        ch = (char) chr;
                    }catch (IOException e){
                        e.printStackTrace();
                    }
                }
                sb.append(ch);
                Token token = new Token(CHRCON, sb, lineNum);
                tokenList.add(token);
                try{
                    chr = br.read();
                    ch = (char) chr;
                }catch (IOException e){
                    e.printStackTrace();
                }
            }else if(ch == '"'){
                sb.append(ch);
                try{
                    chr = br.read();
                    ch = (char) chr;
                }catch (IOException e){
                    e.printStackTrace();
                }
                while(ch != '"'){
                    sb.append(ch);
                    if(ch == '\\'){
                        try{
                            chr = br.read();
                            ch = (char) chr;
                        }catch (IOException e){
                            e.printStackTrace();
                        }
                        sb.append(ch);
                        try{
                            chr = br.read();
                            ch = (char) chr;
                        }catch (IOException e){
                            e.printStackTrace();
                        }
                        continue;
                    }
                    try{
                        chr = br.read();
                        ch = (char) chr;
                    }catch (IOException e){
                        e.printStackTrace();
                    }
                }
                sb.append(ch);
                Token token = new Token(STRCON, sb, lineNum);
                tokenList.add(token);
                try{
                    chr = br.read();
                    ch = (char) chr;
                }catch (IOException e){
                    e.printStackTrace();
                }
            }
            else if((ch == ';') || (ch == ',') || (ch == '(') || (ch == ')') || (ch == '[') || (ch == ']') || (ch == '{') || (ch == '}') || (ch == '%') || (ch == '*') || (ch == '+') || (ch == '-')) {
                sb.append(ch);
                Token token = new Token(sb, lineNum);
                tokenList.add(token);
                try{
                    chr = br.read();
                    ch = (char) chr;
                }catch (IOException e){
                    e.printStackTrace();
                }
            }
        }
    }

}
