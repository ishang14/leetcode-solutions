#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        const int DIR_OFFSET = 2000;
        const int SUM_OFFSET = 4000;

        // ---------- 1) Count non-degenerate parallelograms ----------
        // Using midpoint trick: two segments with same midpoint and non-collinear diagonals
        struct MidInfo {
            long long total = 0;  // number of segments with this midpoint
            unordered_map<long long, int> dirCount; // direction -> how many segments
        };

        unordered_map<long long, MidInfo> midMap;

        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; ++j) {
                int x2 = points[j][0], y2 = points[j][1];

                // Midpoint key (use sums, avoid fractions)
                int sx = x1 + x2;
                int sy = y1 + y2;
                long long midKey =
                    ( (long long)(sx + SUM_OFFSET) << 32 ) ^
                      (long long)(sy + SUM_OFFSET);

                // Direction of this segment (normalized)
                int dx = x2 - x1;
                int dy = y2 - y1;
                int g = std::gcd(dx, dy);
                dx /= g; dy /= g;

                // Canonical orientation: dx > 0 OR dx == 0 & dy > 0
                if (dx < 0 || (dx == 0 && dy < 0)) {
                    dx = -dx;
                    dy = -dy;
                }
                long long dirKey =
                    ( (long long)(dy + DIR_OFFSET) << 32 ) ^
                      (long long)(dx + DIR_OFFSET);

                auto &info = midMap[midKey];
                info.total++;
                info.dirCount[dirKey]++;
            }
        }

        long long parallelograms = 0;

        for (auto &it : midMap) {
            auto &info = it.second;
            long long k = info.total;
            if (k < 2) continue;

            long long totalPairs = k * (k - 1) / 2;  // all pairs of segments
            long long bad = 0; // pairs whose diagonals are collinear => degenerate

            for (auto &dc : info.dirCount) {
                long long c = dc.second; // segments with same direction
                bad += c * (c - 1) / 2;
            }

            parallelograms += (totalPairs - bad);
        }

        // ---------- 2) Count all quadrilaterals with at least one pair of parallel sides ----------
        // Do this by counting 4-point sets with 2 points on each of two parallel lines.

        // slopeKey -> ( lineKey -> set of point indices )
        // slope normalized (dy, dx), lineKey = dy*x - dx*y for any point on line
        unordered_map<long long, unordered_map<long long, unordered_set<int>>> slopeMap;

        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; ++j) {
                int x2 = points[j][0], y2 = points[j][1];

                int dx = x2 - x1;
                int dy = y2 - y1;
                int g = std::gcd(dx, dy);
                dx /= g; dy /= g;

                if (dx < 0 || (dx == 0 && dy < 0)) {
                    dx = -dx;
                    dy = -dy;
                }

                long long slopeKey =
                    ( (long long)(dy + DIR_OFFSET) << 32 ) ^
                      (long long)(dx + DIR_OFFSET);

                long long lineKey = 1LL * dy * x1 - 1LL * dx * y1;

                auto &lineMap = slopeMap[slopeKey];
                auto &ptSet = lineMap[lineKey];
                ptSet.insert(i);
                ptSet.insert(j);
            }
        }

        long long totalWithParallel = 0;

        for (auto &sPair : slopeMap) {
            auto &lineMap = sPair.second;

            // For this slope, gather A_i = C(cnt(line_i), 2)
            vector<long long> A;
            A.reserve(lineMap.size());
            for (auto &lPair : lineMap) {
                int c = (int)lPair.second.size();
                if (c >= 2) {
                    long long waysOnLine = 1LL * c * (c - 1) / 2;
                    A.push_back(waysOnLine);
                }
            }
            if (A.size() < 2) continue; // need at least two lines

            long long sumA = 0, sumA2 = 0;
            for (long long x : A) {
                sumA += x;
                sumA2 += x * x;
            }

            // Sum over unordered pairs of lines: Σ_{i<j} A_i * A_j
            long long contrib = (sumA * sumA - sumA2) / 2;
            totalWithParallel += contrib;
        }

        // Each non-parallelogram trapezoid counted once,
        // each parallelogram counted twice (two directions of sides).
        long long result = totalWithParallel - parallelograms;
        return result;
    }
};
