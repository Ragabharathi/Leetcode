Input: strs = ["flower","flow","flight"]
Output: "fl"

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        common = []
        for l in strs[0]:
            if all(s.startswith("".join(common)+l) for s in strs):
                common.append(l)
            else:
                break
        return "".join(common)  
