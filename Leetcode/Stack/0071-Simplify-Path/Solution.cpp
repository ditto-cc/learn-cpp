
/**
Given an absolute path for a file (Unix-style), simplify it. Or in other words, convert it to the canonical path.

In a UNIX-style file system, a period . refers to the current directory. Furthermore, a double period .. moves the directory up a level.

Note that the returned canonical path must always begin with a slash /, and there must be only a single slash / between two directory names. The last directory name (if it exists) must not end with a trailing /. Also, the canonical path must be the shortest string representing the absolute path.

 

Example 1:

Input: "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.
Example 2:

Input: "/../"
Output: "/"
Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.
Example 3:

Input: "/home//foo/"
Output: "/home/foo"
Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.
Example 4:

Input: "/a/./b/../../c/"
Output: "/c"
Example 5:

Input: "/a/../../b/../c//.//"
Output: "/c"
Example 6:

Input: "/a//b////c/d//././/.."
Output: "/a/b/c"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/simplify-path
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> s;
        string res = "/";
        for (int i = 1; i < path.size();) {
            int j = i;
            if (path[j] == '/') {
                for (; j < path.size() && path[j] == '/'; j++);
            } else if (path[j] == '.') {
                if (j + 1 < path.size() && path[j+1] == '.') {
                    if (!s.empty())
                        s.pop_back();
                    j++;
                }
                j++;
            } else {
                for(; j < path.size() && path[j] != '.' && path[j] != '/'; j++);
                string name = path.substr(i, j);
                s.push_back(name);
            }
            i = j;
        }
        for (int i = 0; i < s.size(); i++) {
            res.append(s[i]);
            if (i != s.size() - 1)
                res.append("/");
        }
        return res;
    }
};