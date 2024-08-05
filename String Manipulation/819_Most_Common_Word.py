class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:

        #Erase ',' to whitespace in the given sentence
        paragraph = paragraph.replace(',',' ')
        
        #split the sentence into a list where each word is in the list
        paragraph = paragraph.split()
        
        #add all words in lower case to new list
        new_para = []
        for word in paragraph:
            temp = ""
            for s in word:
                if s.isalpha():
                    temp += s.lower()
            new_para.append(temp)

        #count frequency of words
        freq = defaultdict(int)
        for word in new_para:
            if word not in banned:
                freq[word] += 1

        #return maximum count of words
        return max(freq, key = lambda x : freq[x])
