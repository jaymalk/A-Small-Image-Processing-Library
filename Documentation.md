# Documentation
## Subtask 1

### Working (Command Line Arguments)

**Convolution**<br>
_Command Format_ <br>
Output on console : `./a.out [fuction] [matrix_file] [kernel_file]` <br>
Saving on file : `./a.out [fuction] [matrix_file] [kernel_file] [output_file]` <br><br>
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





**Activation**<br>

Library
```cpp
    #include<activation>
```

- ***relu (Rectified Linear Units)***<br>
    - _Command Format_ (On console) <br>
        Output on console : `./a.out relu [matrix_file]` <br>
        Saving on file : `./a.out relu [matrix_file] [output_file]` <br><br>
    -  _Library_ (In code)<br>
        ```cpp
            vector<vector<float>> relu(<vector<vector<{float, int}>> matrix);
        ```

- ***tanh (Hyperbolic)***
    - _Command Format_ (On console) <br>
        Output on console : `./a.out tanh [matrix_file]` <br>
        Saving on file : `./a.out tanh [matrix_file] [output_file]` <br><br>
    -  _Library_ (In code)<br>
        ```cpp
        vector<vector<float>> tanh(<vector<vector<{float, int}>> matrix);
        ```

- ***Sigmoid***
    - _Command Format_ (On console) <br>
        Output on console : `./a.out sigmoid [vector_file]` <br>
        Saving on file : `./a.out sigmoid [vector_file] [output_file]` <br><br>
    -  _Library_ (In code)<br>
        ```cpp
        vector<float> sigmoid(vector<float> arr);
        ```

- ***Softmax***
    - _Command Format_ (On console) <br>
        Output on console : `./a.out softmax [vector_file]` <br>
        Saving on file : `./a.out softmax [vector_file] [output_file]` <br><br>
    -  _Library_ (In code)<br>
        ```cpp
        vector<float> softmax(vector<float> arr);
        ```

**Pooling**
```cpp
    #include<pool>
```

- ***Max Pool***<br>
    - _Command Format_ (On console) <br>
        Output on console : `./a.out max_pool [filterSize] [stride] [matrix_file]` <br>
        Saving on file : `./a.out max_pool [filterSize] [stride] [matrix_file] [output_file]` <br><br>
    -  _Library_ (In code)<br>
        ```cpp
            vector<vector<{int, float}>> maxPool(vector<vector<{int, float}>> matrix, int filterSize = 2, int stride = 2 );
        ```

- ***Average Pool***
    - _Command Format_ (On console) <br>
        Output on console : `./a.out avg_pool [filterSize] [stride] [matrix_file]` <br>
        Saving on file : `./a.out avg_pool [filterSize] [stride] [matrix_file] [output_file]` <br><br>
    -  _Library_ (In code)<br>
        ```cpp
        vector<vector<{int, float}>> avgPool(vector<vector<{int, float}>> matrix, int filterSize = 2, int stride = 2 );
        ```

### Exceptions

Message | Cause
------------ | -------------
_File not found_ | [matrix_file] or [kernel_file] non-existent
_Size Error_    | Order(kernel) > Order(matrix)
_Invalid Function_ | Function type is not suitable
__ |
_Unknown Error_ | Fault on our side :sweat_smile:
