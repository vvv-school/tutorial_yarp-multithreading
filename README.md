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

# Testing the tutorial application
