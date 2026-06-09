import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Compiler {

    static List<String> lines_type = new ArrayList<>();
    static List<String> lines_value = new ArrayList<>();
    static int line_number = 0;
    static int error_flag_a = 0;
    static int error_line = 0;
    static int note_end_pos=0;
    static BufferedReader reader;

    static {
        try {
            reader = new BufferedReader(new FileReader("testfile.txt"));
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
    }

    public Compiler() throws FileNotFoundException {
    }

    public static String readfile() throws IOException {
        //BufferedReader reader = new BufferedReader(new FileReader("testfile.txt"));

        String line;
//        for (int currentLine = 1; currentLine < lineNumber; currentLine++) {
//            if ((line = reader.readLine()) == null) {
//                // 如果文件在达到指定行号之前就已经结束，则返回null
//                reader.close();
//                return null;
//            }
//        }
        if ((line = reader.readLine()) != null) {
            return line;
        } else {
            return null;
        }
    }

    public static void writefile() throws IOException {
        BufferedWriter writer = new BufferedWriter(new FileWriter("lexer.txt"));
        for (int i = 0; i < lines_type.size(); i++) {
            String type = lines_type.get(i);
            String value = lines_value.get(i);
            writer.write(type + " " + value + "\n");
        }
        writer.close();
    }

    public static void writeerror() throws IOException {
        BufferedWriter writer = new BufferedWriter(new FileWriter("error.txt"));
        writer.write(error_line + " " + "a"+"\n");
        writer.close();
    }

    private static boolean isAlpha(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
    }

    private static boolean isDigit(char c) {
        return c >= '0' && c <= '9';
    }

    public static String find(String s){
        if(s.equals("main")){
            return "MAINTK";
        }else if(s.equals("const")){
            return "CONSTTK";
        }else if(s.equals("int")){
            return "INTTK";
        }else if(s.equals("char")){
            return "CHARTK";
        }else if(s.equals("break")){
            return "BREAKTK";
        }else if(s.equals("continue")){
            return "CONTINUETK";
        }else if(s.equals("for")){
            return "FORTK";
        }else if(s.equals("if")){
            return "IFTK";
        }else if(s.equals("else")){
            return "ELSETK";
        }else if(s.equals("getint")){
            return "GETINTTK";
        }else if(s.equals("getchar")){
            return "GETCHARTK";
        }else if(s.equals("printf")){
            return "PRINTFTK";
        }else if(s.equals("return")){
            return "RETURNTK";
        }else if(s.equals("void")){
            return "VOIDTK";
        }else{
            return "IDENFR";
        }
    }

    public static void getsympol() throws IOException {
        String line = null;
        int flag = 0;
        line_number = 0;
        while ((line = readfile()) != null) {
            line_number++;
            int curpos = 0;
            while (curpos < line.length()) {
                String token = "";
                String type = null;
                char c;
                if (line.charAt(curpos) == ' ') {
                    curpos++;
                    continue;
                } else if ((isAlpha(c = line.charAt(curpos)))) {
                    token += c;
                    curpos++;
                    while (curpos < line.length() && (isAlpha(line.charAt(curpos)) || isDigit(line.charAt(curpos)))) {
                        c = line.charAt(curpos++);
                        token += c;
                    }
                    type = find(token);
                    lines_type.add(type);
                    lines_value.add(token);
                    continue;
                } else if((isDigit(c = line.charAt(curpos)))) { // 无符号整数
                    token += c;
                    curpos++;
                    while(curpos < line.length() && isDigit(line.charAt(curpos))) {
                        c = line.charAt(curpos++);
                        token += c;
                    }
                    type = "INTCON";
                    lines_type.add(type);
                    lines_value.add(token);
                    continue;
                } else if ((c = line.charAt(curpos)) == '+') {
                    token += c;
                    curpos++;
                    type = "PLUS";
                    lines_type.add(type);
                    lines_value.add(token);
                    continue;
                } else if ((c = line.charAt(curpos)) == '-') {
                    token += c;
                    curpos++;
                    type = "MINU";
                    lines_type.add(type);
                    lines_value.add(token);
                    continue;
                } else if ((c = line.charAt(curpos)) == ';') {
                    token += c;
                    curpos++;
                    type = "SEMICN";
                    lines_type.add(type);
                    lines_value.add(token);
                    continue;
                } else if ((c = line.charAt(curpos)) == '!') {
                    token += c;
                    curpos++;
                    if (curpos < line.length()) {
                        if ((c = line.charAt(curpos)) == '=') {
                            token += c;
                            type = "NEQ";
                            lines_type.add(type);
                            lines_value.add(token);
                            curpos++;
                            continue;
                        }
                    }
                    type = "NOT";
                    lines_type.add(type);
                    lines_value.add(token);
                    continue;
                } else if ((c = line.charAt(curpos)) == '*') {
                    token += c;
                    curpos++;
                    type = "MULT";
                    lines_type.add(type);
                    lines_value.add(token);
                    continue;
                } else if ((c = line.charAt(curpos)) == ',') {
                    token += c;
                    curpos++;
                    type = "COMMA";
                    lines_type.add(type);
                    lines_value.add(token);
                    continue;
                } else if ((c = line.charAt(curpos)) == '%') {
                    token += c;
                    curpos++;
                    type = "MOD"; // 假设%代表取模操作
                    lines_type.add(type);
                    lines_value.add(token);
                    continue;
                } else if ((c = line.charAt(curpos)) == '=') {
                    token += c;
                    curpos++;
                    if (curpos < line.length()) {
                        if ((c = line.charAt(curpos)) == '=') {
                            token += c;
                            type = "EQL";
                            lines_type.add(type);
                            lines_value.add(token);
                            curpos++;
                            continue;
                        }
                    }
                    type = "ASSIGN";
                    lines_type.add(type);
                    lines_value.add(token);
                    continue;
                } else if ((c = line.charAt(curpos)) == '(') {
                    token += c;
                    curpos++;
                    type = "LPARENT";
                    lines_type.add(type);
                    lines_value.add(token);
                    continue;
                } else if ((c = line.charAt(curpos)) == ')') {
                    token += c;
                    curpos++;
                    type = "RPARENT";
                    lines_type.add(type);
                    lines_value.add(token);
                    continue;
                } else if ((c = line.charAt(curpos)) == '<') {
                    token += c;
                    curpos++;
                    if (curpos < line.length()) {
                        if ((c = line.charAt(curpos)) == '=') {
                            token += c;
                            type = "LEQ";
                            lines_type.add(type);
                            lines_value.add(token);
                            curpos++;
                            continue;
                        }
                    }
                    type = "LSS";
                    lines_type.add(type);
                    lines_value.add(token);
                    continue;
                } else if ((c = line.charAt(curpos)) == '>') {
                    token += c;
                    curpos++;
                    if (curpos < line.length()) {
                        if ((c = line.charAt(curpos)) == '=') {
                            token += c;
                            type = "GEQ";
                            lines_type.add(type);
                            lines_value.add(token);
                            curpos++;
                            continue;
                        }
                    }
                    type = "GRE";
                    lines_type.add(type);
                    lines_value.add(token);
                    continue;
                } else if ((c = line.charAt(curpos)) == '{') {
                    token += c;
                    curpos++;
                    type = "LBRACE";
                    lines_type.add(type);
                    lines_value.add(token);
                    continue;
                } else if ((c = line.charAt(curpos)) == '}') {
                    token += c;
                    curpos++;
                    type = "RBRACE";
                    lines_type.add(type);
                    lines_value.add(token);
                    continue;
                } else if ((c = line.charAt(curpos)) == '[') {
                    token += c;
                    curpos++;
                    type = "LBRACK";
                    lines_type.add(type);
                    lines_value.add(token);
                    continue;
                } else if ((c = line.charAt(curpos)) == ']') {
                    token += c;
                    curpos++;
                    type = "RBRACK";
                    lines_type.add(type);
                    lines_value.add(token);
                    continue;
                } else if ((c = line.charAt(curpos)) == '&') {
                    curpos++;
                    if (curpos < line.length() && line.charAt(curpos) == '&') {
                        curpos++;
                        token += "&&";
                        type = "AND";
                        lines_type.add(type);
                        lines_value.add(token);
                    } else {
                        error_flag_a = 1;
                        error_line=line_number;
                    }
                } else if ((c = line.charAt(curpos)) == '|') {
                    curpos++;
                    if (curpos < line.length() && line.charAt(curpos) == '|') {
                        curpos++;
                        token += "||";
                        type = "OR";
                        lines_type.add(type);
                        lines_value.add(token);
                    } else {
                        error_flag_a = 1;
                        error_line=line_number;
                    }
                } else if ((c = line.charAt(curpos)) == '\'') {
                    token += c;
                    curpos++;
                    while (curpos < line.length() && line.charAt(curpos) != '\'') {
                        c = line.charAt(curpos);
                        token += c;
                        curpos++;
                    }
                    if (line.charAt(curpos) == '\''){
                        c = line.charAt(curpos);
                        token += c;
                        curpos++;
                        type = "CHRCON";
                        lines_type.add(type);
                        lines_value.add(token);
                    }
                } else if ((c = line.charAt(curpos)) == '\"') {
                    token += c;
                    curpos++;
                    while (curpos < line.length() && line.charAt(curpos) != '\"') {
                        c = line.charAt(curpos);
                        token += c;
                        curpos++;
                    }
                    if (line.charAt(curpos) == '\"'){
                        c = line.charAt(curpos);
                        token += c;
                        curpos++;
                        type = "STRCON";
                        lines_type.add(type);
                        lines_value.add(token);
                    }
                } else if ((c = line.charAt(curpos)) == '/'){
                    token += c;
                    curpos++;
                    int non_div=0;
                    if (curpos < line.length()){
                        if (line.charAt(curpos) == '/'){
                            curpos++;
                            while(curpos < line.length()){
                                curpos++;
                            }
                            continue;
                        } else if (line.charAt(curpos) == '*'){
                            non_div=1;
                            curpos++;
                            int note_flag =1;
                            while(curpos < line.length()){
                                if(line.charAt(curpos++) == '*'){
                                    if(curpos < line.length() && line.charAt(curpos) == '/'){
                                        note_flag =0;
                                        curpos++;
                                         break;
                                    }
                                }
                            }

                            if(note_flag == 1){
                                while ((line = readfile()) != null) {
                                    line_number++;
                                    curpos=0;
                                    while (curpos < line.length()) {
                                        if(line.charAt(curpos++) == '*'){
                                            if(curpos < line.length() && line.charAt(curpos) == '/'){
                                                note_flag =0;
                                                curpos++;
                                                break;
                                            }
                                        }
                                    }
                                    if(note_flag == 0){
                                        break;
                                    }
                                }


                            }
                        }
                    }
                    if(non_div == 0) {
                        type = "DIV";
                        lines_type.add(type);
                        lines_value.add(token);
                    }
                }else{
                    curpos++;
                    continue;
                }

            }
        }
    }

    public static void main(String[] args) throws IOException {
        getsympol();
        if(error_flag_a == 1){
            writeerror();
        }else{
            writefile();
        }
    }

}
