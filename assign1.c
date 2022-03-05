#include <stdio.h>
#include <math.h>
#include "assign1.h"


int main() {
    printf("%d", quick_power(4, 3));
    return 0;
}

int quick_power(int x, int n) {
    int part_factor;
    if (n == 0) {
        return 1;
    }
    part_factor = quick_power(x, floor(n / 2));
    if (n % 2 != 0) {
        return (part_factor * part_factor * x) % (MODULO);
    } else {
        return (part_factor * part_factor) % (MODULO);
    }
}

int matrix_addition(matrix mat_a, matrix mat_b, matrix mat_res) {
    if (mat_res.m_row != mat_a.m_row ||
        mat_res.m_col != mat_a.m_col ||
        mat_a.m_row != mat_b.m_row ||
        mat_a.m_col != mat_b.m_col) {
        return 1;
    }
    for (int i = 0; i < mat_res.m_row; ++i)
        for (int j = 0; j < mat_res.m_col; ++j) {
            int val = ((long long) get_by_index(mat_a, i, j)) + get_by_index(mat_b, i, j) % MODULO;
            set_by_index(mat_res, i, j, val);
        }
    return 0;
}

int matrix_multiplication(matrix mat_a, matrix mat_b, matrix mat_res) {
    if (mat_res.m_row != mat_a.m_row ||
        mat_res.m_col != mat_b.m_col ||
        mat_a.m_col != mat_b.m_row) {
        return 1;
    }
    for (int i = 0; i < mat_res.m_row; ++i)
        for (int j = 0; j < mat_res.m_col; ++j) {
            int val = 0;
            for (int k = 0; k < mat_a.m_col; ++k)
            {
                val = val + ((long long) get_by_index(mat_a, i, k)) * get_by_index(mat_b, k, j) % MODULO;
            }
            set_by_index(mat_res, i, j, val);
        }
    return 0;
}