#include <array>
#include <iostream>

template<typename T, size_t R, size_t C>
using basic_matrix = std::array<std::array<T, R>, C>;

using matrix = basic_matrix<int, 6, 6>;

int diagonal_sum(const matrix& mat) noexcept
{
    int sum = 0;
    
    for (size_t i = 0; i != mat.size(); i++)
        sum += mat[i][i];
    
    return sum;
}

void tranpose(matrix& mat)
{
    matrix temp = {};

    for (size_t i = 0; i != mat.size(); i++)
    {
        for (size_t j = 0; j != 6; j++)
            temp[i][j] = mat[j][i];
    }

    mat = temp;
}

void print_matrix(const matrix& mat) noexcept
{
    for (const auto& row : mat)
    {
        std::copy(row.cbegin(), row.cend(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << '\n';
    }
}

int main()
{
    int matrix_buffer[36u];
    
    std::copy_n(std::istream_iterator<int>(std::cin), std::size(matrix_buffer), matrix_buffer);
    
    std::cout << "Matrix: " << '\n';

    auto mat = *reinterpret_cast<matrix*>(matrix_buffer);
    print_matrix(mat);

    std::cout << "Tranposed: " << '\n';
    
    tranpose(mat);
    print_matrix(mat);

    return 0;
}
