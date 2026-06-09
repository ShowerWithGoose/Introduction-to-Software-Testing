package FrontEnd;

import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import static java.lang.Boolean.FALSE;
import static java.lang.Boolean.TRUE;

public class LexicalAnalyzer {
    private static HashMap<String, String> reserveCodeMap=new HashMap<>();
    ArrayList<Token> resultList=new ArrayList<>();
    public void printWordResult() {
        try (PrintWriter writer = new PrintWriter(new FileWriter("lexer.txt"))) {
            for (Token token : resultList) {
                writer.println(token.getTokenCode() + " " + token.getOringinStr());
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // 静态初始化保留字表
    static {
        reserveCodeMap.put("main","MAINTK");
        reserveCodeMap.put("const","CONSTTK");
        reserveCodeMap.put("int","INTTK");
        reserveCodeMap.put("char","CHARTK");
        reserveCodeMap.put("break","BREAKTK");
        reserveCodeMap.put("continue","CONTINUETK");
        reserveCodeMap.put("if","IFTK");
        reserveCodeMap.put("else","ELSETK");
        reserveCodeMap.put("for","FORTK");
        reserveCodeMap.put("getint","GETINTTK");
        reserveCodeMap.put("getchar","GETCHARTK");
        reserveCodeMap.put("printf","PRINTFTK");
        reserveCodeMap.put("return","RETURNTK");
        reserveCodeMap.put("void","VOIDTK");
    }
    public boolean isReservedWord(String word) {
        return reserveCodeMap.containsKey(word);
    }
    private char currentChar;
    private StringBuilder token=new StringBuilder();
    private int lineNum=1;
    private int index;
    private String PROGRAM="";
    private void  clearToken()
    {
        this.token.setLength(0);
    }
    private void catToken()
    {
        this.token.append(currentChar);
    }
    private void error() {
        try (PrintWriter writer = new PrintWriter(new FileWriter("error.txt", true))) {  // "true" 表示追加内容到文件
            writer.println(lineNum + " " + "a");
            /*用这种方式去推出*/
            this.index++;
        } catch (IOException e) {
            e.printStackTrace();  // 捕获异常并打印
        }
        return;
    }
    private boolean isAlphabet(char ch) /*判断是否是大小写字母*/
    {
        if((ch>='a' && ch<='z')||(ch>='A'&&ch<='Z')){
            return TRUE;
        }
        return FALSE;
    }
    private boolean isDigit(char ch)
    {
        if(ch>='0'&&ch<='9')
        {
            return TRUE;
        }
        return FALSE;
    }
    public void getSym() throws IOException {
        /*这个函数读取完之后 得把东西放到token数组里边返回*/
        this.clearToken();
        this.currentChar= this.PROGRAM.charAt(index);
        /*跳过空白符*/
        int blankFlag=0;
        while(this.currentChar==' '||this.currentChar=='\t'||this.currentChar=='\n')
        {
            blankFlag=1;
            this.currentChar=PROGRAM.charAt(index);
            if(currentChar=='\n')
            {
                this.lineNum++;
            }
            index++;
            if(index>=PROGRAM.length())
            {
                return;
            }
        }
        /*这个index指向第一个非空白符号*/
        if(blankFlag==1) {
            index--;
        }
        if(isAlphabet(currentChar)||currentChar=='_')
        {
            /*这个里边要判断是保留字还是标识符*/
            while(isAlphabet(currentChar)||isDigit(currentChar)||currentChar=='_')
            {
                catToken();
                this.index++;
                currentChar=PROGRAM.charAt(index);
            }

            //the total string is compelete
            boolean resultValue= isReservedWord(token.toString());
            if(resultValue==TRUE)
            {
                /*确定保留值的符号*/
                Token NewToken=new Token(token.toString(),this.lineNum,token.toString());
                resultList.add(NewToken);
            }
            else
            {
                 Token NewToken=new Token(token.toString(),this.lineNum,"Ident");
                 resultList.add(NewToken);
            }
            return ;
        }

        /*这一段跳过注释 或者说除号*/
        else if (currentChar == '/') {
            // 判断是单行注释还是多行注释
            currentChar = PROGRAM.charAt(index + 1);
            if (currentChar == '/') {
                // 单行注释，跳过直到行末
                index+=2;
                currentChar=PROGRAM.charAt(index);
                while (currentChar != '\n' && index < PROGRAM.length()) {
                    index++;
                    currentChar = PROGRAM.charAt(index);
                }
                //出来的时候index已经指在下一行了
                return;
            }
            else if (currentChar == '*') {
                // 多行注释，跳过直到遇到 "*/"
                index += 2; // 跳过 "/*"
                while (index < PROGRAM.length()) {
                    currentChar = PROGRAM.charAt(index);
                    if (currentChar == '*' && PROGRAM.charAt(index + 1) == '/') {
                        index += 2; // 跳过 "*/"
                        break;
                    }
                    else if(currentChar=='\n')
                    {
                        lineNum++;
                    }
                    index++;
                }
                // 跳过完多行注释后，继续处理下一个字符
                return;
            }
            /*那就不是注释而是纯粹的除号了*/
            else {
                Token newToken = new Token("/", this.lineNum, "/");
                resultList.add(newToken);
                index++;
                return;
            }
        }

        /*运算符*/
        else if(currentChar=='!')
        {
            if(PROGRAM.charAt(index+1)=='=')
            {
                index+=2;
                Token newToken= new Token("!=",this.lineNum,"!=");
                resultList.add(newToken);
                return;
            }
            else {
                Token newToken = new Token("!", this.lineNum, "!");
                resultList.add(newToken);
                index++;
                return;
            }
        }
        else if(currentChar=='&')
        {
            if(PROGRAM.charAt(index+1)=='&')
            {
                index+=2;
                Token newToken= new Token("&&",this.lineNum,"&&");
                resultList.add(newToken);
                return;
            }
            else {
                Token newToken= new Token("&&",this.lineNum,"&&");
                resultList.add(newToken);
                error();
            }
            /*错误处理*/
        }

        else if(currentChar=='|')
        {
            if(PROGRAM.charAt(index+1)=='|')
            {
                Token newToken= new Token("||",this.lineNum,"||");
                resultList.add(newToken);
                index+=2;
                return;
            }
            else {
                Token newToken= new Token("||",this.lineNum,"||");
                resultList.add(newToken);
               error();
            }
            /*错误处理*/
        }
        else if(currentChar=='+')
        {
            Token newToken= new Token("+",this.lineNum,"+");
            resultList.add(newToken);
            index++;
            return;
        }
        else if(currentChar=='-')
        {
            Token newToken= new Token("-",this.lineNum,"-");
            resultList.add(newToken);
            index++;
            return;
        }
        else if(currentChar=='*')
        {
            Token newToken= new Token("*",this.lineNum,"*");
            resultList.add(newToken);
            index++;
            return;
        }
        else if(currentChar=='%')
        {
            Token newToken= new Token("%",this.lineNum,"%");
            resultList.add(newToken);
            index++;
            return;
        }
        else if(currentChar=='<')
        {
            if(PROGRAM.charAt(index+1)=='='){
                Token newToken= new Token("<=",this.lineNum,"<=");
                resultList.add(newToken);
                index+=2;
                return;
            }

            else {
                Token newToken = new Token("<", this.lineNum, "<");
                resultList.add(newToken);
                index++;
                return;
            }
        }
        else if(currentChar=='>')
        {
            if(PROGRAM.charAt(index+1)=='='){
                Token newToken= new Token(">=",this.lineNum,">=");
                resultList.add(newToken);
                index+=2;
                return;
            }

            else {
                Token newToken = new Token(">", this.lineNum, ">");
                resultList.add(newToken);
                index++;
                return;
            }
        }
        else if(currentChar=='=')
        {
            if(PROGRAM.charAt(index+1)=='='){
                Token newToken= new Token("==",this.lineNum,"==");
                resultList.add(newToken);
                index+=2;
                return;
            }
            else if(PROGRAM.charAt(index+1)=='!')
            {
                Token newToken= new Token("!=",this.lineNum,"!=");
                resultList.add(newToken);
                index+=2;
                return;
            }
            else {
                Token newToken = new Token("=", this.lineNum, "=");
                resultList.add(newToken);
                index++;
                return;
            }
        }
        else if(currentChar==';')
        {
            Token newToken= new Token(";",this.lineNum,";");
            resultList.add(newToken);
            index++;
            return;
        }
        else if(currentChar==',')
        {
            Token newToken= new Token(",",this.lineNum,",");
            resultList.add(newToken);
            index++;
            return;
        }
        else if(currentChar=='(')
        {
            Token newToken= new Token("(",this.lineNum,"(");
            resultList.add(newToken);
            index++;
            return;
        }
        else if(currentChar==')')
        {
            Token newToken= new Token(")",this.lineNum,")");
            resultList.add(newToken);
            index++;
            return;
        }
        else if(currentChar=='[')
        {
            Token newToken= new Token("[",this.lineNum,"[");
            resultList.add(newToken);
            index++;
            return;
        }
        else if(currentChar==']')
        {
            Token newToken= new Token("]",this.lineNum,"]");
            resultList.add(newToken);
            index++;
            return;
        }
        else if(currentChar=='{')
        {
            Token newToken= new Token("{",this.lineNum,"{");
            resultList.add(newToken);
            index++;
            return;
        }
        else if(currentChar=='}')
        {
            Token newToken= new Token("}",this.lineNum,"}");
            resultList.add(newToken);
            index++;
            return;
        }
        /*数字常量*/
        else if(currentChar>='0'&&currentChar<='9')
        {
            while(currentChar>='0'&&currentChar<='9')
            {
                catToken();
                index++;
                currentChar=PROGRAM.charAt(index);
            }
            Token newToken= new Token(token.toString(),this.lineNum,"IntConst");
            resultList.add(newToken);
            return;
        }
        /*引号开头为字符串常量*/
        else if(currentChar== '\"')
        {
            index++;
            currentChar=PROGRAM.charAt(index);
            while(currentChar!='\"')
            {
                /*这里本来就应该和单引号处理不一样*/
                 {
                    catToken();
                    index++;
                    currentChar = PROGRAM.charAt(index);
                }
            }
            /*这个是跳过*/
            index++;
            String tokenOrigin="\""+token.toString()+"\"";
            Token newToken= new Token(tokenOrigin,this.lineNum,"StringConst");
            resultList.add(newToken);
            return;
        }

        else if(currentChar=='\'')
        {
            index++;
            currentChar=PROGRAM.charAt(index);
            while(currentChar!='\'')
            {
                if(currentChar=='\\')
                {
                    catToken();
                    currentChar=PROGRAM.charAt(index+1);
                    catToken();
                    index+=2;
                    currentChar=PROGRAM.charAt(index);
                }
                //System.out.println(currentChar);
                else {
                    catToken();
                    index++;
                    currentChar = PROGRAM.charAt(index);
                }
            }
            index++;
            String tokenOrigin="\'"+token.toString()+"\'";
            Token newToken= new Token(tokenOrigin,this.lineNum,"CharConst");
            resultList.add(newToken);
            return;
        }
        else {
            error();
            return;
        }

    }
    public ArrayList AnalizeProgramWord(String program) throws IOException {
        /*文段没有分析完之前就取词加入Array中去*/
        this.PROGRAM=program;
        while(this.index <program.length()){
            this.getSym();
        }
        /*这里是词法的输出开关*/
//        this.printWordResult();
        return this.resultList;
    }
}
