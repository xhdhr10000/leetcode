

bool isBoomerang(int** points, int pointsSize, int* pointsColSize){
    if (pointsSize != 3) return false;
    if (points[0][0]==points[1][0] && points[0][1]==points[1][1] ||
        points[0][0]==points[2][0] && points[0][1]==points[2][1] ||
        points[1][0]==points[2][0] && points[1][1]==points[2][1]) return false;
    if (points[0][1]==points[1][1] && points[0][1]==points[2][1]) return false;
    if (fabs((float)(points[0][0]-points[1][0]) / (float)(points[0][1]-points[1][1]) - 
        (float)(points[0][0]-points[2][0]) / (float)(points[0][1]-points[2][1])) < 0.00001) return false;
    return true;
}
