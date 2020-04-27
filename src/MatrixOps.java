public class MatrixOps {
    static class Matrix {
        int rows;
        int cols;
        int[][] matrix;

        Matrix(int rows, int cols) {
            this.rows = rows;
            this.cols = cols;
            this.matrix = new int[rows][cols];
        }

    }

    private static Matrix multiplyMat(Matrix m1, Matrix m2) {
        if (m1.cols != m2.rows) {
            return null;
        }

        Matrix ans = new Matrix(m1.rows, m2.cols);

        for (int i = 0; i < ans.rows; i++) {
            for (int j = 0; j < ans.cols; j++) {
                for (int k = 0; k < m1.cols; k++) {
                    ans.matrix[i][j] += m1.matrix[i][k] * m2.matrix[k][j];
                }
            }
        }
        return ans;
    }

    private static void printMatrix(Matrix pr) {
        for (int i = 0; i < pr.rows; i++) {
            for (int j = 0; j < pr.cols; j++) {
                System.out.print(pr.matrix[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Matrix m1 = new Matrix(2,3);
        Matrix m2 = new Matrix(3,2);

        m1.matrix = new int[][]{{1, 2, 3}, {4, 5, 6}};
        m2.matrix = new int[][]{{7,8}, {9,10}, {11, 12}};

        Matrix a = multiplyMat(m1, m2);

        assert a != null;
        printMatrix(a);
    }

}
