package frontend;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashMap;


public class Lexer {
    //给定的输入是源程序字符串，给出来的是一个token数组是想要得到的结果,对字符串的分析应该是在Lexer中进行
    char curChar;//当前指向的字符
    String input;//源程序字符串
    int curPos = 0;//当前字符串位置指针
    ArrayList<Token> tokens;//所有的词法分析得到的token,添加到整个大数组中
    ArrayList<Token> total ;
    int curLine = 1;//当前分析到的行数
    StringBuilder token = new StringBuilder();//当前已经读入的字符串
    HashMap<String,LexType> reserve;//用来存储保留字及相应的记忆符
    ArrayList<Error> errors;
    Token curToken;//存储当前的token
    int flag = 0;
    //int x_line = 1;
    public Lexer(String input,ArrayList<Token> tokens,ArrayList<Error> errors,ArrayList<Token> total){
        this.input = input;
        this.tokens = tokens;
        this.errors = errors;
        this.total = total;
        reserve = new HashMap<>(){
            {
                put("main",LexType.MAINTK);
                put("const",LexType.CONSTTK);
                put("int",LexType.INTTK);
                put("char",LexType.CHARTK);
                put("break",LexType.BREAKTK);
                put("continue",LexType.CONTINUETK);
                put("if",LexType.IFTK);
                put("else",LexType.ELSETK);
                put("for",LexType.FORTK);
                put("getint",LexType.GETINTTK);
                put("getchar",LexType.GETCHARTK);
                put("printf",LexType.PRINTFTK);
                put("return",LexType.RETURNTK);
                put("void",LexType.VOIDTK);
            }
        };//查找保留字的表
    }
    public void next(){
        //x_line = curLine;
        //调用一次next会返回一个最小分析单元
        clearToken();//清除token中存储的字符串

        getChar();

        while((curChar == ' '|| curChar == '\n' || curChar == '\t')&&curPos<input.length()){
            if(curChar == '\n'){
                curLine += 1;
            }
            getChar();
        }

        if(isNonDigit(curChar)){
            //该if识别标识符和保留字
            catToken();
            getChar();
            if(flag == 1){
                Token tok;
                if(reserve.containsKey(token.toString())){
                    //说明是保留字
                    tok = new Token(token.toString(), reserve.get(token.toString()), curLine);
                }else{//说明是标识符
                    tok = new Token(token.toString(), LexType.IDENFR, curLine);
                }
                tokens.add(tok);//完成了一个最小分析单元的分析
                total.add(tok);curToken = tok;
                flag = 0;
                return;
            }
            while(isNonDigit(curChar)||Character.isDigit(curChar)){
                catToken();
                getChar();
                if(flag == 1){
                    Token tok;
                    if(reserve.containsKey(token.toString())){
                        //说明是保留字
                        tok = new Token(token.toString(), reserve.get(token.toString()), curLine);
                    }else{//说明是标识符
                        tok = new Token(token.toString(), LexType.IDENFR, curLine);
                    }
                    tokens.add(tok);//完成了一个最小分析单元的分析
                    curToken = tok;
                    total.add(tok);
                    flag = 0;
                    return;
                }
            }//当从while中跳出来的时候说明此时的char字符不是数字字母或下划线
            retract();
            //这个时候无法区别是标识符还是保留字

            Token tok;
            if(reserve.containsKey(token.toString())){
                //说明是保留字
                tok = new Token(token.toString(), reserve.get(token.toString()), curLine);
            }else{//说明是标识符
                tok = new Token(token.toString(), LexType.IDENFR, curLine);
            }
            tokens.add(tok);//完成了一个最小分析单元的分析
            curToken = tok;
            total.add(tok);
        }else if(Character.isDigit(curChar)){
            //该if识别数字常量
            while(Character.isDigit(curChar)){
                catToken();
                getChar();
                if(flag == 1){
                    Token tok = new Token(token.toString(), LexType.INTCON, curLine);
                    tokens.add(tok);
                    curToken = tok;
                    total.add(tok);
                    flag = 0;
                    return;
                }
            }
            retract();
            Token tok = new Token(token.toString(), LexType.INTCON, curLine);
            tokens.add(tok);
            curToken = tok;
            total.add(tok);
        }else if(curChar == '"'){
            //该if识别字符串常量
            catToken();
            getChar();
            if(flag == 1){
                flag = 0;
                return;
            }
            while(curChar!='"'){
                catToken();
                getChar();
                if(flag == 1){
                    flag = 0;
                    return;
                }
            }
            catToken();//把“连接上

            Token tok = new Token(token.toString(), LexType.STRCON, curLine);
            tokens.add(tok);
            curToken = tok;
            total.add(tok);
        }else if(curChar == '\''){
            //该if识别字符常量
            catToken();
            getChar();
            if(flag == 1){
                flag = 0;
                return;
            }
            if(curChar == '\\'){
                //说明是转义字符
                catToken();
                getChar();
                catToken();
                getChar();
                if(flag == 1){
                    flag = 0;
                    return;
                }
            }else {
                //说明是普通的字符常量
                catToken();
                getChar();
                if(flag == 1){
                    flag = 0;
                    return;
                }
            }

            catToken();

            Token tok = new Token(token.toString(), LexType.CHRCON, curLine);
            tokens.add(tok);
            curToken = tok;
            total.add(tok);
        }else if(curChar == '!'){
            catToken();
            getChar();
            if(flag == 1){
                flag = 0;
                return;
            }
            Token tok;
            if(curChar == '='){
                catToken();
                tok = new Token(token.toString(), LexType.NEQ, curLine);
            }else{
                retract();
                tok = new Token(token.toString(), LexType.NOT, curLine);
            }
            tokens.add(tok);
            curToken = tok;
            total.add(tok);
        }else if(curChar == '='){
            catToken();
            getChar();
            if(flag == 1){
                flag = 0;
                return;
            }
            Token tok;
            if(curChar == '='){
                catToken();
                tok = new Token(token.toString(), LexType.EQL, curLine);
            }else{
                retract();
                tok = new Token(token.toString(), LexType.ASSIGN, curLine);
            }
            tokens.add(tok);
            curToken = tok;
            total.add(tok);
        }else if(curChar == '<'){
            catToken();
            getChar();
            if(flag == 1){
                flag = 0;
                return;
            }
            Token tok;
            if(curChar == '='){
                catToken();
                tok = new Token(token.toString(), LexType.LEQ, curLine);
            }else{
                retract();
                tok = new Token(token.toString(), LexType.LSS, curLine);
            }
            tokens.add(tok);
            curToken = tok;
            total.add(tok);
        }else if(curChar == '>'){
            catToken();
            getChar();
            if(flag == 1){
                flag = 0;
                return;
            }
            Token tok;
            if(curChar == '='){
                catToken();
                tok = new Token(token.toString(), LexType.GEQ, curLine);
            }else{
                retract();
                tok = new Token(token.toString(), LexType.GRE, curLine);
            }
            tokens.add(tok);
            curToken = tok;
            total.add(tok);
        }else if(curChar == '%'){
            catToken();
            Token tok = new Token(token.toString(),LexType.MOD,curLine);
            tokens.add(tok);curToken = tok;
            total.add(tok);
        }else if(curChar == '*'){
            catToken();
            Token tok = new Token(token.toString(),LexType.MULT,curLine);
            tokens.add(tok);curToken = tok;
            total.add(tok);
        }else if(curChar == '+'){
            catToken();
            Token tok = new Token(token.toString(), LexType.PLUS, curLine);
            tokens.add(tok);curToken = tok;
            total.add(tok);
        }else if(curChar == '-'){
            catToken();
            Token tok = new Token(token.toString(), LexType.MINU, curLine);
            tokens.add(tok);curToken = tok;
            total.add(tok);
        }else if(curChar == ';'){
            catToken();
            Token tok = new Token(token.toString(), LexType.SEMICN, curLine);
            tokens.add(tok);curToken = tok;
            total.add(tok);
        }else if(curChar == ','){
            catToken();
            Token tok = new Token(token.toString(), LexType.COMMA, curLine);
            tokens.add(tok);curToken = tok;
            total.add(tok);
        }else if(curChar == '('){
            catToken();
            Token tok = new Token(token.toString(), LexType.LPARENT, curLine);
            tokens.add(tok);curToken = tok;
            total.add(tok);
        }else if(curChar == ')'){
            catToken();
            Token tok = new Token(token.toString(), LexType.RPARENT, curLine);
            tokens.add(tok);curToken = tok;
            total.add(tok);
        }else if(curChar == '['){
            catToken();
            Token tok = new Token(token.toString(), LexType.LBRACK, curLine);
            tokens.add(tok);curToken = tok;
            total.add(tok);
        }else if(curChar == ']'){
            catToken();
            Token tok = new Token(token.toString(), LexType.RBRACK, curLine);
            tokens.add(tok);curToken = tok;
            total.add(tok);
        }else if(curChar == '}'){
            catToken();
            Token tok = new Token(token.toString(), LexType.RBRACE, curLine);
            tokens.add(tok);curToken = tok;
            total.add(tok);
        }else if(curChar == '{'){
            catToken();
            Token tok = new Token(token.toString(), LexType.LBRACE, curLine);
            tokens.add(tok);curToken = tok;
            total.add(tok);
        }else if(curChar == '/'){
            //用来处理除法以及注释的问题
            catToken();//是为了除法做准备的
            getChar();
            if(flag == 1){
                flag = 0;
                return;
            }
            if(curChar == '/'){
                //单行注释
                getChar();
                if(flag == 1){
                    flag = 0;
                    return;
                }
                while(curChar != '\n'){
                    getChar();
                    if(flag == 1){
                        flag = 0;
                        return;
                    }
                }
                curLine++;
                next();
            }else if(curChar == '*'){
                //跨行注释
                getChar();
                if(flag == 1){
                    flag = 0;
                    return;
                }
                while(true){
                    if(curChar == '\n'){
                        curLine++;
                    }
                    if(curChar == '*'){
                        getChar();
                        if(flag == 1){
                            flag = 0;
                            return;
                        }
                        if(curChar == '/'){
                            break;
                        }else{
                            retract();
                        }
                    }
                    getChar();
                    if(flag == 1){
                        flag = 0;
                        return;
                    }
                }//出来之后说明到*了
                next();
            }else{
                //非*非/的其他字符
                retract();
                Token tok = new Token(token.toString(),LexType.DIV,curLine);
                tokens.add(tok);curToken = tok;
                total.add(tok);
            }
        }else if(curChar == '&'){
            catToken();
            getChar();
            if(flag == 1){
                flag = 0;
                return;
            }
            if(curChar == '&'){
                catToken();
                if(flag == 1){
                    flag = 0;
                    return;
                }
                Token tok = new Token(token.toString(),LexType.AND,curLine);
                tokens.add(tok);curToken = tok;
                total.add(tok);
            }else {
                //error();
                Error error = new Error(curLine,'a');
                errors.add(error);

                token.append("&");

                Token tok = new Token("&",LexType.AND,curLine);
                tokens.add(tok);curToken = tok;
                total.add(tok);

                retract();

            }
        }else if(curChar == '|'){
            catToken();
            getChar();
            if(flag == 1){
                flag = 0;
                return;
            }
            if(curChar == '|'){
                catToken();
                if(flag == 1){
                    flag = 0;
                    return;
                }
                Token tok = new Token(token.toString(),LexType.OR,curLine);
                tokens.add(tok);curToken = tok;
                total.add(tok);
            }else {
               // error();
                Error error = new Error(curLine,'a');
                errors.add(error);

                token.append("|");

                Token tok = new Token("||",LexType.AND,curLine);
                tokens.add(tok);curToken = tok;
                total.add(tok);
                retract();

            }
        }else{
            catToken();
            tokens.add(new Token("hhh",LexType.AND,curLine));
            total.add(new Token("hhh",LexType.AND,curLine));
        }
    }//词法分析的关键程序
    //public int getX_line(){
        //return  x_line;
    //}
    public boolean isNonDigit(char c){
        return c == '_' || Character.isLetter(c);
    }//判断是否为下划线或大小写字母
    public void catToken(){
        token.append(curChar);
    }//把char中的字符和token中的字符相连
    public void getChar(){
        if(curPos == input.length()){
            flag = 1;
        }else{
            curChar = input.charAt(curPos);
            curPos += 1;
        }

    }//读字符过程，每调用一次读进一个字符放在char中并将指针指向下一个字符
    public void retract(){
        curPos--;
        if(input.charAt(curPos-1) == '\n'){
            curLine = curLine -1;
            curChar = '\n';
        }
    }
    public void clearToken(){
        //清空字符串token
        token.setLength(0);
    }
    public int getCurLine() {
        return curLine;
    }

