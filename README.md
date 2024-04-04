# qt-dynamic-library
Testbed to include dynamic libraries during runtime

This project ist based on [this tutorial](https://wiki.qt.io/How_to_create_a_library_with_Qt_and_use_it_in_an_application). In addition, here is a function with a parameter used.

## Basic test
### Create shared libs
Enter the ```library``` folder, run ```qmake``` and ```make```:

```sh
cd library
qmake
make
```

Verify that your shared lib files are created.

```
ls *.so*
liblib.so  liblib.so.1  liblib.so.1.0  liblib.so.1.0.0
```

### Build your main application

Enter the main folder, run ```qmake``` and ```make```:

```sh
qmake
make
```

A ```hellolib``` binary is created. Execute it and you should see some output, like:

```
./hellolib
library loaded
getCurve loaded!
Returned val from library for  0 :  0
Returned val from local   for  0 :  0
Returned val from library for  0.2 :  0.08
Returned val from local   for  0.2 :  0.08
Returned val from library for  0.4 :  0.32
Returned val from local   for  0.4 :  0.32
Returned val from library for  0.6 :  0.68
Returned val from local   for  0.6 :  0.68
Returned val from library for  0.8 :  0.92
Returned val from local   for  0.8 :  0.92
Returned val from library for  1 :  1
Returned val from local   for  1 :  1
```