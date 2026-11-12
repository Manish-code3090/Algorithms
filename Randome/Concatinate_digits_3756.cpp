#include <vector>
#include <string>

std::vector<int> sumAndMultiply(const std::string& s, const std::vector<std::vector<int>>& queries) {
    std::vector<int> ans;
    const long long MOD = 1e9 + 7;
    for (const std::vector<int>& v : queries) {
        long long x = 0;
        long long sum = 0;
        for (int i = v[0]; i <= v[1]; i++) {
            if (s[i] == '0') continue;
            x = x * 10 + (s[i] - '0');
            sum += s[i] - '0';
            sum %= MOD;
            x %= MOD;
        }
        if (x == 0) {
            ans.push_back((int)sum);
        } else {
            ans.push_back((int)((x * sum) % MOD));
        }
    }
    return ans;
}

int main() {
    return 0;
}