    public StringBuilder getToken() {
        return token;
    }
    public StringBuilder prePreRead(){
        char tmpChar = curChar;
        int tmpCurLine = curLine;
        int tmpCurPos = curPos;
        StringBuilder tmpToken = token;
        int tmpFlag = flag;
        int tmpSize = errors.size();

        next();
        next();

        StringBuilder s = token;

        tokens.remove(tokens.size()-1);
        tokens.remove(tokens.size() -1);//删去最后添加的两个


        total.remove(total.size()-1);
        total.remove(total.size() -1);//删去最后添加的两个

        errors.subList(tmpSize,errors.size()).clear();;
        curChar = tmpChar;
        curLine = tmpCurLine;
        curPos = tmpCurPos;
        token = tmpToken;
        flag = tmpFlag;
        return s;
    }
    public StringBuilder preRead(){
        char tmpChar = curChar;
        int tmpCurLine = curLine;
        int tmpCurPos = curPos;
        StringBuilder tmpToken = new StringBuilder(token.toString());
        int tmpFlag = flag;
        int tmpSize = errors.size();

        next();

        StringBuilder s = new StringBuilder(token.toString());


        tokens.remove(tokens.size()-1);

        total.remove(total.size()-1);
        errors.subList(tmpSize,errors.size()).clear();;
        curChar = tmpChar;
        curLine = tmpCurLine;
        curPos = tmpCurPos;
        token = tmpToken;
        flag = tmpFlag;
        return s;

    }
    public int special(){
        int s = 0;
        for(int i = tokens.size()-2;i>=0;i=i-1){
            if(tokens.get(i).getLexType()!=LexType.FAKE){
                s= tokens.get(i).getLine();
                break;
            }
        }
        return  s;
    }
    public void reSet(char tmpChar,int tmpCurLine,int tmpCurPos,StringBuilder tmpToken,int tmpFlag){//调整传入的数值，恢复lexer的所有属性，由于在假解析的过程中还在发生只指针的移动，所以为了保险起见需要恢复lexer的所有属性
        curChar = tmpChar;
        curLine = tmpCurLine;
        curPos = tmpCurPos;
        token = tmpToken;
        flag = tmpFlag;
    }

    public int getCurPos() {
        return curPos;
    }

    public int getFlag() {
        return flag;
    }

    public char getCurChar() {
        return curChar;
    }

    public Token getCurToken() {
        return curToken;
    }
}
