class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        paragraph = paragraph.replace(',',' ')
        paragraph = paragraph.split()
        new_para = []
        for word in paragraph:
            temp = ""
            for s in word:
                if s.isalpha():
                    temp += s.lower()
            new_para.append(temp)

        freq = defaultdict(int)
        for word in new_para:
            if word not in banned:
                freq[word] += 1

        return max(freq, key = lambda x : freq[x])
