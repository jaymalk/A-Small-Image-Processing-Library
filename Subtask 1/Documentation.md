# Subtask 1
<br>

#### Overview
  - [Command Line Arguments](#command-line-arguments)
    -   [Convolution](#convolution)
    -   [Activation](#activation)
    -   [Pooling](#pooling)
  - [Other Helpful Functions](#other-helpful-functions)

<br><br>

## Command Line Arguments

We have used the aproach where the user can enter a interpreter (basic) and provide commands in a continous way. <br>

All commands defined bellow follow , except for one constraint that *arrow keys must not be pressed*<br>

To enter the interpreter type `./ipl` and just type `exit` to exit. Also, `clear` can be used to clear the screen.

<br><br>

#### Convolution

```cpp
    #include "convolution.h"
```

_Command Format_ <br>
Output on console > ` function matrix_file kernel_file` <br>
Saving on file > ` function matrix_file kernel_file output_file` <br><br>

- Direct convolution

Task | Function
------------ | -------------
Convolution without padding | ```conv```
Convolution with padding | ```conv_pad```
Cross-correlation without padding | ```cross```
Cross-correlation with padding | ```cross_pad```


- Matrix multiplication

Task | Function
------------ | -------------
Convolution without padding | ```conv_mult```
Convolution with padding | ```conv_mult_pad```
Cross-correlation without padding | ```cross_mult```
Cross-correlation with padding | ```cross_mult_pad```


_Library (In code)_

- Direct Convolution/Cross-correlation

```cpp
vector<vector<float>> directConvolution(vector<vector<float>> kernel, vector<vector<float>> matrix, bool convolution, bool padding=false)
```

 - Convolution/Cross-correlation by matrix-multiplication

```cpp
vector<vector<float>> convolutionByMultiplication(vector<vector<float>> kernel, vector<vector<float>> matrix, bool convolution, bool padding=false)
```


### Activation

```cpp
    #include "activation.h"
```


- ***relu (Rectified Linear Units)***
    - _Command Format_ (On console) <br>
        Output on console > ` relu matrix_file num_rows` <br>
        Saving on file > ` relu matrix_file num_rows output_file` <br><br>
    -  _Library_ (In code)<br>
        ```cpp
        vector<vector<float>> relu(<vector<vector<{float, int}>> matrix);
        ```

- ***tanh (Hyperbolic)***
    - _Command Format_ (On console) <br>
        Output on console > ` tanh matrix_file num_rows` <br>
        Saving on file > ` tanh matrix_file num_rows output_file` <br><br>
    -  _Library_ (In code)<br>
        ```cpp
        vector<vector<float>> tanh(<vector<vector<{float, int}>> matrix);
        ```

- ***Sigmoid***
    - _Command Format_ (On console) <br>
        Output on console > ` sigmoid vector_file` <br>
        Saving on file > ` sigmoid vector_file output_file` <br><br>
    -  _Library_ (In code)<br>
        ```cpp
        vector<float> sigmoid(vector<float> arr);
        ```

- ***Softmax***
    - _Command Format_ (On console) <br>
        Output on console > ` softmax vector_file` <br>
        Saving on file > ` softmax vector_file output_file` <br><br>
    -  _Library_ (In code)<br>
        ```cpp
        vector<float> softmax(vector<float> arr);
        ```

### Pooling
```cpp
    #include "pool.h"
```

- ***Max Pool***<br>
    - _Command Format_ (On console) <br>
        Output on console > ` max_pool matrix_file filter_size stride` <br>
        Saving on file > ` max_pool matrix_file output_file filter_size stride` <br><br>
    -  _Library_ (In code)

```cpp
vector<vector<{int, float}>> maxPool(vector<vector<{int, float}>> matrix, int filterSize = 2, int stride = 2 );
```

- ***Average Pool***
    - _Command Format_ (On console) <br>
        Output on console > ` avg_pool matrix_file filter_size stride` <br>
        Saving on file > ` avg_pool matrix_file output_file filter_size stride` <br><br>
    -  _Library_ (In code)

```cpp
vector<vector<{int, float}>> avgPool(vector<vector<{int, float}>> matrix, int filterSize = 2, int stride = 2 );
```

<br><br>

## Other Helpful Functions

##### **Matrix View**  (View the matrix for comparison)<br>

_Command Format_ <br>
    Matrix  > ` view filename num_rows` <br>
    Square Matrix  > ` view_square filename`
