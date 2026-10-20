class Solution(object):
    def findSmallestSetOfVertices(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        has_incoming = set()
        for u, v in edges:
            has_incoming.add(v)

        return [i for i in range(n) if i not in has_incoming]
        
