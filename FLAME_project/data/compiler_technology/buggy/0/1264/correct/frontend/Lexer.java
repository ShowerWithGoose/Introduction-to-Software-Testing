package frontend;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Lexer {
    public boolean hasErrors = false;
    FileReader fileReader;
    public ArrayList<Token> tokenList = new ArrayList<>();
    public Lexer(FileReader fileReader) {
        this.fileReader = fileReader;
        int lineno = 1;
        int character = -1;
        try{
            character = fileReader.read();
        } catch (IOException e){
            e.printStackTrace();
        }
        char ch = (char) character;
        while (character != -1) {
            StringBuilder tokenContent = new StringBuilder("");
            if(ch == '\b'){
                try{
                    character = fileReader.read();
                    ch = (char) character;
                } catch (IOException e){
                    e.printStackTrace();
                }
            }
            else if(ch == '\\'){
                try{
                    character = fileReader.read();
                    ch = (char) character;
                } catch (IOException e){
                    e.printStackTrace();
                }
            }
            else if(ch == '\0'){
                try{
                    character = fileReader.read();
                    ch = (char) character;
                } catch (IOException e){
                    e.printStackTrace();
                }
            }
            else if(Character.isWhitespace(ch)){
                if(ch == '\n'){
                    lineno ++;
                }
                try{
                    character = fileReader.read();
                    ch = (char) character;
                } catch (IOException e){
                    e.printStackTrace();
                }
            }
            else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '_'){
                tokenContent.append(ch);
                try{
                    character = fileReader.read();
                    ch = (char) character;
                } catch (IOException e){
                    e.printStackTrace();
                }
                while((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || ch == '_'){
                    tokenContent.append(ch);
                    try{
                        character = fileReader.read();
                        ch = (char) character;
                    } catch (IOException e){
                        e.printStackTrace();
                    }
                }
                Token token = new Token(tokenContent,lineno);
                tokenList.add(token);
            }
            else if (ch >= '0' && ch <= '9'){
                tokenContent.append(ch);
                try{
                    character = fileReader.read();
                    ch = (char) character;
                } catch (IOException e){
                    e.printStackTrace();
                }
                while(ch >= '0' && ch <= '9'){
                    tokenContent.append(ch);
                    try{
                        character = fileReader.read();
                        ch = (char) character;
                    } catch (IOException e){
                        e.printStackTrace();
                    }
                }
                Token token = new Token("INTCON",tokenContent,lineno);
                tokenList.add(token);
            }
            else if(ch == '"'){
                tokenContent.append(ch);
                try{
                    character = fileReader.read();
                    ch = (char) character;
                } catch (IOException e){
                    e.printStackTrace();
                }
                while(ch != '"'){
                    tokenContent.append(ch);
                    if(ch == '\\'){
                        try{
                            character = fileReader.read();
                            ch = (char) character;
                        } catch (IOException e){
                            e.printStackTrace();
                        }
                        tokenContent.append(ch);
                        try{
                            character = fileReader.read();
                            ch = (char) character;
                        } catch (IOException e){
                            e.printStackTrace();
                        }
                        continue;
                    }
                    try{
                        character = fileReader.read();
                        ch = (char) character;
                    } catch (IOException e){
                        e.printStackTrace();
                    }
                }
                tokenContent.append(ch);
                Token token = new Token("STRCON",tokenContent,lineno);
                tokenList.add(token);
                try{
                    character = fileReader.read();
                    ch = (char) character;
                } catch (IOException e){
                    e.printStackTrace();
                }
            }
            else if(ch == '\''){
                tokenContent.append(ch);
                try{
                    character = fileReader.read();
                    ch = (char) character;
                } catch (IOException e){
                    e.printStackTrace();
                }
                while(ch != '\'' ){
                    tokenContent.append(ch);
                    if(ch == '\\'){
                        try{
                            character = fileReader.read();
                            ch = (char) character;
                        } catch (IOException e){
                            e.printStackTrace();
                        }
                        tokenContent.append(ch);
                        try{
                            character = fileReader.read();
                            ch = (char) character;
                        } catch (IOException e){
                            e.printStackTrace();
                        }
                        continue;
                    }
                    try{
                        character = fileReader.read();
                        ch = (char) character;
                    } catch (IOException e){
                        e.printStackTrace();
                    }
                }
                tokenContent.append(ch);
                Token token = new Token("CHRCON",tokenContent,lineno);
                tokenList.add(token);
                try{
                    character = fileReader.read();
                    ch = (char) character;
                } catch (IOException e){
                    e.printStackTrace();
                }
            }
            else if(ch == '!'){
                tokenContent.append(ch);
                try{
                    character = fileReader.read();
                    ch = (char) character;
                } catch (IOException e){
                    e.printStackTrace();
                }
                if(ch == '='){
                    tokenContent.append(ch);
                    Token token = new Token("NEQ",tokenContent,lineno);
                    tokenList.add(token);
                    try{
                        character = fileReader.read();
                        ch = (char) character;
                    } catch (IOException e){
                        e.printStackTrace();
                    }
                }
                else{
                    Token token = new Token("NOT",tokenContent,lineno);
                    tokenList.add(token);
                }
            }
            //&&,||
            else if(ch == '&'){
                tokenContent.append(ch);
                try{
                    character = fileReader.read();
                    ch = (char) character;
                } catch (IOException e){
                    e.printStackTrace();
                }
                if(ch == '&'){
                    tokenContent.append(ch);
                    Token token = new Token("AND",tokenContent,lineno);
                    tokenList.add(token);
                    try{
                        character = fileReader.read();
                        ch = (char) character;
                    } catch (IOException e){
                        e.printStackTrace();
                    }
                }
                else{
                    hasErrors = true;
                    Token token = new Token("AND",tokenContent,lineno);  //&按&&处理存入
                    try (FileWriter writer = new FileWriter("error.txt")) {
                            writer.write(lineno + " " + "a" + "\n");
                    }
                    catch (IOException e) {
                        e.printStackTrace();
                    }
                }
            }
            else if(ch == '|'){
                tokenContent.append(ch);
                try{
                    character = fileReader.read();
                    ch = (char) character;
                } catch (IOException e){
                    e.printStackTrace();
                }
                if(ch == '|'){
                    tokenContent.append(ch);
                    Token token = new Token("OR",tokenContent,lineno);
                    tokenList.add(token);
                    try{
                        character = fileReader.read();
                        ch = (char) character;
                    } catch (IOException e){
                        e.printStackTrace();
                    }
                }
                else{
                    hasErrors = true;
                    Token token = new Token("OR",tokenContent,lineno);  //|按||处理存入
                    try (FileWriter writer = new FileWriter("error.txt")) {
                        writer.write(lineno + " " + "a" + "\n");
                    }
                    catch (IOException e) {
                        e.printStackTrace();
                    }
                }
            }
            else if(ch == '+'){
                tokenContent.append(ch);
                try{
                    character = fileReader.read();
                    ch = (char) character;
                } catch (IOException e){
                    e.printStackTrace();
                }
                Token token = new Token("PLUS",tokenContent,lineno);
                tokenList.add(token);
            }
            else if(ch == '-'){
                tokenContent.append(ch);
                try{
                    character = fileReader.read();
                    ch = (char) character;
                } catch (IOException e){
                    e.printStackTrace();
                }
                Token token = new Token("MINU",tokenContent,lineno);
                tokenList.add(token);
            }
            else if(ch == '*'){
                tokenContent.append(ch);
                try{
                    character = fileReader.read();
                    ch = (char) character;
                } catch (IOException e){
                    e.printStackTrace();
                }
                Token token = new Token("MULT",tokenContent,lineno);
                tokenList.add(token);
            }
            else if(ch == '/'){
                tokenContent.append(ch);
                try{
                    character = fileReader.read();
                    ch = (char) character;
                } catch (IOException e){
                    e.printStackTrace();
                }
                if(ch == '/'){
                    try{
                        character = fileReader.read();
                        ch = (char) character;
                    } catch (IOException e){
                        e.printStackTrace();
                    }
                    while(ch != '\n' && character != -1){
                        try{
                            character = fileReader.read();
                            ch = (char) character;
                        } catch (IOException e){
                            e.printStackTrace();
                        }
                    }
                }
                else if(ch == '*'){
                    try{
                        character = fileReader.read();
                        ch = (char) character;
                    } catch (IOException e){
                        e.printStackTrace();
                    }
                    while(character != -1){
                        if(ch == '*'){
                            try{
                                character = fileReader.read();
                                ch = (char) character;
                            } catch (IOException e){
                                e.printStackTrace();
                            }
                            if(ch == '/'){
                                try{
                                    character = fileReader.read();
                                    ch = (char) character;
                                } catch (IOException e){
                                    e.printStackTrace();
                                }
                                break;
                            }
                            else{
                                continue;
                            }
                        }
                        else if(ch == '\n'){
                            lineno ++;
                        }
                        try{
                            character = fileReader.read();
                            ch = (char) character;
                        } catch (IOException e){
                            e.printStackTrace();
                        }
                    }
                }
                else{
                    Token token = new Token("DIV",tokenContent,lineno);
                    tokenList.add(token);
                }
            }
            else if(ch == '%'){
                tokenContent.append(ch);
                try{
                    character = fileReader.read();
                    ch = (char) character;
                } catch (IOException e){
                    e.printStackTrace();
                }
                Token token = new Token("MOD",tokenContent,lineno);
                tokenList.add(token);
            }
            else if(ch == '<'){
                tokenContent.append(ch);
                try{
                    character = fileReader.read();
                    ch = (char) character;
                } catch (IOException e){
                    e.printStackTrace();
                }
                if(ch == '='){
                    tokenContent.append(ch);
                    Token token = new Token("LEQ",tokenContent,lineno);
                    tokenList.add(token);
                    try{
                        character = fileReader.read();
                        ch = (char) character;
                    } catch (IOException e){
                        e.printStackTrace();
                    }
                }
                else{
                    Token token = new Token("LSS",tokenContent,lineno);
                    tokenList.add(token);
                }
            }
            else if(ch == '>'){
                tokenContent.append(ch);
                try{
                    character = fileReader.read();
                    ch = (char) character;
                } catch (IOException e){
                    e.printStackTrace();
                }
                if(ch == '='){
                    tokenContent.append(ch);
                    Token token = new Token("GEQ",tokenContent,lineno);
                    tokenList.add(token);
                    try{
                        character = fileReader.read();
                        ch = (char) character;
                    } catch (IOException e){
                        e.printStackTrace();
                    }
                }
                else{
                    Token token = new Token("GRE",tokenContent,lineno);
                    tokenList.add(token);
                }
            }
            else if(ch == '='){
                tokenContent.append(ch);
                try{
                    character = fileReader.read();
                    ch = (char) character;
                } catch (IOException e){
                    e.printStackTrace();
                }
                if(ch == '='){
                    tokenContent.append(ch);
                    Token token = new Token("EQL",tokenContent,lineno);
                    tokenList.add(token);
                    try{
                        character = fileReader.read();
                        ch = (char) character;
                    } catch (IOException e){
                        e.printStackTrace();
                    }
                }
                else{
                    Token token = new Token("ASSIGN",tokenContent,lineno);
                    tokenList.add(token);
                }
            }
            else if(ch == ';'){
                tokenContent.append(ch);
                try{
                    character = fileReader.read();
                    ch = (char) character;
                } catch (IOException e){
                    e.printStackTrace();
                }
                Token token = new Token("SEMICN",tokenContent,lineno);
                tokenList.add(token);
            }
            else if(ch == ','){
                tokenContent.append(ch);
                try{
                    character = fileReader.read();
                    ch = (char) character;
                } catch (IOException e){
                    e.printStackTrace();
                }
                Token token = new Token("COMMA",tokenContent,lineno);
                tokenList.add(token);
            }
            else if(ch == '('){
                tokenContent.append(ch);
                try{
                    character = fileReader.read();
                    ch = (char) character;
                } catch (IOException e){
                    e.printStackTrace();
                }
                Token token = new Token("LPARENT",tokenContent,lineno);
                tokenList.add(token);
            }
            else if(ch == ')'){
                tokenContent.append(ch);
                try{
                    character = fileReader.read();
                    ch = (char) character;
                } catch (IOException e){
                    e.printStackTrace();
                }
                Token token = new Token("RPARENT",tokenContent,lineno);
                tokenList.add(token);
            }
            else if(ch == '['){
                tokenContent.append(ch);
                try{
                    character = fileReader.read();
                    ch = (char) character;
                } catch (IOException e){
                    e.printStackTrace();
                }
                Token token = new Token("LBRACK",tokenContent,lineno);
                tokenList.add(token);
            }
            else if(ch == ']'){
                tokenContent.append(ch);
                try{
                    character = fileReader.read();
                    ch = (char) character;
                } catch (IOException e){
                    e.printStackTrace();
                }
                Token token = new Token("RBRACK",tokenContent,lineno);
                tokenList.add(token);
            }
            else if(ch == '{'){
                tokenContent.append(ch);
                try{
                    character = fileReader.read();
                    ch = (char) character;
                } catch (IOException e){
                    e.printStackTrace();
                }
                Token token = new Token("LBRACE",tokenContent,lineno);
                tokenList.add(token);
            }
            else if(ch == '}'){
                tokenContent.append(ch);
                try{
                    character = fileReader.read();
                    ch = (char) character;
                } catch (IOException e){
                    e.printStackTrace();
                }
                Token token = new Token("RBRACE",tokenContent,lineno);
                tokenList.add(token);
            }
        }
    }

}
