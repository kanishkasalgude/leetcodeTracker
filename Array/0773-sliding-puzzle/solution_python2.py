from collections import deque
class Solution(object):
    def slidingPuzzle(self, board):
        """
        :type board: List[List[int]]
        :rtype: int
        """
        start_state = "".join(str(num) for row in board for num in row)
        target = "123450"
        #012
        #345
        moves = {
            0:[1,3],
            1:[0,2,4],
            2:[1,5],
            3:[0,4],
            4:[1,3,5],
            5:[2,4]
        }

        queue = deque([(start_state, 0)])
        visited = {start_state}

        while queue:
            state, steps = queue.popleft()
            if state == target:
                return steps
            zero_idx = state.index('0')
            for next_idx in moves[zero_idx]:
                state_list = list(state)
                state_list[zero_idx], state_list[next_idx] = state_list[next_idx], state_list[zero_idx]
                new_state = "".join(state_list)

                if new_state not in visited:
                    visited.add(new_state)
                    queue.append((new_state, steps+1))
        return -1

        
