package CompileError;

public class CompileError
{
    private final int lineNum;
    private final String type;
    public CompileError(int line, String type)
    {
        this.lineNum = line;
        this.type = type;
    }

    public int getLineNum()
    {
        return lineNum;
    }

    public String information()
    {
        String inf = String.valueOf(lineNum) + ' ' + type;
        return inf;
    }
}
