
# For multiple compilations using a single file

if [ $1 = "oblas" ];
then

    echo "Beginning open blas compilation..."

    sed ' s/convolution_without_threading/convolution_blas/' include/func/conv/handle.h > include/func/conv/handle_oblas.h

    sed ' s/\\n>/\\n\(oblas\) >/' interpreter.cpp > interpreter_temp.cpp
    sed ' s/handle.h/handle_oblas.h/' interpreter_temp.cpp > interpreter_oblas.cpp

    g++ -o ipl_oblas interpreter_oblas.cpp -I /include/ -L/lib/ -lopenblas -lpthread

    rm -f interpreter_oblas.cpp interpreter_temp.cpp ./include/func/conv/handle_oblas.h

elif [ $1 = "mkl" ];
then

    echo "Beginning mkl compilation..."

    sed ' s/convolution_without_threading/convolution_mkl/' include/func/conv/handle.h > include/func/conv/handle_mkl.h

    sed ' s/\\n>/\\n\(mkl\) >/' interpreter.cpp > interpreter_temp.cpp
    sed ' s/handle.h/handle_mkl.h/' interpreter_temp.cpp > interpreter_mkl.cpp

    g++ -o ipl_mkl interpreter_mkl.cpp -L${MKLROOT}/lib/intel64 -Wl,--no-as-needed -lmkl_intel_ilp64 -lmkl_gnu_thread -lmkl_core -lgomp -lpthread -lm -ldl

    rm -f interpreter_mkl.cpp interpreter_temp.cpp ./include/func/conv/handle_mkl.h

else

    echo "Beginning core compilation..."

    sed ' s/convolution_without_threading/convolution_threaded/' include/func/conv/handle.h > include/func/conv/handle_core.h

    sed ' s/\\n>/\\n\(core\) >/' interpreter.cpp > interpreter_temp.cpp
    sed ' s/handle.h/handle_core.h/' interpreter_temp.cpp > interpreter_core.cpp

    g++ -o ipl_core interpreter_core.cpp -lpthread

    rm -f interpreter_core.cpp interpreter_temp.cpp ./include/func/conv/handle_core.h
fi

echo "Compilation complete."
