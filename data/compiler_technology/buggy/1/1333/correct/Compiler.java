public class Compiler {
    public static void main(String[] args) {
        String content = InOut.input();
        Lexer lexer = new Lexer(content);
        Parser parser = new Parser(lexer.getTokens());
        if (ErrorSet.errorSet.isEmpty()) {
            InOut.outputParseAnswer(parser.getCompUnit());
        } else {
            InOut.outputError(ErrorSet.errorSet);
        }
    }
}
