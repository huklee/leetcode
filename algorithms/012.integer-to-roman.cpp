class Solution {
public:
    // known elegant solution
    string intToRoman_(int num) {
        string RomanM[] = {"", "M"};
        string RomanC[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string RomanX[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string RomanI[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        
        string result = "";
        result += RomanM[num/1000];
        result += RomanC[(num%1000)/100];
        result += RomanX[(num%100)/10];
        result += RomanI[(num%10)/1];
        
        return result;
    }
    
    class Roman{
        public:
        int val;
        int max;
        string s;
        Roman(int val_, int max_, string s_) : val(val_), max(max_), s(s_) {;}
    };

    string intToRoman(int num) {
        int t = num;
        string result = "";
        Roman rc[] = {Roman(1000, 4000, "M"), 
            Roman(900, 1000, "CM"), Roman(400, 500, "CD"), Roman(500, 1000, "D"), Roman(100, 500, "C"), 
            Roman(90, 100, "XC"), Roman(40, 50, "XL"), Roman(50, 100, "L"), Roman(10, 50, "X"),
            Roman(9, 10, "IX"), Roman(4, 5, "IV"), Roman(5, 10, "V"), Roman(1, 5, "I")};

        for (int i=0; i < sizeof(rc)/sizeof(Roman); i++){
            while (t < rc[i].max && rc[i].val <= t){
                t -= rc[i].val;
                result += rc[i].s;
            }    
        }
        return result;
    }
};
