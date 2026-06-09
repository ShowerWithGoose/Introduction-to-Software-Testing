import java.util.ArrayList;
public class lexer {
    public static String[] KeyWord = {
            "main","const","int","char","break","continue","if","else","for",
            "getint","getchar","printf","return","void"
    };
    private int flag;
    private int sign1 = 0;
    private int sign3 = 0;

    public lexer(String input,int line,ArrayList<Token>tokens,int sign2,ArrayList<Error>errors) {
        int pos = 0;
        this.flag = 0;
        while (pos < input.length()) {  //循环判断每一行的每个字符
            while((sign2 == 1 && input.charAt(pos)!='*')||sign1 == 1) { //sign2:多行注释,sign1=1,同行存在/*
                pos++;
                if(pos>=input.length()) {
                    break;
                }
            } //当前字符为'*'
            if(pos>=input.length()) {
                break;
            }
            if (input.charAt(pos) == ' '||input.charAt(pos)=='\t') {
                pos++;
            }//跳过空格和换行符
             else if (input.charAt(pos) == '(') {
                tokens.add(new Token(Token.Type.LPARENT, "(",line));
                pos++;
            } else if (input.charAt(pos) == ')') {
                tokens.add(new Token(Token.Type.RPARENT, ")",line));
                pos++;
            } else if (input.charAt(pos) == '[') {
                tokens.add(new Token(Token.Type.LBRACK, "[",line));
                pos++;
            } else if (input.charAt(pos) == ']') {
                tokens.add(new Token(Token.Type.RBRACK, "]",line));
                pos++;
            } else if (input.charAt(pos) == '{') {
                tokens.add(new Token(Token.Type.LBRACE, "{",line));
                pos++;
            } else if (input.charAt(pos) == '}') {
                tokens.add(new Token(Token.Type.RBRACE, "}",line));
                pos++;
            } else if (input.charAt(pos) == ',') {
                tokens.add(new Token(Token.Type.COMMA, ",",line));
                pos++;
            } else if (input.charAt(pos) == ';') {
                tokens.add(new Token(Token.Type.SEMICN, ";",line));
                pos++;
            } else if (input.charAt(pos) == '+') {
                tokens.add(new Token(Token.Type.PLUS, "+",line));
                pos++;
            } else if (input.charAt(pos) == '-') {
                tokens.add(new Token(Token.Type.MINU, "-",line));
                pos++;
            } else if (input.charAt(pos) == '*') {
                pos++;
                if(pos<input.length()) {
                    char now  = input.charAt(pos);
                    if(now == '/') {
                        sign1 = -1;
                        sign2 = 0;
                        pos++;
                    } else {
                        if(sign2 == 0)
                            tokens.add(new Token(Token.Type.MULT, "*",line));
                    }
                } else {
                    if(sign2 == 0)
                        tokens.add(new Token(Token.Type.MULT, "*",line));
                }
            } else if (input.charAt(pos) == '/') {
                int flag = 0;
                pos++;
                if(pos>=input.length()) {
                    tokens.add(new Token(Token.Type.DIV,"/",line));
                    break;
                }
                if (input.charAt(pos) == '*') {
                    flag = 1;
                    sign1 = 1;
                    pos++;
                    if(pos>=input.length())  {
                        break;
                    }
                    while(pos<input.length()-1) { //保证不会越界
                        char now = input.charAt(pos);
                        if(now=='*') {
                            pos++;
                            if (input.charAt(pos)=='/') {
                                sign1 = 0;
                                pos++;
                                break;
                            }
                        }
                        pos++;
                    }
                    if(sign1==1&&input.charAt(pos-1)=='*'&&input.charAt(pos)=='/'){
                        sign1 = 0;
                        pos++;
                    }
                } else if (input.charAt(pos) =='/') {
                    break;
                }
                if(flag ==0) {
                    tokens.add(new Token(Token.Type.DIV,"/",line));
                }
            } else if (input.charAt(pos) == '%') {
                tokens.add(new Token(Token.Type.MOD,"%",line));
                pos++;
            } else if (input.charAt(pos) == '!') {
                pos++;
                if(pos>=input.length()) {
                    break;
                }
                if(input.charAt(pos)=='=') {
                    tokens.add(new Token(Token.Type.NEQ,"!=",line));
                    pos++;
                } else {
                    tokens.add(new Token(Token.Type.NOT, "!",line));
                }
            } else if (input.charAt(pos) == '&') {
                pos++;
                if(pos>=input.length()) {
                    break;
                }
                if(input.charAt(pos)=='&') {
                tokens.add(new Token(Token.Type.AND,"&&",line));
                pos++;
                }
                else {
                    flag = 1;
                    tokens.add(new Token(Token.Type.AND,"&&",line));
                    errors.add(new Error(Error.Type.ERROR_A,line,"a"));
                }
            } else if (input.charAt(pos) == '|') {
                pos++;
                if(pos>=input.length()) {
                    break;
                }
                if(input.charAt(pos) == '|')
                {
                tokens.add(new Token(Token.Type.OR,"||",line));
                pos++;
                }
                else {
                    flag = 1; //程序有错误
                    tokens.add(new Token(Token.Type.OR,"||",line));
                    errors.add(new Error(Error.Type.ERROR_A,line,"a"));
                }
            } else if (input.charAt(pos) == '=') {
                pos++;
                if(pos>=input.length()) {
                    break;
                }
                if (input.charAt(pos) == '=') {
                    tokens.add(new Token(Token.Type.EQL,"==",line));
                    pos++;
                }
                else {
                    tokens.add(new Token(Token.Type.ASSIGN,"=",line));
                }
            } else if(input.charAt(pos) == '<') {
                pos++;
                if(pos>=input.length()) {
                    break;
                }
                if(input.charAt(pos)=='=') {
                    tokens.add(new Token(Token.Type.LEQ,"<=",line));
                    pos++;
                } else {
                    tokens.add(new Token(Token.Type.LSS,"<",line));
                }
            } else if (input.charAt(pos) == '>') {
                pos++;
                if(pos>=input.length()) {
                    break;
                }
                if(input.charAt(pos)=='=') {
                    tokens.add(new Token(Token.Type.GEQ,">=",line));
                    pos++;
                } else {
                    tokens.add(new Token(Token.Type.GRE,">",line));
                }
            } else  if (input.charAt(pos)>='0'&&input.charAt(pos)<='9'){
                char now = input.charAt(pos);
                StringBuilder sb = new StringBuilder();
                while (now >= '0' && now <= '9') {
                    sb.append(now);
                    pos++;
                    if (pos >= input.length()) {
                        break;
                    }
                    now = input.charAt(pos);
                }
                tokens.add(new Token(Token.Type.INTCON, sb.toString(),line));
            } else if (input.charAt(pos) >='a'&& input.charAt(pos)<='z') {
                char now = input.charAt(pos);
                StringBuilder sb = new StringBuilder();
                while (now >= 'a' && now <= 'z'||now>='A'&& now<='Z'||
                        now =='_'||now>='0'&&now<='9') {
                    sb.append(now);
                    pos++;
                    if (pos >= input.length()) {
                        break;
                    }
                    now = input.charAt(pos);
                }
                int sign = 0;
                for (int j = 0;j< KeyWord.length;j++) {
                    if(sb.toString().equals(KeyWord[j])) {
                        tokens.add(new Token(Token.Type.KEYWORD, sb.toString(),line));
                        sign = 1;
                    }
                }
                if (pos >= input.length()) {
                    if(sign == 0)
                        tokens.add(new Token(Token.Type.IDENFR, sb.toString(),line));
                    break;
                }
                if (sign == 0) {
                    while(now>='0'&&now<='9'||now=='_'||now>='a'&&now<='z' ||now>='A'&&now<='Z'){
                        sb.append(now);
                        pos++;
                        if (pos >= input.length()) {
                            break;
                        }
                        now = input.charAt(pos);
                    }
                    tokens.add(new Token(Token.Type.IDENFR, sb.toString(),line));
                }
            } else if(input.charAt(pos) == '"'){
                StringBuilder string_const = new StringBuilder();
                string_const.append('"');
                pos++;
                if(pos>=input.length()) {
                    break;
                }
                while (input.charAt(pos)!='"') {
                    string_const.append(input.charAt(pos));
                    pos++;
                    if(pos>=input.length()) {
                        break;
                    }
                }
                pos++;
                string_const.append('"');
                tokens.add(new Token(Token.Type.STRCON,string_const.toString(),line));
            } else if(input.charAt(pos)=='\'') {
                StringBuilder s = new StringBuilder();
                s.append('\'');
                pos++;
                if(pos>=input.length()) {
                    break;
                }
                char c = input.charAt(pos);
                while(c!='\'') {
                   s.append(c);
                   pos++;
                   if(pos>=input.length()) {
                       break;
                   }
                   c = input.charAt(pos);
                }
                pos++;
                s.append(c);
                while(pos<input.length()&& input.charAt(pos)=='\'') {
                    s.append(input.charAt(pos));
                    pos++;
                }
                tokens.add(new Token(Token.Type.CHRCON,s.toString(),line));
            } else if (input.charAt(pos)>='A'&&input.charAt(pos)<='Z'||input.charAt(pos)=='_'){
                StringBuilder string_const = new StringBuilder();
                string_const.append(input.charAt(pos));
                pos++;
                if(pos>=input.length()) {
                    tokens.add(new Token(Token.Type.IDENFR,string_const.toString(),line));
                    break;
                }
                while((input.charAt(pos)>='a'&&input.charAt(pos)<='z'||
                input.charAt(pos)>='A'&&input.charAt(pos)<='Z'||input.charAt(pos)>='0'&&input.charAt(pos)<='9'||
                input.charAt(pos)=='_')) {
                    string_const.append(input.charAt(pos));
                    pos++;
                    if (pos >= input.length()) {
                        break;
                    }
                }
                tokens.add(new Token(Token.Type.IDENFR,string_const.toString(),line));
            }
             else {
                 pos++;
            }
        }
    }

    public int getFlag() {
        return flag;
    }

    public int getSign1() {
        return sign1;
    }


}
