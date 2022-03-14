#include <stdio.h>
#include "assign1.h"


int main() {
//    matrix test = create_matrix_all_zero(2, 2);
//    set_by_index(test, 0, 0, 4);
//    set_by_index(test, 0, 1, -1);
//    set_by_index(test, 1, 0, 2);
//    set_by_index(test, 1, 1, 3);
//    matrix res = create_matrix_all_zero(2, 2);
//    matrix res2 = create_matrix_all_zero(2, 2);
//    fast_matrix_exp(test, 12, res);
//    printf("fast: %d %d \n", get_by_index(res, 0, 0), get_by_index(res, 0, 1));
//    printf("fast: %d %d\n", get_by_index(res, 1, 0), get_by_index(res, 1, 1));
//    naive_matrix_exp(test, 12, res2);
//    printf("na: %d %d \n", get_by_index(res2, 0, 0), get_by_index(res2, 0, 1));
//    printf("na: %d %d\n", get_by_index(res2, 1, 0), get_by_index(res2, 1, 1));
    matrix test = create_matrix_all_zero(2, 2);
    matrix ans = create_matrix_all_zero(2, 2);
    set_by_index(test,0,0,1e9);
    matrix_addition(test,test,ans);
    printf("%d\n", get_by_index(ans,0,0));

    return 0;

}

int quick_power(int x, int n) {
    unsigned long long ans = 1;
    unsigned long long power_factor = (unsigned long long) x;
    while (n != 0) {
        if (n % 2 != 0) {
            ans = (ans * power_factor % (MODULO));
        }
        power_factor = (power_factor * power_factor % (MODULO));
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
            int val = ((long)get_by_index(mat_a, i, j) + (long)get_by_index(mat_b, i, j)) % MODULO;
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
            long long val = 0;
            for (int k = 0; k < mat_a.m_col; ++k) {
                val = val % MODULO +
                      ((long long) get_by_index(mat_a, i, k) * (long long) get_by_index(mat_b, k, j)) % MODULO;
            }
            set_by_index(mat_res, i, j, val % MODULO);
        }
    return 0;
}

int naive_matrix_exp(matrix mat_a, int exp, matrix mat_res) {
    if (mat_a.m_col != mat_a.m_row || mat_res.m_col != mat_a.m_col) {
        return 1;
    }
    matrix medium = create_matrix_all_zero(mat_a.m_row, mat_a.m_col);
    matrix res_med = copy_matrix(mat_a);
    for (int i = 0; i < exp - 1; ++i) {
        matrix_multiplication(res_med, mat_a, medium);
        res_med = copy_matrix(medium);
//        printf("%d %d \n", get_by_index(res_med,0,0), get_by_index(res_med,0,1));
//        printf("%d %d \n", get_by_index(res_med,1,0), get_by_index(res_med,1,1));
    }

    scalar_multiplication(res_med, 1, mat_res);
    return 0;
}

int fast_matrix_exp(matrix mat_a, long long exp, matrix mat_res) {
    if (mat_a.m_col != mat_a.m_row || mat_res.m_col != mat_a.m_col) {
        return 1;
    }
    matrix ans = create_matrix_all_zero(mat_a.m_col, mat_a.m_col);
    for (int j = 0; j < mat_a.m_col; ++j) {
        set_by_index(ans, j, j, 1);
    }
    matrix med = create_matrix_all_zero(mat_a.m_col, mat_a.m_col);
    matrix power_factor = create_matrix_all_zero(mat_a.m_col, mat_a.m_col);
    scalar_multiplication(mat_a, 1, power_factor);
    while (exp != 0) {
        if (exp % 2 != 0) {
            matrix_multiplication(ans, power_factor, med);
            scalar_multiplication(med, 1, ans);
        }
        matrix_multiplication(power_factor, power_factor, med);
        scalar_multiplication(med, 1, power_factor);
        exp = exp / 2;
    }
    scalar_multiplication(ans, 1, mat_res);
    return 0;
}