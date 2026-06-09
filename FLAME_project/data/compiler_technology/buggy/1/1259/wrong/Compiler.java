import frontend.Error.ErrorManager;
import frontend.IOManager;
import frontend.Lexer.Lexer;
import frontend.Parser.Parser;
import frontend.Symbol.SymbolManager;
import frontend.Visitor.Visitor;

import java.io.*;

public class Compiler
{
    public static void main(String[] args) {
        Lexer lexer = Lexer.GetLexer();
        Parser parser = Parser.GetInstance();
        Visitor visitor = Visitor.GetInstance();
        SymbolManager symbolManager = SymbolManager.GetInstance();
        try {
            IOManager.InitIOReader(new BufferedReader(new FileReader("testfile.txt")));
            lexer.Init();
            while(lexer.Next() != -1){
                lexer.PutToken();
            }
            parser.Init();
            parser.Process();

            visitor.Init();
            visitor.Process();

            if(ErrorManager.GetInstance().isError()){
                IOManager.InitIOWriter(new BufferedWriter(new FileWriter("error.txt")));
                ErrorManager.GetInstance().PrintError();
            }else{
                IOManager.InitIOWriter(new BufferedWriter(new FileWriter("symbol.txt")));
////                lexer.PrintTokens(bufferedWriter);
////                parser.PrintTree();
                symbolManager.PrintSymbol();
            }
            IOManager.CloseIO();

        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
