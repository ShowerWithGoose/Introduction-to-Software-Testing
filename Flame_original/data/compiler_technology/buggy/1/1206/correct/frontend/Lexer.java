package frontend;

import error.error;
import error.errorList;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PushbackReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

/**
 * @author
 * @Description:
 * @date 2024/9/23 10:19
 */
public class Lexer {
    public String filesrc;
    public ArrayList<token> tokens;
    public int lineno;
    public StreamReader stream;//模拟c++中的输入流
    public SymbolTable symbolTable;//符号表
    private Map<String, token.Type> keywords = new HashMap<String, token.Type>() {{
        put("main", token.Type.MAINTK);
        put("const", token.Type.CONSTTK);
        put("int", token.Type.INTTK);
        put("break", token.Type.BREAKTK);
        put("continue", token.Type.CONTINUETK);
        put("if", token.Type.IFTK);
        put("else", token.Type.ELSETK);
        put("getint", token.Type.GETINTTK);
        put("printf", token.Type.PRINTFTK);
        put("return", token.Type.RETURNTK);
        put("void", token.Type.VOIDTK);
        put("char",token.Type.CHARTK);
        put("getchar",token.Type.GETCHARTK);
        put("for",token.Type.FORTK);
    }};
    public Lexer(String src){
        this.lineno=1;
        this.filesrc=src;
        this.tokens=new ArrayList<>();
        try {
            this.stream=new StreamReader(src);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    public void tokenize(){
        token token;
        while((token=next())!=null){
            if(token.type!=frontend.token.Type.disable)this.tokens.add(token);
        }
    }
    public void read() {

    }
    public token next(){//得到下一个单词
        StringBuilder word=new StringBuilder();
        Character ch;
        try {
            ch=this.stream.get();
            if(ch==null)return null;
            // 跳过空白字符
            while (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r') {
                if (ch == '\n') {
                    this.lineno++;
                }
                ch = this.stream.get();
                if (ch == null) return null;
            }
            // 处理注释
            if(ch=='/'){
                Character cp=this.stream.get();
                if(cp!=null&&cp=='/'){// //类型注释
                    while(true){
                        cp=this.stream.get();
                        if(cp==null)break;
                        if(cp=='\n') {
                            this.lineno++;
                            break;
                        }
                    }
                    return new token(token.Type.disable,"comment",this.lineno-1);
                }else if(cp!=null&&cp=='*'){// /*类型注释
                    cp=this.stream.get();
                    while(true){
                        if (cp == null) return null;
                        if(cp=='\n')this.lineno++;
                        if(cp=='*'){
                            cp=this.stream.get();
                            if(cp=='/')break;
                            this.stream.unget(cp);

                        }
                        cp=this.stream.get();
                    }
                    ch=cp;
                    if (ch == null) return null;
                    return new token(token.Type.disable,"comment",this.lineno);
                }else {//不为注释
                    this.stream.unget(cp);
                }
            }

            if (ch == '[') {//解析符号
                return new token(token.Type.LBRACK, "[",this.lineno);
            } else if (ch == ']') {
                return new token(token.Type.RBRACK, "]",this.lineno);
            } else if (ch == '{') {
                return new token(token.Type.LBRACE, "{",this.lineno);
            } else if (ch == '}') {
                return new token(token.Type.RBRACE, "}",this.lineno);
            } else if (ch == ',') {
                return new token(token.Type.COMMA, ",",this.lineno);
            } else if (ch == ';') {
                return new token(token.Type.SEMICN, ";",this.lineno);
            } else if (ch == '=') {
                ch=stream.get();
                if(ch!=null&&ch=='=')return new token(token.Type.EQL, "==",this.lineno);
                else {
                    stream.unget(ch);
                    return new token(token.Type.ASSIGN, "=",this.lineno);
                }
            } else if (ch == '(') {
                return new token(token.Type.LPARENT, "(",this.lineno);
            } else if (ch == ')') {
                return new token(token.Type.RPARENT, ")",this.lineno);
            } else if (ch == '!'){
                ch=stream.get();
                if(ch!=null&&ch=='=')return new token(token.Type.NEQ, "!=",this.lineno);
                else {
                    stream.unget(ch);
                    return new token(token.Type.NOT, "!",this.lineno);
                }
            } else if (ch == '+'){
                return new token(token.Type.PLUS, "+",this.lineno);
            } else if (ch == '-'){
                return new token(token.Type.MINU, "-",this.lineno);
            } else if (ch == '*'){
                return new token(token.Type.MULT, "*",this.lineno);
            } else if (ch == '/'){
                return new token(token.Type.DIV, "/",this.lineno);
            } else if (ch == '%'){
                return new token(token.Type.MOD, "%",this.lineno);
            } else if (ch == '<'){
                ch=stream.get();
                if(ch!=null&&ch=='=')return new token(token.Type.LEQ, "<=",this.lineno);
                else {
                    if(ch!=null)stream.unget(ch);
                    return new token(token.Type.LSS, "<",this.lineno);
                }
            } else if (ch == '>'){
                ch=stream.get();
                if(ch!=null&&ch=='=')return new token(token.Type.GEQ, ">=",this.lineno);
                else {
                    if(ch!=null)stream.unget(ch);
                    return new token(token.Type.GRE, ">",this.lineno);
                }
            }
            else if(ch=='&') {
                word.append(ch);
                ch = stream.get();
                if(ch!=null&&ch=='&'){
                    return new token(token.Type.AND,"&&",this.lineno);
                }else {
                    errorList.getList().addError(new error(error.wrongType.a,this.lineno));
                    return new token(token.Type.AND,"&",this.lineno,true, token.wrongType.a);
                }
            }else if(ch=='|') {//解析|
                word.append(ch);
                ch = stream.get();
                if(ch!=null&&ch=='|'){
                    return new token(token.Type.OR,"||",this.lineno);
                }else {
                    errorList.getList().addError(new error(error.wrongType.a,this.lineno));
                    return new token(token.Type.OR,"|",this.lineno,true, token.wrongType.a);
                }
            }
            if(Character.isLetter(ch)||ch=='_'){//判断是否为标识符
                word.append(ch);
                ch = stream.get();

                while (ch!=null&&(Character.isLetter(ch)||Character.isDigit(ch)||ch=='_')) {
                    word.append(ch);
                    ch = stream.get();
                }
                if(ch!=null)stream.unget(ch);
                return new token(keywords.getOrDefault(word.toString(), token.Type.IDENFR),word.toString(), this.lineno, false,token.wrongType.none);
            }
            if(ch=='\"'){//判断是否为字符串
                word.append(ch);
                ch=stream.get();
                word.append(ch);
                while(ch!=null&&ch!='\"') {
                    ch = this.stream.get();
                    word.append(ch);
                }//此时ch为"
                return new token(token.Type.STRCON, word.toString(),this.lineno);
            }
            if(ch=='\''){//判断是否为字符
                word.append(ch);
                ch=stream.get();
                word.append(ch);
                if(ch!=null&&ch=='\\'){//遇到转义字符
                    ch=stream.get();
                    word.append(ch);
                    ch=stream.get();
                    word.append(ch);
                }
                while(ch!=null&&ch!='\'') {
                    ch = this.stream.get();
                    word.append(ch);
                }//此时ch为'
                return new token(token.Type.CHRCON, word.toString(),this.lineno);
            }
            if(Character.isDigit(ch)){//遇到数字
                word.append(ch);
                ch = stream.get();
                while (ch!=null&&(Character.isDigit(ch)||ch=='.')) {
                    word.append(ch);
                    ch = stream.get();

                }
                if(ch!=null)stream.unget(ch);
                return new token(token.Type.INTCON, word.toString(),this.lineno);
            }


            if(ch==null)return null;


        } catch (IOException e) {
            e.printStackTrace();
        }
        return null;
    }
    public void lookupWrong(){//查找错误记录，语法分析
        int i=0;
        int len=this.tokens.size();
        SymbolTable table=this.symbolTable;
        for(i=0;i<len;i++){
            //全局作用域
            while(this.tokens.get(i).type!= token.Type.MAINTK){
                //变量定义
                //const变量
                if(this.tokens.get(i).type== token.Type.CONSTTK){
                    while(this.tokens.get(i).type!= token.Type.SEMICN){//不为分号表示语句未结束,还有没有分号的情况
                        if(this.tokens.get(i).type == token.Type.IDENFR){//可能定义多个变量，等号两侧都有可能是变量名（需要区分）
                            if(this.tokens.get(i+1).type == token.Type.ASSIGN){//等号左侧
                                //已定义
                                if(!table.define(this.tokens.get(i).content)){
                                    this.tokens.get(i).wrong=true;
                                    this.tokens.get(i).wType= token.wrongType.b;
                                }
                            }else if(this.tokens.get(i-1).type == token.Type.ASSIGN){//等号右侧
                                //找不到该定义
                                if(!table.lookup(this.tokens.get(i).content)){//变量未定义
                                    this.tokens.get(i).wrong=true;
                                    this.tokens.get(i).wType= token.wrongType.c;
                                }
                            }
                        }
                        i++;
                    }
                }
                //普通变量

                //函数变量
                //函数作用域
                i++;
            }
            //a类错误已实现
            //b
            //m
            if(this.tokens.get(i).type==token.Type.CONTINUETK||this.tokens.get(i).type==token.Type.BREAKTK){

            }

        }
    }
}
class SymbolTable {//符号表记录作用域等相关信息
    private final Stack<Map<String, String>> scopes;//作用域栈
    public SymbolTable() {
        scopes = new Stack<>();
        enterScope(); // 初始化时进入全局作用域
    }
    public void enterScope() {
        scopes.push(new HashMap<>()); // 创建新作用域
    }
    public void exitScope() {
        if (!scopes.isEmpty()) {
            scopes.pop(); // 退出当前作用域
        }
    }
    public boolean define(String name) {
        Map<String, String> currentScope = scopes.peek();//得到当前作用域的符号表
        if (currentScope.containsKey(name)) {
            return false; // 重复定义
        }
        currentScope.put(name, "defined"); // 可以存储更多信息
        return true;
    }
    public boolean lookup(String name) {//查找是否使用了未定义的变量
        for (int i = scopes.size() - 1; i >= 0; i--) {
            if (scopes.get(i).containsKey(name)) {
                return true; // 找到标识符
            }
        }
        return false; // 未找到
    }
}
class StreamReader {
    private PushbackReader reader;

    public StreamReader(String filePath) throws IOException {
        this.reader = new PushbackReader(new BufferedReader(new FileReader(filePath)));

    }
    public Character get() throws IOException {
        int charRead = reader.read();

        return charRead != -1 ? (char) charRead : null; // 返回字符或null
    }
    public void  unget(Character c) throws  IOException {
        reader.unread(c);
    }

}