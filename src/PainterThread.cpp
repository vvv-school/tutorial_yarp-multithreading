/*
 * Copyright (C) 2017 iCub Facility
 * Authors: Ali Paikan
 * CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT
 */

#include <PainterThread.h>
#include <yarp/os/LogStream.h>
#include <yarp/sig/ImageDraw.h>
#include <yarp/math/Rand.h>

using namespace std;
using namespace yarp::os;
using namespace yarp::sig;
using namespace yarp::sig::draw;
using namespace yarp::math;


PainterThread::PainterThread()
    : interrupted(false) { }

PainterThread::~PainterThread() { }


void PainterThread::run() {
    // loop until thread is running
    while(!isStopping()) {        
        // wait to start the proccessing
        unique_lock<mutex> lck(mtx_semStart);
        cv_semStart.wait(lck);
        if(interrupted) {
            cv_semDone.notify_all();
            return;
        }
        for(int i=0; i<w/2; i+=1) {
          for(int j=0; j<h/2; j+=1) {
              PixelRgb color((int)Rand::scalar(0, 255),
                             (int)Rand::scalar(0, 255),
                             (int)Rand::scalar(0, 255));
              addRectangleOutline(*image, color, x+w/2, y+h/2, i, j);
          }
        }
        // let other know the thread already proccessed
        cv_semDone.notify_all();
    }
}


void PainterThread::paint(yarp::sig::ImageOf<yarp::sig::PixelRgb>& image,
                          int x, int y, int w, int h) {
    PainterThread::image = &image;
    PainterThread::x = x;
    PainterThread::y = y;
    PainterThread::w = w;
    PainterThread::h = h;
    // signla the thread to start proccessing
    cv_semStart.notify_all();
}

void PainterThread::wait() {    
    unique_lock<mutex> lck(mtx_semDone);
    cv_semDone.wait(lck);
}

void PainterThread::interrupt() {
    // interrupt the current proccessing/waiting acctions
    interrupted = true;
    cv_semStart.notify_all();
}
