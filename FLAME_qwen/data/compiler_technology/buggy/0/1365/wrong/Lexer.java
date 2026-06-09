import java.io.FileNotFoundException;
import java.io.FileReader;
import java.sql.ResultSet;
import java.util.Scanner;



public class Lexer {

    private final Scanner scanner;



    private int currentPos = 0; //记录现在的位置

    private Type type;

    private String token = "";

    private int lineNumber = 0; //记录行号

    private char currentchar;

    private int number = 0;

    private String errinfo = "";

    private String currentLine = ""; //记录现在这一行的代码
    public Lexer(String file) throws FileNotFoundException {
        scanner = new Scanner(new FileReader(file));
    }

    public Type getType() {
        return type;
    }

    public String getToken() {
        return token;
    }

    public void next() {
        if (currentPos >= currentLine.length()) {
            if (!scanner.hasNextLine()) {
                type = Type.EOF;
                return;
            } else {
                lineNumber++;
                currentPos = 0;
                currentLine = scanner.nextLine();
            }
        }
        clearToken();
        getchar();
        while (isSpace() || isNewline() || isTab()) {
            getchar();
        }
        //仅有空字符或者空行
        if (currentchar == 0) {
            next(); //所以这一步是在干什么，我不懂
            return;
        }
        if (isLetter() || isxiahuaxian()) {
            while (isLetter() || isxiahuaxian() || isDigit()) {
                catToken();
                getchar();
            }
            backtrack();
            type = Type.reserve(token);
        } else if (isDigit()) {
            while (isDigit()) {
                catToken();
                getchar();
            }
            backtrack();
            type = Type.INTCON;
            //number = Integer.parseInt(token);
        } else if (currentchar == '"') {
            catToken();
            getchar();
            while (currentPos < currentLine.length() && currentchar != '"') {
                catToken();
                getchar();
            }
            if (currentchar == '"') {
                catToken();
                type = Type.STRCON;
            } else {
                error("缺少右双引号");
                type = Type.ERR;
            }
        } else if (currentchar == '\'') {
            catToken();
            getchar();
            if (currentchar == '\\') {
                catToken();
                getchar();
                catToken();
                getchar();
                if (currentchar == '\'') {
                    catToken();
                    type = Type.CHRCON;
                } else {
                    error("缺少右单引号");
                    System.out.println(token);
                    type = Type.ERR;
                }
            } else {
                catToken();
                getchar();
                if (currentchar == '\'') {
                    catToken();
                    type = Type.CHRCON;
                } else {
                    error("缺少右单引号");
                    System.out.println(token);
                    type = Type.ERR;
                }
            }
        } else if (currentchar == '!') {
            catToken();
            getchar();
            if (currentchar == '=') {
                catToken();
                type = Type.NEQ;
            } else {
                backtrack();
                type = Type.NOT;
            }
        } else if (currentchar == '&') {
            catToken();
            getchar();
            if (currentchar == '&') {
                catToken();
                type = Type.AND;
            } else {
                backtrack();
                error("不能有这个&符号");
                type = Type.ERR;
            }
        } else if (currentchar == '|') {
            catToken();
            getchar();
            if (currentchar == '|') {
                catToken();
                type = Type.OR;
            } else {
                backtrack();
                error("不能有这个|符号");
                type = Type.ERR;
            }
        } else if (currentchar == '<') {
            catToken();
            getchar();
            if (currentchar == '=') {
                catToken();
                type = Type.LEQ;
            } else {
                backtrack();
                type = Type.LSS;
            }
        } else if (currentchar == '>') {
            catToken();
            getchar();
            if (currentchar == '=') {
                catToken();
                type = Type.GEQ;
            } else {
                backtrack();
                type = Type.GRE;
            }
        } else if (currentchar == '=') {
            catToken();
            getchar();
            if (currentchar == '=') {
                catToken();
                type = Type.EQL;
            } else {
                backtrack();
                type = Type.ASSIGN;
            }
        } else if (currentchar == '+') {
            catToken();
            type = Type.PLUS;
        } else if (currentchar == '-') {
            catToken();
            type = Type.MINU;
        } else if (currentchar == '*') {
            catToken();
            type = Type.MULT;
        } else if (currentchar == '/') {
            catToken();
            getchar();
            if (currentchar == '/') {
                while (currentPos < currentLine.length()) {
                    getchar();
                }
                next();
            } else if (currentchar == '*') {
                getchar();
                if (currentchar == '/') {
                    next();
                    return;
                } else {
                    backtrack();
                }
                while (true) {
                    while (currentPos < currentLine.length()) {
                        getchar();
                        while (currentchar == '*' && currentPos < currentLine.length()) {
                            getchar();
                            if (currentchar == '/') {
                                next();
                                return;
                            }
                        }
                    }
                    //注释未结束
                    if (scanner.hasNextLine()) {
                        currentLine = scanner.nextLine();
                        lineNumber++;
                        currentPos = 0;
                    } else {
                        return;
                    }
                }
            } else {
                backtrack();
                type = Type.DIV;
            }
        } else if (currentchar == '%') {
            catToken();
            type = Type.MOD;
        } else if (currentchar == ';') {
            catToken();
            type = Type.SEMICN;
        } else if (currentchar == ',') {
            catToken();
            type = Type.COMMA;
        } else if (currentchar == '(') {
            catToken();
            type = Type.LPARENT;
        } else if (currentchar == ')') {
            catToken();
            type = Type.RPARENT;
        } else if (currentchar == '[') {
            catToken();
            type = Type.LBRACK;
        } else if (currentchar == ']') {
            catToken();
            type = Type.RBRACK;
        } else if (currentchar == '{') {
            catToken();
            type = Type.LBRACE;
        } else if (currentchar == '}') {
            catToken();
            type = Type.RBRACE;
        } else {
            System.out.println(token);
            error("其他错误");
            type = Type.ERR;
        }
    }

    public void error(String s) {
        //System.out.println(lineNumber + " a\n");
        //System.out.println(s + "\n");
        errinfo = errinfo + Integer.toString(lineNumber) + " a\n";
    }

    public void backtrack() {
        currentPos--;
        currentchar = (currentPos < currentLine.length()) ? currentLine.charAt(currentPos) : 0;
    }

    public void catToken() {
        token += currentchar;
    }


    public void getchar() {
        if (currentPos < currentLine.length()) {
            currentchar = currentLine.charAt(currentPos++);
        } else {
            currentchar = 0;
            currentPos++;
        }
    }

    public void clearToken() {
        token = "";
        type = null;
        lineNumber = 0;
    }

    public boolean isSpace() {
        return currentchar == ' ';
    }

    public boolean isNewline() {
        return currentchar == '\n';
    }

    public boolean isTab() {
        return currentchar == '\t';
    }

    public boolean isLetter() {
        return Character.isLetter(currentchar);
    }

    public boolean isxiahuaxian() {
        return currentchar == '_';
    }

    public boolean isDigit() {
        return Character.isDigit(currentchar);
    }

    public String geterrinfo() {
        return errinfo;
    }
}
