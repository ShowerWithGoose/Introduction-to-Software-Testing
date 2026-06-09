package common;


import IO.MyWriter;

/**
 * The type Error.
 *
 * @author
 * @Description：
 * @date
 */
public class Error {

    /**
     * Error a.
     *
     * @param lineNum 行号
     */
    public static void Error_a(Integer lineNum){
        String message = lineNum.toString()+" "+"a";
        MyWriter.getWriter().callError(message);
    }
    /**
     * Error i.
     *
     * @param lineNum 行号
     */
    public static void Error_i(Integer lineNum){
        String message = lineNum.toString()+" "+"i";
        MyWriter.getWriter().callError(message);
    }
    /**
     * Error j.
     *
     * @param lineNum 行号
     */
    public static void Error_j(Integer lineNum){
        String message = lineNum.toString()+" "+"j";
        MyWriter.getWriter().callError(message);
    }
    /**
     * Error k.
     *
     * @param lineNum 行号
     */
    public static void Error_k(Integer lineNum){
        String message = lineNum.toString()+" "+"k";
        MyWriter.getWriter().callError(message);
    }

}
