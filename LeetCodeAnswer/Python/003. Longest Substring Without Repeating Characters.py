class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        lookup = {}
        record = 0
        ans = 0
        for ii in range(len(s)):
            if s[ii] in lookup.keys():
                record = max(lookup[s[ii]], record)
            ans = max(ans, ii - record + 1)
            lookup[s[ii]] = ii + 1
        return ans
                