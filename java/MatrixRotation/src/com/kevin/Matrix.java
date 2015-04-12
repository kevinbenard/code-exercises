package com.kevin;

/**
 * Created by kevin on 4/11/2015.
 */
public class Matrix {
    public char[][] matrix;
    public int height = 0;
    public int width = 0;

    public Matrix(char[][] mat, int height, int width) {
        this.matrix = mat;
        this.width = width;
        this.height = height;
    }

    public void rotate() {
        System.out.println("Width: " + this.width);
        System.out.println("Height: " + this.height);

        // One left to right scan to shift each cell
        for (int i = 0; i < width; ++i) {
            // (0, 0) goes to (9, 0)
            // (9, 0) goes to (9, 8)
            // (9, 8) goes to (0, 8)
            // (0, 8) goes to (0, 0)
        }
        System.out.println("(9, 8): " + this.matrix[8][9]);
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();

        for (char[] mat_arr: this.matrix) {
            for (char c: mat_arr) {
               sb.append(" " + c);
            }
            sb.append("\n");
        }

        return sb.toString();
    }
}
