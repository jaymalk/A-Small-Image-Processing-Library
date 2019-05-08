# A-Small-Image-Processing-Library
An image processing library with basic features created in C++

The library is completed in a series of steps (subtasks), completed in order.

## Subtask 1
[Docutmentation](./Subtask%201/Documentation.md)<br>
  Implement the following functions using 32 bit float as datatype.
  - **Convolution** of a *square input matrix* and a *square kernel*, both matrices of any size and the kernel smaller than the input,
    - with and without **padding** to maintain or reduce the size of the input matrix.
    - implement the function both as convolution and as matrix multiplication.
  - Non-linear activations of an input matrix of any size with **rlu (Rectified Linear Units)** and **tanh (Hypeborlic)** functions on individual matrix elements.
  - *Sub-sampling* of square input matrices of any size with **max pooling** and **average pooling** functions.
  - Converting a *vector of random floats* to a *vector of probabilities* with **softmax** and **sigmoid** functions.

## Subtask 2
[Docutmentation](./Subtask%202/Documentation.md)<br>
  Extend and optimise the previous design by implementing multi-threading.
   - Use ```POSIX Threads``` to implement various functionalities including *matrix-multiplications* to parrallely execute associative/independent operations.
   - Use other open source libraries such as ```mkl``` and ```openblas```, to achieve the same extension to your desing.
   - Compare performance and plot the result. Use ```gnuplot``` for plotting.
    
   - Results : We were very well able to compete with open-blas but mkl had an advantage as it made use of architecture much better than us.
  <p align="center">
        <img src = "./Subtask%202/continuous.png">
  </p>

## Subtask 3
[Docutmentation](/Subtask%203/Documentation.md)<br>
  Use the present design to implement **LeNet architecture** for digit-recognition.
  - Result : We achieved an accuracy of \(98.9%\) when testing our design on *MNIST data set*.
  - Dependencies : We have used ```python cv2``` for converting our image to a desirable format.
