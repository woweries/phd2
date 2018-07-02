/*
 *  cam_sbig.h
 *  PHD Guiding
 *
 *  Created by Craig Stark.
 *  Copyright (c) 2007-2009 Craig Stark.
 *  All rights reserved.
 *
 *  This source code is distributed under the following "BSD" license
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *    Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *    Redistributions in binary form must reproduce the above copyright notice,
 *     this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *    Neither the name of Craig Stark, Stark Labs nor the names of its
 *     contributors may be used to endorse or promote products derived from
 *     this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *
 */


#ifndef SBIGDEF
#define SBIGDEF

#if defined (__APPLE__)
#include <SBIGUDrv/sbigudrv.h>
#elif defined(__LINUX__)
    #include <sbigudrv.h>
#else
#include "cameras/Sbigudrv.h"
#endif

class CameraSBIG : public GuideCamera
{
    bool UseTrackingCCD;
    bool m_driverLoaded;
    wxSize m_imageSize[2]; // 0=>bin1, 1=>bin2
    double m_devicePixelSize;
    bool IsColor;

public:
    CameraSBIG();
    ~CameraSBIG();

    bool HandleSelectCameraButtonClick(wxCommandEvent& evt);
    bool Capture(int duration, usImage& img, int options, const wxRect& subframe);
    bool Connect(const wxString& camId);
    bool Disconnect();
    void InitCapture();
    bool ST4PulseGuideScope(int direction, int duration);
    bool ST4HasNonGuiMove() { return true; }
    bool HasNonGuiCapture() { return true; }
    wxByte BitsPerPixel();
    virtual bool    GetDevicePixelSize(double* devPixelSize);

private:
    bool LoadDriver();
};

#endif