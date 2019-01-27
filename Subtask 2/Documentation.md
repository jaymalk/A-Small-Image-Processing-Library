# Subtask 2
<br>

#### Overview
  - [Command Line Arguments](#command-line-arguments)
      - [Implementations](#implementations)
    - [Convolution](#convolution)
    - [Activation](#activation)
    - [Pooling](#pooling)
  - [Other Helpful Functions](#other-helpful-functions)
      - [Matrix View](#matrix-view)
      - [Save Previous](#save-previous)

- [Performance Measurement](#performance-measurement)

<br><br>

## Command Line Arguments

We have used the approach where the user can enter a interpreter (basic) and provide commands in a continuous way. <br>

All commands defined below follow , except for one constraint that *arrow keys must not be pressed*<br>

#### Implementations

On executing the make file, three executable files will be created. These include

- `ipl_mkl`

- `ipl_oblas`

- `ipl_core.`

  <br>

To enter a particular interpreter, type `./ipl_mkl` or `./ipl_oblas` or `ipl_core`, and just type `exit` to exit. Another command `clear` can be used to clear the screen.

Also, `...` can be use to [repeat/augment](#save-previous) last command.

Note if only a single implementation is to be compiled, then just enter its code while calling `make`.  e.g. `make mkl` or `make core`

Also, to implement basic shell without any threading features just run `make old` (run as `./ipl` )

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
        Saving on file > ` max_pool matrix_file filter_size stride output_file` <br><br>
    -  _Library_ (In code)

```cpp
vector<vector<{int, float}>> maxPool(vector<vector<{int, float}>> matrix, int filterSize = 2, int stride = 2 );
```

- ***Average Pool***
    - _Command Format_ (On console) <br>
        Output on console > ` avg_pool matrix_file filter_size stride` <br>
        Saving on file > ` avg_pool matrix_file filter_size stride output_file` <br><br>
    -  _Library_ (In code)

```cpp
vector<vector<{int, float}>> avgPool(vector<vector<{int, float}>> matrix, int filterSize = 2, int stride = 2 );
```

<br><br>

## Other Helpful Functions

#### Matrix View

_To view the result in a formatted form on the console. Just for a review._

_Command Format_ <br>
    Matrix  > ` view filename num_rows` <br>
    Square Matrix  > ` view_square filename`

<br>

#### Save Previous

_To augment the previous command (output on console) and saving the output to a file_

_Command Format_ <br>
    To repeat last command  >  `...` <br>
    To augment last command (save only) > `... output_file`



## Performance Measurement

We have measured the performance of our implementation, with ***mkl*** and ***open_blas*** in various ways. These are as followed.

### Continuous multiplication

In this case, we have take matrices of order **n*n** and multiplied it with a vector of size  **n * 1** ​ .

We continuously vary **n** from *8*  - *300*,  and measure time for each multiplication. Then we plot it to get an overview of timings.

### Step multiplication

In this case, we have multiplied the same matrix a hundred times to get statistical data on multiplication.

We varied **n** from *100 - 800* with a step of *100* and measure time at each level.

We, then, plotted these values as ***Box Plot***.
