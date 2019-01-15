# A-Small-Image-Processing-Library
An image processing library with basic features created in C++

The library is completed in a series of steps (subtasks), completed in order.

## Subtask 1
[Docutmentation]("./Subtask%201/Documentation.md")<br>
  Implement the following functions using 32 bit float as datatype.
  - **Convolution** of a *square input matrix* and a *square kernel*, both matrices of any size and the kernel smaller than the input,
    - with and without **padding** to maintain or reduce the size of the input matrix.
    - implement the function both as convolution and as matrix multiplication.
  - Non-linear activations of an input matrix of any size with **rlu (Rectified Linear Units)** and **tanh (Hypeborlic)** functions on individual matrix elements.
  - *Sub-sampling* of square input matrices of any size with **max pooling** and **average pooling** functions.
  - Converting a *vector of random floats* to a *vector of probabilities* with **softmax** and **sigmoid** functions.
