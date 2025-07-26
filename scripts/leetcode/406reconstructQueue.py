from typing import List

class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        people.sort(key=lambda x: (-x[0], x[1]))
        ans = list()
        for person in people:
            ans.insert(person[1], person)
        return ans

people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
print(f"result: {Solution().reconstructQueue(people)}")