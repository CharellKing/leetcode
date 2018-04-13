class Solution {
public:
    string simplifyPath(const string& path) {
        if ("" == path) {
            return "";
        }
        
       list<string> directories;
       string directory;
       for(int i = 0; i < path.size(); i ++) {
           if (path[i] == '/') {
                if (directory == "..") {
                    if (directories.size() > 0) {
                        directories.pop_back();
                    }
                } else if (directory != "." && directory != "") {
                    directories.push_back(directory);
                }
                directory.clear();
           } else {
               directory.push_back(path[i]);
           }
       }
       
       if (directory == "..") {
           if (directories.size() > 0) {
               directories.pop_back();
           }
       } else if (directory != "." && directory != "") {
           directories.push_back(directory);
       }
       
       if (directories.size() <= 0) {
           return "/";
       }
       
       string ret = "";
       while(directories.size() > 0) {
            ret.push_back('/');
            ret += directories.front();
            directories.pop_front();
       }
       return ret;
    }
};
