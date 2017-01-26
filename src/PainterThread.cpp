/*
 * Copyright (C) 2017 iCub Facility
 * Authors: Ali Paikan
 * CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT
 */

#include <PainterThread.h>
#include <yarp/os/LogStream.h>
#include <yarp/sig/ImageDraw.h>
#include <yarp/os/Random.h>

using namespace yarp::os;
using namespace yarp::sig;
using namespace yarp::sig::draw;


PainterThread::PainterThread()
    : semStart(0), semDone(0), interrupted(false) { }

PainterThread::~PainterThread() { }


void PainterThread::run() {
    while(!isStopping()) {        
        semStart.wait();
        if(interrupted) {
            semDone.post();
            return;
        }
        for(int i=0; i<w/2; i+=1) {
          for(int j=0; j<h/2; j+=1) {
              PixelRgb color(Random::uniform(0, 255),
                             Random::uniform(0, 255),
                             Random::uniform(0, 255));
              addRectangleOutline(*image, color, x+w/2, y+h/2, i, j);
          }
        }        
        semDone.post();
    }
}


void PainterThread::paint(yarp::sig::ImageOf<yarp::sig::PixelRgb>& image,
                          int x, int y, int w, int h) {
    PainterThread::image = &image;
    PainterThread::x = x;
    PainterThread::y = y;
    PainterThread::w = w;
    PainterThread::h = h;    
    semStart.post();
}

void PainterThread::wait() {    
    semDone.wait();
}

void PainterThread::interrupt() {
    interrupted = true;
    semStart.post();
}
