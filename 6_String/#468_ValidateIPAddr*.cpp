//#468. Validate IP Address
//Medium
//Method: catch exception
//Complexity: Time O(N); Space O(1)

class Solution {
public:
    string FindIPv4(string IP) {
        size_t sep;
        for (int i = 0; i < 4; ++i) {
            int num;
            try {num = stoi(IP, &sep);}
            catch (exception &e) {return "Neither";}
            if (IP[0] == '-' || num > 255 || (IP[0] == '0' && sep != 1))
                return "Neither";
            if (sep == IP.size()) {
                if (i == 3)
                    return "IPv4";
                else
                    return "Neither";
            } else {
                if (IP[sep] != '.')
                    return "Neither";
                IP = IP.substr(sep + 1);
            }
        }
        return "Neither";
    }
    
    string FindIPv6(string IP) {
        size_t sep;
        for (int i = 0; i < 8; ++i) {
            int num;
            try {num = stoi(IP, &sep, 16);}
            catch (exception &e) {return "Neither";}
            if (IP[0] == '-' || num > 0xffff || (IP[0] == '0' && sep > 4))
                return "Neither";
            if (sep == IP.size()) {
                if (i == 7)
                    return "IPv6";
                else
                    return "Neither";
            } else {
                if (IP[sep] != ':')
                    return "Neither";
                IP = IP.substr(sep + 1);
            }
        }
        return "Neither";
    }
    
    string validIPAddress(string IP) {
        size_t pos = IP.find_first_of(".:");
        if (pos == string::npos)
            return "Neither";
        if (IP[pos] == '.')
            return FindIPv4(IP);
        if (IP[pos] == ':')
            return FindIPv6(IP);
        return "Neither";
    }
};