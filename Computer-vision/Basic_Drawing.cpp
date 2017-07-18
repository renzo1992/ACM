//the draws are line, elipse, rectangle, circle, polygon.

/** @brief Returns a zero array of the specified size and type.

    The method returns a Matlab-style zero array initializer. It can be used to quickly form a constant
    array as a function parameter, part of a matrix expression, or as a matrix initializer. :
    @code
        Mat A;
        A = Mat::zeros(3, 3, CV_32F);
    @endcode
    In the example above, a new matrix is allocated only if A is not a 3x3 floating-point matrix.
    Otherwise, the existing matrix A is filled with zeros.
    @param rows Number of rows.
    @param cols Number of columns.
    @param type Created matrix type.
     */
    static MatExpr zeros(int rows, int cols, int type);
**/
