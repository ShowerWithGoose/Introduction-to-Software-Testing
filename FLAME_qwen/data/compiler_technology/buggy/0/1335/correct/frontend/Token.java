package frontend;

public class Token {
    private String tokenString;
    private Type type;
    private int lineNum;
    private boolean isCorrect;
    private boolean isNum;
    private int numberValue;

    public Token(String tokenString, Type type, int lineNum) {
        this.tokenString = tokenString;
        this.type = type;
        this.lineNum = lineNum;
        this.isNum = type == Type.INTCON;
        this.isCorrect = true;
        this.numberValue = 0;
        if (isNum) {
            try {
                this.numberValue = Integer.parseInt(tokenString);
            } catch (NumberFormatException e) {
                this.isNum = false;
            }
        }
    }

    // Getters and Setters
    public String getTokenString() {
        return tokenString;
    }

    public void setTokenString(String tokenString) {
        this.tokenString = tokenString;
    }

    public Type getType() {
        return type;
    }

    public void setType(Type type) {
        this.type = type;
    }

    public int getLineNum() {
        return lineNum;
    }

    public void setLineNum(int lineNum) {
        this.lineNum = lineNum;
    }

    public boolean isCorrect() {
        return isCorrect;
    }

    public void setCorrect(boolean isCorrect) {
        this.isCorrect = isCorrect;
    }

    public boolean isNum() {
        return isNum;
    }

    public void setNum(boolean isNum) {
        this.isNum = isNum;
    }

    public int getNumberValue() {
        return numberValue;
    }

    public void setNumberValue(int numberValue) {
        this.numberValue = numberValue;
        this.isNum = true;
    }

}
