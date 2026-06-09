package frontend;

import java.util.HashMap;
import java.util.Map;

public class Token {
    private  String type;
    private StringBuilder content;
    private int lineno;
    Map<String, String> tokenMap = new HashMap<String, String>() {{
        put("main", "MAINTK");
        put("const", "CONSTTK");
        put("int", "INTTK");
        put("char", "CHARTK");
        put("break", "BREAKTK");
        put("continue", "CONTINUETK");
        put("if", "IFTK");
        put("else", "ELSETK");
        put("for", "FORTK");
        put("getint", "GETINTTK");
        put("getchar", "GETCHARTK");
        put("printf", "PRINTFTK");
        put("return", "RETURNTK");
        put("void", "VOIDTK");
    }};

    public Token(StringBuilder content, int lineno) {
        this.content = content;
        this.lineno = lineno;
        if(tokenMap.containsKey(content.toString())) {
            this.type = tokenMap.get(content.toString());
        }
        else{
            this.type = "IDENFR";
        }
    }

    public Token(String type, StringBuilder content, int lineno) {
        this.type = type;
        this.content = content;
        this.lineno = lineno;
    }

    public String getType() {
        return type;
    }

    public StringBuilder getContent() {
        return content;
    }
}

