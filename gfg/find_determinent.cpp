int determinantOfMatrix(std::vector<std::vector<int>> matrix, int n) {
    // code here
    if (n == 1)
        return matrix[0][0];

    if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        std::vector<std::vector<int>> second(n - 1, std::vector<int>(n - 1));
        ///travers row
        for (int j = 1; j < n; j++) {
            // traverse columns
            int x = 0;
            for (int k = 0; k < n; k++) {
                if (k == i) //to find determinent we leave that which in the same column 
                    continue;

                second[j - 1][x++] = matrix[j][k];
            }
        }

        ans += matrix[0][i] * determinantOfMatrix(second, n - 1) * ((i & 1) ? -1 : 1);
    }                                                              // this for alternate sign//
                                                                   //if odd position the -1//

    return ans;
}