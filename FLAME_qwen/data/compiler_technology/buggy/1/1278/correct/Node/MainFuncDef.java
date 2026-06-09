package Node;
import Tools.Token;
import Tools.WriteFile;
public class MainFuncDef extends Node {
    Token int_token = null;
    Token main_token = null;
    Token l_token = null;
    Token r_token = null;
    Block block;

    public MainFuncDef(int lineno, Token int_token, Token main_token,
                       Token l_token, Token r_token, Block block) {
        super(lineno);
        this.int_token = int_token;
        this.main_token = main_token;
        this.l_token = l_token;
        this.r_token = r_token;
        this.block = block;
    }

    public void checkOut() {
        WriteFile.MakeFile(int_token.toString() + "\n");
        WriteFile.MakeFile(main_token.toString() + "\n");
        WriteFile.MakeFile(l_token.toString() + "\n");
        WriteFile.MakeFile(r_token.toString() + "\n");
        block.checkOut();
        WriteFile.MakeFile("<MainFuncDef>\n");
    }
}
