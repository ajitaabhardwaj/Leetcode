class Solution:
    def earliestFinishTime(self, landStartTime: List[int], landDuration: List[int], waterStartTime: List[int], waterDuration: List[int]) -> int:
        ans = float("inf")

        for i in range(len(landStartTime)):
            for j in range(len(waterStartTime)):

                # land first, then water
                land_finish = landStartTime[i] + landDuration[i]
                water_start = max(land_finish, waterStartTime[j])
                finish1 = water_start + waterDuration[j]

                # water first, then land
                water_finish = waterStartTime[j] + waterDuration[j]
                land_start = max(water_finish, landStartTime[i])
                finish2 = land_start + landDuration[i]

                ans = min(ans, finish1, finish2)

        return ans