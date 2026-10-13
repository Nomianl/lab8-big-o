/*
 * Course: COEN 2220 - Programming 2
 * Name: [Your Name]
 * Lab: Lab 8 - Big-O / Time Complexity
 * Description: Resolved code for time-complexity analysis
 * Due date: [Date]
 */

#include <iostream>
using namespace std;

/* Returns the ID stored at a valid position already known by the caller. */
int getActivityIdAt(const int activityIds[], int activityIndex)
{
    return activityIds[activityIndex]; // Read one known array position.
}

/* Returns how many activities have an active status. */
int countActiveActivities(const bool isActive[], int activityCount)
{
    int activeCount = 0;

    for (int index = 0; index < activityCount; index++)
    {
        if (isActive[index])
        {
            activeCount++;
        }
    }

    return activeCount;
}

/*
 * Returns how many middle IDs binary search compares before finding targetId.
 * Precondition: activityIds is sorted in ascending order and contains targetId.
 */
int countBinaryComparisons(const int activityIds[], int activityCount, int targetId)
{
    int first = 0;
    int last = activityCount - 1;
    int comparisons = 0;

    while (first <= last)
    {
        int middle = (first + last) / 2;
        comparisons++;

        if (activityIds[middle] == targetId)
        {
            break;
        }
        else if (activityIds[middle] < targetId)
        {
            first = middle + 1;
        }
        else
        {
            last = middle - 1;
        }
    }

    return comparisons;
}

/* Returns how many times a positive count can be reduced by half before reaching 1. */
int countHalvingSteps(int itemCount)
{
    int steps = 0;

    while (itemCount > 1)
    {
        itemCount = itemCount / 2; // Remove approximately half of the remaining items.
        steps++;
    }

    return steps;
}

/* Returns the number of distinct activity pairs visited by two nested loops. */
int countPossiblePairs(int activityCount)
{
    int pairCount = 0;

    for (int first = 0; first < activityCount; first++)
    {
        for (int second = first + 1; second < activityCount; second++)
        {
            pairCount++; // One distinct pair would be compared here.
        }
    }

    return pairCount;
}

int main()
{
    // These activity IDs are sorted so binary search is valid.
    int activityIds[] = {101, 104, 108, 115, 130, 136, 140, 155};
    bool isActive[] = {true, false, true, true, false, false, true, false};
    int activityCount = 8;

    cout << "Activity at index 2: "
         << getActivityIdAt(activityIds, 2) << endl;
    cout << "Active activities: "
         << countActiveActivities(isActive, activityCount) << endl;
    cout << "Binary comparisons for 140: "
         << countBinaryComparisons(activityIds, activityCount, 140) << endl;
    cout << "Halving steps for 8: " << countHalvingSteps(8) << endl;
    cout << "Halving steps for 16: " << countHalvingSteps(16) << endl;
    cout << "Halving steps for 32: " << countHalvingSteps(32) << endl;
    cout << "Possible pairs for 4 activities: " << countPossiblePairs(4) << endl;
    cout << "Possible pairs for 8 activities: " << countPossiblePairs(8) << endl;

    return 0;
}

/*
 * Analysis Answers
 *
 * C1 — Direct access
 * Answer: Here, n is the number of activities in the array. The representative
 * operation is reading activityIds[activityIndex], which takes O(1) time
 * because the function accesses one known position without traversing the array.
 *
 * C2 — Count active activities
 * Answer: Here, n is the number of activities to check. The loop examines each
 * isActive entry once, so countActiveActivities takes O(n) time; the output
 * shows 4 active activities among the 8 entries.
 *
 * C3 — Binary search
 * Answer: Here, n is the number of IDs, and the representative operation is
 * comparing the middle ID with targetId. The function takes O(log n) time
 * because each comparison discards about half of the remaining range. The IDs
 * must be sorted in ascending order; otherwise, the function cannot reliably
 * choose which half to discard. The output finds 140 in 3 comparisons.
 *
 * C4 — Halving steps
 * Answer: Starting at 16, itemCount changes as 16, 8, 4, 2, 1. The function
 * repeatedly divides itemCount by 2, taking 4 steps; increasing the input from
 * 16 to 32 adds just one step (from 4 to 5), which is O(log n) growth.
 *
 * C5 — Distinct pairs
 * Answer: The second loop starts at first + 1 so an activity is not paired
 * with itself and each pair is counted only once. Starting it at 0 would count
 * self-pairs and count each distinct pair in both orders. The nested loops make
 * the function O(n^2); the output reports 6 pairs for 4 activities and 28 for 8.
 *
 * C6 — Compare the observed patterns
 * Answer: Direct access reads one known array position and returns 108, which
 * supports O(1). Counting checks all 8 statuses and finds 4 active activities,
 * supporting O(n), while halving takes 3, 4, and 5 steps for 8, 16, and 32,
 * supporting O(log n). Pair counts rise from 6 for 4 activities to 28 for 8,
 * and the two nested loops support O(n^2).
 *
 * C7 — Sorting decision
 * Answer: If I only need to search once in unsorted IDs, I would use linear
 * search and avoid the cost of sorting first. If I need to search the same IDs
 * many times, sorting once may be worthwhile so I can use binary search for
 * each query. Sorting by a comparison-based algorithm typically costs
 * O(n log n), as discussed in lecture.
 *
 */