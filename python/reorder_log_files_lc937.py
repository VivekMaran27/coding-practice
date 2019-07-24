class Solution:
    
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        def getKey(ele):
            id, rest = ele.split(' ', 1)
            return (0, rest, id) if rest[0].isalpha() else (1, )
        return sorted(logs, key=lambda ele: getKey(ele))
