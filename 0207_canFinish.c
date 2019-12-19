// Author: xhdhr10000
// Date: 2019-10-06
bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize){
    int *indegree = (int*)malloc(sizeof(int)*numCourses);
    bool *visited = (bool*)malloc(sizeof(bool)*numCourses);
    bool *matrix = (bool*)malloc(sizeof(bool)*numCourses*numCourses);
    int count = 0;

    memset(indegree, 0, sizeof(int)*numCourses);
    memset(visited, 0, sizeof(bool)*numCourses);
    memset(matrix, 0, sizeof(bool)*numCourses*numCourses);
    for (int i=0; i<prerequisitesSize; i++) {
        int a = prerequisites[i][0], b = prerequisites[i][1];
        indegree[a]++;
        matrix[b*numCourses+a] = true;
    }
    while (count < numCourses) {
        bool flag = false;
        for (int i=0; i<numCourses; i++) {
            if (!visited[i] && indegree[i] == 0) {
                flag = true;
                visited[i] = true;
                count++;
                for (int j=0; j<numCourses; j++) {
                    if (matrix[i*numCourses+j]) indegree[j]--;
                }
            }
        }
        if (!flag) break;
    }
    return count == numCourses;
}


