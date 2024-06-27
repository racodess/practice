import java.util.*;

public class SimplifiedPath {

    public String simplifyPath(String path){

        StringTokenizer tkn = new StringTokenizer(path, "/");
        Stack<String> opr = new Stack<>();
        while (tkn.hasMoreTokens()){
            String tmp = tkn.nextToken();
            if (tmp.equals("."))
                continue;
            else if (!tmp.equals("..")){
                opr.push(tmp);
            }
            else if (!opr.empty()) {
                opr.pop();
            }
        }

        Stack<String> dir = new Stack<>();
        while (!opr.empty())
            dir.push(opr.pop());

        StringBuilder newPath = new StringBuilder();
        while (!dir.empty())
            newPath.append("/").append(dir.pop());

        if (newPath.isEmpty())
            newPath.append("/");

        return newPath.toString();
    }

    public static void main(String[] args){

        SimplifiedPath test = new SimplifiedPath();
        System.out.println(test.simplifyPath("/a//b////c/d//././/.."));
        System.out.println(test.simplifyPath("/../"));
        System.out.println(test.simplifyPath("/home//foo/"));
    }
}
