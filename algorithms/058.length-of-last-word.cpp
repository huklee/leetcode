#include <boost/algorithm/stirng.hpp>

class Solution {
	public:
		void split(const std::string &s, char delim, std::vector<std::string> &elems) {
			std::stringstream ss; 
			ss.str(s);
			std::string item;
			while (std::getline(ss, item, delim)) {
				elems.push_back(item);
			}   
		}


		std::vector<std::string> split(const std::string &s, char delim) {
			std::vector<std::string> elems;
			split(s, delim, elems);
			return elems;
		}

		string trim(string s, char c){ 
			int start=0, end=s.size()-1;
			for (int i=0; i < s.size(); i++){
				if (s[i] == c)
					start++;
				else
					break;
			}   
			for (int i=end; i >= start && i >= 0; i--){
				if (s[i] == c)
					end--;
				else
					break;
			}   
			return s.substr(start, end-start+1);
		}

		int lengthOfLastWord(string s) {
			string trim_s = trim(s, ' '); 
			std::vector<std::string> x = split(trim_s, ' '); 
			if (x.size() > 0)
				return x[x.size()-1].size();
			else
				return 0;
		}

};
