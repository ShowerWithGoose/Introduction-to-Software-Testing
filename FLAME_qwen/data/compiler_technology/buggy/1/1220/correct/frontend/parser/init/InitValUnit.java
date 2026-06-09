package frontend.parser.init;

import frontend.lexer.Token;
import frontend.parser.SyntaxUnit;

public interface InitValUnit extends SyntaxUnit {
    //  InitVal â†’ Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
}
