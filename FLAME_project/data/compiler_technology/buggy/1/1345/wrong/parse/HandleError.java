package parse;

public class HandleError {
    public static Token handleI(Token token,TokenList list,WrongList wrongs){
        Token x = token;
        if (!x.getType().equals("SEMICN")) {
            list.unReadToken(2);
            x = list.readNextToken();
            wrongs.addWrong(new WrongType(x.getLinenumber(), "i"));
            return new Token("SEMICN", x.getLinenumber(), "");
        }
        return x;
    }

    public static Token handleJ(Token token,TokenList list,WrongList wrongs){
        Token x = token;
        if (!x.getType().equals("RPARENT")) {
            list.unReadToken(2);
            x = list.readNextToken();
            wrongs.addWrong(new WrongType(x.getLinenumber(), "j"));
            return new Token("RPARENT", x.getLinenumber(), "");
        }
        return x;
    }

    public static Token handleK(Token token,TokenList list,WrongList wrongs){
        Token x = token;
        if (!x.getType().equals("RBRACK")) {
            list.unReadToken(2);
            x = list.readNextToken();
            wrongs.addWrong(new WrongType(x.getLinenumber(), "k"));
            return new Token("RBRACK", x.getLinenumber(), "");
        }
        return x;
    }
}
