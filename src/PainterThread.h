/*
 * Copyright (C) 2017 iCub Facility
 * Authors: Ali Paikan
 * CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT
 */

#include <string>
#include <yarp/os/Thread.h>
#include <yarp/os/Semaphore.h>
#include <yarp/sig/Image.h>



class PainterThread : public yarp::os::Thread
{
public:

    PainterThread();
    virtual ~PainterThread();

    virtual void run();

    void paint(yarp::sig::ImageOf<yarp::sig::PixelRgb>& image,
               int x, int y, int w, int h);

    void wait();

    void interrupt();

private:
    yarp::sig::ImageOf<yarp::sig::PixelRgb>* image;
    int x;
    int y;
    int w;
    int h;
    bool interrupted;
    yarp::os::Semaphore semStart;
    yarp::os::Semaphore semDone;
};

