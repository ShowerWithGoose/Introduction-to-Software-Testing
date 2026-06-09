package frontend;

import java.io.BufferedReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.List;


public class Lexer {
    // 定义Token类
    public static class Token{
        // Token类的属性
        String value; // 单词值 int
        String type; // 类型 INTTK
        int line; // 所在行号

        // 对象的构造方法  对应 Token varName = new Token("str1","str2",当前行号)
        Token(String value, String type,int line){
            this.value = value;
            this.type = type;
            this.line = line;
        }

        // 改写toString方法 println(var)即可产生该格式的输出
        public String toString(){
            return type + " " + value + "\n"; // + 用来字符串拼接
        }
    }

    // tokens为词法分析结果！！ 解析出来的一个个Token用List来存储 列表名为 [tokens]
    public static List<Token> tokens = new ArrayList<>(); //这是一个存储Token对象的List

    // 保留字用hash表存储，方便查找单词对应的类别名
    public static final HashMap<String,String> SAVEWORDS; // HashMap<键类型，值类型> 变量名
    static {
        SAVEWORDS = new HashMap<>();
        SAVEWORDS.put("main","MAINTK");
        SAVEWORDS.put("const","CONSTTK");
        SAVEWORDS.put("int", "INTTK");
        SAVEWORDS.put("char", "CHARTK");
        SAVEWORDS.put("break", "BREAKTK");
        SAVEWORDS.put("continue", "CONTINUETK");
        SAVEWORDS.put("if", "IFTK");
        SAVEWORDS.put("else", "ELSETK");
        SAVEWORDS.put("!", "NOT");
        SAVEWORDS.put("&&", "AND");
        SAVEWORDS.put("||", "OR");
        SAVEWORDS.put("for", "FORTK");
        SAVEWORDS.put("getint", "GETINTTK");
        SAVEWORDS.put("getchar", "GETCHARTK");
        SAVEWORDS.put("printf", "PRINTFTK");
        SAVEWORDS.put("return", "RETURNTK");
        SAVEWORDS.put("+", "PLUS");
        SAVEWORDS.put("-", "MINU");
        SAVEWORDS.put("void", "VOIDTK");
        SAVEWORDS.put("*", "MULT");
        SAVEWORDS.put("/", "DIV");
        SAVEWORDS.put("%", "MOD");
        SAVEWORDS.put("<", "LSS");
        SAVEWORDS.put("<=", "LEQ");
        SAVEWORDS.put(">", "GRE");
        SAVEWORDS.put(">=", "GEQ");
        SAVEWORDS.put("==", "EQL");
        SAVEWORDS.put("!=", "NEQ");
        SAVEWORDS.put("=", "ASSIGN");
        SAVEWORDS.put(";", "SEMICN");
        SAVEWORDS.put(",", "COMMA");
        SAVEWORDS.put("(", "LPARENT");
        SAVEWORDS.put(")", "RPARENT");
        SAVEWORDS.put("[", "LBRACK");
        SAVEWORDS.put("]", "RBRACK");
        SAVEWORDS.put("{", "LBRACE");
        SAVEWORDS.put("}", "RBRACE");
    }


