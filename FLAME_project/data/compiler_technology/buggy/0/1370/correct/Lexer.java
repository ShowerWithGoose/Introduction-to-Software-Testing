import java.io.FileNotFoundException;
import java.util.HashMap;

public class Lexer {
    private Character ch;
    private HashMap<String,TokenType> chTable = new HashMap<>();
    private GetChar getChar;

    private int lineno = 1;

    private boolean workDone = false;
    public Lexer(String filepath) throws FileNotFoundException {
        this.getChar = new GetChar(filepath);
        for(TokenType t:TokenType.values()){
            chTable.put(t.valueString(),t);  //初始化符号表
        }
    }

    public void lexer(){
        while(!workDone){
            getATokenDear();
        }
    }

    public Token getATokenDear(){
        ch = getChar.getAChar();
        if(ch == null){//文件结束了吗
           workOff();
           return null;
        }
        while(ch == ' '|| ch == '\0'){//跳过不想要的字符
            ch = getChar.getAChar();
            if(ch == null){
                workOff();
                return null;
            }
        }
        if(ch == '\n'){//下一行了
            this.lineno++;
            ch = getChar.getAChar();
            if(ch == null){
                workOff();
                return null;
            }
        }
        if(Character.isLetter(ch) || ch == '_'){
            String letter = "" + ch;
            ch = getChar.getAChar();
            if(ch == null){
                workOff();
                return produceLetter(letter);
            }
            while(Character.isLetter(ch)||ch == '_'||Character.isDigit(ch)){
                letter = letter + ch;
                ch = getChar.getAChar();
                if(ch == null){
                    workOff();
                    return produceLetter(letter);
                }
            }
            getChar.unGetAChar();
            return produceLetter(letter);
        }else if(Character.isDigit(ch)){
            String num = ""+ch;
            ch = getChar.getAChar();
            if(ch == null){
                workOff();
                return produceNum(num);
            }
            while(Character.isDigit(ch)){
                num = num + ch;
                ch = getChar.getAChar();
                if(ch == null){
                    workOff();
                    return produceNum(num);
                }
            }
            getChar.unGetAChar();
            return produceNum(num);
        }else if(ch == '/'){
            ch = getChar.getAChar();
            if(ch == null){
                workOff();
                return specialC(""+'/');
            }
            if(ch == '/'){
                while(ch!='\n'){
                    ch = getChar.getAChar();
                    if(ch == null){
                        workOff();
                        return null;
                    }
                }
                getChar.unGetAChar();
                return null;
            }
            else if(ch == '*'){
                boolean flag1 = false;
                while(true){
                    ch = getChar.getAChar();
                    if(ch == null){
                        workOff();
                        return null;
                    }
                    if(ch == '\n'){
                        lineno++;
                    }
                    if(flag1){
                        if(ch == '/'){
                            break;
                        }else{
                            flag1 = false;
                        }
                    }
                    if(ch == '*'){
                        flag1 = true;
                    }
                }
                return null;
            }
            else{
                getChar.unGetAChar();
                return specialC(""+'/');
            }
        }else if(ch == '\''){
            String chara = ""+'\'';
            ch = getChar.getAChar();
            if(ch == null){
                workOff();
                return null;
            }
            while(ch!='\''){
                chara = chara + ch;
                if(ch == '\\'){//如果遇到转义
                    ch = getChar.getAChar();//把转义的字符加上
                    if(ch == null){
                        workOff();
                        return null;
                    }
                    chara = chara + ch;
                }
                ch = getChar.getAChar();
                if(ch == null){
                    workOff();
                    return null;
                }
            }
            chara = chara + ch;
            return produceChar(chara);
        }else if(ch == '\"'){
            String str = ""+'\"';
            ch = getChar.getAChar();
            if(ch == null){
                workOff();
                return null;
            }
            while(ch!='\"'){
                str = str + ch;
                if(ch == '\\'){//如果遇到转义
                    ch = getChar.getAChar();//把转义的字符加上
                    if(ch == null){
                        workOff();
                        return null;
                    }
                    str = str + ch;
                }
                ch = getChar.getAChar();
                if(ch == null){
                    workOff();
                    return null;
                }
            }
            str = str + ch;
            return produceStr(str);
        } else if(ch == '<' || ch == '>' ||ch == '=' || ch == '!'){
            String c = ""+ch;
            ch = getChar.getAChar();
            if(ch == null){
                workOff();
                return specialC(c);
            }
            if(ch == '='){
                c = c+'=';
                return specialC(c);
            }else{
                getChar.unGetAChar();
                return specialC(c);
            }
        }else if(ch == '&'){
            String c = ""+ch;
            ch = getChar.getAChar();
            if(ch == null){
                workOff();
                return specialC(c);
            }
            if(ch == '&'){
                c = c+'&';
                return specialC(c);
            }else{
                sendError(ErrorType.a,lineno);
                getChar.unGetAChar();
                return null;
            }
        }else if(ch == '|'){
            String c = ""+ch;
            ch = getChar.getAChar();
            if(ch == null){
                workOff();
                return specialC(c);
            }
            if(ch == '|'){
                c = c+'|';
                return specialC(c);
            }else{
                sendError(ErrorType.a,lineno);
                getChar.unGetAChar();
                return null;
            }
        }else{
            return specialC(""+ch);
        }


    }

    public Token produceLetter(String letter){
        Token token;
        if(chTable.containsKey(letter)){
            TokenType tokenType = chTable.get(letter);
            String message = tokenType.toString() +' '+ letter + '\n';
            WriteIntoF.getInstance().writeToFile(true,message);
            token = new Token(tokenType,letter,lineno);
        }else{
            String message = TokenType.IDENFR.toString() +' '+ letter + '\n';
            WriteIntoF.getInstance().writeToFile(true,message);
            token = new Token(TokenType.IDENFR,letter,lineno);
        }
        return token;
    }

    public Token produceChar(String chara){
        Token token;
        String message = TokenType.CHRCON.toString() +' '+ chara + '\n';
        WriteIntoF.getInstance().writeToFile(true,message);
        token = new Token(TokenType.CHRCON,chara,lineno);
        return token;
    }

    public Token produceStr(String str){
        Token token;
        String message = TokenType.STRCON.toString() +' '+ str + '\n';
        WriteIntoF.getInstance().writeToFile(true,message);
        token = new Token(TokenType.STRCON,str,lineno);
        return token;
    }

    public Token produceNum(String num){
        Token token;
        String message = TokenType.INTCON.toString() +' '+ num + '\n';
        WriteIntoF.getInstance().writeToFile(true,message);
        token = new Token(TokenType.INTCON,num,lineno);
        return token;
    }

    public Token specialC(String c){
        Token token = null;
        if(chTable.containsKey(c)){
            TokenType tokenType = chTable.get(c);
            String message = tokenType.toString() +' '+ c + '\n';
            WriteIntoF.getInstance().writeToFile(true,message);
            token = new Token(tokenType,c,lineno);
        }else{
            System.out.println("Lexer.255 Warning: there comes sth. we don't know how to deal with: " + c +'\n');
        }
        return token;
    }

    public void workOff(){
        this.workDone = true;
    }

    public void sendError(ErrorType errorType,int errorline){
        String errorm = "" + getChar.getLineno() + ' ' +errorType.toString() +  '\n';
        WriteIntoF.getInstance().writeToFile(false,errorm);
    }

}
