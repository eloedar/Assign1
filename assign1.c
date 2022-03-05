#include <stdio.h>
#include <math.h>
#include "assign1.h"


int main() {
    printf("%d", quick_power(258993530, 15223259));
    return 0;
}

int quick_power(int x, int n) {
    unsigned long long ans = 1;
    unsigned long long power_factor = (unsigned long long) x;
    while (n != 0) {
        if (n % 2 != 0) {
            ans = (ans * power_factor % (MODULO));
        }
        power_factor = (power_factor * power_factor%(MODULO));
        n = n / 2;
    }
    return ans % (MODULO);
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
            for (int k = 0; k < mat_a.m_col; ++k) {
                val = val + ((long long) get_by_index(mat_a, i, k)) * get_by_index(mat_b, k, j) % MODULO;
            }
            set_by_index(mat_res, i, j, val);
        }
    return 0;
}