    public void Lexer(BufferedReader br) throws IOException {
        String line;
        int curPos; // 这一行处理到哪个位置了
        int lineLenth;
        char c;
        String token;
        Token tmp;
        int lineNum = 0; // 记录当前处理到的行号，用于打印错误行号

        while((line = br.readLine()) != null){
            lineNum++;
            lineLenth = line.length();
            curPos = 0;

            while(curPos < lineLenth) {
                token = ""; // 清空token，必须用""，不能用null
                c = line.charAt(curPos); // 字符串.charAt(索引) = 字符串[索引]
                // 跳过空格 和 tab
                if (c == ' ' || c == '\t') curPos++;
                // 是标识符or保留字
                else if (Character.isLetter(c) || c == '_') {
                    token += c;
                    while (++curPos < lineLenth) {
                        if (Character.isLetter(line.charAt(curPos)) || Character.isDigit(line.charAt(curPos)) || line.charAt(curPos) == '_') {
                            token += line.charAt(curPos);  // 此处极其冗余，可以将line.charAt(curPos)放到while中来判断！
                        }
                        else{
                            break;
                        }
                    }
                    // 查保留字hash表
                    if (SAVEWORDS.containsKey(token)) { // 哈希表名.containsKey('key') 返回值为 true/false
                        tmp = new Token(token, SAVEWORDS.get(token),lineNum);
                    } else { // 是标识符
                        tmp = new Token(token, "IDENFR",lineNum);
                    }
                    tokens.add(tmp);
                }
                // 是数字
                else if (Character.isDigit(c)) {
                    token += c;
                    while (++curPos < lineLenth) { // 提前判断下一个字符是什么
                        if (Character.isDigit(line.charAt(curPos))) {
                            c = line.charAt(curPos);
                            token += c;
                        }
                        else{
                            break; // 退回多读的字符
                        }
                    }
                    // 加入到List中
                    tmp = new Token(token, "INTCON",lineNum);
                    tokens.add(tmp);
                }
                // 无歧义的单字符
                else if (c == '+' || c == '-' || c == ';' || c == ',' || c == '{' || c == '}' || c == '(' || c == ')' || c == '[' || c == ']' || c == '%' || c == '*') {
                    token = String.valueOf(c); // 强转为string：String.valueOf(任意类型变量)
                    tmp = new Token(token, SAVEWORDS.get(token),lineNum); // 初始化一个名为tmp的Token  哈希表名.get(‘key’)来获取value
                    tokens.add(tmp); // 列表名.add(列表元素名)
                    curPos++;
                }
                // 字符串常量
                else if (c == '\"') {
                    token += c;
                    while (++curPos < lineLenth && line.charAt(curPos) != '\"') {
                        token += line.charAt(curPos);
                    }
                    if (line.charAt(curPos) == '\"') {
                        token += c;
                        tmp = new Token(token, "STRCON",lineNum);
                        tokens.add(tmp);
                        curPos++; // 务必记得跳过这个"
                    } else {
                        System.out.println("字符串无后双引号");
                    }
                }
                // 字符常量 <可以和上面的字符串常量合并成一个方法>
                else if (c == '\'') {
                    token += c;
                    while (++curPos < lineLenth && line.charAt(curPos) != '\'') {
                        token += line.charAt(curPos);
                    }
                    if (line.charAt(curPos) == '\'') {
                        token += c;
                        tmp = new Token(token, "CHRCON",lineNum);
                        tokens.add(tmp);
                        curPos++; // 务必记得跳过这个'
                    } else {
                        System.out.println("字符无后单引号");
                    }
                }
                // 后面还可以衔接等号的 ! > < =  （!= >= <= ==）
                else if (c == '!' || c == '>' || c == '<' || c == '=') {
                    token += c;
                    if (++curPos < lineLenth && line.charAt(curPos) == '=') {
                        token += line.charAt(curPos++);
                    }
                    tmp = new Token(token, SAVEWORDS.get(token),lineNum);  // !! 这也应该建一个方法，叫 AddList（）
                    tokens.add(tmp);
                }
                // &&
                else if(c == '&'){
                    token += c;
                    if(++curPos < lineLenth && line.charAt(curPos) == '&'){
                        token += line.charAt(curPos++);
                        tmp = new Token(token, SAVEWORDS.get(token),lineNum);
                        tokens.add(tmp);
                    }
                    else{ // 2个条件任何一个不满足：词法分析的报错 类型为a
                        // 先将错误添加到errors这个List中
                        //Errorlog el = new Errorlog();
                        //el.AddError(lineNum,'a');
                        // 将&也要加入tokens，在后面的语法分析处理，不用在这里加入errorlog了！
                        tmp = new Token("&", SAVEWORDS.get("&&"),lineNum);
                        tokens.add(tmp);
                    }
                }
                // ||  《应与&&合并》
                else if(c == '|'){
                    token += c;
                    if(++curPos < lineLenth && line.charAt(curPos) == '|'){
                        token += line.charAt(curPos++);
                        tmp = new Token(token, SAVEWORDS.get(token),lineNum);
                        tokens.add(tmp);
                    }
                    else{
                        tmp = new Token("|", SAVEWORDS.get("||"),lineNum);
                        tokens.add(tmp);
                    }
                }
                // 注释 与 除法
                else if(c == '/'){
                    token += c;
                    // 除法
                    if(curPos+1 < lineLenth && line.charAt(curPos+1) != '/' && line.charAt(curPos+1) != '*'){ // 这里不能用++curPos！因为后面的else if也要判断当前curPos
                        tmp = new Token(token, SAVEWORDS.get(token),lineNum);
                        tokens.add(tmp);
                        curPos++;
                    }
                    // 单行注释
                    else if(curPos+1 < lineLenth && line.charAt(curPos+1) == '/'){
                        curPos = lineLenth; // 将指针指向行尾
                    }
                    // 多行注释
                    else if(++curPos < lineLenth && line.charAt(curPos) == '*'){
                        int flag = 0; // flag=1代表多行注释结束
                        while(curPos+1 < lineLenth && line.charAt(curPos+1) != '*'){
                            curPos++;
                        }
                        //  在一行中出现多行注释 /* */
                        if(curPos+1 < lineLenth && line.charAt(curPos+1) == '*' && line.charAt(curPos+2) == '/'){
                            curPos += 3;
                        }
                        // 跨行的多行注释
                        if(curPos+1 == lineLenth){
                            while((line = br.readLine()) != null){
                                lineNum++;
                                lineLenth = line.length();
                                curPos = 0;
                                while(curPos < lineLenth) {
                                    if(line.charAt(curPos) != '*'){
                                        curPos++;
                                    }
                                    else{
                                        if(line.charAt(curPos+1) != '/'){
                                            curPos++;
                                        }
                                        else{ // */
                                            curPos += 2;
                                            flag = 1; // 1代表多行注释结束
                                            break;
                                        }
                                    }
                                }
                                if(flag == 1){ // 跳出多行注释的读行处理
                                    break;
                                }
                            }
                        }
                    }
                }
                else{
                    System.out.println(lineNum + ":" + c + "不匹配任何字符！");
                    curPos++; // 你不匹配你要往后走啊，不然死循环，但其实词法分析这里用不到这条
                }
                //System.out.println(token); //调试用
            }
        }
        // 统一输出到 error.txt 和 lexer.txt
        //Errorlog.WriteError2File(); // 这两个方法是类本身的方法，即定义时用了static，不用实例化，直接 类名.方法 即可
        Lexlog.WriteLexAns2File();
    }
}
