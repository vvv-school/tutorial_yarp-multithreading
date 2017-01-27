Tutorial on YARP Multithreading 
=======================================

This tutorial will guide you to understand and develope a multi-thread module using YARP threads API. 
After doing this tutorial you will be expected to know how to write a proper multi-thread module, using semaphore and etc. 


will guide you to the use 
- [yarp::os::Thread] (http://www.yarp.it/classyarp_1_1os_1_1Thread.html)
- [yarp::os::Semaphore] (http://www.yarp.it/classyarp_1_1os_1_1Semaphore.html)
- [yarp::sig::ImageOf<T>] (http://www.yarp.it/classyarp_1_1sig_1_1ImageOf.html) 
- etc 


# Tutorial
In this tutorial we will develop e YARP module called `tutorial_yarp-multithreading` to produce a painted image in YARP and send it via YARP port. We will use multiple thread to take advantage of multi core CPUs for faster data proccessing. 

![module](/misc/tutorial_yarp-multithreading.png)

# Build and Install the code
Follow these steps to build and properly install your module: 
```
$ cd tutotial_RFModule
$ mkdir build; cd build
$ cmake ../
$ make
$ make install
```
the `make install` will install your module (binary, xml files, etc) in the icub contrib folder which is already setup on your machine. 

# Running the tutorial application
- Simply run the `yarpmanager` and open/run the `Tutorial_yarp-multithreading` application for the GUI then connect the ports: 

```
$ yarpmanager
```
you should be able to see the following output on the `yarpview`: 

![module](/misc/threads_1.png)

While the module is running, right click on the `tutorial_yarp-multithreading` and *attch to stdout* to see the messages printed by the module. Alternatively you can run the `yarplogger` and monitors the printed messages there. The module continuously print the total processing time to create (paint) the image. 

```
$ tutorial_yarp-multithreading --threads 1 --width 320 --height 240
[INFO]Processing time  37.38 ms 
[INFO]Processing time  37.303 ms 
...
```

**Running `tutorial_yarp-multithreading` with two threads**

Stop the module, duble click on the paramaters and change the `--threads` param to `--threads 2`. Or simply run it from the terminal: 

```
$ tutorial_yarp-multithreading --threads 2 --width 320 --height 240
[INFO]Processing time  16.5989 ms 
[INFO]Processing time  16.8562 ms 
...
```

![module](/misc/threads_2.png)

**Running `tutorial_yarp-multithreading` with four threads**

Stop the module, duble click on the paramaters and change the `--threads` param to `--threads 4`. Or simply run it from the terminal: 

```
$ tutorial_yarp-multithreading --threads 4 --width 320 --height 240
[INFO]Processing time  10.601 ms 
[INFO]Processing time  10.617 ms 
...
```

![module](/misc/threads_4.png)


