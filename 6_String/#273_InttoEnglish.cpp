//#273. Integer to English Words
//Hard
//Method: Caution for the empty space
//Complexity: Time O(1); Space O(1)

vector<string> Ones{"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
vector<string> Tens{"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

class Solution {
public:
    string GetThousand(int num) {
        string res;
        if (num % 100 < 20)
            res = Ones[num % 100];
        else {
            res = Tens[num / 10 % 10] + ' ' + Ones[num % 10];
        }
        num /= 100;
        if (num % 10) res = Ones[num % 10] + ' ' + "Hundred" + ' ' + res;
        if (res.back() == ' ') res.pop_back();
        return res;
    }
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string res;
        res = GetThousand(num);
        num /= 1000;
        if (num % 1000) res = GetThousand(num) + ' ' + "Thousand" + ' ' + res;
        num /= 1000;
        if (num % 1000) res = GetThousand(num) + ' ' + "Million" + ' ' + res;
        num /= 1000;
        if (num % 1000) res = GetThousand(num) + ' ' + "Billion" + ' ' + res;
        if (res.back() == ' ') res.pop_back();
        return res;
    }
};