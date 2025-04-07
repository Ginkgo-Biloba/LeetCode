#include "leetcode.hpp"

/* 2062. 统计字符串中的元音子字符串

子字符串 是字符串中的一个连续（非空）的字符序列。
元音子字符串 是 仅 由元音（'a'、'e'、'i'、'o' 和 'u'）组成的一个子字符串，且必须包含 全部五种 元音。
给你一个字符串 word ，统计并返回 word 中 元音子字符串的数目 。

示例 1：
输入：word = "aeiouu"
输出：2
解释：下面列出 word 中的元音子字符串（斜体加粗部分）：
- "aeiouu"
- "aeiouu"

示例 2：
输入：word = "unicornarihan"
输出：0
解释：word 中不含 5 种元音，所以也不会存在元音子字符串。

示例 3：
输入：word = "cuaieuouac"
输出：7
解释：下面列出 word 中的元音子字符串（斜体加粗部分）：
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"

示例 4：
输入：word = "bbaeixoubb"
输出：0
解释：所有包含全部五种元音的子字符串都含有辅音，所以不存在元音子字符串。

提示：
  1 <= word.length <= 100
  word 仅由小写英文字母组成
*/

// https://leetcode.com/problems/count-vowel-substrings-of-a-string/solutions/1563737/sliding-window/
// 抄的
int countVowelSubstrings(string word)
{
	int len = static_cast<int>(word.size());
	int vowel = 0, count = 0, have[128] = {0};
	for (int j = 0, k = 0, i = 0; i < len; ++i) {
		if (strchr("aeiou", word[i])) {
			have[(int)word[i]] += 1;
			vowel += (have[(int)word[i]] == 1);
			for (; vowel == 5; ++k) {
				have[(int)word[k]] -= 1;
				vowel -= (have[(int)word[k]] == 0);
			}
			count += k - j;
		} else {
			memset(have, 0, sizeof(have));
			vowel = 0;
			j = k = i + 1;
		}
	}
	return count;
}

int main()
{
	ToOut(countVowelSubstrings("aeiouu"));
	ToOut(countVowelSubstrings("unicornarihan"));
	ToOut(countVowelSubstrings("cuaieuouac"));
	ToOut(countVowelSubstrings("bbaeixoubb"));
}
