class Solution {
public:
    const std::array<std::string, 10> map = { 
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz" };
    std::vector<std::string> comb;
    std::string part;

    void backtracking(std::string& digits, int pos)
    {
        if (part.size() == digits.size())
        {
            comb.push_back(part);
            return;
        }
        int mappos = digits[pos] - '0';        
        for (int i = 0; i < map[mappos].size(); i++)
        {
            part.push_back(map[mappos][i]);
            backtracking(digits, pos + 1);
            part.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        if (digits.size() == 0)
        {
            return comb;
        }
        backtracking(digits, 0);

        return comb;
    }
};