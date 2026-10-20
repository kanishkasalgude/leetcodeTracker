class Solution(object):
    def networkDelayTime(self, times, n, k):
        """
        :type times: List[List[int]]
        :type n: int
        :type k: int
        :rtype: int
        """
        graph = collections.defaultdict(list)
        min_heap = [(0,k)]
        shortest_times ={}

        for u,v,w in times:
            graph[u].append((v,w))

        while(min_heap):
            time, u = heapq.heappop(min_heap)
            if u in shortest_times:
                continue

            shortest_times[u] = time
            for v, w in graph[u]:
                if v not in shortest_times:
                    heapq.heappush(min_heap, (time+w, v))

        if len(shortest_times) == n:
            return max(shortest_times.values())
        return -1
        
